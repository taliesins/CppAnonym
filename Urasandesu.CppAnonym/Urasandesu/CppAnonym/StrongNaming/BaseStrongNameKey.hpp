#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameKeyApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameKeyApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameKeyApiHolder
    >    
    class BaseStrongNameKey : 
        public SimpleDisposable
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP