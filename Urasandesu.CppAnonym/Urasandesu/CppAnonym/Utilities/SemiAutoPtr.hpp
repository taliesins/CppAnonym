#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        using namespace boost;

        struct Holder
        {
            typedef Holder this_type;

            Holder() : m_useCount(0) { }
            virtual ~Holder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual void EnableDeletion() = 0;
            virtual void DisableDeletion() = 0;

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) 
                    p->Delete();
            }

            LONG m_useCount;
        };

        template<class T, class D>
        struct HolderImpl : 
            Holder
        {
            typedef HolderImpl<T, D> this_type;
            typedef HolderImplFactory<T, D> holder_factory_type;
            typedef DeletionSwitchablePolicy<D> deletion_switchable_deleter;

            explicit HolderImpl(T *p) : 
                Holder(), 
                m_p(p),
                m_dsd(deletion_switchable_deleter(D()))
            { 
                _ASSERTE(p != NULL); 
            }

            HolderImpl(T *p, D d) : 
                Holder(), 
                m_p(p),
                m_dsd(deletion_switchable_deleter(d))
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~HolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return m_p;
            }

            virtual void Delete()
            {
                m_dsd(m_p);
                HolderImplFactory<T, D>::Heap().Delete(this);
            }

            virtual void EnableDeletion()
            {
                m_dsd.EnableDeletion();
            }

            virtual void DisableDeletion()
            {
                m_dsd.DisableDeletion();
            }

            T *m_p;
            mutable deletion_switchable_deleter m_dsd;
        };

        template<class T, class D>
        struct HolderImplFactory
        {
            typedef HolderImpl<T, D> holder_type;
            typedef SimpleHeap<holder_type, QuickHeapWithoutSubscriptOperator> holder_heap_type;
            static holder_heap_type &Heap() { static holder_heap_type heap; return heap; }
        };

    }   // namespace SemiAutoPtrDetail {

    template<class T>
    class SemiAutoPtr : 
        public AutoPtr<T>
    {
    public:
        typedef SemiAutoPtr<T> this_type;
        typedef AutoPtr<T> base_type;

        SemiAutoPtr() : 
            base_type()
        { }

        explicit SemiAutoPtr(T *p) : 
            base_type(p)
        { }

        template<class D>
        SemiAutoPtr(T *p, D d) : 
            base_type(p, d)
        { }

        template<class U>
        SemiAutoPtr(SemiAutoPtr<U> const &other) : 
            base_type(other)
        { }

        inline SemiAutoPtr &operator =(SemiAutoPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        inline SemiAutoPtr &operator =(SemiAutoPtr<U> &other)
        {
            base_type::operator =(other);
            return *this;
        }

        inline void SetAuto()
        {
            m_pHolder->EnableDeletion();
        }

        inline void SetManual()
        {
            m_pHolder->DisableDeletion();
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP