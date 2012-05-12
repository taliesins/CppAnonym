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

        template<class ApiType>
        struct GetExternalApi
        {
            typedef typename ApiType::external_api_types type;
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

        template<class ApiType, class ApiTypeInterface, class IExternalApiType>
        struct CreateDefaultExternalApi
        {
            typedef DefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType> type; 
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

    }   // Detail

    template<class ApiType, class ApiTypeInterface, class IExternalApiType>
    struct ExternalApiOrDefault
    {
        typedef typename Detail::ExternalApiOrDefaultImpl<ApiType, ApiTypeInterface, IExternalApiType>::type type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H