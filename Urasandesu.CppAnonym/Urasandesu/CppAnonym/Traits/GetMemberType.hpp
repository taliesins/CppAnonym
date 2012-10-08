#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#define URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

#define CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(t, member) \
    template<class T> \
    struct Get_##t_##member \
    { \
        typedef typename T::member type; \
    };

#define CPP_ANONYM_GET_MEMBER_TYPE(t, member) \
    Get_##t_##member<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP