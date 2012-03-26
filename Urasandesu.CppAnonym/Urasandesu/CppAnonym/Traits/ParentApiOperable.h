#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
#define URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    struct ParentApiOperable
    {
        typedef boost::mpl::void_ parent_api_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H