#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiHolder
    >
    class BaseTestRuntimeHostProto07F03042
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseMetadataInfoTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoTest, Test_01)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestMetadataInfoApi;

        struct TestMetadataDispenserApi
        {
            typedef mpl::map<mpl::pair<MetadataInfoLabel, BaseMetadataInfo<TestMetadataInfoApi>>> api_cartridges;
        };

        struct TestMetadataInfoApi
        {
            typedef mpl::map<mpl::pair<Hosting::RuntimeHostLabel, Hosting::BaseTestRuntimeHostProto07F03042<mpl::void_>>, 
                             mpl::pair<MetadataDispenserLabel, BaseMetadataDispenser<TestMetadataDispenserApi>>> api_cartridges;
        };

        typedef BaseMetadataInfo<TestMetadataInfoApi> MetadataInfo;
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


    //TEST(Urasandesu_CppAnonym_Hosting_BaseMetadataInfoTest, Test_02)
    //{
    //    namespace fs = boost::filesystem;
    //    using namespace Urasandesu::CppAnonym::Metadata;

    //    // Arrange
    //    struct TestMetadataInfoApi
    //    {
    //    };

    //    typedef BaseMetadataInfo<TestMetadataInfoApi> MetadataInfo;
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
