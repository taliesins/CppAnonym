#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_PersistableHeapProviderTest.*
namespace {

    namespace _E0BB97B4 {

        struct Hoge;
        struct pHoge_Persisted;

    }   // namespace _E0BB97B4 {

    namespace _E0BB97B4 {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef mpl::vector<Hoge> Types;
        typedef StaticDependentObjectsStorage<Types> MyStorage;
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

        struct Hoge : 
            PersistableHeapProvider<
                boost::mpl::vector<
                    PersistentInfo<Hoge, pHoge_Persisted>
                >
            >
        {
            typedef providing_type_at<0>::type hoge_type;
            typedef provider_of<hoge_type>::type hoge_provider_type;

            Hoge() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Hoge() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }

            static hoge_type *CreateStaticHoge()
            {
                Utilities::TempPtr<hoge_type> pHoge = NewStaticHoge();
                pHoge.Persist();
                return pHoge.Get();
            }

            static Utilities::TempPtr<hoge_type> NewStaticHoge()
            {
                hoge_type &sHoge = MyStorage::Object<hoge_type>();
                hoge_provider_type &provider = sHoge.ProviderOf<hoge_type>();
                Utilities::TempPtr<hoge_type> pHoge = provider.NewObject();
                provider.AddPersistedHandler(pHoge, &sHoge);
                return pHoge;
            }
            
            hoge_type *CreateHoge()
            {
                Utilities::TempPtr<hoge_type> pHoge = NewHoge();
                pHoge.Persist();
                return pHoge.Get();
            }

            Utilities::TempPtr<hoge_type> NewHoge()
            {
                hoge_provider_type &provider = ProviderOf<hoge_type>();
                Utilities::TempPtr<hoge_type> pHoge = provider.NewObject();
                provider.AddPersistedHandler(pHoge, this);
                return pHoge;
            }
        };

        struct pHoge_Persisted
        {
            typedef Utilities::TempPtr<Hoge> sender_type;

            pHoge_Persisted(Hoge *pHoge) : 
                m_pHoge(pHoge)
            { 
                _ASSERTE(pHoge != NULL);
            }
                
            void operator()(sender_type *pSender, void *pArg)
            {
                sender_type &pHoge = *pSender;
                typedef Hoge::hoge_provider_type hoge_provider_type;
                hoge_provider_type &provider = m_pHoge->ProviderOf<Hoge>();
                provider.RegisterObject(pHoge);
            }
                
            Hoge *m_pHoge;
        };

    }   // namespace _E0BB97B4 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_PersistableHeapProviderTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace _E0BB97B4;

        Hoge &sHoge = MyStorage::Object<Hoge>();
        Hoge *pHogeRoot = Hoge::CreateStaticHoge();
        Hoge *pHoge = pHogeRoot->CreateHoge();

        ASSERT_EQ(3, OrderChecker::Instance().m_ctorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&sHoge), OrderChecker::Instance().m_ctorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(pHogeRoot), OrderChecker::Instance().m_ctorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(pHoge), OrderChecker::Instance().m_ctorOrder[2]);
        ASSERT_EQ(0, OrderChecker::Instance().m_dtorOrder.size());

        StaticDependentObjectsStorageDetail::Host<Types>().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&sHoge), OrderChecker::Instance().m_dtorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(pHogeRoot), OrderChecker::Instance().m_dtorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(pHoge), OrderChecker::Instance().m_dtorOrder[2]);

        // Restore static area to work the debug heap correctly.
        new(&StaticDependentObjectsStorageDetail::Host<Types>())Host();
    }

}
