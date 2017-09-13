/* 
 * File: PersistableHeapProviderTest.cpp
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
#include <gtest/gtest.h>

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_H
#include <Urasandesu/CppAnonym/PersistableHeapProvider.h>
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

            std::vector<size_t> m_ctorSeq;
            std::vector<size_t> m_dtorSeq;
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

            HogePersistedHandler();
            void operator()(sender_type *pSender, void *pArg);
        };

        struct Hoge : 
            HogeFacade::base_heap_provider_type
        {
            typedef HogeFacade facade;
            typedef facade::hoge_type hoge_type;
            typedef facade::hoge_persisted_handler_type hoge_persisted_handler_type;
            typedef facade::hoge_persistent_info_type hoge_persistent_info_type;
            typedef facade::hoge_provider_type hoge_provider_type;

            Hoge() { OrderChecker::Instance().m_ctorSeq.push_back(reinterpret_cast<size_t>(this)); }
            
            ~Hoge() 
            { 
                OrderChecker::Instance().m_dtorSeq.push_back(reinterpret_cast<size_t>(this)); 
                if (!m_objects.empty())   // root
                {
                    auto &sHoge = MyStorage::Object<hoge_type>();
                    auto &provider = sHoge.ProviderOf<hoge_persistent_info_type>();
                    BOOST_FOREACH (auto const &pObj, m_objects)
                        provider.DeleteObject(pObj);
                }
            }

            static hoge_type *CreateStaticHoge()
            {
                auto pHoge = NewStaticHoge();
                pHoge.Persist();
                return pHoge.Get();
            }

            static Utilities::TempPtr<hoge_type> NewStaticHoge()
            {
                auto &sHoge = MyStorage::Object<hoge_type>();
                auto &provider = sHoge.ProviderOf<hoge_persistent_info_type>();
                auto pHoge = provider.NewObject();
                auto handler = hoge_persisted_handler_type();
                provider.AddPersistedHandler(pHoge, handler);
                return pHoge;
            }
            
            hoge_type *CreateHoge()
            {
                auto pHoge = NewHoge();
                pHoge.Persist();
                return pHoge.Get();
            }

            Utilities::TempPtr<hoge_type> NewHoge()
            {
                auto &sHoge = MyStorage::Object<hoge_type>();
                auto &provider = sHoge.ProviderOf<hoge_persistent_info_type>();
                auto pHoge = provider.NewObject();
                auto handler = hoge_persisted_handler_type();
                provider.AddPersistedHandler(pHoge, handler);
                return pHoge;
            }

            std::vector<hoge_type *> m_objects;
        };

        HogePersistedHandler::HogePersistedHandler()
        { }
                
        void HogePersistedHandler::operator()(sender_type *pSender, void *pArg)
        {
            auto &pHoge = *pSender;
            auto &sHoge = MyStorage::Object<hoge_type>();
            auto &provider = sHoge.ProviderOf<hoge_persistent_info_type>();
            provider.RegisterObject(pHoge);
            sHoge.m_objects.push_back(pHoge.Get());
        }

    }   // namespace _E0BB97B4 {

    CPPANONYM_TEST(Urasandesu_CppAnonym_PersistableHeapProviderTest, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace _E0BB97B4;

        Hoge &sHoge = MyStorage::Object<Hoge>();
        Hoge *pHogeRoot = Hoge::CreateStaticHoge();
        Hoge *pHoge = pHogeRoot->CreateHoge();

        ASSERT_EQ(3, OrderChecker::Instance().m_ctorSeq.size());
        ASSERT_EQ(reinterpret_cast<size_t>(&sHoge), OrderChecker::Instance().m_ctorSeq[0]);
        ASSERT_EQ(reinterpret_cast<size_t>(pHogeRoot), OrderChecker::Instance().m_ctorSeq[1]);
        ASSERT_EQ(reinterpret_cast<size_t>(pHoge), OrderChecker::Instance().m_ctorSeq[2]);
        ASSERT_EQ(0, OrderChecker::Instance().m_dtorSeq.size());

        StaticDependentObjectsStorageDetail::HostAccessor<Hoge>::Host().~Host();

        ASSERT_EQ(3, OrderChecker::Instance().m_dtorSeq.size());
        ASSERT_EQ(reinterpret_cast<size_t>(&sHoge), OrderChecker::Instance().m_dtorSeq[0]);
        ASSERT_EQ(reinterpret_cast<size_t>(pHogeRoot), OrderChecker::Instance().m_dtorSeq[1]);
        ASSERT_EQ(reinterpret_cast<size_t>(pHoge), OrderChecker::Instance().m_dtorSeq[2]);

        // Restore static area to work the debug heap correctly.
        new(&StaticDependentObjectsStorageDetail::HostAccessor<Hoge>::Host())Host();
    }

}
