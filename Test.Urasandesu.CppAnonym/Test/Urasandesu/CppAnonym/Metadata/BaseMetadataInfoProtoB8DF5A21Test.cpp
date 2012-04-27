#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

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


    //TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoProtoB8DF5A21Test, Test_02)
    //{
    //    namespace fs = boost::filesystem;
    //    using namespace Urasandesu::CppAnonym::Metadata;

    //    // Arrange
    //    struct TestMetadataInfoApi
    //    {
    //    };

    //    typedef BaseMetadataInfoProtoB8DF5A21<TestMetadataInfoApi> MetadataInfo;
    //    typedef MetadataInfo::runtime_host_type RuntimeHost;

    //    RuntimeHost runtimeHost;

    //    // Act
    //    MetadataInfo metaInfo;
    //    metaInfo.Init(runtimeHost);

    //    // Assert
    //    typedef MetadataInfo::metadata_dispenser_type MetadataDispenser;
    //    //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::this_type, boost::use_default>));
    //    //BOOST_MPL_ASSERT((boost::is_same<MetadataInfo::metadata_dispenser_api_type, boost::use_default>));
    //    boost::shared_ptr<MetadataDispenser const> pMetaDisp = metaInfo.CreateDispenser();
    //    ASSERT_FALSE(pMetaDisp.get() == NULL);
    //}
}
