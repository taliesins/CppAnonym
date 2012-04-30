#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SimpleHeapProviderTest.*
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

    typedef Urasandesu::CppAnonym::ObjectTag<MyPOD2, Urasandesu::CppAnonym::DefaultHeap> MyPOD2WithDefaultHeap;
    struct MyPOD2GeneratorDefault : 
        Urasandesu::CppAnonym::SimpleHeapProvider<boost::mpl::vector<MyPOD2WithDefaultHeap>>
    {
        typedef MyPOD2WithDefaultHeap object_tag_type;                 
    };

    typedef Urasandesu::CppAnonym::ObjectTag<MyPOD2, Urasandesu::CppAnonym::QuickHeap> MyPOD2WithQuickHeap;
    struct MyPOD2GeneratorQuick : 
        Urasandesu::CppAnonym::SimpleHeapProvider<boost::mpl::vector<MyPOD2WithQuickHeap>>
    {
        typedef MyPOD2WithQuickHeap object_tag_type;                 
    };

    typedef Urasandesu::CppAnonym::ObjectTag<MyPOD2, Urasandesu::CppAnonym::VeryQuickHeapButMustUseSubscriptOperator> MyPOD2WithVeryQuickHeap;
    struct MyPOD2GeneratorVeryQuick : 
        Urasandesu::CppAnonym::SimpleHeapProvider<boost::mpl::vector<MyPOD2WithVeryQuickHeap>>
    {
        typedef MyPOD2WithVeryQuickHeap object_tag_type;                 
    };


    TEST(Urasandesu_CppAnonym_SimpleHeapProviderTest, PerformanceTest_01)
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
            MyPOD2GeneratorDefault gen;
            typedef MyPOD2GeneratorDefault::object_tag_type KeyObjectTag;
            typedef MyPOD2GeneratorDefault::type_decided_by<KeyObjectTag>::type MyPOD2Heap;
            MyPOD2Heap &heap = gen.Of<KeyObjectTag>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = heap.New();
            }
        }
        
        double defaultElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            MyPOD2GeneratorQuick gen;
            typedef MyPOD2GeneratorQuick::object_tag_type KeyObjectTag;
            typedef MyPOD2GeneratorQuick::type_decided_by<KeyObjectTag>::type MyPOD2Heap;
            MyPOD2Heap &heap = gen.Of<KeyObjectTag>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = heap.New();
            }
        }
        
        double quickElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            MyPOD2GeneratorVeryQuick gen;
            typedef MyPOD2GeneratorVeryQuick::object_tag_type KeyObjectTag;
            typedef MyPOD2GeneratorVeryQuick::type_decided_by<KeyObjectTag>::type MyPOD2Heap;
            MyPOD2Heap &heap = gen.Of<KeyObjectTag>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD2 *pPod2 = heap.New();
            }
        }
        
        double veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "Quick Heap: " << quickElapsed << " (x " << defaultElapsed / quickElapsed << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed << " (x " << defaultElapsed / veryQuickElapsed << ")" << endl;
        // Sample results are as follows: 
        //   Default Heap: 0.639
        //   Quick Heap: 0.148 (x 4.31757)
        //   Very Quick Heap: 0.08 (x 7.9875)
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
    }
}
