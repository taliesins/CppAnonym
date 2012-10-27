#include "stdafx.h"

//#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
//#include <Urasandesu/CppAnonym/IHeapContent.h>
//#endif

//#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/HeapProvider.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

//#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
//#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.h>
//#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SimpleHeapTest.*
namespace {

    struct MyPOD1
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
    
    struct MyPOD2
    {
        INT int1;
        MyPOD1 pod1;
        PVOID pv;
        
        MyPOD2 *prev;
        MyPOD2 *next;
    };

    struct MyPOD3
    {
        INT int1;
        MyPOD1 pod1;
        PVOID pv;
        
        MyPOD3 *prev;
        MyPOD3 *next;
    };

    TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        pPod2->int1 = 1;
        pPod2->pod1.byte1 = 0x02;
        pPod2->pod1.byte2 = 0x03;
        pPod2->pod1.byte3 = 0x04;
        pPod2->pod1.byte4 = 0x05;
        pPod2->pod1.byte5 = 0x06;
        pPod2->pod1.byte6 = 0x07;
        pPod2->pod1.byte7 = 0x08;
        pPod2->pod1.byte8 = 0x09;
        pPod2->pv = pPod2;
        pPod2->prev = pPod2;
        pPod2->next = pPod2;
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap[0]->int1);
        ASSERT_EQ(0x02, pod2Heap[0]->pod1.byte1);
        ASSERT_EQ(0x03, pod2Heap[0]->pod1.byte2);
        ASSERT_EQ(0x04, pod2Heap[0]->pod1.byte3);
        ASSERT_EQ(0x05, pod2Heap[0]->pod1.byte4);
        ASSERT_EQ(0x06, pod2Heap[0]->pod1.byte5);
        ASSERT_EQ(0x07, pod2Heap[0]->pod1.byte6);
        ASSERT_EQ(0x08, pod2Heap[0]->pod1.byte7);
        ASSERT_EQ(0x09, pod2Heap[0]->pod1.byte8);
        ASSERT_EQ(pPod2, pod2Heap[0]->pv);
        ASSERT_EQ(pPod2, pod2Heap[0]->prev);
        ASSERT_EQ(pPod2, pod2Heap[0]->next);
        ASSERT_EQ(1, pod2Heap.Size());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        pPod2->int1 = 1;
        pPod2->pod1.byte1 = 0x02;
        pPod2->pod1.byte2 = 0x03;
        pPod2->pod1.byte3 = 0x04;
        pPod2->pod1.byte4 = 0x05;
        pPod2->pod1.byte5 = 0x06;
        pPod2->pod1.byte6 = 0x07;
        pPod2->pod1.byte7 = 0x08;
        pPod2->pod1.byte8 = 0x09;
        pPod2->pv = pPod2;
        pPod2->prev = pPod2;
        pPod2->next = pPod2;
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap[0]->int1);
        ASSERT_EQ(0x02, pod2Heap[0]->pod1.byte1);
        ASSERT_EQ(0x03, pod2Heap[0]->pod1.byte2);
        ASSERT_EQ(0x04, pod2Heap[0]->pod1.byte3);
        ASSERT_EQ(0x05, pod2Heap[0]->pod1.byte4);
        ASSERT_EQ(0x06, pod2Heap[0]->pod1.byte5);
        ASSERT_EQ(0x07, pod2Heap[0]->pod1.byte6);
        ASSERT_EQ(0x08, pod2Heap[0]->pod1.byte7);
        ASSERT_EQ(0x09, pod2Heap[0]->pod1.byte8);
        ASSERT_EQ(pPod2, pod2Heap[0]->pv);
        ASSERT_EQ(pPod2, pod2Heap[0]->prev);
        ASSERT_EQ(pPod2, pod2Heap[0]->next);
        ASSERT_EQ(1, pod2Heap.Size());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        pPod2->int1 = 1;
        pPod2->pod1.byte1 = 0x02;
        pPod2->pod1.byte2 = 0x03;
        pPod2->pod1.byte3 = 0x04;
        pPod2->pod1.byte4 = 0x05;
        pPod2->pod1.byte5 = 0x06;
        pPod2->pod1.byte6 = 0x07;
        pPod2->pod1.byte7 = 0x08;
        pPod2->pod1.byte8 = 0x09;
        pPod2->pv = pPod2;
        pPod2->prev = pPod2;
        pPod2->next = pPod2;
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap[0]->int1);
        ASSERT_EQ(0x02, pod2Heap[0]->pod1.byte1);
        ASSERT_EQ(0x03, pod2Heap[0]->pod1.byte2);
        ASSERT_EQ(0x04, pod2Heap[0]->pod1.byte3);
        ASSERT_EQ(0x05, pod2Heap[0]->pod1.byte4);
        ASSERT_EQ(0x06, pod2Heap[0]->pod1.byte5);
        ASSERT_EQ(0x07, pod2Heap[0]->pod1.byte6);
        ASSERT_EQ(0x08, pod2Heap[0]->pod1.byte7);
        ASSERT_EQ(0x09, pod2Heap[0]->pod1.byte8);
        ASSERT_EQ(pPod2, pod2Heap[0]->pv);
        ASSERT_EQ(pPod2, pod2Heap[0]->prev);
        ASSERT_EQ(pPod2, pod2Heap[0]->next);
        ASSERT_EQ(1, pod2Heap.Size());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        for (INT i = 0; i < 511; ++i)
            pod2Heap.New();

        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(512, pod2Heap.Size());

        pod2Heap.New();

        ASSERT_NE(pPod2, pod2Heap[0]);      // This heap version is very quick, but you must use subscript operator [] if access it after a while.
                                            // Because the allocated objects are moved when the heap is over a threshold size.
        ASSERT_EQ(513, pod2Heap.Size());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_Construction_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_Construction_01) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;

        ASSERT_EQ(0, Counter::Instance().Value());
        {
            SimpleHeap<Counter> testerHeap;
            {
                Counter *pTester = testerHeap.New();
                ASSERT_EQ(1, Counter::Instance().Value());
            }
            
            {
                Counter *pTester = testerHeap.New();
                ASSERT_EQ(2, Counter::Instance().Value());
            }
        }
        ASSERT_EQ(0, Counter::Instance().Value());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_Construction_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_Construction_01) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;

        ASSERT_EQ(0, Counter::Instance().Value());
        {
            SimpleHeap<Counter, QuickHeap> testerHeap;
            {
                Counter *pTester = testerHeap.New();
                ASSERT_EQ(1, Counter::Instance().Value());
            }
            
            {
                Counter *pTester = testerHeap.New();
                ASSERT_EQ(2, Counter::Instance().Value());
            }
        }
        ASSERT_EQ(0, Counter::Instance().Value());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorTest_Construction_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorTest_Construction_01) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;

        ASSERT_EQ(0, Counter::Instance().Value());
        {
            SimpleHeap<Counter, VeryQuickHeapButMustUseSubscriptOperator> testerHeap;
            {
                Counter *pTester = testerHeap.New();
                ASSERT_EQ(1, Counter::Instance().Value());
            }
            
            {
                Counter *pTester = testerHeap.New();
                ASSERT_EQ(2, Counter::Instance().Value());
            }
        }
        ASSERT_EQ(0, Counter::Instance().Value());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, PerformanceTest_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym;

        INT const ASSIGN_COUNT = 512;
