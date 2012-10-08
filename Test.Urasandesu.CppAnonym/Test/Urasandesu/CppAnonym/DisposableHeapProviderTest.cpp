#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_DISPOSINGINFO_HPP
#include <Urasandesu/CppAnonym/DisposingInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_DisposableHeapProviderTest.*
namespace {

    namespace _731D234E {

        struct Piyo;
        struct pPiyo_Persisted;

    }   // namespace _731D234E {

    namespace _731D234E {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef mpl::vector<Piyo> Types;
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
            std::vector<int> m_disposingOrder;
        };

        struct Piyo : 
            DisposableHeapProvider<
                boost::mpl::vector<
                    DisposingInfo<Piyo, pPiyo_Persisted>
                >
            >
        {
            typedef providing_type_at<0>::type piyo_type;
            typedef provider_of<piyo_type>::type piyo_provider_type;

            Piyo() { OrderChecker::Instance().m_ctorOrder.push_back(reinterpret_cast<int>(this)); }
            ~Piyo() { OrderChecker::Instance().m_dtorOrder.push_back(reinterpret_cast<int>(this)); }

            static piyo_type *CreateStaticPiyo()
            {
                Utilities::TempPtr<piyo_type> pPiyo = NewStaticPiyo();
                pPiyo.Persist();
                return pPiyo.Get();
            }

            static Utilities::TempPtr<piyo_type> NewStaticPiyo()
            {
                piyo_type &sPiyo = MyStorage::Object<piyo_type>();
                piyo_provider_type &provider = sPiyo.ProviderOf<piyo_type>();
                Utilities::TempPtr<piyo_type> pPiyo = provider.NewObject();
                provider.AddPersistedHandler(pPiyo, &sPiyo);
                return pPiyo;
            }
            
            piyo_type *CreatePiyo()
            {
                Utilities::TempPtr<piyo_type> pPiyo = NewPiyo();
                pPiyo.Persist();
                return pPiyo.Get();
            }

            Utilities::TempPtr<piyo_type> NewPiyo()
            {
                piyo_provider_type &provider = ProviderOf<piyo_type>();
                Utilities::TempPtr<piyo_type> pPiyo = provider.NewObject();
                provider.AddPersistedHandler(pPiyo, this);
                return pPiyo;
            }

            void Dispose()
            {
                OrderChecker::Instance().m_disposingOrder.push_back(reinterpret_cast<int>(this));
            }
        };

        struct pPiyo_Persisted
        {
            typedef Utilities::TempPtr<Piyo> sender_type;

            pPiyo_Persisted(Piyo *pPiyo) : 
                m_pPiyo(pPiyo)
            { 
                _ASSERTE(pPiyo != NULL);
            }
                
            void operator()(sender_type *pSender, void *pArg)
            {
                sender_type &pPiyo = *pSender;
                typedef Piyo::piyo_provider_type piyo_provider_type;
                piyo_provider_type &provider = m_pPiyo->ProviderOf<Piyo>();
                provider.RegisterObject(pPiyo);
            }
                
            Piyo *m_pPiyo;
        };

    }   // namespace _731D234E {

    CPPANONYM_TEST(Urasandesu_CppAnonym_DisposableHeapProviderTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace _731D234E;

        Piyo &sPiyo = MyStorage::Object<Piyo>();
        Piyo *pPiyoRoot = Piyo::CreateStaticPiyo();
        Piyo *pPiyo = pPiyoRoot->CreatePiyo();

        ASSERT_EQ(3, OrderChecker::Instance().m_ctorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&sPiyo), OrderChecker::Instance().m_ctorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(pPiyoRoot), OrderChecker::Instance().m_ctorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(pPiyo), OrderChecker::Instance().m_ctorOrder[2]);
        ASSERT_EQ(0, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(0, OrderChecker::Instance().m_disposingOrder.size());

        StaticDependentObjectsStorageDetail::Host<Types>().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(&sPiyo), OrderChecker::Instance().m_dtorOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(pPiyoRoot), OrderChecker::Instance().m_dtorOrder[1]);
        ASSERT_EQ(reinterpret_cast<int>(pPiyo), OrderChecker::Instance().m_dtorOrder[2]);

        ASSERT_EQ(2, OrderChecker::Instance().m_disposingOrder.size());
        ASSERT_EQ(reinterpret_cast<int>(pPiyoRoot), OrderChecker::Instance().m_disposingOrder[0]);
        ASSERT_EQ(reinterpret_cast<int>(pPiyo), OrderChecker::Instance().m_disposingOrder[1]);

        // Restore static area to work the debug heap correctly.
        new(&StaticDependentObjectsStorageDetail::Host<Types>())Host();
    }

}
