#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        struct Holder;

        template<class U> 
        struct HolderAccessor;

        template<class T, class D>
        struct HolderImpl;

        template<class T, class D>
        struct HolderImplFactory;

        template<class T>
        class AutoPtrImpl;

    }   // namespace SemiAutoPtrDetail {

    template<class T>
    class SemiAutoPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP