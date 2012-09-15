#pragma once
#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#define URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_HPP
#include <Urasandesu/CppAnonym/DependentObjectsProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorageFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

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

#endif  // #ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP