#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoProto4236D495.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

//#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
//#include <Urasandesu/CppAnonym/HeapProvider.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
//#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseStrongNameInfoProto4236D495.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataProtoB8DF5A21.h>
//#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

//namespace Urasandesu { namespace CppAnonym { namespace Metadata {
//
//    template<
//        class MetadataInfoApiType
//    >    
//    class BaseMetadataInfoProtoB8DF5A21
//    {
//    };
//
//}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {
//
//namespace Urasandesu { namespace CppAnonym { namespace Metadata {
//
//    struct IAssemblyMetadataApi { };
//    struct IMetadataDispenserApi { };
//
//}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseStrongNameInfoProto4236D495Test.*
namespace {

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

    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameInfoProto4236D495Test, Test_01)
    {
        typedef Urasandesu::CppAnonym::StrongNaming::StrongNameInfoProto4236D495 StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x6f, 0x4a, 0x1b, 0x2b, 0x8c, 0xa3, 0xfc, 0x55, 
            0x67, 0xc7, 0x60, 0x45, 0xb7, 0x32, 0x0a, 0x45, 
            0xc1, 0x80, 0x35, 0xf5, 0x10, 0xca, 0x4f, 0x2f, 
            0xb4, 0x79, 0x64, 0x83, 0x06, 0xa0, 0x7a, 0x29, 
            0xd2, 0xd8, 0xf0, 0x5a, 0x70, 0xeb, 0xbb, 0xd0, 
            0x32, 0xbb, 0x09, 0x87, 0x99, 0xc9, 0x22, 0x65, 
            0x4e, 0xab, 0xeb, 0xaf, 0x7b, 0x84, 0xd3, 0x92, 
            0x7c, 0x23, 0x5e, 0x6d, 0xe5, 0x4a, 0x3b, 0xaf, 
            0xba, 0x5a, 0x2f, 0x27, 0x65, 0x3a, 0xf0, 0x52, 
            0xf0, 0x57, 0xf0, 0x06, 0x5a, 0xc7, 0x71, 0xd7, 
            0x22, 0x12, 0x7b, 0xbb, 0xa1, 0xcd, 0x01, 0xc8, 
            0xa6, 0x65, 0xfd, 0x2f, 0xf0, 0xdd, 0xa3, 0x61, 
            0x08, 0x61, 0x28, 0x9a, 0xe4, 0xd0, 0x5c, 0xcc, 
            0xdd, 0x6d, 0x35, 0xb6, 0xe6, 0xab, 0x46, 0xb8, 
            0xa6, 0xf8, 0xd1, 0x65, 0xad, 0x7f, 0x3f, 0xca, 
            0xcc, 0x5f, 0xdf, 0x62, 0x4b, 0xd7, 0x36, 0x98
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);

        typedef StrongNameInfo::strong_name_key_type StrongNameKey;
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        boost::shared_ptr<StrongNameKey const> pSnKey = snInfo.CreateKey(pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKey = pSnKey->GetPublicKey();
        ASSERT_EQ(148, publicKey.size());
        for (UINT i = 0; i < publicKey.size(); ++i)
            ASSERT_EQ(PUB_KEY_BLOB[PUB_KEY_BLOB_SIZE - publicKey.size() + i], publicKey[i]);
    }


    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameInfoProto4236D495Test, Test_02)
    {
        typedef Urasandesu::CppAnonym::StrongNaming::StrongNameInfoProto4236D495 StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x6f, 0x4a, 0x1b, 0x2b, 0x8c, 0xa3, 0xfc, 0x55, 
            0x67, 0xc7, 0x60, 0x45, 0xb7, 0x32, 0x0a, 0x45, 
            0xc1, 0x80, 0x35, 0xf5, 0x10, 0xca, 0x4f, 0x2f, 
            0xb4, 0x79, 0x64, 0x83, 0x06, 0xa0, 0x7a, 0x29, 
            0xd2, 0xd8, 0xf0, 0x5a, 0x70, 0xeb, 0xbb, 0xd0, 
            0x32, 0xbb, 0x09, 0x87, 0x99, 0xc9, 0x22, 0x65, 
            0x4e, 0xab, 0xeb, 0xaf, 0x7b, 0x84, 0xd3, 0x92, 
            0x7c, 0x23, 0x5e, 0x6d, 0xe5, 0x4a, 0x3b, 0xaf, 
            0xba, 0x5a, 0x2f, 0x27, 0x65, 0x3a, 0xf0, 0x52, 
            0xf0, 0x57, 0xf0, 0x06, 0x5a, 0xc7, 0x71, 0xd7, 
            0x22, 0x12, 0x7b, 0xbb, 0xa1, 0xcd, 0x01, 0xc8, 
            0xa6, 0x65, 0xfd, 0x2f, 0xf0, 0xdd, 0xa3, 0x61, 
            0x08, 0x61, 0x28, 0x9a, 0xe4, 0xd0, 0x5c, 0xcc, 
            0xdd, 0x6d, 0x35, 0xb6, 0xe6, 0xab, 0x46, 0xb8, 
            0xa6, 0xf8, 0xd1, 0x65, 0xad, 0x7f, 0x3f, 0xca, 
            0xcc, 0x5f, 0xdf, 0x62, 0x4b, 0xd7, 0x36, 0x98
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);
        BYTE const PUB_KEY_TOKEN[] = { 0xce, 0x9e, 0x95, 0xb0, 0x43, 0x34, 0xd5, 0xfb };

        typedef StrongNameInfo::strong_name_key_type StrongNameKey;
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        boost::shared_ptr<StrongNameKey const> pSnKey = snInfo.CreateKey(pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKeyToken = pSnKey->GetPublicKeyToken();
        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }


    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameInfoProto4236D495Test, Test_03)
    {
        typedef Urasandesu::CppAnonym::StrongNaming::StrongNameInfoProto4236D495 StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);
        BYTE const PUB_KEY_TOKEN[] = { 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89 };

        typedef StrongNameInfo::strong_name_key_type StrongNameKey;
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        boost::shared_ptr<StrongNameKey const> pSnKey = snInfo.CreateKey(pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKeyToken = pSnKey->GetPublicKeyToken();
        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }


    TEST(Urasandesu_CppAnonym_Hosting_BaseStrongNameInfoProto4236D495Test, Test_04)
    {
#if 0
        typedef Urasandesu::CppAnonym::StrongNaming::StrongNameInfoProto4236D495 StrongNameInfo;
        StrongNameInfo snInfo;

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);
        BYTE const PUB_KEY_TOKEN[] = { 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89 };

        typedef StrongNameInfo::strong_name_key_type StrongNameKey;
        PublicKeyBlob const *pPubKeyBlob = reinterpret_cast<PublicKeyBlob const *>(PUB_KEY_BLOB);
        boost::shared_ptr<StrongNameKey const> pSnKey = snInfo.CreateKey(pPubKeyBlob, PUB_KEY_BLOB_SIZE);
        std::vector<BYTE> const &publicKeyToken = pSnKey->GetPublicKeyToken();
        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
#endif

        // TODO: mscorlib の場合はキャッシュから取得されてるみたい。もう少し別のものも見てみる！
        // なるほど。MS が作ってる Assembly は全部そうか。
#if 1
        namespace fs = boost::filesystem;

        fs::path asmPath(L"C:\\Users\\Akira\\Prig\\Debug\\Urasandesu.NAnonym.dll");
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

        for (BYTE const *i = reinterpret_cast<BYTE const *>(pPubKey), *i_end = i + pubKeySize; i != i_end; ++i)
        {
            std::cout << boost::format("%|1$02X|") % static_cast<INT>(*i);
        }
        std::cout << std::endl;
#endif
    }
}
