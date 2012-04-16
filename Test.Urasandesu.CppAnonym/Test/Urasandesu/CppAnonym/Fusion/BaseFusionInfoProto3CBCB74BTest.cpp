﻿#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoProto3CBCB74B.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042
    {
    public:
        boost::filesystem::path const &GetCORSystemDirectoryPath() const
        {
            return m_corSystemDirectoryPath;
        }

        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Fusion_BaseFusionInfoProto3CBCB74BTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Fusion_BaseFusionInfoProto3CBCB74BTest, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Fusion;

        // Arrange
        struct TestFusionInfoApi
        {
            typedef INT runtime_host_api_type;
        };
        typedef BaseFusionInfoProto3CBCB74B<TestFusionInfoApi> FusionInfo;
        typedef FusionInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;
        runtimeHost.m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";


        // Act
        FusionInfo fuInfo;
        fuInfo.Init(runtimeHost);

        std::wstring assemblyName(L"System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        boost::shared_ptr<AssemblyInfo> pAsmInfo = fuInfo.QueryAssemblyInfo(AssemblyQueryTypes::AQT_GET_SIZE, assemblyName);


        // Assert        
        fs::path expected(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ASSERT_TRUE(fs::equivalent(expected, pAsmInfo->GetAssemblyPath()));
        ASSERT_EQ(652, pAsmInfo->GetAssemblySizeInKB());
    }

    TEST(Urasandesu_CppAnonym_Fusion_BaseFusionInfoProto3CBCB74BTest, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Fusion;

        // Arrange
        struct TestFusionInfoApi
        {
            typedef INT runtime_host_api_type;
        };
        typedef BaseFusionInfoProto3CBCB74B<TestFusionInfoApi> FusionInfo;
        typedef FusionInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;
        runtimeHost.m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";


        // Act
        FusionInfo fuInfo;
        fuInfo.Init(runtimeHost);

        std::wstring assemblyName(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        boost::shared_ptr<AssemblyInfo> pAsmInfo = fuInfo.QueryAssemblyInfo(AssemblyQueryTypes::AQT_GET_SIZE, assemblyName);


        // Assert        
        fs::path expected(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
        ASSERT_TRUE(fs::equivalent(expected, pAsmInfo->GetAssemblyPath()))
            << "Expected: " << expected.c_str() << ", Actual: " << pAsmInfo->GetAssemblyPath().c_str();
        ASSERT_EQ(5464, pAsmInfo->GetAssemblySizeInKB());
    }
}