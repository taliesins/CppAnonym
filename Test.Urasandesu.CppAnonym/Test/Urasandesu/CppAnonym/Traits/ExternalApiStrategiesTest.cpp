#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_ApiStrategiesTest.*
namespace {

    namespace UCT {
        using namespace Urasandesu::CppAnonym::Traits;
    }   // namespace UCT

#if 0
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
#endif


    struct IHogedataInfoApi;
    
    struct DefaultHogedataInfoApi;

    template<
        class HogedataInfoApiType
    >
    class BaseHogedataInfo;

    struct IAssemblyHogedataApi { };

    struct DefaultAssemblyHogedataApi : 
        IAssemblyHogedataApi
    {
        typedef boost::mpl::vector<DefaultHogedataInfoApi> external_api_types;
    };

    template<
        class AssemblyHogedataApiType = DefaultAssemblyHogedataApi
    >
    class BaseAssemblyHogedata
    {
    public:
        
        typedef typename UCT::ExternalApiOrDefault<AssemblyHogedataApiType, IAssemblyHogedataApi, IHogedataInfoApi>::type hogedata_info_api_type;
        typedef BaseHogedataInfo<hogedata_info_api_type> hogedata_info_type;

        hogedata_info_type *GetInfo() const
        {
            return NULL;
        }
    };

    
    
    struct IHogedataDispenserApi { };

    struct DefaultHogedataDispenserApi : 
        IHogedataDispenserApi
    {
        typedef boost::mpl::vector<DefaultHogedataInfoApi, DefaultAssemblyHogedataApi> external_api_types;
    };
    
    template<
        class HogedataDispenserApiType = DefaultHogedataDispenserApi
    >
    class BaseHogedataDispenser
    {
    public:
        typedef typename UCT::ExternalApiOrDefault<HogedataDispenserApiType, IHogedataDispenserApi, IHogedataInfoApi>::type hogedata_info_api_type;
        typedef BaseHogedataInfo<hogedata_info_api_type> hogedata_info_type;

        typedef typename UCT::ExternalApiOrDefault<HogedataDispenserApiType, IHogedataDispenserApi, IAssemblyHogedataApi>::type assembly_hogedata_api_type;
        typedef BaseAssemblyHogedata<assembly_hogedata_api_type> assembly_hogedata_type;

        hogedata_info_type *GetInfo() const
        {
            return NULL;
        }

        assembly_hogedata_type *GetAssembly() const
        {
            return NULL;
        }
    };



    struct IHogedataInfoApi { };

    struct DefaultHogedataInfoApi : 
        IHogedataInfoApi
    {
        typedef boost::mpl::vector<DefaultHogedataDispenserApi> external_api_types;
    };

    template<
        class HogedataInfoApiType = DefaultHogedataInfoApi
    >
    class BaseHogedataInfo
    {
    public:
        
        typedef typename UCT::ExternalApiOrDefault<HogedataInfoApiType, IHogedataInfoApi, IHogedataDispenserApi>::type hogedata_dispenser_api_type;
        typedef BaseHogedataDispenser<hogedata_dispenser_api_type> hogedata_dispenser_type;

        hogedata_dispenser_type *GetDispenser() const
        {
            return NULL;
        }
    };

    


#if 0
    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseHogedataInfo<> HogedataInfo;
        typedef HogedataInfo::hogedata_dispenser_api_type HogedataDispenserApi;
        typedef HogedataInfo::hogedata_dispenser_type HogedataDispenser;
        typedef HogedataDispenser::assembly_hogedata_api_type AssemblyHogedataApi;
        typedef HogedataDispenser::assembly_hogedata_type AssemblyHogedata;
        HogedataInfo hogeInfo;
        HogedataDispenser hogeDisp;
        AssemblyHogedata asmHoge;

        hogeInfo.GetDispenser();
        hogeDisp.GetInfo();
        hogeDisp.GetAssembly();
        asmHoge.GetInfo();
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenserApi, DefaultHogedataDispenserApi>));
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser, BaseHogedataDispenser<>>));
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_api_type, DefaultHogedataInfoApi>));
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_type, BaseHogedataInfo<>>));
        BOOST_MPL_ASSERT((boost::is_same<AssemblyHogedata::hogedata_info_api_type, DefaultHogedataInfoApi>));
        BOOST_MPL_ASSERT((boost::is_same<AssemblyHogedata::hogedata_info_type, BaseHogedataInfo<>>));
    }
#endif

    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        
        BOOST_MPL_ASSERT((boost::is_same<Detail::ExtractDefaultExternalApi<INT, INT>::api_type, INT>));
        BOOST_MPL_ASSERT((
            boost::is_same<
                Detail::ExtractDefaultExternalApi<
                    DefaultExternalApi<
                        INT, 
                        IHogedataInfoApi, 
                        IHogedataDispenserApi
                    >, 
                    IHogedataInfoApi
                >::api_type, INT>));
        BOOST_MPL_ASSERT((
            boost::is_same<
                Detail::ExtractDefaultExternalApi<
                    DefaultExternalApi<
                        DefaultExternalApi<
                            DefaultExternalApi<
                                INT, 
                                IHogedataInfoApi, 
                                IHogedataDispenserApi
                            >, 
                            IHogedataDispenserApi, 
                            IAssemblyHogedataApi
                        >, 
                        IAssemblyHogedataApi, 
                        IHogedataInfoApi
                    >, 
                    IHogedataInfoApi
                >::api_type, INT>));

        BOOST_MPL_ASSERT((
            boost::is_same<
                ExternalApiOrDefault<
                    INT, 
                    IHogedataInfoApi, 
                    IHogedataDispenserApi>::type, 
                DefaultExternalApi<
                    INT, 
                    IHogedataInfoApi, 
                    IHogedataDispenserApi>>));        
        BOOST_MPL_ASSERT((
            boost::is_same<
                ExternalApiOrDefault<
                    DefaultExternalApi<
                        INT, 
                        IHogedataInfoApi, 
                        IHogedataDispenserApi
                    >, 
                    IHogedataDispenserApi, 
                    IAssemblyHogedataApi
                >::type, 
                DefaultExternalApi<
                    DefaultExternalApi<
                        INT,
                        IHogedataInfoApi,
                        IHogedataDispenserApi
                    >,
                    IHogedataDispenserApi,
                    IAssemblyHogedataApi
                >>));        
        BOOST_MPL_ASSERT((
            boost::is_same<
                ExternalApiOrDefault<
                    DefaultExternalApi<
                        INT, 
                        IHogedataInfoApi, 
                        IHogedataDispenserApi
                    >, 
                    IHogedataDispenserApi, 
                    IHogedataInfoApi
                >::type, INT>));
        BOOST_MPL_ASSERT((
            boost::is_same<
                ExternalApiOrDefault<
                    DefaultExternalApi<
                        DefaultExternalApi<
                            INT,
                            IHogedataInfoApi,
                            IHogedataDispenserApi
                        >,
                        IHogedataDispenserApi,
                        IAssemblyHogedataApi
                    >,
                    IAssemblyHogedataApi,
                    IHogedataInfoApi
                >::type, INT>));

        typedef BaseHogedataInfo<INT> HogedataInfo;
        typedef HogedataInfo::hogedata_dispenser_api_type HogedataDispenserApi;
        typedef HogedataInfo::hogedata_dispenser_type HogedataDispenser;
        typedef HogedataDispenser::assembly_hogedata_api_type AssemblyHogedataApi;
        typedef HogedataDispenser::assembly_hogedata_type AssemblyHogedata;
        HogedataInfo hogeInfo;
        HogedataDispenser hogeDisp;
        AssemblyHogedata asmHoge;

        hogeInfo.GetDispenser();
        hogeDisp.GetInfo();
        hogeDisp.GetAssembly();
        asmHoge.GetInfo();
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenserApi, DefaultExternalApi<INT, IHogedataInfoApi, IHogedataDispenserApi>>));
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser, BaseHogedataDispenser<DefaultExternalApi<INT, IHogedataInfoApi, IHogedataDispenserApi>>>));
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_type, BaseHogedataInfo<INT>>));
        BOOST_MPL_ASSERT((boost::is_same<AssemblyHogedata::hogedata_info_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<AssemblyHogedata::hogedata_info_type, BaseHogedataInfo<INT>>));
    }


    //TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, Test_01)
    //{
    //    namespace mpl = boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Traits;

    //    typedef BaseHogedataInfo<> HogedataInfo;
    //    HogedataInfo hogeInfo;

    //    hogeInfo.GetDispenser();
    //    BOOST_MPL_ASSERT((boost::is_same<HogedataInfo::hogedata_dispenser_api_type, DefaultHogedataDispenserApi>));
    //    BOOST_MPL_ASSERT((boost::is_same<HogedataInfo::hogedata_dispenser_type, BaseHogedataDispenser<>>));

    //    typedef BaseHogedataInfo<INT> HogedataInfo2;
    //    HogedataInfo2 hogeInfo2;

    //    hogeInfo2.GetDispenser();
    //    BOOST_MPL_ASSERT((boost::is_same<HogedataInfo2::hogedata_dispenser_api_type, DefaultExternalApi<INT, IHogedataDispenserApi>>));

    //    
    //    typedef BaseHogedataDispenser<> HogedataDispenser;
    //    HogedataDispenser hogeDisp;

    //    hogeDisp.GetInfo();
    //    BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser::hogedata_info_api_type, DefaultHogedataInfoApi>));

    //    typedef BaseHogedataDispenser<INT> HogedataDispenser2;
    //    HogedataDispenser2 hogeDisp2;
    //    hogeDisp2.GetInfo();
    //    BOOST_MPL_ASSERT((boost::is_same<HogedataDispenser2::hogedata_info_api_type, DefaultExternalApi<INT, IHogedataInfoApi>>));
    //}
}
