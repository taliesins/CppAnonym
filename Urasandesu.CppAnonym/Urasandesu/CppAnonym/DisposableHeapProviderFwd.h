/* 
 * File: DisposableHeapProviderFwd.h
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
#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H
#define URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H
#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.h>
#endif

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_DISPOSABLE_HEAP_PROVIDER_LIMIT_TYPES, CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_DISPOSABLE_HEAP_PROVIDER_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_DISPOSABLE_HEAP_PROVIDER_LIMIT_TYPES, param)

    namespace DisposableHeapProviderDetail {

        CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(DisposingInfoDispose, Dispose, void, ());

        template<class I>
        struct DisposingInfoFacade;

        template<class ReversedDisposingInfoTypes, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImplImpl;

        template<class DisposingInfo, class T>
        struct HasObjectT;

        template<class DisposingInfoTypes, LONG N>
        class ProvidingTypeAtImpl;

        template<class ReversedDisposingInfoTypes, class ProvidingType>
        class ProviderOfImpl;

        template<class DisposingInfoTypes>
        class ATL_NO_VTABLE DisposableHeapProviderImpl;

        template<CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
        class DesignatedSequence;

    }   // namespace DisposableHeapProviderDetail {

    template<CPPANONYM_DISPOSABLE_HEAP_PROVIDER_AUX_DECLARE_PARAMS>
    struct ATL_NO_VTABLE DisposableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDERFWD_H
