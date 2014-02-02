/* 
 * File: CartridgeApiSystem.h
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
#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#define URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_H
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
    struct DefaultApiCartridgesHolder
    {
        typedef DefaultApiCartridgesHolder<ApiCartridgesHolder, CurrentApiLabel, ApiLabel> this_type;
        typedef boost::mpl::map<boost::mpl::pair<CurrentApiLabel, this_type> > api_cartridges;
    };

    namespace ApiAtDetail {

        namespace mpl = boost::mpl;
        using boost::is_same;
        using mpl::at;
        using mpl::eval_if;
        using mpl::false_;
        using mpl::identity;
        using mpl::map;
        using mpl::true_;
        using mpl::void_;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ApiCartridges, api_cartridges);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ApiCartridges, api_cartridges);

        template<class ApiCartridgesHolder, class ApiLabel>
        struct DefaultHolderDispenser
        {
            typedef ApiCartridgesHolder type;
            typedef false_ matches_to_default;
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class _, class ApiLabel>
        struct DefaultHolderDispenser<DefaultApiCartridgesHolder<ApiCartridgesHolder, CurrentApiLabel, _>, ApiLabel> : 
            DefaultHolderDispenser<ApiCartridgesHolder, ApiLabel>
        {
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class _>
        struct DefaultHolderDispenser<DefaultApiCartridgesHolder<ApiCartridgesHolder, CurrentApiLabel, _>, CurrentApiLabel>
        {
            typedef ApiCartridgesHolder type;
            typedef true_ matches_to_default;
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
        struct CreateDefaultHolder
        {
            typedef DefaultApiCartridgesHolder<ApiCartridgesHolder, CurrentApiLabel, ApiLabel> type; 
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
        class ApiAtImplCore
        {
            typedef typename eval_if<
                                CPP_ANONYM_HAS_MEMBER_TYPE(ApiCartridges, ApiCartridgesHolder), 
                                CPP_ANONYM_GET_MEMBER_TYPE(ApiCartridges, ApiCartridgesHolder), 
                                identity<map<> > >::type api_cartridges;
            typedef typename at<api_cartridges, ApiLabel>::type result;
        public:
            typedef typename eval_if<
                                is_same<result, void_>, 
                                CreateDefaultHolder<ApiCartridgesHolder, CurrentApiLabel, ApiLabel>,
                                identity<result> >::type type;
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
        class ApiAtImpl
        {
            typedef DefaultHolderDispenser<ApiCartridgesHolder, ApiLabel> dispenser;
        public:
            typedef typename eval_if<
                                typename dispenser::matches_to_default,
                                dispenser,
                                ApiAtImplCore<ApiCartridgesHolder, CurrentApiLabel, ApiLabel> >::type type;
        };

    }   // namespace ApiAtDetail {

    template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
    struct ApiAt : 
        ApiAtDetail::ApiAtImpl<ApiCartridgesHolder, CurrentApiLabel, ApiLabel>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
