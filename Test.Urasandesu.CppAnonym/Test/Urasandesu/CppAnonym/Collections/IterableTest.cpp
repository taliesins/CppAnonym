/* 
 * File: IterableTest.cpp
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

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Collections_IterableTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_SameValueSameSize_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2, 3;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_TRUE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_SameValueSameSize_01_1)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2, 3;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_TRUE(SequenceEqual(v1, v2)); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_SameValueSameSizeDifferentContainer_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;
        using std::list;

        vector<int> v1;
        v1 += 1, 2, 3;

        list<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_TRUE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_SameValueSameSizeDifferentContainer_01_1)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;
        using std::list;

        vector<int> v1;
        v1 += 1, 2, 3;

        list<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_TRUE(SequenceEqual(v1, v2)); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentSize_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2, 3;

        vector<int> v2;
        v2 += 1, 2;
        
        ASSERT_FALSE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentSize_01_1)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2, 3;

        vector<int> v2;
        v2 += 1, 2;
        
        ASSERT_FALSE(SequenceEqual(v1, v2)); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentSize_02)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_FALSE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentSize_02_1)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 2;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_FALSE(SequenceEqual(v1, v2)); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentValue_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 3, 2;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_FALSE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end())); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_DifferentValue_01_1)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v1;
        v1 += 1, 3, 2;

        vector<int> v2;
        v2 += 1, 2, 3;
        
        ASSERT_FALSE(SequenceEqual(v1, v2)); 
    }

    
    
    namespace _4032AB6C {

        struct Hoge
        {
            Hoge(int value) : m_value(value) { }
            int m_value;
        };

    }   // namespace _4032AB6C {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_WithSelector_01)
    {
        using _4032AB6C::Hoge;
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        auto v1 = vector<Hoge>();
        v1 += Hoge(1), Hoge(2), Hoge(3);

        auto v2 = vector<Hoge>();
        v2 += Hoge(1), Hoge(2), Hoge(3);

        auto equalTo = [](Hoge const &x, Hoge const &y) { return x.m_value == y.m_value; };
        ASSERT_TRUE(SequenceEqual(v1.begin(), v1.end(), v2.begin(), v2.end(), equalTo)); 
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceEqualTest_WithSelector_01_1)
    {
        using _4032AB6C::Hoge;
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        auto v1 = vector<Hoge>();
        v1 += Hoge(1), Hoge(2), Hoge(3);

        auto v2 = vector<Hoge>();
        v2 += Hoge(1), Hoge(2), Hoge(3);

        auto equalTo = [](Hoge const &x, Hoge const &y) { return x.m_value == y.m_value; };
        ASSERT_TRUE(SequenceEqual(v1, v2, equalTo)); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceHashValueTest_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using std::vector;

        vector<int const *> v;
        v.push_back(reinterpret_cast<int const *>(1));
        v.push_back(reinterpret_cast<int const *>(2));
        v.push_back(reinterpret_cast<int const *>(3));

#ifdef _M_IX86
        ASSERT_EQ(4216901971, SequenceHashValue(v.begin(), v.end())); 
#else
        ASSERT_EQ(11093822460243, SequenceHashValue(v.begin(), v.end())); 
#endif
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceHashValueTest_01_1)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using std::vector;

        vector<int const *> v;
        v.push_back(reinterpret_cast<int const *>(1));
        v.push_back(reinterpret_cast<int const *>(2));
        v.push_back(reinterpret_cast<int const *>(3));

#ifdef _M_IX86
        ASSERT_EQ(4216901971, SequenceHashValue(v));
#else
        ASSERT_EQ(11093822460243, SequenceHashValue(v));
#endif
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, ResizeIfAvailableTest_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        vector<int> v;
        {
            auto *p = ResizeIfAvailable(0, v);
            ASSERT_TRUE(p == nullptr);
        }
        {
            auto *p = ResizeIfAvailable(10, v);
            ASSERT_FALSE(p == nullptr);
            ASSERT_TRUE(p == &v[0]);
            auto i = 0;
            v[i++] = 9; v[i++] = 8; v[i++] = 7; v[i++] = 6; v[i++] = 5; 
            v[i++] = 4; v[i++] = 3; v[i++] = 2; v[i++] = 1; v[i++] = 0; 
            for (auto i = 0; i < 10; ++i)
                ASSERT_EQ(10 - i - 1, p[i]);
        }
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceToStringTest_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;
        using std::wstring;

        auto v = vector<BYTE>();
        v += 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89;
        ASSERT_EQ(wstring(L"b77a5c561934e089"), SequenceToString(v.begin(), v.end()));
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceToStringTest_02)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;
        using std::wstring;

        auto v = vector<BYTE>();
        v += 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89;
        auto actual = wstring(SequenceToString(v.begin(), v.end()));
        ASSERT_EQ(wstring(L"b77a5c561934e089"), actual);
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, SequenceToStringTest_03)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;
        using std::wstring;
        using std::wostringstream;

        auto v = vector<BYTE>();
        v += 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89;
        auto actual = wostringstream();
        actual << SequenceToString(v.begin(), v.end());
        ASSERT_EQ(wstring(L"b77a5c561934e089"), actual.str());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, FindIfTest_01)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::assign::operator +=;
        using std::vector;

        auto v = vector<int>();
        v += 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
        auto result = FindIf(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
        ASSERT_EQ(2, *result);
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, FindIfTest_02)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::adaptors::filtered;
        using boost::assign::operator +=;
        using std::vector;

        auto v = vector<int>();
        v += 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
        auto targets = v | filtered([](int i) { return i % 2 == 0; });
        auto result = FindIf(targets, [](int i) { return i % 3 == 0; });
        ASSERT_TRUE(result);
        ASSERT_EQ(6, result.get());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Collections_IterableTest, FindIfTest_03)
    {
        using namespace Urasandesu::CppAnonym::Collections;
        using boost::adaptors::filtered;
        using boost::assign::operator +=;
        using std::vector;

        auto v = vector<int>();
        v += 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
        auto targets1 = v | filtered([](int i) { return i % 2 == 0; });
        auto targets2 = targets1 | filtered([](int i) { return i % 3 == 0; });
        auto result = FindIf(targets2, [](int i) { return i % 5 == 0; });
        ASSERT_FALSE(result);
    }
}
