#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#define URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEKEYAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct DefaultStrongNameKeyApiHolder
    { 
        typedef boost::mpl::map<boost::mpl::pair<StrongNameInfoLabel, BaseStrongNameInfo<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEKEYAPIHOLDER_H