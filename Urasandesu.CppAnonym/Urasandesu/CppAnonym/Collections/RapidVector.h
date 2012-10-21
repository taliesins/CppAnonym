﻿#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#define URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASCONST_H
#include <Urasandesu/CppAnonym/Traits/HasConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTORFWD_H
#include <Urasandesu/CppAnonym/Collections/RapidVectorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    namespace RapidVectorDetail {

        namespace mpl = boost::mpl;
        using boost::has_trivial_constructor;
        using boost::has_trivial_destructor;
        using boost::integral_constant;
        using boost::is_pointer;
        using boost::iterator_core_access;
        using boost::iterator_facade;
        using boost::random_access_traversal_tag;
        using boost::remove_pointer;
        using mpl::eval_if;
        using mpl::identity;
        using Traits::HasConst;
        using Traits::RemoveConst;

        typedef integral_constant<bool, false> False;

        template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
        class RapidVectorIterator : 
            public iterator_facade<RapidVectorIterator<Value, T, RAPID_SIZE, Alloc>, Value, random_access_traversal_tag>
        {
        public:
            typedef RapidVectorIterator<Value, T, RAPID_SIZE, Alloc> this_type;

        private:
            typedef typename eval_if<
                HasConst<Value>, 
                identity<typename std::vector<T, Alloc>::const_iterator>, 
                identity<typename std::vector<T, Alloc>::iterator> >::type iterator_;

            typedef typename eval_if<
                HasConst<Value>,
                identity<this_type >,
                identity<RapidVectorIterator<Value const, T, RAPID_SIZE, Alloc> > >::type const_iterator_;
        public:
            RapidVectorIterator();
            explicit RapidVectorIterator(RapidVectorImpl<T, RAPID_SIZE, Alloc> *pThis, bool isEnd = false);

            template<class OtherValue, class OtherT, DWORD OTHER_RAPID_SIZE, class OtherAlloc>
            RapidVectorIterator(RapidVectorIterator<OtherValue, OtherT, OTHER_RAPID_SIZE, OtherAlloc> const &other);

            operator const_iterator_() const;

        private:
            friend class iterator_core_access;
            
            template<class T, DWORD RAPID_SIZE, class Alloc>
            friend class RapidVectorImpl;

            template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
            friend class RapidVectorIterator;

            void increment();
            void advance(difference_type n);
            bool equal(this_type const& other) const;
            reference dereference() const;
            difference_type distance_to(this_type const& other) const;
            
            RapidVectorImpl<T, RAPID_SIZE, Alloc> *m_pThis;
            bool m_isEnd;
            T *m_pBuf;
            iterator_ m_i;
        };





        template<class T, DWORD RAPID_SIZE, class Alloc>
        struct RapidVectorFacade
        {
            typedef std::vector<T, Alloc> internal_vector_type;
	        typedef typename internal_vector_type::allocator_type allocator_type;
	        typedef RapidVectorIterator<T const, T, RAPID_SIZE, Alloc> const_iterator;
	        typedef typename internal_vector_type::const_pointer const_pointer;
	        typedef typename internal_vector_type::const_reference const_reference;
	        typedef typename internal_vector_type::const_reverse_iterator const_reverse_iterator;
	        typedef typename internal_vector_type::difference_type difference_type;
	        typedef RapidVectorIterator<T, T, RAPID_SIZE, Alloc> iterator;
	        typedef typename internal_vector_type::pointer pointer;
	        typedef typename internal_vector_type::reference reference;
	        typedef typename internal_vector_type::reverse_iterator reverse_iterator;
	        typedef typename internal_vector_type::size_type size_type;
	        typedef typename internal_vector_type::value_type value_type;
            typedef typename is_pointer<T>::type is_value_type_pointer;
            typedef typename remove_pointer<typename RemoveConst<T>::type>::type raw_value_type;
            typedef typename has_trivial_constructor<raw_value_type>::type has_raw_value_type_trivial_constructor;
            typedef typename has_trivial_destructor<raw_value_type>::type has_raw_value_type_trivial_destructor;
            static size_t const RAPID_BUF_SIZE = (RAPID_SIZE * sizeof(T) + sizeof(UINT64) - 1) / sizeof(UINT64);
        };

        template<class T, DWORD RAPID_SIZE, class Alloc>
        class RapidVectorImpl
        {
        public:
            typedef RapidVectorImpl<T, RAPID_SIZE, Alloc> this_type;

            typedef RapidVectorFacade<T, RAPID_SIZE, Alloc> facade;
            typedef typename facade::internal_vector_type internal_vector_type;
	        typedef typename facade::allocator_type allocator_type;
	        typedef typename facade::const_iterator const_iterator;
	        typedef typename facade::const_pointer const_pointer;
	        typedef typename facade::const_reference const_reference;
	        typedef typename facade::const_reverse_iterator const_reverse_iterator;
	        typedef typename facade::difference_type difference_type;
	        typedef typename facade::iterator iterator;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::reference reference;
	        typedef typename facade::reverse_iterator reverse_iterator;
	        typedef typename facade::size_type size_type;
	        typedef typename facade::value_type value_type;
            typedef typename facade::is_value_type_pointer is_value_type_pointer;
            typedef typename facade::raw_value_type raw_value_type;
            typedef typename facade::has_raw_value_type_trivial_constructor has_raw_value_type_trivial_constructor;
            typedef typename facade::has_raw_value_type_trivial_destructor has_raw_value_type_trivial_destructor;
            static size_t const RAPID_BUF_SIZE = facade::RAPID_BUF_SIZE;

            RapidVectorImpl();
            ~RapidVectorImpl();
            RapidVectorImpl(this_type const &other);
        
            void reserve(size_type count);
            void push_back(typename boost::call_traits<T>::param_type val);
            void pop_back();
        
            template<class Iterator>
            void assign(Iterator first, Iterator last);

            iterator erase(const_iterator first, const_iterator last);
            this_type &operator =(this_type &other);
            const_reference operator[](size_type pos) const;
            reference operator[](size_type pos);
	        iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            size_type size() const;
            size_type capacity() const;
            bool empty() const;
            void resize(size_type newSize);
            bool RunAsRapid() const;

        private:
            template<class Value, class T, DWORD RAPID_SIZE, class Alloc>
	        friend class RapidVectorIterator;

            T *RapidBuf();
            T const *RapidBuf() const;
            static void CopyRapidBuf(T *pDstRapidBuf, T const *pSrcRapidBuf, size_type size);
            static void MoveRapidBuf(T *pDstRapidBuf, T *pSrcRapidBuf, size_type size);
            static void AssignVec(std::vector<T, Alloc> *&pVec, size_type newSize, T *pRapidBuf, size_type size);
            static void AssignRapidBuf(T *pRapidBuf, size_type newSize, std::vector<T, Alloc> const *pVec);
            static void ConstructRapidBuf(T *pRapidBuf);
            static void DestructRapidBuf(T *pRapidBuf, size_type size);
            void DestroyVec();

            std::vector<T, Alloc> *m_pVec;
            SIZE_T m_size;
            SIZE_T m_capacity;
            //static size_t const RAPID_BUF_SIZE = (RAPID_SIZE * sizeof(T) + sizeof(UINT64) - 1) / sizeof(UINT64);
            UINT64 m_pRapidBuf[RAPID_BUF_SIZE];
        };





        template<class Facade, class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        struct CopyRapidBufImpl
        {
            typedef Facade facade;
	        typedef typename facade::const_pointer const_pointer;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;
            typedef typename facade::raw_value_type raw_value_type;
            static size_t const RAPID_BUF_SIZE = facade::RAPID_BUF_SIZE;
            
            static void Copy(pointer pDstRapidBuf, const_pointer pSrcRapidBuf, size_type size);
        };

        template<class Facade>
        struct CopyRapidBufImpl<Facade, False, False, False> 
        { 
            typedef Facade facade;
	        typedef typename facade::const_pointer const_pointer;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;
            typedef typename facade::raw_value_type raw_value_type;
            static size_t const RAPID_BUF_SIZE = facade::RAPID_BUF_SIZE;
            
            static void Copy(pointer pDstRapidBuf, const_pointer pSrcRapidBuf, size_type size);
        };





        template<class Facade, class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        struct MoveRapidBufImpl
        {
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;

            static void Move(pointer pDstRapidBuf, pointer pSrcRapidBuf, size_type size);
        };

        template<class Facade>
        struct MoveRapidBufImpl<Facade, False, False, False> 
        { 
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;

            static void Move(pointer pDstRapidBuf, pointer pSrcRapidBuf, size_type size);
        };





        template<class Facade, class IsPointer, class HasTrivialConstructor, class HasTrivialDestructor>
        struct AssignRapidBufImpl
        {
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;
            typedef typename facade::internal_vector_type internal_vector_type;

            static void Assign(pointer pRapidBuf, size_type newSize, internal_vector_type const *pVec);
        };

        template<class Facade>
        struct AssignRapidBufImpl<Facade, False, False, False> 
        { 
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;
            typedef typename facade::internal_vector_type internal_vector_type;

            static void Assign(pointer pRapidBuf, size_type newSize, internal_vector_type const *pVec);
        };





        template<class Facade, class IsPointer, class HasTrivialConstructor>
        struct ConstructRapidBufImpl
        {
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
            static size_t const RAPID_BUF_SIZE = facade::RAPID_BUF_SIZE;

            static inline void Construct(pointer pRapidBuf);
        };

        template<class Facade>
        struct ConstructRapidBufImpl<Facade, False, False> 
        { 
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
            static size_t const RAPID_BUF_SIZE = facade::RAPID_BUF_SIZE;

            static void Construct(pointer pRapidBuf);
        };





        template<class Facade, class IsPointer, class HasTrivialDestructor>
        struct DestructRapidBufImpl
        {
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;
	        typedef typename facade::value_type value_type;
            typedef typename facade::raw_value_type raw_value_type;

            static void Destruct(pointer pRapidBuf, size_type size);
        };

        template<class Facade>
        struct DestructRapidBufImpl<Facade, False, False> 
        { 
            typedef Facade facade;
	        typedef typename facade::pointer pointer;
	        typedef typename facade::size_type size_type;
	        typedef typename facade::value_type value_type;
            typedef typename facade::raw_value_type raw_value_type;
            
            static void Destruct(pointer pRapidBuf, size_type size);
        };
        
    }   // namespace RapidVectorDetail

    template<class T, DWORD RAPID_SIZE, class Alloc>
    struct RapidVector : 
        RapidVectorDetail::RapidVectorImpl<T, RAPID_SIZE, Alloc>
    {
        typedef RapidVector<T, RAPID_SIZE, Alloc> this_type;
        typedef RapidVectorDetail::RapidVectorImpl<T, RAPID_SIZE, Alloc> base_type;

        RapidVector();
        ~RapidVector();
        RapidVector(this_type const &other);
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H