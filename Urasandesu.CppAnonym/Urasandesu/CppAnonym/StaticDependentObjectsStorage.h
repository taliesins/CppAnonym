#pragma once
#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#define URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorageFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace StaticDependentObjectsStorageDetail {

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        struct DependentObjectsProvidersHost : 
            DependentObjectsProvider<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>
        {
        };

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        class StaticDependentObjectsStorageImpl
        {
        public:
            typedef DependentObjectsProvidersHost<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)> host_type;
        
            template<class T>
            static T &Object()
            {
                typedef typename host_type::provider_of<T>::type provider_type;
                provider_type &provider = Host().ProviderOf<T>();
                return provider.Object();
            }

        private:
            template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
            friend struct HostAccessor;

            static host_type &Host()
            {
                static host_type host;
                return host;
            }
        };

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        struct HostAccessor
        {
            static DependentObjectsProvidersHost<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)> &Host()
            {
                return StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::Host();
            }
        };

    }   // namespace StaticDependentObjectsStorageDetail {

    template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
    struct StaticDependentObjectsStorage : 
        StaticDependentObjectsStorageDetail::StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H