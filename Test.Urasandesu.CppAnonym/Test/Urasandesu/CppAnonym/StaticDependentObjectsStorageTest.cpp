﻿#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_StaticDependentObjectsStorageTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_StaticDependentObjectsStorageTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef StaticDependentObjectsStorage<int, long, float, double > MyStorage;

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

        struct Counter0 : 
            SurvivalCounter<BasicCounter<Tag, 0> >
        {
            Counter0() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Counter0() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }
        };

        struct Counter1 : 
            SurvivalCounter<BasicCounter<Tag, 1> >
        {
            Counter1() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Counter1() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }
        };

        struct Counter2 : 
            SurvivalCounter<BasicCounter<Tag, 2> >
        {
            Counter2() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Counter2() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }
        };

    }   // namespace _C317D758 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_StaticDependentObjectsStorageTest, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace _C317D758;

        typedef StaticDependentObjectsStorage<Counter0, Counter1, Counter2> MyStorage;
        typedef MyStorage::host_type Host;
        Counter1 &counter1 = MyStorage::Object<Counter1>();
        Counter0 &counter0 = MyStorage::Object<Counter0>();
        Counter2 &counter2 = MyStorage::Object<Counter2>();

        ASSERT_EQ(3, OrderChecker::Instance().m_ctorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&counter1), OrderChecker::Instance().m_ctorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(&counter0), OrderChecker::Instance().m_ctorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(&counter2), OrderChecker::Instance().m_ctorOrder[2]);
        ASSERT_EQ(0, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(1, Counter0::Instance().Value());
        ASSERT_EQ(1, Counter1::Instance().Value());
        ASSERT_EQ(1, Counter2::Instance().Value());

        StaticDependentObjectsStorageDetail::HostAccessor<Counter0, Counter1, Counter2>::Host().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&counter2), OrderChecker::Instance().m_dtorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(&counter1), OrderChecker::Instance().m_dtorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(&counter0), OrderChecker::Instance().m_dtorOrder[2]);
        ASSERT_EQ(0, Counter0::Instance().Value());
        ASSERT_EQ(0, Counter1::Instance().Value());
        ASSERT_EQ(0, Counter2::Instance().Value());
    }

}
