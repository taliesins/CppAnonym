#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
#define URASANDESU_CPPANONYM_TRAITS_DISTINCT_H

#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCTFWD_H
#include <Urasandesu/CppAnonym/Traits/DistinctFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace DistinctDetail {

        namespace mpl = boost::mpl;
        using mpl::arg;
        using mpl::begin;
        using mpl::end;
        using mpl::fold;
        using mpl::insert;
        using mpl::set0;

        template<class Sequence>
        struct DistinctImpl : 
            fold<Sequence, set0<>, insert<arg<1>, arg<2> > >
        {
        };

        template<class Sequence>
        struct DistinctBeginImpl : 
            begin<typename DistinctImpl<Sequence>::type>
        {
        };

        template<class Sequence>
        struct DistinctEndImpl : 
            end<typename DistinctImpl<Sequence>::type>
        {
        };

    }   // namespace DistinctDetail {

    template<class Sequence>
    struct Distinct : 
        DistinctDetail::DistinctImpl<Sequence>
    {
    };

    template<class Sequence>
    struct DistinctBegin : 
        DistinctDetail::DistinctBeginImpl<Sequence>
    {
    };

    template<class Sequence>
    struct DistinctEnd : 
        DistinctDetail::DistinctEndImpl<Sequence>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H