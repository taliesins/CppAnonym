/* 
 * File: HeapProviderTest.cpp
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

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_HeapProviderTest.*
namespace {

    struct A : 
        Urasandesu::CppAnonym::IHeapContent<INT>
    {
        INT m_value;
    };

    struct B : 
        Urasandesu::CppAnonym::IHeapContent<INT>
    {
        ULONG m_value;
    };

    TEST(Urasandesu_CppAnonym_HeapProviderTest, DefaultPathTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef HeapProvider<INT, mpl::vector<A, B> > MyHeapProvider;

        MyHeapProvider heap;
        MyHeapProvider::type_decided_by<A>::type &aHeap = heap.Of<A>();
        A *pA = aHeap.New(0);
        pA->m_value = 10;
        ASSERT_EQ(aHeap.Get(0), pA);
        ASSERT_EQ(10, aHeap.Get(0)->m_value);
        ASSERT_EQ(1, aHeap.Size());
        ASSERT_TRUE(aHeap.Exists(0)); 
        ASSERT_FALSE(aHeap.Exists(1)); 

        MyHeapProvider::type_decided_by<B>::type &bHeap = heap.Of<B>();
        B *pB = bHeap.New(1);
        pB->m_value = 20;
        ASSERT_EQ(bHeap.Get(1), pB);
        ASSERT_EQ(20, bHeap.Get(1)->m_value);
        ASSERT_EQ(1, bHeap.Size());
        ASSERT_TRUE(bHeap.Exists(1)); 
        ASSERT_FALSE(bHeap.Exists(0)); 

        MyHeapProvider const &cHeap = heap;
        MyHeapProvider::type_decided_by<A>::type const &caHeap = cHeap.Of<A>();
        A const *pcA = caHeap.Get(0);
        ASSERT_EQ(caHeap.Get(0), pcA);
        ASSERT_EQ(10, caHeap.Get(0)->m_value);
        ASSERT_EQ(1, caHeap.Size());
        ASSERT_TRUE(caHeap.Exists(0)); 
        ASSERT_FALSE(caHeap.Exists(1)); 

        std::cout << "Size Of MyHeapProvider: " << sizeof(MyHeapProvider) << std::endl;
    }


    TEST(Urasandesu_CppAnonym_HeapProviderTest, TypeConceptTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef HeapProvider<INT, mpl::vector<INT, DOUBLE> > MyHeapProvider;

        // This declaration doesn't work because contents of boost::mpl::vector don't 
        // implement necessary interface Urasandesu::CppAnonym::IHeapContent.
        MyHeapProvider heap;
        MyHeapProvider::type_decided_by<INT>::type &intHeap = heap.Of<INT>();
        //INT *pI = intHeap.NewPseudo();  // error C2664
    }

    TEST(Urasandesu_CppAnonym_HeapProviderTest, DeleteTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef HeapProvider<INT, mpl::vector<A, B> > MyHeapProvider;

        MyHeapProvider heap;
        MyHeapProvider::type_decided_by<A>::type &aHeap = heap.Of<A>();
        A *pA = aHeap.New(0);
        ASSERT_EQ(1, aHeap.Size());
        ASSERT_TRUE(aHeap.Exists(0)); 

        aHeap.DeleteLast();
        ASSERT_EQ(0, aHeap.Size());
        ASSERT_FALSE(aHeap.Exists(0)); 

        
        MyHeapProvider::type_decided_by<B>::type &bHeap = heap.Of<B>();
        B *pB = bHeap.New(0);
        ASSERT_EQ(1, bHeap.Size());
        ASSERT_TRUE(bHeap.Exists(0)); 

        bHeap.DeleteLast();
        ASSERT_EQ(0, bHeap.Size());
        ASSERT_FALSE(bHeap.Exists(0)); 
    }
}
