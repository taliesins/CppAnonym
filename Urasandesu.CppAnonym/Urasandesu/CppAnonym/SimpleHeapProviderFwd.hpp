/* 
 * File: SimpleHeapProviderFwd.hpp
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
#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
#define URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

// TODO: rename to SimpleHeapProviderFwd.h.

namespace Urasandesu { namespace CppAnonym {

    namespace SimpleHeapProviderDetail {
        
        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProviderImplImpl;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ObjectTagObject, object_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ObjectTagObject, object_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ObjectTagTag, tag_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ObjectTagTag, tag_type);

        template<class ObjectTag, class T>
        struct HasObjectT;

        template<class ProvidingObjectTagTypes, LONG N>
        class ProvidingTypeAtImpl;

        template<class ReversedProvidingObjectTagTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class ProvidingObjectTagTypes>
        struct ATL_NO_VTABLE SimpleHeapProviderImpl;

    }   // namespace SimpleHeapProviderDetail


    template<class ProvidingObjectTagTypes>
    struct ATL_NO_VTABLE SimpleHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDERFWD_HPP
