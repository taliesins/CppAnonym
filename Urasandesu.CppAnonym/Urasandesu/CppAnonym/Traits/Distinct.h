/* 
 * File: Distinct.h
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
#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
#define URASANDESU_CPPANONYM_TRAITS_DISTINCT_H

#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCTFWD_H
#include <Urasandesu/CppAnonym/Traits/DistinctFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace DistinctDetail {

        namespace mpl = boost::mpl;
        using mpl::arg;
        using mpl::begin;
        using mpl::end;
        using mpl::fold;
        using mpl::insert;
        using mpl::set0;

        template<class Sequence>
        struct DistinctImpl : 
            fold<Sequence, set0<>, insert<arg<1>, arg<2> > >
        {
        };

        template<class Sequence>
        struct DistinctBeginImpl : 
            begin<typename DistinctImpl<Sequence>::type>
        {
        };

        template<class Sequence>
        struct DistinctEndImpl : 
            end<typename DistinctImpl<Sequence>::type>
        {
        };

    }   // namespace DistinctDetail {

    template<class Sequence>
    struct Distinct : 
        DistinctDetail::DistinctImpl<Sequence>
    {
    };

    template<class Sequence>
    struct DistinctBegin : 
        DistinctDetail::DistinctBeginImpl<Sequence>
    {
    };

    template<class Sequence>
    struct DistinctEnd : 
        DistinctDetail::DistinctEndImpl<Sequence>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
