﻿#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

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

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());
    }

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, ALotOfAllocAndFreeHeapTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, ALotOfAllocAndFreeHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());
    }


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, PerformanceTest_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym;

        INT const ASSIGN_COUNT = 21;
#ifdef _DEBUG
        INT const RETRY_COUNT = 1000;
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
            SimpleHeap<MyPOD2, ALotOfAllocAndFreeHeap> pod2Heap;
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = pod2Heap.New();
            }
        }
        
        double alotOfAllocElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "A Lot Of Allocation And Free Heap: " << alotOfAllocElapsed << endl;
        ASSERT_LT(alotOfAllocElapsed, defaultElapsed);
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

    
    TEST(Urasandesu_CppAnonym_SimpleHeapTest, ALotOfAllocAndFreeHeapDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, ALotOfAllocAndFreeHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.Size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.Size());
    }
}
