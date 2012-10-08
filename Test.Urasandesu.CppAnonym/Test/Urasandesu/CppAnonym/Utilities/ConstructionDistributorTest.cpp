#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_01) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;
        ASSERT_EQ(0, Counter::Instance().Value());
        
        BYTE buf[sizeof(Counter *)];
        ASSERT_EQ(0, Counter::Instance().Value());

        ConstructionDistributor<Counter *>::Construct(buf);
        ASSERT_EQ(0, Counter::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_02) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;
        ASSERT_EQ(0, Counter::Instance().Value());
        
        BYTE buf[sizeof(Counter *)];
        ASSERT_EQ(0, Counter::Instance().Value());

        ConstructionDistributor<Counter *>::Construct(buf, new Counter());
        ASSERT_EQ(1, Counter::Instance().Value());

        Counter *&p = reinterpret_cast<Counter *&>(buf);
        ASSERT_TRUE(p != NULL);

        delete p;
        ASSERT_EQ(0, Counter::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_01) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;
        ASSERT_EQ(0, Counter::Instance().Value());
        
        BYTE buf[sizeof(shared_ptr<Counter>)];
        ASSERT_EQ(0, Counter::Instance().Value());

        ConstructionDistributor<shared_ptr<Counter> >::Construct(buf);
        ASSERT_EQ(0, Counter::Instance().Value());

        shared_ptr<Counter> &p = reinterpret_cast<shared_ptr<Counter> &>(buf);
        ASSERT_FALSE(p);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_02) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;
        ASSERT_EQ(0, Counter::Instance().Value());
        
        BYTE buf[sizeof(shared_ptr<Counter>)];
        ASSERT_EQ(0, Counter::Instance().Value());

        ConstructionDistributor<shared_ptr<Counter> >::Construct(buf, new Counter());
        ASSERT_EQ(1, Counter::Instance().Value());

        shared_ptr<Counter> &p = reinterpret_cast<shared_ptr<Counter> &>(buf);
        ASSERT_TRUE(p);

        p.~shared_ptr<Counter>();
        ASSERT_EQ(0, Counter::Instance().Value());
    }

}
