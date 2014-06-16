/* 
 * File: VersionTest.cpp
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

#ifndef URASANDESU_CPPANONYM_VERSION_H
#include <Urasandesu/CppAnonym/Version.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_VersionTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_VersionTest, Test_01)
    {
        using Urasandesu::CppAnonym::Version;
        using std::wostringstream;
        using std::wstring;

        auto version = Version();
        auto oss = wostringstream();
        oss << version;
        ASSERT_EQ(wstring(L"0.0"), oss.str());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_VersionTest, Test_02)
    {
        using Urasandesu::CppAnonym::Version;
        using std::wostringstream;
        using std::wstring;

        auto version = Version(4, 0, 30319, 33440);
        auto oss = wostringstream();
        oss << version;
        ASSERT_EQ(wstring(L"4.0.30319.33440"), oss.str());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_VersionTest, Test_03)
    {
        using Urasandesu::CppAnonym::Version;

        ASSERT_EQ(Version(4, 0, 30319, 33440), Version(4, 0, 30319, 33440));
        ASSERT_NE(Version(4, 0, 30319, 33441), Version(4, 0, 30319, 33440));
        ASSERT_LT(Version(4, 0, 30319, 33440), Version(4, 0, 30319, 33441));
        ASSERT_LE(Version(4, 0, 30319, 33441), Version(4, 0, 30319, 33441));
        ASSERT_GT(Version(4, 0, 30319, 33441), Version(4, 0, 30319, 33440));
        ASSERT_GE(Version(4, 0, 30319, 33440), Version(4, 0, 30319, 33440));
    }
}
