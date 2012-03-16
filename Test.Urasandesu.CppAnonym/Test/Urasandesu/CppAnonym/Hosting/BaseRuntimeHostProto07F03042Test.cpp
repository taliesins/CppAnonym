#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

//#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
//#include <Urasandesu/CppAnonym/IHeapContent.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTHOSTINFOAPIPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/DefaultHostInfoApiProto07F03042.h>
//#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoProto07F03042.h>
//#endif
//
#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

//#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
//#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H
#include <Urasandesu/CppAnonym/Fusion/DefaultFusionInfoApiProto3CBCB74B.h>
#endif

//#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
//#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
//#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoProto3CBCB74B.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseRuntimeHostProto07F03042Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseRuntimeHostProto07F03042Test, Test_01)
    {
        namespace fs = boost::filesystem;
        
        typedef Urasandesu::CppAnonym::Hosting::RuntimeHostProto07F03042 RuntimeHost;
        
        RuntimeHost runtimeHost;
        std::wstring const &corVersion = runtimeHost.GetCORVersion();
        ASSERT_STREQ(L"v2.0.50727", corVersion.c_str());

        fs::path const &corSystemDirectoryPath = runtimeHost.GetCORSystemDirectoryPath();
        fs::path expected(L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\");
        ASSERT_TRUE(fs::equivalent(expected, corSystemDirectoryPath)) 
            << "Expected: " << expected.c_str() << ", Actual: " << corSystemDirectoryPath.c_str();
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseRuntimeHostProto07F03042Test, Test_02)
    {
        namespace fs = boost::filesystem;
        
        typedef Urasandesu::CppAnonym::Hosting::RuntimeHostProto07F03042 RuntimeHost;
        
        RuntimeHost runtimeHost;
        typedef RuntimeHost::fusion_info_type FusionInfo;
        FusionInfo const *pFuInfo = runtimeHost.GetInfo<FusionInfo>();
        ASSERT_FALSE(pFuInfo == NULL);

        FusionInfo const *pFuInfo2 = runtimeHost.GetInfo<FusionInfo>();
        ASSERT_EQ(pFuInfo, pFuInfo2);
    }
}
