#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace MaxSizeTypeDetail {

        namespace mpl = boost::mpl;

        template<class Types>
        class MaxSizeTypeImpl
        {
            typedef typename mpl::transform_view<Types, mpl::sizeof_<mpl::_1> > type_size_view;
            typedef typename mpl::max_element<type_size_view>::type i;
        public:
            typedef typename mpl::deref<typename i::base>::type type;
        };

    }   // namespace MaxSizeTypeDetail {

    template<class Types>
    struct MaxSizeType : 
        MaxSizeTypeDetail::MaxSizeTypeImpl<Types>
    {
    };



    
    
    namespace IsLikePointerDetail {

        using namespace boost;
        using namespace boost::mpl;

        template<class T>
        class IsLikePointerImpl : 
            public is_pointer<T>
        {
        };

        template<class T, template<class> class CandidateSmartPtr>
        class IsLikePointerImpl<CandidateSmartPtr<T> >
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(IndirectionOperator, operator*, T &, () const); 
            CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(MemberAccessOperator, operator->, T *, () const);
        public:
            typedef typename and_<
                CPP_ANONYM_HAS_MEMBER_FUNCTION(IndirectionOperator, CandidateSmartPtr<T>), 
                CPP_ANONYM_HAS_MEMBER_FUNCTION(MemberAccessOperator, CandidateSmartPtr<T>), 
                not_<
                    or_<
                        has_trivial_constructor<CandidateSmartPtr<T> >,
                        has_trivial_copy<CandidateSmartPtr<T> >, 
                        has_trivial_assign<CandidateSmartPtr<T> >, 
                        has_trivial_destructor<CandidateSmartPtr<T> >
                    >
                >
            >::type type;
        };

    }   // namespace IsLikePointerDetail {

    template<class T>
    struct IsLikePointer : 
        IsLikePointerDetail::IsLikePointerImpl<T>
    {
    };

    template<class T, template<class> class CandidateSmartPtr>
    struct IsLikePointer<CandidateSmartPtr<T> > : 
        IsLikePointerDetail::IsLikePointerImpl<CandidateSmartPtr<T> >
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace VariantPtrDetail {

        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;

        template<class Types>
        class VariantPtrImpl : 
            noncopyable
        {
        public:
            typedef fold<Types, true_, and_<_1, IsLikePointer<_2> > > all_types_are_like_pointer;
            BOOST_MPL_ASSERT((typename all_types_are_like_pointer::type));

            typedef typename MaxSizeType<Types>::type max_size_type;

#ifdef _DEBUG
            VariantPtrImpl() : 
                m_which(-1)
#else
            VariantPtrImpl()
#endif
            {
                ::ZeroMemory(m_storage, sizeof(max_size_type));
            }

            template<class T>
            VariantPtrImpl(T &p)
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                m_which = I::pos::value;
#else
#endif
                ConstructionDistributor<T>::Construct<T &>(m_storage, p);
            }

            template<class T>
            T &Get()
            {
                typedef typename mpl::find<Types, T>::type I;
                typedef typename mpl::end<Types>::type IEnd;
                BOOST_MPL_ASSERT((not_<is_same<I, IEnd> >));
#ifdef _DEBUG
                _ASSERTE(m_which == I::pos::value);
#else
#endif
                return reinterpret_cast<T &>(m_storage);
            }

            template<class T>
            void Clear()
            {
                // 指定された T が Types に含まれるかの検証が必要。
                // 指定された T の位置が現在処理中の T と等しいかの検証を行う処理が必要。
                // !has_trivial_destructor であれば destructor 呼ぶって処理が必要。
                // !has_trivial_constructor であれば constructor 呼ぶって処理が必要。
                reinterpret_cast<T &>(m_storage).~T();
                //new(m_storage)T();
                ::ZeroMemory(m_storage, sizeof(max_size_type));
            }

            template<class T>
            void Copy(VariantPtrImpl<Types> &other)
            {
                // 指定された T が Types に含まれるかの検証が必要。
                // 指定された T の位置が現在処理中の T と等しいかの検証を行う処理が必要。
                // !has_trivial_assign であれば operator= 使う処理が必要。
                    // !has_trivial_destructor であれば destructor 呼ぶって処理が必要。
                    // !has_trivial_copy であれば copy constructor 呼ぶって処理が必要。
                reinterpret_cast<T &>(other.m_storage) = reinterpret_cast<T &>(m_storage);
                //new(other.m_storage)T(reinterpret_cast<T &>(m_storage));
                //other.Clear<T>();
                //other.Get<T>() = Get<T>();
            }

            template<class T>
            T Detach()
            {
                // 指定された T が Types に含まれるかの検証が必要。
                // 指定された T の位置が現在処理中の T と等しいかの検証を行う処理が必要。
                // !has_trivial_constructor であれば constructor 呼ぶって処理が必要。
                // !has_trivial_destructor であれば destructor 呼ぶって処理が必要。
                // !has_trivial_constructor であれば constructor 呼ぶって処理が必要。
                T p;
                ::memcpy_s(&p, sizeof(T), m_storage, sizeof(T));
                //T p(reinterpret_cast<T &>(m_storage));
                //reinterpret_cast<T &>(m_storage).~T();
                reinterpret_cast<T &>(m_storage).~T();
                //new(m_storage)T();
                ::ZeroMemory(m_storage, sizeof(max_size_type));
                return p;
            }

        private:
            BYTE m_storage[sizeof(max_size_type)];
#ifdef _DEBUG
            INT m_which;
#else
#endif
        };

    }   // namespace VariantPtrDetail {

    template<class Types>
    struct VariantPtr : 
        VariantPtrDetail::VariantPtrImpl<Types>
    {
        typedef VariantPtr<Types> this_type;
        typedef VariantPtrDetail::VariantPtrImpl<Types> base_type;

        VariantPtr() : 
            base_type()
        { }

        template<class T>
        VariantPtr(T &v) : 
            base_type(v)
        { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest.*
namespace {

    namespace _AE9B0ABB {

        namespace mpl = boost::mpl;
        using namespace boost;
        
        struct Hoge
        {
            typedef Hoge this_type;

            Hoge() : m_useCount(0) { }

            inline friend void intrusive_ptr_add_ref(this_type *p)
            {
                ++p->m_useCount;
            }

            inline friend void intrusive_ptr_release(this_type *p)
            {
                --p->m_useCount;
            }
            
            LONG m_useCount;
        };
    
    }   // namespace _AE9B0ABB {

    TEST(Urasandesu_CppAnonym_Utilities_VariantPtrTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _AE9B0ABB;
        
        //BOOST_MPL_ASSERT_RELATION(sizeof(variant<int *, shared_ptr<int> >), ==, sizeof(shared_ptr<int>));


        {
            typedef variant<Hoge *, intrusive_ptr<Hoge> > Var;
            Hoge hoge;
            intrusive_ptr<Hoge> p(&hoge);
            Var v(p);
            intrusive_ptr<Hoge> &p_ = get<intrusive_ptr<Hoge> >(v);
            ASSERT_EQ(2, p_->m_useCount);
        }

        {
            typedef variant<Hoge *, intrusive_ptr<Hoge> > Var;
            Hoge hoge;
            Var v(&hoge);
            Hoge *&p_ = get<Hoge *>(v);
            ASSERT_EQ(0, p_->m_useCount);
        }
        
        BOOST_MPL_ASSERT((boost::is_same<MaxSizeType<mpl::vector<int, __int64> >::type, __int64>)); 
        
        {
            typedef VariantPtr<mpl::vector<Hoge *, intrusive_ptr<Hoge> > > Var;
            Var v;
#ifdef _DEBUG
            BOOST_MPL_ASSERT_RELATION(sizeof(Var), ==, sizeof(intrusive_ptr<Hoge>) + sizeof(INT));
#else
            BOOST_MPL_ASSERT_RELATION(sizeof(Var), ==, sizeof(intrusive_ptr<Hoge>));
#endif
        }
        
        {
            Hoge hoge;
            intrusive_ptr<Hoge> p1(&hoge);
            typedef VariantPtr<mpl::vector<Hoge *, intrusive_ptr<Hoge> > > Var;
            Var v1(p1);
            {
                intrusive_ptr<Hoge> &p = v1.Get<intrusive_ptr<Hoge> >();
                ASSERT_EQ(2, p->m_useCount);

                Var v2;
                v1.Copy<intrusive_ptr<Hoge> >(v2);
                ASSERT_EQ(3, p->m_useCount);

                v2.Clear<intrusive_ptr<Hoge> >();
                ASSERT_EQ(2, p->m_useCount);
            }

            {
                intrusive_ptr<Hoge> p = v1.Detach<intrusive_ptr<Hoge> >();
                ASSERT_EQ(1, p->m_useCount);

                v1.Clear<intrusive_ptr<Hoge> >();
                ASSERT_EQ(1, p->m_useCount);
            }

            //{
            //    Hoge *&p = v1.Get<Hoge *>();
            //}
        }

        BOOST_MPL_ASSERT((mpl::not_<IsLikePointer<int> >));
        BOOST_MPL_ASSERT((IsLikePointer<int *>));
        typedef Hoge *(intrusive_ptr<Hoge>::*PointerMemberAccessor)() const;
        //typedef Identify<Hoge *(intrusive_ptr<Hoge>::*)() const, &intrusive_ptr<Hoge>::operator-> > AAAA;
        //PointerMemberAccessor pma = &intrusive_ptr<Hoge>::operator->;
        //typedef CPP_ANONYM_HAS_MEMBER_FUNCTION(PointerMemberAccessorS, intrusive_ptr<Hoge>)::type AAAAA;
        //BOOST_MPL_ASSERT((AAAAA));
        //BOOST_MPL_ASSERT((boost::is_same<mpl::identity<IsLikePointer<intrusive_ptr<Hoge> >::type>::type, int>));
        BOOST_MPL_ASSERT((IsLikePointer<intrusive_ptr<Hoge> >));
        BOOST_MPL_ASSERT((IsLikePointer<shared_ptr<Hoge> >));

        //Piyo piyo(10);

    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        SemiAutoPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_02)
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

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_03)
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

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_04)
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

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_05)
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

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_06)
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

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_07)
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

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_08)
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

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_09)
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

    TEST(Urasandesu_CppAnonym_Utilities_SemiAutoPtrTest, Test_10)
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
#ifdef _DEBUG
        ASSERT_LT(veryQuickElapsed, defaultElapsed * 2.0);
#else
        ASSERT_LT(veryQuickElapsed, defaultElapsed);
#endif
    }

}
