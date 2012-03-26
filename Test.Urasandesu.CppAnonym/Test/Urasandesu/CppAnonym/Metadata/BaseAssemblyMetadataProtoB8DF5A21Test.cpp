#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOrDefault.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOrDefault.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultTypeMetadataApiProtoB8DF5A21.h>
#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyMetadataApiProtoB8DF5A21.h>
//#endif
//
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestTypeMetadataApi
        {
        };

        struct TestAssemblyMetadataApi : 
            Traits::ChildApiOperable 
        {
            typedef INT metadata_dispenser_api_type;
            //typedef IMetaDataImport2 metadata_import_api_type;
            typedef TestTypeMetadataApi type_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        typedef BaseAssemblyMetadataProtoB8DF5A21<TestAssemblyMetadataApi> AssemblyMetadata;
        typedef AssemblyMetadata::metadata_dispenser_type MetadataDispenser;

        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(&pMetaDispApi))
        ); 

        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ASSERT_HRESULT_SUCCEEDED(
            pMetaDispApi->OpenScope(asmPath.c_str(), ofRead, 
                                    IID_IMetaDataImport2, 
                                    reinterpret_cast<IUnknown **>(&pMetaImpApi))
        );

        MetadataDispenser metaDisp;

        
        // Act
        AssemblyMetadata asmMeta;
        asmMeta.Init(metaDisp, pMetaImpApi);
        mdAssembly mda = asmMeta.GetToken();


        // Assert
        ASSERT_EQ(0x20000001, mda);
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestTypeMetadataApi : 
            Traits::ParentApiOperable,
            Traits::ChildApiOperable,  
            ITypeMetadataApi
        {
            typedef TestAssemblyMetadataApi parent_api_type;
            //typedef TestAssemblyMetadataApi assembly_metadata_api_type;
            //typedef IMetaDataImport2 metadata_import_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        struct TestAssemblyMetadataApi : 
            Traits::ChildApiOperable,  
            IAssemblyMetadataApi
        {
            typedef INT metadata_dispenser_api_type;
            //typedef IMetaDataImport2 metadata_import_api_type;
            //typedef TestTypeMetadataApi type_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2, TestTypeMetadataApi> child_api_types;
        };

        typedef BaseAssemblyMetadataProtoB8DF5A21<TestAssemblyMetadataApi> AssemblyMetadata;
        typedef AssemblyMetadata::metadata_dispenser_type MetadataDispenser;

        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(&pMetaDispApi))
        ); 

        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ASSERT_HRESULT_SUCCEEDED(
            pMetaDispApi->OpenScope(asmPath.c_str(), ofRead, 
                                    IID_IMetaDataImport2, 
                                    reinterpret_cast<IUnknown **>(&pMetaImpApi))
        );

        MetadataDispenser metaDisp;

        
        // Act
        AssemblyMetadata asmMeta;
        asmMeta.Init(metaDisp, pMetaImpApi);

        typedef AssemblyMetadata::type_metadata_type TypeMetadata;
        //BOOST_MPL_ASSERT((boost::is_same<AssemblyMetadata::type_metadata_type, INT>));
        std::wstring name(L"System.Func`1");
        TypeMetadata const *pTypeMeta = asmMeta.GetType(name);


        // Assert
        ASSERT_FALSE(pTypeMeta == NULL);
        TypeMetadata const *pTypeMeta2 = asmMeta.GetType(name);
        ASSERT_EQ(pTypeMeta, pTypeMeta2);
    }
}
