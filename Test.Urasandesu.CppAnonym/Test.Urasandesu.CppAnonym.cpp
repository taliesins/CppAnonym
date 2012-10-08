// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

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

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    //CPPANONYM_TEST(Urasandesu_CppAnonym_Test, Test_03)
    //{
    //    typedef std::vector<WCHAR, Urasandesu::CppAnonym::Utilities::StackAllocator<WCHAR> > WStrVector;
    //    WStrVector wstrVec(10);

    //    WCHAR *pstr = &wstrVec[0];
    //    ::swprintf_s(pstr, 10, L"aiueo");
    //    //typedef boost::pool<Urasandesu::CppAnonym::Utilities::StackAllocator<WCHAR> > WStrPool;
    //    //WStrPool wstrPool(sizeof(WCHAR));

    //    //WCHAR *pstr = reinterpret_cast<WCHAR *>(wstrPool.ordered_malloc(10));
    //    //::ZeroMemory(pstr, sizeof(WCHAR) * 10);
    //    //::swprintf_s(pstr, sizeof(WCHAR) * 10, L"aiueo");

    //    ASSERT_STREQ(L"aiueo", pstr);
    //}

    template<class T>
    struct Extract;

    template<template<class>class T, class U>
    struct Extract<T<U>>
    {
        typedef U type;
    };

    struct IntPtrHash : 
        Urasandesu::CppAnonym::Traits::HashComputable<int const *>
    {
        result_type operator()(param_type v) const
        {
            return *v;
        }
    };

    struct IntPtrEqualTo : 
        Urasandesu::CppAnonym::Traits::EqualityComparable<int const *>
    {
        inline result_type operator()(param_type x, param_type y) const
        {
            return *x == *y;
        }
    };

    //CPPANONYM_TEST(Urasandesu_CppAnonym_Test, Test_02)
    //{
    //    typedef boost::unordered_map<int const *, int, IntPtrHash, IntPtrEqualTo> IntPtrMap;
    //    IntPtrMap map;

    //    int i1 = 10;
    //    int i2 = 10;
    //    int i3 = 20;

    //    map[&i1] = i1;
    //    map[&i2] = i2;
    //    map[&i3] = i3;

    //    typedef IntPtrMap::iterator Iterator;
    //    {
    //        Iterator i = map.find(&i1);
    //        ASSERT_EQ((*i).first, &i1);
    //        ASSERT_EQ((*i).second, i2);
    //    }

    //    {
    //        Iterator i = map.find(&i2);
    //        ASSERT_EQ((*i).first, &i1);
    //        ASSERT_EQ((*i).second, i2);
    //    }

    //    {
    //        Iterator i = map.find(&i3);
    //        ASSERT_EQ((*i).first, &i3);
    //        ASSERT_EQ((*i).second, i3);
    //    }
    //    
    //    //// const * で取っておくのが良さそ
    //    //ASSERT_TRUE(IntPtrEqualTo()(&i1, &i2));
    //    //ASSERT_FALSE(IntPtrEqualTo()(&i2, &i3));
    //    //ASSERT_FALSE(IntPtrEqualTo()(&i1, &i3));
    //}

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost != NULL);

        MetadataInfo const *pMetaInfo = pRuntimeHost->GetInfo<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo != NULL);

        MetadataDispenser *pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaInfo != NULL);
        
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

        TypeMetadata const *pVoid = pMSCorLib->GetType(L"System.Void");
        ASSERT_TRUE(pVoid != NULL);
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        TypeMetadata const *pObject = pMSCorLib->GetType(L"System.Object");
        ASSERT_TRUE(pObject != NULL);
        ASSERT_EQ(0x02000002, pObject->GetToken());
        
        TypeMetadata const *pIntPtr = pMSCorLib->GetType(L"System.IntPtr");
        ASSERT_TRUE(pIntPtr != NULL);
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        TypeMetadata const *pDateTime = pMSCorLib->GetType(L"System.DateTime");
        ASSERT_TRUE(pDateTime != NULL);
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        TypeMetadata const *pFunc1 = pSystemCore->GetType(L"System.Func`1");
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
                        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
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
                        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
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
#if 0        

        MethodMetadata const *pToLocalTime = NULL;
        {
            std::vector<TypeMetadata const *> params;
            pToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, pDateTime, params);
        }




        boost::shared_ptr<AssemblyNameMetadata> pMSCorlibPrigAsmName = make_shared<AssemblyNameMetadata>();
        pMSCorlibPrigAsmName->SetName(L"mscorlib.Prig");
        boost::shared_ptr<AssemblyMetadata> pMSCorlibPrig = pMetaDisp->DefineAssembly(*pMSCorlibPrigAsmName);
        boost::shared_ptr<ModuleMetadata> pMSCorlibPrigDll = pMSCorlibPrig->DefineModule(L"mscorlib.Prig", L"mscorlib.Prig.dll");
        boost::shared_ptr<TypeMetadata> pPDateTime = pMSCorlibPrigDll->DefineType(L"System.Prig.PDateTime", 
                                                                                  TypeAttributes::TA_PUBLIC | 
                                                                                  TypeAttributes::TA_ABSTRACT | 
                                                                                  TypeAttributes::TA_ANSI_CLASS | 
                                                                                  TypeAttributes::TA_SEALED | 
                                                                                  TypeAttributes::TA_BEFORE_FIELD_INIT);
        boost::shared_ptr<TypeMetadata> pNowGet = pPDateTime->DefineNestedType(L"NowGet", 
                                                                               TypeAttributes::TA_ABSTRACT | 
                                                                               TypeAttributes::TA_ANSI_CLASS | 
                                                                               TypeAttributes::TA_SEALED | 
                                                                               TypeAttributes::TA_NESTED_PUBLIC | 
                                                                               TypeAttributes::TA_BEFORE_FIELD_INIT);
        boost::shared_ptr<FieldMetadata> pm_body = pPDateTime->DefineField(L"m_body", 
                                                                           *pFunc1DateTime, 
                                                                           FieldAttributes::FA_PRIVATE | 
                                                                           FieldAttributes::FA_STATIC);
        boost::shared_ptr<MethodMetadata> pget_Body = pPDateTime->DefineMethod(L"get_Body", 
                                                                               MethodAttributes::MA_PUBLIC | 
                                                                               MethodAttributes::MA_HIDE_BY_SIG | 
                                                                               MethodAttributes::MA_SPECIAL_NAME | 
                                                                               MethodAttributes::MA_STATIC, 
                                                                               CallingConventions::CA_STANDARD, 
                                                                               *pFunc1DateTime, 
                                                                               std::vector<TypeMetadata const *>());
        std::vector<TypeMetadata const *> set_BodyParams;
        set_BodyParams.push_back(pFunc1DateTime);
        boost::shared_ptr<MethodMetadata> pset_Body = pPDateTime->DefineMethod(L"set_Body", 
                                                                               MethodAttributes::MA_PUBLIC | 
                                                                               MethodAttributes::MA_HIDE_BY_SIG | 
                                                                               MethodAttributes::MA_SPECIAL_NAME | 
                                                                               MethodAttributes::MA_STATIC, 
                                                                               CallingConventions::CA_STANDARD, 
                                                                               *pVoid, 
                                                                               set_BodyParams);
        boost::shared_ptr<PropertyMetadata> pBody = pPDateTime->DefineProperty(L"Body", 
                                                                               PropertyAttributes::PA_NONE, 
                                                                               *pFunc1DateTime, 
                                                                               std::vector<TypeMetadata const *>());
        pBody->SetGetMethod(*pget_Body);
        pBody->SetSetMethod(*pset_Body);
        boost::shared_ptr<MethodMetadata> pNowGetcctor = pNowGet->DefineMethod(L".cctor", 
                                                                               MethodAttributes::MA_PUBLIC | 
                                                                               MethodAttributes::MA_HIDE_BY_SIG | 
                                                                               MethodAttributes::MA_SPECIAL_NAME | 
                                                                               MethodAttributes::MA_STATIC, 
                                                                               CallingConventions::CA_STANDARD, 
                                                                               *pVoid, 
                                                                               std::vector<TypeMetadata const *>());
        boost::shared_ptr<MethodMetadata> pInitializeget_Body = pNowGet->DefineMethod(L"Initializeget_Body", 
                                                                                      MethodAttributes::MA_PUBLIC | 
                                                                                      MethodAttributes::MA_HIDE_BY_SIG | 
                                                                                      MethodAttributes::MA_SPECIAL_NAME | 
                                                                                      MethodAttributes::MA_STATIC, 
                                                                                      CallingConventions::CA_STANDARD, 
                                                                                      *pDateTime, 
                                                                                      std::vector<TypeMetadata const *>());
        {
            ILGenerator *pGen = pget_Body->GetILGenerator();
            pGen->Emit(OpCodes::Ldsfld, *pm_body);
            pGen->Emit(OpCodes::Ret);
        }
        {
            ILGenerator *pGen = pset_Body->GetILGenerator();
            pGen->Emit(OpCodes::Ldarg_0);
            pGen->Emit(OpCodes::Stsfld, *pm_body);
            pGen->Emit(OpCodes::Ret);
        }
        {
            ILGenerator *pGen = pNowGetcctor->GetILGenerator();
            pGen->Emit(OpCodes::Ldnull);
            pGen->Emit(OpCodes::Ldftn, *pInitializeget_Body);
            pGen->Emit(OpCodes::Newobj, *pFunc1DateTimector);
            pGen->Emit(OpCodes::Stsfld, *pm_body);
            pGen->Emit(OpCodes::Ret);
        }
        {
            ILGenerator *pGen = pInitializeget_Body->GetILGenerator();
            pGen->DeclareLocal(*pDateTime);
            pGen->Emit(OpCodes::Call, *pget_UtcNow);
            pGen->Emit(OpCodes::Stloc_0);
            pGen->Emit(OpCodes::Ldloca, 0x00);
            pGen->Emit(OpCodes::Call, *pToLocalTime);
            pGen->Emit(OpCodes::Ret);
        }

        pMSCorlibPrig->Save(L"mscorlib.Prig.dll", PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
#endif
    }
}
