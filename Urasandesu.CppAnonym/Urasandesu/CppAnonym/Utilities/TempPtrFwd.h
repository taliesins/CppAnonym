/* 
 * File: TempPtrFwd.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TempPtrDetail {

        using namespace boost;

        namespace TempPtrStatesDetail {

            struct TempPtrStatesDef
            {
                enum type
                {
                    TPS_NONE, 
                    TPS_PERSISTED, 
                    TPS_HAS_ALREADY_PERSISTED, 
                    TPS_UNREACHED
                };
            };

        }   // TempPtrStatesDetail

        typedef SafeEnum<TempPtrStatesDetail::TempPtrStatesDef> TempPtrStates;

        struct TempPtrHolder;

        template<class T, class TD, class ImplD>
        struct TempPtrHolderImpl;

        template<class T, class TD, class ImplD>
        struct MakeHolderImpl;

        template<
            class T, 
            class Tag = QuickHeapWithoutRandomAccess
        >
        struct MakeHeapHolderImpl;

        struct PersistedHandlerHolder;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PersistedHandlerSender, sender_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistedHandlerSender, sender_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PersistedHandlerArg, arg_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(PersistedHandlerArg, arg_type);

        template<class Handler, class ImplD>
        struct PersistedHandlerHolderImpl;

        template<class Handler, class ImplD>
        struct MakePersistedHandlerHolderImpl;

        template<
            class Handler, 
            class Tag = QuickHeapWithoutRandomAccess
        >
        struct MakeHeapPersistedHandlerHolderImpl;

        template<class T>
        class TempPtrImpl;

        template<class U> 
        struct PersistedHandlersAccessor;

    }   // namespace TempPtrDetail {

    template<class T>
    struct TempPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTRFWD_H
