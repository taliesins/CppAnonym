#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAP_HPP

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_HPP
#include <Urasandesu/CppAnonym/SimpleHeapFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

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
                    Utilities::DestructionDistributor<T>::Destruct(*i_end);
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
                        Utilities::DestructionDistributor<T>::Destruct(*i);
                    m_array.erase(obj, m_array.end());
                }
            }

            inline SIZE_T Size() const
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return &m_array[ix];
            }
            
            inline T const *operator[] (SIZE_T ix) const
            {
                return &m_array[ix];
            }
        
        private:    
            void DeleteLastCore()
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                Utilities::DestructionDistributor<T *>::Destruct(pObj);
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
                    Utilities::DestructionDistributor<T *>::Destruct(*i_end);
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

                    inline bool operator()(T const *x) const
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
                    // This loop is performed only one time.
                    for (TIterator i = obj, i_end = m_array.end(); i != i_end; ++i)
                    {
                        Utilities::DestructionDistributor<T *>::Destruct(*i);
                        m_pool.free(*i);
                    }
                    m_array.erase(obj, m_array.end());
                }
            }
            
            inline SIZE_T Size() const
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return m_array[ix];
            }
            
            inline T const *operator[] (SIZE_T ix) const
            {
                return m_array[ix];
            }
        
        private:    
            void DeleteLastCore()
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                Utilities::DestructionDistributor<T *>::Destruct(pObj);
                m_pool.free(pObj);
            }

            boost::pool<> m_pool;
            TArray m_array;
        };


        template<class T>
        class SimpleHeapImpl<T, QuickHeap2>
        {
        public:
            struct Box
            {
                Box(T *pObj, bool needsDestruct) : 
                    m_pObj(pObj),
                    m_needsDestruct(needsDestruct)
                { }
                
                T *m_pObj;
                bool m_needsDestruct;
            };
            typedef std::vector<Box> BoxArray;

            SimpleHeapImpl() : 
                m_pool(sizeof(T))
            { }
            
            ~SimpleHeapImpl()
            {
                if (m_array.empty())
                    return;

                for (Box *i = &m_array[0] - 1, *i_end = i + m_array.size(); i != i_end; --i_end)
                {
                    Box &box = *i_end;
                    if (box.m_needsDestruct)
                        Utilities::DestructionDistributor<T *>::Destruct(box.m_pObj);
                    m_pool.free(box.m_pObj);
                }
            }

            inline void *Alloc(SIZE_T num)
            {
                T *pObj = reinterpret_cast<T *>(m_pool.ordered_malloc(num));
                m_array.push_back(Box(pObj, false));
                return pObj;
            }

            void Construct(T *pObj)
            {
                if (m_array.empty())
                    return;

                for (Box *i = &m_array[0] - 1, *i_end = i + m_array.size(); i != i_end; --i_end)
                {
                    Box &box = *i_end;
                    if (box.m_pObj == pObj)
                    {
                        box.m_needsDestruct = true;
#pragma warning(push)
#pragma warning(disable: 4345)
                        new(pObj)T();
#pragma warning(pop)
                        break;
                    }
                }
            }

            void Destroy(T *pObj)
            {
                if (m_array.empty())
                    return;

                for (Box *i = &m_array[0] - 1, *i_end = i + m_array.size(); i != i_end; --i_end)
                {
                    Box &box = *i_end;
                    if (box.m_pObj == pObj)
                    {
                        box.m_needsDestruct = false;
                        pObj->~T();
                        break;
                    }
                }
            }

            void Deallocate(void *pObj, SIZE_T num)
            {
                if (m_array.empty())
                    return;

                if ((*this)[Size() - 1] == reinterpret_cast<T *>(pObj))
                {
                    DeallocateLastCore(num);
                    return;
                }

                class EqualTo : 
                    std::unary_function<Box, bool>
                {
                public:
                    EqualTo(T *pObj_) : 
                        m_pObj_(pObj_)
                    { }

                    inline bool operator()(Box const &box) const
                    {
                        return m_pObj_ == box.m_pObj;
                    }
                private:
                    T *m_pObj_;
                };
                typedef BoxArray::iterator Iterator;
                Iterator result = std::remove_if(m_array.begin(), m_array.end(), EqualTo(reinterpret_cast<T *>(pObj)));
                if (result != m_array.end())
                {
                    // This loop is performed only one time.
                    for (Iterator i = result, i_end = m_array.end(); i != i_end; ++i)
                    {
                        Box &box = *i;
                        m_pool.ordered_free(box.m_pObj, num);
                    }
                    m_array.erase(result, m_array.end());
                }
            }

//            inline T *New()
//            {
//                T *pObj = reinterpret_cast<T *>(m_pool.malloc());
//#pragma warning(push)
//#pragma warning(disable: 4345)
//                new(pObj)T();
//#pragma warning(pop)
//                m_array.push_back(pObj);
//                return pObj;
//            }

            //void DeleteLast()
            //{
            //    if (m_array.empty())
            //        return;
            //    
            //    DeleteLastCore();
            //}

            //void Delete(T *pObj)
            //{
            //    if (m_array.empty())
            //        return;

            //    if ((*this)[Size() - 1] == pObj)
            //    {
            //        DeleteLastCore();
            //        return;
            //    }

            //    class EqualTo : 
            //        std::unary_function<T *, bool>
            //    {
            //    public:
            //        EqualTo(T *pObj_) : 
            //            m_pObj_(pObj_)
            //        { }

            //        inline bool operator()(T const *x) const
            //        {
            //            return m_pObj_ == x;
            //        }
            //    private:
            //        T *m_pObj_;
            //    };
            //    typedef BoxArray::iterator TIterator;
            //    TIterator obj = std::remove_if(m_array.begin(), m_array.end(), EqualTo(pObj));
            //    if (obj != m_array.end())
            //    {
            //        // This loop is performed only one time.
            //        for (TIterator i = obj, i_end = m_array.end(); i != i_end; ++i)
            //        {
            //            Utilities::DestructionDistributor<T *>::Destruct(*i);
            //            m_pool.free(*i);
            //        }
            //        m_array.erase(obj, m_array.end());
            //    }
            //}
            
            inline SIZE_T Size() const
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return m_array[ix].m_pObj;
            }
            
            inline T const *operator[] (SIZE_T ix) const
            {
                return m_array[ix].m_pObj;
            }
        
        private:    
            void DeallocateLastCore(SIZE_T num)
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                m_pool.ordered_free(pObj, num);
            }

            //void DeleteLastCore()
            //{
            //    T *pObj = (*this)[Size() - 1];
            //    m_array.pop_back();
            //    Utilities::DestructionDistributor<T *>::Destruct(pObj);
            //    m_pool.free(pObj);
            //}

            boost::pool<> m_pool;
            BoxArray m_array;
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
            
            inline SIZE_T Size() const
            {
                return m_array.size();
            }
            
            inline T *operator[] (SIZE_T ix)
            {
                return &m_array[ix];
            }
            
            inline T const *operator[] (SIZE_T ix) const
            {
                return &m_array[ix];
            }
        
        private:
            boost::ptr_vector<T> m_array;
        };
    }   // namespace Detail
    
    template<
        class T, 
        class Tag
    >
    class SimpleHeap
    {
        Detail::SimpleHeapImpl<T, Tag> m_impl;
        
    public:
        inline void *Alloc(SIZE_T num)
        {
            return m_impl.Alloc(num);
        }

        inline void Construct(T *pObj)
        {
            m_impl.Construct(pObj);
        }

        inline void Destroy(T *pObj)
        {
            m_impl.Destroy(pObj);
        }

        inline void Deallocate(void *p, SIZE_T num)
        {
            m_impl.Deallocate(p, num);
        }

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
        
        inline SIZE_T Size() const
        {
            return m_impl.Size();
        }

        inline T *operator[] (SIZE_T ix)
        {
            return m_impl[ix];
        }

        inline T const *operator[] (SIZE_T ix) const
        {
            return m_impl[ix];
        }
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAP_HPP