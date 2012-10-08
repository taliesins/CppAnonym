#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTER_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTERFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/TemporaryPointerFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace Detail {

        struct TemporaryHolder
        {
            typedef TemporaryHolder this_type;

            TemporaryHolder() : m_useCount(0) { }
            virtual ~TemporaryHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual void DisableDeletion() = 0;

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) p->Delete();
            }

            LONG m_useCount;
        };

        template<class T, class Tag, class D>
        struct TemporaryHolderImpl : 
            TemporaryHolder
        {
            typedef TemporaryHolderImpl<T, Tag, D> this_type;
            typedef TemporaryHolderImplFactory<T, Tag, D> holder_factory_type;
            typedef DeletionDisabledPolicy<D> deletion_disabled_deleter;

            explicit TemporaryHolderImpl(T *p) : 
                TemporaryHolder(), 
                m_p(p),
                m_ddd(deletion_disabled_deleter(D()))
            { _ASSERTE(p != NULL); }

            TemporaryHolderImpl(T *p, D d) : 
                TemporaryHolder(), 
                m_p(p),
                m_ddd(deletion_disabled_deleter(d))
            { _ASSERTE(p != NULL); }

            virtual ~TemporaryHolderImpl()
            {
                m_ddd(m_p);
            }

            virtual void *Pointer() const
            {
                return m_p;
            }

            virtual void Delete()
            {
                m_ddd(m_p);
            }

            virtual void DisableDeletion()
            {
                m_ddd.DisableDeletion();
            }

            T *m_p;
            mutable deletion_disabled_deleter m_ddd;
        };

        template<class T, class Tag, class D>
        struct TemporaryHolderImplFactory
        {
            typedef TemporaryHolderImpl<T, Tag, D> holder_type;
            typedef holder_type *holder_ptr_type;
            typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
            static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        };

    }   // namespace Detail {

    template<class T, class Tag>
    class TemporaryPointer
    {
    public:
        typedef TemporaryPointer<T, Tag> this_type;
        typedef Detail::TemporaryHolder holder_type;
        typedef boost::intrusive_ptr<holder_type> holder_ptr_type;

        typedef T element_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;

        explicit TemporaryPointer(T *p) : 
            m_pHolder(Detail::TemporaryHolderImplFactory<T, Tag, DefaultDeleter>::Heap().New(p))
        { }

        template<class D>
        TemporaryPointer(T *p, D d) : 
            m_pHolder(Detail::TemporaryHolderImplFactory<T, Tag, D>::Heap().New(p, d))
        { }

        pointer operator->()
        {
            return Get();
        }

        pointer Get() const
        {
            return static_cast<pointer>(m_pHolder->Pointer());
        }

        reference operator *()
        {
            pointer p = Get();
            _ASSERTE(p != NULL);
            return *p;
        }

    protected:
        holder_ptr_type m_pHolder;
    };

    template<class T, class Tag>
    class PersistableTemporaryPointer : 
        public TemporaryPointer<T, Tag>
    {
    public:
        typedef PersistableTemporaryPointer<T, Tag> this_type;
        typedef TemporaryPointer<T, Tag> base_type;

        explicit PersistableTemporaryPointer(T *p) : 
            TemporaryPointer(p)
        { }

        template<class D>
        PersistableTemporaryPointer(T *p, D d) : 
            TemporaryPointer(p, d)
        { }

        pointer Persist() const
        {
            m_pHolder->DisableDeletion();
            return Get();
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTER_HPP