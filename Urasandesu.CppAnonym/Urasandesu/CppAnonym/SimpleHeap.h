#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#define URASANDESU_CPPANONYM_SIMPLEHEAP_H

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPFWD_H
#include <Urasandesu/CppAnonym/SimpleHeapFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SimpleHeapDetail {

        template<class T>
        class ReferenceEqualTo : 
            std::unary_function<T, bool>
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
            std::unary_function<T *, bool>
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
        class SimpleHeapImpl<T, VeryQuickHeapButMustUseSubscriptOperator>
        {
        public:
            typedef Collections::RapidVector<T> TArray;
            
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

            SIZE_T Size() const
            {
                return m_array.size();
            }
            
            T *operator[] (SIZE_T ix)
            {
                return &m_array[ix];
            }
            
            T const *operator[] (SIZE_T ix) const
            {
                return &m_array[ix];
            }

        private:    
            void DeleteLastCore()
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                Utilities::DestructionDistributor<T>::Destruct(pObj);
            }

            TArray m_array;
            T *m_pCurrent;
            SIZE_T m_lastCapacity;
        };

        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, QuickHeap>
        {
        public:
            typedef std::vector<T *> TArray;

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
            
            SIZE_T Size() const
            {
                return m_array.size();
            }
            
            T *operator[] (SIZE_T ix)
            {
                return m_array[ix];
            }
            
            T const *operator[] (SIZE_T ix) const
            {
                return m_array[ix];
            }

        private:    
            void DeleteLastCore()
            {
                T *pObj = (*this)[Size() - 1];
                m_array.pop_back();
                Utilities::DestructionDistributor<T>::Destruct(pObj);
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
            }
            
            T *New();
            
            template<class A1>
            inline T *New(A1 arg1);

            template<class A1, class A2>
            inline T *New(A1 arg1, A2 arg2);

            template<class A1, class A2, class A3>
            inline T *New(A1 arg1, A2 arg2, A3 arg3);

            void Delete(T *pObj);
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
            
            SIZE_T Size() const
            {
                return m_array.size();
            }
            
            T *operator[] (SIZE_T ix)
            {
                return &m_array[ix];
            }
            
            T const *operator[] (SIZE_T ix) const
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
            
            void DeleteLast();                      // not supported
            SIZE_T Size() const;                    // not supported
            T *operator[] (SIZE_T ix);              // not supported
            T const *operator[] (SIZE_T ix) const;  // not supported
        };
    
    }   // namespace SimpleHeapDetail
    
    template<
        class T, 
        class Tag
    >
    class SimpleHeap : 
        boost::noncopyable
    {
    public:
        typedef T object_type;

        T *New()
        {
            return m_impl.New();
        }

        template<class A1>
        T *New(A1 arg1)
        {
            return m_impl.New<A1>(arg1);
        }

        template<class A1, class A2>
        T *New(A1 arg1, A2 arg2)
        {
            return m_impl.New<A1, A2>(arg1, arg2);
        }

        template<class A1, class A2, class A3>
        T *New(A1 arg1, A2 arg2, A3 arg3)
        {
            return m_impl.New<A1, A2>(arg1, arg2, arg3);
        }

        void DeleteLast()
        {
            m_impl.DeleteLast();
        }
        
        void Delete(T *pObj)
        {
            m_impl.Delete(pObj);
        }
        
        SIZE_T Size() const
        {
            return m_impl.Size();
        }
        
        T *operator[] (SIZE_T ix)
        {
            return m_impl[ix];
        }
        
        T const *operator[] (SIZE_T ix) const
        {
            return m_impl[ix];
        }

    private:
        SimpleHeapDetail::SimpleHeapImpl<T, Tag> m_impl;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAP_H