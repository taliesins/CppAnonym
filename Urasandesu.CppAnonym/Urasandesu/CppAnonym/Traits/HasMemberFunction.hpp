#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP
#define URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T, T> struct Identify;

// NOTE: enum { n = sizeof(T) }; is intended for to exclude any incomplete types.
#define CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(name, member, member_ret, member_params) \
    template<class T, class Tag = boost::mpl::void_> \
    struct Has_##name##_##member \
    { \
        enum { n = sizeof(T) }; \
        typedef boost::mpl::false_ type; \
        static const bool value = false; \
    }; \
     \
    template<class T> \
    struct Has_##name##_##member<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, Urasandesu::CppAnonym::Traits::Identify<member_ret(T::*)member_params, &T::member> >::type> \
    { \
        typedef boost::mpl::true_ type; \
        static const bool value = true; \
    };

#define CPP_ANONYM_USING_HAS_MEMBER_FUNCTION(name, member) \
    Has_##name##_##member

#define CPP_ANONYM_HAS_MEMBER_FUNCTION(name, member, t) \
    Has_##name##_##member<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_HPP