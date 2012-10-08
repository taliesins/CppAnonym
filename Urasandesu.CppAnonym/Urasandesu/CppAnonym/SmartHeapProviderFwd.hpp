#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_SMART_HEAP_PROVIDER_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_SMART_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_SMART_HEAP_PROVIDER_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_SMART_HEAP_PROVIDER_LIMIT_TYPES, CPPANONYM_SMART_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_SMART_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_SMART_HEAP_PROVIDER_LIMIT_TYPES, param)

    namespace SmartHeapProviderDetail {

        template<class I>
        struct ProvidingTypeFacade;

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImplImpl;

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE SmartHeapProviderImpl;

        template<CPPANONYM_SMART_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
        class DesignatedSequence;

    }   // namespace SmartHeapProviderDetail {

    template<CPPANONYM_SMART_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
    struct ATL_NO_VTABLE SmartHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP