#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AutoPtrDetail {

        struct AutoPtrHolder;

        template<class T, class TD, class ImplD>
        struct AutoPtrHolderImpl;

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl;

        template<
            class T, 
            class Tag = QuickHeapWithoutSubscriptOperator
        >
        struct MakeHeapHolderImpl;

        template<class T>
        class AutoPtrImpl;

        template<class U> 
        struct AutoPtrHolderAccessor;

    }   // namespace AutoPtrDetail {

    template<class T>
    struct AutoPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTRFWD_H