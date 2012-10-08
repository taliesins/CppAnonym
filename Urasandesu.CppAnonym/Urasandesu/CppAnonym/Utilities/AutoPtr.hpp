#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_HPP
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_HPP
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        using namespace boost;

        struct AutoPtrHolder
        {
            typedef AutoPtrHolder this_type;

            AutoPtrHolder() : m_useCount(0) { }
            virtual ~AutoPtrHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;

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
        struct AutoPtrHolderImpl : 
            AutoPtrHolder
        {
            typedef AutoPtrHolderImpl<T, TD, ImplD> this_type;
            typedef AutoPtrHolder base_type;
            typedef T object_type;
            typedef TD object_deleter_type;
            typedef ImplD impl_deleter_type; 

            AutoPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
                base_type(), 
                m_p(p),
                m_d(d),
                m_impld(impld)
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~AutoPtrHolderImpl()
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

            object_type *m_p;
            mutable object_deleter_type m_d;
            impl_deleter_type m_impld;
        };

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl : 
            Traits::MakePointerHolderImpl<T, TD, ImplD, AutoPtrHolderImpl>
        {
        };

        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            Traits::MakeHeapPointerHolderImpl<T, AutoPtrHolderImpl, Tag>
        {
        };

        template<class T>
        class AutoPtrImpl
        {
        public:
            typedef AutoPtrImpl<T> this_type;
            typedef AutoPtrHolder holder_type;

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

            AutoPtrImpl() : 
                m_pHolder()
            { }

            explicit AutoPtrImpl(T *p) : 
                m_pHolder(new MakeHolderImpl<T, DefaultDeleter, DefaultDeleter>::type(p, DefaultDeleter(), DefaultDeleter()))
            { }

            template<class TD>
            AutoPtrImpl(T *p, TD d) : 
                m_pHolder(new MakeHolderImpl<T, TD, DefaultDeleter>::type(p, d, DefaultDeleter()))
            { }

            template<class TD, class ImplD>
            AutoPtrImpl(typename MakeHolderImpl<T, TD, ImplD>::type *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder != NULL); 
            }

            template<class U>
            AutoPtrImpl(AutoPtrImpl<U> const &other) : 
                m_pHolder(AutoPtrHolderAccessor<U>::Get(other))
            { }

            inline AutoPtrImpl &operator =(AutoPtrImpl &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }

            template<class U>
            inline AutoPtrImpl &operator =(AutoPtrImpl<U> &other)
            {
                m_pHolder = AutoPtrHolderAccessor<U>::Get(other);
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

        protected:
            AutoPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

            intrusive_ptr<holder_type> m_pHolder;

        private:
            template<class U> friend struct AutoPtrHolderAccessor;
        };

        template<class U> 
        struct AutoPtrHolderAccessor
        {
            typedef typename AutoPtrImpl<U>::holder_type holder_type;

            static intrusive_ptr<holder_type> const &Get(AutoPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

    }   // namespace AutoPtrDetail {

    template<class T>
    struct AutoPtr : 
        AutoPtrDetail::AutoPtrImpl<T>
    {
        typedef AutoPtr<T> this_type;
        typedef AutoPtrDetail::AutoPtrImpl<T> base_type;

        AutoPtr() : 
            base_type()
        { }

        explicit AutoPtr(T *p) : 
            base_type(p)
        { }

        template<class TD>
        AutoPtr(T *p, TD d) : 
            base_type(p, d)
        { }

        template<class TD, class ImplD>
        explicit AutoPtr(AutoPtrDetail::AutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        { }

        template<class U>
        AutoPtr(AutoPtr<U> const &other) : 
            base_type(other)
        { }

        inline AutoPtr &operator =(AutoPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        inline AutoPtr &operator =(AutoPtr<U> &other)
        {
            base_type::operator =(other);
            return *this;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP