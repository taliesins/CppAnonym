#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIHOLDER_H

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

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/DefaultFusionInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion {
    struct DefaultFusionInfoApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Hosting::RuntimeHostApiHolderLabel, Hosting::DefaultRuntimeHostApiHolder>, 
                                boost::mpl::pair<Hosting::RuntimeHostLabel, Hosting::BaseRuntimeHost<>>> api_cartridges;
    };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIHOLDER_H