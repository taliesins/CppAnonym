/* 
 * File: HasMemberType.h
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
#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#define URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

// NOTE: enum { n = sizeof(HasMemberTypeT) }; is intended for to exclude any incomplete types.
#define CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(name, member) \
    template<class HasMemberTypeT, class Tag = boost::mpl::void_> \
    struct Has_##name \
    { \
        typedef boost::mpl::false_ type; \
        enum { value = false }; \
    }; \
    \
    template<class HasMemberTypeT> \
    struct Has_##name<HasMemberTypeT, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, typename HasMemberTypeT::member>::type> \
    { \
        typedef boost::mpl::true_ type; \
        enum { value = true }; \
    };

#define CPP_ANONYM_USING_HAS_MEMBER_TYPE(name) \
    Has_##name

#define CPP_ANONYM_HAS_MEMBER_TYPE(name, t) \
    Has_##name<t>

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
