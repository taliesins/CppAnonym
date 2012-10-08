#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabel.hpp>
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

    template<
        class MetadataInfoApiHolder
    >    
    class BaseMetadataInfo : 
        public SmartPtrChain<
            BaseMetadataInfo<MetadataInfoApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataInfo<MetadataInfoApiHolder> this_type;

        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        typedef typename provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;

        typedef typename chain_from<runtime_host_type>::type metadata_info_chain_type; 

        BaseMetadataInfo()
        { }

        boost::shared_ptr<metadata_dispenser_type> CreateDispenser() const
        {
            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            boost::shared_ptr<metadata_dispenser_type> pDisp = NewDispenser();
            provider.Register(pDisp);
            return pDisp;
        }

    private:
        friend typename runtime_host_type;

        boost::shared_ptr<metadata_dispenser_type> NewDispenser() const
        {
            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            metadata_info_chain_type &chain = ChainFrom<runtime_host_type>();
            return chain.NewObject<metadata_dispenser_type>(provider);
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP