#pragma once
#ifndef URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDER_H
#define URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/ApiHolders/DefaultCppAnonymStorageApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {
    
    namespace DefaultCppAnonymStorageApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        struct DefaultCppAnonymStorageApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>
            > api_cartridges;
        };

    }   // namespace DefaultCppAnonymStorageApiHolderDetail {

    struct DefaultCppAnonymStorageApiHolder : 
        DefaultCppAnonymStorageApiHolderDetail::DefaultCppAnonymStorageApiHolderImpl
    {
    };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_APIHOLDERS_DEFAULTCPPANONYMSTORAGEAPIHOLDER_H