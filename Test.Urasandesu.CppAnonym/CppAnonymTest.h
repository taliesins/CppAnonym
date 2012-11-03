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