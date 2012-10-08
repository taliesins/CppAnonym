#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_SemiAutoPtr.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        SemiAutoPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        SemiAutoPtr<int> p(new int(10));
        ASSERT_TRUE(p);
        ASSERT_EQ(10, *p);
    }

    
    
    
    
    namespace _8ADF83E1 {

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

    }   // namespace _8ADF83E1 {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _8ADF83E1;

        DefaultDeleterWithCount::m_count = 0;
        DefaultDeleterWithCount deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); }
        { SemiAutoPtr<int> p(new int(10), deleter); }
        { SemiAutoPtr<int> p(new int(10), deleter); }

        ASSERT_EQ(3, DefaultDeleterWithCount::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_04)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _8ADF83E1;

        std::vector<int *> garbages;
        DefaultDeleterWithCount::m_count = 0;
        DefaultDeleterWithCount deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }

        ASSERT_EQ(0, DefaultDeleterWithCount::m_count);

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_05)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _8ADF83E1;

        DefaultDeleterWithCount::m_count = 0;
        DefaultDeleterWithCount deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }

        ASSERT_EQ(3, DefaultDeleterWithCount::m_count);
    }
}
