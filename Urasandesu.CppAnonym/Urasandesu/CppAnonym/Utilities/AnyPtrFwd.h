#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTRFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_ANYPTRFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AnyPtrDetail {

        struct AnyPtrHolder;

        template<class T, class TD, class ImplD>
        struct AnyPtrHolderImpl;

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl;

        template<
            class T, 
            class Tag
        >
        struct MakeHeapHolderImpl;

        class AnyPtrImpl;

    }   // namespace AnyPtrDetail {

    struct AnyPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTRFWD_H