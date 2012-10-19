#pragma once
#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP
#define URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace StaticDependentObjectsStorageDetail {

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        template<class T>
        inline T &StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::Object()
        {
            typedef typename host_type::provider_of<T>::type provider_type;
            provider_type &provider = Host().ProviderOf<T>();
            return provider.Object();
        }

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        inline typename StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::host_type &
            StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::Host()
        {
            static host_type host;
            return host;
        }

        
        
        
        
        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        inline DependentObjectsProvidersHost<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)> &
            HostAccessor<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::Host()
        {
            return StaticDependentObjectsStorageImpl<T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(T)>::Host();
        }

    }   // namespace StaticDependentObjectsStorageDetail {

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_HPP