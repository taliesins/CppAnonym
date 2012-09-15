#pragma once
#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP
#define URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP

namespace Urasandesu { namespace CppAnonym {

    namespace StaticDependentObjectsStorageDetail {

        template<class Types>
        struct DependentObjectsProvidersHost;

        template<class Types>
        class StaticDependentObjectsStorageImpl;

    }   // namespace StaticDependentObjectsStorageDetail {

    template<class Types>
    struct StaticDependentObjectsStorage;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP