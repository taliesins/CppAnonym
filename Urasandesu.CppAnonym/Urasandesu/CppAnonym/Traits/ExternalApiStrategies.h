#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#define URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class ApiType, class ApiTypeInterface, class IExternalApiType>
    struct DefaultExternalApi : 
        ApiTypeInterface
    {
        typedef boost::mpl::vector<DefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType>> external_api_types;
    };

    template<class ApiType, class CurrentApiKey, class ApiKey>
    struct DefaultApi
    {
        typedef boost::mpl::map<boost::mpl::pair<CurrentApiKey, DefaultApi<ApiType, CurrentApiKey, ApiKey>>> api_map;
    };

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template<class ApiType, class Tag = mpl::void_>
        struct HasExternalApi
        {
            typedef mpl::false_ type;
            static const bool value = false;
        };

        template<class ApiType>
        struct HasExternalApi<ApiType, typename mpl::apply<mpl::always<mpl::void_>, typename ApiType::external_api_types>::type>
        {
            typedef mpl::true_ type;
            static const bool value = true;
        };

        template<class T, class Tag = mpl::void_>
        struct HasApiMap
        {
            typedef mpl::false_ type;
            static const bool value = false;
        };

        template<class T>
        struct HasApiMap<T, typename mpl::apply<mpl::always<mpl::void_>, typename T::api_map>::type>
        {
            typedef mpl::true_ type;
            static const bool value = true;
        };

        template<class ApiType>
        struct GetExternalApi
        {
            typedef typename ApiType::external_api_types type;
        };

        template<class ApiType>
        struct GetApiMap
        {
            typedef typename ApiType::api_map type;
        };

        template<class ApiType, class IExternalApiType>
        struct DefaultExternalApiExtractor
        {
            typedef ApiType api_type;
            typedef mpl::false_ matches_to_default;
        };

        template<class ApiType, class ApiTypeInterface, class _, class IExternalApiType>
        struct DefaultExternalApiExtractor<DefaultExternalApi<ApiType, ApiTypeInterface, _>, IExternalApiType> : 
            DefaultExternalApiExtractor<ApiType, IExternalApiType>
        {
        };

        template<class ApiType, class ApiTypeInterface, class _>
        struct DefaultExternalApiExtractor<DefaultExternalApi<ApiType, ApiTypeInterface, _>, ApiTypeInterface>
        {
            typedef ApiType api_type;
            typedef mpl::true_ matches_to_default;
        };

        template<class ApiType, class ApiKey>
        struct DefaultApiExtractor
        {
            typedef ApiType api_type;
            typedef mpl::false_ matches_to_default;
        };

        template<class ApiType, class CurrentApiKey, class _, class ApiKey>
        struct DefaultApiExtractor<DefaultApi<ApiType, CurrentApiKey, _>, ApiKey> : 
            DefaultApiExtractor<ApiType, ApiKey>
        {
        };

        template<class ApiType, class CurrentApiKey, class _>
        struct DefaultApiExtractor<DefaultApi<ApiType, CurrentApiKey, _>, CurrentApiKey>
        {
            typedef ApiType api_type;
            typedef mpl::true_ matches_to_default;
        };

        template<class ApiType, class ApiTypeInterface, class IExternalApiType>
        struct CreateDefaultExternalApi
        {
            typedef DefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType> type; 
        };

        template<class ApiType, class CurrentApiKey, class ApiKey>
        struct CreateDefaultApi
        {
            typedef DefaultApi<ApiType, CurrentApiKey, ApiKey> type; 
        };

        template<class ApiType, class ApiTypeInterface, class IExternalApiType>
        class ExternalApiOrDefaultImpl_
        {
            typedef typename mpl::eval_if<
                                HasExternalApi<ApiType>,
                                GetExternalApi<ApiType>, 
                                mpl::identity<mpl::vector<>>>::type external_api_types;
            typedef typename mpl::find_if<external_api_types, boost::is_base_of<IExternalApiType, _1>>::type i;
            typedef typename mpl::end<external_api_types>::type i_end; 
        public:
            typedef typename mpl::eval_if<
                                boost::is_same<i, i_end>, 
                                CreateDefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType>,
                                mpl::deref<i>>::type type;
        };

        template<class ApiType, class CurrentApiKey, class ApiKey>
        class ApiAtImpl_
        {
            typedef typename mpl::eval_if<
                                HasApiMap<ApiType>,
                                GetApiMap<ApiType>, 
                                mpl::identity<mpl::map<>>>::type api_map;
            typedef typename mpl::at<api_map, ApiKey>::type result;
        public:
            typedef typename mpl::eval_if<
                                boost::is_same<result, mpl::void_>, 
                                CreateDefaultApi<ApiType, CurrentApiKey, ApiKey>,
                                mpl::identity<result>>::type type;
        };
        
        template<class ApiType, class ApiTypeInterface, class IExternalApiType>
        class ExternalApiOrDefaultImpl
        {
            typedef DefaultExternalApiExtractor<ApiType, IExternalApiType> extractor;
        public:
            typedef typename mpl::eval_if<
                                typename extractor::matches_to_default,
                                mpl::identity<typename extractor::api_type>,
                                ExternalApiOrDefaultImpl_<ApiType, ApiTypeInterface, IExternalApiType>>::type type;
        };
        
        template<class ApiType, class CurrentApiKey, class ApiKey>
        class ApiAtImpl
        {
            typedef DefaultApiExtractor<ApiType, ApiKey> extractor;
        public:
            typedef typename mpl::eval_if<
                                typename extractor::matches_to_default,
                                mpl::identity<typename extractor::api_type>,
                                ApiAtImpl_<ApiType, CurrentApiKey, ApiKey>>::type type;
        };

    }   // Detail

    template<class ApiType, class ApiTypeInterface, class IExternalApiType>
    struct ExternalApiOrDefault
    {
        typedef typename Detail::ExternalApiOrDefaultImpl<ApiType, ApiTypeInterface, IExternalApiType>::type type;
    };

    template<class ApiMapType, class CurrentApiKey, class ApiKey>
    struct ApiAt
    {
        typedef typename Detail::ApiAtImpl<ApiMapType, CurrentApiKey, ApiKey>::type type;
    };
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H