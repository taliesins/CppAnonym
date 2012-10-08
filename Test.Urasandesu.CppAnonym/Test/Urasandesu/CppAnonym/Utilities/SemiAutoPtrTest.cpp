#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_SemiAutoPtr.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        SemiAutoPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        SemiAutoPtr<int> p(new int(10));
        ASSERT_TRUE(p);
        ASSERT_EQ(10, *p);
    }

    
    
    
    
    namespace _DE3EFDB5 {

        using namespace Urasandesu::CppAnonym::Utilities;

        struct DefaultDeleterWithCount : 
            DefaultDeleter
        {
            template<class T>
            void operator()(T *p)
            {
                DefaultDeleter::operator()(p);
                ++m_count;
            }

            static int m_count;
        };

        int DefaultDeleterWithCount::m_count = 0;

    }   // namespace _DE3EFDB5 {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); }
        { SemiAutoPtr<int> p(new int(10), deleter); }
        { SemiAutoPtr<int> p(new int(10), deleter); }

        ASSERT_EQ(3, Deleter::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_04)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new int(10), deleter); garbages.push_back(p.Get()); p.SetManual(); }

        ASSERT_EQ(0, Deleter::m_count);

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_05)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new int(10), deleter); p.SetManual(); p.SetAuto(); }

        ASSERT_EQ(3, Deleter::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_06)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef SemiAutoPtr<int>::make_holder_impl<Deleter, Deleter>::type HolderImpl;

        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); }

        ASSERT_EQ(6, Deleter::m_count);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_07)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        std::vector<int *> garbages;
        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef SemiAutoPtr<int>::make_holder_impl<Deleter, Deleter>::type HolderImpl;

        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); garbages.push_back(p.Get()); p.SetManual(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); garbages.push_back(p.Get()); p.SetManual(); }

        ASSERT_EQ(3, Deleter::m_count);

        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_08)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _DE3EFDB5;

        typedef DefaultDeleterWithCount Deleter;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef SemiAutoPtr<int>::make_holder_impl<Deleter, Deleter>::type HolderImpl;

        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); p.SetManual(); p.SetAuto(); }
        { SemiAutoPtr<int> p(new HolderImpl(new int(10), deleter, deleter)); p.SetManual(); p.SetAuto(); }

        ASSERT_EQ(6, Deleter::m_count);
    }




    
    namespace _B444C480 {

        struct ObjectHeapDeleterWithCount;
        struct HolderImplHeapDeleterWithCount;

    }   // namespace _B444C480 {

    namespace _B444C480 {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef SemiAutoPtr<int>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef ObjectHeapDeleterWithCount ObjectHeapDeleter;
        typedef HolderImplHeapDeleterWithCount HolderImplHeapDeleter;
        typedef SemiAutoPtr<int>::make_holder_impl<ObjectHeapDeleter, HolderImplHeapDeleter>::type HolderImpl;
        typedef SimpleHeap<HolderImpl, QuickHeapWithoutSubscriptOperator> HolderImplHeap;

        struct ObjectHeapDeleterWithCount : 
            SemiAutoPtr<int>::make_heap_holder_impl<>::object_deleter_type
        {
            typedef SemiAutoPtr<int>::make_heap_holder_impl<>::object_deleter_type base_type;

            ObjectHeapDeleterWithCount(ObjectHeap &heap) : 
                base_type(heap)
            { }

            template<class T>
            void operator()(T *p)
            {
                base_type::operator()(p);
                ++m_count;
            }

            static int m_count;
        };

        int ObjectHeapDeleterWithCount::m_count = 0;

        
        struct HolderImplHeapDeleterWithCount : 
            HeapDeleter<HolderImplHeap>
        {
            typedef HeapDeleter<HolderImplHeap> base_type;

            HolderImplHeapDeleterWithCount(HolderImplHeap &heap) : 
                base_type(heap)
            { }
            
            template<class T>
            void operator()(T *p)
            {
                base_type::operator()(p);
                ++m_count;
            }

            static int m_count;
        };

        int HolderImplHeapDeleterWithCount::m_count = 0;
    
    }   // namespace _B444C480 {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_09)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _B444C480;

        ObjectHeapDeleter::m_count = 0;
        HolderImplHeapDeleter::m_count = 0;
        
        ObjectHeap objectHeap;
        ObjectHeapDeleter objectHeapDeleter(objectHeap);
        HolderImplHeap holderImplHeap;
        HolderImplHeapDeleter holderImplHeapDeleter(holderImplHeap);

        { SemiAutoPtr<int> p(holderImplHeap.New(objectHeap.New(10), objectHeapDeleter, holderImplHeapDeleter)); }
        { SemiAutoPtr<int> p(holderImplHeap.New(objectHeap.New(10), objectHeapDeleter, holderImplHeapDeleter)); }
        { SemiAutoPtr<int> p(holderImplHeap.New(objectHeap.New(10), objectHeapDeleter, holderImplHeapDeleter)); }

        ASSERT_EQ(3, ObjectHeapDeleter::m_count);
        ASSERT_EQ(3, HolderImplHeapDeleter::m_count);
    }





    namespace _B444C480 {

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

    }   // namespace _B444C480 {

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtr, Test_10)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _B444C480;
        
        typedef SemiAutoPtr<MyPOD2>::make_heap_holder_impl<>::object_heap_type ObjectHeap;
        typedef SemiAutoPtr<MyPOD2>::make_heap_holder_impl<>::object_deleter_type ObjectDeleter;
        typedef SemiAutoPtr<MyPOD2>::make_heap_holder_impl<>::heap_type HolderImplHeap;
        typedef SemiAutoPtr<MyPOD2>::make_heap_holder_impl<>::deleter_type HolderImplDeleter;

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
        {
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                SemiAutoPtr<MyPOD2> p(new MyPOD2());
            }
        }
        
        double defaultElapsed = t.elapsed();
        
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                SemiAutoPtr<MyPOD2> p(objectHeap.New(), objectDeleter);
            }
        }
        
        double quickElapsed = t.elapsed();
        
        t.restart();

        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                SemiAutoPtr<MyPOD2> p(holderImplHeap.New(objectHeap.New(), objectDeleter, holderImplDeleter));
            }
        }
        
        double veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "Quick Heap: " << quickElapsed << " (x " << defaultElapsed / quickElapsed << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed << " (x " << defaultElapsed / veryQuickElapsed << ")" << endl;
        // Sample results is as follows: 
        //   Default Heap: 10.748
        //   Quick Heap: 5.367 (x 2.00261)
        //   Very Quick Heap: 0.998 (x 10.7695)
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
    }

}
