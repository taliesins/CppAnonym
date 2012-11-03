#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEAPIAT_H
#define URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEAPIAT_H

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
#endif

#ifndef URASANDESU_CPPANONYM_INTERFACES_CPPANONYMSTORAGEAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Interfaces/CppAnonymStorageApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEAPIATFWD_H
#include <Urasandesu/CppAnonym/CppAnonymStorageDetail/CppAnonymStorageApiAtFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace CppAnonymStorageDetail {

    namespace CppAnonymStorageApiAtDetail {

        using Urasandesu::CppAnonym::Interfaces::CppAnonymStorageApiHolderLabel;
        using Urasandesu::CppAnonym::Traits::ApiAt;

        template<class ApiCartridgesHolder, class ApiLabel>
        struct CppAnonymStorageApiAtImpl : 
            ApiAt<ApiCartridgesHolder, CppAnonymStorageApiHolderLabel, ApiLabel>
        {
        };

    }   // namespace CppAnonymStorageApiAtDetail {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct CppAnonymStorageApiAt : 
        CppAnonymStorageApiAtDetail::CppAnonymStorageApiAtImpl<ApiCartridgesHolder, ApiLabel>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace CppAnonymStorageDetail {

#endif  // URASANDESU_CPPANONYM_CPPANONYMSTORAGEDETAIL_CPPANONYMSTORAGEAPIAT_H