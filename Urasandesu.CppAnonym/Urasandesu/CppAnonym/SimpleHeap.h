#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#define URASANDESU_CPPANONYM_SIMPLEHEAP_H

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

namespace Urasandesu { namespace CppAnonym {
    
    struct DefaultHeap;
    struct QuickHeap;
    struct VeryQuickHeapButMustUseSubscriptOperator;    // Very quick version for small objects allocation.
                                                        // In particular, the size is less than between 32 to 40, and when they are performed a lot of allocation and free.
                                                        // Although must use the subscript operator [] if access the allocated object after a while, 
                                                        // because the allocated objects are moved when the heap is over a threshold size.
    
    namespace Detail {
    
        template<class T, class Tag>
        struct SimpleHeapImpl;
        
        template<class T>
        class SimpleHeapImpl<T, VeryQuickHeapButMustUseSubscriptOperator>
        {
        public:
            typedef Collections::RapidVector<T> TArray;
            
            SimpleHeapImpl() : m_pCurrent(&m_array[0]), m_lastMaxSize(m_array.max_size()) { }

            T *New()
            {
                T *pObj = NULL;
                m_array.resize(m_array.size() + 1);
                if (m_lastMaxSize < m_array.max_size())
                {
                    m_lastMaxSize = m_array.max_size();
                    m_pCurrent = &m_array[0] + m_array.size() - 1;
                }
                pObj = m_pCurrent;
                ++m_pCurrent;
#pragma warning(push)
#pragma warning(disable: 4345)
                new(pObj)T();
#pragma warning(pop)
                return pObj;
            }

            inline void DeleteLast()
            {
                if (m_array.empty())
                    return;
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                pObj->~T();
            }

            inline SIZE_T Size()
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return &m_array[ix];
            }
            
            ~SimpleHeapImpl()
            {
                for (T const *i = &m_array[0], *i_end = i + m_array.size(); i != i_end; ++i)
                    (*i).~T();
            }
        
        private:    
            TArray m_array;
            T *m_pCurrent;
            SIZE_T m_lastMaxSize;
        };

        template<class T>
        class SimpleHeapImpl<T, QuickHeap>
        {
        public:
            inline T *New()
            {
                T *pObj = m_pool.malloc();
                m_array.push_back(pObj);
                return pObj;
            }

            inline void DeleteLast()
            {
                if (m_array.empty())
                    return;
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                m_pool.free(pObj);
            }
            
            inline SIZE_T Size()
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return m_array[ix];
            }
        
        private:    
            boost::object_pool<T> m_pool;
            std::vector<T *> m_array;
        };
    
        template<class T>
        class SimpleHeapImpl<T, DefaultHeap>
        {
        public:
            inline T *New()
            {
                T *pObj = new T();
                m_array.push_back(pObj);
                return pObj;
            }

            inline void DeleteLast()
            {
                if (m_array.empty())
                    return;
                m_array.pop_back();
            }
            
            inline SIZE_T Size()
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return &m_array[ix];
            }
        
        private:
            boost::ptr_vector<T> m_array;
        };
    }   // namespace Detail
    
    template<
        class T, 
        class Tag = DefaultHeap
    >
    class SimpleHeap
    {
        Detail::SimpleHeapImpl<T, Tag> m_impl;
        
    public:
        inline T *New()
        {
            return m_impl.New();
        }

        inline void DeleteLast()
        {
            m_impl.DeleteLast();
        }
        
        inline SIZE_T Size()
        {
            return m_impl.Size();
        }

        inline T *operator[] (SIZE_T ix)
        {
            return m_impl[ix];
        }
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAP_H