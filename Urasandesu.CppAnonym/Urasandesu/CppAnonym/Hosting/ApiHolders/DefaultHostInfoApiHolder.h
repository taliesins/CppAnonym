#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoApiHolderLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    struct DefaultHostInfoApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Interfaces::RuntimeHostApiHolderLabel, ApiHolders::DefaultRuntimeHostApiHolder>, 
                                boost::mpl::pair<Interfaces::RuntimeHostLabel, BaseRuntimeHost<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H