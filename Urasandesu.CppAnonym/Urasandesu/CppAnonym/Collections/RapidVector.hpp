#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::RapidVectorIterator() : 
            m_pThis(NULL), 
            m_isEnd(false),
            m_pBuf(NULL)
        { }

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

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::operator const_iterator_() const
        {
            return const_iterator_(*this);
        }

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::increment() 
        { 
            if (m_pThis->RunAsRapid())
                ++m_pBuf;
            else
                ++m_i;
        }

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        void RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::advance(difference_type n) 
        { 
            if (m_pThis->RunAsRapid())
                m_pBuf += n;
            else
                m_i += n;
        }

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        bool RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::equal(RapidVectorIterator<Value, T, RAPID_SIZE, Alloc> const& other) const
        {
            if (m_pThis->RunAsRapid())
                return m_pBuf == other.m_pBuf;
            else
                return m_i == other.m_i;
        }

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        typename RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::reference 
            RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::dereference() const 
        { 
            return m_pThis->RunAsRapid() ? *m_pBuf : *m_i; 
        }

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        typename RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::difference_type 
            RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>::distance_to(RapidVectorIterator<Value, T, RAPID_SIZE, Alloc> const& other) const
        {
            if (m_pThis->RunAsRapid())
                return static_cast<difference_type>(other.m_pBuf - m_pBuf);
            else
                return other.m_i - m_i;
        }

        
        
        
        
        template<class T, DWORD RAPID_SIZE, class Alloc>
        RapidVectorImpl<T, RAPID_SIZE, Alloc>::RapidVectorImpl() : 
            m_pVec(NULL), 
            m_size(0), 
            m_capacity(RAPID_SIZE)
        { 
            ConstructRapidBuf(RapidBuf());
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        RapidVectorImpl<T, RAPID_SIZE, Alloc>::~RapidVectorImpl() 
        {
            if (RunAsRapid())
                DestructRapidBuf(RapidBuf(), m_size);
            else
                DestroyVec(); 
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
                assign(other.begin(), other.end());
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
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::this_type &
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::operator=(typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::this_type &other)
        {
            if (this != &other)
            {
                reserve(other.size());
                assign(other.begin(), other.end());
            }
            return *this;
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::const_reference 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::operator[](typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::size_type pos) const
        {
            return RunAsRapid() ? RapidBuf()[pos] : (*m_pVec)[pos];
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::reference 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::operator[](typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::size_type pos)
        {
            return RunAsRapid() ? RapidBuf()[pos] : (*m_pVec)[pos];
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
	    inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::iterator 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::begin()
	    {
	        return iterator(this);
	    }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::const_iterator 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::begin() const
        {
            return const_iterator(const_cast<this_type *>(this));
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::iterator 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::end()
        {
            return iterator(this, true);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::const_iterator 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::end() const
        {
            return const_iterator(const_cast<this_type *>(this), true);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::size_type 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::size() const
        {
            return m_size;
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline typename RapidVectorImpl<T, RAPID_SIZE, Alloc>::size_type 
            RapidVectorImpl<T, RAPID_SIZE, Alloc>::capacity() const
        {
            return m_capacity;
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline bool RapidVectorImpl<T, RAPID_SIZE, Alloc>::empty() const
        {
            return m_size == 0;
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
        inline bool RapidVectorImpl<T, RAPID_SIZE, Alloc>::RunAsRapid() const
        {
            return m_capacity <= RAPID_SIZE;
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline T *RapidVectorImpl<T, RAPID_SIZE, Alloc>::RapidBuf()
        {
            return reinterpret_cast<T *>(m_pRapidBuf);
        }

        template<class T, DWORD RAPID_SIZE, class Alloc>
        inline T const *RapidVectorImpl<T, RAPID_SIZE, Alloc>::RapidBuf() const
        {
            return reinterpret_cast<T *>(const_cast<PUINT64>(m_pRapidBuf));
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
        inline void 
            CopyRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::Copy(
                typename CopyRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::pointer pDstRapidBuf, 
                typename CopyRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::const_pointer pSrcRapidBuf, 
                typename CopyRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::size_type size
            )
        {
            ::memcpy_s(pDstRapidBuf, size * sizeof(raw_value_type), pSrcRapidBuf, size * sizeof(raw_value_type));
        }

        template<class Facade>
        inline void 
            CopyRapidBufImpl<Facade, False, False, False>::Copy(
                typename CopyRapidBufImpl<Facade, False, False, False>::pointer pDstRapidBuf, 
                typename CopyRapidBufImpl<Facade, False, False, False>::const_pointer pSrcRapidBuf, 
                typename CopyRapidBufImpl<Facade, False, False, False>::size_type size
            )
        {
            for (raw_value_type const *i = pSrcRapidBuf - 1, *i_end = i + size; i != i_end; --i_end)
                *(--pDstRapidBuf + size) = *i_end;
        }

        
        
        
        
        template<class Facade, class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        inline void 
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
        inline 
            void MoveRapidBufImpl<Facade, False, False, False>::Move(
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

        
        
        
        
        
        template<class Facade, class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        inline void 
            AssignRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::Assign(
                typename AssignRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::pointer pRapidBuf, 
                typename AssignRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::size_type newSize, 
                typename AssignRapidBufImpl<Facade, IsPointer, HasTrivialConstructor, HasTrivialDestructor>::internal_vector_type const *pVec
            )
        {
            ::memcpy_s(pRapidBuf, newSize * sizeof(raw_value_type), &(*pVec)[0], newSize * sizeof(raw_value_type));
        }

        template<class Facade>
        inline void 
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

        
        
        
        
        
        template<class Facade, class IsPointer, class HasTrivialConstructor>
        inline void 
            ConstructRapidBufImpl<Facade, IsPointer, HasTrivialConstructor>::Construct(
                typename ConstructRapidBufImpl<Facade, IsPointer, HasTrivialConstructor>::pointer pRapidBuf
            )
        {
            // Do nothing. Because T has trivial constructor in this case.
        }

        template<class Facade>
        inline void 
            ConstructRapidBufImpl<Facade, False, False>::Construct(
                typename ConstructRapidBufImpl<Facade, False, False>::pointer pRapidBuf
            )
        {
            ::ZeroMemory(pRapidBuf, RAPID_BUF_SIZE * sizeof(UINT64));
        }

        
        
        
        
        
        template<class Facade, class IsPointer, class HasTrivialDestructor>
        inline void 
            DestructRapidBufImpl<Facade, IsPointer, HasTrivialDestructor>::Destruct(
                typename DestructRapidBufImpl<Facade, IsPointer, HasTrivialDestructor>::pointer pRapidBuf, size_type size
            )
        {
            // Do nothing. Because T has trivial constructor in this case.
        }

        template<class Facade>
        inline void 
            DestructRapidBufImpl<Facade, False, False>::Destruct(
                typename DestructRapidBufImpl<Facade, False, False>::pointer pRapidBuf, 
                typename DestructRapidBufImpl<Facade, False, False>::size_type size
            )
        {
            for (value_type *i = pRapidBuf - 1, *i_end = i + size; i != i_end; --i_end)
                (*i_end).~raw_value_type();
                
            ::ZeroMemory(pRapidBuf, size * sizeof(raw_value_type));
        }

    }   // namespace RapidVectorDetail

    
    template<class T, DWORD RAPID_SIZE, class Alloc>
    RapidVector<T, RAPID_SIZE, Alloc>::RapidVector() : 
        RapidVector<T, RAPID_SIZE, Alloc>::base_type()
    { }

    template<class T, DWORD RAPID_SIZE, class Alloc>
    RapidVector<T, RAPID_SIZE, Alloc>::~RapidVector()
    { }

    template<class T, DWORD RAPID_SIZE, class Alloc>
    RapidVector<T, RAPID_SIZE, Alloc>::RapidVector(typename RapidVector<T, RAPID_SIZE, Alloc>::this_type const &other) : 
        RapidVector<T, RAPID_SIZE, Alloc>::base_type(other)
    { }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP