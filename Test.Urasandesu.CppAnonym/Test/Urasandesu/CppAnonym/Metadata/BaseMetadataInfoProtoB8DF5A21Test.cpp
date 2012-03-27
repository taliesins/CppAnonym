#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOrDefault.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOrDefault.h>
#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataInfoApiProtoB8DF5A21.h>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoProtoB8DF5A21.h>
#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiProtoB8DF5A21.h>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

//#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
//#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
//#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
//#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyMetadataApiProtoB8DF5A21.h>
//#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IMetadataDispenserApi { };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseMetadataInfoProtoB8DF5A21Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataInfoApi
        {
        };

        typedef BaseMetadataInfoProtoB8DF5A21<TestMetadataInfoApi> MetadataInfo;
        typedef MetadataInfo::runtime_host_type RuntimeHost;

        RuntimeHost runtimeHost;

        // Act
        MetadataInfo metaInfo;
        metaInfo.Init(runtimeHost);

        // Assert
        typedef MetadataInfo::metadata_dispenser_type MetadataDispenser;
        //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::this_type, boost::use_default>));
        //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::metadata_dispenser_api_type, boost::use_default>));
        boost::shared_ptr<MetadataDispenser const> pMetaDisp = metaInfo.CreateDispenser();
        ASSERT_FALSE(pMetaDisp.get() == NULL);
    }
}
