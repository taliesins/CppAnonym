#pragma once
#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H
#define URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    struct ParentApiOperable;

    namespace Detail {
        
        namespace mpl = boost::mpl;
        using namespace mpl::placeholders;

        template<class ApiType>
        struct GetParentApi
        {
            typedef typename ApiType::parent_api_type type;
        };
        
        template<class ApiType, class IApiType>
        class ParentApiOrDefaultImpl
        {
            typedef typename mpl::eval_if<
                                boost::mpl::or_<
                                    boost::is_same<ParentApiOperable, ApiType>,
                                    boost::is_base_of<ParentApiOperable, ApiType> 
                                >, 
                                GetParentApi<ApiType>, 
                                mpl::identity<mpl::void_>>::type parent_api_type;
        public:
            typedef typename mpl::eval_if<
                                boost::is_base_of<IApiType, parent_api_type>, 
                                mpl::identity<parent_api_type>, 
                                mpl::identity<boost::use_default>>::type type;
        };
    
    }   // Detail

    template<class ApiType, class IApiType>
    struct ParentApiOrDefault
    {
        typedef typename Detail::ParentApiOrDefaultImpl<ApiType, IApiType>::type type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

#endif  // #ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIORDEFAULT_H