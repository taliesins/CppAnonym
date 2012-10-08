#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        struct Holder;

        template<class U> 
        struct HolderAccessor;

        template<class T, class D>
        struct HolderImpl;

        template<class T, class D>
        struct HolderImplFactory;

        template<class T>
        class AutoPtrImpl;

    }   // namespace AutoPtrDetail {

    template<class T>
    struct AutoPtr;

    template<class T>
    class SemiAutoPtr;

    template<class T>
    class TempPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP