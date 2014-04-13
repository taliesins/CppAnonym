/* 
 * File: AutoPtr.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.h>
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

            AutoPtrHolder() : 
                m_useCount(0) 
            { }

            virtual ~AutoPtrHolder()
            { }

            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;

            friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            friend void intrusive_ptr_release(this_type *&p)
            {
                if(--p->m_useCount == 0) 
                {
                    p->Delete();
                    p = nullptr;
                }
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
                _ASSERTE(p); 
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

            template<class Tag = QuickHeapWithoutRandomAccess>
            struct make_heap_holder_impl : 
                MakeHeapHolderImpl<T, Tag>
            {
            };

            AutoPtrImpl() : 
                m_pHolder()
            { }
            
            explicit AutoPtrImpl(T *p) : 
                m_pHolder(new AutoPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()))
            { }

            template<class TD>
            AutoPtrImpl(T *p, TD d) : 
                m_pHolder(new AutoPtrHolderImpl<T, TD, DefaultDeleter>(p, d, DefaultDeleter()))
            { }

            template<class TD, class ImplD>
            AutoPtrImpl(AutoPtrHolderImpl<T, TD, ImplD> *pHolder) : 
                m_pHolder(pHolder)
            {
                _ASSERTE(pHolder); 
            }

            AutoPtrImpl(this_type const &other) : 
                m_pHolder(other.m_pHolder)
            { }

            template<class U>
            AutoPtrImpl(AutoPtrImpl<U> const &other) : 
                m_pHolder(AutoPtrHolderAccessor<U>::Get(other))
            { }

            AutoPtrImpl &operator =(AutoPtrImpl const &other)
            {
                m_pHolder = other.m_pHolder;
                return *this;
            }

            template<class U>
            AutoPtrImpl &operator =(AutoPtrImpl<U> const &other)
            {
                m_pHolder = AutoPtrHolderAccessor<U>::Get(other);
                return *this;
            }
            
            T *operator ->()
            {
                return Get();
            }
            
            T const *operator ->() const
            {
                return Get();
            }
            
            T *Get() const
            {
                return static_cast<T *>(m_pHolder->Pointer());
            }
            
            T &operator *()
            {
                auto *p = Get();
                _ASSERTE(p);
                return *p;
            }

        protected:
            AutoPtrImpl(intrusive_ptr<holder_type> const &pHolder) : 
                m_pHolder(pHolder)
            { }

        private:
            template<class U> friend struct AutoPtrHolderAccessor;

            intrusive_ptr<holder_type> m_pHolder;

        private:
            struct Tester
            {
                Tester(int) { }
                void Dummy() { }
            };

            typedef void (Tester::*unspecified_bool_type)();

        public:
            operator unspecified_bool_type() const
            {
                return !m_pHolder ? 0 : &Tester::Dummy;
            }
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

        AutoPtr(this_type const &other) : 
            base_type(other)
        { }

        template<class U>
        AutoPtr(AutoPtr<U> const &other) : 
            base_type(other)
        { }

        AutoPtr &operator =(AutoPtr const &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        AutoPtr &operator =(AutoPtr<U> const &other)
        {
            base_type::operator =(other);
            return *this;
        }

    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H
