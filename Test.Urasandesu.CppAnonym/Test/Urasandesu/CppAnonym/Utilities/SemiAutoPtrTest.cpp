#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        {
            SemiAutoPtr<Tester> sp;
            ASSERT_EQ(0, Tester::Instance().Value());
            ASSERT_FALSE(sp);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionTTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionTTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());
        
        {
            SemiAutoPtr<Tester> sp(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp);
            ASSERT_EQ(42, sp->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { SemiAutoPtr<int> sp(new int(10), Tester()); }
        { SemiAutoPtr<int> sp(new int(10), Tester()); }
        { SemiAutoPtr<int> sp(new int(10), Tester()); }

        ASSERT_EQ(3, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TDTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TDTest_02) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int *> garbages;
        Tester t;
        { SemiAutoPtr<int> sp(new int(10), t); garbages.push_back(sp.Get()); sp.SetManual(); }
        { SemiAutoPtr<int> sp(new int(10), t); garbages.push_back(sp.Get()); sp.SetManual(); }
        { SemiAutoPtr<int> sp(new int(10), t); garbages.push_back(sp.Get()); sp.SetManual(); }

        ASSERT_EQ(0, Tester::Instance().Value());

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TDTest_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TDTest_03) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { SemiAutoPtr<int> sp(new int(10), Tester()); sp.SetManual(); sp.SetAuto(); }
        { SemiAutoPtr<int> sp(new int(10), Tester()); sp.SetManual(); sp.SetAuto(); }
        { SemiAutoPtr<int> sp(new int(10), Tester()); sp.SetManual(); sp.SetAuto(); }

        ASSERT_EQ(3, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        typedef SemiAutoPtr<int>::make_holder_impl<Tester, Tester>::type HolderImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }

        ASSERT_EQ(6, Tester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_02) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        typedef SemiAutoPtr<int>::make_holder_impl<Tester, Tester>::type HolderImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int *> garbages;
        Tester t;
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), t, t)); garbages.push_back(sp.Get()); sp.SetManual(); }
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), t, t)); garbages.push_back(sp.Get()); sp.SetManual(); }
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), t, t)); garbages.push_back(sp.Get()); sp.SetManual(); }

        ASSERT_EQ(3, Tester::Instance().Value());

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_03) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        typedef SemiAutoPtr<int>::make_holder_impl<Tester, Tester>::type HolderImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); sp.SetManual(); sp.SetAuto(); }
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); sp.SetManual(); sp.SetAuto(); }
        { SemiAutoPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); sp.SetManual(); sp.SetAuto(); }

        ASSERT_EQ(6, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_04)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ConstructionT_TD_ImplDTest_04) Tag;

        typedef SemiAutoPtr<int>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef SemiAutoPtr<int>::make_heap_holder_impl<>::object_deleter_type ObjectHeapDeleter;
        typedef CounterWithAction1<ObjectHeapDeleter, ActionCouner<BasicCounter<Tag, 0> > > ObjectHeapDeleterTester;

        struct HolderImplHeapDeleterTester;
        typedef SemiAutoPtr<int>::make_holder_impl<ObjectHeapDeleterTester, HolderImplHeapDeleterTester>::type HolderImpl;
        typedef SimpleHeap<HolderImpl, QuickHeapWithoutSubscriptOperator> HolderImplHeap;
        typedef HeapDeleter<HolderImplHeap> HolderImplHeapDeleter;
        struct HolderImplHeapDeleterTester : 
            CounterWithAction1<HolderImplHeapDeleter, ActionCouner<BasicCounter<Tag, 1> > >
        { 
            typedef CounterWithAction1<HolderImplHeapDeleter, ActionCouner<BasicCounter<Tag, 1> > > base_type;
            HolderImplHeapDeleterTester(HolderImplHeapDeleter action) : base_type(action) { }
        };

        
        ASSERT_EQ(0, ObjectHeapDeleterTester::Instance().Value());
        ASSERT_EQ(0, HolderImplHeapDeleterTester::Instance().Value());        

        ObjectHeap objectHeap;
        ObjectHeapDeleter objectHeapDeleter(objectHeap);
        ObjectHeapDeleterTester objectHeapDeleterTester(objectHeapDeleter);
        HolderImplHeap holderImplHeap;
        HolderImplHeapDeleter holderImplHeapDeleter(holderImplHeap);
        HolderImplHeapDeleterTester holderImplHeapDeleterTester(holderImplHeapDeleter);

        { SemiAutoPtr<int> sp(holderImplHeap.New(objectHeap.New(10), objectHeapDeleterTester, holderImplHeapDeleterTester)); }
        { SemiAutoPtr<int> sp(holderImplHeap.New(objectHeap.New(10), objectHeapDeleterTester, holderImplHeapDeleterTester)); }
        { SemiAutoPtr<int> sp(holderImplHeap.New(objectHeap.New(10), objectHeapDeleterTester, holderImplHeapDeleterTester)); }

        ASSERT_EQ(3, ObjectHeapDeleterTester::Instance().Value());
        ASSERT_EQ(3, HolderImplHeapDeleterTester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, CopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, CopyConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            SemiAutoPtr<Tester> sp2(sp1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, CopyConstructionAtManualModeTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, CopyConstructionAtManualModeTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<Tester *> garbages;
        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            sp1.SetManual();
            SemiAutoPtr<Tester> sp2(sp1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());

        typedef std::vector<Tester *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitCopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitCopyConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            SemiAutoPtr<Tester const> sp2(sp1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitCopyConstructionAtManualModeTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitCopyConstructionAtManualModeTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<Tester const *> garbages;
        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            sp1.SetManual();
            SemiAutoPtr<Tester const> sp2(sp1);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());

        typedef std::vector<Tester const *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, AssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, AssignTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            SemiAutoPtr<Tester> sp2;
            sp2 = sp1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, AssignAtManualModeTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, AssignAtManualModeTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<Tester *> garbages;
        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            sp1.SetManual();
            SemiAutoPtr<Tester> sp2;
            sp2 = sp1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());

        typedef std::vector<Tester *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitAssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitAssignTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            SemiAutoPtr<Tester const> sp2;
            sp2 = sp1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitAssignAtManualModeTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, ImplicitAssignAtManualModeTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<Tester const *> garbages;
        { 
            SemiAutoPtr<Tester> sp1(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp1);
            ASSERT_EQ(42, sp1->m_value);
            sp1.SetManual();
            SemiAutoPtr<Tester const> sp2;
            sp2 = sp1;
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp2);
            ASSERT_EQ(42, sp2->m_value);
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());

        typedef std::vector<Tester const *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }





    namespace _B444C480 {

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

    }   // namespace _B444C480 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, PerformanceTest_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _B444C480;
        
        typedef SemiAutoPtr<POD2>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef SemiAutoPtr<POD2>::make_heap_holder_impl<>::object_deleter_type ObjectDeleter;
        typedef SemiAutoPtr<POD2>::make_heap_holder_impl<>::heap_type HolderImplHeap;
        typedef SemiAutoPtr<POD2>::make_heap_holder_impl<>::deleter_type HolderImplDeleter;

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
                SemiAutoPtr<POD2> p(new POD2());
        
        double defaultElapsed = t.elapsed();
        
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                SemiAutoPtr<POD2> p(objectHeap.New(), objectDeleter);
        
        double quickElapsed = t.elapsed();
        
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                SemiAutoPtr<POD2> p(holderImplHeap.New(objectHeap.New(), objectDeleter, holderImplDeleter));
        
        double veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "Quick Heap: " << quickElapsed << " (x " << defaultElapsed / quickElapsed << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed << " (x " << defaultElapsed / veryQuickElapsed << ")" << endl;
        // Sample results is as follows: 
        //   Default Heap: 11.17
        //   Quick Heap: 5.725 (x 1.95109)
        //   Very Quick Heap: 1.185 (x 9.42616)
#ifdef _DEBUG
        ASSERT_LT(veryQuickElapsed, defaultElapsed * 2.0);
#else
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
#endif
    }

}
