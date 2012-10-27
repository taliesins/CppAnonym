#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_H
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_H

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_PERSISTABLE_HEAP_PROVIDER_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_PERSISTABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_PERSISTABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_PERSISTABLE_HEAP_PROVIDER_LIMIT_TYPES, CPPANONYM_PERSISTABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_PERSISTABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_PERSISTABLE_HEAP_PROVIDER_LIMIT_TYPES, param)

    namespace PersistableHeapProviderDetail {

        template<class I>
        struct PersistentInfoFacade;

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE PersistableHeapProviderImplImpl;

        template<class PersistentInfoTypes, LONG N>
        class ProvidingTypeAtImpl;

        template<class ReversedPersistentInfoTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class PersistentInfoTypes>
        struct ATL_NO_VTABLE PersistableHeapProviderImpl;

        template<CPPANONYM_PERSISTABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
        class DesignatedSequence;

    }   // namespace PersistableHeapProviderDetail {

    template<CPPANONYM_PERSISTABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
    struct ATL_NO_VTABLE PersistableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_H