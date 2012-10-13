#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenserApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataDispenserApiHolderLabel, ApiLabel>
    {
    };

    namespace MetadataDispenserDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        template<
            class MetadataDispenserApiHolder
        >    
        struct MetadataDispenserFacade
        {
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataInfoLabel>::type metadata_info_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataDispenserLabel>::type metadata_dispenser_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataDispenserPersistedHandlerLabel>::type metadata_dispenser_persisted_handler_type;
            typedef DisposingInfo<metadata_dispenser_type, metadata_dispenser_persisted_handler_type> metadata_dispenser_disposing_info_type;


            //typedef DisposableHeapProvider<
            //> base_heap_provider_type;


            //typedef typename base_heap_provider_type::provider_of<assembly_metadata_type>::type assembly_metadata_provider_type;


            typedef metadata_info_type metadata_dispenser_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<metadata_dispenser_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<metadata_dispenser_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<metadata_dispenser_previous_type>::type metadata_dispenser_chain_type;
        };

    }   // namespace MetadataDispenserDetail {

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser : 
        public MetadataDispenserDetail::MetadataDispenserFacade<MetadataDispenserApiHolder>::base_ptr_chain_type
    {
    public:
        typedef MetadataDispenserDetail::MetadataDispenserFacade<MetadataDispenserApiHolder> facade;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::metadata_dispenser_persisted_handler_type metadata_dispenser_persisted_handler_type;
        typedef typename facade::metadata_dispenser_disposing_info_type metadata_dispenser_disposing_info_type;
        typedef typename facade::metadata_dispenser_previous_type metadata_dispenser_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::metadata_dispenser_chain_type metadata_dispenser_chain_type;
    };





    namespace MetadataDispenserDetail {

        template<
            class MetadataDispenserApiHolder
        >    
        struct MetadataDispenserPersistedHandlerFacade : 
            MetadataDispenserFacade<MetadataDispenserApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(MetadataDispenserProvider, metadata_dispenser_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(MetadataDispenserProvider, metadata_dispenser_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(MetadataDispenserProvider, metadata_info_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(MetadataDispenserProvider, metadata_info_type), 
                mpl::void_
            >::type metadata_dispenser_provider_type;
        };

    }   // namespace MetadataDispenserDetail {

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenserPersistedHandler
    {
    public:
        typedef MetadataDispenserDetail::MetadataDispenserPersistedHandlerFacade<MetadataDispenserApiHolder> facade;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::metadata_dispenser_persisted_handler_type metadata_dispenser_persisted_handler_type;
        typedef typename facade::metadata_dispenser_disposing_info_type metadata_dispenser_disposing_info_type;
        typedef typename facade::metadata_dispenser_previous_type metadata_dispenser_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::metadata_dispenser_chain_type metadata_dispenser_chain_type;
        typedef typename facade::metadata_dispenser_provider_type metadata_dispenser_provider_type;
        
        typedef Utilities::TempPtr<metadata_dispenser_type> sender_type;

        BaseMetadataDispenserPersistedHandler(metadata_info_type *pMetaInfo) : 
            m_pMetaInfo(pMetaInfo)
        { }
        
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pDisp = *pSender;
            metadata_dispenser_provider_type &provider = m_pMetaInfo->ProviderOf<metadata_dispenser_disposing_info_type>();
            provider.RegisterObject(pDisp);
        }

    private:        
        metadata_info_type *m_pMetaInfo;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP