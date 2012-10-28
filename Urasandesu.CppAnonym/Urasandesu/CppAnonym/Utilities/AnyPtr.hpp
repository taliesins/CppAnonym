#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#include <Urasandesu/CppAnonym/Utilities/AnyPtr.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AnyPtrDetail {

        inline AnyPtrHolder::AnyPtrHolder() : 
            m_useCount(0) 
        { }
        
        inline AnyPtrHolder::~AnyPtrHolder() 
        { }

        inline void intrusive_ptr_add_ref(AnyPtrHolder::this_type *p)
        {
            ++p->m_useCount;
        }

        inline void intrusive_ptr_release(AnyPtrHolder::this_type *p)
        {
            if(--p->m_useCount == 0) 
                p->Delete();
        }

        
        
        
        
        template<class T, class TD, class ImplD>
        inline AnyPtrHolderImpl<T, TD, ImplD>::AnyPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
            base_type(), 
            m_p(p),
            m_d(d),
            m_impld(impld)
        { 
            _ASSERTE(p != NULL); 
        }

        template<class T, class TD, class ImplD>
        inline AnyPtrHolderImpl<T, TD, ImplD>::~AnyPtrHolderImpl()
        {
        }

        template<class T, class TD, class ImplD>
        inline void *AnyPtrHolderImpl<T, TD, ImplD>::Pointer() const
        {
            return const_cast<typename Traits::RemoveConst<object_type *>::type>(m_p);
        }

        template<class T, class TD, class ImplD>
        inline void AnyPtrHolderImpl<T, TD, ImplD>::Delete()
        {
            m_d(m_p);
            m_impld(this);
        }

        template<class T, class TD, class ImplD>
        inline std::type_info const &AnyPtrHolderImpl<T, TD, ImplD>::GetType() const 
        { 
            return typeid(object_type *); 
        }

        
        
        
        
        inline AnyPtrImpl::AnyPtrImpl() : 
            m_pHolder()
        { }

        template<class T>
        inline AnyPtrImpl::AnyPtrImpl(T *p) : 
            m_pHolder(new AnyPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()))
        { }

        template<class T, class TD>
        inline AnyPtrImpl::AnyPtrImpl(T *p, TD d) : 
            m_pHolder(new AnyPtrHolderImpl<T, TD, DefaultDeleter>(p, d, DefaultDeleter()))
        { }

        template<class T, class TD, class ImplD>
        inline AnyPtrImpl::AnyPtrImpl(AnyPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            m_pHolder(pHolder)
        {
            _ASSERTE(pHolder != NULL); 
        }

        inline AnyPtrImpl::AnyPtrImpl(AnyPtrImpl const &other) : 
            m_pHolder(other.m_pHolder)
        { }

        inline AnyPtrImpl &AnyPtrImpl::operator =(AnyPtrImpl &other)
        {
            m_pHolder = other.m_pHolder;
            return *this;
        }

        inline bool AnyPtrImpl::IsEmpty() const
        {
            return !m_pHolder;
        }

        template<class Pointer>
        inline bool AnyPtrImpl::Is() const 
        {
            BOOST_MPL_ASSERT((is_pointer<Pointer>));
            return m_pHolder && typeid(Pointer) == m_pHolder->GetType();
        }

        template<class Pointer>
        inline AnyPtrImpl::operator Pointer()
        {
            return Is<Pointer>() ? static_cast<Pointer>(m_pHolder->Pointer()) : NULL;
        }

        inline AnyPtrImpl::AnyPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
            m_pHolder(pHolder)
        { }

    }   // namespace AnyPtrDetail {

    
    
    
    
    inline AnyPtr::AnyPtr() : 
        base_type()
    { }

    template<class T>
    inline AnyPtr::AnyPtr(T *p) : 
        base_type(p)
    { }

    template<class T, class TD>
    inline AnyPtr::AnyPtr(T *p, TD d) : 
        base_type(p, d)
    { }

    template<class T, class TD, class ImplD>
    inline AnyPtr::AnyPtr(AnyPtrDetail::AnyPtrHolderImpl<T, TD, ImplD> *pHolder) : 
        base_type(pHolder)
    { }

    inline AnyPtr::AnyPtr(AnyPtr const &other) : 
        base_type(other)
    { }

    inline AnyPtr &AnyPtr::operator =(AnyPtr &other)
    {
        base_type::operator =(other);
        return *this;
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP