#pragma once
#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace DependentObjectsProviderDetail {

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE DependentObjectsProviderImplImpl;

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE DependentObjectsProviderImpl;

    }   // namespace DependentObjectsProviderDetail {

    template<class ProvidingTypes>
    struct ATL_NO_VTABLE DependentObjectsProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDERFWD_HPP