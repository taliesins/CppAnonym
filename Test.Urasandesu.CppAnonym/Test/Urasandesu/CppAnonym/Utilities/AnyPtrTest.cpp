/* 
 * File: AnyPtrTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#include <Urasandesu/CppAnonym/Utilities/AnyPtr.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_AnyPtrTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, EmptyTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        auto p = AnyPtr();
        ASSERT_TRUE(!p);
        ASSERT_FALSE(p);
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        {
            auto p = AnyPtr();
            ASSERT_EQ(0, Tester::Instance().Value());
            ASSERT_FALSE(p);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionTTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionTTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());
        
        {
            auto p = AnyPtr(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p);
            ASSERT_EQ(42, p.Get<Tester *>()->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionT_TDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionT_TDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { auto p = AnyPtr(new int(10), Tester()); }
        { auto p = AnyPtr(new int(10), Tester()); }
        { auto p = AnyPtr(new int(10), Tester()); }

        ASSERT_EQ(3, Tester::Instance().Value());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionT_TD_ImplDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ConstructionT_TD_ImplDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        typedef AnyPtr::make_holder_impl<int, Tester, Tester>::type HolderImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        { auto p = AnyPtr(new HolderImpl(new int(10), Tester(), Tester())); }
        { auto p = AnyPtr(new HolderImpl(new int(10), Tester(), Tester())); }
        { auto p = AnyPtr(new HolderImpl(new int(10), Tester(), Tester())); }

        ASSERT_EQ(6, Tester::Instance().Value());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, CopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, CopyConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            auto p1 = AnyPtr(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p1);
            ASSERT_EQ(42, p1.Get<Tester *>()->m_value);
            auto p2 = AnyPtr(p1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p2);
            ASSERT_EQ(42, p2.Get<Tester *>()->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ImplicitCopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, ImplicitCopyConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            auto p1 = AnyPtr(static_cast<Tester const *>(new Tester(42)));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p1);
            ASSERT_EQ(42, p1.Get<Tester const *>()->m_value);
            auto p2 = AnyPtr(p1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p2);
            ASSERT_EQ(42, p2.Get<Tester const *>()->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, AssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AnyPtrTest, AssignTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            auto const p1 = AnyPtr(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p1);
            ASSERT_EQ(42, p1.Get<Tester *>()->m_value);
            auto p2 = AnyPtr();
            p2 = p1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(p2);
            ASSERT_EQ(42, p2.Get<Tester *>()->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, TypeCheckAndCastTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AnyPtr p1(new int(42));
        ASSERT_FALSE(!p1);
        ASSERT_TRUE(p1);
        ASSERT_TRUE(p1.Is<int *>());
        ASSERT_FALSE(p1.Is<long *>());

        int *p2 = p1.Get<int *>();
        ASSERT_EQ(42, *p2);
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, TypeCheckAndCastTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        int const *p = new int(42);
        AnyPtr p1(p);
        ASSERT_FALSE(!p1);
        ASSERT_TRUE(p1);
        ASSERT_TRUE(p1.Is<int const *>());
        ASSERT_FALSE(p1.Is<int *>());

        int const *p2 = p1.Get<int const *>();
        ASSERT_EQ(42, *p2);
    }
}
