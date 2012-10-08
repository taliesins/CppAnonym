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

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
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
    class BaseMethodNameMetadata : 
        boost::noncopyable
    {
    public:
        typedef BaseMethodNameMetadata<MethodNameMetadataApiHolder> this_type;

        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;

        typedef typename std::vector<type_metadata_type const *>::iterator param_types_iterator;
        typedef typename std::vector<type_metadata_type const *>::const_iterator param_types_const_iterator;

        BaseMethodNameMetadata() : 
            m_pRetTypeName(NULL), 
            m_pTypeNameAsScope(NULL), 
            m_pTypeAsScope(NULL), 
            m_pMethodResolved(NULL), 
            m_mdt(mdTokenNil)
        { }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"WriteLine";
            }
            return m_name;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        CallingConventions const &GetCallingConvention() const
        {
            return m_callingConvention;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            m_callingConvention = callingConvention;
        }

        type_name_metadata_type const &GetReturnTypeName() const
        {
            _ASSERTE(m_pRetTypeName != NULL);
            return *m_pRetTypeName;
        }

        void SetReturnTypeName(type_name_metadata_type const &retTypeName)
        {
            m_pRetTypeName = &retTypeName;
        }

        std::vector<type_name_metadata_type const *> const &GetParameterTypeNames() const
        {
            return m_paramTypeNames;
        }

        void SetParameterTypeNames(std::vector<type_name_metadata_type const *> const &paramTypeNames)
        {
            m_paramTypeNames = paramTypeNames;
        }

        type_name_metadata_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pTypeNameAsScope != NULL);
            return *m_pTypeNameAsScope;
        }

        void SetResolutionScope(type_name_metadata_type &typeNameMetaAsScope)
        {
            m_pTypeNameAsScope = &typeNameMetaAsScope;
        }

        void SetResolutionScope(type_metadata_type &typeMetaAsScope)
        {
            m_pTypeAsScope = &typeMetaAsScope;
        }

        method_metadata_type const *Resolve() const
        {
            // This method implementation is temporary.
            if (m_pTypeAsScope == NULL)
                m_pTypeAsScope = GetResolutionScope().Resolve();
            
            if (m_pMethodResolved == NULL)
            {
                type_metadata_type const *pRetType = NULL;
                pRetType = GetReturnTypeName().Resolve();
                std::vector<type_name_metadata_type const *> const &paramTypeNames = GetParameterTypeNames();
                typedef std::vector<type_name_metadata_type const *>::const_iterator ConstTypeNameMetadataIterator;
                std::vector<type_metadata_type const *> paramTypes(paramTypeNames.size());
                for (ConstTypeNameMetadataIterator i = paramTypeNames.cbegin(), i_end = paramTypeNames.cend(); i != i_end; ++i)
                    paramTypes.push_back((*i)->Resolve());
                m_pMethodResolved = m_pTypeAsScope->GetMethod(GetName(), GetCallingConvention(), *pRetType, paramTypes);
            }
            return m_pMethodResolved;
        }

    private:
        template<
            class MethodMetadataApiHolder
        >
        friend class BaseMethodMetadata;

        void SetToken(mdToken mdt)
        {
            m_mdt = mdt;
        }

        mutable std::wstring m_name;
        CallingConventions m_callingConvention;
        type_name_metadata_type const *m_pRetTypeName;
        std::vector<type_name_metadata_type const *> m_paramTypeNames;
        type_name_metadata_type *m_pTypeNameAsScope;
        mdToken m_mdt;
        mutable type_metadata_type const *m_pTypeAsScope;
        mutable method_metadata_type const *m_pMethodResolved;
    };

    
    
    
    
    template<
        class MethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseMethodNameMetadata<MethodNameMetadataApiHolder> const *>
    {
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);
            
            return x->m_name == y->m_name;
        }
    };

    template<
        class MethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataHash : 
        Traits::HashComputable<BaseMethodNameMetadata<MethodNameMetadataApiHolder> const *>
    {
        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);
            
            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->m_name));
            return seed;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP