#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_DEFAULTHOSTINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_HOSTING_DEFAULTHOSTINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_RUNTIMEHOSTLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/RuntimeHostLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_RUNTIMEHOSTAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/RuntimeHostApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_HOSTINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/HostInfoApiHolderLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultHostInfoApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<RuntimeHostApiHolderLabel, DefaultRuntimeHostApiHolder>, 
                                boost::mpl::pair<RuntimeHostLabel, BaseRuntimeHost<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_DEFAULTHOSTINFOAPIHOLDER_H