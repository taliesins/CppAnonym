#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace SmartHeapProviderDetail {

        template<class I>
        struct ProvidingTypeFacade;

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImplImpl;

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE SmartHeapProviderImpl;

    }   // namespace SmartHeapProviderDetail {

    template<class ProvidingTypes>
    struct ATL_NO_VTABLE SmartHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDERFWD_HPP