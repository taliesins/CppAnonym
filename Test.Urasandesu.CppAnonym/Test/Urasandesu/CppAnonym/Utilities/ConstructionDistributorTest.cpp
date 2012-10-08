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
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(Tester *)];
        ASSERT_EQ(0, Tester::Counter().Value());

        ConstructionDistributor<Tester *>::Construct(buf);
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, RawPointerTest_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(Tester *)];
        ASSERT_EQ(0, Tester::Counter().Value());

        ConstructionDistributor<Tester *>::Construct(buf, new Tester());
        ASSERT_EQ(1, Tester::Counter().Value());

        Tester *&p = reinterpret_cast<Tester *&>(buf);
        ASSERT_TRUE(p != NULL);

        delete p;
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_01) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(shared_ptr<Tester>)];
        ASSERT_EQ(0, Tester::Counter().Value());

        ConstructionDistributor<shared_ptr<Tester> >::Construct(buf);
        ASSERT_EQ(0, Tester::Counter().Value());

        shared_ptr<Tester> &p = reinterpret_cast<shared_ptr<Tester> &>(buf);
        ASSERT_FALSE(p);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_ConstructionDistributorTest, NotPod_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(shared_ptr<Tester>)];
        ASSERT_EQ(0, Tester::Counter().Value());

        ConstructionDistributor<shared_ptr<Tester> >::Construct(buf, new Tester());
        ASSERT_EQ(1, Tester::Counter().Value());

        shared_ptr<Tester> &p = reinterpret_cast<shared_ptr<Tester> &>(buf);
        ASSERT_TRUE(p);

        p.~shared_ptr<Tester>();
        ASSERT_EQ(0, Tester::Counter().Value());
    }

}