#ifdef _DEBUG
        INT const RETRY_COUNT = 100;
#else
        INT const RETRY_COUNT = 100000;
#endif
        boost::timer t;
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            SimpleHeap<MyPOD2> pod2Heap;
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = pod2Heap.New();
            }
        }
        
        double defaultElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = pod2Heap.New();
            }
        }
        
        double quickElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = pod2Heap.New();
            }
        }
        
        double veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "Quick Heap: " << quickElapsed << " (x " << defaultElapsed / quickElapsed << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed << " (x " << defaultElapsed / veryQuickElapsed << ")" << endl;
        // Sample results is as follows: 
        //   Default Heap: 0.811
        //   Quick Heap: 0.113 (x 7.17699)
        //   Very Quick Heap: 0.046 (x 17.6304)
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.Size());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.Size());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.Size());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapDeleteTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(0, pod2Heap.Size());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapDeleteTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = NULL;
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(1, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[0]);
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(2, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[1]);
            pPod2 = pPod2_;
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(3, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[2]);
        }

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(2, pod2Heap.Size());
        ASSERT_NE(pPod2, pod2Heap[1]);
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapDeleteTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(0, pod2Heap.Size());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapDeleteTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = NULL;
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(1, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[0]);
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(2, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[1]);
            pPod2 = pPod2_;
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(3, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[2]);
        }

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(2, pod2Heap.Size());
        ASSERT_NE(pPod2, pod2Heap[1]);
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorDeleteTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(0, pod2Heap.Size());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorDeleteTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
        
        MyPOD2 *pPod2 = NULL;
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            pPod2_->int1 = 1;
            ASSERT_EQ(1, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[0]);
            ASSERT_EQ(1, pod2Heap[0]->int1);
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            pPod2_->int1 = 2;
            ASSERT_EQ(2, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[1]);
            ASSERT_EQ(2, pod2Heap[1]->int1);
            pPod2 = pPod2_;
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            pPod2_->int1 = 3;
            ASSERT_EQ(3, pod2Heap.Size());
            ASSERT_EQ(pPod2_, pod2Heap[2]);
            ASSERT_EQ(3, pod2Heap[2]->int1);
        }

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(2, pod2Heap.Size());
        ASSERT_EQ(pPod2, pod2Heap[1]);  // This assertion is really TRUE!!, but its content has been changed.
        ASSERT_EQ(3, pod2Heap[1]->int1);
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorDeleteTest_03)
    {
        using namespace Urasandesu::CppAnonym;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustUseSubscriptOperatorDeleteTest_03) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> pod2Heap;
        
        ASSERT_EQ(0, Counter::Instance().Value());
        {
            SimpleHeap<Counter, VeryQuickHeapButMustUseSubscriptOperator> testerHeap;
            Counter *pTester1 = testerHeap.New();
            ASSERT_EQ(1, Counter::Instance().Value());
            Counter *pTester2 = testerHeap.New();
            ASSERT_EQ(2, Counter::Instance().Value());
            testerHeap.Delete(pTester1);
            ASSERT_EQ(1, Counter::Instance().Value());
        }
        ASSERT_EQ(0, Counter::Instance().Value());
    }
}
