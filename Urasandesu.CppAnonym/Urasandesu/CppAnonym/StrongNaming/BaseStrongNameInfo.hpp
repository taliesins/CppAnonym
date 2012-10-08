#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameInfoApiHolder
    >    
    class BaseStrongNameInfo : 
        public SimpleDisposable
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP