#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
#include <Urasandesu/CppAnonym/Utilities/AnyPtr.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_AnyPtrTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, EmptyTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AnyPtr p;
        ASSERT_TRUE(p.IsEmpty());
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, TypeCheckAndCastTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AnyPtr p1(new int(42));
        ASSERT_FALSE(p1.IsEmpty());
        ASSERT_TRUE(p1.Is<int *>());
        ASSERT_FALSE(p1.Is<long *>());

        int *p2 = p1;
        ASSERT_EQ(42, *p2);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_AnyPtrTest, TypeCheckAndCastTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        int const *p = new int(42);
        AnyPtr p1(p);
        ASSERT_FALSE(p1.IsEmpty());
        ASSERT_TRUE(p1.Is<int const *>());
        ASSERT_FALSE(p1.Is<int *>());

        int const *p2 = p1;
        ASSERT_EQ(42, *p2);
    }
}
