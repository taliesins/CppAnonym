#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_HPP
#define URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPLFWD_HPP
#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImplFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<
        class T, 
        class TD, 
        class ImplD, 
        template<class, class, class> class PointerHolderImpl
    >
    struct MakePointerHolderImpl
    {
        typedef PointerHolderImpl<T, TD, ImplD> type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_HPP