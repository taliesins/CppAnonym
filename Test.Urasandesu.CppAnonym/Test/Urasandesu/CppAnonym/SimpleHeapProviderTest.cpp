#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#include <Urasandesu/CppAnonym/ObjectTag.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SimpleHeapProviderTest.*
namespace {

    namespace _FEE1E6AA {

        namespace mpl = boost::mpl;        
        using namespace Urasandesu::CppAnonym;

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

        struct MyPOD2GeneratorDefault : 
            SimpleHeapProvider<mpl::vector<ObjectTag<MyPOD2, DefaultHeap> > >
        {
        };

        struct MyPOD2GeneratorQuick : 
            SimpleHeapProvider<mpl::vector<ObjectTag<MyPOD2, QuickHeap> > >
        {
        };

        struct MyPOD2GeneratorVeryQuick : 
            SimpleHeapProvider<mpl::vector<ObjectTag<MyPOD2, VeryQuickHeapButMustUseSubscriptOperator> > >
        {
        };
    
    }   // namespace _FEE1E6AA {

    TEST(Urasandesu_CppAnonym_SimpleHeapProviderTest, PerformanceTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace std;
        using namespace Urasandesu::CppAnonym;
        using namespace _FEE1E6AA;

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
            typedef MyPOD2GeneratorDefault Generator;
            Generator gen;
            typedef Generator::providing_type_at<0>::type Target;
            typedef Generator::provider_of<Target>::type TargetProvider;
            TargetProvider &provider = gen.ProviderOf<Target>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                Target *pTarget = provider.Heap().New();
            }
        }
        
        double defaultElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            typedef MyPOD2GeneratorQuick Generator;
            Generator gen;
            typedef Generator::providing_type_at<0>::type Target;
            typedef Generator::provider_of<Target>::type TargetProvider;
            TargetProvider &provider = gen.ProviderOf<Target>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                Target *pTarget = provider.Heap().New();
            }
        }
        
        double quickElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            typedef MyPOD2GeneratorVeryQuick Generator;
            Generator gen;
            typedef Generator::providing_type_at<0>::type Target;
            typedef Generator::provider_of<Target>::type TargetProvider;
            TargetProvider &provider = gen.ProviderOf<Target>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                Target *pTarget = provider.Heap().New();
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
