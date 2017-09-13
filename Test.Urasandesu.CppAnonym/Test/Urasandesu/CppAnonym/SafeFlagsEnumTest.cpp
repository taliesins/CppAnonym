/* 
 * File: SafeFlagsEnumTest.cpp
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

#ifndef URASANDESU_CPPANONYM_SAFEFLAGSENUM_H
#include <Urasandesu/CppAnonym/SafeFlagsEnum.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SafeFlagsEnumTest.*
namespace {

    namespace _464C8113 {

        namespace HogeTypesDetail {

            struct HogeTypesDef
            {
                enum type
                {
                    HT_ITEM1,
                    HT_ITEM2,
                    HT_ITEM3,
                    HT_UNREACHED
                };
            };

        }   // namespace HogeTypesDetail {

        typedef Urasandesu::CppAnonym::SafeFlagsEnum<HogeTypesDetail::HogeTypesDef> HogeTypes;

    }   // namespace _464C8113 {

    TEST(Urasandesu_CppAnonym_SafeFlagsEnumTest, Test_01)
    {
        using namespace _464C8113;

        auto v = HogeTypes(HogeTypes::HT_ITEM2);
        ASSERT_TRUE(v == HogeTypes::HT_ITEM2);
        ASSERT_TRUE(v != HogeTypes::HT_ITEM1);
        ASSERT_TRUE(v < HogeTypes::HT_ITEM3);
        ASSERT_TRUE(v <= HogeTypes::HT_ITEM2);
        ASSERT_TRUE(v <= HogeTypes::HT_ITEM3);
        ASSERT_TRUE(v > HogeTypes::HT_ITEM1);
        ASSERT_TRUE(v >= HogeTypes::HT_ITEM2);
        ASSERT_TRUE(v >= HogeTypes::HT_ITEM1);
    }

    
    
    namespace _76A57C3C {

        namespace PiyoTypesDetail {

            struct PiyoTypesDef
            {
                enum type
                {
                    PT_NONE = 0,
                    PT_ITEM1 = 1,
                    PT_ITEM2 = 2,
                    PT_ITEM3 = 4,
                    PT_UNREACHED = 8
                };

                CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type)

            };

        }   // namespace PiyoTypesDetail {

        typedef Urasandesu::CppAnonym::SafeFlagsEnum<PiyoTypesDetail::PiyoTypesDef> PiyoTypes;

    }   // namespace _76A57C3C {

    TEST(Urasandesu_CppAnonym_SafeFlagsEnumTest, Test_02)
    {
        using namespace _76A57C3C;

        {
            auto v = PiyoTypes(PiyoTypes::PT_ITEM1 | PiyoTypes::PT_ITEM2);
            ASSERT_TRUE((v & PiyoTypes::PT_ITEM2) == PiyoTypes::PT_ITEM2);
            ASSERT_FALSE((v & PiyoTypes::PT_ITEM3) == PiyoTypes::PT_ITEM3);
        }
        {
            auto v1 = PiyoTypes(6ul);
            ASSERT_TRUE((v1 & PiyoTypes::PT_ITEM2) == PiyoTypes::PT_ITEM2);
            ASSERT_FALSE((v1 & PiyoTypes::PT_ITEM1) == PiyoTypes::PT_ITEM1);

            auto v2 = PiyoTypes(0ul);
            v2 |= v1 & ~PiyoTypes::PT_ITEM2;
            ASSERT_FALSE((v2 & PiyoTypes::PT_ITEM2) == PiyoTypes::PT_ITEM2);
            ASSERT_TRUE((v2 & PiyoTypes::PT_ITEM3) == PiyoTypes::PT_ITEM3);

            auto v3 = v1;
            v3 &= ~PiyoTypes::PT_ITEM2;
            ASSERT_FALSE((v3 & PiyoTypes::PT_ITEM2) == PiyoTypes::PT_ITEM2);
            ASSERT_TRUE((v3 & PiyoTypes::PT_ITEM3) == PiyoTypes::PT_ITEM3);
        }
    }
}
