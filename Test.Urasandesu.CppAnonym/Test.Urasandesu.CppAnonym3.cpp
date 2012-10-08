// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

// foward declarations
namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

    struct CppAnonymStorageApiHolderLabel { };
    struct CppAnonymStorageLabel { };

}}} // namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

    struct DefaultCppAnonymStorageApiHolder;

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym {

    template<
        class CppAnonymStorageApiHolder = ApiHolders::DefaultCppAnonymStorageApiHolder
    >    
    class BaseCppAnonymStorage;

    typedef BaseCppAnonymStorage<> CppAnonymStorage;

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

    struct HostInfoApiHolderLabel { };
    struct HostInfoLabel { };
    struct HostInfoPersistedHandlerLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    struct DefaultHostInfoApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiHolder = ApiHolders::DefaultHostInfoApiHolder
    >    
    class BaseHostInfo;

    typedef BaseHostInfo<> HostInfo;





    template<
        class HostInfoApiHolder = ApiHolders::DefaultHostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler;

    typedef BaseHostInfoPersistedHandler<> HostInfoPersistedHandler;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

    namespace DefaultCppAnonymStorageApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        struct DefaultCppAnonymStorageApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>
            > api_cartridges;
        };

    }   // namespace DefaultCppAnonymStorageApiHolderDetail {

    struct DefaultCppAnonymStorageApiHolder : 
        DefaultCppAnonymStorageApiHolderDetail::DefaultCppAnonymStorageApiHolderImpl
    {
    };

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct CppAnonymStorageApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Urasandesu::CppAnonym::Interfaces::CppAnonymStorageApiHolderLabel, ApiLabel>
    {
    };

    namespace CppAnonymStorageDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        template<
            class CppAnonymStorageApiHolder
        >    
        struct CppAnonymStorageFacade
        {
            typedef typename CppAnonymStorageApiAt<CppAnonymStorageApiHolder, HostInfoLabel>::type host_info_type;
            typedef StaticDependentObjectsStorage<host_info_type> base_type;
        };

    }   // namespace CppAnonymStorageDetail {

    template<
        class CppAnonymStorageApiHolder
    >    
    class BaseCppAnonymStorage : 
        public CppAnonymStorageDetail::CppAnonymStorageFacade<CppAnonymStorageApiHolder>::base_type
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    namespace DefaultHostInfoApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        struct DefaultHostInfoApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>,
                pair<HostInfoPersistedHandlerLabel, HostInfoPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultHostInfoApiHolderDetail {

    struct DefaultHostInfoApiHolder : 
        DefaultHostInfoApiHolderDetail::DefaultHostInfoApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct HostInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::HostInfoApiHolderLabel, ApiLabel>
    {
    };

    namespace HostInfoDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        
        template<
            class HostInfoApiHolder
        >    
        struct HostInfoFacade
        {
            typedef typename HostInfoApiAt<HostInfoApiHolder, HostInfoLabel>::type host_info_type;
            typedef typename HostInfoApiAt<HostInfoApiHolder, HostInfoPersistedHandlerLabel>::type host_info_persisted_handler_type;
            typedef DisposingInfo<host_info_type, host_info_persisted_handler_type> host_info_disposing_info_type;


            typedef DisposableHeapProvider<
                host_info_disposing_info_type 
            > base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<host_info_disposing_info_type>::type host_info_provider_type;


            typedef mpl::void_ host_info_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<host_info_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<host_info_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<host_info_previous_type>::type host_info_chain_type;
        };
    
    }   // namespace HostInfoDetail {

    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfo : 
        public HostInfoDetail::HostInfoFacade<HostInfoApiHolder>::base_ptr_chain_type,
        public HostInfoDetail::HostInfoFacade<HostInfoApiHolder>::base_heap_provider_type,
        public SimpleDisposable
    {
    public:
        typedef BaseHostInfo<HostInfoApiHolder> this_type;
        
        typedef HostInfoDetail::HostInfoFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::host_info_persisted_handler_type host_info_persisted_handler_type;
        typedef typename facade::host_info_disposing_info_type host_info_disposing_info_type;
        typedef typename facade::base_heap_provider_type base_heap_provider_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;

        BaseHostInfo()
        { }

        static host_info_type *CreateHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            
            TempPtr<host_info_type> pHost = NewHost();
            pHost.Persist();
            return pHost.Get();
        }
    
    private:
        static Utilities::TempPtr<host_info_type> NewHost()
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            host_info_type &hostInfo = CppAnonymStorage::Object<host_info_type>();
            host_info_provider_type &provider = hostInfo.ProviderOf<host_info_disposing_info_type>();
            TempPtr<host_info_type> pHostInfo = host_info_chain_type::NewRootObject<host_info_type>(provider);
            host_info_persisted_handler_type handler(&hostInfo);
            provider.AddPersistedHandler(pHostInfo, handler);
            return pHostInfo;
        }
    };





    namespace HostInfoDetail {

        template<
            class HostInfoApiHolder
        >    
        struct HostInfoPersistedHandlerFacade : 
            HostInfoFacade<HostInfoApiHolder>
        {
        };

    }   // namespace HostInfoDetail {
    
    template<
        class HostInfoApiHolder
    >    
    class BaseHostInfoPersistedHandler
    {
    public:
        typedef HostInfoDetail::HostInfoPersistedHandlerFacade<HostInfoApiHolder> facade;
        typedef typename facade::host_info_type host_info_type;
        typedef typename facade::host_info_persisted_handler_type host_info_persisted_handler_type;
        typedef typename facade::host_info_disposing_info_type host_info_disposing_info_type;
        typedef typename facade::base_heap_provider_type base_heap_provider_type;
        typedef typename facade::host_info_provider_type host_info_provider_type;
        typedef typename facade::host_info_previous_type host_info_previous_type;
        typedef typename facade::chain_info_types chain_info_types;
        typedef typename facade::base_ptr_chain_type base_ptr_chain_type;
        typedef typename facade::host_info_chain_type host_info_chain_type;
        
        typedef Utilities::TempPtr<host_info_type> sender_type;

        BaseHostInfoPersistedHandler(host_info_type *pHostInfo) : 
            m_pHostInfo(pHostInfo)
        { }

        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pHostInfo = *pSender;

            host_info_provider_type &provider = m_pHostInfo->ProviderOf<host_info_disposing_info_type>();
            provider.RegisterObject(pHostInfo);
        }

    private:
        host_info_type *m_pHostInfo;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

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
    }


}
