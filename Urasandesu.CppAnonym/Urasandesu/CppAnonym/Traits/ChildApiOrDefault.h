#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H
#define URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    //struct ChildApiOperable;

    template<class ApiType, class IParentApiType>
    struct DefaultParentApi;

    template<class ApiType, class IChildApiType>
    struct DefaultChildApi : IChildApiType
    {
        typedef ApiType parent_api_type;
    };

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

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

        template<class ApiType>
        struct GetChildApi
        {
            typedef typename ApiType::child_api_types type;
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
        
        template<class ApiType, class IChildApiType>
        class ChildApiOrDefaultImpl
        {
            typedef typename mpl::eval_if<
                                HasChildApi<ApiType>,
                                //boost::mpl::or_<
                                //    boost::is_same<ChildApiOperable, ApiType>,
                                //    boost::is_base_of<ChildApiOperable, ApiType> 
                                //>, 
                                GetChildApi<ApiType>, 
                                mpl::identity<mpl::vector<>>>::type child_api_types;
            //typedef typename mpl::eval_if<
            //                    boost::is_same<ApiType, mpl::void_>,
            //                    mpl::identity<mpl::void_>, 
            //                    child_api_types_>::type child_api_types;
            typedef typename mpl::find_if<child_api_types, boost::is_base_of<IChildApiType, _1>>::type i;
            typedef typename mpl::end<child_api_types>::type i_end; 
        public:
            typedef typename mpl::eval_if<
                                boost::is_same<i, i_end>, 
                                CreateDefaultChildApi<ApiType, IChildApiType>,
                                //mpl::identity<mpl::void_>, 
                                mpl::deref<i>>::type type;
        };

    }   // Detail
        
    template<class ApiType, class IChildApiType>
    struct ChildApiOrDefault
    {
        typedef typename Detail::ChildApiOrDefaultImpl<ApiType, IChildApiType>::type type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H