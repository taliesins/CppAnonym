// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

// foward declarations
namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

}}} // namespace Urasandesu { namespace CppAnonym { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#ifndef URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDER_H
#include <Urasandesu/CppAnonym/ApiHolders/DefaultCppAnonymStorageApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

}}} // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HPP
#include <Urasandesu/CppAnonym/BaseCppAnonymStorage.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPI_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHost.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {


// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test3.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test3, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        HostInfo const *pHostInfo = HostInfo::CreateHost();
        ASSERT_TRUE(pHostInfo != NULL);

        RuntimeHost const *pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost != NULL);

        MetadataInfo const *pMetaInfo = pRuntimeHost->Map<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo != NULL);

        MetadataDispenser *pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaDisp != NULL);
    }


}
