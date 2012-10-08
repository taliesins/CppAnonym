#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASCONST_H
#include <Urasandesu/CppAnonym/Traits/HasConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVectorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        namespace mpl = boost::mpl;

        template<
            class Value, 
            class T, 
            DWORD RAPID_SIZE,
            class Alloc
        >
        class RapidVectorIterator : 
            public boost::iterator_facade<
                RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>, 
                Value, 
                boost::random_access_traversal_tag>
        {
        private:
            typedef typename mpl::eval_if<
                Traits::HasConst<Value>, 
                mpl::identity<typename std::vector<T, Alloc>::const_iterator>, 
                mpl::identity<typename std::vector<T, Alloc>::iterator> >::type iterator_;

            typedef typename mpl::eval_if<
                Traits::HasConst<Value>,
                mpl::identity<RapidVectorIterator<Value, T, RAPID_SIZE, Alloc> >,
                mpl::identity<RapidVectorIterator<Value const, T, RAPID_SIZE, Alloc> > >::type const_iterator_;
        public:
            RapidVectorIterator() : 
                m_pThis(NULL), 
                m_isEnd(false),
                m_pBuf(NULL)
            { }

            explicit RapidVectorIterator(RapidVector<T, RAPID_SIZE, Alloc> *pThis, bool isEnd = false) : 
                m_pThis(pThis), 
                m_isEnd(isEnd),
                m_pBuf(NULL)
            {
                if (m_pThis->RunAsRapid())
                    m_pBuf = !isEnd ? m_pThis->RapidBuf() : m_pThis->RapidBuf() + m_pThis->m_size;
                else
                    m_i = !isEnd ? m_pThis->m_pVec->begin() : m_pThis->m_pVec->end();
            }

            template<
                class OtherValue, 
                class OtherT, 
                DWORD OTHER_RAPID_SIZE, 
                class OtherAlloc
            >
            RapidVectorIterator(RapidVectorIterator<OtherValue, OtherT, OTHER_RAPID_SIZE, OtherAlloc> const &other)
            {
                m_pThis = other.m_pThis;
                m_isEnd = other.m_isEnd;
                m_pBuf = other.m_pBuf;
                m_i = other.m_i;
            } 

            operator const_iterator_() const
            {
                return const_iterator_(*this);
            }
        
        private:
            friend class boost::iterator_core_access;
            
            template<class T, DWORD RAPID_SIZE, class Alloc>
            friend class RapidVector;

            template<
                class Value, 
                class T, 
                DWORD RAPID_SIZE, 
                class Alloc
            >
            friend class RapidVectorIterator;

            inline void increment() 
            { 
                if (m_pThis->RunAsRapid())
                    ++m_pBuf;
                else
                    ++m_i;
            }

            inline void advance(difference_type n) 
            { 
                if (m_pThis->RunAsRapid())
                    m_pBuf += n;
                else
                    m_i += n;
            }

            inline bool equal(RapidVectorIterator<Value, T, RAPID_SIZE, Alloc> const& other) const
            {
                if (m_pThis->RunAsRapid())
                    return m_pBuf == other.m_pBuf;
                else
                    return m_i == other.m_i;
            }

            inline reference dereference() const 
            { 
                return m_pThis->RunAsRapid() ? *m_pBuf : *m_i; 
            }

            difference_type distance_to(RapidVectorIterator<Value, T, RAPID_SIZE, Alloc> const& other) const
            {
                if (m_pThis->RunAsRapid())
                    return static_cast<difference_type>(other.m_pBuf - m_pBuf);
                else
                    return other.m_i - m_i;
            }

            RapidVector<T, RAPID_SIZE, Alloc> *m_pThis;
            bool m_isEnd;
            T *m_pBuf;
            iterator_ m_i;
        };
        
    }   // namespace RapidVectorDetail

    template<class T, DWORD RAPID_SIZE, class Alloc>
    class RapidVector
    {
    public:
        typedef RapidVector<T, RAPID_SIZE, Alloc> type;
	    typedef typename std::vector<T, Alloc>::allocator_type allocator_type;
	    typedef RapidVectorDetail::RapidVectorIterator<T const, T, RAPID_SIZE, Alloc> const_iterator;
	    typedef typename std::vector<T, Alloc>::const_pointer const_pointer;
	    typedef typename std::vector<T, Alloc>::const_reference const_reference;
	    typedef typename std::vector<T, Alloc>::const_reverse_iterator const_reverse_iterator;
	    typedef typename std::vector<T, Alloc>::difference_type difference_type;
	    typedef RapidVectorDetail::RapidVectorIterator<T, T, RAPID_SIZE, Alloc> iterator;
	    typedef typename std::vector<T, Alloc>::pointer pointer;
	    typedef typename std::vector<T, Alloc>::reference reference;
	    typedef typename std::vector<T, Alloc>::reverse_iterator reverse_iterator;
	    typedef typename std::vector<T, Alloc>::size_type size_type;
	    typedef typename std::vector<T, Alloc>::value_type value_type;
        typedef typename boost::is_pointer<T>::type is_value_type_pointer;
        typedef typename boost::remove_pointer<typename Traits::RemoveConst<T>::type>::type raw_value_type;
        typedef typename boost::has_trivial_constructor<raw_value_type>::type has_raw_value_type_trivial_constructor;
        typedef typename boost::has_trivial_destructor<raw_value_type>::type has_raw_value_type_trivial_destructor;
        typedef boost::integral_constant<bool, false> false_;

        RapidVector() : 
            m_pVec(NULL), 
            m_size(0), 
            m_capacity(RAPID_SIZE)
        { 
            ConstructRapidBuf(RapidBuf());
        }

        ~RapidVector() 
        {
            if (RunAsRapid())
                DestructRapidBuf(RapidBuf(), m_size);
            else
                DestroyVec(); 
        }

        RapidVector(type const &other) : 
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

        void reserve(size_type count)
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
        
        void push_back(typename boost::call_traits<T>::param_type val)
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

        void pop_back()
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

        template<class Iterator>
        void assign(Iterator first, Iterator last)
        {
            if (!empty())
                erase(begin(), end());
            
            for (Iterator i = first, i_end = last; i != i_end; ++i)
                push_back(*i);
        }

        iterator erase(const_iterator first, const_iterator last)
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

        inline type &operator =(type &other)
        {
            if (this != &other)
            {
                reserve(other.size());
                assign(other.begin(), other.end());
            }
            return *this;
        }

        inline const_reference operator[](size_type pos) const
        {
            return RunAsRapid() ? RapidBuf()[pos] : (*m_pVec)[pos];
        }

        inline reference operator[](size_type pos)
        {
            return RunAsRapid() ? RapidBuf()[pos] : (*m_pVec)[pos];
        }

	    inline iterator begin()
	    {
	        return iterator(this);
	    }

        inline const_iterator begin() const
        {
            return const_iterator(const_cast<type *>(this));
        }

        inline iterator end()
        {
            return iterator(this, true);
        }

        inline const_iterator end() const
        {
            return const_iterator(const_cast<type *>(this), true);
        }

        inline size_type size() const
        {
            return m_size;
        }

        inline size_type capacity() const
        {
            return m_capacity;
        }

        inline bool empty() const
        {
            return m_size == 0;
        }

        void resize(size_type newSize)
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

        inline bool RunAsRapid() const
        {
            return m_capacity <= RAPID_SIZE;
        }
    
    private:
        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
	    friend class RapidVectorDetail::RapidVectorIterator;

        inline T *RapidBuf()
        {
            return reinterpret_cast<T *>(m_pRapidBuf);
        }

        inline T const *RapidBuf() const
        {
            return reinterpret_cast<T *>(const_cast<PUINT64>(m_pRapidBuf));
        }

        static void CopyRapidBuf(T *pDstRapidBuf, T const *pSrcRapidBuf, size_type size)
        {
            _ASSERTE(size <= RAPID_SIZE);

            typedef copy_rapid_buf_impl_type<
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor, 
                has_raw_value_type_trivial_destructor
            > Impl;
            
            Impl::Copy(pDstRapidBuf, pSrcRapidBuf, size);
        }

        template<class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        struct copy_rapid_buf_impl_type
        {
            static inline void Copy(T *pDstRapidBuf, T const *pSrcRapidBuf, size_type size)
            {
                ::memcpy_s(pDstRapidBuf, size * sizeof(raw_value_type), pSrcRapidBuf, size * sizeof(raw_value_type));
            }
        };

        template<>
        struct copy_rapid_buf_impl_type<false_, false_, false_ > 
        { 
            static inline void Copy(T *pDstRapidBuf, T const *pSrcRapidBuf, size_type size)
            {
                for (T const *i = pSrcRapidBuf - 1, *i_end = i + size; i != i_end; --i_end)
                    *(--pDstRapidBuf + size) = *i_end;
            }
        };

        static void MoveRapidBuf(T *pDstRapidBuf, T *pSrcRapidBuf, size_type size)
        {
            _ASSERTE(size <= RAPID_SIZE);

            typedef move_rapid_buf_impl_type<
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor, 
                has_raw_value_type_trivial_destructor
            > Impl;
            
            Impl::Move(pDstRapidBuf, pSrcRapidBuf, size);
        }

        template<class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        struct move_rapid_buf_impl_type
        {
            static inline void Move(T *pDstRapidBuf, T *pSrcRapidBuf, size_type size)
            {
                CopyRapidBuf(pDstRapidBuf, pSrcRapidBuf, size);
            }
        };

        template<>
        struct move_rapid_buf_impl_type<false_, false_, false_ > 
        { 
            static inline void Move(T *pDstRapidBuf, T *pSrcRapidBuf, size_type size)
            {
                CopyRapidBuf(pDstRapidBuf, pSrcRapidBuf, size);
                DestructRapidBuf(pSrcRapidBuf, size);
            }
        };

        static void AssignVec(std::vector<T, Alloc> *&pVec, size_type newSize, T *pRapidBuf, size_type size)
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

        static void AssignRapidBuf(T *pRapidBuf, size_type newSize, std::vector<T, Alloc> const *pVec)
        {
            _ASSERTE(pVec->size() <= RAPID_SIZE);
            _ASSERTE(newSize <= RAPID_SIZE);

            typedef assign_rapid_buf_impl_type<
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor, 
                has_raw_value_type_trivial_destructor
            > Impl;

            Impl::Assign(pRapidBuf, newSize, pVec);
        }

        template<class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        struct assign_rapid_buf_impl_type
        {
            static inline void Assign(T *pRapidBuf, size_type newSize, std::vector<T, Alloc> const *pVec)
            {
                ::memcpy_s(pRapidBuf, newSize * sizeof(raw_value_type), &(*pVec)[0], newSize * sizeof(raw_value_type));
            }
        };

        template<>
        struct assign_rapid_buf_impl_type<false_, false_, false_ > 
        { 
            static inline void Assign(T *pRapidBuf, size_type newSize, std::vector<T, Alloc> const *pVec)
            {
                ::ZeroMemory(pRapidBuf, newSize * sizeof(raw_value_type));

                typedef std::vector<T, Alloc>::const_iterator Iterator;
                for (Iterator i = pVec->cbegin(), i_end = i + newSize; i != i_end; ++i)
                    *(pRapidBuf++) = *i;
            }
        };

        static void ConstructRapidBuf(T *pRapidBuf)
        {
            typedef construct_rapid_buf_impl_type<
                is_value_type_pointer, 
                has_raw_value_type_trivial_constructor
            > Impl;
            
            Impl::Construct(pRapidBuf);
        }

        template<class IsPointer, class HasTrivialConstructor>
        struct construct_rapid_buf_impl_type
        {
            static inline void Construct(T *pRapidBuf)
            {
                // Do nothing. Because T has trivial constructor in this case.
            }
        };

        template<>
        struct construct_rapid_buf_impl_type<false_, false_ > 
        { 
            static inline void Construct(T *pRapidBuf)
            {
                ::ZeroMemory(pRapidBuf, RAPID_BUF_SIZE * sizeof(UINT64));
            }
        };

        static void DestructRapidBuf(T *pRapidBuf, size_type size)
        {
            typedef destruct_rapid_buf_impl_type<
                is_value_type_pointer, 
                has_raw_value_type_trivial_destructor
            > Impl;
            
            Impl::Destruct(pRapidBuf, size);
        }

        template<class IsPointer, class HasTrivialDestructor>
        struct destruct_rapid_buf_impl_type
        {
            static inline void Destruct(T *pRapidBuf, size_type size)
            {
                // Do nothing. Because T has trivial constructor in this case.
            }
        };

        template<>
        struct destruct_rapid_buf_impl_type<false_, false_ > 
        { 
            static inline void Destruct(T *pRapidBuf, size_type size)
            {
                for (T *i = pRapidBuf - 1, *i_end = i + size; i != i_end; --i_end)
                    (*i_end).~raw_value_type();
                
                ::ZeroMemory(pRapidBuf, size * sizeof(raw_value_type));
            }
        };

        void DestroyVec()
        {
            if (m_pVec != NULL)
            {
                delete m_pVec;
                m_pVec = NULL;
            }
        }
	    
        std::vector<T, Alloc> *m_pVec;
        SIZE_T m_size;
        SIZE_T m_capacity;
        static size_t const RAPID_BUF_SIZE = (RAPID_SIZE * sizeof(T) + sizeof(UINT64) - 1) / sizeof(UINT64);
        UINT64 m_pRapidBuf[RAPID_BUF_SIZE];
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP