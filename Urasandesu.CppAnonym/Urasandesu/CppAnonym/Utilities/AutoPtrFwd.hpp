#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        struct AutoPtrHolder;

        template<class U> 
        struct AutoPtrHolderAccessor;

        template<class T, class D>
        struct AutoPtrHolderImpl;

        template<class T, class D>
        struct AutoPtrHolderImplFactory;

        template<class T>
        class AutoPtrImpl;

    }   // namespace AutoPtrDetail {

    template<class T>
    struct AutoPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_HPP