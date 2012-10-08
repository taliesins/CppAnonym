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
        class SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>
        {
        public:
            SimpleHeapImpl() : 
                m_pool(sizeof(T))
            { }
            
            ~SimpleHeapImpl()
            {
                // This implementation isn't supported enumerating the objects that was constructed  by it.
                // Therefore, the such objects must be destructed with the method Delete(T *).
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
#endif
            }

            inline T *New()
            {
                T *pObj = reinterpret_cast<T *>(m_pool.malloc());
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructing..." << std::endl;
#endif
#pragma warning(push)
#pragma warning(disable: 4345)
                new(pObj)T();
#pragma warning(pop)
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructed !!" << std::endl;
#endif
                return pObj;
            }

            template<class A1>
            inline T *New(A1 arg1)
            {
                T *pObj = reinterpret_cast<T *>(m_pool.malloc());
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructing..." << std::endl;
#endif
                new(pObj)T(arg1);
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructed !!" << std::endl;
#endif
                return pObj;
            }

            template<class A1, class A2>
            inline T *New(A1 arg1, A2 arg2)
            {
                T *pObj = reinterpret_cast<T *>(m_pool.malloc());
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructing..." << std::endl;
#endif
                new(pObj)T(arg1, arg2);
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructed !!" << std::endl;
#endif
                return pObj;
            }

            void Delete(T *pObj)
            {
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is destructing..." << std::endl;
#endif
                Utilities::DestructionDistributor<T *>::Destruct(pObj);
                m_pool.free(pObj);
#ifdef DEBUG_SIMPLEHEAP
                std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is destructed !!" << std::endl;
#endif
            }
            
            void DeleteLast();                      // not supported
            SIZE_T Size() const;                    // not supported
            T *operator[] (SIZE_T ix);              // not supported
            T const *operator[] (SIZE_T ix) const;  // not supported
        
        private:    
            boost::pool<> m_pool;
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
    
        template<class T>
        class SimpleHeapImpl<T, DefaultHeapWithoutSubscriptOperator>
        {
        public:
            inline T *New()
            {
                T *pObj = new T();
                return pObj;
            }

            template<class A1>
            inline T *New(A1 arg1)
            {
                T *pObj = new T(arg1);
                return pObj;
            }

            template<class A1, class A2>
            inline T *New(A1 arg1, A2 arg2)
            {
                T *pObj = new T(arg1, arg2);
                return pObj;
            }

            void Delete(T *pObj)
            {
                delete pObj;
            }
            
            void DeleteLast();                      // not supported
            SIZE_T Size() const;                    // not supported
            T *operator[] (SIZE_T ix);              // not supported
            T const *operator[] (SIZE_T ix) const;  // not supported
        };
    }   // namespace Detail
    
    template<
        class T, 
        class Tag
    >
    class SimpleHeap : 
        boost::noncopyable
    {
        Detail::SimpleHeapImpl<T, Tag> m_impl;
        
    public:
        inline T *New()
        {
            return m_impl.New();
        }

        template<class A1>
        inline T *New(A1 arg1)
        {
            return m_impl.New<A1>(arg1);
        }

        template<class A1, class A2>
        inline T *New(A1 arg1, A2 arg2)
        {
            return m_impl.New<A1, A2>(arg1, arg2);
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