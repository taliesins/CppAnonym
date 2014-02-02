/* 
 * File: IsAnyTTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_H
#include <Urasandesu/CppAnonym/Utilities/IsAnyT.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_IsAnyTTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_IsAnyTTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using boost::any_cast;
        using boost::shared_ptr;
        using std::find_if;

        typedef std::vector<boost::any> AnyVector;

        AnyVector v;
        v.push_back(shared_ptr<int>(new int(10)));
        v.push_back(shared_ptr<char>(new char('a')));
        v.push_back(shared_ptr<double>(new double(20.)));
        v.push_back(shared_ptr<float>(new float(30.f)));
        
        AnyVector::iterator i, i_end = v.end();
        i = find_if(v.begin(), v.end(), IsAnyT<shared_ptr<char> >()); 
        ASSERT_TRUE(i != i_end);
        ASSERT_EQ('a', *any_cast<shared_ptr<char> >(*i));
    }
}
