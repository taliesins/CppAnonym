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

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Traits {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym {

    namespace DependentObjectsProviderDetail {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ReversedProvidingTypes, class I, class IEnd>
        class ATL_NO_VTABLE DependentObjectsProviderImplImpl : 
            public DependentObjectsProviderImplImpl<ReversedProvidingTypes, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DependentObjectsProviderImplImpl<ReversedProvidingTypes, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;

            object_type &Object()
            {
                if (!m_pObject)
                    m_pObject = make_shared<object_type>();
                return *m_pObject.get();
            }

        private:
            shared_ptr<object_type> m_pObject;
        };

        template<class ReversedProvidingTypes>
        class DependentObjectsProviderImplImpl<ReversedProvidingTypes, 
                                               typename mpl::end<ReversedProvidingTypes>::type, 
                                               typename mpl::end<ReversedProvidingTypes>::type> : 
            noncopyable
        {
        };

        template<class ReversedProvidingTypes, class ProvidingType>
        class ProviderOfImpl
        {
            typedef typename mpl::find<ReversedProvidingTypes, ProvidingType>::type i;
            typedef typename mpl::end<ReversedProvidingTypes>::type i_end;
        public:
            typedef DependentObjectsProviderImplImpl<ReversedProvidingTypes, i, i_end> type;
        };

        template<class ProvidingTypes>
        struct ATL_NO_VTABLE DependentObjectsProviderImpl : 
            DependentObjectsProviderImplImpl<typename mpl::reverse<ProvidingTypes>::type, 
                                             typename mpl::begin<typename mpl::reverse<ProvidingTypes>::type>::type, 
                                             typename mpl::end<typename mpl::reverse<ProvidingTypes>::type>::type>
        {
            typedef DependentObjectsProviderImpl<ProvidingTypes> this_type;
            typedef ProvidingTypes providing_types;

            template<LONG N>
            struct providing_type_at : 
                mpl::at_c<providing_types, N>
            {
            };

            template<class ProvidingType>
            struct provider_of : 
                ProviderOfImpl<typename mpl::reverse<ProvidingTypes>::type, ProvidingType>
            {
            };

            template<class ProvidingType>
            inline typename provider_of<ProvidingType>::type &ProviderOf() const
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                return static_cast<typename provider_of<ProvidingType>::type &>(*pMutableThis);
            }
        };

    }   // namespace DependentObjectsProviderDetail {

    template<class ProvidingTypes>
    struct ATL_NO_VTABLE DependentObjectsProvider : 
        DependentObjectsProviderDetail::DependentObjectsProviderImpl<ProvidingTypes>
    {
    };

    
    
    
    
    namespace StaticDependentObjectsStorageDetail {

        template<class Types>
        struct DependentObjectsProvidersHost : 
            DependentObjectsProvider<Types>
        {
        };

        template<class Types>
        class StaticDependentObjectsStorageImpl
        {
        public:
            typedef DependentObjectsProvidersHost<Types> host_type;
        
            template<class T>
            static T &Object()
            {
                typedef typename host_type::provider_of<T>::type provider_type;
                provider_type &provider = Host().ProviderOf<T>();
                return provider.Object();
            }

        private:
            static host_type &Host()
            {
                static host_type host;
                return host;
            }
        };

    }   // namespace StaticDependentObjectsStorageDetail {

    template<class Types>
    struct StaticDependentObjectsStorage : 
        StaticDependentObjectsStorageDetail::StaticDependentObjectsStorageImpl<Types>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_TempPtr.*
namespace {
    
    TEST(Urasandesu_CppAnonym_Utilities_StaticDependentObjectsStorage, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef StaticDependentObjectsStorage<mpl::vector<int, long, float, double> > MyStorage;

        MyStorage::Object<int>() = 10;
        MyStorage::Object<long>() = 20L;
        MyStorage::Object<float>() = 30.f;
        MyStorage::Object<double>() = 40.;

        ASSERT_EQ(10, MyStorage::Object<int>());
        ASSERT_EQ(20L, MyStorage::Object<long>());
        ASSERT_EQ(30.f, MyStorage::Object<float>());
        ASSERT_EQ(40., MyStorage::Object<double>());
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

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

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

        ASSERT_EQ(0, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }

    
    
    
    
    TEST(Urasandesu_CppAnonym_Utilities_TempPtr, Test_04)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace _85245FB6;

        typedef DefaultDeleterWithCount Deleter;
        std::vector<int *> garbages;
        Deleter::m_count = 0;
        Deleter deleter;

        typedef TempPtr<int>::persisted_handler_impl_type<Handler, Deleter>::type PersistedHandlerImpl;

        { 
            TempPtr<int> p(new int(10), deleter);
            p.AddPersistedHandler(new PersistedHandlerImpl(Handler(deleter), deleter));
            ASSERT_FALSE(p.IsPersisted());
            ASSERT_FALSE(deleter.m_called);
            p.Persist();
            garbages.push_back(p.Get());
            ASSERT_TRUE(p.IsPersisted());
            ASSERT_TRUE(deleter.m_called);
        }

        ASSERT_EQ(1, Deleter::m_count);
        
        typedef std::vector<int *>::iterator Iterator;
        for (Iterator i = garbages.begin(), i_end = garbages.end(); i != i_end; ++i)
            deleter(*i);
    }
}
