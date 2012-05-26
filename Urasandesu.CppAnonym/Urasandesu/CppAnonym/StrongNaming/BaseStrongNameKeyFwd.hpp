#pragma once
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#define URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEKEYAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/DefaultStrongNameKeyApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<
        class StrongNameKeyApiHolder = DefaultStrongNameKeyApiHolder
    >    
    class BaseStrongNameKey;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

#endif  // #ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP