#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#define URASANDESU_CPPANONYM_TRAITS_REPLACE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACEFWD_H
#include <Urasandesu/CppAnonym/Traits/ReplaceFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace ReplaceDetail {

        namespace mpl = boost::mpl;
        using boost::is_same;
        using mpl::eval_if;
        using mpl::identity;

        template<class T, class Old, class New>
        struct ReplaceImpl : 
            eval_if<is_same<T, Old>, identity<New>, identity<T> >
        {
        };

    }   // namespace ReplaceDetail {

    template<class T, class Old, class New>
    struct Replace : 
        ReplaceDetail::ReplaceImpl<T, Old, New>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H