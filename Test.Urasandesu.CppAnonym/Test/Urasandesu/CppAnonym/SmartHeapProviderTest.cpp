#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP
#include <Urasandesu/CppAnonym/DependentObjectsProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.hpp>
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

            std::vector<int> m_ctorOrder;
            std::vector<int> m_dtorOrder;
        };

        struct Foo : 
            SmartHeapProvider<Foo>
        {
            typedef providing_type_at<0>::type foo_type;
            typedef provider_of<foo_type>::type foo_provider_type;

            Foo() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Foo() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }

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

            ASSERT_EQ(3, OrderChecker::Instance().m_ctorOrder.size());
            ASSERT_EQ(sFooAddr, OrderChecker::Instance().m_ctorOrder[0]);
            ASSERT_EQ(pFooRootAddr, OrderChecker::Instance().m_ctorOrder[1]);
            ASSERT_EQ(pFooAddr, OrderChecker::Instance().m_ctorOrder[2]);
            ASSERT_EQ(0, OrderChecker::Instance().m_dtorOrder.size());
        }
        ASSERT_EQ(2, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(pFooAddr, OrderChecker::Instance().m_dtorOrder[0]);
        ASSERT_EQ(pFooRootAddr, OrderChecker::Instance().m_dtorOrder[1]);

        StaticDependentObjectsStorageDetail::HostAccessor<Foo>::Host().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(sFooAddr, OrderChecker::Instance().m_dtorOrder[2]);

        // Restore static area to work the debug heap correctly.
        new(&StaticDependentObjectsStorageDetail::HostAccessor<Foo>::Host())Host();
    }

}
