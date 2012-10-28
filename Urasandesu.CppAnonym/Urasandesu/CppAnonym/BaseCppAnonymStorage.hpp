#pragma once
#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HPP
#define URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HPP

#ifndef URASANDESU_CPPANONYM_INTERFACES_CPPANONYMSTORAGEAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Interfaces/CppAnonymStorageApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGEFWD_HPP
#include <Urasandesu/CppAnonym/BaseCppAnonymStorageFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct CppAnonymStorageApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, CppAnonym::Interfaces::CppAnonymStorageApiHolderLabel, ApiLabel>
    {
    };

    namespace CppAnonymStorageDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        template<
            class CppAnonymStorageApiHolder
        >    
        struct CppAnonymStorageFacade
        {
            typedef typename CppAnonymStorageApiAt<CppAnonymStorageApiHolder, HostInfoLabel>::type host_info_type;
            typedef StaticDependentObjectsStorage<host_info_type> base_type;
        };

    }   // namespace CppAnonymStorageDetail {

    template<
        class CppAnonymStorageApiHolder
    >    
    class BaseCppAnonymStorage : 
        public CppAnonymStorageDetail::CppAnonymStorageFacade<CppAnonymStorageApiHolder>::base_type
    {
    };

    template class BaseCppAnonymStorage<>;

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HPP