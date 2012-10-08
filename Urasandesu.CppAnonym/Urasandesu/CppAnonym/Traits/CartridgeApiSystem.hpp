#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#define URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
    struct DefaultApiCartridgesHolder
    {
        typedef DefaultApiCartridgesHolder<ApiCartridgesHolder, CurrentApiLabel, ApiLabel> this_type;
        typedef boost::mpl::map<boost::mpl::pair<CurrentApiLabel, this_type>> api_cartridges;
    };

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ApiCartridges, api_cartridges);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ApiCartridges, api_cartridges);

        template<class ApiCartridgesHolder, class ApiLabel>
        struct DefaultHolderDispenser
        {
            typedef ApiCartridgesHolder type;
            typedef mpl::false_ matches_to_default;
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
            typedef mpl::true_ matches_to_default;
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
        struct CreateDefaultHolder
        {
            typedef DefaultApiCartridgesHolder<ApiCartridgesHolder, CurrentApiLabel, ApiLabel> type; 
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
        class ApiAtImplCore
        {
            typedef typename mpl::eval_if<
                                CPP_ANONYM_HAS_MEMBER_TYPE(ApiCartridges, api_cartridges, ApiCartridgesHolder), 
                                CPP_ANONYM_GET_MEMBER_TYPE(ApiCartridges, api_cartridges, ApiCartridgesHolder), 
                                mpl::identity<mpl::map<>>>::type api_cartridges;
            typedef typename mpl::at<api_cartridges, ApiLabel>::type result;
        public:
            typedef typename mpl::eval_if<
                                boost::is_same<result, mpl::void_>, 
                                CreateDefaultHolder<ApiCartridgesHolder, CurrentApiLabel, ApiLabel>,
                                mpl::identity<result>>::type type;
        };

        template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
        class ApiAtImpl
        {
            typedef DefaultHolderDispenser<ApiCartridgesHolder, ApiLabel> dispenser;
        public:
            typedef typename mpl::eval_if<
                                typename dispenser::matches_to_default,
                                dispenser,
                                ApiAtImplCore<ApiCartridgesHolder, CurrentApiLabel, ApiLabel>>::type type;
        };

    }   // Detail

    template<class ApiCartridgesHolder, class CurrentApiLabel, class ApiLabel>
    struct ApiAt
    {
        typedef typename Detail::ApiAtImpl<ApiCartridgesHolder, CurrentApiLabel, ApiLabel>::type type;
    };
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP