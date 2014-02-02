﻿/* 
 * File: Replace.h
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
#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#define URASANDESU_CPPANONYM_TRAITS_REPLACE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACEFWD_H
#include <Urasandesu/CppAnonym/Traits/ReplaceFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace ReplaceDetail {

        namespace mpl = boost::mpl;
        using boost::is_same;
        using mpl::eval_if;
        using mpl::identity;

        template<class T, class Old, class New>
        struct ReplaceImpl : 
            eval_if<is_same<T, Old>, identity<New>, identity<T> >
        {
        };

    }   // namespace ReplaceDetail {

    template<class T, class Old, class New>
    struct Replace : 
        ReplaceDetail::ReplaceImpl<T, Old, New>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
