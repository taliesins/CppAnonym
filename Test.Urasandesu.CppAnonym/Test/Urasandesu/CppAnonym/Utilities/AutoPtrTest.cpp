#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_AutoPtrTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        {
            AutoPtr<Tester> sp;
            ASSERT_EQ(0, Tester::Instance().Value());
            ASSERT_FALSE(sp);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionTTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionTTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());
        
        {
            AutoPtr<Tester> sp(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp);
            ASSERT_EQ(42, sp->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionT_TDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionT_TDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { AutoPtr<int> sp(new int(10), Tester()); }
        { AutoPtr<int> sp(new int(10), Tester()); }
        { AutoPtr<int> sp(new int(10), Tester()); }

        ASSERT_EQ(3, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionT_TD_ImplDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ConstructionT_TD_ImplDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        typedef AutoPtr<int>::make_holder_impl<Tester, Tester>::type HolderImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        { AutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }
        { AutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }
        { AutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }

        ASSERT_EQ(6, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, CopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, CopyConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            AutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            AutoPtr<Tester> sp2(sp1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ImplicitCopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ImplicitCopyConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            AutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            AutoPtr<Tester const> sp2(sp1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, AssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, AssignTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            AutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            AutoPtr<Tester> sp2;
            sp2 = sp1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ImplicitAssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_AutoPtrTest, ImplicitAssignTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            AutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            AutoPtr<Tester const> sp2;
            sp2 = sp1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }

    
    
    
    
    namespace _80607A18 {

        struct POD1
        {
            BYTE byte1;
            BYTE byte2;
            BYTE byte3;
            BYTE byte4;
            BYTE byte5;
            BYTE byte6;
            BYTE byte7;
            BYTE byte8;
        };
    
        struct POD2
        {
            INT int1;
            POD1 pod1;
            PVOID pv;
        
            POD2 *prev;
            POD2 *next;
        };

    }   // namespace _80607A18 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_AutoPtrTest, PerformanceTest_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _80607A18;
        
        typedef AutoPtr<POD2>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef AutoPtr<POD2>::make_heap_holder_impl<>::object_deleter_type ObjectDeleter;
        typedef AutoPtr<POD2>::make_heap_holder_impl<>::heap_type HolderImplHeap;
        typedef AutoPtr<POD2>::make_heap_holder_impl<>::deleter_type HolderImplDeleter;

        ObjectHeap objectHeap;
        ObjectDeleter objectDeleter(objectHeap);
        HolderImplHeap holderImplHeap;
        HolderImplDeleter holderImplDeleter(holderImplHeap);

        INT const ASSIGN_COUNT = 512;
#ifdef _DEBUG
        INT const RETRY_COUNT = 100;
#else
        INT const RETRY_COUNT = 100000;
#endif
        boost::timer t;
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                AutoPtr<POD2> p(new POD2());
        
        double defaultElapsed = t.elapsed();
        
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                AutoPtr<POD2> p(objectHeap.New(), objectDeleter);
        
        double quickElapsed = t.elapsed();
        
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                AutoPtr<POD2> p(holderImplHeap.New(objectHeap.New(), objectDeleter, holderImplDeleter));
        
        double veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "Quick Heap: " << quickElapsed << " (x " << defaultElapsed / quickElapsed << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed << " (x " << defaultElapsed / veryQuickElapsed << ")" << endl;
        // Sample results is as follows: 
        //   Default Heap: 10.865
        //   Quick Heap: 5.304 (x 2.04845)
        //   Very Quick Heap: 0.797 (x 13.6324)
#ifdef _DEBUG
        ASSERT_LT(veryQuickElapsed, defaultElapsed * 2.0);
#else
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
#endif
    }

}
