/* 
 * File: PointerVisitorTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_POINTERVISITOR_H
#include <Urasandesu/CppAnonym/Utilities/PointerVisitor.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_PointerVisitorTest.*
namespace {

    namespace _F3D8FAC7 {

        using boost::apply_visitor;
        using boost::static_visitor;
        using boost::variant;

        typedef variant<
            boost::blank,
            bool *,
            BYTE *, 
            DOUBLE *,
            int const *
        > Hoge;

    }   // namespace _F3D8FAC7 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_PointerVisitorTest, Test_01)
    {
        using namespace _F3D8FAC7;
        using Urasandesu::CppAnonym::Utilities::PointerVisitor;

        {
            auto hoge = Hoge();
            ASSERT_TRUE(apply_visitor(PointerVisitor(), hoge) == nullptr);
        }
        {
            auto v = true;
            auto hoge = Hoge(&v);
            ASSERT_TRUE(apply_visitor(PointerVisitor(), hoge) == &v);
        }
        {
            auto v = static_cast<BYTE>(42);
            auto hoge = Hoge(&v);
            ASSERT_TRUE(apply_visitor(PointerVisitor(), hoge) == &v);
        }
        {
            auto v = 3.14;
            auto hoge = Hoge(&v);
            ASSERT_TRUE(apply_visitor(PointerVisitor(), hoge) == &v);
        }
        {
            auto v = 42;
            auto hoge = Hoge(&v);
            ASSERT_TRUE(apply_visitor(PointerVisitor(), hoge) == &v);
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_PointerVisitorTest, Test_02)
    {
        using namespace _F3D8FAC7;
        using Urasandesu::CppAnonym::Utilities::GetPointer;

        {
            auto hoge = Hoge();
            ASSERT_TRUE(GetPointer(hoge) == nullptr);
        }
        {
            auto v = true;
            auto hoge = Hoge(&v);
            ASSERT_TRUE(GetPointer(hoge) == &v);
        }
        {
            auto v = static_cast<BYTE>(42);
            auto hoge = Hoge(&v);
            ASSERT_TRUE(GetPointer(hoge) == &v);
        }
        {
            auto v = 3.14;
            auto hoge = Hoge(&v);
            ASSERT_TRUE(GetPointer(hoge) == &v);
        }
        {
            auto v = 42;
            auto hoge = Hoge(&v);
            ASSERT_TRUE(GetPointer(hoge) == &v);
        }
    }
}
