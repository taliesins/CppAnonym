/* 
 * File: TempPtr.hpp
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_H
#include <Urasandesu/CppAnonym/Utilities/TempPtr.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        template<class T>
        TempPtrImpl<T>::TempPtrImpl() : 
            m_pHolder(),
            m_state(TempPtrStates::TPS_NONE),
            m_persistedHandlers()
        { }

        template<class T>
        TempPtrImpl<T>::TempPtrImpl(T *p, bool hasAlreadyPersisted) : 
            m_pHolder(),
            m_state(!hasAlreadyPersisted ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED),
            m_persistedHandlers()
        { 
            if (!hasAlreadyPersisted)
                m_pHolder.Set<intrusive_ptr<holder_type> >(new TempPtrHolderImpl<T, DefaultDeleter, DefaultDeleter>(p, DefaultDeleter(), DefaultDeleter()));
            else
                m_pHolder.Set<T *>(p);
        }

        template<class T>
        template<class TD>
        TempPtrImpl<T>::TempPtrImpl(T *p, TD td) : 
            m_pHolder(),
            m_state(TempPtrStates::TPS_NONE),
            m_persistedHandlers()
        { 
            m_pHolder.Set<intrusive_ptr<holder_type> >(new TempPtrHolderImpl<T, TD, DefaultDeleter>(p, td, DefaultDeleter()));
        }

        template<class T>
        template<class TD, class ImplD>
        TempPtrImpl<T>::TempPtrImpl(TempPtrHolderImpl<T, TD, ImplD> *pHolder) : 
            m_pHolder(),
            m_state(TempPtrStates::TPS_NONE),
            m_persistedHandlers()
        { 
            m_pHolder.Set<intrusive_ptr<holder_type> >(pHolder);
        }

        template<class T>
        TempPtrImpl<T>::TempPtrImpl(this_type const &other) : 
            m_pHolder(),
            m_state(!other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED),
            m_persistedHandlers(other.m_persistedHandlers)
        { 
            if (!other.IsPersisted())
                m_pHolder.Assign<intrusive_ptr<holder_type> >(other.m_pHolder);
            else
                m_pHolder.Set<T *>(other.Get());
        }

        template<class T>
        template<class U>
        TempPtrImpl<T>::TempPtrImpl(TempPtrImpl<U> const &other) : 
            m_pHolder(),
            m_state(!other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED),
            m_persistedHandlers(PersistedHandlersAccessor<U>::Get(other))
        { 
            if (!other.IsPersisted())
                m_pHolder.Assign<intrusive_ptr<holder_type> >(TempPtrHolderAccessor<U>::Get(other));
            else
                m_pHolder.Set<T *>(other.Get());
        }

        template<class T>
        TempPtrImpl<T>::~TempPtrImpl()
        {
            Clear();
        }

        template<class T>
        typename TempPtrImpl<T>::this_type &TempPtrImpl<T>::operator =(this_type const &other)
        {
            if (this != &other)
            {
                Clear();

                if (!other.IsPersisted())
                    m_pHolder.Assign<intrusive_ptr<holder_type> >(other.m_pHolder);
                else
                    m_pHolder.Set<T *>(other.Get());

                m_state = !other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED;
                    
                m_persistedHandlers = other.m_persistedHandlers;
            }
            return *this;
        }

        template<class T>
        template<class U>
        typename TempPtrImpl<T>::this_type &TempPtrImpl<T>::operator =(TempPtrImpl<U> const &other)
        {
            Clear();

            if (!other.IsPersisted())
                m_pHolder.Assign<intrusive_ptr<holder_type> >(TempPtrHolderAccessor<U>::Get(other));
            else
                m_pHolder.Set<T *>(other.Get());

            m_state = !other.IsPersisted() ? TempPtrStates::TPS_NONE : TempPtrStates::TPS_HAS_ALREADY_PERSISTED;
                    
            auto const &persistedHandlers = PersistedHandlersAccessor<U>::Get(other);
            m_persistedHandlers.reserve(persistedHandlers.size());
            m_persistedHandlers.assign(persistedHandlers.cbegin(), persistedHandlers.cend());
                
            return *this;
        }

        template<class T>
        T *TempPtrImpl<T>::Get() const
        {
            switch (m_state.Value())
            {
                case TempPtrStates::TPS_NONE:
                case TempPtrStates::TPS_PERSISTED:
                    return static_cast<T *>(m_pHolder.Get<intrusive_ptr<holder_type> >()->Pointer());
                case TempPtrStates::TPS_HAS_ALREADY_PERSISTED:
                    return m_pHolder.Get<T *>();
                default:
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
            }
        }

        template<class T>
        void TempPtrImpl<T>::Persist()
        {
            if (!IsPersisted())
            {
                auto lastState = TempPtrStates(m_state);
                m_state = TempPtrStates::TPS_PERSISTED;
                if (!m_persistedHandlers.empty())
                {
                    try
                    {
                        for (auto i = m_persistedHandlers.begin(), i_end = m_persistedHandlers.end(); i != i_end; ++i)
                            (**i)(this, NULL);
                    }
                    catch (...)
                    {
                        m_state = lastState;
                        throw;
                    }
                }
                m_pHolder.Get<intrusive_ptr<holder_type> >()->DisableDeletion();
            }
        }

        template<class T>
        void TempPtrImpl<T>::Clear()
        {
            switch (m_state.Value())
            {
                case TempPtrStates::TPS_NONE:
                case TempPtrStates::TPS_PERSISTED:
                    m_pHolder.Clear<intrusive_ptr<holder_type> >();
                    break;
                case TempPtrStates::TPS_HAS_ALREADY_PERSISTED:
                    m_pHolder.Clear<T *>();
                    break;
                default:
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
            }

            m_state = TempPtrStates::TPS_NONE;
            m_persistedHandlers = persisted_handlers_type();
        }

    }   // namespace TempPtrDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
