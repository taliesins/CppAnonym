#pragma once
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#define URASANDESU_CPPANONYM_SIMPLEHEAP_H

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
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
            ReferenceEqualTo(T *p);
            bool operator()(T const &x) const;

        private:
            T *m_p;
        };

        
        
        
        
        template<class T>
        class PointerEqualTo : 
            std::unary_function<T *, bool>
        {
        public:
            PointerEqualTo(T *p);
            bool operator()(T const *x) const;

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
            
            SimpleHeapImpl();
            ~SimpleHeapImpl();
            T *New();
            void DeleteLast();
            void Delete(T *pObj);
            SIZE_T Size() const;
            T *operator[] (SIZE_T ix);
            T const *operator[] (SIZE_T ix) const;

        private:    
            void DeleteLastCore();

            TArray m_array;
            T *m_pCurrent;
            SIZE_T m_lastCapacity;
        };

        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, QuickHeap>
        {
        public:
            typedef std::vector<T *> TArray;

            SimpleHeapImpl(); 
            ~SimpleHeapImpl();
            T *New();
            void DeleteLast();
            void Delete(T *pObj);
            SIZE_T Size() const;
            T *operator[] (SIZE_T ix);
            T const *operator[] (SIZE_T ix) const;

        private:    
            void DeleteLastCore();

            boost::pool<> m_pool;
            TArray m_array;
        };

        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, QuickHeapWithoutSubscriptOperator>
        {
        public:
            SimpleHeapImpl();
            ~SimpleHeapImpl();
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
            T *New();
            void DeleteLast();
            void Delete(T *pObj);
            SIZE_T Size() const;
            T *operator[] (SIZE_T ix);
            T const *operator[] (SIZE_T ix) const;

        private:
            boost::ptr_vector<T> m_array;
        };
    
        
        
        
        
        template<class T>
        class SimpleHeapImpl<T, DefaultHeapWithoutSubscriptOperator>
        {
        public:
            T *New();
            
            template<class A1>
            T *New(A1 arg1);

            template<class A1, class A2>
            T *New(A1 arg1, A2 arg2);

            void Delete(T *pObj);
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

        T *New();

        template<class A1>
        T *New(A1 arg1);

        template<class A1, class A2>
        T *New(A1 arg1, A2 arg2);

        template<class A1, class A2, class A3>
        T *New(A1 arg1, A2 arg2, A3 arg3);

        void DeleteLast();
        void Delete(T *pObj);
        SIZE_T Size() const;
        T *operator[] (SIZE_T ix);
        T const *operator[] (SIZE_T ix) const;

    private:
        SimpleHeapDetail::SimpleHeapImpl<T, Tag> m_impl;
    };
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_SIMPLEHEAP_H