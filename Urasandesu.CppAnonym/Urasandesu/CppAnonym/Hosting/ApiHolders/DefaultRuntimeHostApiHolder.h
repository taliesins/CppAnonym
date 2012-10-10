#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#define URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    namespace DefaultRuntimeHostApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        struct DefaultRuntimeHostApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>,
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<RuntimeHostPersistedHandlerLabel, RuntimeHostPersistedHandler>
            > api_cartridges;
        };

    }   // namespace DefaultRuntimeHostApiHolderDetail {

    struct DefaultRuntimeHostApiHolder : 
        DefaultRuntimeHostApiHolderDetail::DefaultRuntimeHostApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H