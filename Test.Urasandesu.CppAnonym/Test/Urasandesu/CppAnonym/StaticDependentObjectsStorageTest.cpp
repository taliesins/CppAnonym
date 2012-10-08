#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_StaticDependentObjectsStorageTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_StaticDependentObjectsStorageTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef StaticDependentObjectsStorage<mpl::vector<int, long, float, double> > MyStorage;

        MyStorage::Object<int>() = 10;
        MyStorage::Object<long>() = 20L;
        MyStorage::Object<float>() = 30.f;
        MyStorage::Object<double>() = 40.;

        ASSERT_EQ(10, MyStorage::Object<int>());
        ASSERT_EQ(20L, MyStorage::Object<long>());
        ASSERT_EQ(30.f, MyStorage::Object<float>());
        ASSERT_EQ(40., MyStorage::Object<double>());
    }





    namespace _C317D758 {

        struct Tag;

        struct OrderChecker
        {
            static OrderChecker &Instance()
            {
                static OrderChecker checker;
                return checker;
            }

            std::vector<int> m_ctorOrder;
            std::vector<int> m_dtorOrder;
        };

        struct Tester0 : 
            ConstructionTester<Tag, 0>
        {
            Tester0() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Tester0() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }
        };

        struct Tester1 : 
            ConstructionTester<Tag, 1>
        {
            Tester1() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Tester1() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }
        };

        struct Tester2 : 
            ConstructionTester<Tag, 2>
        {
            Tester2() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Tester2() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }
        };

    }   // namespace _C317D758 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_StaticDependentObjectsStorageTest, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace _C317D758;

        typedef mpl::vector<Tester0, Tester1, Tester2> Types;
        typedef StaticDependentObjectsStorage<Types> MyStorage;
        typedef MyStorage::host_type Host;
        Tester1 &tester1 = MyStorage::Object<Tester1>();
        Tester0 &tester0 = MyStorage::Object<Tester0>();
        Tester2 &tester2 = MyStorage::Object<Tester2>();

        ASSERT_EQ(3, OrderChecker::Instance().m_ctorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&tester1), OrderChecker::Instance().m_ctorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(&tester0), OrderChecker::Instance().m_ctorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(&tester2), OrderChecker::Instance().m_ctorOrder[2]);
        ASSERT_EQ(0, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(1, Tester0::Counter().Value());
        ASSERT_EQ(1, Tester1::Counter().Value());
        ASSERT_EQ(1, Tester2::Counter().Value());

        StaticDependentObjectsStorageDetail::Host<Types>().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&tester2), OrderChecker::Instance().m_dtorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(&tester1), OrderChecker::Instance().m_dtorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(&tester0), OrderChecker::Instance().m_dtorOrder[2]);
        ASSERT_EQ(0, Tester0::Counter().Value());
        ASSERT_EQ(0, Tester1::Counter().Value());
        ASSERT_EQ(0, Tester2::Counter().Value());
    }
}
