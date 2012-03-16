#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_CppAnonymArgumentExceptionTest.*
namespace {

    TEST(Urasandesu_CppAnonym_CppAnonymArgumentExceptionTest, Test_01)
    {
        using namespace std;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        
        try
        {
            BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"hoge", L"paramName"));
        }
        catch (CppAnonymException &e)
        {
            string msg = diagnostic_information(e);
            //cout << msg << endl;
            string expectContaining = "paramName";
            ASSERT_TRUE(msg.find(expectContaining) != string::npos);
        }
    }
}
