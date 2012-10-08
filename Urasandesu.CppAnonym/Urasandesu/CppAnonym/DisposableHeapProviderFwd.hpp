#pragma once
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace DisposableHeapProviderDetail {

        CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(DisposingInfoDispose, Dispose, void, ());

        template<class I>
        struct DisposingInfoFacade;

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImplImpl;

        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(DisposingInfoObject, object_type);

        template<class DisposingInfo, class T>
        struct HasObjectT;

        template<class DisposingInfoTypes, LONG N>
        class ProvidingTypeAtImpl;

        template<class ReversedDisposingInfoTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class DisposingInfoTypes>
        struct ATL_NO_VTABLE DisposableHeapProviderImpl;

    }   // namespace DisposableHeapProviderDetail {

    template<class DisposingInfoTypes>
    struct ATL_NO_VTABLE DisposableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_HPP