#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_ApiStrategiesTest.*
namespace {

    namespace UCT {
        using namespace Urasandesu::CppAnonym::Traits;
    }   // namespace Detail

    struct DefaultHogedataInfoApi;

    template<
        class HogedataInfoApiType
    >
    class BaseHogedataInfo;

    struct IHogedataDispenserApi { };

    struct DefaultHogedataDispenserApi : 
        IHogedataDispenserApi
    {
        typedef DefaultHogedataInfoApi parent_api_type;
        typedef boost::mpl::vector<> child_api_types;
    };
    
    struct IHogedataInfoApi;

    template<
        class HogedataDispenserApiType = DefaultHogedataDispenserApi
    >
    class BaseHogedataDispenser
    {
    public:

        typedef typename UCT::ParentApiOrDefault<HogedataDispenserApiType, IHogedataInfoApi>::type hogedata_info_api_type;

        BaseHogedataInfo<hogedata_info_api_type> *GetInfo() const
        {
            return NULL;
        }
    };


    struct IHogedataInfoApi { };

    struct DefaultHogedataInfoApi : 
        IHogedataInfoApi
    {
        typedef boost::mpl::void_ parent_api_type;
        typedef boost::mpl::vector<DefaultHogedataDispenserApi> child_api_types;
    };

    template<
        class HogedataInfoApiType = DefaultHogedataInfoApi
    >
    class BaseHogedataInfo
    {
    public:
        
        typedef typename UCT::ChildApiOrDefault<HogedataInfoApiType, IHogedataDispenserApi>::type hogedata_dispenser_api_type;

        BaseHogedataDispenser<hogedata_dispenser_api_type> *GetDispenser() const
        {
            return NULL;
        }
    };


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseHogedataInfo<> HogedataInfo;
        HogedataInfo hogeInfo;

        hogeInfo.GetDispenser();
        BOOST_MPL_ASSERT((boost::is_same<HogedataInfo::hogedata_dispenser_api_type, DefaultHogedataDispenserApi>));

        typedef BaseHogedataInfo<INT> HogedataInfo2;
        HogedataInfo2 hogeInfo2;

        hogeInfo2.GetDispenser();
        BOOST_MPL_ASSERT((boost::is_same<HogedataInfo2::hogedata_dispenser_api_type, DefaultChildApi<INT, IHogedataDispenserApi>>));

        
        typedef BaseHogedataDispenser<> HogedataDispenser;
        HogedataDispenser hogeDisp;

        hogeDisp.GetInfo();
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_api_type, DefaultHogedataInfoApi>));

        typedef BaseHogedataDispenser<INT> HogedataDispenser2;
        HogedataDispenser2 hogeDisp2;
        hogeDisp2.GetInfo();
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser2::hogedata_info_api_type, DefaultParentApi<INT, IHogedataInfoApi>>));
    }
}
