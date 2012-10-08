#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#define URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

#define CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(name, member) \
    template<class T> \
    struct Get_##name##_##member \
    { \
        typedef typename T::member type; \
    };

#define CPP_ANONYM_USING_GET_MEMBER_TYPE(name, member) \
    Get_##name##_##member

#define CPP_ANONYM_GET_MEMBER_TYPE(name, member, t) \
    Get_##name##_##member<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP