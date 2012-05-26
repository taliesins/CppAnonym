#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/DefaultStrongNameKeyApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H
#include <Urasandesu/CppAnonym/Utilities/AnyPointer.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseTestMetadataDispenserProtoB8DF5A21
    {
    public:
        template<class T>
        T const *FindType() const 
        {
            if (m_pType.IsEmpty())
            {
                m_pType = new T();
            } 
            return m_pType;
        }

    private:
        mutable Utilities::AnyPointer m_pType;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test.*
namespace {

    void SetupApis(boost::filesystem::path const &asmPath, 
                   IMetaDataDispenserEx **ppMetaDispApi, 
                   IMetaDataImport2 **ppMetaImpApi)
    {
        namespace fs = boost::filesystem;

        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(ppMetaDispApi))
        ); 

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaDispApi)->OpenScope(asmPath.c_str(), ofRead, 
                                        IID_IMetaDataImport2, 
                                        reinterpret_cast<IUnknown **>(ppMetaImpApi))
        );
    }

    
    void SetupApis(boost::filesystem::path const &asmPath, 
                   IMetaDataDispenserEx **ppMetaDispApi, 
                   IMetaDataImport2 **ppMetaImpApi, 
                   IMetaDataAssemblyImport **ppMetaAsmImpApi, 
                   mdAssembly &mda)
    {
        namespace fs = boost::filesystem;

        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(ppMetaDispApi))
        ); 

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaDispApi)->OpenScope(asmPath.c_str(), ofRead, 
                                        IID_IMetaDataImport2, 
                                        reinterpret_cast<IUnknown **>(ppMetaImpApi))
        );

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaImpApi)->QueryInterface(IID_IMetaDataAssemblyImport, 
                                            reinterpret_cast<void **>(ppMetaAsmImpApi))
        );

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaAsmImpApi)->GetAssemblyFromScope(&mda) 
        );
    }
    
    
    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Hoge)
    {
        namespace fs = boost::filesystem;

        fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        ATL::CComPtr<IMetaDataAssemblyImport> pMetaAsmImpApi;
        mdAssembly mda = mdAssemblyNil;
        SetupApis(asmPath, &pMetaDispApi, &pMetaImpApi, &pMetaAsmImpApi, mda);

        std::auto_ptr<PublicKeyBlob> pPubKeyToken;
        DWORD pubKeyTokenSize = 0;
        std::auto_ptr<WCHAR> name;
        ULONG nameSize = 0;
        ASSEMBLYMETADATA amd;
        ::ZeroMemory(&amd, sizeof(ASSEMBLYMETADATA));
        DWORD asmFlags = 0;
        DWORD asmFlagsTmp = 0;
        ASSERT_HRESULT_SUCCEEDED(
            pMetaAsmImpApi->GetAssemblyProps(mda, NULL, NULL, NULL, NULL, 0, 
                                             &nameSize, &amd, 
                                             &asmFlagsTmp)
        );

        asmFlags |= (asmFlagsTmp & ~afPublicKey);
        name = std::auto_ptr<WCHAR>(new WCHAR[nameSize]);
        amd.szLocale = amd.cbLocale ? new WCHAR[amd.cbLocale] : NULL;
        amd.rOS = amd.ulOS ? new OSINFO[amd.ulOS] : NULL;
        amd.rProcessor = amd.ulProcessor ? new ULONG[amd.ulProcessor] : NULL;

        void const *pPubKey = NULL;
        DWORD pubKeySize = 0;
        ASSERT_HRESULT_SUCCEEDED(
            pMetaAsmImpApi->GetAssemblyProps(mda, &pPubKey, &pubKeySize, NULL, 
                                             name.get(), nameSize, NULL, 
                                             &amd, NULL)
        );

        std::wcout << L"Assembly Name: " << name.get() << std::endl;
        std::wcout << L"Major Version: " << amd.usMajorVersion << std::endl;
        std::wcout << L"Minor Version: " << amd.usMinorVersion << std::endl;
        std::wcout << L"Build Number: " << amd.usBuildNumber << std::endl;
        std::wcout << L"Revision Number: " << amd.usRevisionNumber << std::endl;
        std::wcout << L"Locale: " << (amd.szLocale == NULL ? L"" : amd.szLocale) << std::endl;
        std::wcout << L"Processor IDs: ";
        for (DWORD const *i = amd.rProcessor, *i_end = i + amd.ulProcessor; i != i_end; ++i)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
        std::wcout << L"OSINFOs: ";
        for (OSINFO const *i = amd.rOS, *i_end = i + amd.ulOS; i != i_end; ++i)
        {
            OSINFO const &osInfo = *i;
            std::cout << "(" << osInfo.dwOSPlatformId << ", " << osInfo.dwOSMajorVersion << ", " << osInfo.dwOSMinorVersion << ") ";
        }
        std::cout << std::endl;

        //for (BYTE const *i = reinterpret_cast<BYTE const *>(pPubKey), *i_end = i + pubKeySize; i != i_end; ++i)
        //{
        //    std::cout << boost::format("%|1$02X|") % static_cast<INT>(*i);
        //}
        //std::cout << std::endl;
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Test_01)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi 
        {
            typedef INT metadata_dispenser_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> external_api_types;
            typedef mpl::map<mpl::pair<IMetaDataImport2, IMetaDataImport2>> api_cartridges;
        };

        typedef BaseAssemblyMetadata<TestAssemblyMetadataApi> AssemblyMetadata;
        typedef AssemblyMetadata::metadata_dispenser_type MetadataDispenser;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        SetupApis(asmPath, &pMetaDispApi, &pMetaImpApi);

        MetadataDispenser metaDisp;

        
        // Act
        AssemblyMetadata asmMeta;
        asmMeta.Init(metaDisp, *pMetaImpApi);
        mdAssembly mda = asmMeta.GetToken();


        // Assert
        ASSERT_EQ(0x20000001, mda);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Test_02)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestTypeMetadataApi
        {
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestAssemblyMetadataApi, 
                                       IMetaDataImport2, 
                                       BaseAssemblyMetadata<TestAssemblyMetadataApi>> external_api_types;
            typedef mpl::map<mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                             mpl::pair<AssemblyMetadataLabel, BaseAssemblyMetadata<TestAssemblyMetadataApi>>> api_cartridges;
        };

        struct TestAssemblyMetadataApi
        {
            typedef INT metadata_dispenser_api_type;
            typedef boost::mpl::vector<IMetaDataImport2, TestTypeMetadataApi> external_api_types;
            typedef mpl::map<mpl::pair<AssemblyNameMetadataLabel, BaseAssemblyNameMetadata<>>, 
                             mpl::pair<TypeMetadataLabel, BaseTypeMetadata<TestTypeMetadataApi>>, 
                             mpl::pair<IMetaDataImport2, IMetaDataImport2>> api_cartridges;
        };

        typedef BaseAssemblyMetadata<TestAssemblyMetadataApi> AssemblyMetadata;
        typedef AssemblyMetadata::metadata_dispenser_type MetadataDispenser;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        SetupApis(asmPath, &pMetaDispApi, &pMetaImpApi);

        MetadataDispenser metaDisp;

        
        // Act
        AssemblyMetadata asmMeta;
        asmMeta.Init(metaDisp, *pMetaImpApi);

        typedef AssemblyMetadata::type_metadata_type TypeMetadata;
        std::wstring name(L"System.Func`1");
        TypeMetadata const *pTypeMeta = asmMeta.GetType(name);


        // Assert
        ASSERT_FALSE(pTypeMeta == NULL);
        TypeMetadata const *pTypeMeta2 = asmMeta.GetType(name);
        ASSERT_EQ(pTypeMeta, pTypeMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Test_03)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestAssemblyNameMetadataApi
        {
            typedef mpl::map<mpl::pair<AssemblyMetadataLabel, BaseAssemblyMetadata<TestAssemblyMetadataApi>>, 
                             mpl::pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>> api_cartridges;
        };

        struct TestAssemblyMetadataApi
        {
            typedef mpl::map<mpl::pair<AssemblyNameMetadataLabel, BaseAssemblyNameMetadata<TestAssemblyNameMetadataApi>>, 
                             mpl::pair<MetadataDispenserLabel, BaseTestMetadataDispenserProtoB8DF5A21<mpl::void_>>, 
                             mpl::pair<IMetaDataImport2, IMetaDataImport2>> api_cartridges;
        };

        typedef BaseAssemblyMetadata<TestAssemblyMetadataApi> AssemblyMetadata;
        typedef AssemblyMetadata::metadata_dispenser_type MetadataDispenser;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        SetupApis(asmPath, &pMetaDispApi, &pMetaImpApi);

        MetadataDispenser metaDisp;

        
        // Act
        AssemblyMetadata asmMeta;
        asmMeta.Init(metaDisp, *pMetaImpApi);

        typedef AssemblyMetadata::assembly_name_metadata_type AssemblyNameMetadata;
        AssemblyNameMetadata const *pAsmNameMeta = asmMeta.GetAssemblyName();

        
        // Assert
        ASSERT_TRUE(pAsmNameMeta != NULL);
        AssemblyNameMetadata const *pAsmNameMeta2 = asmMeta.GetAssemblyName();
        ASSERT_EQ(pAsmNameMeta, pAsmNameMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseAssemblyMetadataProtoB8DF5A21Test, Test_04)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestAssemblyNameMetadataApi
        {
            typedef boost::mpl::vector<TestAssemblyMetadataApi, IMetaDataAssemblyImport> external_api_types;
            typedef mpl::map<mpl::pair<AssemblyMetadataLabel, BaseAssemblyMetadata<TestAssemblyMetadataApi>>, 
                             mpl::pair<StrongNaming::StrongNameInfoLabel, StrongNaming::BaseStrongNameInfo<>>, 
                             mpl::pair<StrongNaming::StrongNameKeyLabel, StrongNaming::BaseStrongNameKey<>>, 
                             mpl::pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>> api_cartridges;
        };

        struct TestAssemblyMetadataApi
        {
            typedef boost::mpl::vector<TestAssemblyNameMetadataApi, IMetaDataImport2> external_api_types;
            typedef mpl::map<mpl::pair<AssemblyNameMetadataLabel, BaseAssemblyNameMetadata<TestAssemblyNameMetadataApi>>, 
                             mpl::pair<MetadataDispenserLabel, BaseTestMetadataDispenserProtoB8DF5A21<mpl::void_>>,
                             mpl::pair<IMetaDataImport2, IMetaDataImport2>> api_cartridges;
        };

        typedef BaseAssemblyMetadata<TestAssemblyMetadataApi> AssemblyMetadata;
        typedef AssemblyMetadata::metadata_dispenser_type MetadataDispenser;
        //typedef MetadataDispenser::metadata_info_type MetadataInfo;
        //typedef MetadataInfo::runtime_host_type RuntimeHost;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        SetupApis(asmPath, &pMetaDispApi, &pMetaImpApi);

        //RuntimeHost runtimeHost;
        //MetadataInfo metaInfo;
        //metaInfo.Init(runtimeHost);
        MetadataDispenser metaDisp;
        //metaDisp.Init(metaInfo);

        
        // Act
        AssemblyMetadata asmMeta;
        asmMeta.Init(metaDisp, *pMetaImpApi);

        typedef AssemblyMetadata::assembly_name_metadata_type AssemblyNameMetadata;
        AssemblyNameMetadata const *pAsmNameMeta = asmMeta.GetAssemblyName();
        std::wstring const &name = pAsmNameMeta->GetName();

        typedef AssemblyNameMetadata::strong_name_key_type StrongNameKey;
        StrongNameKey const *pSnKey = pAsmNameMeta->GetStrongNameKey();

        
        // Assert
        ASSERT_STREQ(L"System.Core", name.c_str());
        ASSERT_TRUE(pSnKey != NULL);

        //ASSERT_TRUE(pAsmNameMeta != NULL);
        //AssemblyNameMetadata const *pAsmNameMeta2 = asmMeta.GetName();
        //ASSERT_EQ(pAsmNameMeta, pAsmNameMeta2);
    }
}
