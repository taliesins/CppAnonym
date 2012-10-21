#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Traits_ReplaceTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Traits_ReplaceTest, Test_01)
    {
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;

        BOOST_MPL_ASSERT((is_same<Replace<int, int, double>::type, double>));
        BOOST_MPL_ASSERT((is_same<Replace<char, int, double>::type, char>));
    }
}
