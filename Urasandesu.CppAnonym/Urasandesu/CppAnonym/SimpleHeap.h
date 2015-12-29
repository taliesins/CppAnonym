/* 
 * File: SimpleHeap.h
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
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#define URASANDESU_CPPANONYM_SIMPLEHEAP_H

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H
#include <Urasandesu/CppAnonym/SimpleHeapFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SimpleHeapDetail {

        using boost::iterator_core_access;
        using boost::iterator_facade;
        using boost::noncopyable;
        using boost::ptr_vector;
        using boost::pool;
        using boost::random_access_traversal_tag;
        using std::unary_function;
        using std::vector;



        template<class T>
        class ReferenceEqualTo : 
            unary_function<T, bool>
        {
        public:
            ReferenceEqualTo(T *p) : 
                m_p(p)
            { }
            
            bool operator()(T const &x) const
            {
                return m_p == &x;
            }

        private:
            T *m_p;
        };

        template<class T>
        class PointerEqualTo : 
            unary_function<T *, bool>
        {
        public:
            PointerEqualTo(T *p) : 
                m_p(p)
            { }
            
            bool operator()(T const *x) const
            {
                return m_p == x;
            }

        private:
            T *m_p;
        };
    
        
        
        
        
        template<class T, class Tag>
        struct SimpleHeapImpl;
        
        template<class T>
        class SimpleHeapImpl<T, VeryQuickHeapButMustAccessThroughEachMethod> : 
            noncopyable
        {
        public:
            typedef Collections::RapidVector<T> internal_vector_type;
            typedef typename internal_vector_type::const_iterator const_iterator;
            typedef typename internal_vector_type::iterator iterator;
            typedef typename internal_vector_type::size_type size_type;
            typedef typename internal_vector_type::const_reference const_reference;
            typedef typename internal_vector_type::reference reference;
            
            SimpleHeapImpl() : 
                m_pCurrent(&m_array[0]), 
                m_lastCapacity(m_array.capacity()) 
            { } 
            
            ~SimpleHeapImpl()
            { }
            
            T *New();
            
            void DeleteLast()
            {
                if (m_array.empty())
                    return;
                
                DeleteLastCore();
            }
            
            void Delete(T *pObj);

            size_type size() const
            {
                return m_array.size();
            }
            
            reference operator [](SIZE_T ix)
            {
                return m_array[ix];
            }
            
            const_reference operator [](SIZE_T ix) const
            {
                return m_array[ix];
            }

            iterator begin()
            {
                return m_array.begin();
            }

            const_iterator begin() const
            {
                return m_array.begin();
            }

            iterator end()
            {
                return m_array.end();
            }
            
            const_iterator end() const
            {
                return m_array.end();
            }

        private:    
            void DeleteLastCore()
            {
                T *pObj = &(*this)[size() - 1];
                m_array.pop_back();
                Utilities::DestructionDistributor<T>::Destruct(pObj);
            }

            internal_vector_type m_array;
            T *m_pCurrent;
            SIZE_T m_lastCapacity;
        };

        
        
        
        
        template<class T, class Tag>
        class QuickHeapIterator : 
            public iterator_facade<QuickHeapIterator<T, Tag>, T, random_access_traversal_tag>
        {
        public:
            typedef typename iterator_facade<QuickHeapIterator<T, Tag>, T, random_access_traversal_tag>::reference reference;
            typedef typename iterator_facade<QuickHeapIterator<T, Tag>, T, random_access_traversal_tag>::difference_type difference_type;            

        private:
            typedef QuickHeapIterator<T, Tag> this_type;
            typedef vector<T *> internal_vector_type;
            typedef typename internal_vector_type::iterator internal_iterator;
            typedef typename internal_vector_type::const_iterator internal_const_iterator;
            typedef this_type const_iterator;
            typedef this_type iterator;
            typedef typename internal_vector_type::size_type size_type;
            typedef const reference const_reference;

        public:
            QuickHeapIterator() : 
                m_isEnd(false)
            {}

            explicit QuickHeapIterator(internal_iterator i, bool isEnd = false) : 
                m_i(i), 
                m_isEnd(isEnd)
            {}

            void increment()
            { 
                _ASSERTE(!m_isEnd);
                ++m_i;
            }

            void decrement()
            { 
                _ASSERTE(!m_isEnd);
                --m_i;
            }
            
            void advance(difference_type n)
            { 
                _ASSERTE(!m_isEnd);
                m_i += n;
            }
            
            bool equal(this_type const& other) const
            {
                return m_i == other.m_i;
            }
            
            reference dereference() const
            { 
                _ASSERTE(!m_isEnd);
                return **m_i;
            }
            
            difference_type distance_to(this_type const& other) const
            {
                _ASSERTE(!other.m_isEnd);
                return other.m_i - m_i;
            }
            
        private:
            template<class T, class Tag> friend struct SimpleHeapImpl;
            friend class iterator_core_access;

            internal_iterator m_i;
            bool m_isEnd;
        };

        template<class T>
        class SimpleHeapImpl<T, QuickHeap> : 
            noncopyable
        {
        public:
            typedef SimpleHeapImpl<T, QuickHeap> this_type;
            typedef QuickHeapIterator<T, QuickHeap> iterator;
            typedef typename iterator::internal_vector_type internal_vector_type;
            typedef typename iterator::internal_iterator internal_iterator;
            typedef typename iterator::internal_const_iterator internal_const_iterator;
            typedef typename iterator::const_iterator const_iterator;
            typedef typename iterator::size_type size_type;
            typedef typename iterator::const_reference const_reference;
            typedef typename iterator::reference reference;

            SimpleHeapImpl() : 
                m_pool(sizeof(T))
            { }
            
            ~SimpleHeapImpl();            
            T *New();
            
            void DeleteLast()
            {
                if (m_array.empty())
                    return;
                
                DeleteLastCore();
            }
            
            void Delete(T *pObj);
            
            size_type size() const
            {
                return m_array.size();
            }
            
            reference operator [](SIZE_T ix)
            {
                return *m_array[ix];
            }
            
            const_reference operator [](SIZE_T ix) const
            {
                return *m_array[ix];
            }

            iterator begin()
            {
                return iterator(m_array.begin());
            }

            const_iterator begin() const
            {
                return const_iterator(const_cast<this_type *>(this)->m_array.begin());
            }

            iterator end()
            {
                return iterator(m_array.end(), true);
            }
            
            const_iterator end() const
            {
                return const_iterator(const_cast<this_type *>(this)->m_array.end(), true);
            }

        private:    
            void DeleteLastCore()
            {
                T *pObj = &(*this)[size() - 1];
                m_array.pop_back();
                Utilities::DestructionDistributor<T>::Destruct(pObj);
                m_pool.free(pObj);
            }

            pool<> m_pool;
            internal_vector_type m_array;
        };

        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, QuickHeapWithoutRandomAccess> : 
            noncopyable
        {
        public:
            SimpleHeapImpl() : 
                m_pool(sizeof(T))
            { }
            
            ~SimpleHeapImpl()
            {
                // This implementation isn't supported enumerating the objects that was constructed  by it.
                // Therefore, the such objects must be destructed with the method Delete(T *).
            }
            
            T *New();
            
            template<class A1>
            inline T *New(A1 arg1);

            template<class A1, class A2>
            inline T *New(A1 arg1, A2 arg2);

            template<class A1, class A2, class A3>
            inline T *New(A1 arg1, A2 arg2, A3 arg3);

            void Delete(T *pObj);
        private:    
            pool<> m_pool;
        };
    
        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, DefaultHeap> : 
            noncopyable
        {
        public:
            typedef ptr_vector<T> internal_vector_type;
            typedef typename internal_vector_type::const_iterator const_iterator;
            typedef typename internal_vector_type::iterator iterator;
            typedef typename internal_vector_type::size_type size_type;
            typedef typename internal_vector_type::const_reference const_reference;
            typedef typename internal_vector_type::reference reference;

            T *New()
            {
                T *pObj = new T();
                m_array.push_back(pObj);
                return pObj;
            }
            
            void DeleteLast()
            {
                if (m_array.empty())
                    return;
                m_array.pop_back();
            }
            
            void Delete(T *pObj);
            
            size_type size() const
            {
                return m_array.size();
            }
            
            reference operator [](SIZE_T ix)
            {
                return m_array[ix];
            }
            
            const_reference operator [](SIZE_T ix) const
            {
                return m_array[ix];
            }

            iterator begin()
            {
                return m_array.begin();
            }

            const_iterator begin() const
            {
                return m_array.begin();
            }

            iterator end()
            {
                return m_array.end();
            }
            
            const_iterator end() const
            {
                return m_array.end();
            }

        private:
            ptr_vector<T> m_array;
        };
    
        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, DefaultHeapWithoutRandomAccess> : 
            noncopyable
        {
        public:
            T *New()
            {
                T *pObj = new T();
                return pObj;
            }
            
            template<class A1>
            T *New(A1 arg1)
            {
                T *pObj = new T(arg1);
                return pObj;
            }

            template<class A1, class A2>
            T *New(A1 arg1, A2 arg2)
            {
                T *pObj = new T(arg1, arg2);
                return pObj;
            }

            void Delete(T *pObj)
            {
                delete pObj;
            }
        };
    
    }   // namespace SimpleHeapDetail
    
    template<class T, class Tag>
    struct SimpleHeap : 
        SimpleHeapDetail::SimpleHeapImpl<T, Tag>
    {
        typedef SimpleHeap<T, Tag> this_type;
        typedef SimpleHeapDetail::SimpleHeapImpl<T, Tag> base_type;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAP_H
