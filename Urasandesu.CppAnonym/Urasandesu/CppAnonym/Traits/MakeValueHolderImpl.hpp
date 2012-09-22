#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_HPP
#define URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPLFWD_HPP
#include <Urasandesu/CppAnonym/Traits/MakeValueHolderImplFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        class ImplD, 
        template<class, class> class ValueHolderImpl
    >
    struct MakeValueHolderImpl
    {
        typedef ValueHolderImpl<T, ImplD> type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_HPP