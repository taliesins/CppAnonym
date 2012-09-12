#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtrFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace Interfaces {

    struct InfrastructureFactoryApiHolderLabel { };
    struct InfrastructureFactoryLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

    struct DefaultInfrastructureFactoryApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<
        class InfrastructureFactoryApiHolder = ApiHolders::DefaultInfrastructureFactoryApiHolder
    >
    struct BaseInfrastructureFactory;

    typedef BaseInfrastructureFactory<> InfrastructureFactory;

    
    
    
    
    namespace SimpleHeapFactoryDetail {

        template<class FactoryTypes, class I, class IEnd>
        struct ATL_NO_VTABLE FactoryStorageImpl;

        template<class FactoryTypes, class FactoryType>
        class FactoryOfImpl;

        template<class FactoryTypes>
        struct FactoryStorage;

        template<class FactoryTypes>
        class SimpleHeapFactoryImpl;

    }   // namespace SimpleHeapFactoryDetail {

    template<class FactoryTypes>
    struct SimpleHeapFactory;

    struct DefaultHeapFactory;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Traits {

//    template<class T, T> struct Identify;
//
//// NOTE: enum { n = sizeof(T) }; is intended for to exclude any incomplete types.
//#define CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(name, member, member_ret, member_params) \
//    template<class T, class Tag = boost::mpl::void_> \
//    struct Has_##name##_##member \
//    { \
//        enum { n = sizeof(T) }; \
//        typedef boost::mpl::false_ type; \
//        static const bool value = false; \
//    }; \
//     \
//    template<class T> \
//    struct Has_##name##_##member<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, Urasandesu::CppAnonym::Traits::Identify<member_ret(T::*)member_params, &T::member> >::type> \
//    { \
//        typedef boost::mpl::true_ type; \
//        static const bool value = true; \
//    };
//
//#define CPP_ANONYM_USING_HAS_MEMBER_FUNCTION(name, member) \
//    Has_##name##_##member
//
//#define CPP_ANONYM_HAS_MEMBER_FUNCTION(name, member, t) \
//    Has_##name##_##member<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

    namespace DefaultInfrastructureFactoryApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;

        struct DefaultInfrastructureFactoryApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>
            > api_cartridges;
        };

    }   // namespace DefaultInfrastructureFactoryApiHolderDetail {

    struct DefaultInfrastructureFactoryApiHolder : 
        DefaultInfrastructureFactoryApiHolderDetail::DefaultInfrastructureFactoryApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct InfrastructureFactoryApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::InfrastructureFactoryApiHolderLabel, ApiLabel>
    {
    };

    namespace InfrastructureFactoryDetail {

        template<
            class InfrastructureFactoryApiHolder
        >
        struct BaseInfrastructureFactoryImpl
        {
            typedef typename InfrastructureFactoryApiAt<InfrastructureFactoryApiHolder, Hosting::Interfaces::HostInfoLabel>::type host_info_type;
            typedef typename TempPtr<host_info_type>::holder_impl_type host_info_infra_type;

            typedef SimpleHeapFactory<
                boost::mpl::vector<
                    host_info_infra_type
                >
            > factory_type;
        };

    }   // namespace InfrastructureFactoryDetail {

    template<
        class InfrastructureFactoryApiHolder
    >
    struct BaseInfrastructureFactory : 
        InfrastructureFactoryDetail::BaseInfrastructureFactoryImpl<InfrastructureFactoryApiHolder>::factory_type
    {
    }; 
    
    
    
    namespace SimpleHeapFactoryDetail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class FactoryTypes, class I, class IEnd>
        struct ATL_NO_VTABLE FactoryStorageImpl : 
            FactoryStorageImpl<FactoryTypes, typename mpl::next<I>::type, IEnd>
        {
            typedef FactoryStorageImpl<FactoryTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef SimpleHeap<object_type, QuickHeapWithoutSubscriptOperator> object_heap_type;

            object_heap_type m_heap;
        };

        template<class FactoryTypes>
        struct ATL_NO_VTABLE FactoryStorageImpl<FactoryTypes, 
                                                typename mpl::end<FactoryTypes>::type, 
                                                typename mpl::end<FactoryTypes>::type> : 
            noncopyable
        {
        };

        template<class FactoryTypes, class FactoryType>
        class FactoryOfImpl
        {
            typedef FactoryTypes factory_types;
            typedef typename mpl::find<factory_types, FactoryType>::type i;
            typedef typename mpl::end<FactoryTypes>::type i_end;
        public:
            typedef FactoryStorageImpl<FactoryTypes, i, i_end> type;
        };

        template<class FactoryTypes>
        struct FactoryStorage : 
            FactoryStorageImpl<FactoryTypes, 
                               typename mpl::begin<FactoryTypes>::type, 
                               typename mpl::end<FactoryTypes>::type>
        {
            typedef FactoryStorage<FactoryTypes> this_type;
            typedef FactoryTypes factory_types;

            template<class FactoryType>
            class factory_of : 
                public FactoryOfImpl<factory_types, FactoryType>
            {
            };

            template<class FactoryType>
            inline typename factory_of<FactoryType>::type &FactoryOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename factory_of<FactoryType>::type &>(*pMutableThis);
            }
        };

        template<class FactoryTypes>
        class SimpleHeapFactoryImpl
        {
        public:
            typedef FactoryStorage<typename mpl::reverse<FactoryTypes>::type> factory_storage_type;

            template<LONG N>
            struct factory_type_at : 
                boost::mpl::at_c<FactoryTypes, N>
            {
            };

            template<class FactoryType>
            struct factory_of : 
                factory_storage_type::template factory_of<FactoryType>
            {
            };

            template<class FactoryType>
            static FactoryType *New()
            {
                return Heap<FactoryType>().New();
            }

            template<class FactoryType, class A1>
            static FactoryType *New(A1 arg1)
            {
                return Heap<FactoryType>().New(arg1);
            }

            template<class FactoryType, class A1, class A2>
            static FactoryType *New(A1 arg1, A2 arg2)
            {
                return Heap<FactoryType>().New(arg1, arg2);
            }

            template<class FactoryType>
            static void Delete(FactoryType *p)
            {
                return Heap<FactoryType>().Delete(p);
            }

        private:
            template<class FactoryType>
            static SimpleHeap<FactoryType, QuickHeapWithoutSubscriptOperator> &Heap()
            {
                return Storage().FactoryOf<FactoryType>().m_heap;
            }

            static factory_storage_type &Storage()
            {
                static factory_storage_type storage;
                return storage;
            }
        };

    }   // namespace SimpleHeapFactoryDetail {

    template<class FactoryTypes>
    struct SimpleHeapFactory : 
        SimpleHeapFactoryDetail::SimpleHeapFactoryImpl<FactoryTypes>
    {
    };


    struct DefaultHeapFactory
    {
    //public:
        //typedef FactoryStorage<typename mpl::reverse<FactoryTypes>::type> factory_storage_type;

        //template<LONG N>
        //struct factory_type_at : 
        //    boost::mpl::at_c<FactoryTypes, N>
        //{
        //};

        //template<class FactoryType>
        //struct factory_of : 
        //    factory_storage_type::template factory_of<FactoryType>
        //{
        //};

        template<class FactoryType>
        static FactoryType *New()
        {
            return SimpleHeap<FactoryType, DefaultHeapWithoutSubscriptOperator>().New();
        }

        template<class FactoryType, class A1>
        static FactoryType *New(A1 arg1)
        {
            return SimpleHeap<FactoryType, DefaultHeapWithoutSubscriptOperator>().New(arg1);
        }

        template<class FactoryType, class A1, class A2>
        static FactoryType *New(A1 arg1, A2 arg2)
        {
            return SimpleHeap<FactoryType, DefaultHeapWithoutSubscriptOperator>().New(arg1, arg2);
        }

        template<class FactoryType>
        static void Delete(FactoryType *p)
        {
            return SimpleHeap<FactoryType, DefaultHeapWithoutSubscriptOperator>().Delete(p);
        }

    //private:
        //static factory_storage_type &Storage()
        //{
        //    static factory_storage_type storage;
        //    return storage;
        //}
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_TempPtr.*
namespace {

    namespace _6DF959DB {

#define HAS_MEM_FUNC(func, name) \
    template<typename T, typename Sign> \
    struct name { \
        typedef char yes[1]; \
        typedef char no [2]; \
        template <typename U, U> struct type_check; \
        template <typename _1> static yes &chk(type_check<Sign, &_1::func> *); \
        template <typename   > static no  &chk(...); \
        static bool const value = sizeof(chk<T>(0)) == sizeof(yes); \
    }

HAS_MEM_FUNC(ToString, HasToStringImpl);

        template<class T>
        struct HasToString
        {
            typedef boost::mpl::bool_<HasToStringImpl<T, std::string(T::*)()>::value> type;
        };

        struct Hoge
        {
        };

        struct Piyo
        {
            std::string ToString()
            {
                return "aiueo";
            }
        };

    }   // namespace _6DF959DB {

    TEST(Urasandesu_CppAnonym_Utilities_HasMemFunc, Test_01)
    {
        using namespace _6DF959DB;

        BOOST_MPL_ASSERT((boost::mpl::not_<HasToString<Hoge> >));
        BOOST_MPL_ASSERT((HasToString<Piyo>));
        //BOOST_MPL_ASSERT((boost::mpl::not_<HasToString<int> >));
    }





    namespace _7CD85B33 {

        namespace mpl = boost::mpl;

        template<class T, class Tag = boost::mpl::void_>
        struct HasToString
        {
            enum { n = sizeof(T) };
            typedef boost::mpl::false_ type;
            static const bool value = false;
        };
        
        template<class T, T> struct Identify;

        template<class T>
        struct HasToString<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, Identify<std::string(T::*)(), &T::ToString> >::type>
        {
            typedef boost::mpl::true_ type;
            static const bool value = true;
        };

        struct Hoge
        {
        };

        struct Piyo
        {
            std::string ToString()
            {
                return "aiueo";
            }
        };

        struct Huga
        {
            template<class T>
            T ToString()
            {
                return T();
            }
        };

        template<class T>
        struct Foo
        {
            T ToString()
            {
                return T();
            }
        };

#define HOGE(ret, params) \
    typedef ret(*MyFunc##params)

//#define HOGE(identity) \
//    typedef identity::type MyFunc;
    

        CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(Has, ToString, std::string, ());

    }   // namespace _7CD85B33 {

    TEST(Urasandesu_CppAnonym_Utilities_HasMemFunc, Test_02)
    {
        namespace mpl = boost::mpl;
        using _7CD85B33::HasToString;
        using _7CD85B33::Hoge;
        using _7CD85B33::Piyo;
        using _7CD85B33::Huga;
        using _7CD85B33::Foo;
        using _7CD85B33::CPP_ANONYM_USING_HAS_MEMBER_FUNCTION(Has, ToString);

        BOOST_MPL_ASSERT((mpl::not_<HasToString<Hoge> >));
        BOOST_MPL_ASSERT((HasToString<Piyo>));
        BOOST_MPL_ASSERT((mpl::not_<HasToString<int> >));
        BOOST_MPL_ASSERT((mpl::not_<CPP_ANONYM_HAS_MEMBER_FUNCTION(Has, ToString, Hoge)>));
        BOOST_MPL_ASSERT((CPP_ANONYM_HAS_MEMBER_FUNCTION(Has, ToString, Piyo)));
        BOOST_MPL_ASSERT((CPP_ANONYM_HAS_MEMBER_FUNCTION(Has, ToString, Huga)));
        BOOST_MPL_ASSERT((mpl::not_<CPP_ANONYM_HAS_MEMBER_FUNCTION(Has, ToString, Foo<int>)>));

        HOGE(std::string *, (int, int));                      // こっちかな？    
        //HOGE((mpl::identity<std::string(*(int, int))>));  // 括弧が入っちゃう・・・。
        //typedef std::string *(*MyFunc(int, int));
        BOOST_MPL_ASSERT((boost::is_same<MyFunc, std::string *(*(int, int))>));
    }





    TEST(Urasandesu_CppAnonym_Utilities_SimpleHeapFactory, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef SimpleHeapFactory<mpl::vector<int, long, float, double> > HeapFactory;

        int *i = HeapFactory::New<int>(10);
        long *l = HeapFactory::New<long>(47l);
        float *f = HeapFactory::New<float>(1.2f);
        double *d = HeapFactory::New<double>(4.7);

        ASSERT_EQ(10, *i);
        ASSERT_EQ(47l, *l);
        ASSERT_EQ(1.2f, *f);
        ASSERT_EQ(4.7, *d);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_SimpleHeapFactory, Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Utilities;

        typedef TempPtr<HostInfo>::object_heap_type HostInfoHeap;
        typedef TempPtr<HostInfo>::object_heap_deleter_type HostInfoHeapDeleter;
        typedef InfrastructureFactory::factory_type_at<0>::type HostInfoInfra;

        HostInfoHeap heap;
        HostInfoInfra *pHostInfoInfra = InfrastructureFactory::New<HostInfoInfra>(heap.New(), HostInfoHeapDeleter(heap));

        std::cout << reinterpret_cast<int>(pHostInfoInfra) << std::endl;

        //typedef SimpleHeapFactory<mpl::vector<int, long, float, double> > HeapFactory;

        //int *i = HeapFactory::Heap<int>().New(10);
        //long *l = HeapFactory::Heap<long>().New(47l);
        //float *f = HeapFactory::Heap<float>().New(1.2f);
        //double *d = HeapFactory::Heap<double>().New(4.7);

        //ASSERT_EQ(10, *i);
        //ASSERT_EQ(47l, *l);
        //ASSERT_EQ(1.2f, *f);
        //ASSERT_EQ(4.7, *d);
    }





    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        TempPtr<int> p;
        ASSERT_FALSE(p);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_02)
    {
        using namespace Urasandesu::CppAnonym::Utilities;

        TempPtr<int> p(new int(10));
        ASSERT_TRUE(p);
        ASSERT_EQ(10, *p);
    }

    
    
    
    
    namespace _85245FB6 {

        using namespace Urasandesu::CppAnonym::Utilities;

        struct DefaultDeleterWithCount : 
            DefaultDeleter
        {
            DefaultDeleterWithCount() : 
                m_called(false)
            { }

            template<class T>
            void operator()(T *p)
            {
                DefaultDeleter::operator()(p);
                ++m_count;
            }

            bool m_called;
            static int m_count;
        };

        int DefaultDeleterWithCount::m_count = 0;

        struct Handler
        {
            Handler(DefaultDeleterWithCount &deleter) : 
                m_pDeleter(&deleter)
            { }
            
            typedef TempPtr<int> sender_type;
            void operator()(sender_type *pSender, void *pArg)
            {
                sender_type &p = *pSender;
                p.Persist();    // test that no infinite loop...
                m_pDeleter->m_called = true;
            }

            DefaultDeleterWithCount *m_pDeleter;
        };

    }   // namespace _85245FB6 {

    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_03)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        std::vector<int *> garbages;
        DefaultDeleterWithCount::m_count = 0;
        DefaultDeleterWithCount deleter;

        { 
            TempPtr<int> p(new int(10), deleter);
            p.AddPersistedHandler(Handler(deleter));
            ASSERT_FALSE(p.IsPersisted());
            ASSERT_FALSE(deleter.m_called);
            p.Persist();
            garbages.push_back(p.Get());
            ASSERT_TRUE(p.IsPersisted());
            ASSERT_TRUE(deleter.m_called);
        }

        ASSERT_EQ(0, DefaultDeleterWithCount::m_count);
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }
}
