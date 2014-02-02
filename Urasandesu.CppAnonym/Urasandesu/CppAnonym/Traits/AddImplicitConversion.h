/* 
 * File: AddImplicitConversion.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


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
