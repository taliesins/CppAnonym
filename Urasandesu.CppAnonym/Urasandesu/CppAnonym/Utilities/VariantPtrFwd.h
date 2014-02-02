﻿/* 
 * File: VariantPtrFwd.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#define CPPANONYM_VARIANT_PTR_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_VARIANT_PTR_LIMIT_TYPES, CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_VARIANT_PTR_LIMIT_TYPES, param)

    namespace VariantPtrDetail {

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        class VariantPtrImpl;

    }   // namespace VariantPtrDetail {

    template<CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS>
    struct VariantPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_H
