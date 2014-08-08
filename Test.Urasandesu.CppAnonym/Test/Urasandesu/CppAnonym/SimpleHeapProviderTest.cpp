/* 
 * File: SimpleHeapProviderTest.cpp
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

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#include <Urasandesu/CppAnonym/ObjectTag.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_HPP
#include <Urasandesu/CppAnonym/Collections/RapidVector.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.h>
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
            SimpleHeapProvider<mpl::vector<ObjectTag<MyPOD2, VeryQuickHeapButMustAccessThroughEachMethod> > >
        {
        };
    
    }   // namespace _FEE1E6AA {

    TEST(Urasandesu_CppAnonym_SimpleHeapProviderTest, PerformanceTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace std;
        using namespace Urasandesu::CppAnonym;
        using namespace _FEE1E6AA;
        using boost::timer::cpu_timer;

        INT const ASSIGN_COUNT = 512;
#ifdef _DEBUG
        INT const RETRY_COUNT = 100;
#else
        INT const RETRY_COUNT = 100000;
#endif
        auto t = cpu_timer();
        
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
        
        auto defaultElapsed = t.elapsed();
        t = cpu_timer();
        
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
        
        auto quickElapsed = t.elapsed();
        t = cpu_timer();
        
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
        
        auto veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed.wall << endl;
        cout << "Quick Heap: " << quickElapsed.wall << " (x " << defaultElapsed.wall / quickElapsed.wall << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed.wall << " (x " << defaultElapsed.wall / veryQuickElapsed.wall << ")" << endl;
        // Sample results are as follows: 
        //   Default Heap: 8.205
        //   Quick Heap: 1.467 (x 5.59305)
        //   Very Quick Heap: 0.639 (x 12.8404)
        ASSERT_LT(veryQuickElapsed.wall, defaultElapsed.wall);
    }

    
    
    TEST(Urasandesu_CppAnonym_SimpleHeapProviderTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace _FEE1E6AA;

        {
            auto gen = MyPOD2GeneratorDefault();
            auto &provider = gen.ProviderOf<MyPOD2>();
            auto *pMyPOD2 = provider.Heap().New();
            ASSERT_TRUE(pMyPOD2 != nullptr);
        }

        {
            auto gen = MyPOD2GeneratorQuick();
            auto &provider = gen.ProviderOf<MyPOD2>();
            auto *pMyPOD2 = provider.Heap().New();
            ASSERT_TRUE(pMyPOD2 != nullptr);
        }

        {
            auto gen = MyPOD2GeneratorVeryQuick();
            auto &provider = gen.ProviderOf<MyPOD2>();
            auto *pMyPOD2 = provider.Heap().New();
            ASSERT_TRUE(pMyPOD2 != nullptr);
        }
    }
}
