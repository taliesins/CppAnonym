#pragma once
#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace PersistableHeapProviderDetail {

        template<class I>
        struct PersistentInfoFacade;

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE PersistableHeapProviderImplImpl;

        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistentInfoObject, object_type);

        template<class PersistentInfo, class T>
        struct HasObjectT;

        template<class PersistentInfoTypes, LONG N>
        class ProvidingTypeAtImpl;

        template<class ReversedPersistentInfoTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class PersistentInfoTypes>
        struct ATL_NO_VTABLE PersistableHeapProviderImpl;

    }   // namespace PersistableHeapProviderDetail {

    template<class PersistentInfoTypes>
    struct ATL_NO_VTABLE PersistableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDERFWD_HPP