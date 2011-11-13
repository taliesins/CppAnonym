#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include "Urasandesu/CppAnonym/CppAnonymException.h"
#endif

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include "Urasandesu/CppAnonym/StackFrame.h"
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include "Urasandesu/CppAnonym/StackTrace.h"
#endif

namespace {

    // CppAnonymTest.exe --gtest_filter=CppAnonymTestSuite.CppAnonymExceptionTest
    TEST(CppAnonymTestSuite, CppAnonymExceptionTest)
    {
        using namespace std;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        
        try
        {
            BOOST_THROW_EXCEPTION(CppAnonymException());
        }
        catch (CppAnonymException &e)
        {
            string msg = diagnostic_information(e);
            cout << msg << endl;
            string expectContaining = "testing";
            ASSERT_TRUE(msg.find(expectContaining) != string::npos);
        }
    }
}
