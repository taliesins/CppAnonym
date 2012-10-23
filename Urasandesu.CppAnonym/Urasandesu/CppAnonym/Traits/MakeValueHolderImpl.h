#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H
#define URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H

#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPLFWD_H
#include <Urasandesu/CppAnonym/Traits/MakeValueHolderImplFwd.h>
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

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H