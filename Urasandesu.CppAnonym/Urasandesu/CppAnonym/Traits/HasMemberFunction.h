#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H
#define URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T, T> struct Identify { };

// NOTE: enum { n = sizeof(HasMemberFunctionT) }; is intended for to exclude any incomplete types.
#define CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(name, member, member_ret, member_params) \
    template<class HasMemberFunctionT, class Tag = boost::mpl::void_> \
    struct Has_##name \
    { \
        enum { n = sizeof(HasMemberFunctionT) }; \
        typedef boost::mpl::false_ type; \
        static const bool value = false; \
    }; \
     \
    template<class HasMemberFunctionT> \
    struct Has_##name< \
        HasMemberFunctionT, \
        typename boost::mpl::apply< \
            boost::mpl::always<boost::mpl::void_>, \
            Urasandesu::CppAnonym::Traits::Identify< \
                member_ret(HasMemberFunctionT::*)member_params, \
                static_cast<member_ret(HasMemberFunctionT::*)member_params>(&HasMemberFunctionT::member) \
            > \
        >::type \
    > \
    { \
        typedef boost::mpl::true_ type; \
        static const bool value = true; \
    };


#define CPP_ANONYM_USING_HAS_MEMBER_FUNCTION(name) \
    Has_##name

#define CPP_ANONYM_HAS_MEMBER_FUNCTION(name, t) \
    Has_##name<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H