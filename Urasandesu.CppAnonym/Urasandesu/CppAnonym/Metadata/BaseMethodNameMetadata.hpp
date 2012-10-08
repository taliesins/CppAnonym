#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataFwd.hpp>
#endif

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

        BaseMethodNameMetadata() : 
            m_pRetTypeName(NULL), 
            m_pTypeNameAsScope(NULL), 
            m_pTypeAsScope(NULL), 
            m_pResolvedMethod(NULL), 
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
            
            if (m_pResolvedMethod == NULL)
            {
                type_metadata_type const *pRetType = NULL;
                pRetType = GetReturnTypeName().Resolve();
                std::vector<type_name_metadata_type const *> const &paramTypeNames = GetParameterTypeNames();
                typedef std::vector<type_name_metadata_type const *>::const_iterator ConstTypeNameMetadataIterator;
                std::vector<type_metadata_type const *> paramTypes;
                paramTypes.reserve(paramTypeNames.size());
                for (ConstTypeNameMetadataIterator i = paramTypeNames.cbegin(), i_end = paramTypeNames.cend(); i != i_end; ++i)
                    paramTypes.push_back((*i)->Resolve());
                m_pResolvedMethod = m_pTypeAsScope->GetMethod(GetName(), GetCallingConvention(), *pRetType, paramTypes);
            }
            return m_pResolvedMethod;
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

        void SetResolvedMethod(method_metadata_type &resolvedMethod)
        {
            _ASSERTE(m_pResolvedMethod == NULL);
            m_pResolvedMethod = &resolvedMethod;
        }

        mutable std::wstring m_name;
        CallingConventions m_callingConvention;
        type_name_metadata_type const *m_pRetTypeName;
        std::vector<type_name_metadata_type const *> m_paramTypeNames;
        type_name_metadata_type *m_pTypeNameAsScope;
        mdToken m_mdt;
        mutable type_metadata_type const *m_pTypeAsScope;
        mutable method_metadata_type const *m_pResolvedMethod;
    };

    
    
    

    template<
        class MethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataHash : 
        Traits::HashComputable<BaseMethodNameMetadata<MethodNameMetadataApiHolder> const *>
    {
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeNameMetadataHashLabel>::type type_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Collections;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, v->GetCallingConvention().Value());
            hash_combine(seed, type_name_metadata_hash_type()(&v->GetReturnTypeName()));
            hash_combine(seed, SequenceHashValue(v->GetParameterTypeNames().cbegin(), 
                                                 v->GetParameterTypeNames().cend(), 
                                                 type_name_metadata_hash_type()));
            hash_combine(seed, type_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class MethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseMethodNameMetadata<MethodNameMetadataApiHolder> const *>
    {
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeNameMetadataEqualToLabel>::type type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   x->GetCallingConvention() == y->GetCallingConvention() &&
                   type_name_metadata_equal_to_type()(&x->GetReturnTypeName(), &y->GetReturnTypeName()) &&
                   SequenceEqual(x->GetParameterTypeNames().cbegin(), x->GetParameterTypeNames().cend(), 
                                 y->GetParameterTypeNames().cbegin(), y->GetParameterTypeNames().cend()) &&
                   type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP