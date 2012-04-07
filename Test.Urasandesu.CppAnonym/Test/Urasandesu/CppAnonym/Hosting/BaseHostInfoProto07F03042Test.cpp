#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTHOSTINFOAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultHostInfoApiProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostProto07F03042.h>
#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataInfoApiProtoB8DF5A21.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H
//#include <Urasandesu/CppAnonym/Fusion/DefaultFusionInfoApiProto3CBCB74B.h>
//#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct DefaultStrongNameInfoApiProto4236D495 { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataInfoApiProtoB8DF5A21 { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct DefaultFusionInfoApiProto3CBCB74B { };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

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
