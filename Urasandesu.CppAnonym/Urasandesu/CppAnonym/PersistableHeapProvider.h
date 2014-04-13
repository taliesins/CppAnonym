/* 
 * File: PersistableHeapProvider.h
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
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_H
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP
#include <Urasandesu/CppAnonym/PersistentInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_H
#include <Urasandesu/CppAnonym/PersistableHeapProviderFwd.h>
#endif

// TODO: rename to PersistableHeapProvider.hpp.

namespace Urasandesu { namespace CppAnonym {

    namespace PersistableHeapProviderDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using boost::is_same;
        using boost::noncopyable;
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
        using std::unique_ptr;

        template<class I>
        struct PersistentInfoFacade
        {
            typedef typename deref<I>::type persistent_info_type;
            typedef typename persistent_info_type::object_type object_type;
            typedef typename persistent_info_type::persisted_handler_type persisted_handler_type;
            typedef typename TempPtr<object_type>::template make_heap_holder_impl<>::object_deleter_type object_deleter_type;
            typedef typename TempPtr<object_type>::template make_heap_holder_impl<>::type holder_impl_type;
            typedef typename TempPtr<object_type>::template make_heap_holder_impl<>::deleter_type holder_impl_deleter_type;
            typedef typename TempPtr<object_type>::template make_heap_persisted_handler_holder_impl<persisted_handler_type>::type persisted_handler_holder_impl_type;
            typedef typename TempPtr<object_type>::template make_heap_persisted_handler_holder_impl<persisted_handler_type>::deleter_type persisted_handler_holder_impl_deleter_type;
            typedef ObjectTag<object_type, QuickHeapWithoutRandomAccess> object_object_tag_type;
            typedef ObjectTag<holder_impl_type, QuickHeapWithoutRandomAccess> holder_impl_object_tag_type;
            typedef ObjectTag<persisted_handler_holder_impl_type, QuickHeapWithoutRandomAccess> persisted_handler_holder_impl_object_tag_type;
            typedef SimpleHeapProvider<vector<object_object_tag_type, holder_impl_object_tag_type, persisted_handler_holder_impl_object_tag_type> > base_type;
            typedef typename base_type::template provider_of<object_type>::type object_provider_type;
            typedef typename base_type::template provider_of<holder_impl_type>::type holder_impl_provider_type;
            typedef typename base_type::template provider_of<persisted_handler_holder_impl_type>::type persisted_handler_holder_impl_provider_type;
            typedef typename object_provider_type::object_heap_type object_heap_type;
            typedef typename holder_impl_provider_type::object_heap_type holder_impl_heap_type;
            typedef typename persisted_handler_holder_impl_provider_type::object_heap_type persisted_handler_holder_impl_heap_type;
        };

        template<class ReversedPersistentInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE PersistableHeapProviderImplImpl : 
            PersistentInfoFacade<I>::base_type,
            public PersistableHeapProviderImplImpl<ReversedPersistentInfoTypes, typename next<I>::type, IEnd>
        {
        public:
            typedef typename PersistentInfoFacade<I>::base_type base_type;
            typedef typename PersistentInfoFacade<I>::object_type object_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_type persisted_handler_type;
            typedef typename PersistentInfoFacade<I>::object_deleter_type object_deleter_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_type holder_impl_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_deleter_type holder_impl_deleter_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_type persisted_handler_holder_impl_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_deleter_type persisted_handler_holder_impl_deleter_type;            
            typedef typename PersistentInfoFacade<I>::object_provider_type object_provider_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_provider_type holder_impl_provider_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_provider_type persisted_handler_holder_impl_provider_type;
            typedef typename PersistentInfoFacade<I>::object_heap_type object_heap_type;
            typedef typename PersistentInfoFacade<I>::holder_impl_heap_type holder_impl_heap_type;
            typedef typename PersistentInfoFacade<I>::persisted_handler_holder_impl_heap_type persisted_handler_holder_impl_heap_type;

            TempPtr<object_type> NewObject()
            {
                auto objDeleter = object_deleter_type(ObjectHeap());
                auto *pObj = ObjectHeap().New();

                auto implDeleter = holder_impl_deleter_type(HolderImplHeap());
                auto *pHolderImpl = HolderImplHeap().New(pObj, objDeleter, implDeleter);

                return TempPtr<object_type>(pHolderImpl);
            }

            void RegisterObject(TempPtr<object_type> &p)
            {
                p.Persist();
            }

            SIZE_T AddPersistedHandler(TempPtr<object_type> &p, persisted_handler_type const &handler)
            {
                auto implDeleter = persisted_handler_holder_impl_deleter_type(PersistedHandlerImplHeap());
                auto *pHandlerImpl = PersistedHandlerImplHeap().New(handler, implDeleter);

                return p.AddPersistedHandler(pHandlerImpl);
            }

            void DeleteObject(object_type *p)
            {
                ObjectHeap().Delete(p);
            }

        private:            
            static void Destruct(object_heap_type &heap, std::vector<object_type *> &objects)
            {
                for (auto ri = objects.rbegin(), ri_end = objects.rend(); ri != ri_end; ++ri)
                    heap.Delete(*ri);
            }

            object_heap_type &ObjectHeap()
            {
                auto &provider = base_type::ProviderOf<object_type>();
                return provider.Heap();
            }

            holder_impl_heap_type &HolderImplHeap()
            {
                auto &provider = base_type::ProviderOf<holder_impl_type>();
                return provider.Heap();
            }

            persisted_handler_holder_impl_heap_type &PersistedHandlerImplHeap()
            {
                auto &provider = base_type::ProviderOf<persisted_handler_holder_impl_type>();
                return provider.Heap();
            }

            unique_ptr<std::vector<object_type *> > m_pObjects;
        };

        template<class ReversedPersistentInfoTypes>
        class PersistableHeapProviderImplImpl<ReversedPersistentInfoTypes, 
                                              typename end<ReversedPersistentInfoTypes>::type, 
                                              typename end<ReversedPersistentInfoTypes>::type> : 
            noncopyable
        {
        };

        
        
        
        
        template<class PersistentInfoTypes, LONG N>
        class ProvidingTypeAtImpl
        {
            typedef typename at_c<PersistentInfoTypes, N>::type persistent_info_type;
        public:
            typedef typename persistent_info_type::object_type type;
        };

        
        
        
        
        template<class PersistentInfoTypes, LONG N>
        class ProvidingHandlerTypeAtImpl
        {
            typedef typename at_c<PersistentInfoTypes, N>::type persistent_info_type;
        public:
            typedef typename persistent_info_type::persisted_handler_type type;
        };

        
        
        
        
        template<class ReversedPersistentInfoTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename find<ReversedPersistentInfoTypes, ProvidingType>::type i;
            typedef typename end<ReversedPersistentInfoTypes>::type i_end;
            BOOST_MPL_ASSERT((not_<is_same<i, i_end> >));
        public:
            typedef PersistableHeapProviderImplImpl<ReversedPersistentInfoTypes, i, i_end> type;
        };

        
        
        
        
        template<class PersistentInfoTypes>
        class ATL_NO_VTABLE PersistableHeapProviderImpl : 
            public PersistableHeapProviderImplImpl<typename reverse<PersistentInfoTypes>::type, 
                                                   typename begin<typename reverse<PersistentInfoTypes>::type>::type, 
                                                   typename end<typename reverse<PersistentInfoTypes>::type>::type>
        {
        private:
            typedef PersistableHeapProviderImpl<PersistentInfoTypes> this_type;
            typedef PersistentInfoTypes persistent_info_types;

        public:
            template<LONG N>
            struct persistent_info_at : 
                at_c<persistent_info_types, N>
            {
            };

            template<LONG N>
            struct providing_type_at : 
                ProvidingTypeAtImpl<persistent_info_types, N>
            {
            };

            template<LONG N>
            struct providing_handler_type_at : 
                ProvidingHandlerTypeAtImpl<persistent_info_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename reverse<persistent_info_types>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            inline typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

        
        
        
        
        template<class T0, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
        class DesignatedSequence
        {
            typedef vector<T0, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename lambda<not_<is_same<_, void_> > >::type is_designated;
        public:
            typedef typename fold<filter_view<types, is_designated>, vector<>, push_back<_1, _2> >::type type;
        };

    }   // namespace PersistableHeapProviderDetail {

    template<class T0, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
    struct ATL_NO_VTABLE PersistableHeapProvider : 
        PersistableHeapProviderDetail::PersistableHeapProviderImpl<
            typename PersistableHeapProviderDetail::DesignatedSequence<T0, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)>::type
        >
    {
        // The following typedef can't resolve if each element of the sequence is PersistableHeapProvider.
        //typedef typename PersistableHeapProviderDetail::DesignatedSequence<T0, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)>::type persistent_info_types;
        template<class T = boost::mpl::void_>
        struct persistent_info : 
            PersistableHeapProviderDetail::DesignatedSequence<T0, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)>
        {
        };
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_H
