/* 
 * File: RapidVector.hpp
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
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::RapidVectorIterator(RapidVectorImpl<T, RAPID_SIZE, Alloc> *pThis, bool isEnd) : 
            m_pThis(pThis), 
            m_isEnd(isEnd),
            m_pBuf(NULL)
        {
            if (m_pThis->RunAsRapid())
                m_pBuf = !isEnd ? m_pThis->RapidBuf() : m_pThis->RapidBuf() + m_pThis->m_size;
            else
                m_i = !isEnd ? m_pThis->m_pVec->begin() : m_pThis->m_pVec->end();
        }

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        template<class OtherValue, class OtherT, DWORD OTHER_RAPID_SIZE, class OtherAlloc>
        RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::RapidVectorIterator(RapidVectorIterator<OtherValue, OtherT, OTHER_RAPID_SIZE, OtherAlloc> const &other)
        {
            m_pThis = other.m_pThis;
            m_isEnd = other.m_isEnd;
            m_pBuf = other.m_pBuf;
            m_i = other.m_i;
        } 

        template<class T, DWORD RAPID_SIZE, class Alloc>
        RapidVectorImpl<T, RAPID_SIZE, Alloc>::RapidVectorImpl(typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::this_type const &other) : 
            m_pVec(NULL), 
            m_size(0), 
            m_capacity(RAPID_SIZE)
        {
            ConstructRapidBuf(RapidBuf());
            
            if (this != &other)
            {
                reserve(other.size());
                assign(other.cbegin(), other.cend());
            }
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::reserve(size_type count)
        {
            if (count <= capacity())
                return;

            if (count <= RAPID_SIZE)
                return;

            if (RunAsRapid() && RAPID_SIZE < count)
                AssignVec(m_pVec, count, RapidBuf(), m_size);
            m_pVec->reserve(count);
            m_capacity = m_pVec->capacity();
        }
        
        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::push_back(typename boost::call_traits<T>::param_type val)
        {
            if (RunAsRapid() && m_size < RAPID_SIZE)
            {
                RapidBuf()[m_size++] = val;
                return;
            }
            
            if (RunAsRapid() && m_size == RAPID_SIZE)
            {
                AssignVec(m_pVec, m_size, RapidBuf(), RAPID_SIZE);
                ++m_size;
            }
            m_pVec->push_back(val);
            m_size = m_pVec->size();
            m_capacity = m_pVec->capacity();
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::pop_back()
        {
            _ASSERTE(!empty());

            if (RunAsRapid())
            {
                DestructRapidBuf(RapidBuf() + m_size - 1, m_size);
                --m_size;
                return;
            }

            m_pVec->pop_back();
            m_size = m_pVec->size();
            // NOTE: std::vector::capacity() has no effect by calling the pop_back method.
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        template<class Iterator>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::assign(Iterator first, Iterator last)
        {
            if (!empty())
                erase(begin(), end());
            
            for (Iterator i = first, i_end = last; i != i_end; ++i)
                push_back(*i);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::iterator 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::erase(
                typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::const_iterator first, 
                typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::const_iterator last
            )
        {
            _ASSERTE(!empty());

            if (this != first.m_pThis || this != last.m_pThis)
                return end();

            if (RunAsRapid())
            {
                if (last.m_pBuf == RapidBuf() + m_size)
                {
                    difference_type diff = static_cast<difference_type>(last.m_pBuf - first.m_pBuf);
                    DestructRapidBuf(RapidBuf() + m_size - diff, diff);
                    m_size -= diff;
                    return begin();
                }
                else
                {
                    difference_type diff = static_cast<difference_type>(first.m_pBuf - RapidBuf());
                    size_type size = static_cast<size_type>(RapidBuf() + m_size - last.m_pBuf);
                    MoveRapidBuf(RapidBuf() + diff, last.m_pBuf, size);
                    m_size -= m_size - diff - size;
                    return begin();
                }
            }

            m_pVec->erase(first.m_i, last.m_i);
            m_size = m_pVec->size();
            // NOTE: std::vector::capacity() has no effect by calling the erase() method.

            return begin();
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::resize(size_type newSize)
        {
            if (newSize <= RAPID_SIZE)
            {
                m_size = newSize;
                return;
            }
            
            if (RunAsRapid() && RAPID_SIZE < newSize)
            {
                AssignVec(m_pVec, newSize, RapidBuf(), RAPID_SIZE);
                m_size = newSize;
            }
            m_pVec->resize(newSize);
            m_capacity = m_pVec->capacity();
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::CopyRapidBuf(T *pDstRapidBuf, T const *pSrcRapidBuf, size_type size)
        {
            _ASSERTE(size <= RAPID_SIZE);

            typedef CopyRapidBufImpl<
                facade,
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor, 
                has_raw_value_type_trivial_destructor
            > Impl;
            
            Impl::Copy(pDstRapidBuf, pSrcRapidBuf, size);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::MoveRapidBuf(T *pDstRapidBuf, T *pSrcRapidBuf, size_type size)
        {
            _ASSERTE(size <= RAPID_SIZE);

            typedef MoveRapidBufImpl<
                facade,
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor, 
                has_raw_value_type_trivial_destructor
            > Impl;
            
            Impl::Move(pDstRapidBuf, pSrcRapidBuf, size);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::AssignVec(std::vector<T, Alloc> *&pVec, size_type newSize, T *pRapidBuf, size_type size)
        {
            _ASSERTE(size <= RAPID_SIZE);

            pVec = new std::vector<T, Alloc>();
            pVec->reserve(newSize);
            if (0 < size)
            {
                pVec->assign(pRapidBuf, pRapidBuf + size);
                DestructRapidBuf(pRapidBuf, size);
            }
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::AssignRapidBuf(T *pRapidBuf, size_type newSize, std::vector<T, Alloc> const *pVec)
        {
            _ASSERTE(pVec->size() <= RAPID_SIZE);
            _ASSERTE(newSize <= RAPID_SIZE);

            typedef AssignRapidBufImpl<
                facade,
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor, 
                has_raw_value_type_trivial_destructor
            > Impl;

            Impl::Assign(pRapidBuf, newSize, pVec);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::ConstructRapidBuf(T *pRapidBuf)
        {
            typedef ConstructRapidBufImpl<
                facade,
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor
            > Impl;
            
            Impl::Construct(pRapidBuf);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::DestructRapidBuf(T *pRapidBuf, size_type size)
        {
            typedef DestructRapidBufImpl<
                facade,
                is_value_type_pointer, 
                has_raw_value_type_trivial_destructor
            > Impl;
            
            Impl::Destruct(pRapidBuf, size);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorImpl<T, RAPID_SIZE, Alloc>::DestroyVec()
        {
            if (m_pVec != NULL)
            {
                delete m_pVec;
                m_pVec = NULL;
            }
        }





        template<class Facade, class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        void 
            MoveRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::Move(
                typename MoveRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::pointer pDstRapidBuf, 
                typename MoveRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::pointer pSrcRapidBuf, 
                typename MoveRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::size_type size
            )
        {
            typedef CopyRapidBufImpl<
                Facade, 
                IsPointer, 
                HasTrivialConstructor, 
                HasTrivialDestructor
            > Impl;

            Impl::Copy(pDstRapidBuf, pSrcRapidBuf, size);
        }

        template<class Facade>
        void 
            MoveRapidBufImpl<Facade, False, False, False>::Move(
                typename MoveRapidBufImpl<Facade, False, False, False>::pointer pDstRapidBuf, 
                typename MoveRapidBufImpl<Facade, False, False, False>::pointer pSrcRapidBuf, 
                typename MoveRapidBufImpl<Facade, False, False, False>::size_type size
            )
        {
            {
                typedef CopyRapidBufImpl<
                    Facade, 
                    False, 
                    False, 
                    False
                > Impl;

                Impl::Copy(pDstRapidBuf, pSrcRapidBuf, size);
            }

            {
                typedef DestructRapidBufImpl<
                    Facade,
                    False, 
                    False
                > Impl;
            
                Impl::Destruct(pSrcRapidBuf, size);
            }
        }

        
        
        
        

        template<class Facade>
        void 
            AssignRapidBufImpl<Facade, False, False, False>::Assign(
                typename AssignRapidBufImpl<Facade, False, False, False>::pointer pRapidBuf, 
                typename AssignRapidBufImpl<Facade, False, False, False>::size_type newSize, 
                typename AssignRapidBufImpl<Facade, False, False, False>::internal_vector_type const *pVec
            )
        {
            ::ZeroMemory(pRapidBuf, newSize * sizeof(raw_value_type));

            typedef typename internal_vector_type::const_iterator Iterator;
            for (Iterator i = pVec->cbegin(), i_end = i + newSize; i != i_end; ++i)
                *(pRapidBuf++) = *i;
        }

    }   // namespace RapidVectorDetail

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
