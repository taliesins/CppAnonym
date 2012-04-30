#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASCONST_H
#include <Urasandesu/CppAnonym/Traits/HasConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVectorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace Detail {

        namespace mpl = boost::mpl;

        template<
            class Value, 
            class T, 
            class Alloc, 
            DWORD RAPID_SIZE
        >
        class RapidVectorIterator : 
            public boost::iterator_facade<
                RapidVectorIterator<Value, T, Alloc, RAPID_SIZE>, 
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
                mpl::identity<RapidVectorIterator<Value, T, Alloc, RAPID_SIZE> >,
                mpl::identity<RapidVectorIterator<Value const, T, Alloc, RAPID_SIZE> > >::type const_iterator_;
        public:
            RapidVectorIterator() : 
                m_pThis(NULL), 
                m_isEnd(false),
                m_pBuf(NULL)
            { }

            explicit RapidVectorIterator(RapidVector<T, Alloc, RAPID_SIZE> *pThis, bool isEnd = false) : 
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
                class OtherAlloc, 
                DWORD OTHER_RAPID_SIZE
            >
            RapidVectorIterator(RapidVectorIterator<OtherValue, OtherT, OtherAlloc, OTHER_RAPID_SIZE> const &other)
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
            
            template<class T, class Alloc, DWORD RAPID_SIZE>
            friend class RapidVector;

            template<
                class Value, 
                class T, 
                class Alloc, 
                DWORD RAPID_SIZE
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

            inline bool equal(RapidVectorIterator<Value, T, Alloc, RAPID_SIZE> const& other) const
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

            difference_type distance_to(RapidVectorIterator<Value, T, Alloc, RAPID_SIZE> const& other) const
            {
                if (m_pThis->RunAsRapid())
                    return static_cast<difference_type>(other.m_pBuf - m_pBuf);
                else
                    return other.m_i - m_i;
            }

            RapidVector<T, Alloc, RAPID_SIZE> *m_pThis;
            bool m_isEnd;
            T *m_pBuf;
            iterator_ m_i;
        };
        
    }   // namespace Detail

    template<class T, class Alloc, DWORD RAPID_SIZE>
    class RapidVector
    {
    public:
        typedef RapidVector<T, Alloc, RAPID_SIZE> type;
	    typedef typename std::vector<T, Alloc>::allocator_type allocator_type;
	    typedef Detail::RapidVectorIterator<T const, T, Alloc, RAPID_SIZE> const_iterator;
	    typedef typename std::vector<T, Alloc>::const_pointer const_pointer;
	    typedef typename std::vector<T, Alloc>::const_reference const_reference;
	    typedef typename std::vector<T, Alloc>::const_reverse_iterator const_reverse_iterator;
	    typedef typename std::vector<T, Alloc>::difference_type difference_type;
	    typedef Detail::RapidVectorIterator<T, T, Alloc, RAPID_SIZE> iterator;
	    typedef typename std::vector<T, Alloc>::pointer pointer;
	    typedef typename std::vector<T, Alloc>::reference reference;
	    typedef typename std::vector<T, Alloc>::reverse_iterator reverse_iterator;
	    typedef typename std::vector<T, Alloc>::size_type size_type;
	    typedef typename std::vector<T, Alloc>::value_type value_type;

        RapidVector() : m_size(0), m_pVec(NULL) { }
        ~RapidVector() { DestroyVec(); }
        
        void push_back(typename boost::call_traits<T>::param_type val)
        {
            if (m_size < RAPID_SIZE)
            {
                RapidBuf()[m_size++] = val;
                return;
            }
            
            if (m_size == RAPID_SIZE)
            {
                AssignVec(m_pVec, m_size, RapidBuf());
                ++m_size;
            }
            m_pVec->push_back(val);
        }

        void pop_back()
        {
            _ASSERTE(!empty());

            if (RunAsRapid())
            {
                --m_size;
                return;
            }

            m_pVec->pop_back();
            // NOTE: std::vector::max_size has no effect by calling the pop_back method.
            if (--m_size == RAPID_SIZE)
            {
                DestroyVec();
            }
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
                    m_size -= static_cast<difference_type>(last.m_pBuf - first.m_pBuf);
                    return begin();
                }
                else
                {
                    difference_type diff = static_cast<difference_type>(first.m_pBuf - RapidBuf());
                    size_type size = static_cast<size_type>(RapidBuf() + m_size - last.m_pBuf) * sizeof(T);
                    ::memcpy_s(RapidBuf() + diff, size, last.m_pBuf, size);
                    m_size -= m_size - diff - size;
                    return begin();
                }
            }

            m_pVec->erase(first.m_i, last.m_i);
            m_size = m_pVec->size();
            if (m_size < RAPID_SIZE)
            {
                ::memcpy_s(RapidBuf(), m_size, &(*m_pVec)[0], m_size);
                DestroyVec();
            }

            return begin();
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
            return RunAsRapid() ? m_size : m_pVec->size();
        }

        inline size_type max_size() const
        {
            return RunAsRapid() ? RAPID_SIZE : m_pVec->max_size();
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
                AssignVec(m_pVec, newSize, RapidBuf());
                m_size = newSize;
            }
            m_pVec->resize(newSize);
        }

        inline bool RunAsRapid() const
        {
            return m_size <= RAPID_SIZE;
        }
    
    private:
        template<class Value, class T, class Alloc, DWORD RAPID_SIZE>
	    friend class Detail::RapidVectorIterator;
	    
        std::vector<T, Alloc> *m_pVec;
        SIZE_T m_size;
        UINT64 m_pRapidBuf[(RAPID_SIZE * sizeof(T) + sizeof(UINT64) - 1) / sizeof(UINT64)];

        inline T *RapidBuf()
        {
            return reinterpret_cast<T *>(m_pRapidBuf);
        }

        inline T const *RapidBuf() const
        {
            return reinterpret_cast<T *>(const_cast<PUINT64>(m_pRapidBuf));
        }

        static void AssignVec(std::vector<T, Alloc> *&pVec, size_type newSize, T *pRapidBuf)
        {
            pVec = new std::vector<T, Alloc>(newSize);
            pVec->assign(pRapidBuf, pRapidBuf + RAPID_SIZE);
        }

        void DestroyVec()
        {
            if (m_pVec != NULL)
            {
                delete m_pVec;
                m_pVec = NULL;
            }
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP