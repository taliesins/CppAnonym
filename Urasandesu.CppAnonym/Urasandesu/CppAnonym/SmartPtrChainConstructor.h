/* 
 * File: SmartPtrChainConstructor.h
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
#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
#define URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_H
#include <Urasandesu/CppAnonym/Utilities/TempPtr.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTORFWD_H
#include <Urasandesu/CppAnonym/SmartPtrChainConstructorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace SmartPtrChainConstructorDetail {

        using boost::mpl::bool_;
        using Utilities::TempPtr;

        CPP_ANONYM_DECLARE_HAS_MEMBER_FUNCTION(HasInitialized, Initialized, void, ());
        
        template<class T>
        struct HasInitialized : 
            CPP_ANONYM_HAS_MEMBER_FUNCTION(HasInitialized, T)
        {
        };

        typedef boost::mpl::bool_<false> False;

        template<class HasInitialized>
        struct InitializeImpl
        {
            template<class T>
            static void Initialize(TempPtr<T> &pObj)
            {
                pObj->Initialized();
            }
        };

        template<>
        struct InitializeImpl<False>
        {
            template<class T>
            static void Initialize(TempPtr<T> &pObj)
            {
                // do nothing
            }
        };

        struct SmartPtrChainConstructorImpl
        {
            template<
                class T,
                class PersistableHeapProvider
            >
            static TempPtr<T> NewRootObject(PersistableHeapProvider &provider)
            {
                auto pObj = provider.NewObject();

                typedef InitializeImpl<HasInitialized<T>::type> Impl;
                Impl::Initialize(pObj);

                return pObj;
            }

            template<
                class T,
                class Current,
                class PersistableHeapProvider
            >
            static TempPtr<T> NewObject(Current &current, PersistableHeapProvider &provider)
            {
                typedef typename Current::current_type previous_type;
                auto pObj = TempPtr<T>(provider.NewObject());
                auto &chain = pObj->ChainFrom<previous_type>();
                chain.SetPrevious(current);

                typedef InitializeImpl<HasInitialized<T>::type> Impl;
                Impl::Initialize(pObj);

                return pObj;
            }
        };

    }   // namespace SmartPtrChainConstructorDetail {

    struct SmartPtrChainConstructor : 
        SmartPtrChainConstructorDetail::SmartPtrChainConstructorImpl
    {
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
