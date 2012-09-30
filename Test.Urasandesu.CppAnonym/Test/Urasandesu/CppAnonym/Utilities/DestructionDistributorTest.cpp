#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_DestructionDistributorTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, RawPointerTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        
        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, RawPointerTest_01) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(Tester *)] = { 0 };
        ASSERT_EQ(0, Tester::Counter().Value());

        DestructionDistributor<Tester *>::Destruct(buf);
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, RawPointerTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, RawPointerTest_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(Tester *)];
        Tester *p = new Tester();
        ::memcpy_s(buf, sizeof(Tester *), &p, sizeof(Tester *));
        ASSERT_EQ(1, Tester::Counter().Value());

        DestructionDistributor<Tester *>::Destruct(buf);
        ASSERT_EQ(1, Tester::Counter().Value());

        delete p;
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, NotPodTest_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, NotPodTest_01) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(shared_ptr<Tester>)] = { 0 };
        ASSERT_EQ(0, Tester::Counter().Value());

        DestructionDistributor<shared_ptr<Tester> >::Destruct(buf);
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, NotPodTest_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, NotPodTest_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE buf[sizeof(shared_ptr<Tester>)];
        shared_ptr<Tester> p(new Tester());
        ::memcpy_s(buf, sizeof(shared_ptr<Tester>), &p, sizeof(shared_ptr<Tester>));
        ASSERT_EQ(1, Tester::Counter().Value());

        DestructionDistributor<shared_ptr<Tester> >::Destruct(buf);
        ASSERT_EQ(0, Tester::Counter().Value());

        ::ZeroMemory(&p, sizeof(shared_ptr<Tester>));  // suppress original auto destruction
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, NotPodTest_03)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_DestructionDistributorTest, NotPodTest_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        shared_ptr<Tester> p(new Tester());
        ASSERT_EQ(1, Tester::Counter().Value());

        DestructionDistributor<shared_ptr<Tester> >::Destruct(&p);
        ASSERT_EQ(0, Tester::Counter().Value());

        ::ZeroMemory(&p, sizeof(shared_ptr<Tester>));  // suppress original auto destruction
    }

}
