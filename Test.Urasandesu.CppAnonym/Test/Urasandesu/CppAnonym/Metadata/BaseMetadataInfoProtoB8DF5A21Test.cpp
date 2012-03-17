#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataInfoApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataProtoB8DF5A21.h>
#endif

//#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
//#include <Urasandesu/CppAnonym/IHeapContent.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTHOSTINFOAPIPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/DefaultHostInfoApiProto07F03042.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoProto07F03042.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostProto07F03042.h>
//#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
//#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseMetadataInfoProtoB8DF5A21Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        //struct TestMetadataDispenserApi;

        //struct TestAssemblyMetadataApi
        //{
        //    typedef TestMetadataDispenserApi metadata_dispenser_api_type;
        //    typedef IMetaDataImport2 metadata_import_api_type;
        //};

        //struct TestMetadataDispenserApi
        //{
        //    typedef TestMetadataInfoApi metadata_info_api_type;
        //    typedef TestAssemblyMetadataApi assembly_metadata_api_type;
        //};

        //struct TestMetadataInfoApi
        //{
        //    typedef INT runtime_host_api_type;
        //    typedef TestMetadataDispenserApi metadata_dispenser_api_type;
        //};
        typedef MetadataInfoProtoB8DF5A21 MetadataInfo;
#if 1
        typedef MetadataInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;
        //runtimeHost.m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";


        // Act
        MetadataInfo metaInfo;
        metaInfo.Init(runtimeHost);

        typedef MetadataInfo::metadata_dispenser_type MetadataDispenser;
        boost::shared_ptr<MetadataDispenser const> pMetaDisp = metaInfo.CreateDispenser();
        ASSERT_FALSE(pMetaDisp.get() == NULL);

        typedef MetadataDispenser::assembly_metadata_type AssemblyMetadata;
        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        AssemblyMetadata const *pAsmMeta = pMetaDisp->LoadAssemblyFromFile(asmPath);
        ASSERT_FALSE(pAsmMeta == NULL);

        AssemblyMetadata const *pAsmMeta2 = pMetaDisp->LoadAssemblyFromFile(asmPath);
        ASSERT_EQ(pAsmMeta, pAsmMeta2);
        //std::wstring assemblyName(L"System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        //boost::shared_ptr<AssemblyInfo> pAsmInfo = fuInfo.QueryAssemblyInfo(AssemblyQueryTypes::GetSize, assemblyName);


        //// Assert        
        //fs::path expected(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        //ASSERT_TRUE(fs::equivalent(expected, pAsmInfo->GetAssemblyPath()));
        //ASSERT_EQ(652, pAsmInfo->GetAssemblySizeInKB());
#endif
    }
}
