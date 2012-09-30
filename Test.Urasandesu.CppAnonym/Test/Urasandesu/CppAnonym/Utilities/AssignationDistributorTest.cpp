#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributor.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_AssignationDistributorTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, RawPointerTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, RawPointerTest_01) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE bufSrc[sizeof(Tester *)];
        ASSERT_EQ(0, Tester::Counter().Value());

        BYTE bufDst[sizeof(Tester *)];
        ASSERT_EQ(0, Tester::Counter().Value());

        AssignationDistributor<Tester *>::Assign(bufDst, bufSrc);
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, RawPointerTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, RawPointerTest_01) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE bufSrc[sizeof(Tester *)];
        Tester *pSrc = new Tester();
        ::memcpy_s(bufSrc, sizeof(Tester *), &pSrc, sizeof(Tester *));
        ASSERT_EQ(1, Tester::Counter().Value());

        BYTE bufDst[sizeof(Tester *)];
        Tester *pDst = new Tester();
        ::memcpy_s(bufDst, sizeof(Tester *), &pDst, sizeof(Tester *));
        ASSERT_EQ(2, Tester::Counter().Value());

        AssignationDistributor<Tester *>::Assign(bufDst, bufSrc);
        ASSERT_EQ(2, Tester::Counter().Value());

        delete pSrc;
        ASSERT_EQ(1, Tester::Counter().Value());

        delete pDst;
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, NotPodTest_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, NotPodTest_01) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE bufSrc[sizeof(shared_ptr<Tester>)] = { 0 };
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE bufDst[sizeof(shared_ptr<Tester>)] = { 0 };
        ASSERT_EQ(0, Tester::Counter().Value());

        AssignationDistributor<shared_ptr<Tester> >::Assign(bufDst, bufSrc);
        ASSERT_EQ(0, Tester::Counter().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, NotPodTest_02)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, NotPodTest_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        BYTE bufSrc[sizeof(shared_ptr<Tester>)];
        shared_ptr<Tester> pSrc(new Tester());
        ::memcpy_s(bufSrc, sizeof(shared_ptr<Tester>), &pSrc, sizeof(shared_ptr<Tester>));
        ASSERT_EQ(1, Tester::Counter().Value());
        
        BYTE bufDst[sizeof(shared_ptr<Tester>)];
        shared_ptr<Tester> pDst(new Tester());
        ::memcpy_s(bufDst, sizeof(shared_ptr<Tester>), &pDst, sizeof(shared_ptr<Tester>));
        ASSERT_EQ(2, Tester::Counter().Value());

        shared_ptr<Tester> &pSrc_ = *reinterpret_cast<shared_ptr<Tester> *>(bufSrc);
        shared_ptr<Tester> &pDst_ = *reinterpret_cast<shared_ptr<Tester> *>(bufDst);

        ASSERT_EQ(1, pSrc_.use_count());
        ASSERT_EQ(1, pDst_.use_count());
        ASSERT_NE(pSrc_, pDst_);

        AssignationDistributor<shared_ptr<Tester> >::Assign(bufDst, bufSrc);
        ASSERT_EQ(1, Tester::Counter().Value());
        
        ASSERT_EQ(2, pSrc_.use_count());
        ASSERT_EQ(2, pDst_.use_count());
        ASSERT_EQ(pSrc_, pDst_);
        
        pSrc_.~shared_ptr<Tester>();
        pDst_.~shared_ptr<Tester>();
        ::ZeroMemory(&pSrc, sizeof(shared_ptr<Tester>));  // suppress original auto destruction
        ::ZeroMemory(&pDst, sizeof(shared_ptr<Tester>));  // suppress original auto destruction
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, NotPodTest_03)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AssignationDistributorTest, NotPodTest_02) Tag;
        typedef ConstructionTester<Tag, 0> Tester;
        ASSERT_EQ(0, Tester::Counter().Value());
        
        shared_ptr<Tester> pSrc(new Tester());
        ASSERT_EQ(1, Tester::Counter().Value());
        
        shared_ptr<Tester> pDst(new Tester());
        ASSERT_EQ(2, Tester::Counter().Value());

        ASSERT_EQ(1, pSrc.use_count());
        ASSERT_EQ(1, pDst.use_count());
        ASSERT_NE(pSrc, pDst);

        AssignationDistributor<shared_ptr<Tester> >::Assign(&pSrc, &pDst);
        ASSERT_EQ(1, Tester::Counter().Value());

        ASSERT_EQ(2, pSrc.use_count());
        ASSERT_EQ(2, pDst.use_count());
        ASSERT_EQ(pSrc, pDst);
    }

}
