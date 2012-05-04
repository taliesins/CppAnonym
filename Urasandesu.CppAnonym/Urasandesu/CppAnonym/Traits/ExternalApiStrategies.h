#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#define URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class ApiType, class IChildApiType>
    struct DefaultChildApi;

    template<class ApiType, class IParentApiType>
    struct DefaultParentApi
    {
        typedef boost::mpl::vector<ApiType> child_api_types;
    };

    template<class ApiType, class IChildApiType>
    struct DefaultChildApi
    {
        typedef ApiType parent_api_type;
    };

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
        struct HasParentApi
        {
            typedef mpl::false_ type;
            static const bool value = false;
        };

        template<class ApiType>
        struct HasParentApi<ApiType, typename mpl::apply<mpl::always<mpl::void_>, typename ApiType::parent_api_type>::type>
        {
            typedef mpl::true_ type;
            static const bool value = true;
        };

        template<class ApiType, class Tag = mpl::void_>
        struct HasChildApi
        {
            typedef mpl::false_ type;
            static const bool value = false;
        };

        template<class ApiType>
        struct HasChildApi<ApiType, typename mpl::apply<mpl::always<mpl::void_>, typename ApiType::child_api_types>::type>
        {
            typedef mpl::true_ type;
            static const bool value = true;
        };

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
        struct GetParentApi
        {
            typedef typename ApiType::parent_api_type type;
        };

        template<class ApiType>
        struct GetChildApi
        {
            typedef typename ApiType::child_api_types type;
        };

        template<class ApiType>
        struct GetExternalApi
        {
            typedef typename ApiType::external_api_types type;
        };

        template<class ApiType, class IExternalApiType>
        struct ExtractDefaultExternalApi
        {
            typedef ApiType api_type;
            typedef mpl::false_ is_default;
        };

        template<class ApiType, class ApiTypeInterface, class _, class IExternalApiType>
        struct ExtractDefaultExternalApi<DefaultExternalApi<ApiType, ApiTypeInterface, _>, IExternalApiType> : 
            ExtractDefaultExternalApi<ApiType, IExternalApiType>
        {
        };

        template<class ApiType, class _, class IExternalApiType>
        struct ExtractDefaultExternalApi<DefaultExternalApi<ApiType, IExternalApiType, _>, IExternalApiType>
        {
            typedef ApiType api_type;
            typedef mpl::true_ is_default;
        };

        //template<class ApiType, class ApiTypeInterface, class IExternalApiType>
        //class ExtractDefaultExternalApi<DefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType>>
        //{
        //    typedef typename ExternalApiOrDefaultImpl<ApiType, ApiTypeInterface, IExternalApiType>::type extracted_type;
        //public:
        //    typedef typename mpl::eval_if<
        //                        boost::is_base_of<ApiTypeInterface, extracted_type>, 
        //                        mpl::identity<ApiType>, 
        //                        ExtractDefaultExternalApi<ApiType>>::type type;
        //};

        //template<class ApiType, class IExternalApiType>
        //class ContainsExternalApi
        //{
        //    typedef typename mpl::eval_if<
        //                        HasExternalApi<ApiType>,
        //                        GetExternalApi<ApiType>, 
        //                        mpl::identity<mpl::vector<>>>::type external_api_types;
        //    typedef typename mpl::find_if<external_api_types, boost::is_base_of<IExternalApiType, _1>>::type i;
        //    typedef typename mpl::end<external_api_types>::type i_end; 
        //public:
        //    typedef typename mpl::not_<boost::is_same<i, i_end>>::type type;
        //    static const bool value = type::value;
        //};

        template<class ApiType, class IParentApiType>
        struct CreateDefaultParentApi
        {
            typedef DefaultParentApi<ApiType, IParentApiType> type; 
        };

        template<class SourceApiType, class IChildApiType, class IParentApiType>
        struct CreateDefaultParentApi<DefaultChildApi<SourceApiType, IChildApiType>, IParentApiType>
        {
            typedef SourceApiType type; 
        };

        template<class ApiType, class IChildApiType>
        struct CreateDefaultChildApi
        {
            typedef DefaultChildApi<ApiType, IChildApiType> type; 
        };

        template<class SourceApiType, class IParentApiType, class IChildApiType>
        struct CreateDefaultChildApi<DefaultParentApi<SourceApiType, IParentApiType>, IChildApiType>
        {
            typedef SourceApiType type; 
        };

        template<class ApiType, class ApiTypeInterface, class IExternalApiType>
        struct CreateDefaultExternalApi
        {
            typedef DefaultExternalApi<ApiType, ApiTypeInterface, IExternalApiType> type; 
        };

        //template<class ApiType1, class ApiTypeInterface1, class IExternalApiType1, class ApiTypeInterface2, class IExternalApiType2>
        //struct CreateDefaultExternalApi<DefaultExternalApi<ApiType1, ApiTypeInterface1, IExternalApiType1>, ApiTypeInterface2, IExternalApiType2>
        //{
        //    typedef typename mpl::eval_if<
        //                        boost::is_same<ApiTypeInterface1, IExternalApiType2>,
        //                        mpl::identity<ApiType1>,
        //                        DefaultExternalApi<
        //                            DefaultExternalApi<
        //                                ApiType1, 
        //                                ApiTypeInterface1, 
        //                                IExternalApiType1
        //                            >, 
        //                            ApiTypeInterface2, 
        //                            IExternalApiType2>>::type type;
        //};

        template<class ApiType, class IParentApiType>
        class ParentApiOrDefaultImpl
        {
            typedef typename mpl::eval_if<
                                HasParentApi<ApiType>,
                                GetParentApi<ApiType>, 
                                mpl::identity<mpl::void_>>::type parent_api_type;
        public:
            typedef typename mpl::eval_if<
                                boost::is_base_of<IParentApiType, parent_api_type>, 
                                mpl::identity<parent_api_type>, 
                                CreateDefaultParentApi<ApiType, IParentApiType>>::type type;
        };
        
        template<class ApiType, class IChildApiType>
        class ChildApiOrDefaultImpl
        {
            typedef typename mpl::eval_if<
                                HasChildApi<ApiType>,
                                GetChildApi<ApiType>, 
                                mpl::identity<mpl::vector<>>>::type child_api_types;
            typedef typename mpl::find_if<child_api_types, boost::is_base_of<IChildApiType, _1>>::type i;
            typedef typename mpl::end<child_api_types>::type i_end; 
        public:
            typedef typename mpl::eval_if<
                                boost::is_same<i, i_end>, 
                                CreateDefaultChildApi<ApiType, IChildApiType>,
                                mpl::deref<i>>::type type;
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
            typedef ExtractDefaultExternalApi<ApiType, IExternalApiType> extracted_type;
        public:
            typedef typename mpl::eval_if<
                                typename extracted_type::is_default,
                                mpl::identity<typename extracted_type::api_type>,
                                ExternalApiOrDefaultImpl_<ApiType, ApiTypeInterface, IExternalApiType>>::type type;
        };
        
        //template<class ApiType, class ApiTypeInterface, class _, class __, class IExternalApiType>
        //struct ExternalApiOrDefaultImpl<DefaultExternalApi<ApiType, ApiTypeInterface, _>, __, IExternalApiType> : 
        //    ExternalApiOrDefaultImpl<ApiType, ApiTypeInterface, IExternalApiType>
        //{
        //};
        //
        //template<class ApiType, class _, class __, class IExternalApiType>
        //struct ExternalApiOrDefaultImpl<DefaultExternalApi<ApiType, IExternalApiType, _>, __, IExternalApiType>
        //{
        //    typedef ApiType type;
        //};

    }   // Detail

    template<class ApiType, class IParentApiType>
    struct ParentApiOrDefault
    {
        typedef typename Detail::ParentApiOrDefaultImpl<ApiType, IParentApiType>::type type;
    };
        
    template<class ApiType, class IChildApiType>
    struct ChildApiOrDefault
    {
        typedef typename Detail::ChildApiOrDefaultImpl<ApiType, IChildApiType>::type type;
    };
        
    template<class ApiType, class ApiTypeInterface, class IExternalApiType>
    struct ExternalApiOrDefault
    {
        typedef typename Detail::ExternalApiOrDefaultImpl<ApiType, ApiTypeInterface, IExternalApiType>::type type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H