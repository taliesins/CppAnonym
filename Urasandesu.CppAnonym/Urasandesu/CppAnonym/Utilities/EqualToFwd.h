/* 
 * File: EqualToFwd.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace EqualToDetail {

        template<class T>
        struct EqualToImpl;

    }   // namespace EqualToDetail {

    template<class T>
    struct EqualTo;

    namespace EqualToDetail {

        namespace mpl = boost::mpl;
        using mpl::eval_if;
        using mpl::identity;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(EqualToActualValueType, value_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(EqualToActualValueType, value_type);
        
        template<class T>
        class EqualToDecidedByImpl
        {
            typedef typename eval_if<
                        CPP_ANONYM_HAS_MEMBER_TYPE(EqualToActualValueType, T),
                        CPP_ANONYM_GET_MEMBER_TYPE(EqualToActualValueType, T),
                        identity<T> >::type value_type;
        public:
            typedef EqualTo<value_type> type;
        };

    }   // namespace EqualToDetail {

    template<class T>
    struct EqualToDecidedBy : 
        EqualToDetail::EqualToDecidedByImpl<T>
    {
    };

    template<class T>
    typename EqualToDecidedBy<T>::type CreateEqualTo(T const &);

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H
