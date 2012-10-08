#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#define URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

    struct DefaultStrongNameKeyApiHolder
    { 
        typedef boost::mpl::map<boost::mpl::pair<Interfaces::StrongNameInfoLabel, BaseStrongNameInfo<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H