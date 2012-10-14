#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_H
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_H

#ifndef URASANDESU_CPPANONYM_IDISPOSABLE_HPP
#include <Urasandesu/CppAnonym/IDisposable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H
#include <Urasandesu/CppAnonym/DisposableHeapProviderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DisposableHeapProviderDetail {

        namespace mpl = boost::mpl;
        using mpl::_;
        using mpl::_1;
        using mpl::_2;
        using mpl::deref;
        using mpl::filter_view;
        using mpl::fold;
        using mpl::not_;
        using mpl::void_;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        template<class T, class HasDispose>
        struct DisposeCoreImpl
        {
            static void DisposeCore(T *p);
        };

        template<class T>
        struct DisposeCoreImpl<T, mpl::true_> 
        { 
            static void DisposeCore(T *p);
        };

        template<class I>
        struct DisposingInfoFacade
        {
            typedef typename mpl::deref<I>::type disposing_info_type;
            typedef PersistableHeapProvider<disposing_info_type> base_type;
            typedef typename base_type::object_type object_type;
            typedef typename base_type::persisted_handler_type persisted_handler_type;
        };

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImplImpl : 
            public DisposingInfoFacade<I>::base_type,
            public DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DisposingInfoFacade<I> facade;
            typedef typename facade::base_type base_type;
            typedef typename facade::object_type object_type;
            typedef typename facade::persisted_handler_type persisted_handler_type;

            ~DisposableHeapProviderImplImpl();
            TempPtr<object_type> NewObject();
            SIZE_T RegisterObject(TempPtr<object_type> &p);
            object_type *GetObject(SIZE_T n);
            SIZE_T AddPersistedHandler(TempPtr<object_type> &p, persisted_handler_type const &handler);

        private:
            static void Destruct(std::vector<object_type *> &objects);
            static void DisposeCore(object_type *p);
        };

        template<class ReversedDisposingInfoTypes>
        class DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, 
                                              typename mpl::end<ReversedDisposingInfoTypes>::type, 
                                              typename mpl::end<ReversedDisposingInfoTypes>::type> : 
            noncopyable
        {
        };

        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(DisposingInfoObject, object_type);

        template<class DisposingInfo, class T>
        struct HasObjectT : 
            boost::is_same<typename CPP_ANONYM_GET_MEMBER_TYPE(DisposingInfoObject, DisposingInfo)::type, T>
        {
        };

        template<class DisposingInfoTypes, LONG N>
        class ProvidingTypeAtImpl
        {
            typedef typename mpl::at_c<DisposingInfoTypes, N>::type disposing_info_type;
        public:
            typedef typename disposing_info_type::object_type type;
        };

        template<class DisposingInfoTypes, class T>
        class FirstProviderOfImpl
        {
            typedef typename mpl::find_if<DisposingInfoTypes, HasObjectT<mpl::_1, T> >::type i;
        public:
            typedef typename ProviderOfImpl<typename mpl::reverse<DisposingInfoTypes>::type, typename deref<i>::type>::type type;
        };

        template<class ReversedDisposingInfoTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename mpl::find<ReversedDisposingInfoTypes, ProvidingType>::type i;
            typedef typename mpl::end<ReversedDisposingInfoTypes>::type i_end;
            BOOST_MPL_ASSERT((not_<boost::is_same<i, i_end> >));
        public:
            typedef DisposableHeapProviderImplImpl<ReversedDisposingInfoTypes, i, i_end> type;
        };

        template<class ReversedDisposingInfoTypes, class T>
        class IsProvidedObjectImpl
        {
            typedef typename mpl::find_if<ReversedDisposingInfoTypes, HasObjectT<mpl::_1, T> >::type i;
            typedef typename mpl::end<ReversedDisposingInfoTypes>::type i_end;
        public:
            typedef typename mpl::not_<is_same<i, i_end> >::type type;
        };

        template<class DisposingInfoTypes, class T>
        class FirstProvidingPersistedHandlerImpl
        {
            typedef typename mpl::find_if<DisposingInfoTypes, HasObjectT<mpl::_1, T> >::type i;
            typedef typename mpl::deref<i>::type disposing_info_type;
        public:
            typedef typename disposing_info_type::persisted_handler_type type;
        };
        
        template<class DisposingInfoTypes>
        struct ATL_NO_VTABLE DisposableHeapProviderImpl : 
            DisposableHeapProviderImplImpl<typename mpl::reverse<DisposingInfoTypes>::type, 
                                           typename mpl::begin<typename mpl::reverse<DisposingInfoTypes>::type>::type, 
                                           typename mpl::end<typename mpl::reverse<DisposingInfoTypes>::type>::type>
        {
            typedef DisposableHeapProviderImpl<DisposingInfoTypes> this_type;
            typedef DisposingInfoTypes disposing_info_types;

            template<LONG N>
            struct disposing_info_at : 
                mpl::at_c<disposing_info_types, N>
            {
            };

            template<LONG N>
            struct providing_type_at : 
                ProvidingTypeAtImpl<disposing_info_types, N>
            {
            };

            template<class T>
            struct first_provider_of : 
                FirstProviderOfImpl<disposing_info_types, T>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename mpl::reverse<disposing_info_types>::type, ProvidingType>
            {
            };

            template<class T>
            struct is_provided_object : 
                IsProvidedObjectImpl<typename mpl::reverse<disposing_info_types>::type, T>
            {
            };

            template<class T>
            struct first_providing_persisted_handler : 
                FirstProvidingPersistedHandlerImpl<disposing_info_types, T>
            {
            };

            template<class T>
            typename first_provider_of<T>::type & FirstProviderOf() const;

            template<class ProvidingType>
            typename provider_of<ProvidingType>::type &ProviderOf() const;
        };

        template<class T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
        class DesignatedSequence
        {
            typedef mpl::vector<T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)> types;
            typedef typename mpl::lambda<not_<boost::is_same<_, void_> > >::type is_designated;
        public:
            typedef typename fold<filter_view<types, is_designated>, mpl::vector<>, mpl::push_back<_1, _2> >::type type;
        };

    }   // namespace DisposableHeapProviderDetail {

    template<class T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(class T)>
    struct ATL_NO_VTABLE DisposableHeapProvider : 
        DisposableHeapProviderDetail::DisposableHeapProviderImpl<
            typename DisposableHeapProviderDetail::DesignatedSequence<T0, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(T)>::type
        >
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_H