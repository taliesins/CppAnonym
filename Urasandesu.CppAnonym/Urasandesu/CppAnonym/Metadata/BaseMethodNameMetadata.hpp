#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASHFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/HashFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class MethodNameMetadataApiHolder>
    struct EqualTo<
                    Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder> > : 
        std::binary_function<
                    Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder>, 
                    Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder>, 
                    bool>
    {
        typedef Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder> method_name_metadata_type;
        
        bool operator()(method_name_metadata_type const &x, method_name_metadata_type const &y) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            return x.m_name == y.m_name &&
                   x.m_callConvention == y.m_callConvention &&
                   x.m_pRetType == y.m_pRetType &&
                   SequenceEqual(x.m_paramTypes.begin(), x.m_paramTypes.end(), 
                                 y.m_paramTypes.begin(), y.m_paramTypes.end());
        }
    };



    template<class MethodNameMetadataApiHolder>
    struct Hash<Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder> > : 
        std::unary_function<Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder>, std::size_t>
    {
        typedef Metadata::BaseMethodNameMetadata<MethodNameMetadataApiHolder> method_name_metadata_type;
        
        std::size_t operator()(method_name_metadata_type const &x) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            std::size_t seed = 0;
            hash_combine(seed, hash_value(x.m_name));
            hash_combine(seed, x.m_callConvention.Value());
            hash_combine(seed, HashValue(x.m_pRetType));
            hash_combine(seed, SequenceHashValue(x.m_paramTypes.begin(), x.m_paramTypes.end()));
            return seed;
        }
    };
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodNameMetadataApiHolder
    >    
    class BaseMethodNameMetadata
    {
    public:
        typedef BaseMethodNameMetadata<MethodNameMetadataApiHolder> this_type;

        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;

        typedef typename std::vector<type_metadata_type const *>::iterator param_types_iterator;
        typedef typename std::vector<type_metadata_type const *>::const_iterator param_types_const_iterator;

        BaseMethodNameMetadata() { }
        std::wstring m_name;
        CallingConventions m_callConvention;
        type_metadata_type const *m_pRetType;
        std::vector<type_metadata_type const *> m_paramTypes;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP