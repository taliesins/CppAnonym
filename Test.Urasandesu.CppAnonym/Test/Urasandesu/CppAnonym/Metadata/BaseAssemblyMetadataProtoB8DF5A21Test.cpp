#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultTypeMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoProto4236D495.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYPROTO4236D495_H
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyProto4236D495.h>
#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataInfoApiProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostProto07F03042.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H
//#include <Urasandesu/CppAnonym/Fusion/DefaultFusionInfoApiProto3CBCB74B.h>
//#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct RemoveConst 
    { 
        typedef T type;
    };

    template<class T>
    struct RemoveConst<const T *>
    {
        typedef T * type;
    };

    template<class T>
    struct RemoveConst<T * const>
    {
        typedef T * type;
    };

    template<class T>
    struct RemoveConst<const T &>
    {
        typedef T & type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    // NOTE: I made this class by reference to Boost.Any. 
    //       Boost.Any is permitted free of changes under Boost Software License, Version 1.0.
    //       The copyright statement is as below: 
    // 
    // Copyright Kevlin Henney, 2000, 2001, 2002. All rights reserved.
    //
    // Distributed under the Boost Software License, Version 1.0. (See
    // accompanying file LICENSE_1_0.txt or copy at
    // http://www.boost.org/LICENSE_1_0.txt)
    class AnyPointer
    {
    public:
        AnyPointer() : 
            m_pHolder(NULL)
        { }

        template<class PointerType>
        AnyPointer(PointerType p) : 
            m_pHolder(new PointerHolder<PointerType>(p))
        { }

        AnyPointer(AnyPointer const &other) : 
            m_pHolder(other.IsEmpty() ? NULL : other.m_pHolder->Clone())
        { }

        ~AnyPointer() 
        { 
            if (m_pHolder != NULL)
                delete m_pHolder;
        }

        inline bool IsEmpty() const { return m_pHolder == NULL; }

        template<class PointerType>
        inline bool Is() const 
        {
            return !IsEmpty() && 
                   typeid(typename PointerHolder<PointerType>::pointer_type) == m_pHolder->GetType();
        }
        
        inline AnyPointer &Swap(AnyPointer &other) 
        { 
            std::swap(m_pHolder, other.m_pHolder); 
            return *this; 
        }

        inline AnyPointer &operator =(AnyPointer &other)
        {
            other.Swap(*this);
            return *this;
        }

        template<class PointerType>
        inline AnyPointer &operator =(PointerType p)
        {
            AnyPointer(p).Swap(*this);
            return *this;
        }

        template<class PointerType>
        inline operator PointerType()
        {
            typedef typename PointerHolder<PointerType>::type HolderType;
            return Is<PointerType>() ? static_cast<HolderType *>(m_pHolder)->m_p : NULL;
        }

    private:
        struct Holder
        {
            virtual ~Holder() { }
            virtual std::type_info const &GetType() const = 0;
            virtual Holder *Clone() const = 0;
        };

        template<class PointerType>
        struct PointerHolder : Holder
        {
            BOOST_MPL_ASSERT((boost::is_pointer<PointerType>));
            typedef typename Traits::RemoveConst<PointerType>::type pointer_type;
            typedef PointerHolder<pointer_type> type;
            PointerHolder(pointer_type p) : m_p(p) { }
            virtual ~PointerHolder() { delete m_p; }
            virtual std::type_info const &GetType() const { return typeid(pointer_type); }            
            virtual Holder *Clone() const { return new PointerHolder(m_p); }            
            pointer_type m_p;
        };

        Holder *m_pHolder;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IMetadataDispenserApi { };
    struct DefaultMetadataDispenserApiProtoB8DF5A21 : IMetadataDispenserApi { };

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21
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

    //struct ITypeMetadataApi { };
    //struct IAssemblyMetadataApi { };

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
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi 
        {
            typedef INT metadata_dispenser_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        typedef BaseAssemblyMetadataProtoB8DF5A21<TestAssemblyMetadataApi> AssemblyMetadata;
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
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestTypeMetadataApi : 
            ITypeMetadataApi
        {
            typedef TestAssemblyMetadataApi parent_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> child_api_types;
        };

        struct TestAssemblyMetadataApi : 
            IAssemblyMetadataApi
        {
            typedef INT metadata_dispenser_api_type;
            typedef boost::mpl::vector<IMetaDataImport2, TestTypeMetadataApi> child_api_types;
        };

        typedef BaseAssemblyMetadataProtoB8DF5A21<TestAssemblyMetadataApi> AssemblyMetadata;
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
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        typedef AssemblyMetadataProtoB8DF5A21 AssemblyMetadata;
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
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestAssemblyMetadataApi;

        struct TestAssemblyNameMetadataApi : 
            IAssemblyNameMetadataApi
        {
            typedef TestAssemblyMetadataApi parent_api_type;
            typedef boost::mpl::vector<IMetaDataAssemblyImport> child_api_types;
        };

        struct TestAssemblyMetadataApi : 
            IAssemblyMetadataApi
        {
            typedef boost::mpl::vector<TestAssemblyNameMetadataApi, IMetaDataImport2> child_api_types;
        };

        typedef BaseAssemblyMetadataProtoB8DF5A21<TestAssemblyMetadataApi> AssemblyMetadata;
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
