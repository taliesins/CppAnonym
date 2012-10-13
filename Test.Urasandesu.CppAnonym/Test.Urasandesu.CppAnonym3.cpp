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

    struct AssemblyMetadataApiHolderLabel { };
    struct AssemblyMetadataLabel { };
    struct AssemblyMetadataPersistedHandlerLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultAssemblyMetadataApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataApiHolder = ApiHolders::DefaultAssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata;

    typedef BaseAssemblyMetadata<> AssemblyMetadata;

    
    
    
    
    template<
        class AssemblyMetadataApiHolder = ApiHolders::DefaultAssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadataPersistedHandler;

    typedef BaseAssemblyMetadataPersistedHandler<> AssemblyMetadataPersistedHandler;

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

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {


    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    namespace AssemblyMetadataDetail {
        
        template<
            class AssemblyMetadataApiHolder
        >    
        struct AssemblyMetadataFacade
        {
        };

    }   // namespace AssemblyMetadataDetail {

    template<
        class AssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata
    {
    public:
        mdAssembly GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }
    };





    namespace AssemblyMetadataDetail {

        template<
            class AssemblyMetadataApiHolder
        >    
        struct AssemblyMetadataPersistedHandlerFacade : 
            AssemblyMetadataFacade<AssemblyMetadataApiHolder>
        {
            //CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(AssemblyMetadataProvider, assembly_metadata_provider_type);
            //CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(AssemblyMetadataProvider, assembly_metadata_provider_type);
            //typedef typename mpl::eval_if<
            //    CPP_ANONYM_HAS_MEMBER_TYPE(AssemblyMetadataProvider, metadata_dispenser_type), 
            //    CPP_ANONYM_GET_MEMBER_TYPE(AssemblyMetadataProvider, metadata_dispenser_type), 
            //    mpl::void_
            //>::type assembly_metadata_provider_type;
        };

    }   // namespace AssemblyMetadataDetail {

    template<
        class AssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadataPersistedHandler
    {
    //public:
    //    typedef AssemblyMetadataDetail::AssemblyMetadataPersistedHandlerFacade<AssemblyMetadataApiHolder> facade;
    //    typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
    //    typedef typename facade::assembly_metadata_type assembly_metadata_type;
    //    typedef typename facade::assembly_metadata_provider_type assembly_metadata_provider_type;

    //    typedef Utilities::TempPtr<assembly_metadata_type> sender_type;

    //    BaseAssemblyMetadataPersistedHandler(metadata_dispenser_type *pDisp) : 
    //        m_pDisp(pDisp)
    //    {
    //        _ASSERTE(pDisp != NULL); 
    //    }
    //    
    //    void operator()(sender_type *pSender, void *pArg)
    //    {
    //        sender_type &pAsm = *pSender;            
    //        assembly_metadata_provider_type &provider = m_pDisp->ProviderOf<assembly_metadata_type>();
    //        m_pDisp->m_asmToIndex[pAsm.Get()] = provider.RegisterObject(pAsm);
    //    }

    //private:        
    //    metadata_dispenser_type *m_pDisp;
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

        AssemblyMetadata const *pSystemCore = NULL;
        pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                             L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());
    }


}
