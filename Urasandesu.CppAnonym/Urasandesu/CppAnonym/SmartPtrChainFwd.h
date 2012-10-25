#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_H
#define URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_H

namespace Urasandesu { namespace CppAnonym {

    namespace SmartPtrChainDetail {

        template<class Current, class ChainInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE SmartPtrChainImplImpl;

        template<class Current>
        struct ExtractPreviousOrDefault;

        template<class Last, class T>
        struct ExtractChainInfoTypesOrDefault;

        template<class Last, class Current>
        class FlattenChainInfoImpl;

        template<class T>
        struct FlattenChainInfo;

        template<class Current, class T>
        class IsMappable;

        template<class ChainInfo, class T>
        struct HasPreviousT;

        template<class ChainInfoTypes, LONG N>
        class ChainingPreviousTypeAtImpl;

        template<class Current, class ChainInfoTypes, class ChainingPreviousType>
        class ChainFromImpl;

        template<class T>
        struct Wrap;

        template<class T>
        struct Container;

        template<class Chain, class T>
        struct MapFirstAncestorSelector;

        template<class Chain, class T>
        struct MapFirstSelector;

        template<class Current, class ChainInfoTypes>
        class ATL_NO_VTABLE SmartPtrChainImpl;

    }   // namespace SmartPtrChainDetail

    template<class Current, class ChainInfoTypes>
    struct ATL_NO_VTABLE SmartPtrChain;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_H