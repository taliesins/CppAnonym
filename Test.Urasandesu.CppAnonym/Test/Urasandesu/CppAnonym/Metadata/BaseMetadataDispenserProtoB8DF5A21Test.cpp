#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataInfoApiType
    >    
    class BaseMetadataInfoProtoB8DF5A21
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IAssemblyMetadataApi { };
    struct IMetadataDispenserApi { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Metadata_BaseMetadataDispenserProtoB8DF5A21Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Metadata_BaseMetadataDispenserProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataDispenserApi;

        struct TestAssemblyMetadataApi : 
            IAssemblyMetadataApi
        {
            typedef TestMetadataDispenserApi parent_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        struct TestMetadataDispenserApi : 
            IMetadataDispenserApi
        {
            typedef boost::mpl::vector<TestAssemblyMetadataApi> child_api_types;
        };
        typedef BaseMetadataDispenserProtoB8DF5A21<TestMetadataDispenserApi> MetadataDispenser;
        typedef MetadataDispenser::metadata_info_type MetadataInfo;

        MetadataInfo metaInfo;
        
        
        // Act
        MetadataDispenser metaDisp;
        metaDisp.Init(metaInfo);

        typedef MetadataDispenser::assembly_metadata_type AssemblyMetadata;
        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        AssemblyMetadata const *pAsmMeta = metaDisp.LoadAssemblyFromFile(asmPath);


        // Assert
        ASSERT_FALSE(pAsmMeta == NULL);
        AssemblyMetadata const *pAsmMeta2 = metaDisp.LoadAssemblyFromFile(asmPath);
        ASSERT_EQ(pAsmMeta, pAsmMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Metadata_BaseMetadataDispenserProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataDispenserApi;

        struct TestAssemblyMetadataApi : 
            IAssemblyMetadataApi
        {
            typedef TestMetadataDispenserApi parent_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        struct TestMetadataDispenserApi : 
            IMetadataDispenserApi
        {
            typedef boost::mpl::vector<TestAssemblyMetadataApi> child_api_types;
        };
        typedef BaseMetadataDispenserProtoB8DF5A21<TestMetadataDispenserApi> MetadataDispenser;
        typedef MetadataDispenser::metadata_info_type MetadataInfo;

        MetadataInfo metaInfo;
        
        
        // Act
        MetadataDispenser metaDisp;
        metaDisp.Init(metaInfo);

        
    }
}
