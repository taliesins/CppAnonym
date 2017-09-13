/* 
 * File: StaticDependentObjectsStorageTest.cpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#include "stdafx.h"
#include <gtest/gtest.h>

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
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

            std::vector<int> m_ctorSeq;
            std::vector<int> m_dtorSeq;
        };

        struct Counter0 : 
            SurvivalCounter<BasicCounter<Tag, 0> >
        {
            Counter0() { OrderChecker::Instance().m_ctorSeq.push_back(reinterpret_cast<int>(this)); }
            ~Counter0() { OrderChecker::Instance().m_dtorSeq.push_back(reinterpret_cast<int>(this)); }
        };

        struct Counter1 : 
            SurvivalCounter<BasicCounter<Tag, 1> >
        {
            Counter1() { OrderChecker::Instance().m_ctorSeq.push_back(reinterpret_cast<int>(this)); }
            ~Counter1() { OrderChecker::Instance().m_dtorSeq.push_back(reinterpret_cast<int>(this)); }
        };

        struct Counter2 : 
            SurvivalCounter<BasicCounter<Tag, 2> >
        {
            Counter2() { OrderChecker::Instance().m_ctorSeq.push_back(reinterpret_cast<int>(this)); }
            ~Counter2() { OrderChecker::Instance().m_dtorSeq.push_back(reinterpret_cast<int>(this)); }
        };

    }   // namespace _C317D758 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_StaticDependentObjectsStorageTest, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace _C317D758;

        typedef StaticDependentObjectsStorage<Counter0, Counter1, Counter2> MyStorage;
        typedef StaticDependentObjectsStorageDetail::HostAccessor<Counter0, Counter1, Counter2> MyStorageHostAccessor;
        typedef MyStorage::host_type Host;
        Counter1 &counter1 = MyStorage::Object<Counter1>();
        Counter0 &counter0 = MyStorage::Object<Counter0>();
        Counter2 &counter2 = MyStorage::Object<Counter2>();

        ASSERT_EQ(3, OrderChecker::Instance().m_ctorSeq.size());
        ASSERT_EQ(reinterpret_cast<int>(&counter1), OrderChecker::Instance().m_ctorSeq[0]);
        ASSERT_EQ(reinterpret_cast<int>(&counter0), OrderChecker::Instance().m_ctorSeq[1]);
        ASSERT_EQ(reinterpret_cast<int>(&counter2), OrderChecker::Instance().m_ctorSeq[2]);
        ASSERT_EQ(0, OrderChecker::Instance().m_dtorSeq.size());
        ASSERT_EQ(1, Counter0::Instance().Value());
        ASSERT_EQ(1, Counter1::Instance().Value());
        ASSERT_EQ(1, Counter2::Instance().Value());

        MyStorageHostAccessor::Host().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorSeq.size());
        ASSERT_EQ(reinterpret_cast<int>(&counter2), OrderChecker::Instance().m_dtorSeq[0]);
        ASSERT_EQ(reinterpret_cast<int>(&counter1), OrderChecker::Instance().m_dtorSeq[1]);
        ASSERT_EQ(reinterpret_cast<int>(&counter0), OrderChecker::Instance().m_dtorSeq[2]);
        ASSERT_EQ(0, Counter0::Instance().Value());
        ASSERT_EQ(0, Counter1::Instance().Value());
        ASSERT_EQ(0, Counter2::Instance().Value());
        
        // Restore static area to work the debug heap correctly.
        new(&MyStorageHostAccessor::Host())Host();
    }

}
