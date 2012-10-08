#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTO_PTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_AutoPtr.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_AutoPtr, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AutoPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_AutoPtr, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        AutoPtr<int> p(new int(10));
        ASSERT_TRUE(p);
        ASSERT_EQ(10, *p);
    }

    
    
    
    
    namespace _80607A18 {

        using namespace Urasandesu::CppAnonym::Utilities;

        struct DefaultDeleterWithCount : 
            DefaultDeleter
        {
            template<class T>
            void operator()(T *p)
            {
                DefaultDeleter::operator()(p);
                ++m_count;
            }

            static int m_count;
        };

        int DefaultDeleterWithCount::m_count = 0;

    }   // namespace _80607A18 {

    TEST(Urasandesu_CppAnonym_Utilities_AutoPtr, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _80607A18;

        DefaultDeleterWithCount deleter;

        { AutoPtr<int> p(new int(10), deleter); }
        { AutoPtr<int> p(new int(10), deleter); }
        { AutoPtr<int> p(new int(10), deleter); }

        ASSERT_EQ(3, DefaultDeleterWithCount::m_count);
    }
}
