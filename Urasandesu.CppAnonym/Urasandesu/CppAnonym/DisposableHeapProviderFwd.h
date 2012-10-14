#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_DISPOSABLE_HEAP_PROVIDER_LIMIT_TYPES, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_DISPOSABLE_HEAP_PROVIDER_LIMIT_TYPES, param)

    namespace DisposableHeapProviderDetail {

        CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(DisposingInfoDispose, Dispose, void, ());

        template<class I>
        struct DisposingInfoFacade;

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImplImpl;

        template<class DisposingInfo, class T>
        struct HasObjectT;

        template<class DisposingInfoTypes, LONG N>
        class ProvidingTypeAtImpl;

        template<class ReversedDisposingInfoTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class DisposingInfoTypes>
        struct ATL_NO_VTABLE DisposableHeapProviderImpl;

        template<CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
        class DesignatedSequence;

    }   // namespace DisposableHeapProviderDetail {

    template<CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
    struct ATL_NO_VTABLE DisposableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H