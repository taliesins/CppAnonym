/* 
 * File: SafeEnumTest.cpp
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

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SafeEnumTest.*
namespace {

    namespace _66D68309 {

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

                friend std::wostream &operator <<(std::wostream &os, type v)
                {
                    switch (v)
                    {
                        case HT_ITEM1: os << L"ITEM1"; break;
                        case HT_ITEM2: os << L"ITEM2"; break;
                        case HT_ITEM3: os << L"ITEM3"; break;
                        default:       os << L"UNREACHED"; break;
                    }
                    return os;
                }
            };

        }   // namespace HogeTypesDetail {

        typedef Urasandesu::CppAnonym::SafeEnum<HogeTypesDetail::HogeTypesDef> HogeTypes;

    }   // namespace _66D68309 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_SafeEnumTest, Test_01)
    {
        using namespace _66D68309;

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

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SafeEnumTest, Test_02)
    {
        using namespace _66D68309;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        auto hash = CreateHash(HogeTypes());

        auto hoge1 = HogeTypes::HT_ITEM2;
        auto hoge2 = HogeTypes::HT_ITEM2;
        ASSERT_EQ(hash(hoge1), hash(hoge2));
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SafeEnumTest, Test_03)
    {
        using namespace _66D68309;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        auto equalTo = CreateEqualTo(HogeTypes());

        auto hoge1 = HogeTypes::HT_ITEM2;
        auto hoge2 = HogeTypes::HT_ITEM2;
        ASSERT_TRUE(equalTo(hoge1, hoge2));
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SafeEnumTest, Test_04)
    {
        using namespace _66D68309;
        using namespace Urasandesu::CppAnonym::Utilities;
        using boost::unordered_map;
        
        auto map = unordered_map<HogeTypes, int, Hash<HogeTypes>, EqualTo<HogeTypes> >();
        map[HogeTypes::HT_ITEM1] = 42;
        map[HogeTypes::HT_ITEM2] = 10;

        ASSERT_EQ(2, map.size());
        ASSERT_EQ(42, map[HogeTypes::HT_ITEM1]);
        ASSERT_EQ(10, map[HogeTypes::HT_ITEM2]);
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SafeEnumTest, Test_05)
    {
        using namespace _66D68309;
        using namespace Urasandesu::CppAnonym::Utilities;
        using std::wostringstream;
        using std::wstring;
        
        auto hoge1 = HogeTypes::HT_ITEM2;

        auto oss = wostringstream();
        oss << hoge1;
        ASSERT_EQ(wstring(L"ITEM2"), oss.str());
    }
}
