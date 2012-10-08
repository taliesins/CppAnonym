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

    
    
    
    
    namespace _DE3EFDB5 {

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

    }   // namespace _DE3EFDB5 {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); }
        { SemiAutoPtr<int> p(new int(10), deleter); }
        { SemiAutoPtr<int> p(new int(10), deleter); }

        ASSERT_EQ(3, Deleter::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_04)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }

        ASSERT_EQ(0, Deleter::m_count);

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_05)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }

        ASSERT_EQ(3, Deleter::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_06)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef SemiAutoPtr<int>::holder_impl_type<Deleter, Deleter>::type HolderImpl;

        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); }

        ASSERT_EQ(6, Deleter::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_07)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        std::vector<int *> garbages;
        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef SemiAutoPtr<int>::holder_impl_type<Deleter, Deleter>::type HolderImpl;

        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); garbages.push_back(p.Get()); p.SetManual(); }

        ASSERT_EQ(3, Deleter::m_count);

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_08)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef SemiAutoPtr<int>::holder_impl_type<Deleter, Deleter>::type HolderImpl;

        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); p.SetManual(); p.SetAuto(); }

        ASSERT_EQ(6, Deleter::m_count);
    }
}
