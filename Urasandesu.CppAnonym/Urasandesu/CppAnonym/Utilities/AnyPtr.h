#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#define URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTRFWD_H
#include <Urasandesu/CppAnonym/Utilities/AnyPtrFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AnyPtrDetail {

        using namespace boost;
        
        struct AnyPtrHolder
        {
            typedef AnyPtrHolder this_type;

            AnyPtrHolder();
            virtual ~AnyPtrHolder();
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual std::type_info const &GetType() const = 0;

            friend void intrusive_ptr_add_ref(this_type *p);
            friend void intrusive_ptr_release(this_type *p);

            LONG m_useCount;
        };

        template<class T, class TD, class ImplD>
        struct AnyPtrHolderImpl : 
            AnyPtrHolder
        {
            typedef AnyPtrHolderImpl<T, TD, ImplD> this_type;
            typedef AnyPtrHolder base_type;
            typedef T object_type;
            typedef TD object_deleter_type;
            typedef ImplD impl_deleter_type; 

            AnyPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld);
            virtual ~AnyPtrHolderImpl();
            virtual void *Pointer() const;
            virtual void Delete();
            virtual std::type_info const &GetType() const;

            object_type *m_p;
            mutable object_deleter_type m_d;
            impl_deleter_type m_impld;
        };

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl : 
            Traits::MakePointerHolderImpl<T, TD, ImplD, AnyPtrHolderImpl>
        {
        };

        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            Traits::MakeHeapPointerHolderImpl<T, AnyPtrHolderImpl, Tag>
        {
        };

        class AnyPtrImpl
        {
        public:
            typedef AnyPtrImpl this_type;
            typedef AnyPtrHolder holder_type;

            AnyPtrImpl();

            template<class T>
            explicit AnyPtrImpl(T *p);

            template<class T, class TD>
            AnyPtrImpl(T *p, TD d);

            template<class T, class TD, class ImplD>
            AnyPtrImpl(AnyPtrHolderImpl<T, TD, ImplD> *pHolder);

            AnyPtrImpl(AnyPtrImpl const &other);
            AnyPtrImpl &operator =(AnyPtrImpl &other);
            bool IsEmpty() const;
            
            template<class Pointer>
            bool Is() const;

            template<class Pointer>
            operator Pointer();

        protected:
            AnyPtrImpl(intrusive_ptr<holder_type> const &pHolder);

            intrusive_ptr<holder_type> m_pHolder;
        };

    }   // namespace AnyPtrDetail {

    struct AnyPtr : 
        AnyPtrDetail::AnyPtrImpl
    {
        typedef AnyPtr this_type;
        typedef AnyPtrDetail::AnyPtrImpl base_type;

        AnyPtr();

        template<class T>
        explicit AnyPtr(T *p);

        template<class T, class TD>
        AnyPtr(T *p, TD d);

        template<class T, class TD, class ImplD>
        explicit AnyPtr(AnyPtrDetail::AnyPtrHolderImpl<T, TD, ImplD> *pHolder);

        AnyPtr(AnyPtr const &other);
        AnyPtr &operator =(AnyPtr &other);
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H