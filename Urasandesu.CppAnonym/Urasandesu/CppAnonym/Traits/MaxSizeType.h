/* 
 * File: MaxSizeType.h
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
#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
#define URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H

#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPEFWD_H
#include <Urasandesu/CppAnonym/Traits/MaxSizeTypeFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    namespace MaxSizeTypeDetail {

        namespace mpl = boost::mpl;
        using mpl::_1;
        using mpl::deref;
        using mpl::max_element;
        using mpl::sizeof_;
        using mpl::transform_view;

        template<class Types>
        class MaxSizeTypeImpl
        {
            typedef typename transform_view<Types, sizeof_<_1> > type_size_view;
            typedef typename max_element<type_size_view>::type i;
        public:
            typedef typename deref<typename i::base>::type type;
        };

    }   // namespace MaxSizeTypeDetail {

    template<class Types>
    struct MaxSizeType : 
        MaxSizeTypeDetail::MaxSizeTypeImpl<Types>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
