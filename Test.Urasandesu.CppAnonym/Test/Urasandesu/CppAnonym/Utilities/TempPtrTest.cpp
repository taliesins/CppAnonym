/* 
 * File: TempPtrTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_TempPtrTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0 > > > Tester;

        ASSERT_EQ(0, Tester::Instance().Value());

        {
            TempPtr<Tester> sp;
            ASSERT_EQ(0, Tester::Instance().Value());
            ASSERT_FALSE(sp);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionTTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionTTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0> > > Tester;
        
        ASSERT_EQ(0, Tester::Instance().Value());

        {
            TempPtr<Tester> sp(new Tester(42));
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp);
            ASSERT_EQ(42, sp->m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_boolAlreadyPersistedTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_boolAlreadyPersistedTest_01) Tag;
        typedef CounterWithValue1<int, SurvivalCounter<BasicCounter<Tag, 0> > > Tester;
        
        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<Tester *> garbages;
        {
            TempPtr<Tester> sp(new Tester(42), true);
            ASSERT_EQ(1, Tester::Instance().Value());
            ASSERT_TRUE(sp);
            ASSERT_EQ(42, sp->m_value);
            garbages.push_back(sp.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());

        typedef std::vector<Tester *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_TDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_TDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        
        ASSERT_EQ(0, Tester::Instance().Value());

        { TempPtr<int> sp(new int(10), Tester()); }
        { TempPtr<int> sp(new int(10), Tester()); }
        { TempPtr<int> sp(new int(10), Tester()); }

        ASSERT_EQ(3, Tester::Instance().Value());
    }

    
    
    
    
    namespace _85245FB6 {

        using namespace Urasandesu::CppAnonym::Utilities;

        template<class Tester>
        struct TestHandler
        {
            TestHandler(Tester &t) : 
                m_t(t)
            { }
            
            typedef TempPtr<int> sender_type;
            
            void operator()(sender_type *pSender, void *pArg)
            {
                sender_type &sp = *pSender;
                sp.Persist();    // test for no infinite loop...
                m_t.m_value = true;
            }

            Tester &m_t;
        };

    }   // namespace _85245FB6 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, AddPersistedHandlerHandlerTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, AddPersistedHandlerHandlerTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        
        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int *> garbages;
        Tester t;
        { 
            TempPtr<int> sp(new int(10), t);
            sp.AddPersistedHandler(TestHandler<Tester>(t));
            ASSERT_FALSE(sp.IsPersisted());
            ASSERT_FALSE(t.m_value);
            sp.Persist();
            garbages.push_back(sp.Get());
            ASSERT_TRUE(sp.IsPersisted());
            ASSERT_TRUE(t.m_value);
        }

        ASSERT_EQ(0, Tester::Instance().Value());
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, AddPersistedHandlerHandler_ImplDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, AddPersistedHandlerHandler_ImplDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int *> garbages;
        Tester t;
        { 
            TempPtr<int> sp(new int(10), t);
            sp.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            ASSERT_FALSE(sp.IsPersisted());
            ASSERT_FALSE(t.m_value);
            sp.Persist();
            garbages.push_back(sp.Get());
            ASSERT_TRUE(sp.IsPersisted());
            ASSERT_TRUE(t.m_value);
        }

        ASSERT_EQ(1, Tester::Instance().Value());
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }
    
    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, AddPersistedHandlerHandler_ImplDTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, AddPersistedHandlerHandler_ImplDTest_02) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;
        
        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int *> garbages;
        Tester t;
        { 
            int *p = new int(10);
            garbages.push_back(p);
            
            TempPtr<int> sp1(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            ASSERT_FALSE(sp1.IsPersisted());
            ASSERT_FALSE(t.m_value);
            
            TempPtr<int> sp2(sp1);
            ASSERT_FALSE(sp2.IsPersisted());
            ASSERT_FALSE(t.m_value);
            
            sp1.Persist();
            ASSERT_TRUE(sp1.IsPersisted());
            ASSERT_FALSE(sp2.IsPersisted());
            ASSERT_TRUE(t.m_value);

            sp2.Persist();
            ASSERT_TRUE(sp1.IsPersisted());
            ASSERT_TRUE(sp2.IsPersisted());
            ASSERT_TRUE(t.m_value);
        }

        ASSERT_EQ(1, Tester::Instance().Value());
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_TD_ImplDTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_TD_ImplDTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<BasicCounter<Tag, 0> > > Tester;
        ASSERT_EQ(0, Tester::Instance().Value());

        typedef TempPtr<int>::make_holder_impl<Tester, Tester>::type HolderImpl;

        { TempPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }
        { TempPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }
        { TempPtr<int> sp(new HolderImpl(new int(10), Tester(), Tester())); }

        ASSERT_EQ(6, Tester::Instance().Value());
    }




    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_TD_ImplDTest_02)
    {
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ConstructionT_TD_ImplDTest_02) Tag;
        
        typedef TempPtr<int>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef TempPtr<int>::make_heap_holder_impl<>::object_deleter_type ObjectHeapDeleter;
        typedef CounterWithAction1<ObjectHeapDeleter, ActionCouner<BasicCounter<Tag, 0> > > ObjectHeapDeleterTester;

        struct HolderImplHeapDeleterTester;
        typedef TempPtr<int>::make_holder_impl<ObjectHeapDeleterTester, HolderImplHeapDeleterTester>::type HolderImpl;
        typedef SimpleHeap<HolderImpl, QuickHeapWithoutRandomAccess> HolderImplHeap;
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

        { TempPtr<int> sp(holderImplHeap.New(objectHeap.New(10), objectHeapDeleterTester, holderImplHeapDeleterTester)); }
        { TempPtr<int> sp(holderImplHeap.New(objectHeap.New(10), objectHeapDeleterTester, holderImplHeapDeleterTester)); }
        { TempPtr<int> sp(holderImplHeap.New(objectHeap.New(10), objectHeapDeleterTester, holderImplHeapDeleterTester)); }

        ASSERT_EQ(3, ObjectHeapDeleterTester::Instance().Value());
        ASSERT_EQ(3, HolderImplHeapDeleterTester::Instance().Value());
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, CopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, CopyConstructionTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        Tester t;
        { 
            int *p = new int(10);
            
            TempPtr<int> sp1(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            TempPtr<int> sp2(sp1);
        }

        ASSERT_EQ(2, Tester::Instance().Value());
        ASSERT_FALSE(t.m_value);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, CopyConstructionAlreadyPersistedTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, CopyConstructionAlreadyPersistedTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int *> garbages;
        Tester t;
        { 
            int *p = new int(10);
            
            TempPtr<int> sp1(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            sp1.Persist();
            TempPtr<int> sp2(sp1);
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());
        ASSERT_TRUE(t.m_value);

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitCopyConstructionTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitCopyConstructionTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        Tester t;
        { 
            int *p = new int(10);
            
            TempPtr<int> sp1(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            TempPtr<int const> sp2(sp1);
        }

        ASSERT_EQ(2, Tester::Instance().Value());
        ASSERT_FALSE(t.m_value);
    }

    
    
    
    
    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitCopyConstructionAlreadyPersistedTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitCopyConstructionAlreadyPersistedTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        std::vector<int const *> garbages;
        Tester t;
        { 
            int *p = new int(10);
            
            TempPtr<int> sp1(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            sp1.Persist();
            TempPtr<int const> sp2(sp1);
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());
        ASSERT_TRUE(t.m_value);

        typedef std::vector<int const *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, AssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, AssignTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        auto t = Tester();
        { 
            auto *p = new int(10);
            
            auto sp1 = TempPtr<int>(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            auto sp2 = TempPtr<int>();
            sp2 = sp1;
        }

        ASSERT_EQ(2, Tester::Instance().Value());
        ASSERT_FALSE(t.m_value);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, AssignAlreadyPersistedTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, AssignAlreadyPersistedTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        auto garbages = std::vector<int *>();
        auto t = Tester();
        { 
            auto *p = new int(10);
            
            auto sp1 = TempPtr<int>(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            sp1.Persist();
            auto sp2 = TempPtr<int>();
            sp2 = sp1;
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());
        ASSERT_TRUE(t.m_value);

        for (auto i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, AssignAlreadyPersistedTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        auto garbages = std::vector<int *>();
        { 
            auto *p = new int(10);
            
            auto sp1 = TempPtr<int>(p, true);
            ASSERT_TRUE(sp1 != nullptr);

            sp1 = TempPtr<int>();
            ASSERT_TRUE(sp1 == nullptr);
            
            garbages.push_back(p);
        }

        for (auto i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitAssignTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitAssignTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        auto t = Tester();
        { 
            auto *p = new int(10);
            
            auto sp1 = TempPtr<int>(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            auto sp2 = TempPtr<int const>();
            sp2 = sp1;
        }

        ASSERT_EQ(2, Tester::Instance().Value());
        ASSERT_FALSE(t.m_value);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitAssignAlreadyPersistedTest_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef GTEST_TEST_CLASS_NAME_(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitAssignAlreadyPersistedTest_01) Tag;
        typedef CounterWithAction1<DefaultDeleter, ActionCouner<CounterWithValue1<bool, BasicCounter<Tag, 0> > > > Tester;
        typedef TempPtr<int>::make_persisted_handler_holder_impl<TestHandler<Tester>, Tester>::type PersistedHandlerImpl;

        ASSERT_EQ(0, Tester::Instance().Value());

        auto garbages = std::vector<int const *>();
        auto t = Tester();
        { 
            auto *p = new int(10);
            
            auto sp1 = TempPtr<int>(p, t);
            sp1.AddPersistedHandler(new PersistedHandlerImpl(TestHandler<Tester>(t), t));
            sp1.Persist();
            auto sp2 = TempPtr<int const>();
            sp2 = sp1;
            garbages.push_back(sp2.Get());
        }

        ASSERT_EQ(1, Tester::Instance().Value());
        ASSERT_TRUE(t.m_value);

        for (auto i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            t(*i);
    }





    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, ImplicitAssignAlreadyPersistedTest_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        auto garbages = std::vector<int const *>();
        { 
            auto *p = new int(10);
            
            auto sp1 = TempPtr<int const>(p, true);
            ASSERT_TRUE(sp1 != nullptr);

            sp1 = TempPtr<int>();
            ASSERT_TRUE(sp1 == nullptr);
            
            garbages.push_back(p);
        }

        for (auto i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            delete *i;
    }





    namespace _BB8140DA {

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

    }   // namespace _BB8140DA {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_TempPtrTest, PerformanceTest_01)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _BB8140DA;
        using boost::timer::cpu_timer;
        
        typedef TempPtr<POD2>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef TempPtr<POD2>::make_heap_holder_impl<>::object_deleter_type ObjectDeleter;
        typedef TempPtr<POD2>::make_heap_holder_impl<>::heap_type HolderImplHeap;
        typedef TempPtr<POD2>::make_heap_holder_impl<>::deleter_type HolderImplDeleter;

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
        auto t = cpu_timer();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                TempPtr<POD2> p(new POD2());
        
        auto defaultElapsed = t.elapsed();
        t = cpu_timer();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                TempPtr<POD2> p(objectHeap.New(), objectDeleter);
        
        auto quickElapsed = t.elapsed();
        t = cpu_timer();

        for (INT i = 0; i < RETRY_COUNT; ++i)
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
                TempPtr<POD2> p(holderImplHeap.New(objectHeap.New(), objectDeleter, holderImplDeleter));
        
        auto veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed.wall << endl;
        cout << "Quick Heap: " << quickElapsed.wall << " (x " << defaultElapsed.wall / quickElapsed.wall << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed.wall << " (x " << defaultElapsed.wall / veryQuickElapsed.wall << ")" << endl;
        // Sample results is as follows: 
        //   Default Heap: 12.387
        //   Quick Heap: 6.708 (x 1.8466)
        //   Very Quick Heap: 1.778 (x 6.96682)
#ifdef _DEBUG
        ASSERT_LT(veryQuickElapsed.wall, defaultElapsed.wall * 2.0);
#else
        ASSERT_LT(veryQuickElapsed.wall, defaultElapsed.wall);
#endif
    }

}
