#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_IMODULEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/IModuleMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIModuleMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IModuleMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IModuleMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata
    {
    public:
        typedef BaseIModuleMetadata<IModuleMetadataApiHolder> this_type;

        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

        virtual mdModule GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<i_assembly_metadata_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type const> >
    {
    public:
        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataHashLabel>::type i_assembly_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_assembly_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type const> >
    {
    public:
        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x && y);

            return x->GetName() == y->GetName() &&
                   i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEIMODULEMETADATA_HPP