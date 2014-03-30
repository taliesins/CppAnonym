/* 
 * File: SimpleHeapTest.cpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
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

    struct MyPOD3
    {
        INT int1;
        MyPOD1 pod1;
        PVOID pv;
        
        MyPOD3 *prev;
        MyPOD3 *next;
    };

    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_01)
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
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap[0].int1);
        ASSERT_EQ(0x02, pod2Heap[0].pod1.byte1);
        ASSERT_EQ(0x03, pod2Heap[0].pod1.byte2);
        ASSERT_EQ(0x04, pod2Heap[0].pod1.byte3);
        ASSERT_EQ(0x05, pod2Heap[0].pod1.byte4);
        ASSERT_EQ(0x06, pod2Heap[0].pod1.byte5);
        ASSERT_EQ(0x07, pod2Heap[0].pod1.byte6);
        ASSERT_EQ(0x08, pod2Heap[0].pod1.byte7);
        ASSERT_EQ(0x09, pod2Heap[0].pod1.byte8);
        ASSERT_EQ(pPod2, pod2Heap[0].pv);
        ASSERT_EQ(pPod2, pod2Heap[0].prev);
        ASSERT_EQ(pPod2, pod2Heap[0].next);
        ASSERT_EQ(1, pod2Heap.size());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_01)
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
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap[0].int1);
        ASSERT_EQ(0x02, pod2Heap[0].pod1.byte1);
        ASSERT_EQ(0x03, pod2Heap[0].pod1.byte2);
        ASSERT_EQ(0x04, pod2Heap[0].pod1.byte3);
        ASSERT_EQ(0x05, pod2Heap[0].pod1.byte4);
        ASSERT_EQ(0x06, pod2Heap[0].pod1.byte5);
        ASSERT_EQ(0x07, pod2Heap[0].pod1.byte6);
        ASSERT_EQ(0x08, pod2Heap[0].pod1.byte7);
        ASSERT_EQ(0x09, pod2Heap[0].pod1.byte8);
        ASSERT_EQ(pPod2, pod2Heap[0].pv);
        ASSERT_EQ(pPod2, pod2Heap[0].prev);
        ASSERT_EQ(pPod2, pod2Heap[0].next);
        ASSERT_EQ(1, pod2Heap.size());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
        
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
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap[0].int1);
        ASSERT_EQ(0x02, pod2Heap[0].pod1.byte1);
        ASSERT_EQ(0x03, pod2Heap[0].pod1.byte2);
        ASSERT_EQ(0x04, pod2Heap[0].pod1.byte3);
        ASSERT_EQ(0x05, pod2Heap[0].pod1.byte4);
        ASSERT_EQ(0x06, pod2Heap[0].pod1.byte5);
        ASSERT_EQ(0x07, pod2Heap[0].pod1.byte6);
        ASSERT_EQ(0x08, pod2Heap[0].pod1.byte7);
        ASSERT_EQ(0x09, pod2Heap[0].pod1.byte8);
        ASSERT_EQ(pPod2, pod2Heap[0].pv);
        ASSERT_EQ(pPod2, pod2Heap[0].prev);
        ASSERT_EQ(pPod2, pod2Heap[0].next);
        ASSERT_EQ(1, pod2Heap.size());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        auto capacity = SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod>::internal_vector_type().capacity();
        for (auto i = 0ul; i < capacity - 1; ++i)
            pod2Heap.New();

        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(capacity, pod2Heap.size());

        pod2Heap.New();

        ASSERT_NE(pPod2, &pod2Heap[0]);             // This heap version is very quick, but you must access through the each method if access it after a while.
                                                    // Because the allocated objects are moved when the heap is over a threshold size.
        ASSERT_EQ(capacity + 1, pod2Heap.size());   // 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_Construction_01)
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

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_Construction_01)
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

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_Construction_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_Construction_01) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;

        ASSERT_EQ(0, Counter::Instance().Value());
        {
            SimpleHeap<Counter, VeryQuickHeapButMustAccessThroughEachMethod> testerHeap;
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


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, PerformanceTest_01)
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
            SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
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
        //   Default Heap: 6.459
        //   Quick Heap: 0.889 (x 7.26547)
        //   Very Quick Heap: 0.296 (x 21.8209)
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.size());
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.size());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodDeleteLastTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        pod2Heap.DeleteLast();
        ASSERT_EQ(0, pod2Heap.size());
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapDeleteTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(0, pod2Heap.size());
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapDeleteTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2> pod2Heap;
        
        MyPOD2 *pPod2 = NULL;
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(1, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[0]);
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(2, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[1]);
            pPod2 = pPod2_;
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(3, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[2]);
        }

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(2, pod2Heap.size());
        ASSERT_NE(pPod2, &pod2Heap[1]);
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapDeleteTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(0, pod2Heap.size());
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapDeleteTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, QuickHeap> pod2Heap;
        
        MyPOD2 *pPod2 = NULL;
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(1, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[0]);
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(2, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[1]);
            pPod2 = pPod2_;
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            ASSERT_EQ(3, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[2]);
        }

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(2, pod2Heap.size());
        ASSERT_NE(pPod2, &pod2Heap[1]);
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodDeleteTest_01)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
        
        MyPOD2 *pPod2 = pod2Heap.New();
        ASSERT_EQ(pPod2, &pod2Heap[0]);
        ASSERT_EQ(1, pod2Heap.size());

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(0, pod2Heap.size());
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodDeleteTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
        
        MyPOD2 *pPod2 = NULL;
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            pPod2_->int1 = 1;
            ASSERT_EQ(1, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[0]);
            ASSERT_EQ(1, pod2Heap[0].int1);
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            pPod2_->int1 = 2;
            ASSERT_EQ(2, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[1]);
            ASSERT_EQ(2, pod2Heap[1].int1);
            pPod2 = pPod2_;
        }
        
        {
            MyPOD2 *pPod2_ = pod2Heap.New();
            pPod2_->int1 = 3;
            ASSERT_EQ(3, pod2Heap.size());
            ASSERT_EQ(pPod2_, &pod2Heap[2]);
            ASSERT_EQ(3, pod2Heap[2].int1);
        }

        pod2Heap.Delete(pPod2);
        ASSERT_EQ(2, pod2Heap.size());
        ASSERT_EQ(pPod2, &pod2Heap[1]);  // This assertion is really TRUE!!, but its content has been changed.
        ASSERT_EQ(3, pod2Heap[1].int1);
    }


    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodDeleteTest_03)
    {
        using namespace Urasandesu::CppAnonym;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodDeleteTest_03) Tag;
        typedef SurvivalCounter<BasicCounter<Tag, 0> > Counter;
        
        SimpleHeap<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> pod2Heap;
        
        ASSERT_EQ(0, Counter::Instance().Value());
        {
            SimpleHeap<Counter, VeryQuickHeapButMustAccessThroughEachMethod> testerHeap;
            Counter *pTester1 = testerHeap.New();
            ASSERT_EQ(1, Counter::Instance().Value());
            Counter *pTester2 = testerHeap.New();
            ASSERT_EQ(2, Counter::Instance().Value());
            testerHeap.Delete(pTester1);
            ASSERT_EQ(1, Counter::Instance().Value());
        }
        ASSERT_EQ(0, Counter::Instance().Value());
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_MakableIteratorRange_01)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expecteds = vector<INT>();
        expecteds += 10, 20, 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        auto m = 0;
        BOOST_FOREACH (auto const &n, rng)
            ASSERT_EQ(expecteds[m++], n); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_MakableIteratorRange_02)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expecteds = vector<INT>();
        expecteds += 10, 20, 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        for (auto n = 0; n < rng.size(); ++n)
            ASSERT_EQ(expecteds[n], rng[n]); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, DefaultHeapTest_MakableIteratorRange_03)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expected = 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        auto i = rng.begin();
        i += 2;
        ASSERT_EQ(expected, *i); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_MakableIteratorRange_01)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT, QuickHeap>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expecteds = vector<INT>();
        expecteds += 10, 20, 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        auto m = 0;
        BOOST_FOREACH (auto const &n, rng)
            ASSERT_EQ(expecteds[m++], n); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_MakableIteratorRange_02)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT, QuickHeap>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expecteds = vector<INT>();
        expecteds += 10, 20, 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        for (auto n = 0; n < rng.size(); ++n)
            ASSERT_EQ(expecteds[n], rng[n]); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_MakableIteratorRange_03)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT, QuickHeap>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expected = 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        auto i = rng.begin();
        i += 2;
        ASSERT_EQ(expected, *i); 
    }

    
    
    namespace _38B917E4 {
        
        using namespace Urasandesu::CppAnonym;
        using boost::any_range;
        using boost::adaptors::transformed;
        using boost::noncopyable;
        using boost::random_access_traversal_tag;

        struct IItem
        {
            IItem() { }
            virtual ~IItem() { }
            virtual INT GetValue() const = 0;
        };

        struct Item1 : 
            IItem
        {
            INT GetValue() const { return 1; }
        }; 

        any_range<IItem const *, random_access_traversal_tag, IItem const *, ptrdiff_t> MakeUpper(SimpleHeap<Item1, QuickHeap> const &heap)
        {
            using std::function;;

            auto toUpper = function<IItem const *(Item1 const &)>();
            toUpper = [](Item1 const &item1) { return static_cast<IItem const *>(&item1); };
            return heap | transformed(toUpper);
        }

    }   // namespace _38B917E4 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, QuickHeapTest_MakableIteratorRange_04)
    {
        using namespace _38B917E4;
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::iterator_range;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<Item1, QuickHeap>();
        { auto *pItem1 = heap.New(); }
        { auto *pItem1 = heap.New(); }
        { auto *pItem1 = heap.New(); }
        
        auto expecteds = vector<INT>();
        expecteds += 1, 1, 1;


        // Act
        auto rng = MakeUpper(heap);


        // Assert
        ASSERT_EQ(3, rng.size()); 
        auto m = 0;
        BOOST_FOREACH (auto const &pItem, rng)
            ASSERT_EQ(expecteds[m++], pItem->GetValue()); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_MakableIteratorRange_01)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT, VeryQuickHeapButMustAccessThroughEachMethod>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expecteds = vector<INT>();
        expecteds += 10, 20, 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        auto m = 0;
        BOOST_FOREACH (auto const &n, rng)
            ASSERT_EQ(expecteds[m++], n); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_MakableIteratorRange_02)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT, VeryQuickHeapButMustAccessThroughEachMethod>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expecteds = vector<INT>();
        expecteds += 10, 20, 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        for (auto n = 0; n < rng.size(); ++n)
            ASSERT_EQ(expecteds[n], rng[n]); 
    }

    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_MakableIteratorRange_03)
    {
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<INT, VeryQuickHeapButMustAccessThroughEachMethod>();
        { auto *pn = heap.New(); *pn = 10; }
        { auto *pn = heap.New(); *pn = 20; }
        { auto *pn = heap.New(); *pn = 30; }
        
        auto expected = 30;


        // Act
        auto rng = make_iterator_range(heap);


        // Assert
        ASSERT_EQ(3, rng.size());
        auto i = rng.begin();
        i += 2;
        ASSERT_EQ(expected, *i); 
    }

    
    
    namespace _028300BD {
        
        using namespace Urasandesu::CppAnonym;
        using boost::any_range;
        using boost::adaptors::transformed;
        using boost::noncopyable;
        using boost::random_access_traversal_tag;

        struct IItem
        {
            IItem() { }
            virtual ~IItem() { }
            virtual INT GetValue() const = 0;
        };

        struct Item1 : 
            IItem
        {
            INT GetValue() const { return 1; }
        }; 

        any_range<IItem const *, random_access_traversal_tag, IItem const *, ptrdiff_t> MakeUpper(SimpleHeap<Item1, VeryQuickHeapButMustAccessThroughEachMethod> const &heap)
        {
            using std::function;;

            auto toUpper = function<IItem const *(Item1 const &)>();
            toUpper = [](Item1 const &item1) { return static_cast<IItem const *>(&item1); };
            return heap | transformed(toUpper);
        }

    }   // namespace _028300BD {

    CPPANONYM_TEST(Urasandesu_CppAnonym_SimpleHeapTest, VeryQuickHeapButMustAccessThroughEachMethodTest_MakableIteratorRange_04)
    {
        using namespace _028300BD;
        using namespace Urasandesu::CppAnonym;
        using boost::assign::operator +=;
        using boost::iterator_range;
        using boost::make_iterator_range;
        using std::vector;

        // Arrange
        auto heap = SimpleHeap<Item1, VeryQuickHeapButMustAccessThroughEachMethod>();
        { auto *pItem1 = heap.New(); }
        { auto *pItem1 = heap.New(); }
        { auto *pItem1 = heap.New(); }
        
        auto expecteds = vector<INT>();
        expecteds += 1, 1, 1;


        // Act
        auto rng = MakeUpper(heap);


        // Assert
        ASSERT_EQ(3, rng.size()); 
        auto m = 0;
        BOOST_FOREACH (auto const &pItem, rng)
            ASSERT_EQ(expecteds[m++], pItem->GetValue()); 
    }
}
