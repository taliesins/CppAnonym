#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
#include <Urasandesu/CppAnonym/Utilities/Hash.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_HashTest.*
namespace {

    TEST(Urasandesu_CppAnonym_HashTest, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym::Utilities;
        
        typedef Hash<fs::path> PathHash;
        PathHash hash;

        fs::path path1(L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\");
        fs::path path2(L"c:\\windows\\microsoft.net\\framework\\v2.0.50727\\");
        ASSERT_EQ(hash(path1), hash(path2));
    }
}
