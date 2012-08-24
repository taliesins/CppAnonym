#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace Detail {

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
    
    }   // namespace Detail {


    template<class Sequence, class F>
    struct Flatten : 
        Detail::FlattenImpl<Sequence, F>
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

    
    namespace _200861B5 {

        struct SmartPtrChainMapper;
        struct SmartPtrChainConstructor;

        
        
        
        
        template<
            class Previous, 
            class Mapper = SmartPtrChainMapper,
            class Constructor = SmartPtrChainConstructor
        >
        struct SmartPtrChainInfo;

        
        
        
        
        template<
            class Previous, 
            class Mapper,
            class Constructor
        >
        struct SmartPtrChainInfo
        {
            typedef Previous previous_type;
            typedef Mapper mapper_type;
            typedef Constructor constructor_type;
        };

        struct A;
        struct B;
        struct C;
        struct D;

        template<class ChainInfo>
        struct get_previous
        {
            typedef typename ChainInfo::previous_type type;
        };

    }   // namespace _200861B5 {

    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, Test_01)
    {
        using namespace _200861B5;
        
        typedef boost::mpl::vector<SmartPtrChainInfo<A>, SmartPtrChainInfo<B>, SmartPtrChainInfo<C> > Vec;
        typedef boost::mpl::find_if<Vec, boost::is_same<get_previous<boost::mpl::_1>, C> >::type I;
        //typedef boost::mpl::find_if<Vec, boost::is_same<get_previous<boost::mpl::_1>, D> >::type I;
        typedef boost::mpl::end<Vec>::type IEnd;
        BOOST_MPL_ASSERT((boost::mpl::not_<boost::is_same<I, IEnd> >));
    }

    namespace _E2724154 {

        struct A
        {
            A() { }
            int i;
        };

        struct B
        {
            char *str;
        };

    }   // namespace _E2724154 {

    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, Test_02)
    {
        using namespace _E2724154;

        {
            boost::shared_ptr<void> pVoid;
            boost::shared_ptr<A> pA = boost::make_shared<A>();
            pA->i = 10;
            pVoid = pA;
            boost::shared_ptr<B> pB = boost::static_pointer_cast<B>(pVoid);
            ASSERT_TRUE(pB);    // reinterpret_cast と同じっぽ。
        }
        
        {
            boost::any any1;
            boost::shared_ptr<A> pA1 = boost::make_shared<A>();
            pA1->i = 10;
            any1 = pA1;
            ASSERT_EQ(2, pA1.use_count());

            boost::any any2;
            any2 = any1;
            ASSERT_EQ(3, pA1.use_count());

            boost::shared_ptr<B> *ppB = boost::any_cast<boost::shared_ptr<B> >(&any2);
            ASSERT_FALSE(ppB);

            boost::shared_ptr<A> *ppA = boost::any_cast<boost::shared_ptr<A> >(&any2);
            ASSERT_TRUE(ppA != NULL);
            boost::shared_ptr<A> pA2 = *ppA;
            ASSERT_EQ(4, pA1.use_count());
        }
        
    }

    namespace _35C2C9F3 {

        template<
            class Previous 
        >
        struct SmartPtrChainInfo
        {
            typedef Previous previous_type;
        };
        
        struct A
        {
            typedef boost::mpl::vector<SmartPtrChainInfo<boost::mpl::void_> > chain_info_sequence_type;
        };

        struct B
        {
            typedef boost::mpl::vector<SmartPtrChainInfo<A> > chain_info_sequence_type;
        };

        struct C
        {
            typedef boost::mpl::vector<SmartPtrChainInfo<B> > chain_info_sequence_type;
        };

        struct D
        {
            typedef boost::mpl::vector<SmartPtrChainInfo<D>, SmartPtrChainInfo<B> > chain_info_sequence_type;
        };

        struct E
        {
            typedef boost::mpl::vector<SmartPtrChainInfo<D> > chain_info_sequence_type;
        };

        namespace Detail {

            namespace mpl = boost::mpl;

        //struct Flatter
        //{
        //    template<class F, class State, class Value>
        //    struct apply : 
        //        mpl::copy<typename mpl::apply<F, Value>::type, mpl::back_inserter<State> >
        //    {
        //    };
        //};

        //template<class Sequence, class F>
        //struct FlattenImpl : 
        //    mpl::fold<Sequence, mpl::vector<>, mpl::bind<Flatter, F, mpl::_1, mpl::_2> >
        //{
        //};

        //template<class Sequence, class F>
        //struct Flatten : 
        //    FlattenImpl<Sequence, F>
        //{
        //};

        //struct GetValueF
        //{
        //    template<class Value>
        //    struct apply
        //    {
        //        typedef Value type;
        //    };
        //};

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Type, type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Type, type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ChainInfo, previous_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ChainInfo, previous_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type);

        template<class Current>
        struct EvalCurrent : 
            mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(ChainInfo, previous_type, Current),
                CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, Current),
                mpl::identity<Current> >
        {
        };

        //template<class Last, class Current>
        //struct EvalChainInfoSequence : 
        //    mpl::eval_if<
        //        mpl::and_<
        //            CPP_ANONYM_HAS_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type, Current),
        //            mpl::not_<boost::is_same<Last, Current> >
        //        >,
        //        CPP_ANONYM_GET_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type, Current),
        //        mpl::identity<mpl::vector<Current> > >
        //{
        //};

        //template<class Last, class Current>
        //struct EvalCurrentChainInfoSequence : 
        //    EvalChainInfoSequence<Last, typename EvalCurrent<Current>::type>
        //{
        //};

        //template<class Last, class Current>
        //struct FlattenChainInfoImpl : 
        //    mpl::eval_if<
        //        boost::is_same<typename EvalCurrentChainInfoSequence<Last, Current>::type, mpl::vector<Current> >, 
        //        mpl::vector<Current>,
        //        Flatten<
        //            typename EvalCurrentChainInfoSequence<Last, Current>::type,
        //            FlattenChainInfoImpl<Current, mpl::_1 > > >
        //{
        //};

        //template<class T>
        //struct FlattenChainInfo : 
        //    FlattenChainInfoImpl<mpl::void_, T>
        //{
        //};

        template<class T>
        struct GetPreviousType
        {
            typedef typename T::previous_type type;
        };

        struct GetPreviousTypeF
        {
            template<class T>
            struct apply : 
                mpl::eval_if<
                    CPP_ANONYM_HAS_MEMBER_TYPE(ChainInfo, previous_type, T),
                    CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, T),
                    mpl::identity<T> >
            {
            };
        };

        }   // namespace Detail {
    }   // namespace _35C2C9F3 {

    TEST(Urasandesu_CppAnonym_Traits_ApiStrategiesTest, Test_03)
    {
        namespace mpl = boost::mpl;
        using Urasandesu::CppAnonym::Traits::Flatten;
        using namespace _35C2C9F3;

        typedef mpl::vector<int, float, double> Vec0;
        typedef mpl::vector<Vec0, Vec0, Vec0> Vec1;
        typedef mpl::fold<Vec1, mpl::vector0<>, mpl::insert_range<mpl::_1, mpl::end<mpl::_1>, mpl::deref<mpl::_2> > >::type Vec2;
        BOOST_MPL_ASSERT_RELATION(mpl::size<Vec2>::value, ==, 9);

        typedef mpl::vector<SmartPtrChainInfo<Vec0>, Vec0, SmartPtrChainInfo<Vec0> > Vec3;
        BOOST_MPL_ASSERT((boost::is_same<Flatten<Vec1, mpl::identity<mpl::_1> >::type, mpl::vector9<int, float, double, int, float, double, int, float, double> >));
        BOOST_MPL_ASSERT((boost::is_same<Flatten<Vec3, Detail::GetPreviousTypeF >::type, mpl::vector9<int, float, double, int, float, double, int, float, double> >));
        BOOST_MPL_ASSERT((boost::is_same<Flatten<Vec3, Detail::EvalCurrent<mpl::_1> >::type, mpl::vector9<int, float, double, int, float, double, int, float, double> >));

        //typedef FlattenChainInfo<B>::type Vec3;
        //BOOST_MPL_ASSERT_RELATION(mpl::size<Vec3>::value, ==, 3);

        //typedef FlattenChainInfo<E>::type Vec4;
        //BOOST_MPL_ASSERT_RELATION(mpl::size<FlattenChainInfo<D>::type>::value, ==, 5);
        //BOOST_MPL_ASSERT((boost::is_same<FlattenChainInfo<D>::type, int >));
    }
}
