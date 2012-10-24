#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_H
#include <Urasandesu/CppAnonym/Utilities/AutoPtrFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        using namespace boost;

        struct AutoPtrHolder
        {
            typedef AutoPtrHolder this_type;

            AutoPtrHolder();
            virtual ~AutoPtrHolder();
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;

            friend void intrusive_ptr_add_ref(this_type *p);
            friend void intrusive_ptr_release(this_type *p);

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

            AutoPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld);
            virtual ~AutoPtrHolderImpl();
            virtual void *Pointer() const;
            virtual void Delete();

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

            AutoPtrImpl();
            explicit AutoPtrImpl(T *p);

            template<class TD>
            AutoPtrImpl(T *p, TD d);

            template<class TD, class ImplD>
            AutoPtrImpl(AutoPtrHolderImpl<T, TD, ImplD> *pHolder);

            AutoPtrImpl(this_type const &other);

            template<class U>
            AutoPtrImpl(AutoPtrImpl<U> const &other);

            AutoPtrImpl &operator =(AutoPtrImpl &other);

            template<class U>
            AutoPtrImpl &operator =(AutoPtrImpl<U> &other);

            operator bool() const;
            bool operator !() const;
            T *operator ->();
            T *Get() const;
            T &operator *();

        protected:
            AutoPtrImpl(intrusive_ptr<holder_type> const &pHolder);

        private:
            template<class U> friend struct AutoPtrHolderAccessor;

            intrusive_ptr<holder_type> m_pHolder;
        };

        template<class U> 
        struct AutoPtrHolderAccessor
        {
            typedef typename AutoPtrImpl<U>::holder_type holder_type;

            static intrusive_ptr<holder_type> const &Get(AutoPtrImpl<U> const &p);
        };

    }   // namespace AutoPtrDetail {

    template<class T>
    struct AutoPtr : 
        AutoPtrDetail::AutoPtrImpl<T>
    {
        typedef AutoPtr<T> this_type;
        typedef AutoPtrDetail::AutoPtrImpl<T> base_type;

        AutoPtr();
        explicit AutoPtr(T *p);

        template<class TD>
        AutoPtr(T *p, TD d);

        template<class TD, class ImplD>
        explicit AutoPtr(AutoPtrDetail::AutoPtrHolderImpl<T, TD, ImplD> *pHolder);

        AutoPtr(this_type const &other);

        template<class U>
        AutoPtr(AutoPtr<U> const &other);

        AutoPtr &operator =(AutoPtr &other);

        template<class U>
        AutoPtr &operator =(AutoPtr<U> &other);

    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H