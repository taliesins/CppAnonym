#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_IASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/IAssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIAssemblyMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IAssemblyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IAssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadata
    {
    public:
        typedef BaseIAssemblyMetadata<IAssemblyMetadataApiHolder> this_type;

        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;
        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

        virtual mdAssembly GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual Utilities::AutoPtr<strong_name_key_type const> GetStrongNameKey() const = 0;
        virtual metadata_dispenser_type const *GetResolutionScope() const = 0;
    };




    
    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataHash : 
        Traits::HashComputable<typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type const *>
    {
    public:
        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, HashValue(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadataEqualTo : 
        Traits::EqualityComparable<typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type const *>
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   x->GetResolutionScope() == y->GetResolutionScope();
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATA_HPP