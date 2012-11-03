#pragma once
#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_H
#define URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEFACADE_H
#include <Urasandesu/CppAnonym/CppAnonymStorageDetail/CppAnonymStorageFacade.h>
#endif

#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGEFWD_H
#include <Urasandesu/CppAnonym/BaseCppAnonymStorageFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<
        class CppAnonymStorageApiHolder
    >    
    class BaseCppAnonymStorage : 
        public CppAnonymStorageDetail::CppAnonymStorageFacade<CppAnonymStorageApiHolder>::base_type
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_H