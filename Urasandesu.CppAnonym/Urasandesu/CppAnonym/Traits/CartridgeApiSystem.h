#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
#define URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
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