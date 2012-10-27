#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_H
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        namespace mpl = boost::mpl;
        using namespace boost;

        struct SemiAutoPtrHolder
        {
            typedef SemiAutoPtrHolder this_type;

            SemiAutoPtrHolder() : m_useCount(0) { }
            virtual ~SemiAutoPtrHolder() { };
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

        template<class T, class TD, class ImplD>
        struct SemiAutoPtrHolderImpl : 
            SemiAutoPtrHolder
        {
            typedef SemiAutoPtrHolderImpl<T, TD, ImplD> this_type;
            typedef SemiAutoPtrHolder base_type;
            typedef T object_type;
            typedef DeletionSwitchablePolicy<TD> object_deleter_type;
            typedef ImplD impl_deleter_type; 

            SemiAutoPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
                base_type(), 
                m_p(p),
                m_d(d),
                m_impld(impld)
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~SemiAutoPtrHolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return m_p;
            }

            virtual void Delete()
            {
                m_d(m_p);
                m_impld(this);
            }

            virtual void EnableDeletion()
            {
                m_d.EnableDeletion();
            }

            virtual void DisableDeletion()
            {
                m_d.DisableDeletion();
            }

            object_type *m_p;
            mutable object_deleter_type m_d;
            impl_deleter_type m_impld;
        };

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl : 
            Traits::MakePointerHolderImpl<T, TD, ImplD, SemiAutoPtrHolderImpl>
        {
        };

        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            Traits::MakeHeapPointerHolderImpl<T, SemiAutoPtrHolderImpl, Tag>
        {
        };

        template<class T>
        class SemiAutoPtrImpl
        {
        public:
            typedef SemiAutoPtrImpl<T> this_type;
            typedef SemiAutoPtrHolder holder_type;

            template<class TD, class ImplD>
            struct make_holder_impl : 
                MakeHolderImpl<T, TD, ImplD>
            {
            };

            template<class Tag = QuickHeapWithoutSubscriptOperator>
            struct make_heap_holder_impl : 
                MakeHeapHolderImpl<T, Tag>
            {
            };

            SemiAutoPtrImpl() : 
                m_pHolder()
            { }

            explicit SemiAutoPtrImpl(T *p) : 
                m_pHolder(new SemiAutoPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()))
            { }

            template<class TD>
            SemiAutoPtrImpl(T *p, TD d) : 
                m_pHolder(new SemiAutoPtrHolderImpl<T, TD, DefaultDeleter>(p, d, DefaultDeleter()))
            { }

            template<class TD, class ImplD>
            SemiAutoPtrImpl(SemiAutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder != NULL); 
            }

            SemiAutoPtrImpl(this_type const &other) : 
                m_pHolder(other.m_pHolder)
            { }

            template<class U>
            SemiAutoPtrImpl(SemiAutoPtrImpl<U> const &other) : 
                m_pHolder(SemiAutoPtrHolderAccessor<U>::Get(other))
            { }

            inline SemiAutoPtrImpl &operator =(SemiAutoPtrImpl &other)
            {
                if (this != &other)
                {
                    m_pHolder = other.m_pHolder;
                }
                return *this;
            }

            template<class U>
            inline SemiAutoPtrImpl &operator =(SemiAutoPtrImpl<U> &other)
            {
                m_pHolder = SemiAutoPtrHolderAccessor<U>::Get(other);
                return *this;
            }

            inline operator bool() const
            {
                return m_pHolder;
            }

            bool operator !() const
            {
                return !m_pHolder;
            }

            inline T *operator->()
            {
                return Get();
            }

            inline T *Get() const
            {
                return static_cast<T *>(m_pHolder->Pointer());
            }

            inline T &operator *()
            {
                T *p = Get();
                _ASSERTE(p != NULL);
                return *p;
            }

            inline void SetAuto()
            {
                m_pHolder->EnableDeletion();
            }

            inline void SetManual()
            {
                m_pHolder->DisableDeletion();
            }

        private:
            template<class U> friend struct SemiAutoPtrHolderAccessor;
            intrusive_ptr<holder_type> m_pHolder;
        };

        template<class U> 
        struct SemiAutoPtrHolderAccessor
        {
            typedef typename SemiAutoPtrImpl<U>::holder_type holder_type;

            static intrusive_ptr<holder_type> const &Get(SemiAutoPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

    }   // namespace SemiAutoPtrDetail {

    template<class T>
    struct SemiAutoPtr : 
        SemiAutoPtrDetail::SemiAutoPtrImpl<T>
    {
        typedef SemiAutoPtr<T> this_type;
        typedef SemiAutoPtrDetail::SemiAutoPtrImpl<T> base_type;

        SemiAutoPtr() : 
            base_type()
        { }

        explicit SemiAutoPtr(T *p) : 
            base_type(p)
        { }

        template<class TD>
        SemiAutoPtr(T *p, TD d) : 
            base_type(p, d)
        { }

        template<class TD, class ImplD>
        explicit SemiAutoPtr(SemiAutoPtrDetail::SemiAutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        { }

        SemiAutoPtr(this_type const &other) : 
            base_type(other)
        { }

        template<class U>
        SemiAutoPtr(SemiAutoPtr<U> const &other) : 
            base_type(other)
        { }

        ~SemiAutoPtr()
        {
        }

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
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP