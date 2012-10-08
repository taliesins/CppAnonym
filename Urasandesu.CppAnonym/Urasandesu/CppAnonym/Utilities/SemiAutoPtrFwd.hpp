#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        struct SemiAutoPtrHolder;

        template<class T, class TD, class ImplD>
        struct SemiAutoPtrHolderImpl;

        template<class T>
        class SemiAutoPtrImpl;

        template<class U> 
        struct SemiAutoPtrHolderAccessor;

    }   // namespace SemiAutoPtrDetail {

    template<class T>
    class SemiAutoPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP