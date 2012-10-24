﻿#pragma once
#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HXX
#define URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HXX

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDER_H
#include <Urasandesu/CppAnonym/ApiHolders/DefaultCppAnonymStorageApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_H
#include <Urasandesu/CppAnonym/BaseCppAnonymStorage.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template class BaseCppAnonymStorage<>;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HXX