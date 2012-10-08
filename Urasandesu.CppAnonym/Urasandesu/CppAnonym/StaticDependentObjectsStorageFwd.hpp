﻿#pragma once
#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP
#define URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_LIMIT_TYPES, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_LIMIT_TYPES, param)

    namespace StaticDependentObjectsStorageDetail {

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        struct DependentObjectsProvidersHost;

        template<class T0, CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_ENUM_SHIFTED_PARAMS(class T)>
        class StaticDependentObjectsStorageImpl;

        template<CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_AUX_DECLARE_PARAMS>
        struct HostAccessor;

    }   // namespace StaticDependentObjectsStorageDetail {

    template<CPPANONYM_STATIC_DEPENDENT_OBJECTS_STORAGE_AUX_DECLARE_PARAMS>
    struct StaticDependentObjectsStorage;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGEFWD_HPP