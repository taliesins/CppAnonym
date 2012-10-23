#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
#define URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPEFWD_H
#include <Urasandesu/CppAnonym/Traits/MaxSizeTypeFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace MaxSizeTypeDetail {

        namespace mpl = boost::mpl;
        using mpl::_1;
        using mpl::deref;
        using mpl::max_element;
        using mpl::sizeof_;
        using mpl::transform_view;

        template<class Types>
        class MaxSizeTypeImpl
        {
            typedef typename transform_view<Types, sizeof_<_1> > type_size_view;
            typedef typename max_element<type_size_view>::type i;
        public:
            typedef typename deref<typename i::base>::type type;
        };

    }   // namespace MaxSizeTypeDetail {

    template<class Types>
    struct MaxSizeType : 
        MaxSizeTypeDetail::MaxSizeTypeImpl<Types>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H