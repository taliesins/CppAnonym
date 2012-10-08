﻿#pragma once
#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGEFWD_HPP
#define URASANDESU_CPPANONYM_BASECPPANONYMSTORAGEFWD_HPP

#ifndef URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/ApiHolders/DefaultCppAnonymStorageApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<
        class CppAnonymStorageApiHolder = ApiHolders::DefaultCppAnonymStorageApiHolder
    >    
    class BaseCppAnonymStorage;

    typedef BaseCppAnonymStorage<> CppAnonymStorage;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_BASECPPANONYMSTORAGEFWD_HPP