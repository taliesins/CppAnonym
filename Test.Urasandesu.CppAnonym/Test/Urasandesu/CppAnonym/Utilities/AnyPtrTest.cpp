#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AnyPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_AnyPtrTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AnyPtr p;
        ASSERT_TRUE(p.IsEmpty());
    }

    TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AnyPtr p(new int(10));
        ASSERT_FALSE(p.IsEmpty());
        ASSERT_TRUE(p.Is<int *>());

        int *pInt = p;
        ASSERT_EQ(10, *pInt);
    }
}
