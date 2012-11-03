#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEFACADE_H
#define URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEFACADE_H

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEAPIAT_H
#include <Urasandesu/CppAnonym/CppAnonymStorageDetail/CppAnonymStorageApiAt.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEFACADEFWD_H
#include <Urasandesu/CppAnonym/CppAnonymStorageDetail/CppAnonymStorageFacadeFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace CppAnonymStorageDetail {

    namespace CppAnonymStorageFacadeDetail {

        using Urasandesu::CppAnonym::Hosting::Interfaces::HostInfoLabel;

        template<
            class CppAnonymStorageApiHolder
        >    
        struct CppAnonymStorageFacadeImpl
        {
            typedef typename CppAnonymStorageApiAt<CppAnonymStorageApiHolder, HostInfoLabel>::type host_info_type;
            typedef StaticDependentObjectsStorage<host_info_type> base_type;
        };

    }   // namespace CppAnonymStorageFacadeDetail {

    template<
        class CppAnonymStorageApiHolder
    >    
    struct CppAnonymStorageFacade : 
        CppAnonymStorageFacadeDetail::CppAnonymStorageFacadeImpl<CppAnonymStorageApiHolder>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace CppAnonymStorageDetail {

#endif  // URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEFACADE_H