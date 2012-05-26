#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#define URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEINFOAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_RUNTIMEHOSTLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/RuntimeHostLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEKEYLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameKeyLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct DefaultStrongNameInfoApiHolder
    { 
        typedef boost::mpl::map<boost::mpl::pair<Hosting::RuntimeHostLabel, Hosting::BaseRuntimeHost<> >, 
                                boost::mpl::pair<StrongNameKeyLabel, BaseStrongNameKey<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEINFOAPIHOLDER_H