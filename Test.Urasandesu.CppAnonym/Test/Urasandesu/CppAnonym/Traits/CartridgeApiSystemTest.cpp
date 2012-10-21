#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace FlattenDetail {

        namespace mpl = boost::mpl;

        struct Flatter
        {
            template<class F, class State, class Value>
            struct apply : 
                mpl::copy<typename mpl::apply<F, Value>::type, mpl::back_inserter<State> >
            {
            };
        };

        template<class Sequence, class F>
        struct FlattenImpl : 
            mpl::fold<Sequence, mpl::vector<>, mpl::bind<Flatter, F, mpl::_1, mpl::_2> >
        {
        };
    
    }   // namespace FlattenDetail {


    template<class Sequence, class F>
    struct Flatten : 
        FlattenDetail::FlattenImpl<Sequence, F>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {


// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Traits_ApiStrategiesTest.*
namespace {

    namespace UCT {
        using namespace Urasandesu::CppAnonym::Traits;
    }   // namespace UCT

    struct Class1ApiHolderLabel; 

    struct DefaultClass1ApiHolder; 

    struct Class1Label;

    template<
        class Class1ApiHolder = DefaultClass1ApiHolder
    >
    class BaseClass1;

    struct Class2ApiHolderLabel;

    struct DefaultClass2ApiHolder;

    struct Class2Label;

    template<
        class Class2ApiHolder = DefaultClass2ApiHolder
    >
    class BaseClass2;

    struct Class3ApiHolderLabel;

    struct DefaultClass3ApiHolder;

    struct Class3Label;

    template<
        class Class3ApiHolder = DefaultClass3ApiHolder
    >
    class BaseClass3;

    
    
    struct Class2ApiHolderLabel { };

    struct DefaultClass2ApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Class1ApiHolderLabel, DefaultClass1ApiHolder>, 
                                boost::mpl::pair<Class1Label, BaseClass1<>>, 
                                boost::mpl::pair<Class3ApiHolderLabel, DefaultClass3ApiHolder>,
                                boost::mpl::pair<Class3Label, BaseClass3<>>> api_cartridges;
    };

    struct Class2Label { };

    template<
        class Class2ApiHolder
    >
    class BaseClass2
    {
    public:
        typedef typename UCT::ApiAt<Class2ApiHolder, Class2Label, Class1ApiHolderLabel>::type class1_api_holder;
        typedef typename UCT::ApiAt<Class2ApiHolder, Class2Label, Class1Label>::type class1_type;
        typedef typename UCT::ApiAt<Class2ApiHolder, Class2Label, Class3ApiHolderLabel>::type class3_api_holder;
        typedef typename UCT::ApiAt<Class2ApiHolder, Class2Label, Class3Label>::type class3_type;

        BaseClass2() { }

        class1_type const *GetClass1() const
        {
            return m_pClass1;
        }

        class3_type const *GetClass3() const
        {
            return m_pClass3;
        }

    private:
        class1_type *m_pClass1;
        class3_type *m_pClass3;
    };


    
    
    struct Class3ApiHolderLabel { };

    struct DefaultClass3ApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Class1ApiHolderLabel, DefaultClass1ApiHolder>, 
                                boost::mpl::pair<Class1Label, BaseClass1<>>,
                                boost::mpl::pair<Class2ApiHolderLabel, DefaultClass2ApiHolder>,
                                boost::mpl::pair<Class2Label, BaseClass2<>>> api_cartridges;
    };

    struct Class3Label { };

    template<
        class Class3ApiHolder
    >
    class BaseClass3
    {
    public:
        typedef typename UCT::ApiAt<Class3ApiHolder, Class3Label, Class1ApiHolderLabel>::type class1_api_holder;
        typedef typename UCT::ApiAt<Class3ApiHolder, Class3Label, Class1Label>::type class1_type;
        typedef typename UCT::ApiAt<Class3ApiHolder, Class3Label, Class2ApiHolderLabel>::type class2_api_holder;
        typedef typename UCT::ApiAt<Class3ApiHolder, Class3Label, Class2Label>::type class2_type;

        BaseClass3() { }
        
        class1_type const *GetClass1() const
        {
            return m_pClass1;
        }

        class2_type const *GetClass2() const
        {
            return m_pClass2;
        }

    private:
        class1_type *m_pClass1;
        class2_type *m_pClass2;
    };


    
    
    struct Class1Api { };

    struct DefaultClass1ApiHolder 
    { 
        typedef boost::mpl::map<boost::mpl::pair<Class2ApiHolderLabel, DefaultClass2ApiHolder>, 
                                boost::mpl::pair<Class2Label, BaseClass2<>>, 
                                boost::mpl::pair<Class3ApiHolderLabel, DefaultClass3ApiHolder>, 
                                boost::mpl::pair<Class3Label, BaseClass3<>>> api_cartridges;
    };

    struct Class1Label { };

    template<
        class Class1ApiHolder
    >
    class BaseClass1 : 
        public UCT::ApiAt<Class1ApiHolder, Class1Label, Class3Label>::type, 
        public UCT::ApiAt<Class1ApiHolder, Class1Label, Class2Label>::type
    {
    public:
        typedef typename UCT::ApiAt<Class1ApiHolder, Class1Label, Class2ApiHolderLabel>::type class2_api_holder;
        typedef typename UCT::ApiAt<Class1ApiHolder, Class1Label, Class2Label>::type class2_type;
        typedef typename UCT::ApiAt<Class1ApiHolder, Class1Label, Class3ApiHolderLabel>::type class3_api_holder;
        typedef typename UCT::ApiAt<Class1ApiHolder, Class1Label, Class3Label>::type class3_type;

        BaseClass1() { }

        class2_type const *GetClass2() const
        {
            return m_pClass2;
        }

        class3_type const *GetClass3() const
        {
            return m_pClass3;
        }
    
    private:
        class2_type *m_pClass2;
        class3_type *m_pClass3;
    };


    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, ApiAtTest_StartWithClass1_01)
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
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_api_holder, DefaultClass1ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_type, Class1>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_api_holder, DefaultClass1ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_type, Class1>));
    }


    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, ApiAtTest_StartWithClass1_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        struct TestClass1ApiHolder;
        struct TestClass2ApiHolder;
        struct TestClass3ApiHolder;

        struct TestClass3ApiHolder
        {
            typedef mpl::map<mpl::pair<Class1ApiHolderLabel, TestClass1ApiHolder>, 
                             mpl::pair<Class1Label, BaseClass1<TestClass1ApiHolder>>> api_cartridges;
        };

        struct TestClass2ApiHolder
        {
            typedef mpl::map<mpl::pair<Class1ApiHolderLabel, TestClass1ApiHolder>, 
                             mpl::pair<Class1Label, BaseClass1<TestClass1ApiHolder>>, 
                             mpl::pair<Class3ApiHolderLabel, TestClass3ApiHolder>,
                             mpl::pair<Class3Label, BaseClass3<TestClass3ApiHolder>>> api_cartridges;
        };

        struct TestClass1ApiHolder 
        { 
            typedef mpl::map<mpl::pair<Class2ApiHolderLabel, TestClass2ApiHolder>, 
                             mpl::pair<Class2Label, BaseClass2<TestClass2ApiHolder>>> api_cartridges;
        };

        typedef BaseClass1<TestClass1ApiHolder> Class1;
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
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_api_holder, TestClass1ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class1_type, Class1>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_api_holder, TestClass1ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class1_type, Class1>));
    }


    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, ApiAtTest_StartWithClass2_01)
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
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_api_holder, DefaultClass2ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_type, Class2>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_api_holder, DefaultClass2ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_type, Class2>));
    }


    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, ApiAtTest_StartWithClass2_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        struct TestClass1ApiHolder;
        struct TestClass2ApiHolder;
        struct TestClass3ApiHolder;

        struct TestClass3ApiHolder
        {
            typedef mpl::map<mpl::pair<Class2ApiHolderLabel, TestClass2ApiHolder>,
                             mpl::pair<Class2Label, BaseClass2<TestClass2ApiHolder>>> api_cartridges;
        };

        struct TestClass2ApiHolder
        {
            typedef mpl::map<mpl::pair<Class1ApiHolderLabel, TestClass1ApiHolder>, 
                             mpl::pair<Class1Label, BaseClass1<TestClass1ApiHolder>>, 
                             mpl::pair<Class3ApiHolderLabel, TestClass3ApiHolder>,
                             mpl::pair<Class3Label, BaseClass3<TestClass3ApiHolder>>> api_cartridges;
        };

        struct TestClass1ApiHolder 
        { 
            typedef mpl::map<mpl::pair<Class2ApiHolderLabel, TestClass2ApiHolder>, 
                             mpl::pair<Class2Label, BaseClass2<TestClass2ApiHolder>>> api_cartridges;
        };

        typedef BaseClass2<TestClass2ApiHolder> Class2;
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
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_api_holder, TestClass2ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class2_type, Class2>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_api_holder, TestClass2ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class3::class2_type, Class2>));
    }


    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, ApiAtTest_StartWithClass3_01)
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
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_api_holder, DefaultClass3ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_type, Class3>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_api_holder, DefaultClass3ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_type, Class3>));
    }


    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, ApiAtTest_StartWithClass3_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        struct TestClass1ApiHolder;
        struct TestClass2ApiHolder;
        struct TestClass3ApiHolder;

        struct TestClass3ApiHolder
        {
            typedef mpl::map<mpl::pair<Class1ApiHolderLabel, TestClass1ApiHolder>, 
                             mpl::pair<Class1Label, BaseClass1<TestClass1ApiHolder>>,
                             mpl::pair<Class2ApiHolderLabel, TestClass2ApiHolder>,
                             mpl::pair<Class2Label, BaseClass2<TestClass2ApiHolder>>> api_cartridges;
        };

        struct TestClass2ApiHolder
        {
            typedef mpl::map<mpl::pair<Class3ApiHolderLabel, TestClass3ApiHolder>,
                             mpl::pair<Class3Label, BaseClass3<TestClass3ApiHolder>>> api_cartridges;
        };

        struct TestClass1ApiHolder 
        { 
            typedef mpl::map<mpl::pair<Class3ApiHolderLabel, TestClass3ApiHolder>, 
                             mpl::pair<Class3Label, BaseClass3<TestClass3ApiHolder>>> api_cartridges;
        };

        typedef BaseClass3<TestClass3ApiHolder> Class3;
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
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_api_holder, TestClass3ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class1::class3_type, Class3>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_api_holder, TestClass3ApiHolder>));
        BOOST_MPL_ASSERT((boost::is_same<Class2::class3_type, Class3>));
    }
}
