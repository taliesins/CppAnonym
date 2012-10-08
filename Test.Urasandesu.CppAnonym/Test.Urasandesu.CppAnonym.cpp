// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
#endif

// Foward Declarations
namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    class TypeInfo
    {
    public:
        TypeInfo() : 
            m_pHolder(NULL)
        { }

        template<class Type>
        TypeInfo(boost::mpl::identity<Type> const &) : 
            m_pHolder(new TypeHolder<Type>())
        { }

        TypeInfo(TypeInfo const &other) : 
            m_pHolder(other.IsEmpty() ? NULL : other.m_pHolder->Clone())
        { }

        ~TypeInfo() 
        { 
            if (m_pHolder != NULL)
                delete m_pHolder;
        }

        inline bool IsEmpty() const { return m_pHolder == NULL; }

        template<class Type>
        inline bool Is() const 
        {
            return !IsEmpty() && 
                   typeid(typename TypeHolder<Type>::type) == m_pHolder->GetType();
        }

        inline std::string const &GetRawName() const
        {
            return IsEmpty() ? m_empty : m_pHolder->GetRawName();
        }
        
        inline TypeInfo &Swap(TypeInfo &other) 
        { 
            std::swap(m_pHolder, other.m_pHolder); 
            return *this; 
        }

        inline TypeInfo &operator =(TypeInfo &other)
        {
            other.Swap(*this);
            return *this;
        }

        template<class Type>
        inline TypeInfo &operator =(boost::mpl::identity<Type> const &id)
        {
            TypeInfo(id).Swap(*this);
            return *this;
        }

        inline bool operator ==(TypeInfo const &other) const
        {
            if (IsEmpty() && other.IsEmpty())
                return true;
            else if (IsEmpty() || other.IsEmpty())
                return false;
            else
                return m_pHolder->GetType() == other.m_pHolder->GetType();
        }

        inline bool operator !=(TypeInfo const &other) const
        {
            return !(*this == other);
        }

    private:
        struct Holder
        {
            virtual ~Holder() { }
            virtual std::type_info const &GetType() const = 0;
            virtual Holder *Clone() const = 0;
            virtual std::string const &GetRawName() const = 0;
        };

        template<class Type>
        struct TypeHolder : Holder
        {
            typedef Type type;
            typedef TypeHolder<type> this_type;
            virtual ~TypeHolder() { }
            virtual std::type_info const &GetType() const { return typeid(type); }            
            virtual Holder *Clone() const { return new TypeHolder<type>(); }            
            virtual std::string const &GetRawName() const
            {
                if (m_name.empty())
                    m_name = typeid(type).raw_name();
                return m_name;
            }

            mutable std::string m_name;
        };

        Holder *m_pHolder;
        std::string m_empty;
    };

    
    
    
    
    class TypeInfoHash : 
        Traits::HashComputable<TypeInfo>
    {
    public:
        result_type operator()(param_type v) const
        {
            return boost::hash_value(v.GetRawName());
        }
    };

    
    
    
    
    class TypeInfoEqualTo : 
        Traits::EqualityComparable<TypeInfo>
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct AssemblyMetadataGeneratorApiHolderLabel { };
    struct AssemblyMetadataGeneratorLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultAssemblyMetadataGeneratorApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class AssemblyMetadataGeneratorApiHolder = ApiHolders::DefaultAssemblyMetadataGeneratorApiHolder
    >    
    class BaseAssemblyMetadataGenerator;

    typedef BaseAssemblyMetadataGenerator<> AssemblyMetadataGenerator;





    typedef enum CorTokenTypeEx
    {
        // mdtBaseType(0x72000000) を下駄履き。
    } CorTokenTypeEx;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {


#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHost.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultFieldNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseFieldNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultILGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseILGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTPROPERTYNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultPropertyNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEPROPERTYNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BasePropertyNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTLOCALNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultLocalNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseLocalNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    //namespace Detail {

    //    using namespace boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

    //    struct DefaultAssemblyMetadataApiHolderImpl
    //    {
    //        typedef map<
    //            pair<MetadataDispenserLabel, MetadataDispenser>, 
    //            pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
    //            pair<ModuleMetadataLabel, ModuleMetadata>, 
    //            pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
    //            pair<TypeMetadataLabel, TypeMetadata>, 
    //            pair<TypeNameMetadataLabel, TypeNameMetadata>, 
    //            pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
    //            pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
    //            pair<IMetaDataImport2, IMetaDataImport2> 
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultAssemblyMetadataGeneratorApiHolder
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyMetadataGeneratorApiHolder
    >    
    class BaseAssemblyMetadataGenerator
    {
    public:
        void Save(std::wstring const &name, PortableExecutableKinds const &portableExecutableKind, ImageFileMachine const &imageFileMachine)
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, TypeInfo_Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;

        TypeInfo t1 = mpl::identity<int>();
        TypeInfo t2 = mpl::identity<int>();
        TypeInfo t3 = mpl::identity<double>();

        ASSERT_TRUE(t1 == t2);
        ASSERT_FALSE(t1 == t3);

        std::vector<TypeInfo> typeInfos;
        typeInfos.push_back(t1);
        typeInfos.push_back(t2);
        typeInfos.push_back(t3);

        TypeInfo t4 = mpl::identity<double>();
        std::vector<TypeInfo>::iterator result = std::find(typeInfos.begin(), typeInfos.end(), t4);
        ASSERT_FALSE(result == typeInfos.end());
        ASSERT_TRUE((*result).Is<double>());
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, StrongNaming_Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        //::_CrtSetBreakAlloc(5404);

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");

        StrongNameInfo const &snInfo = pRuntimeHost->Map<StrongNameInfo>();
        
        StrongNameKey const *pSnKey = NULL;
        pSnKey = snInfo.GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        std::vector<BYTE> const &publicKey = pSnKey->GetPublicKey();

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x19, 0xc4, 0x67, 0xdf, 0x70, 0xd1, 0xae, 0xf6, 
            0x96, 0x95, 0xf6, 0x8e, 0x65, 0xaf, 0x52, 0x46, 
            0x0b, 0x8e, 0x00, 0x94, 0x1f, 0x4a, 0x17, 0x5f, 
            0x4d, 0xf8, 0xd3, 0x70, 0x9f, 0x1a, 0x32, 0xd9, 
            0xf3, 0xff, 0xf6, 0xfd, 0x68, 0xb8, 0x79, 0xdc, 
            0x3d, 0xad, 0x60, 0x63, 0x2a, 0x9b, 0x6d, 0x9a, 
            0x5f, 0xc1, 0x9e, 0xf8, 0xb9, 0xd9, 0xae, 0x7a, 
            0xe9, 0xfe, 0x2a, 0xf2, 0x5e, 0x29, 0x02, 0x1b, 
            0xa2, 0x66, 0xad, 0x0b, 0x83, 0x7f, 0xc8, 0x22, 
            0x2f, 0xf5, 0x51, 0x55, 0x67, 0x68, 0xa1, 0x1b, 
            0xae, 0x1d, 0xe5, 0xf7, 0xca, 0xad, 0xf8, 0xc7, 
            0x78, 0x19, 0xfc, 0xfb, 0x8b, 0x3b, 0x73, 0x0b, 
            0x38, 0xe1, 0xeb, 0xcd, 0x68, 0x3d, 0x12, 0xdd, 
            0x87, 0x4f, 0x42, 0x8f, 0xbb, 0x0d, 0xb5, 0xd6, 
            0x92, 0xda, 0xfa, 0x66, 0xa3, 0xe3, 0x6a, 0x8b, 
            0x28, 0xb2, 0x36, 0xb8, 0xde, 0x56, 0x07, 0xda
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);

        ASSERT_EQ(148, publicKey.size());
        for (UINT i = 0; i < publicKey.size(); ++i)
            ASSERT_EQ(PUB_KEY_BLOB[PUB_KEY_BLOB_SIZE - publicKey.size() + i], publicKey[i]);
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, StrongNaming_Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");

        StrongNameInfo const &snInfo = pRuntimeHost->Map<StrongNameInfo>();
        
        StrongNameKey const *pSnKey = NULL;
        pSnKey = snInfo.GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        std::vector<BYTE> const &publicKeyToken = pSnKey->GetPublicKeyToken();

        BYTE const PUB_KEY_TOKEN[] = { 0xf3, 0xc5, 0xad, 0xb8, 0x52, 0x21, 0xac, 0x4f };

        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost != NULL);

        MetadataInfo const &metaInfo = pRuntimeHost->Map<MetadataInfo>();

        MetadataDispenser *pMetaDisp = metaInfo.CreateDispenser();
        ASSERT_TRUE(pMetaDisp != NULL);
        
        AssemblyMetadata const *pSystemCore = NULL;
        pSystemCore = pMetaDisp->LoadAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                              L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_TRUE(pSystemCore != NULL);
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());

        AssemblyMetadata const *pMSCorLib = NULL;
        pMSCorLib = pMetaDisp->LoadAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                            L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        ASSERT_TRUE(pMSCorLib != NULL);
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        ModuleMetadata const *pSystemCoreModule = NULL;
        pSystemCoreModule = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_TRUE(pSystemCoreModule != NULL);
        ASSERT_EQ(0x00000001, pSystemCoreModule->GetToken());

        ModuleMetadata const *pMSCorLibModule = NULL;
        pMSCorLibModule = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_TRUE(pMSCorLibModule != NULL);
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        TypeMetadata const *pVoid = pMSCorLibModule->GetType(L"System.Void");
        ASSERT_TRUE(pVoid != NULL);
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        TypeMetadata const *pObject = pMSCorLibModule->GetType(L"System.Object");
        ASSERT_TRUE(pObject != NULL);
        ASSERT_EQ(0x02000002, pObject->GetToken());
        
        TypeMetadata const *pIntPtr = pMSCorLibModule->GetType(L"System.IntPtr");
        ASSERT_TRUE(pIntPtr != NULL);
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        TypeMetadata const *pDateTime = pMSCorLibModule->GetType(L"System.DateTime");
        ASSERT_TRUE(pDateTime != NULL);
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        TypeMetadata const *pFunc1 = pSystemCoreModule->GetType(L"System.Func`1");
        ASSERT_TRUE(pFunc1 != NULL);
        ASSERT_TRUE(pFunc1->IsGenericType());
        ASSERT_TRUE(pFunc1->IsGenericTypeDefinition());
        {
            std::vector<TypeMetadata const *> const &genericArgs = pFunc1->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (UINT i = 0; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_TRUE(genericArgs[i]->IsGenericParameter());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1->GetToken());

        TypeMetadata const *pFunc1DateTime = NULL;
        {
            std::vector<TypeMetadata const *> genericArgs;
            genericArgs.push_back(pDateTime);
            pFunc1DateTime = pFunc1->MakeGenericType(genericArgs);
        }
        ASSERT_TRUE(pFunc1DateTime != NULL);
        ASSERT_TRUE(pFunc1DateTime->IsGenericType());
        ASSERT_FALSE(pFunc1DateTime->IsGenericTypeDefinition());
        {
            std::vector<TypeMetadata const *> const &genericArgs = pFunc1DateTime->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (UINT i = 0; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_FALSE(genericArgs[i]->IsGenericParameter());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1DateTime->GetToken());   // !! CAUTION: This is CORRECT !!

        MethodMetadata const *pFunc1DateTimector = NULL;
        {
            std::vector<TypeMetadata const *> params;
            params.push_back(pObject);
            params.push_back(pIntPtr);
            pFunc1DateTimector = pFunc1DateTime->GetMethod(L".ctor", CallingConventions::CC_HAS_THIS, *pVoid, params);
        }
        ASSERT_TRUE(pFunc1DateTimector != NULL);
        ASSERT_EQ(0x06000232, pFunc1DateTimector->GetToken());   // !! CAUTION: This is CORRECT !!

        MethodMetadata const *pget_UtcNow = NULL;
        {
            std::vector<TypeMetadata const *> params;
            pget_UtcNow = pDateTime->GetMethod(L"get_UtcNow", CallingConventions::CC_STANDARD, *pDateTime, params);
        }
        ASSERT_TRUE(pget_UtcNow != NULL);
        ASSERT_EQ(0x060002D3, pget_UtcNow->GetToken());

        MethodMetadata const *pToLocalTime = NULL;
        {
            std::vector<TypeMetadata const *> params;
            pToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, *pDateTime, params);
        }
        ASSERT_TRUE(pToLocalTime != NULL);
        ASSERT_EQ(0x060002E7, pToLocalTime->GetToken());




        StrongNameInfo const &snInfo = pRuntimeHost->Map<StrongNameInfo>();

        AssemblyNameMetadataGenerator *pMSCorLibPrigNameGen = NULL;
        pMSCorLibPrigNameGen = pMetaDisp->NewAssemblyNameGenerator(L"mscorlib.Prig");
        StrongNameKey const *pSnKey = NULL;
        pSnKey = snInfo.GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        pMSCorLibPrigNameGen->SetStrongNameKey(*pSnKey);
        ASSERT_TRUE(pMSCorLibPrigNameGen != NULL);
        ASSERT_STREQ(L"mscorlib.Prig", pMSCorLibPrigNameGen->GetName().c_str());
        ASSERT_TRUE(pMSCorLibPrigNameGen->GetStrongNameKey() != NULL);

        ModuleNameMetadataGenerator *pMSCorLibPrigNameModuleGen = NULL;
        pMSCorLibPrigNameModuleGen = pMSCorLibPrigNameGen->NewModuleNameGenerator(L"mscorlib.Prig.dll");
        ASSERT_TRUE(pMSCorLibPrigNameModuleGen != NULL);
        ASSERT_STREQ(L"mscorlib.Prig.dll", pMSCorLibPrigNameModuleGen->GetName().c_str());

        TypeNameMetadataGenerator *pPDateTimeNameGen = NULL;
        pPDateTimeNameGen = pMSCorLibPrigNameModuleGen->NewTypeNameGenerator(L"System.Prig.PDateTime",
                                                                             TypeAttributes::TA_PUBLIC | 
                                                                             TypeAttributes::TA_ABSTRACT | 
                                                                             TypeAttributes::TA_ANSI_CLASS | 
                                                                             TypeAttributes::TA_SEALED | 
                                                                             TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_TRUE(pPDateTimeNameGen != NULL);
        ASSERT_STREQ(L"System.Prig.PDateTime", pPDateTimeNameGen->GetName().c_str());
        ASSERT_TRUE((pPDateTimeNameGen->GetAttribute().Value() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_FALSE((pPDateTimeNameGen->GetAttribute().Value() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);

        TypeNameMetadataGenerator *pNowGetNameGen = NULL;
        pNowGetNameGen = pPDateTimeNameGen->NewNestedTypeNameGenerator(L"NowGet", 
                                                                       TypeAttributes::TA_ABSTRACT | 
                                                                       TypeAttributes::TA_ANSI_CLASS | 
                                                                       TypeAttributes::TA_SEALED | 
                                                                       TypeAttributes::TA_NESTED_PUBLIC | 
                                                                       TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_TRUE(pNowGetNameGen != NULL);
        ASSERT_STREQ(L"NowGet", pNowGetNameGen->GetName().c_str());
        ASSERT_TRUE((pNowGetNameGen->GetAttribute().Value() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_TRUE((pNowGetNameGen->GetAttribute().Value() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);
        
        FieldNameMetadataGenerator *pm_bodyNameGen = NULL;
        pm_bodyNameGen = pPDateTimeNameGen->NewFieldNameGenerator(L"m_body", 
                                                                  *pFunc1DateTime, 
                                                                  FieldAttributes::FA_PRIVATE | 
                                                                  FieldAttributes::FA_STATIC);
        ASSERT_TRUE(pm_bodyNameGen != NULL);
        ASSERT_STREQ(L"m_body", pm_bodyNameGen->GetName().c_str());
        ASSERT_TRUE(&pm_bodyNameGen->GetFieldType() == pFunc1DateTime);
        ASSERT_TRUE((pm_bodyNameGen->GetAttribute().Value() & FieldAttributes::FA_PRIVATE) == FieldAttributes::FA_PRIVATE);
        ASSERT_FALSE((pm_bodyNameGen->GetAttribute().Value() & FieldAttributes::FA_PUBLIC) == FieldAttributes::FA_PUBLIC);

        MethodNameMetadataGenerator *pget_BodyNameGen = NULL;
        pget_BodyNameGen = pPDateTimeNameGen->NewMethodNameGenerator(L"get_Body", 
                                                                     CallingConventions::CC_STANDARD, 
                                                                     *pFunc1DateTime, 
                                                                     std::vector<TypeMetadata const *>(), 
                                                                     MethodAttributes::MA_PUBLIC | 
                                                                     MethodAttributes::MA_HIDE_BY_SIG | 
                                                                     MethodAttributes::MA_SPECIAL_NAME | 
                                                                     MethodAttributes::MA_STATIC);
        ASSERT_TRUE(pget_BodyNameGen != NULL);
        ASSERT_STREQ(L"get_Body", pget_BodyNameGen->GetName().c_str());
        ASSERT_EQ(CallingConventions::CC_STANDARD, pget_BodyNameGen->GetCallingConvention().Value());
        ASSERT_TRUE(&pget_BodyNameGen->GetReturnType() == pFunc1DateTime);
        ASSERT_EQ(0, pget_BodyNameGen->GetParameterTypes().size());
        ASSERT_TRUE((pget_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pget_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        std::vector<TypeMetadata const *> set_BodyParams;
        set_BodyParams.push_back(pFunc1DateTime);
        MethodNameMetadataGenerator *pset_BodyNameGen = NULL;
        pset_BodyNameGen = pPDateTimeNameGen->NewMethodNameGenerator(L"set_Body",
                                                                     CallingConventions::CC_STANDARD, 
                                                                     *pVoid, 
                                                                     set_BodyParams, 
                                                                     MethodAttributes::MA_PUBLIC | 
                                                                     MethodAttributes::MA_HIDE_BY_SIG | 
                                                                     MethodAttributes::MA_SPECIAL_NAME | 
                                                                     MethodAttributes::MA_STATIC);
        ASSERT_TRUE(pset_BodyNameGen != NULL);
        ASSERT_STREQ(L"set_Body", pset_BodyNameGen->GetName().c_str());
        ASSERT_EQ(CallingConventions::CC_STANDARD, pset_BodyNameGen->GetCallingConvention().Value());
        ASSERT_TRUE(&pset_BodyNameGen->GetReturnType() == pVoid);
        ASSERT_EQ(1, pset_BodyNameGen->GetParameterTypes().size());
        ASSERT_TRUE((pset_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pset_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        PropertyNameMetadataGenerator *pBodyNameGen = NULL;
        pBodyNameGen = pPDateTimeNameGen->NewPropertyNameGenerator(L"Body", 
                                                                   *pFunc1DateTime, 
                                                                   std::vector<TypeMetadata const *>(), 
                                                                   PropertyAttributes::PA_NONE);
        pBodyNameGen->SetGetMethod(*pget_BodyNameGen);
        pBodyNameGen->SetSetMethod(*pset_BodyNameGen);
        ASSERT_TRUE(pBodyNameGen != NULL);
        ASSERT_STREQ(L"Body", pBodyNameGen->GetName().c_str());
        ASSERT_TRUE(&pBodyNameGen->GetPropertyType() == pFunc1DateTime);
        ASSERT_EQ(0, pBodyNameGen->GetParameterTypes().size());
        ASSERT_TRUE((pBodyNameGen->GetAttribute().Value() & PropertyAttributes::PA_NONE) == PropertyAttributes::PA_NONE);
        ASSERT_FALSE((pBodyNameGen->GetAttribute().Value() & PropertyAttributes::PA_SPECIAL_NAME) == PropertyAttributes::PA_SPECIAL_NAME);
        ASSERT_TRUE(pBodyNameGen->GetGetMethod() == pget_BodyNameGen);
        ASSERT_TRUE(pBodyNameGen->GetSetMethod() == pset_BodyNameGen);

        MethodNameMetadataGenerator *pNowGetcctorNameGen = NULL;
        pNowGetcctorNameGen = pNowGetNameGen->NewMethodNameGenerator(L".cctor", 
                                                                     CallingConventions::CC_STANDARD, 
                                                                     *pVoid, 
                                                                     std::vector<TypeMetadata const *>(),
                                                                     MethodAttributes::MA_PUBLIC | 
                                                                     MethodAttributes::MA_HIDE_BY_SIG | 
                                                                     MethodAttributes::MA_SPECIAL_NAME | 
                                                                     MethodAttributes::MA_STATIC);
        
        MethodNameMetadataGenerator *pInitializeget_BodyNameGen = NULL;
        pInitializeget_BodyNameGen = pNowGetNameGen->NewMethodNameGenerator(L"Initializeget_Body", 
                                                                            CallingConventions::CC_STANDARD, 
                                                                            *pDateTime, 
                                                                            std::vector<TypeMetadata const *>(), 
                                                                            MethodAttributes::MA_PUBLIC | 
                                                                            MethodAttributes::MA_HIDE_BY_SIG | 
                                                                            MethodAttributes::MA_SPECIAL_NAME | 
                                                                            MethodAttributes::MA_STATIC);

        {
            ILGenerator &gen = pget_BodyNameGen->GetILGenerator();
            gen.Emit(OpCodes::Ldsfld, *pm_bodyNameGen);
            gen.Emit(OpCodes::Ret);
            {
                std::vector<Instruction const *> const &insts = gen.GetInstructions();
                ASSERT_EQ(2, insts.size());
                for (UINT i = 0; i < insts.size(); ++i)
                {
                    OpCode const &op = insts[i]->GetOpCode();
                    boost::any const &operand = insts[i]->GetOprand();
                    switch (i)
                    {
                        case 0:
                            ASSERT_EQ(&OpCodes::Ldsfld, &op);
                            ASSERT_EQ(pm_bodyNameGen, boost::any_cast<FieldNameMetadataGenerator const *>(operand));
                            break;
                        case 1:
                            ASSERT_EQ(&OpCodes::Ret, &op);
                            ASSERT_TRUE(operand.empty());
                            break;
                        default:
                            FAIL() << "We shouldn't get here!!";
                    }
                }
            }
        }
        {
            ILGenerator &gen = pset_BodyNameGen->GetILGenerator();
            gen.Emit(OpCodes::Ldarg_0);
            gen.Emit(OpCodes::Stsfld, *pm_bodyNameGen);
            gen.Emit(OpCodes::Ret);
        }
        {
            ILGenerator &gen = pNowGetcctorNameGen->GetILGenerator();
            gen.Emit(OpCodes::Ldnull);
            gen.Emit(OpCodes::Ldftn, *pInitializeget_BodyNameGen);
            gen.Emit(OpCodes::Newobj, *pFunc1DateTimector);
            gen.Emit(OpCodes::Stsfld, *pm_bodyNameGen);
            gen.Emit(OpCodes::Ret);
        }
        {
            ILGenerator &gen = pInitializeget_BodyNameGen->GetILGenerator();
            LocalNameMetadataGenerator *p1 = NULL; 
            p1 = gen.NewLocalNameMetadataGenerator(*pDateTime);
            gen.Emit(OpCodes::Call, *pget_UtcNow);
            gen.Emit(OpCodes::Stloc_0);
            gen.Emit(OpCodes::Ldloca, 0x00);
            gen.Emit(OpCodes::Call, *pToLocalTime);
            gen.Emit(OpCodes::Ret);
        }

        AssemblyMetadataGenerator *pMSCorLibPrigGen = NULL;
        pMSCorLibPrigGen = pMSCorLibPrigNameGen->Resolve();
        pMSCorLibPrigGen->Save(L"mscorlib.Prig.dll", PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
    }
}
