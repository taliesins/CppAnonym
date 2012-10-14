#pragma once
#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_H
#define URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_H

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_LIMIT_TYPES, CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_LIMIT_TYPES, param)

    namespace DependentObjectsProviderDetail {

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE DependentObjectsProviderImplImpl;

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE DependentObjectsProviderImpl;

        template<CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_AUX_DECLARE_PARAMS>
        class DesignatedSequence;

    }   // namespace DependentObjectsProviderDetail {

    template<CPPANONYM_DEPENDENT_OBJECTS_PROVIDER_AUX_DECLARE_PARAMS>
    struct ATL_NO_VTABLE DependentObjectsProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_H