#include "stdafx.h"

//#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
//#include <Urasandesu/CppAnonym/HeapProvider.h>
//#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

//#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
//#include <Urasandesu/CppAnonym/Traits/ParentApiOperable.h>
//#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOrDefault.h>
#endif

//#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
//#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
//#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOrDefault.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataProtoB8DF5A21.h>
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
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
//#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21
    {
    };

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test.*
namespace {

    void SetupApis(IMetaDataDispenserEx **ppMetaDispApi, IMetaDataImport2 **ppMetaImpApi, mdTypeDef &mdtd)
    {
        namespace fs = boost::filesystem;

        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(ppMetaDispApi))
        ); 

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaDispApi)->OpenScope(asmPath.c_str(), ofRead, 
                                        IID_IMetaDataImport2, 
                                        reinterpret_cast<IUnknown **>(ppMetaImpApi))
        );

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaImpApi)->FindTypeDefByName(L"System.Func`1", NULL, &mdtd)
        );
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi  
            //Traits::ChildApiOperable 
        {
            typedef INT assembly_metadata_api_type;
            //typedef IMetaDataImport2 metadata_import_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(&pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, pMetaImpApi);
        typeMeta.SetKey(mdtd);
        mdToken mdt = typeMeta.GetToken();


        // Assert
        ASSERT_EQ(0x02000058, mdt);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi  
            //Traits::ChildApiOperable 
        {
            typedef INT assembly_metadata_api_type;
            //typedef IMetaDataImport2 metadata_import_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(&pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, pMetaImpApi);

        std::wstring name(L".ctor");
        CallingConventions callConvention = CallingConventions::CC_HAS_THIS;
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VOID);
        std::vector<TypeMetadata const *> paramTypes;
        TypeMetadata paramType0;
        paramType0.SetKind(TypeKinds::TK_OBJECT);
        paramTypes.push_back(&paramType0);
        TypeMetadata paramType1;
        paramType1.SetKind(TypeKinds::TK_I);
        paramTypes.push_back(&paramType1);
        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        //typeMeta.SetKey(mdtd);
        //mdToken mdt = typeMeta.GetToken();


        //// Assert
        //ASSERT_EQ(0x02000058, mdt);
    }

    struct TypeKindsDef
    {
        enum type
        {
            TK_END = ELEMENT_TYPE_END, 
            TK_VOID = ELEMENT_TYPE_VOID, 
            TK_BOOLEAN = ELEMENT_TYPE_BOOLEAN, 
            TK_CHAR = ELEMENT_TYPE_CHAR, 
            TK_UNREACHED
        };
    };

    struct TypeKindsDef2
    {
        enum type
        {
            TK_END = ELEMENT_TYPE_END, 
            TK_VOID = ELEMENT_TYPE_VOID, 
            TK_BOOLEAN = ELEMENT_TYPE_BOOLEAN, 
            TK_CHAR = ELEMENT_TYPE_CHAR, 
            TK_UNREACHED
        };
    };
    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_03)
    {
        typedef Urasandesu::CppAnonym::SafeEnum<TypeKindsDef> TypeKinds;
        TypeKinds kinds = TypeKinds::TK_END;    // O.K.
        //TypeKindsDef2::type kinds3 = kinds;   // error C2440
        //int i = kinds;                          // error C2440
        //TypeKinds kinds4 = 10;                  // error C2440
        TypeKinds kinds2 = TypeKinds::TK_END;    // O.K.
        kinds = kinds2;

        switch (kinds.Value())
        {
            case TypeKinds::TK_END:
                break;
            case TypeKinds::TK_VOID:
                break;
            default:
                break;
        }
    }
    
    
    
    // TODO: Move the following prototypes to the tests for ParentApiOrDefault/ChildApiOrDefault.
    struct DefaultHogedataInfoApi;

    template<
        class HogedataInfoApiType
    >
    class BaseHogedataInfo;

    struct IHogedataDispenserApi { };
    struct DefaultHogedataDispenserApi : 
        //Urasandesu::CppAnonym::Traits::ParentApiOperable, 
        IHogedataDispenserApi
    {
        typedef DefaultHogedataInfoApi parent_api_type;
        typedef boost::mpl::vector<> child_api_types;
    };
    
    struct IHogedataInfoApi;

    template<
        class HogedataDispenserApiType = DefaultHogedataDispenserApi
    >
    class BaseHogedataDispenser
    {
    public:

        typedef typename Urasandesu::CppAnonym::Traits::ParentApiOrDefault<HogedataDispenserApiType, IHogedataInfoApi>::type hogedata_info_api_type;

        BaseHogedataInfo<hogedata_info_api_type> *GetInfo() const
        {
            return NULL;
        }
    };

    struct IHogedataInfoApi { };
    struct DefaultHogedataInfoApi : 
        //Urasandesu::CppAnonym::Traits::ChildApiOperable, 
        IHogedataInfoApi
    {
        typedef boost::mpl::void_ parent_api_type;
        typedef boost::mpl::vector<DefaultHogedataDispenserApi> child_api_types;
    };

    template<
        class HogedataInfoApiType = DefaultHogedataInfoApi
    >
    class BaseHogedataInfo
    {
    public:
        
        typedef typename Urasandesu::CppAnonym::Traits::ChildApiOrDefault<HogedataInfoApiType, IHogedataDispenserApi>::type hogedata_dispenser_api_type;

        BaseHogedataDispenser<hogedata_dispenser_api_type> *GetDispenser() const
        {
            return NULL;
        }
    };

    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_04)
    {
        namespace mpl = boost::mpl;
        namespace UCT = Urasandesu::CppAnonym::Traits;

        typedef BaseHogedataInfo<> HogedataInfo;
        HogedataInfo hogeInfo;

        hogeInfo.GetDispenser();
        BOOST_MPL_ASSERT((boost::is_same<HogedataInfo::hogedata_dispenser_api_type, DefaultHogedataDispenserApi>));

        typedef BaseHogedataInfo<INT> HogedataInfo2;
        HogedataInfo2 hogeInfo2;
        BOOST_MPL_ASSERT((boost::is_same<HogedataInfo2::hogedata_dispenser_api_type, UCT::DefaultChildApi<INT, IHogedataDispenserApi>>));

        
        typedef BaseHogedataDispenser<> HogedataDispenser;
        HogedataDispenser hogeDisp;

        hogeDisp.GetInfo();
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_api_type, DefaultHogedataInfoApi>));

        typedef BaseHogedataDispenser<INT> HogedataDispenser2;
        HogedataDispenser2 hogeDisp2;
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser2::hogedata_info_api_type, UCT::DefaultParentApi<INT, IHogedataInfoApi>>));
    }
}
