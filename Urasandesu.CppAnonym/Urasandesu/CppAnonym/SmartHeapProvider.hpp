#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
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
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class I>
        struct ProvidingTypeFacade
        {
            typedef typename mpl::deref<I>::type object_type;
            typedef typename AutoPtr<object_type>::make_heap_holder_impl<>::object_deleter_type object_deleter_type;
            typedef typename AutoPtr<object_type>::make_heap_holder_impl<>::type holder_impl_type;
            typedef typename AutoPtr<object_type>::make_heap_holder_impl<>::deleter_type holder_impl_deleter_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> object_object_tag_type;
            typedef ObjectTag<holder_impl_type, QuickHeapWithoutSubscriptOperator> holder_impl_object_tag_type;
            typedef SimpleHeapProvider<mpl::vector<object_object_tag_type, holder_impl_object_tag_type> > base_type;
            typedef typename base_type::provider_of<object_type>::type object_provider_type;
            typedef typename base_type::provider_of<holder_impl_type>::type holder_impl_provider_type;
            typedef typename object_provider_type::object_heap_type object_heap_type;
            typedef typename holder_impl_provider_type::object_heap_type holder_impl_heap_type;
        };

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImplImpl : 
            ProvidingTypeFacade<I>::base_type,
            public SmartHeapProviderImplImpl<ReversedProvidingTypes, typename mpl::next<I>::type, IEnd>
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
                                        typename mpl::end<ReversedProvidingTypes>::type, 
                                        typename mpl::end<ReversedProvidingTypes>::type> : 
            noncopyable
        {
        };

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename mpl::find<ReversedProvidingTypes, ProvidingType>::type i;
            typedef typename mpl::end<ReversedProvidingTypes>::type i_end;
        public:
            typedef SmartHeapProviderImplImpl<ReversedProvidingTypes, i, i_end> type;
        };

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE SmartHeapProviderImpl : 
            SmartHeapProviderImplImpl<typename mpl::reverse<ProvidingTypes>::type, 
                                      typename mpl::begin<typename mpl::reverse<ProvidingTypes>::type>::type, 
                                      typename mpl::end<typename mpl::reverse<ProvidingTypes>::type>::type>
        {
            typedef SmartHeapProviderImpl<ProvidingTypes> this_type;
            typedef ProvidingTypes providing_types;

            template<LONG N>
            struct providing_type_at : 
                mpl::at_c<providing_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename mpl::reverse<providing_types>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            inline typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

        template<class T0, CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
        class DesignatedSequence
        {
            typedef mpl::vector<T0, CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename mpl::lambda<not_<boost::is_same<_, void_> > >::type is_designated;
        public:
            typedef typename fold<filter_view<types, is_designated>, mpl::vector<>, mpl::push_back<_1, _2> >::type type;
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