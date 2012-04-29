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
            
            ~SimpleHeapImpl()
            {
                if (m_array.empty())
                    return;

                for (T *i = &m_array[0] - 1, *i_end = i + m_array.size(); i != i_end; --i_end)
                    Utilities::SmartDestructor<T>::Destruct(*i_end);
            }

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
                
                DeleteLastCore();
            }

            void Delete(T *pObj)
            {
                if (m_array.empty())
                    return;

                if ((*this)[Size() - 1] == pObj)
                {
                    DeleteLastCore();
                    return;
                }

                class EqualTo : 
                    std::unary_function<T, bool>
                {
                public:
                    EqualTo(T *pObj_) : 
                        m_pObj_(pObj_)
                    { }

                    bool operator()(T const &x) const
                    {
                        return m_pObj_ == &x;
                    }
                private:
                    T *m_pObj_;
                };
                typedef TArray::iterator TIterator;
                TIterator obj = std::remove_if(m_array.begin(), m_array.end(), EqualTo(pObj));
                if (obj != m_array.end())
                {
                    for (TIterator i = obj, i_end = m_array.end(); i != i_end; ++i)
                        Utilities::SmartDestructor<T>::Destruct(*i);
                    m_array.erase(obj, m_array.end());
                }
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
            void DeleteLastCore()
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                Utilities::SmartDestructor<T *>::Destruct(pObj);
            }

            TArray m_array;
            T *m_pCurrent;
            SIZE_T m_lastMaxSize;
        };

        template<class T>
        class SimpleHeapImpl<T, QuickHeap>
        {
        public:
            typedef std::vector<T *> TArray;

            SimpleHeapImpl() : 
                m_pool(sizeof(T))
            { }
            
            ~SimpleHeapImpl()
            {
                if (m_array.empty())
                    return;

                for (T **i = &m_array[0] - 1, **i_end = i + m_array.size(); i != i_end; --i_end)
                {
                    Utilities::SmartDestructor<T *>::Destruct(*i_end);
                    m_pool.free(*i_end);
                }
            }

            inline T *New()
            {
                T *pObj = reinterpret_cast<T *>(m_pool.malloc());
#pragma warning(push)
#pragma warning(disable: 4345)
                new(pObj)T();
#pragma warning(pop)
                m_array.push_back(pObj);
                return pObj;
            }

            void DeleteLast()
            {
                if (m_array.empty())
                    return;
                
                DeleteLastCore();
            }

            void Delete(T *pObj)
            {
                if (m_array.empty())
                    return;

                if ((*this)[Size() - 1] == pObj)
                {
                    DeleteLastCore();
                    return;
                }

                class EqualTo : 
                    std::unary_function<T *, bool>
                {
                public:
                    EqualTo(T *pObj_) : 
                        m_pObj_(pObj_)
                    { }

                    bool operator()(T const *x) const
                    {
                        return m_pObj_ == x;
                    }
                private:
                    T *m_pObj_;
                };
                typedef TArray::iterator TIterator;
                TIterator obj = std::remove_if(m_array.begin(), m_array.end(), EqualTo(pObj));
                if (obj != m_array.end())
                {
                    for (TIterator i = obj, i_end = m_array.end(); i != i_end; ++i)
                    {
                        Utilities::SmartDestructor<T *>::Destruct(*i);
                        m_pool.free(*i);
                    }
                    m_array.erase(obj, m_array.end());
                }
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
            void DeleteLastCore()
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                Utilities::SmartDestructor<T *>::Destruct(pObj);
                m_pool.free(pObj);
            }

            boost::pool<> m_pool;
            TArray m_array;
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

            void Delete(T *pObj)
            {
                if (m_array.empty())
                    return;
                
                if ((*this)[Size() - 1] == pObj)
                {
                    m_array.pop_back();
                    return;
                }

                class EqualTo : 
                    std::unary_function<T, bool>
                {
                public:
                    EqualTo(T *pObj_) : 
                        m_pObj_(pObj_)
                    { }

                    bool operator()(T const &x) const
                    {
                        return m_pObj_ == &x;
                    }
                private:
                    T *m_pObj_;
                };
                m_array.erase_if(m_array.begin(), m_array.end(), EqualTo(pObj));
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

        inline void Delete(T *pObj)
        {
            m_impl.Delete(pObj);
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