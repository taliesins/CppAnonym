#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#define URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

// NOTE: enum { n = sizeof(T) }; is intended for to exclude any incomplete types.
#define CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(name, member) \
    template<class T, class Tag = boost::mpl::void_> \
    struct Has_##name \
    { \
        enum { n = sizeof(T) }; \
        typedef boost::mpl::false_ type; \
        static const bool value = false; \
    }; \
    \
    template<class T> \
    struct Has_##name<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, typename T::member>::type> \
    { \
        typedef boost::mpl::true_ type; \
        static const bool value = true; \
    };

#define CPP_ANONYM_USING_HAS_MEMBER_TYPE(name) \
    Has_##name

#define CPP_ANONYM_HAS_MEMBER_TYPE(name, t) \
    Has_##name<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP