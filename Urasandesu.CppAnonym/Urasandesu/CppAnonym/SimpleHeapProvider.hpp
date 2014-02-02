/* 
 * File: SimpleHeapProvider.hpp
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
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
#include <Urasandesu/CppAnonym/Traits/Distinct.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#include <Urasandesu/CppAnonym/ObjectTag.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SimpleHeapProviderDetail {
        
        namespace mpl = boost::mpl;
        using boost::is_same;
        using mpl::_1;
        using mpl::at_c;
        using mpl::begin;
        using mpl::deref;
        using mpl::end;
        using mpl::find_if;
        using mpl::next;
        using mpl::reverse;
        using namespace boost;

        template<class ReversedProvidingObjectTagTypes, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImplImpl : 
            public SimpleHeapProviderImplImpl<ReversedProvidingObjectTagTypes, typename next<I>::type, IEnd>
        {
        public:
            typedef SimpleHeapProviderImplImpl<ReversedProvidingObjectTagTypes, I, IEnd> this_type;
            typedef typename deref<I>::type object_tag_type;
            typedef typename object_tag_type::object_type object_type;
            typedef typename object_tag_type::tag_type tag_type;
            typedef SimpleHeap<object_type, tag_type> object_heap_type;

            static object_heap_type &StaticHeap()
            {
                static object_heap_type heap;
                return heap;
            }

            object_heap_type &Heap()
            {
                if (!m_pHeap.get())
                    m_pHeap = make_shared<object_heap_type>();
                return *m_pHeap.get();
            }
        
        private:
            shared_ptr<object_heap_type> m_pHeap;
        };

        template<class ReversedProvidingObjectTagTypes>
        class ATL_NO_VTABLE SimpleHeapProviderImplImpl<ReversedProvidingObjectTagTypes, 
                                                       typename end<ReversedProvidingObjectTagTypes>::type, 
                                                       typename end<ReversedProvidingObjectTagTypes>::type> : 
            noncopyable
        {
        };


        
        template<class ObjectTag, class T>
        struct HasObjectT : 
            is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(ObjectTagObject, ObjectTag)::type, T>
        {
        };


        
        template<class ProvidingObjectTagTypes, LONG N>
        class ProvidingTypeAtImpl
        {
            typedef typename at_c<ProvidingObjectTagTypes, N>::type providing_object_tag_type;
        public:
            typedef typename providing_object_tag_type::object_type type;
        };


        
        template<class ReversedProvidingObjectTagTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename find_if<ReversedProvidingObjectTagTypes, HasObjectT<_1, ProvidingType> >::type i;
            typedef typename end<ReversedProvidingObjectTagTypes>::type i_end;
        public:
            typedef SimpleHeapProviderImplImpl<ReversedProvidingObjectTagTypes, i, i_end> type;
        };


        
        template<class ProvidingObjectTagTypes>
        struct ATL_NO_VTABLE SimpleHeapProviderImpl : 
            SimpleHeapProviderImplImpl<typename reverse<ProvidingObjectTagTypes>::type, 
                                       typename begin<typename reverse<ProvidingObjectTagTypes>::type>::type, 
                                       typename end<typename reverse<ProvidingObjectTagTypes>::type>::type>
        {
            typedef SimpleHeapProviderImpl<ProvidingObjectTagTypes> this_type;
            typedef ProvidingObjectTagTypes providing_object_tag_types;

            template<LONG N>
            struct providing_type_at : 
                ProvidingTypeAtImpl<ProvidingObjectTagTypes, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename reverse<providing_object_tag_types>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

    }   // namespace SimpleHeapProviderDetail


    template<class ProvidingObjectTagTypes>
    struct ATL_NO_VTABLE SimpleHeapProvider : 
        SimpleHeapProviderDetail::SimpleHeapProviderImpl<ProvidingObjectTagTypes>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
