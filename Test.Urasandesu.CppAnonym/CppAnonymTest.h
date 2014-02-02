/* 
 * File: CppAnonymTest.h
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


#pragma once
#ifndef CPPANONYMTEST_H
#define CPPANONYMTEST_H

#include <gtest/gtest.h>

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include <Urasandesu/CppAnonym/StackTrace.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#define CPPANONYM_TEST(test_case_name, test_name) \
    class GTEST_TEST_CLASS_NAME_(test_case_name, test_name); \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)); \
    TEST(test_case_name, test_name) \
    { \
        using namespace Urasandesu::CppAnonym; \
        try \
        { \
            CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)()); \
        } \
        catch (CppAnonymException &e) \
        { \
            std::cout << boost::diagnostic_information(e) << std::endl; \
            throw; \
        } \
        catch (...) \
        { \
            std::cout << boost::diagnostic_information(boost::current_exception()) << std::endl; \
            throw; \
        } \
    } \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name))

#endif  // #ifndef CPPANONYMTEST_H
