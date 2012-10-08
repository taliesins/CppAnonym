﻿#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataInfoApiHolderLabel, ApiLabel>
    {
    };

    namespace MetadataInfoDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        template<
            class MetadataInfoApiHolder
        >    
        struct MetadataInfoFacade
        {
            typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, RuntimeHostLabel>::type runtime_host_type;
            typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, MetadataInfoLabel>::type metadata_info_type;
            typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, MetadataDispenserLabel>::type metadata_dispenser_type;
            typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, MetadataDispenserPersistedHandlerLabel>::type metadata_dispenser_persisted_handler_type;

            typedef mpl::vector<
                DisposingInfo<metadata_dispenser_type, metadata_dispenser_persisted_handler_type>
            > disposing_info_types;
            typedef DisposableHeapProvider<disposing_info_types> base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;


            typedef runtime_host_type metadata_info_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<metadata_info_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<metadata_info_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<metadata_info_previous_type>::type metadata_info_chain_type;
        };

    }   // namespace MetadataInfoDetail {

    template<
        class MetadataInfoApiHolder
    >    
    class BaseMetadataInfo : 
        public MetadataInfoDetail::MetadataInfoFacade<MetadataInfoApiHolder>::base_ptr_chain_type,
        public MetadataInfoDetail::MetadataInfoFacade<MetadataInfoApiHolder>::base_heap_provider_type,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataInfo<MetadataInfoApiHolder> this_type;

        typedef MetadataInfoDetail::MetadataInfoFacade<MetadataInfoApiHolder> facade;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::metadata_dispenser_persisted_handler_type metadata_dispenser_persisted_handler_type;
        typedef typename facade::metadata_dispenser_provider_type metadata_dispenser_provider_type;
        typedef typename facade::metadata_info_previous_type metadata_info_previous_type;
        typedef typename facade::metadata_info_chain_type metadata_info_chain_type;

        BaseMetadataInfo()
        { }

        metadata_dispenser_type *CreateDispenser() const
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            
            TempPtr<metadata_dispenser_type> pNewDisp = NewDispenser();
            pNewDisp.Persist();
            return pNewDisp.Get();
        }

    private:
        friend typename metadata_info_previous_type;

        Utilities::TempPtr<metadata_dispenser_type> NewDispenser() const
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            metadata_info_chain_type &chain = ChainFrom<metadata_info_previous_type>();
            TempPtr<metadata_dispenser_type> pDisp = chain.NewObject<metadata_dispenser_type>(provider);
            metadata_dispenser_persisted_handler_type handler(const_cast<this_type *>(this));
            provider.AddPersistedHandler(pDisp, handler);
            return pDisp;
        }
    };





    namespace MetadataInfoDetail {

        template<
            class MetadataInfoApiHolder
        >    
        struct MetadataInfoPersistedHandlerFacade : 
            MetadataInfoFacade<MetadataInfoApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(MetadataInfoProvider, metadata_info_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(MetadataInfoProvider, metadata_info_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(MetadataInfoProvider, runtime_host_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(MetadataInfoProvider, runtime_host_type), 
                mpl::void_
            >::type metadata_info_provider_type;
        };

    }   // namespace MetadataInfoDetail {

    template<
        class MetadataInfoApiHolder
    >    
    class BaseMetadataInfoPersistedHandler
    {
    public:
        typedef MetadataInfoDetail::MetadataInfoPersistedHandlerFacade<MetadataInfoApiHolder> facade;
        typedef typename facade::runtime_host_type runtime_host_type;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_info_provider_type metadata_info_provider_type;

        typedef Utilities::TempPtr<metadata_info_type> sender_type;

        BaseMetadataInfoPersistedHandler(runtime_host_type *pRuntimeHost) : 
            m_pRuntimeHost(pRuntimeHost)
        { 
            _ASSERTE(pRuntimeHost != NULL);
        }
                
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pMetaInfo = *pSender;
            metadata_info_provider_type &provider = m_pRuntimeHost->ProviderOf<metadata_info_type>();
            TypeInfo key = mpl::identity<metadata_info_type>();
            m_pRuntimeHost->m_infoToIndex[key] = provider.RegisterObject(pMetaInfo);
        }
                
    private:                
        runtime_host_type *m_pRuntimeHost;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP