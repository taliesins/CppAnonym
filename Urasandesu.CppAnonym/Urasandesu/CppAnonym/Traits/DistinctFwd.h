#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCTFWD_H
#define URASANDESU_CPPANONYM_TRAITS_DISTINCTFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace DistinctDetail {

        template<class Sequence>
        struct DistinctImpl;

        template<class Sequence>
        struct DistinctBeginImpl;

        template<class Sequence>
        struct DistinctEndImpl;

    }   // namespace DistinctDetail {

    template<class Sequence>
    struct Distinct;

    template<class Sequence>
    struct DistinctBegin;

    template<class Sequence>
    struct DistinctEnd;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCTFWD_H