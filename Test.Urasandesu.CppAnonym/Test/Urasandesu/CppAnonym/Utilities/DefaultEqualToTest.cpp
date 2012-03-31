#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTEQUALTO_H
#include <Urasandesu/CppAnonym/Utilities/DefaultEqualTo.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_DefaultEqualToTest.*
namespace {

    TEST(Urasandesu_CppAnonym_DefaultEqualToTest, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        typedef DefaultEqualTo<fs::path, fs::path> EqualTo;
        EqualTo equalTo;

        fs::path path1(L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\");
        fs::path path2(L"c:\\windows\\microsoft.net\\framework\\v2.0.50727\\");
        ASSERT_TRUE(equalTo(path1, path2));
    }
}
