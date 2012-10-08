#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ITYPEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ITypeMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseITypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ITypeMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ITypeMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadata
    {
    public:
        typedef BaseITypeMetadata<ITypeMetadataApiHolder> this_type;

        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type i_module_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<this_type const> GetBaseType() const = 0;
        virtual boost::shared_ptr<i_module_metadata_type const> GetResolutionScope() const = 0;
        virtual std::vector<COR_SIGNATURE> const &GetSignatures() const = 0;
        virtual bool IsGenericParameter() const = 0;
    };




    
    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type const> >
    {
    public:
        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IModuleMetadataHashLabel>::type i_module_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_module_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type const> >
    {
    public:
        //typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATA_HPP