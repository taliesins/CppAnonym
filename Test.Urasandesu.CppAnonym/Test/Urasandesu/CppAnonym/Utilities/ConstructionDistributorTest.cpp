/* 
 * File: ConstructionDistributorTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.h>
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
