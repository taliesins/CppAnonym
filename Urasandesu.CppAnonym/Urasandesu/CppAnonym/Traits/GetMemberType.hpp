#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#define URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

#define CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(name, member) \
    template<class GetMemberTypeT> \
    struct Get_##name \
    { \
        typedef typename GetMemberTypeT::member type; \
    };

#define CPP_ANONYM_USING_GET_MEMBER_TYPE(name) \
    Get_##name

#define CPP_ANONYM_GET_MEMBER_TYPE(name, t) \
    Get_##name<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP