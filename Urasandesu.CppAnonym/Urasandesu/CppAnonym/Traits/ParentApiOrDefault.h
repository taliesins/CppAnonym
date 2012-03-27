#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H
#define URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    //struct ParentApiOperable;

    template<class ApiType, class IChildApiType>
    struct DefaultChildApi;

    template<class ApiType, class IParentApiType>
    struct DefaultParentApi : IParentApiType
    {
        typedef boost::mpl::vector<ApiType> child_api_types;
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

        template<class ApiType>
        struct GetParentApi
        {
            typedef typename ApiType::parent_api_type type;
        };

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
        
        template<class ApiType, class IParentApiType>
        class ParentApiOrDefaultImpl
        {
            typedef typename mpl::eval_if<
                                HasParentApi<ApiType>,
                                //boost::mpl::or_<
                                //    boost::is_same<ParentApiOperable, ApiType>,
                                //    boost::is_base_of<ParentApiOperable, ApiType> 
                                //>, 
                                GetParentApi<ApiType>, 
                                mpl::identity<mpl::void_>>::type parent_api_type;
            //typedef typename mpl::eval_if<
            //                    boost::is_same<ApiType, mpl::void_>,
            //                    mpl::identity<mpl::void_>, 
            //                    parent_api_type_>::type parent_api_type;
        public:
            typedef typename mpl::eval_if<
                                boost::is_base_of<IParentApiType, parent_api_type>, 
                                mpl::identity<parent_api_type>, 
                                CreateDefaultParentApi<ApiType, IParentApiType>>::type type;
                                //mpl::identity<mpl::void_>>::type type;
        };
    
    }   // Detail

    template<class ApiType, class IParentApiType>
    struct ParentApiOrDefault
    {
        typedef typename Detail::ParentApiOrDefaultImpl<ApiType, IParentApiType>::type type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H