/* 
 * File: TempPtr.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_H
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_H
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeValueHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H
#include <Urasandesu/CppAnonym/Traits/MakeHeapValueHolderImpl.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/VariantPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_H
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H
#include <Urasandesu/CppAnonym/Utilities/TempPtrFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {
        
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Collections;
        using namespace Urasandesu::CppAnonym::Traits;
        using mpl::eval_if;
        using mpl::identity;

        struct TempPtrHolder
        {
            typedef TempPtrHolder this_type;

            TempPtrHolder() : m_useCount(0) { }
            virtual ~TempPtrHolder() { };
            virtual void *Pointer() const = 0;
            virtual void Delete() = 0;
            virtual void DisableDeletion() = 0;

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
        struct TempPtrHolderImpl : 
            TempPtrHolder
        {
            typedef TempPtrHolderImpl<T, TD, ImplD> this_type;
            typedef TempPtrHolder base_type;
            typedef T object_type;
            typedef DeletionSwitchablePolicy<TD> object_deleter_type;
            typedef ImplD impl_deleter_type; 

            TempPtrHolderImpl(object_type *p, object_deleter_type d, impl_deleter_type impld) : 
                base_type(), 
                m_p(p),
                m_d(d),
                m_impld(impld)
            { 
                _ASSERTE(p != NULL); 
            }

            virtual ~TempPtrHolderImpl()
            {
            }

            virtual void *Pointer() const
            {
                return const_cast<typename RemoveConst<object_type>::type *>(m_p);
            }

            virtual void Delete()
            {
                m_d(m_p);
                m_impld(this);
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
            MakePointerHolderImpl<T, TD, ImplD, TempPtrHolderImpl>
        {
        };

        
        
        
        
        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl : 
            MakeHeapPointerHolderImpl<T, TempPtrHolderImpl, Tag>
        {
        };

        
        
        
        
        struct PersistedHandlerHolder
        {
            typedef PersistedHandlerHolder this_type;

            PersistedHandlerHolder() : m_useCount(0) { }
            virtual ~PersistedHandlerHolder() { };
            virtual void operator ()(void *pSender, void *pArg) = 0;
            virtual void Delete() = 0;

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

        
        
        
        
        template<class Handler, class ImplD>
        struct PersistedHandlerHolderImpl : 
            PersistedHandlerHolder
        {
            typedef PersistedHandlerHolderImpl<Handler, ImplD> this_type;
            typedef PersistedHandlerHolder base_type;

            typedef typename eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(PersistedHandlerSender, Handler), 
                CPP_ANONYM_GET_MEMBER_TYPE(PersistedHandlerSender, Handler), 
                identity<void>
            >::type sender_type;

            typedef typename eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(PersistedHandlerArg, Handler), 
                CPP_ANONYM_GET_MEMBER_TYPE(PersistedHandlerArg, Handler), 
                identity<void>
            >::type arg_type;

            PersistedHandlerHolderImpl(Handler handler) : 
                base_type(),
                m_handler(handler),
                m_impld(ImplD())
            { }

            PersistedHandlerHolderImpl(Handler handler, ImplD impld) : 
                base_type(), 
                m_handler(handler),
                m_impld(impld)
            { }
            
            virtual ~PersistedHandlerHolderImpl() 
            { 
            }

            virtual void operator ()(void *pSender, void *pArg)
            {
                m_handler(static_cast<sender_type *>(pSender), static_cast<arg_type *>(pArg));
            }

            virtual void Delete()
            {
                m_impld(this);
            }

            Handler m_handler;
            ImplD m_impld;
        };

        
        
        
        
        template<class Handler, class ImplD>
        struct MakePersistedHandlerHolderImpl : 
            MakeValueHolderImpl<Handler, ImplD, PersistedHandlerHolderImpl>
        {
        };

        
        
        
        
        template<
            class Handler, 
            class Tag
        >
        struct MakeHeapPersistedHandlerHolderImpl : 
            MakeHeapValueHolderImpl<Handler, PersistedHandlerHolderImpl, Tag>
        {
        };

        
        
        
        
        template<class T>
        class TempPtrImpl
        {
        public:
            typedef TempPtrImpl<T> this_type;
            typedef TempPtrHolder holder_type;
            typedef PersistedHandlerHolder persisted_handler_holder_type;
            typedef VariantPtr<intrusive_ptr<holder_type>, T *> variant_holder_type;
            typedef TempPtrStates state_type;
            typedef RapidVector<intrusive_ptr<persisted_handler_holder_type>, 1 > persisted_handlers_type;

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

            template<class Handler, class ImplD>
            struct make_persisted_handler_holder_impl : 
                MakePersistedHandlerHolderImpl<Handler, ImplD>
            {
            };

            template<class Handler, class Tag = QuickHeapWithoutRandomAccess>
            struct make_heap_persisted_handler_holder_impl : 
                MakeHeapPersistedHandlerHolderImpl<Handler, Tag>
            {
            };

            TempPtrImpl();
            TempPtrImpl(T *p, bool hasAlreadyPersisted);

            template<class TD>
            TempPtrImpl(T *p, TD td);

            template<class TD, class ImplD>
            TempPtrImpl(TempPtrHolderImpl<T, TD, ImplD> *pHolder);

            TempPtrImpl(this_type const &other);

            template<class U>
            TempPtrImpl(TempPtrImpl<U> const &other);

            ~TempPtrImpl();
            this_type &operator =(this_type const &other);

            template<class U>
            TempPtrImpl &operator =(TempPtrImpl<U> const &other);

            T *operator ->()
            {
                return Get();
            }

            T const *operator ->() const
            {
                return Get();
            }

            T *Get() const;

            T &operator *()
            {
                T *p = Get();
                _ASSERTE(p != NULL);
                return *p;
            }

            bool IsPersisted() const
            {
                return m_state != TempPtrStates::TPS_NONE;
            }

            void Persist();

            template<class Handler>
            SIZE_T AddPersistedHandler(Handler handler)
            {
                m_persistedHandlers.push_back(new MakePersistedHandlerHolderImpl<Handler, DefaultDeleter>::type(handler));
                return m_persistedHandlers.size() - 1;
            }

            template<class Handler, class ImplD>
            SIZE_T AddPersistedHandler(PersistedHandlerHolderImpl<Handler, ImplD> *pPersistedHandlerHolder)
            {
                m_persistedHandlers.push_back(pPersistedHandlerHolder);
                return m_persistedHandlers.size() - 1;
            }

            void RemovePersistedHandler(SIZE_T id)
            {
                _ASSERTE(id < m_persistedHandlers.size());
                m_persistedHandlers.erace(m_persistedHandlers.begin() + id);
            }

        private:
            template<class U> friend struct TempPtrHolderAccessor;
            template<class U> friend struct PersistedHandlersAccessor;
            
            VariantPtr<intrusive_ptr<holder_type>, T *> m_pHolder;
            TempPtrStates m_state;
            persisted_handlers_type m_persistedHandlers;

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
        struct TempPtrHolderAccessor
        {
            typedef typename TempPtrImpl<U>::variant_holder_type variant_holder_type;

            static variant_holder_type const &Get(TempPtrImpl<U> const &p)
            {
                return p.m_pHolder;
            }
        };

        
        
        
        
        template<class U> 
        struct PersistedHandlersAccessor
        {
            typedef typename TempPtrImpl<U>::persisted_handlers_type persisted_handlers_type;

            static persisted_handlers_type const &Get(TempPtrImpl<U> const &p)
            {
                return p.m_persistedHandlers;
            }
        };

    }   // namespace TempPtrDetail {

    template<class T>
    struct TempPtr : 
        TempPtrDetail::TempPtrImpl<T>
    {
        typedef TempPtr<T> this_type;
        typedef TempPtrDetail::TempPtrImpl<T> base_type;

        TempPtr() : 
            base_type()
        { }

        TempPtr(T *p, bool hasAlreadyPersisted = false) : 
            base_type(p, hasAlreadyPersisted)
        { }

        template<class TD>
        TempPtr(T *p, TD td) : 
            base_type(p, td)
        { }

        template<class TD, class ImplD>
        explicit TempPtr(TempPtrDetail::TempPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            base_type(pHolder)
        {
        }

        TempPtr(this_type const &other) : 
            base_type(other)
        { }

        template<class U>
        TempPtr(TempPtr<U> const &other) : 
            base_type(other)
        { }

        ~TempPtr()
        {
        }

        TempPtr &operator =(TempPtr const &other)
        {
            base_type::operator =(other);
            return *this;
        }

        template<class U>
        TempPtr &operator =(TempPtr<U> const &other)
        {
            base_type::operator =(other);
            return *this;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_H
