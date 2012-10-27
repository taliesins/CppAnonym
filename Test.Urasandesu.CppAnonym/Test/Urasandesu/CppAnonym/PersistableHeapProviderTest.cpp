#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_PersistableHeapProviderTest.*
namespace {

    namespace _E0BB97B4 {

        struct Hoge;
        struct HogePersistedHandler;

    }   // namespace _E0BB97B4 {

    namespace _E0BB97B4 {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef StaticDependentObjectsStorage<Hoge> MyStorage;
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

        struct HogeFacade
        {
            typedef Hoge hoge_type;
            typedef HogePersistedHandler hoge_persisted_handler_type;
            typedef PersistentInfo<hoge_type, hoge_persisted_handler_type> hoge_persistent_info_type;

            
            typedef PersistableHeapProvider<
                hoge_persistent_info_type
            > base_heap_provider_type;
            
            
            typedef base_heap_provider_type::provider_of<hoge_persistent_info_type>::type hoge_provider_type;
        };

        struct HogePersistedHandler
        {
            typedef HogeFacade facade;
            typedef facade::hoge_type hoge_type;
            typedef facade::hoge_persisted_handler_type hoge_persisted_handler_type;
            typedef facade::hoge_persistent_info_type hoge_persistent_info_type;
            typedef facade::hoge_provider_type hoge_provider_type;

            typedef Utilities::TempPtr<hoge_type> sender_type;

            HogePersistedHandler(hoge_type *pHoge);
            void operator()(sender_type *pSender, void *pArg);

            hoge_type *m_pHoge;
        };

        struct Hoge : 
            HogeFacade::base_heap_provider_type
        {
            typedef HogeFacade facade;
            typedef facade::hoge_type hoge_type;
            typedef facade::hoge_persisted_handler_type hoge_persisted_handler_type;
            typedef facade::hoge_persistent_info_type hoge_persistent_info_type;
            typedef facade::hoge_provider_type hoge_provider_type;

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
                hoge_provider_type &provider = sHoge.ProviderOf<hoge_persistent_info_type>();
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
                hoge_provider_type &provider = ProviderOf<hoge_persistent_info_type>();
                Utilities::TempPtr<hoge_type> pHoge = provider.NewObject();
                provider.AddPersistedHandler(pHoge, this);
                return pHoge;
            }
        };

        HogePersistedHandler::HogePersistedHandler(hoge_type *pHoge) : 
            m_pHoge(pHoge)
        { 
            _ASSERTE(pHoge != NULL);
        }
                
        void HogePersistedHandler::operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pHoge = *pSender;
            hoge_provider_type &provider = m_pHoge->ProviderOf<hoge_persistent_info_type>();
            provider.RegisterObject(pHoge);
        }

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

        StaticDependentObjectsStorageDetail::HostAccessor<Hoge>::Host().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&sHoge), OrderChecker::Instance().m_dtorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(pHogeRoot), OrderChecker::Instance().m_dtorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(pHoge), OrderChecker::Instance().m_dtorOrder[2]);

        // Restore static area to work the debug heap correctly.
        new(&StaticDependentObjectsStorageDetail::HostAccessor<Hoge>::Host())Host();
    }

}
