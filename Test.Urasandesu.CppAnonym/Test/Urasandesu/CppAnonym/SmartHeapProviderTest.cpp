/* 
 * File: SmartHeapProviderTest.cpp
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

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_H
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_SmartHeapProviderTest.*
namespace {

    namespace _DF280537 {

        struct Foo;

    }   // namespace _DF280537 {

    namespace _DF280537 {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef StaticDependentObjectsStorage<Foo> MyStorage;
        typedef MyStorage::host_type Host;

        struct OrderChecker
        {
            static OrderChecker &Instance()
            {
                static OrderChecker checker;
                return checker;
            }

            std::vector<int> m_ctorSeq;
            std::vector<int> m_dtorSeq;
        };

        struct Foo : 
            SmartHeapProvider<Foo>
        {
            typedef providing_type_at<0>::type foo_type;
            typedef provider_of<foo_type>::type foo_provider_type;

            Foo() { OrderChecker::Instance().m_ctorSeq.push_back(reinterpret_cast<int>(this)); }
            ~Foo() { OrderChecker::Instance().m_dtorSeq.push_back(reinterpret_cast<int>(this)); }

            static Utilities::AutoPtr<foo_type> CreateStaticFoo()
            {
                foo_type &sFoo = MyStorage::Object<foo_type>();
                foo_provider_type &provider = sFoo.ProviderOf<foo_type>();
                return provider.NewObject();
            }

            Utilities::AutoPtr<foo_type> CreateFoo()
            {
                foo_provider_type &provider = ProviderOf<foo_type>();
                return provider.NewObject();
            }
        };

    }   // namespace _DF280537 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_SmartHeapProviderTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DF280537;

        int sFooAddr = 0;
        int pFooRootAddr = 0;
        int pFooAddr = 0;
        Foo &sFoo = MyStorage::Object<Foo>();
        sFooAddr = reinterpret_cast<int>(&sFoo);
        {
            AutoPtr<Foo> pFooRoot = Foo::CreateStaticFoo();
            pFooRootAddr = reinterpret_cast<int>(pFooRoot.Get());
            AutoPtr<Foo> pFoo = pFooRoot->CreateFoo();
            pFooAddr = reinterpret_cast<int>(pFoo.Get());

            ASSERT_EQ(3, OrderChecker::Instance().m_ctorSeq.size());
            ASSERT_EQ(sFooAddr, OrderChecker::Instance().m_ctorSeq[0]);
            ASSERT_EQ(pFooRootAddr, OrderChecker::Instance().m_ctorSeq[1]);
            ASSERT_EQ(pFooAddr, OrderChecker::Instance().m_ctorSeq[2]);
            ASSERT_EQ(0, OrderChecker::Instance().m_dtorSeq.size());
        }
        ASSERT_EQ(2, OrderChecker::Instance().m_dtorSeq.size());
        ASSERT_EQ(pFooAddr, OrderChecker::Instance().m_dtorSeq[0]);
        ASSERT_EQ(pFooRootAddr, OrderChecker::Instance().m_dtorSeq[1]);

        StaticDependentObjectsStorageDetail::HostAccessor<Foo>::Host().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorSeq.size());
        ASSERT_EQ(sFooAddr, OrderChecker::Instance().m_dtorSeq[2]);

        // Restore static area to work the debug heap correctly.
        new(&StaticDependentObjectsStorageDetail::HostAccessor<Foo>::Host())Host();
    }

}
