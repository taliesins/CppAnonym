﻿#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTHOSTINFOAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultHostInfoApiProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseHostInfoProto07F03042Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseHostInfoProto07F03042Test, Test_01)
    {
        typedef Urasandesu::CppAnonym::Hosting::HostInfoProto07F03042 HostInfo;
        typedef HostInfo::runtime_host_type RuntimeHost;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");
        RuntimeHost const *pRuntimeHost2 = hostInfo.GetRuntime(L"v2.0.50727");
        ASSERT_EQ(pRuntimeHost, pRuntimeHost2); 
    }
}
