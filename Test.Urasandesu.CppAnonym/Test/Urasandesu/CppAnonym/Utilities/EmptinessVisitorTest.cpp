/* 
 * File: EmptinessVisitorTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_EMPTINESSVISITOR_H
#include <Urasandesu/CppAnonym/Utilities/EmptinessVisitor.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_EmptinessVisitorTest.*
namespace {

    namespace _3DA98A5D {

        using boost::apply_visitor;
        using boost::static_visitor;
        using boost::variant;

        typedef variant<
            boost::blank,
            bool,
            BYTE, 
            DOUBLE,
            int const *
        > Hoge;

    }   // namespace _3DA98A5D {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_EmptinessVisitorTest, Test_01)
    {
        using namespace _3DA98A5D;
        using Urasandesu::CppAnonym::Utilities::EmptinessVisitor;

        {
            auto hoge = Hoge();
            ASSERT_TRUE(apply_visitor(EmptinessVisitor(), hoge));
        }
        {
            auto hoge = Hoge(true);
            ASSERT_FALSE(apply_visitor(EmptinessVisitor(), hoge));
        }
        {
            auto hoge = Hoge(static_cast<BYTE>(42));
            ASSERT_FALSE(apply_visitor(EmptinessVisitor(), hoge));
        }
        {
            auto hoge = Hoge(3.14);
            ASSERT_FALSE(apply_visitor(EmptinessVisitor(), hoge));
        }
        {
            auto i = 42;
            auto hoge = Hoge(&i);
            ASSERT_FALSE(apply_visitor(EmptinessVisitor(), hoge));
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_EmptinessVisitorTest, Test_02)
    {
        using namespace _3DA98A5D;
        using Urasandesu::CppAnonym::Utilities::Empty;

        {
            auto hoge = Hoge();
            ASSERT_TRUE(Empty(hoge));
        }
        {
            auto hoge = Hoge(true);
            ASSERT_FALSE(Empty(hoge));
        }
        {
            auto hoge = Hoge(static_cast<BYTE>(42));
            ASSERT_FALSE(Empty(hoge));
        }
        {
            auto hoge = Hoge(3.14);
            ASSERT_FALSE(Empty(hoge));
        }
        {
            auto i = 42;
            auto hoge = Hoge(&i);
            ASSERT_FALSE(Empty(hoge));
        }
    }
}
