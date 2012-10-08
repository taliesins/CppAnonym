#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#define URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP

namespace Urasandesu { namespace CppAnonym { namespace Traits {

#define CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(t, member) \
    template<class T, class Tag = boost::mpl::void_> \
    struct Has_##t_##member \
    { \
        typedef boost::mpl::false_ type; \
        static const bool value = false; \
    }; \
    \
    template<class T> \
    struct Has_##t_##member<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, typename T::member>::type> \
    { \
        typedef boost::mpl::true_ type; \
        static const bool value = true; \
    };

#define CPP_ANONYM_HAS_MEMBER_TYPE(t, member) \
    Has_##t_##member<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP