#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace _565A04BF {

        struct Holder
        {
            typedef Holder this_type;

            Holder() : m_useCount(0) { }
            virtual ~Holder() { };
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
        struct HolderImpl : 
            Holder
        {
            typedef HolderImpl<T, Tag, D> this_type;
            typedef HolderImplFactory<T, Tag, D> holder_factory_type;
            typedef DeletionSwitchablePolicy<D> deletion_disabled_deleter;

            explicit HolderImpl(T *p) : 
                Holder(), 
                m_p(p),
                m_ddd(deletion_disabled_deleter(D()))
            { _ASSERTE(p != NULL); }

            HolderImpl(T *p, D d) : 
                Holder(), 
                m_p(p),
                m_ddd(deletion_disabled_deleter(d))
            { _ASSERTE(p != NULL); }

            virtual ~HolderImpl()
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
        struct HolderImplFactory
        {
            typedef HolderImpl<T, Tag, D> holder_type;
            typedef holder_type *holder_ptr_type;
            typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
            static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        };

    }   // namespace _565A04BF {

    template<class T, class Tag>
    class TempPtr
    {
    public:
        typedef TempPtr<T, Tag> this_type;
        typedef _565A04BF::Holder holder_type;
        typedef boost::intrusive_ptr<holder_type> holder_ptr_type;

        typedef T element_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;

        explicit TempPtr(T *p) : 
            m_pHolder(_565A04BF::HolderImplFactory<T, Tag, DefaultDeleter>::Heap().New(p))
        { }

        template<class D>
        TempPtr(T *p, D d) : 
            m_pHolder(_565A04BF::HolderImplFactory<T, Tag, D>::Heap().New(p, d))
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
    class PersistPtr : 
        public TempPtr<T, Tag>
    {
    public:
        typedef PersistPtr<T, Tag> this_type;
        typedef TempPtr<T, Tag> base_type;

        explicit PersistPtr(T *p) : 
            TempPtr(p)
        { }

        template<class D>
        PersistPtr(T *p, D d) : 
            TempPtr(p, d)
        { }

        void Revert()
        {
            m_pHolder->EnableDeletion();
        }

        void Persist()
        {
            m_pHolder->DisableDeletion();
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP