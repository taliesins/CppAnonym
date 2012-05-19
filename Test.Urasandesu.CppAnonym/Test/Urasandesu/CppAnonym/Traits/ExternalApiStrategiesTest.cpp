#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_ApiStrategiesTest.*
namespace {

    namespace UCT {
        using namespace Urasandesu::CppAnonym::Traits;
    }   // namespace UCT



    struct IClass1Api;
    
    struct DefaultClass1Api;

    template<
        class Class1ApiType
    >
    class BaseClass1;

    struct IClass2Api;

    struct DefaultClass2Api;
    
    template<
        class Class2ApiType
    >
    class BaseClass2;

    struct IClass3Api { };

    struct DefaultClass3Api : 
        IClass3Api
    {
        typedef boost::mpl::vector<DefaultClass1Api, DefaultClass2Api> external_api_types;
    };

    template<
        class Class3ApiType = DefaultClass3Api
    >
    class BaseClass3
    {
    public:
        
        typedef typename UCT::ExternalApiOrDefault<Class3ApiType, IClass3Api, IClass1Api>::type class1_api_type;
        typedef BaseClass1<class1_api_type> class1_type;

        typedef typename UCT::ExternalApiOrDefault<Class3ApiType, IClass3Api, IClass2Api>::type class2_api_type;
        typedef BaseClass2<class2_api_type> class2_type;

        class1_type *GetClass1() const
        {
            return NULL;
        }

        class2_type *GetClass2() const
        {
            return NULL;
        }
    };

    
    
    struct IClass2Api { };

    struct DefaultClass2Api : 
        IClass2Api
    {
        typedef boost::mpl::vector<DefaultClass1Api, DefaultClass3Api> external_api_types;
    };
    
    template<
        class Class2ApiType = DefaultClass2Api
    >
    class BaseClass2
    {
    public:
        typedef typename UCT::ExternalApiOrDefault<Class2ApiType, IClass2Api, IClass1Api>::type class1_api_type;
        typedef BaseClass1<class1_api_type> class1_type;

        typedef typename UCT::ExternalApiOrDefault<Class2ApiType, IClass2Api, IClass3Api>::type class3_api_type;
        typedef BaseClass3<class3_api_type> class3_type;

        class1_type *GetClass1() const
        {
            return NULL;
        }

        class3_type *GetClass3() const
        {
            return NULL;
        }
    };



    struct IClass1Api { };

    struct DefaultClass1Api : 
        IClass1Api
    {
        typedef boost::mpl::vector<DefaultClass2Api, DefaultClass3Api> external_api_types;
    };

    template<
        class Class1ApiType = DefaultClass1Api
    >
    class BaseClass1
    {
    public:
        
        typedef typename UCT::ExternalApiOrDefault<Class1ApiType, IClass1Api, IClass2Api>::type class2_api_type;
        typedef BaseClass2<class2_api_type> class2_type;
        
        typedef typename UCT::ExternalApiOrDefault<Class1ApiType, IClass1Api, IClass3Api>::type class3_api_type;
        typedef BaseClass3<class3_api_type> class3_type;

        class2_type *GetClass2() const
        {
            return NULL;
        }

        class3_type *GetClass3() const
        {
            return NULL;
        }
    };


    struct TypeMetadataKey;

    struct DefaultTypeMetadataApi; 

    template<
        class TypeMetadataApiType = DefaultTypeMetadataApi
    >
    struct BaseTypeMetadata;

    struct MethodMetadataKey;

    struct DefaultMethodMetadataApi;

    template<
        class MethodMetadataApiType = DefaultMethodMetadataApi
    >
    struct BaseMethodMetadata;

    struct MethodNameMetadataKey;

    struct DefaultMethodNameMetadataApi;

    template<
        class MethodNameMetadataApiType = DefaultMethodNameMetadataApi
    >
    struct BaseMethodNameMetadata;

    
    
    struct MethodMetadataKey { };

    struct DefaultMethodMetadataApi
    {
        typedef boost::mpl::map<boost::mpl::pair<TypeMetadataKey, BaseTypeMetadata<>>> api_map;
    };

    template<
        class MethodMetadataApiType
    >
    struct BaseMethodMetadata
    {
        typedef typename UCT::ApiAt<MethodMetadataApiType, MethodMetadataKey, TypeMetadataKey>::type type_metadata_type;

        BaseMethodMetadata() { }
        type_metadata_type *m_pRetType;
    };


    
    
    struct MethodNameMetadataKey { };

    struct DefaultMethodNameMetadataApi
    {
        typedef boost::mpl::map<boost::mpl::pair<TypeMetadataKey, BaseTypeMetadata<>>> api_map;
    };

    template<
        class MethodNameMetadataApiType
    >
    struct BaseMethodNameMetadata
    {
        typedef typename UCT::ApiAt<MethodNameMetadataApiType, MethodNameMetadataKey, TypeMetadataKey>::type type_metadata_type;

        BaseMethodNameMetadata() { }
        type_metadata_type *m_pRetType;
    };


    
    
    struct TypeMetadataKey { };

    struct DefaultTypeMetadataApi 
    { 
        typedef boost::mpl::map<boost::mpl::pair<MethodMetadataKey, BaseMethodMetadata<>>, 
                                boost::mpl::pair<MethodNameMetadataKey, BaseMethodNameMetadata<>>> api_map;
    };

    template<
        class TypeMetadataApiType
    >
    struct BaseTypeMetadata : 
        public UCT::ApiAt<TypeMetadataApiType, TypeMetadataKey, MethodNameMetadataKey>::type, 
        public UCT::ApiAt<TypeMetadataApiType, TypeMetadataKey, MethodMetadataKey>::type
    {
        BaseTypeMetadata() { }
    };

    // 名前、どうしようか？
    // 自由に型の入れ替えができる、ってことまできてるから。
    // あんまり、External じゃなくなってきてるし・・・。
    // ApiCartridge とか。いや、凝った名前は付けないのが原則。
    // もっと退屈でそのまんまな感じのほうが良い。
    // ApiMap とか。
    //    typedef typename UCT::ApiMap<Class1ApiType, Class1ApiKey, Class2ApiKey>::type class2_api_type;    // これだと、Map 型のなにがしに見えるな・・・。
    // ApiMapAccessor とか。
    //    typedef typename UCT::ApiMapAccessor<Class1ApiType, Class1ApiKey, Class2ApiKey>::type class2_api_type;    // Default が出てくるのが？？ってなりそう。
    // ApiMapAtOrDefault とか。
    //    typedef typename UCT::ApiMapAtOrDefault<Class1ApiType, Class1ApiKey, Class2ApiKey>::type class2_api_type;    // Map 要らなくね？
    // ApiAtOrDefault とか。
    //    typedef typename UCT::ApiAtOrDefault<Class1ApiType, Class1ApiKey, Class2ApiKey>::type class2_api_type;    // 英語的におかしいね。API と at 逆か。
    // AtApiOrDefault とか。
    //    typedef typename UCT::AtApiOrDefault<Class1ApiType, Class1ApiKey, Class2ApiKey>::type class2_api_type;    // あ。メタ関数的であれば、Default が出てきても驚くことはなさそう。
    // ApiAt とか。
    //    typedef typename UCT::ApiAt<Class1ApiType, Class1ApiKey, Class2ApiKey>::type class2_api_type;    // 英語的におかしいことはなかった。
    //// そういえば、Class1ApiType に渡される型って、必ず完全な型なんだから、Class1ApiKey はそこから導出できるんじゃね？
    ////    typedef typename UCT::ApiAt<Class1ApiType, Class2ApiKey>::type class2_api_type;    // int とか入ってくるとだめか。

    // ApiAt<ApiMap, CurrentApiKey, ApiKey> に決めるとすると、他の I/F はこうか。
    // 
    //template<class ApiType, class ApiTypeInterface, class IExternalApiType>
    //struct DefaultExternalApi : 
    //    ApiTypeInterface
    //{
    //    typedef boost::mpl::vector<DefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType>> external_api_types;
    //};
    // 


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, Hoge)
    {
        typedef BaseTypeMetadata<> TypeMetadata;
        typedef BaseMethodMetadata<> MethodMetadata;
        typedef BaseMethodNameMetadata<> MethodNameMetadata;
        TypeMetadata typeMeta;
        MethodMetadata *pMethodMeta = &typeMeta;            // O.K.
        MethodNameMetadata *pMethodNameMeta = &typeMeta;    // O.K.

        BOOST_MPL_ASSERT((boost::is_same<BaseMethodNameMetadata<INT>::type_metadata_type, INT >));

        //typedef boost::mpl::map<boost::mpl::pair<MetadataInfoKey, BaseMetadataInfo<>>> external_type_map;
        //BOOST_MPL_ASSERT_RELATION(boost::mpl::size<external_type_map>::value, ==, 1);
        //typedef boost::mpl::at<external_type_map, MetadataInfoKey>::type Result;
        //BOOST_MPL_ASSERT((boost::is_same<Result, BaseMetadataInfo<> >));

//BOOST_MPL_ASSERT_RELATION( size<m>::value, ==, 4 );
//BOOST_MPL_ASSERT_NOT(( empty<m> ));
//
//BOOST_MPL_ASSERT(( is_same< at<m,int>::type, unsigned > ));
//BOOST_MPL_ASSERT(( is_same< at<m,long_<5> >::type, char[17] > ));
//BOOST_MPL_ASSERT(( is_same< at<m,int[42]>::type, bool > ));
//BOOST_MPL_ASSERT(( is_same< at<m,long>::type, void_ > ));
    }
        

    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, ApiOrDefaultTest_StartWithClass1_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseClass1<> Class1;
        typedef Class1::class2_type Class2;
        typedef Class2::class3_type Class3;
        Class1 class1;
        Class2 class2;
        Class3 class3;

        class1.GetClass2();
        class1.GetClass3();
        class2.GetClass1();
        class2.GetClass3();
        class3.GetClass1();
        class3.GetClass2();
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_api_type, DefaultClass1Api>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_type, Class1>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_api_type, DefaultClass1Api>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_type, Class1>));
    }


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, ApiOrDefaultTest_StartWithClass1_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseClass1<INT> Class1;
        typedef Class1::class2_type Class2;
        typedef Class2::class3_type Class3;
        Class1 class1;
        Class2 class2;
        Class3 class3;

        class1.GetClass2();
        class1.GetClass3();
        class2.GetClass1();
        class2.GetClass3();
        class3.GetClass1();
        class3.GetClass2();
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_type, Class1>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_type, Class1>));
    }


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, ApiOrDefaultTest_StartWithClass2_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseClass2<> Class2;
        typedef Class2::class1_type Class1;
        typedef Class2::class3_type Class3;
        Class1 class1;
        Class2 class2;
        Class3 class3;

        class1.GetClass2();
        class1.GetClass3();
        class2.GetClass1();
        class2.GetClass3();
        class3.GetClass1();
        class3.GetClass2();
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_api_type, DefaultClass2Api>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_type, Class2>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_api_type, DefaultClass2Api>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_type, Class2>));
    }


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, ApiOrDefaultTest_StartWithClass2_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseClass2<INT> Class2;
        typedef Class2::class1_type Class1;
        typedef Class2::class3_type Class3;
        Class1 class1;
        Class2 class2;
        Class3 class3;

        class1.GetClass2();
        class1.GetClass3();
        class2.GetClass1();
        class2.GetClass3();
        class3.GetClass1();
        class3.GetClass2();
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_type, Class2>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_type, Class2>));
    }


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, ApiOrDefaultTest_StartWithClass3_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseClass3<> Class3;
        typedef Class3::class1_type Class1;
        typedef Class3::class2_type Class2;
        Class1 class1;
        Class2 class2;
        Class3 class3;

        class1.GetClass2();
        class1.GetClass3();
        class2.GetClass1();
        class2.GetClass3();
        class3.GetClass1();
        class3.GetClass2();
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_api_type, DefaultClass3Api>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_type, Class3>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_api_type, DefaultClass3Api>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_type, Class3>));
    }


    TEST(Urasandesu_CppAnonym_Hosting_ApiStrategiesTest, ApiOrDefaultTest_StartWithClass3_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        typedef BaseClass3<INT> Class3;
        typedef Class3::class1_type Class1;
        typedef Class3::class2_type Class2;
        Class1 class1;
        Class2 class2;
        Class3 class3;

        class1.GetClass2();
        class1.GetClass3();
        class2.GetClass1();
        class2.GetClass3();
        class3.GetClass1();
        class3.GetClass2();
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_type, Class3>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_api_type, INT>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_type, Class3>));
    }
}
