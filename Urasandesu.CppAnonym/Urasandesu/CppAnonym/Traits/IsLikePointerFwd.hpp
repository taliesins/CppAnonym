#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTERFWD_HPP
#define URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTERFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace IsLikePointerDetail {

        template<class T>
        class IsLikePointerImpl;

    }   // namespace IsLikePointerDetail {

    template<class T>
    struct IsLikePointer;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTERFWD_HPP