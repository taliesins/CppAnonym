#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACEFWD_H
#define URASANDESU_CPPANONYM_TRAITS_REPLACEFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace ReplaceDetail {

        template<class T, class Old, class New>
        struct ReplaceImpl;

    }   // namespace ReplaceDetail {

    template<class T, class Old, class New>
    struct Replace;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_REPLACEFWD_H