#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtrFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Traits {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_TempPtr.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        TempPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_02)
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
                m_called(false)
            { }

            template<class T>
            void operator()(T *p)
            {
                DefaultDeleter::operator()(p);
                ++m_count;
            }

            bool m_called;
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
                p.Persist();    // test that no infinite loop...
                m_pDeleter->m_called = true;
            }

            DefaultDeleterWithCount *m_pDeleter;
        };

    }   // namespace _85245FB6 {

    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_03)
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
            ASSERT_FALSE(deleter.m_called);
            p.Persist();
            garbages.push_back(p.Get());
            ASSERT_TRUE(p.IsPersisted());
            ASSERT_TRUE(deleter.m_called);
        }

        ASSERT_EQ(0, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_04)
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
            ASSERT_FALSE(deleter.m_called);
            p.Persist();
            garbages.push_back(p.Get());
            ASSERT_TRUE(p.IsPersisted());
            ASSERT_TRUE(deleter.m_called);
        }

        ASSERT_EQ(1, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }
}
