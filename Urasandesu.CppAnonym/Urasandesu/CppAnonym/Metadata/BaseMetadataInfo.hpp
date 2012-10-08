#pragma once
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

        //typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        //typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        //typedef typename provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;
        typedef typename providing_type_at<0>::type metadata_dispenser_type;

        typedef typename provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;

        typedef typename chaining_previous_type_at<0>::type metadata_info_previous_type;
        typedef typename chain_from<metadata_info_previous_type>::type metadata_info_chain_type; 
        typedef metadata_info_previous_type runtime_host_type;

        BaseMetadataInfo()
        { }

        metadata_dispenser_type *CreateDispenser() const
        {
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
            struct pDisp_Persisted
            {
                typedef TempPtr<metadata_dispenser_type> sender_type;

                pDisp_Persisted(this_type &this_) : 
                    m_pThis(&this_)
                { }
                
                void operator()(sender_type *pSender, void *pArg)
                {
                    sender_type &pDisp = *pSender;
                    metadata_dispenser_provider_type &provider = m_pThis->ProviderOf<metadata_dispenser_type>();
                    provider.RegisterObject(pDisp);
                }
                
                this_type *m_pThis;
            };
            pDisp.AddPersistedHandler(pDisp_Persisted(const_cast<this_type &>(*this)));
            return pDisp;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP