#pragma once
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_HPP
#define URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace SmartPtrChainDetail {

        template<class Current, class ChainInfoSequence, class I, class IEnd>
        class ATL_NO_VTABLE SmartPtrChainImplImpl;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ChainInfo, previous_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ChainInfo, previous_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(SmartPtrChain, chain_info_types);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(SmartPtrChain, chain_info_types);

        template<class Current>
        struct ExtractPreviousOrDefault;

        template<class Last, class T>
        struct ExtractChainInfoSequenceOrDefault;

        template<class Last, class Current>
        class FlattenChainInfoImpl;

        template<class T>
        struct FlattenChainInfo;

        template<class Current, class T>
        class IsMappable;

    }   // namespace SmartPtrChainDetail


    template<class Current, class ChainInfoSequence>
    class ATL_NO_VTABLE SmartPtrChain;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINFWD_HPP