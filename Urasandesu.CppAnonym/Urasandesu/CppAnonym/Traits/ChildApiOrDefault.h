#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H
#define URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    struct ChildApiOperable;

    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template<class ApiType>
        struct GetChildApi
        {
            typedef typename ApiType::child_api_types type;
        };
        
        template<class ApiType, class IApiType>
        class ChildApiOrDefaultImpl
        {
            typedef typename mpl::eval_if<
                                boost::mpl::or_<
                                    boost::is_same<ChildApiOperable, ApiType>,
                                    boost::is_base_of<ChildApiOperable, ApiType> 
                                >, 
                                GetChildApi<ApiType>, 
                                mpl::identity<mpl::vector<>>>::type child_api_types;
            typedef typename mpl::find_if<child_api_types, boost::is_base_of<IApiType, _1>>::type i;
            typedef typename mpl::end<child_api_types>::type i_end; 
        public:
            typedef typename mpl::eval_if<
                                boost::is_same<i, i_end>, 
                                mpl::identity<boost::use_default>, 
                                mpl::deref<i>>::type type;
        };

    }   // Detail
        
    template<class ApiType, class IApiType>
    struct ChildApiOrDefault
    {
        typedef typename Detail::ChildApiOrDefaultImpl<ApiType, IApiType>::type type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIORDEFAULT_H