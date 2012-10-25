#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAP_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SimpleHeapDetail {

        template<class T>
        T *SimpleHeapImpl<T, VeryQuickHeapButMustUseSubscriptOperator>::New()
        {
            T *pObj = NULL;
            m_array.resize(m_array.size() + 1);
            if (m_lastCapacity < m_array.capacity())
            {
                m_lastCapacity = m_array.capacity();
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

        template<class T>
        void SimpleHeapImpl<T, VeryQuickHeapButMustUseSubscriptOperator>::Delete(T *pObj)
        {
            if (m_array.empty())
                return;

            if ((*this)[Size() - 1] == pObj)
            {
                DeleteLastCore();
                return;
            }

            typedef TArray::iterator Iterator;
            Iterator result = std::remove_if(m_array.begin(), m_array.end(), ReferenceEqualTo<T>(pObj));
            if (result != m_array.end())
                m_array.erase(result, m_array.end());
        }

        
        
        
        
        template<class T>
        SimpleHeapImpl<T, QuickHeap>::~SimpleHeapImpl()
        {
            if (m_array.empty())
                return;

            for (T **i = &m_array[0] - 1, **i_end = i + m_array.size(); i != i_end; --i_end)
            {
                Utilities::DestructionDistributor<T>::Destruct(*i_end);
                m_pool.free(*i_end);
            }
        }

        template<class T>
        inline T *SimpleHeapImpl<T, QuickHeap>::New()
        {
            T *pObj = reinterpret_cast<T *>(m_pool.malloc());
#pragma warning(push)
#pragma warning(disable: 4345)
            new(pObj)T();
#pragma warning(pop)
            m_array.push_back(pObj);
            return pObj;
        }

        template<class T>
        void SimpleHeapImpl<T, QuickHeap>::Delete(T *pObj)
        {
            if (m_array.empty())
                return;

            if ((*this)[Size() - 1] == pObj)
            {
                DeleteLastCore();
                return;
            }

            typedef TArray::iterator TIterator;
            TIterator obj = std::remove_if(m_array.begin(), m_array.end(), PointerEqualTo<T>(pObj));
            if (obj != m_array.end())
            {
                // This loop is performed only one time.
                for (TIterator i = obj, i_end = m_array.end(); i != i_end; ++i)
                {
                    Utilities::DestructionDistributor<T>::Destruct(*i);
                    m_pool.free(*i);
                }
                m_array.erase(obj, m_array.end());
            }
        }

        
        
        
        
        template<class T>
        inline T *SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>::New()
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

        template<class T>
        template<class A1>
        inline T *SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>::New(A1 arg1)
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

        template<class T>
        template<class A1, class A2>
        inline T *SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>::New(A1 arg1, A2 arg2)
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

        template<class T>
        template<class A1, class A2, class A3>
        inline T *SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>::New(A1 arg1, A2 arg2, A3 arg3)
        {
            T *pObj = reinterpret_cast<T *>(m_pool.malloc());
#ifdef DEBUG_SIMPLEHEAP
            std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructing..." << std::endl;
#endif
            new(pObj)T(arg1, arg2, arg3);
#ifdef DEBUG_SIMPLEHEAP
            std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is constructed !!" << std::endl;
#endif
            return pObj;
        }

        template<class T>
        void SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>::Delete(T *pObj)
        {
#ifdef DEBUG_SIMPLEHEAP
            std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is destructing..." << std::endl;
#endif
            Utilities::DestructionDistributor<T>::Destruct(pObj);
            m_pool.free(pObj);
#ifdef DEBUG_SIMPLEHEAP
            std::cout << "Type: " << typeid(T).name() << ", " << reinterpret_cast<int>(pObj) << " is destructed !!" << std::endl;
#endif
        }
    
        
        
        

        template<class T>
        void SimpleHeapImpl<T, DefaultHeap>::Delete(T *pObj)
        {
            if (m_array.empty())
                return;
                
            if ((*this)[Size() - 1] == pObj)
            {
                m_array.pop_back();
                return;
            }

            m_array.erase_if(m_array.begin(), m_array.end(), ReferenceEqualTo<T>(pObj));
        }

    }   // namespace SimpleHeapDetail

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAP_HPP