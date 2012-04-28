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

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct AddImplicitConversion
    {
        AddImplicitConversion(T& other) { }
        AddImplicitConversion& operator=(T& other) { return *this; }
    };

#ifdef CPPANONYM_ADDIMPLICITCONVERSION_SIZE
#error This .h reserves the word "CPPANONYM_ADDIMPLICITCONVERSION_SIZE".
#endif
#define CPPANONYM_ADDIMPLICITCONVERSION_SIZE 11

#ifdef CPPANONYM_IGNORE_PARAM
#error This .h reserves the word "CPPANONYM_IGNORE_PARAM".
#endif
#define CPPANONYM_IGNORE_PARAM(z, n, _) \
        template<template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> class Container> \
        struct IgnoreParam ## n \
        { \
        };

    BOOST_PP_REPEAT_FROM_TO(1, CPPANONYM_ADDIMPLICITCONVERSION_SIZE, CPPANONYM_IGNORE_PARAM, nil)

#undef CPPANONYM_IGNORE_PARAM

#ifdef CPPANONYM_ADDIMPLICITCONVERSION
#error This .h reserves the word "CPPANONYM_ADDIMPLICITCONVERSION".
#endif
#define CPPANONYM_ADDIMPLICITCONVERSION(z, n, _) \
        template<template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> class Container> \
        struct AddImplicitConversion<IgnoreParam ## n<Container>> \
        { \
            template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> \
            AddImplicitConversion(Container<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), T)>& other) { } \
            template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> \
            AddImplicitConversion& operator=(Container<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), T)>& other) { return *this; } \
        };

    BOOST_PP_REPEAT_FROM_TO(1, CPPANONYM_ADDIMPLICITCONVERSION_SIZE, CPPANONYM_ADDIMPLICITCONVERSION, nil)

#undef CPPANONYM_ADDIMPLICITCONVERSION
    
#undef CPPANONYM_ADDIMPLICITCONVERSION_SIZE

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym {

    template<class Key, class Object, class Tag = DefaultHeap>
    struct KeyObjectTag
    {
        typedef Key key_type;
        typedef Object object_type;
        typedef Tag tag_type;
    };

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

    struct MyPOD3GeneratorDefault : 
        Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<
                    MyPOD3, 
                    Urasandesu::CppAnonym::DefaultHeap
                >                 
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<
                    MyPOD3, 
                    Urasandesu::CppAnonym::DefaultHeap
                > object_tag_type;                 
    };

    struct MyPOD3GeneratorQuick : 
        Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<
                    MyPOD3, 
                    Urasandesu::CppAnonym::QuickHeap
                >                 
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<
                    MyPOD3, 
                    Urasandesu::CppAnonym::QuickHeap
                > object_tag_type;                 
    };

    struct MyPOD3GeneratorVeryQuick : 
        Urasandesu::CppAnonym::SimpleHeapProvider<
            boost::mpl::vector<
                Urasandesu::CppAnonym::ObjectTag<
                    MyPOD3, 
                    Urasandesu::CppAnonym::VeryQuickHeapButMustUseSubscriptOperator
                >                 
            >
        >
    {
        typedef Urasandesu::CppAnonym::ObjectTag<
                    MyPOD3, 
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
        //   Default Heap: 0.16
        //   Quick Heap: 0.053 (x 3.01887)
        //   Very Quick Heap: 0.008 (x 20)
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
            MyPOD3GeneratorDefault gen;
            typedef MyPOD3GeneratorDefault::object_tag_type KeyObjectTag;
            typedef MyPOD3GeneratorDefault::type_decided_by<KeyObjectTag>::type MyPOD3Heap;
            MyPOD3Heap &heap = gen.Of<KeyObjectTag>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD3 *pPod3 = heap.New();
            }
        }
        
        double defaultElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            MyPOD3GeneratorQuick gen;
            typedef MyPOD3GeneratorQuick::object_tag_type KeyObjectTag;
            typedef MyPOD3GeneratorQuick::type_decided_by<KeyObjectTag>::type MyPOD3Heap;
            MyPOD3Heap &heap = gen.Of<KeyObjectTag>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD3 *pPod3 = heap.New();
            }
        }
        
        double quickElapsed = t.elapsed();
        
        t.restart();
        
        for (INT i = 0; i < RETRY_COUNT; ++i)
        {
            MyPOD3GeneratorVeryQuick gen;
            typedef MyPOD3GeneratorVeryQuick::object_tag_type KeyObjectTag;
            typedef MyPOD3GeneratorVeryQuick::type_decided_by<KeyObjectTag>::type MyPOD3Heap;
            MyPOD3Heap &heap = gen.Of<KeyObjectTag>();
            for (INT j = 0; j < ASSIGN_COUNT; ++j)
            {
                MyPOD3 *pPod3 = heap.New();
            }
        }
        
        double veryQuickElapsed = t.elapsed();
        
        cout << "Default Heap: " << defaultElapsed << endl;
        cout << "Quick Heap: " << quickElapsed << " (x " << defaultElapsed / quickElapsed << ")" << endl;
        cout << "Very Quick Heap: " << veryQuickElapsed << " (x " << defaultElapsed / veryQuickElapsed << ")" << endl;
        // Sample results is as follows: 
        //   Default Heap: 0.16
        //   Quick Heap: 0.053 (x 3.01887)
        //   Very Quick Heap: 0.008 (x 20)
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
}
