#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_HPP
#define URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPEFWD_HPP
#include <Urasandesu/CppAnonym/Traits/MaxSizeTypeFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace MaxSizeTypeDetail {

        namespace mpl = boost::mpl;
        using namespace boost::mpl;

        template<class Types>
        class MaxSizeTypeImpl
        {
            typedef typename transform_view<Types, sizeof_<_1> > type_size_view;
            typedef typename mpl::max_element<type_size_view>::type i;
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

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_HPP