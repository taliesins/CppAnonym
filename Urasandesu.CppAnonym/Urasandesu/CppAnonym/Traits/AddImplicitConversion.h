#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_ADDIMPLICITCONVERSION_H
#define URASANDESU_CPPANONYM_TRAITS_ADDIMPLICITCONVERSION_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct AddImplicitConversion
    {
        AddImplicitConversion(T& other) { }
        AddImplicitConversion& operator=(T& other) { return *this; }
    };

#ifdef CPPANONYM_ADDIMPLICITCONVERSION_SIZE
#error This .h reserves the word "CPPANONYM_ADDIMPLICITCONVERSION_SIZE".
#endif
#define CPPANONYM_ADDIMPLICITCONVERSION_SIZE 11

#ifdef CPPANONYM_IGNORE_PARAM
#error This .h reserves the word "CPPANONYM_IGNORE_PARAM".
#endif
#define CPPANONYM_IGNORE_PARAM(z, n, _) \
        template<template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> class Container> \
        struct IgnoreParam ## n \
        { \
        };

    BOOST_PP_REPEAT_FROM_TO(1, CPPANONYM_ADDIMPLICITCONVERSION_SIZE, CPPANONYM_IGNORE_PARAM, nil)

#undef CPPANONYM_IGNORE_PARAM

#ifdef CPPANONYM_ADDIMPLICITCONVERSION
#error This .h reserves the word "CPPANONYM_ADDIMPLICITCONVERSION".
#endif
#define CPPANONYM_ADDIMPLICITCONVERSION(z, n, _) \
        template<template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> class Container> \
        struct AddImplicitConversion<IgnoreParam ## n<Container>> \
        { \
            template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> \
            AddImplicitConversion(Container<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), T)>& other) { } \
            template<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), class T)> \
            AddImplicitConversion& operator=(Container<BOOST_PP_ENUM_SHIFTED_PARAMS_Z(z, BOOST_PP_INC(n), T)>& other) { return *this; } \
        };

    BOOST_PP_REPEAT_FROM_TO(1, CPPANONYM_ADDIMPLICITCONVERSION_SIZE, CPPANONYM_ADDIMPLICITCONVERSION, nil)

#undef CPPANONYM_ADDIMPLICITCONVERSION
    
#undef CPPANONYM_ADDIMPLICITCONVERSION_SIZE

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_ADDIMPLICITCONVERSION_H