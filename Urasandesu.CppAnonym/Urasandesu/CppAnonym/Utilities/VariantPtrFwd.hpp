#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace VariantPtrDetail {

        template<class Types>
        class VariantPtrImpl;

    }   // namespace VariantPtrDetail {

    template<class Types>
    struct VariantPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP