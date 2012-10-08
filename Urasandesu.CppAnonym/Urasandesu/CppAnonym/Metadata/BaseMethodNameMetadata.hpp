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
        public MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::IMethodNameMetadataLabel>::type,
        boost::noncopyable
    {
    public:
        typedef BaseMethodNameMetadata<MethodNameMetadataApiHolder> this_type;
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::IMethodNameMetadataLabel>::type base_type;

        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename MethodNameMetadataApiAt<MethodNameMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;

        BaseMethodNameMetadata() : 
            m_pTypeNameAsScope(NULL),
            m_pTypeAsScope(NULL),
            m_pRetTypeName(NULL), 
            m_pResolvedMethod(NULL), 
            m_mdt(mdTokenNil)
        { }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            _ASSERTE(m_pTypeNameAsScope != NULL || m_pTypeAsScope != NULL);
            if (m_pTypeNameAsScope != NULL)
                return m_pTypeNameAsScope->Map<T>();
            else
                return m_pTypeAsScope->GetTypeNameCore().Map<T>();
        }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"WriteLine";
            }
            return m_name;
        }

        CallingConventions const &GetCallingConvention() const
        {
            return m_callingConvention;
        }

        typename base_type::i_type_name_metadata_type const &GetReturnTypeName() const
        {
            _ASSERTE(m_pRetTypeName != NULL);
            return *m_pRetTypeName;
        }

        std::vector<typename base_type::i_type_name_metadata_type const *> const &GetParameterTypeNames() const
        {
            return m_paramTypeNames;
        }

        typename base_type::i_type_name_metadata_type const &GetResolutionScope() const
        {
            return Map<type_name_metadata_type>();
        }

        typename base_type::i_method_metadata_type const &Resolve() const
        {
            return ResolveCore();
        }

    private:
        friend typename type_name_metadata_type;
        friend typename method_metadata_type;

        void Init(type_name_metadata_type &typeNameAsScope) const
        {
            _ASSERTE(m_pTypeNameAsScope == NULL && m_pTypeAsScope == NULL);
            m_pTypeNameAsScope = &typeNameAsScope;
        }

        void Init(type_metadata_type &typeAsScope) const
        {
            _ASSERTE(m_pTypeNameAsScope == NULL && m_pTypeAsScope == NULL);
            m_pTypeAsScope = &typeAsScope;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            m_callingConvention = callingConvention;
        }

        void SetReturnTypeName(typename base_type::i_type_name_metadata_type const &retTypeName)
        {
            m_pRetTypeName = &retTypeName;
        }

        void SetParameterTypeNames(std::vector<typename base_type::i_type_name_metadata_type const *> const &paramTypeNames)
        {
            m_paramTypeNames = paramTypeNames;
        }

        method_metadata_type const &ResolveCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->ResolveCore();
        }
        
        method_metadata_type &ResolveCore()
        {
            if (m_pTypeAsScope == NULL)
                m_pTypeAsScope = &Map<type_name_metadata_type>().ResolveCore();

            if (m_pResolvedMethod == NULL)
                m_pResolvedMethod = m_pTypeAsScope->GetMethodCore(*this);

            return *m_pResolvedMethod;
            //if (m_pTypeAsScope == NULL)
            //    m_pTypeAsScope = GetResolutionScope().Resolve();
            //
            //if (m_pResolvedMethod == NULL)
            //{
            //    type_metadata_type const *pRetType = NULL;
            //    pRetType = GetReturnTypeName().Resolve();
            //    std::vector<type_name_metadata_type const *> const &paramTypeNames = GetParameterTypeNames();
            //    typedef std::vector<type_name_metadata_type const *>::const_iterator ConstTypeNameMetadataIterator;
            //    std::vector<type_metadata_type const *> paramTypes;
            //    paramTypes.reserve(paramTypeNames.size());
            //    for (ConstTypeNameMetadataIterator i = paramTypeNames.cbegin(), i_end = paramTypeNames.cend(); i != i_end; ++i)
            //        paramTypes.push_back((*i)->Resolve());
            //    m_pResolvedMethod = m_pTypeAsScope->GetMethod(GetName(), GetCallingConvention(), *pRetType, paramTypes);
            //}
            //return m_pResolvedMethod;
        }

        //void SetResolutionScope(type_name_metadata_type &typeNameMetaAsScope)
        //{
        //    m_pTypeNameAsScope = &typeNameMetaAsScope;
        //}

        //void SetResolutionScope(type_metadata_type &typeMetaAsScope)
        //{
        //    m_pTypeAsScope = &typeMetaAsScope;
        //}

        void SetToken(mdToken mdt)
        {
            m_mdt = mdt;
        }

        void SetResolvedMethod(method_metadata_type &resolvedMethod)
        {
            _ASSERTE(m_pResolvedMethod == NULL);
            m_pResolvedMethod = &resolvedMethod;
        }

        mutable type_name_metadata_type *m_pTypeNameAsScope;
        mutable type_metadata_type *m_pTypeAsScope;
        mutable std::wstring m_name;
        CallingConventions m_callingConvention;
        typename base_type::i_type_name_metadata_type const *m_pRetTypeName;
        std::vector<typename base_type::i_type_name_metadata_type const *> m_paramTypeNames;
        mdToken m_mdt;
        method_metadata_type *m_pResolvedMethod;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP