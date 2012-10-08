#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#define URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

    namespace DefaultStrongNameKeyApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;

        struct DefaultStrongNameKeyApiHolderImpl
        {
            typedef map<
                pair<StrongNameInfoLabel, StrongNameInfo>
            > api_cartridges;
        };

    }   // namespace DefaultStrongNameKeyApiHolderDetail {

    struct DefaultStrongNameKeyApiHolder : 
        DefaultStrongNameKeyApiHolderDetail::DefaultStrongNameKeyApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H