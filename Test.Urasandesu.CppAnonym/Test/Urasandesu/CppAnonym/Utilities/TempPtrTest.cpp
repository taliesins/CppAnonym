#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_TempPtrTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        TempPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        TempPtr<int> p(new int(10));
        ASSERT_TRUE(p);
        ASSERT_EQ(10, *p);
    }

    
    
    
    
    namespace _85245FB6 {

        using namespace Urasandesu::CppAnonym::Utilities;

        struct DefaultDeleterWithCount : 
            DefaultDeleter
        {
            DefaultDeleterWithCount() : 
                m_persistCalled(false)
            { }

            template<class T>
            void operator()(T *p)
            {
                DefaultDeleter::operator()(p);
                ++m_count;
            }

            bool m_persistCalled;
            static int m_count;
        };

        int DefaultDeleterWithCount::m_count = 0;

        struct Handler
        {
            Handler(DefaultDeleterWithCount &deleter) : 
                m_pDeleter(&deleter)
            { }
            
            typedef TempPtr<int> sender_type;
            void operator()(sender_type *pSender, void *pArg)
            {
                sender_type &p = *pSender;
                p.Persist();    // test for no infinite loop...
                m_pDeleter->m_persistCalled = true;
            }

            DefaultDeleterWithCount *m_pDeleter;
        };

    }   // namespace _85245FB6 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        { 
            TempPtr<int> p(new int(10), deleter);
            p.AddPersistedHandler(Handler(deleter));
            ASSERT_FALSE(p.IsPersisted());
            ASSERT_FALSE(deleter.m_persistCalled);
            p.Persist();
            garbages.push_back(p.Get());
            ASSERT_TRUE(p.IsPersisted());
            ASSERT_TRUE(deleter.m_persistCalled);
        }

        ASSERT_EQ(0, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_04)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef TempPtr<int>::persisted_handler_impl_type<Handler, Deleter>::type PersistedHandlerImpl;

        { 
            TempPtr<int> p(new int(10), deleter);
            p.AddPersistedHandler(new PersistedHandlerImpl(Handler(deleter), deleter));
            ASSERT_FALSE(p.IsPersisted());
            ASSERT_FALSE(deleter.m_persistCalled);
            p.Persist();
            garbages.push_back(p.Get());
            ASSERT_TRUE(p.IsPersisted());
            ASSERT_TRUE(deleter.m_persistCalled);
        }

        ASSERT_EQ(1, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_05)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef TempPtr<int>::persisted_handler_impl_type<Handler, Deleter>::type PersistedHandlerImpl;

        { 
            int *pi = new int(10);
            garbages.push_back(pi);
            
            TempPtr<int> p1(pi, deleter);
            p1.AddPersistedHandler(new PersistedHandlerImpl(Handler(deleter), deleter));
            ASSERT_FALSE(p1.IsPersisted());
            ASSERT_FALSE(deleter.m_persistCalled);
            
            TempPtr<int> p2(p1);
            ASSERT_FALSE(p2.IsPersisted());
            ASSERT_FALSE(deleter.m_persistCalled);
            
            p1.Persist();
            ASSERT_TRUE(p1.IsPersisted());
            ASSERT_FALSE(p2.IsPersisted());
            ASSERT_TRUE(deleter.m_persistCalled);

            p2.Persist();
            ASSERT_TRUE(p1.IsPersisted());
            ASSERT_TRUE(p2.IsPersisted());
            ASSERT_TRUE(deleter.m_persistCalled);
        }

        ASSERT_EQ(1, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_06)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef TempPtr<int>::persisted_handler_impl_type<Handler, Deleter>::type PersistedHandlerImpl;

        { 
            int *pi = new int(10);
            
            TempPtr<int> p1(pi, deleter);
            p1.AddPersistedHandler(new PersistedHandlerImpl(Handler(deleter), deleter));
            TempPtr<int> p2(p1);
        }

        ASSERT_EQ(2, Deleter::m_count);
        ASSERT_FALSE(deleter.m_persistCalled);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, Test_07)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef TempPtr<int>::persisted_handler_impl_type<Handler, Deleter>::type PersistedHandlerImpl;

        { 
            int *pi = new int(10);
            
            TempPtr<int> p1(pi, deleter);
            p1.AddPersistedHandler(new PersistedHandlerImpl(Handler(deleter), deleter));
            TempPtr<int> p2;
            p2 = p1;
        }

        ASSERT_EQ(2, Deleter::m_count);
        ASSERT_FALSE(deleter.m_persistCalled);
    }
}
