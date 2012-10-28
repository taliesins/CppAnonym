#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        inline AutoPtrHolder::AutoPtrHolder() : 
            m_useCount(0) 
        { }
        
        inline AutoPtrHolder::~AutoPtrHolder() 
        { };

        inline void intrusive_ptr_add_ref(AutoPtrHolder::this_type *p)
        {
            ++p->m_useCount;
        }

        inline void intrusive_ptr_release(AutoPtrHolder::this_type *p)
        {
            if(--p->m_useCount == 0) 
                p->Delete();
        }

        
        
        
        
        template<class T, class TD, class ImplD>
        inline AutoPtrHolderImpl<T, TD, ImplD>::AutoPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
            base_type(), 
            m_p(p),
            m_d(d),
            m_impld(impld)
        { 
            _ASSERTE(p != NULL); 
        }

        template<class T, class TD, class ImplD>
        inline AutoPtrHolderImpl<T, TD, ImplD>::~AutoPtrHolderImpl()
        {
        }

        template<class T, class TD, class ImplD>
        inline void *AutoPtrHolderImpl<T, TD, ImplD>::Pointer() const
        {
            return m_p;
        }

        template<class T, class TD, class ImplD>
        inline void AutoPtrHolderImpl<T, TD, ImplD>::Delete()
        {
            m_d(m_p);
            m_impld(this);
        }





        
        template<class T>
        inline AutoPtrImpl<T>::AutoPtrImpl() : 
            m_pHolder()
        { }

        template<class T>
        inline AutoPtrImpl<T>::AutoPtrImpl(T *p) : 
            m_pHolder(new AutoPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()))
        { }

        template<class T>
        template<class TD>
        inline AutoPtrImpl<T>::AutoPtrImpl(T *p, TD d) : 
            m_pHolder(new AutoPtrHolderImpl<T, TD, DefaultDeleter>(p, d, DefaultDeleter()))
        { }

        template<class T>
        template<class TD, class ImplD>
        inline AutoPtrImpl<T>::AutoPtrImpl(AutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            m_pHolder(pHolder)
        {
            _ASSERTE(pHolder != NULL); 
        }

        template<class T>
        inline AutoPtrImpl<T>::AutoPtrImpl(this_type const &other) : 
            m_pHolder(other.m_pHolder)
        { }

        template<class T>
        template<class U>
        inline AutoPtrImpl<T>::AutoPtrImpl(AutoPtrImpl<U> const &other) : 
            m_pHolder(AutoPtrHolderAccessor<U>::Get(other))
        { }

        template<class T>
        inline AutoPtrImpl<T> &AutoPtrImpl<T>::operator =(AutoPtrImpl &other)
        {
            m_pHolder = other.m_pHolder;
            return *this;
        }

        template<class T>
        template<class U>
        inline AutoPtrImpl<T> &AutoPtrImpl<T>::operator =(AutoPtrImpl<U> &other)
        {
            m_pHolder = AutoPtrHolderAccessor<U>::Get(other);
            return *this;
        }

        template<class T>
        inline AutoPtrImpl<T>::operator bool() const
        {
            return m_pHolder;
        }

        template<class T>
        inline bool AutoPtrImpl<T>::operator !() const
        {
            return !m_pHolder;
        }

        template<class T>
        inline T *AutoPtrImpl<T>::operator ->()
        {
            return Get();
        }

        template<class T>
        inline T *AutoPtrImpl<T>::Get() const
        {
            return static_cast<T *>(m_pHolder->Pointer());
        }

        template<class T>
        inline T &AutoPtrImpl<T>::operator *()
        {
            T *p = Get();
            _ASSERTE(p != NULL);
            return *p;
        }

        template<class T>
        inline AutoPtrImpl<T>::AutoPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
            m_pHolder(pHolder)
        { }

        
        
        
        
        
        template<class U> 
        inline intrusive_ptr<typename AutoPtrHolderAccessor<U>::holder_type> const &
            AutoPtrHolderAccessor<U>::Get(AutoPtrImpl<U> const &p)
        {
            return p.m_pHolder;
        }

    }   // namespace AutoPtrDetail {

    
    
    
    
    template<class T>
    inline AutoPtr<T>::AutoPtr() : 
        base_type()
    { }

    template<class T>
    inline AutoPtr<T>::AutoPtr(T *p) : 
        base_type(p)
    { }

    template<class T>
    template<class TD>
    inline AutoPtr<T>::AutoPtr(T *p, TD d) : 
        base_type(p, d)
    { }

    template<class T>
    template<class TD, class ImplD>
    inline AutoPtr<T>::AutoPtr(AutoPtrDetail::AutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
        base_type(pHolder)
    { }

    template<class T>
    inline AutoPtr<T>::AutoPtr(this_type const &other) : 
        base_type(other)
    { }

    template<class T>
    template<class U>
    inline AutoPtr<T>::AutoPtr(AutoPtr<U> const &other) : 
        base_type(other)
    { }

    template<class T>
    inline AutoPtr<T> &AutoPtr<T>::operator =(AutoPtr &other)
    {
        base_type::operator =(other);
        return *this;
    }

    template<class T>
    template<class U>
    inline AutoPtr<T> &AutoPtr<T>::operator =(AutoPtr<U> &other)
    {
        base_type::operator =(other);
        return *this;
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP