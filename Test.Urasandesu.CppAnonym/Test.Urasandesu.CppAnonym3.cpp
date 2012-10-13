// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

// foward declarations
namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

}}} // namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct MetadataDispenserApiHolderLabel { };
    struct MetadataDispenserLabel { };
    struct MetadataDispenserPersistedHandlerLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultMetadataDispenserApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser;

    typedef BaseMetadataDispenser<> MetadataDispenser;

    
    
    
    
    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenserPersistedHandler;

    typedef BaseMetadataDispenserPersistedHandler<> MetadataDispenserPersistedHandler;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#ifndef URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDER_H
#include <Urasandesu/CppAnonym/ApiHolders/DefaultCppAnonymStorageApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HPP
#include <Urasandesu/CppAnonym/BaseCppAnonymStorage.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPI_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHost.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultMetadataDispenserApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataDispenserApiHolderImpl
        {
            typedef map<
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<MetadataDispenserPersistedHandlerLabel, MetadataDispenserPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultMetadataDispenserApiHolderDetail {

    struct DefaultMetadataDispenserApiHolder : 
        DefaultMetadataDispenserApiHolderDetail::DefaultMetadataDispenserApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
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

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {


// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test3.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test3, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        HostInfo const *pHostInfo = HostInfo::CreateHost();
        ASSERT_TRUE(pHostInfo != NULL);

        RuntimeHost const *pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost != NULL);

        MetadataInfo const *pMetaInfo = pRuntimeHost->Map<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo != NULL);

        MetadataDispenser *pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaDisp != NULL);
    }


}
