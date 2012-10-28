#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#define URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.h>
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

            AnyPtrHolder() : 
                m_useCount(0) 
            { }
            
            virtual ~AnyPtrHolder()
            { }
            
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual std::type_info const &GetType() const = 0;

            friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }
            
            friend void intrusive_ptr_release(this_type *p)
            {
                if(--p->m_useCount == 0) 
                    p->Delete();
            }

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

            AnyPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
                base_type(), 
                m_p(p),
                m_d(d),
                m_impld(impld)
            { 
                _ASSERTE(p != NULL); 
            }
            
            virtual ~AnyPtrHolderImpl()
            {
            }
            
            virtual void *Pointer() const
            {
                return const_cast<typename Traits::RemoveConst<object_type *>::type>(m_p);
            }
            
            virtual void Delete()
            {
                m_d(m_p);
                m_impld(this);
            }
            
            virtual std::type_info const &GetType() const
            { 
                return typeid(object_type *); 
            }

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

            AnyPtrImpl() : 
                m_pHolder()
            { }

            template<class T>
            explicit AnyPtrImpl(T *p) : 
                m_pHolder(new AnyPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()))
            { }

            template<class T, class TD>
            AnyPtrImpl(T *p, TD d) : 
                m_pHolder(new AnyPtrHolderImpl<T, TD, DefaultDeleter>(p, d, DefaultDeleter()))
            { }

            template<class T, class TD, class ImplD>
            AnyPtrImpl(AnyPtrHolderImpl<T, TD, ImplD> *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder != NULL); 
            }

            AnyPtrImpl(AnyPtrImpl const &other) : 
                m_pHolder(other.m_pHolder)
            { }
            
            AnyPtrImpl &operator =(AnyPtrImpl &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }
            
            bool IsEmpty() const
            {
                return !m_pHolder;
            }
            
            template<class Pointer>
            bool Is() const
            {
                BOOST_MPL_ASSERT((is_pointer<Pointer>));
                return m_pHolder && typeid(Pointer) == m_pHolder->GetType();
            }

            template<class Pointer>
            operator Pointer()
            {
                return Is<Pointer>() ? static_cast<Pointer>(m_pHolder->Pointer()) : NULL;
            }

        protected:
            AnyPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

            intrusive_ptr<holder_type> m_pHolder;
        };

    }   // namespace AnyPtrDetail {

    struct AnyPtr : 
        AnyPtrDetail::AnyPtrImpl
    {
        typedef AnyPtr this_type;
        typedef AnyPtrDetail::AnyPtrImpl base_type;

        AnyPtr() : 
            base_type()
        { }

        template<class T>
        explicit AnyPtr(T *p) : 
            base_type(p)
        { }

        template<class T, class TD>
        AnyPtr(T *p, TD d) : 
            base_type(p, d)
        { }

        template<class T, class TD, class ImplD>
        explicit AnyPtr(AnyPtrDetail::AnyPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        { }

        AnyPtr(AnyPtr const &other) : 
            base_type(other)
        { }

        AnyPtr &operator =(AnyPtr &other)
        {
            base_type::operator =(other);
            return *this;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H