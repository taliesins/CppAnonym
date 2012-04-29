#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
#include <Urasandesu/CppAnonym/SimpleHeap.h>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    struct SmartDestructor
    {
        typedef typename boost::call_traits<T>::param_type param_type;
        typedef typename boost::remove_pointer<typename Traits::RemoveConst<T>::type>::type raw_type;

        static void Destruct(param_type obj)
        {
            typedef typename boost::is_pointer<T>::type is_pointer;
            typedef typename boost::has_trivial_destructor<raw_type>::type has_trivial_destructor;
            
            DestructImpl<is_pointer, has_trivial_destructor>::Destruct(obj);
        }

        template<class IsPointer, class HasTrivialDestructor>
        struct DestructImpl
        {
            static void Destruct(param_type obj)
            {
                // Do nothing. Because T has trivial destructor in this case.
            }
        };

        template<>
        struct DestructImpl<boost::integral_constant<bool, false>, boost::integral_constant<bool, false>> 
        { 
            static void Destruct(param_type obj)
            {
                obj.~raw_type();
            }
        };

        template<>
        struct DestructImpl<boost::integral_constant<bool, true>, boost::integral_constant<bool, false>> 
        { 
            static void Destruct(param_type obj)
            {
                obj->~raw_type();
            }
        };
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym {

    template<class Object, class Tag = DefaultHeap>
    struct ObjectTag
    {
        typedef Object object_type;
        typedef Tag tag_type;
    };

    namespace Detail {
        
        namespace mpl = boost::mpl;

        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImpl : 
            public SimpleHeapProviderImpl<ObjectTagSequence, typename mpl::next<I>::type, IEnd>
        {
        private:
            typedef SimpleHeapProviderImpl<ObjectTagSequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_tag_type;
            typedef typename object_tag_type::object_type object_type;
            typedef typename object_tag_type::tag_type tag_type;

            boost::shared_ptr<SimpleHeap<object_type, tag_type>> mutable m_pFactory;
            
            inline SimpleHeap<object_type, tag_type> &Factory() const
            {
                if (!m_pFactory.get())
                    m_pFactory = boost::make_shared<SimpleHeap<object_type, tag_type>>();
                return *m_pFactory.get();
            }

        public:
            inline SIZE_T Size() const
            {
                return Factory().Size();
            }

            inline object_type *operator[] (SIZE_T ix)
            {
                return Factory()[ix];
            }

            inline object_type *New()
            {
                return Factory().New();
            }
            
            inline object_type *Peek() const
            {
                return Size() == 0 ? NULL : Factory()[Size() - 1];
            }

            inline void DeleteLast()
            {
                object_type *pObj = Peek();
                if (pObj != NULL)
                    Factory().DeleteLast();
            }
        };

        template<class ObjectTagSequence>
        class ATL_NO_VTABLE SimpleHeapProviderImpl<ObjectTagSequence, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type> : 
            boost::noncopyable
        {
        };

    }   // namespace Detail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider : 
        Detail::SimpleHeapProviderImpl<ObjectTagSequence, 
                                 typename Traits::DistinctBegin<ObjectTagSequence>::type, 
                                 typename Traits::DistinctEnd<ObjectTagSequence>::type>
    {
    public:
        typedef SimpleHeapProvider<ObjectTagSequence> this_type;

        template<class KeyObjectTag>
        struct type_decided_by
        {
            typedef Detail::SimpleHeapProviderImpl<
                ObjectTagSequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<ObjectTagSequence>::type,
                    KeyObjectTag
                >::type,
                typename Traits::DistinctEnd<ObjectTagSequence>::type
            > type;
        };

        template<class KeyObjectTag>
        inline typename type_decided_by<KeyObjectTag>::type &Of()
        {
            return static_cast<typename type_decided_by<KeyObjectTag>::type &>(*this);
        }

        template<class KeyObjectTag>
        inline typename type_decided_by<KeyObjectTag>::type const &Of() const
        {
            return const_cast<this_type *>(this)->Of<KeyObjectTag>();
        }
    };
}}   // namespace Urasandesu { namespace CppAnonym {

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

    struct MyPOD3 : 
        Urasandesu::CppAnonym::IHeapContent<size_t>
    {
        INT int1;
        MyPOD1 pod1;
        PVOID pv;
        
        MyPOD3 *prev;
        MyPOD3 *next;
    };

    struct MyPOD2GeneratorDefault : 
        Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<
                    MyPOD2, 
                    Urasandesu::CppAnonym::DefaultHeap
                >                 
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<
                    MyPOD2, 
                    Urasandesu::CppAnonym::DefaultHeap
                > object_tag_type;                 
    };

    struct MyPOD2GeneratorQuick : 
        Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<
                    MyPOD2, 
                    Urasandesu::CppAnonym::QuickHeap
                >                 
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<
                    MyPOD2, 
                    Urasandesu::CppAnonym::QuickHeap
                > object_tag_type;                 
    };

    struct MyPOD2GeneratorVeryQuick : 
        Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<
                    MyPOD2, 
                    Urasandesu::CppAnonym::VeryQuickHeapButMustUseSubscriptOperator
                >                 
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<
                    MyPOD2, 
                    Urasandesu::CppAnonym::VeryQuickHeapButMustUseSubscriptOperator
                > object_tag_type;                 
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


    TEST(Urasandesu_CppAnonym_SimpleHeapTest, PerformanceTest_02)
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
        // Sample results is as follows: 
        //   Default Heap: 0.639
        //   Quick Heap: 0.148 (x 4.31757)
        //   Very Quick Heap: 0.08 (x 7.9875)
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


    TEST(Urasandesu_CppAnonym_Utilities_SmartDestructorTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym;

        typedef Utilities::SmartDestructor<int> IntDestructor;
        int i = 10;
        IntDestructor::Destruct(i);

        
        struct POD
        {
            int i;
        };
        typedef Utilities::SmartDestructor<POD> PODDestructor;
        POD pod;
        pod.i = 20;
        PODDestructor::Destruct(pod);

        typedef Utilities::SmartDestructor<POD *> PODPointerDestructor;
        {
            BYTE b[sizeof(POD)];
            POD *pPod = reinterpret_cast<POD *>(b);
            new(pPod)POD();
            PODPointerDestructor::Destruct(pPod);
        }


        struct DestructionChecker
        {
            DestructionChecker() : Destructed(false) { }
            static DestructionChecker &Instance() { static DestructionChecker c; return c; }
            bool Destructed;
        };
        struct NotPOD
        {
            NotPOD() { DestructionChecker::Instance().Destructed = false; }
            ~NotPOD() { DestructionChecker::Instance().Destructed = true; }
            int i;
        };
        typedef Utilities::SmartDestructor<NotPOD> NotPODDestructor;
        {
            BYTE b[sizeof(NotPOD)];
            NotPOD *pNotPod = reinterpret_cast<NotPOD *>(b);
            new(pNotPod)NotPOD();
            ASSERT_FALSE(DestructionChecker::Instance().Destructed);
            NotPODDestructor::Destruct(*pNotPod);
            ASSERT_TRUE(DestructionChecker::Instance().Destructed);
        }

        typedef Utilities::SmartDestructor<NotPOD *> NotPODPointerDestructor;
        {
            BYTE b[sizeof(NotPOD)];
            NotPOD *pNotPod = reinterpret_cast<NotPOD *>(b);
            new(pNotPod)NotPOD();
            ASSERT_FALSE(DestructionChecker::Instance().Destructed);
            NotPODPointerDestructor::Destruct(pNotPod);
            ASSERT_TRUE(DestructionChecker::Instance().Destructed);
        }
    }
}
