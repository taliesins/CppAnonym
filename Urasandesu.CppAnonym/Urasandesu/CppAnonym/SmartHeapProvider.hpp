/* 
 * File: SmartHeapProvider.hpp
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
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP
#include <Urasandesu/CppAnonym/SmartHeapProviderFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SmartHeapProviderDetail {

        namespace mpl = boost::mpl;
        using boost::is_same;
        using mpl::_;
        using mpl::_1;
        using mpl::_2;
        using mpl::at_c;
        using mpl::begin;
        using mpl::deref;
        using mpl::end;
        using mpl::filter_view;
        using mpl::find;
        using mpl::fold;
        using mpl::lambda;
        using mpl::next;
        using mpl::not_;
        using mpl::push_back;
        using mpl::reverse;
        using mpl::vector;
        using mpl::void_;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class I>
        struct ProvidingTypeFacade
        {
            typedef typename deref<I>::type object_type;
            typedef typename AutoPtr<object_type>::template make_heap_holder_impl<>::object_deleter_type object_deleter_type;
            typedef typename AutoPtr<object_type>::template make_heap_holder_impl<>::type holder_impl_type;
            typedef typename AutoPtr<object_type>::template make_heap_holder_impl<>::deleter_type holder_impl_deleter_type;
            typedef ObjectTag<object_type, QuickHeapWithoutRandomAccess> object_object_tag_type;
            typedef ObjectTag<holder_impl_type, QuickHeapWithoutRandomAccess> holder_impl_object_tag_type;
            typedef SimpleHeapProvider<vector<object_object_tag_type, holder_impl_object_tag_type> > base_type;
            typedef typename base_type::template provider_of<object_type>::type object_provider_type;
            typedef typename base_type::template provider_of<holder_impl_type>::type holder_impl_provider_type;
            typedef typename object_provider_type::object_heap_type object_heap_type;
            typedef typename holder_impl_provider_type::object_heap_type holder_impl_heap_type;
        };

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImplImpl : 
            ProvidingTypeFacade<I>::base_type,
            public SmartHeapProviderImplImpl<ReversedProvidingTypes, typename next<I>::type, IEnd>
        {
        public:
            typedef typename ProvidingTypeFacade<I>::base_type base_type;
            typedef typename ProvidingTypeFacade<I>::object_type object_type;
            typedef typename ProvidingTypeFacade<I>::object_deleter_type object_deleter_type;
            typedef typename ProvidingTypeFacade<I>::holder_impl_type holder_impl_type;
            typedef typename ProvidingTypeFacade<I>::holder_impl_deleter_type holder_impl_deleter_type;
            typedef typename ProvidingTypeFacade<I>::object_provider_type object_provider_type;
            typedef typename ProvidingTypeFacade<I>::holder_impl_provider_type holder_impl_provider_type;
            typedef typename ProvidingTypeFacade<I>::object_heap_type object_heap_type;
            typedef typename ProvidingTypeFacade<I>::holder_impl_heap_type holder_impl_heap_type;

            AutoPtr<object_type> NewObject()
            {
                object_deleter_type objDeleter(ObjectHeap());
                object_type *pObj = ObjectHeap().New();

                holder_impl_deleter_type implDeleter(HolderImplHeap());
                holder_impl_type *pHolderImpl = HolderImplHeap().New(pObj, objDeleter, implDeleter);

                return AutoPtr<object_type>(pHolderImpl);
            }

        private:
            object_heap_type &ObjectHeap()
            {
                object_provider_type &provider = base_type::ProviderOf<object_type>();
                return provider.Heap();
            }

            holder_impl_heap_type &HolderImplHeap()
            {
                holder_impl_provider_type &provider = base_type::ProviderOf<holder_impl_type>();
                return provider.Heap();
            }
        };

        template<class ReversedProvidingTypes>
        class SmartHeapProviderImplImpl<ReversedProvidingTypes, 
                                        typename end<ReversedProvidingTypes>::type, 
                                        typename end<ReversedProvidingTypes>::type> : 
            noncopyable
        {
        };

        
        
        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename find<ReversedProvidingTypes, ProvidingType>::type i;
            typedef typename end<ReversedProvidingTypes>::type i_end;
        public:
            typedef SmartHeapProviderImplImpl<ReversedProvidingTypes, i, i_end> type;
        };

        
        
        template<class ProvidingTypes>
        struct ATL_NO_VTABLE SmartHeapProviderImpl : 
            SmartHeapProviderImplImpl<typename reverse<ProvidingTypes>::type, 
                                      typename begin<typename reverse<ProvidingTypes>::type>::type, 
                                      typename end<typename reverse<ProvidingTypes>::type>::type>
        {
            typedef SmartHeapProviderImpl<ProvidingTypes> this_type;
            typedef ProvidingTypes providing_types;

            template<LONG N>
            struct providing_type_at : 
                at_c<providing_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename reverse<providing_types>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

        
        
        template<class T0, CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
        class DesignatedSequence
        {
            typedef vector<T0, CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename lambda<not_<is_same<_, void_> > >::type is_designated;
        public:
            typedef typename fold<filter_view<types, is_designated>, vector<>, push_back<_1, _2> >::type type;
        };

    }   // namespace SmartHeapProviderDetail {

    template<class T0, CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
    struct ATL_NO_VTABLE SmartHeapProvider : 
        SmartHeapProviderDetail::SmartHeapProviderImpl<
            typename SmartHeapProviderDetail::DesignatedSequence<T0, CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)>::type
        >
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
