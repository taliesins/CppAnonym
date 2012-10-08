#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODE_H
#include <Urasandesu/CppAnonym/Metadata/OpCode.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODES_H
#include <Urasandesu/CppAnonym/Metadata/OpCodes.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataApiHolder
    >    
    class BaseMethodMetadata : 
        public MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type,
        boost::noncopyable
    {
    public:
        typedef BaseMethodMetadata<MethodMetadataApiHolder> this_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type base_type;

        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::MethodNameMetadataLabel>::type method_name_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;

        BaseMethodMetadata() : 
            m_pTypeAsScope(NULL),
            m_pMethodName(NULL), 
            m_mdt(mdTokenNil)
        { }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pTypeAsScope != NULL); return m_pTypeAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                method_name_metadata_type const &methodName = GetMethodNameCore();

                std::wstring const &name = methodName.GetName();

                SimpleBlob sig;

                CallingConventions const &callingConvention = methodName.GetCallingConvention();
                SignatureUtil::PutSignatures(sig, callingConvention);
                
                std::vector<i_type_name_metadata_type const *> const &paramTypeNames = methodName.GetParameterTypeNames();
                sig.Put<COR_SIGNATURE>(paramTypeNames.size());

                i_type_name_metadata_type const &retTypeName = methodName.GetReturnTypeName();
                SignatureUtil::PutSignatures(sig, retTypeName);

                typedef std::vector<i_type_name_metadata_type const *>::const_iterator ConstIterator;
                for (ConstIterator ci = paramTypeNames.cbegin(), ci_end = paramTypeNames.cend(); ci != ci_end; ++ci)
                    SignatureUtil::PutSignatures(sig, **ci);

                this_type *pMutableThis = const_cast<this_type *>(this);

                assembly_metadata_type &asmMeta = pMutableThis->Map<assembly_metadata_type>();
                type_metadata_type &typeMeta = pMutableThis->Map<type_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = asmMeta.GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.FindMethod(typeMeta.GetToken(), name.c_str(), 
                                                   sig.Ptr(), sig.Size(), &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return m_mdt;
        }

        typename base_type::i_method_name_metadata_type const &GetMethodName() const
        {
            return GetMethodNameCore();
        }

    private:
        friend typename type_metadata_type;

        void Init(type_metadata_type &typeAsScope) const
        {
            _ASSERTE(m_pTypeAsScope == NULL);
            m_pTypeAsScope = &typeAsScope;
        }

        void SetToken(mdToken mdt)
        {
            _ASSERTE(m_mdt == mdTokenNil);
            _ASSERTE(mdt != mdTokenNil);

            m_mdt = mdt;
        }

        void SetMethodName(method_name_metadata_type &methodName)
        {
            if (m_pMethodName != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            m_pMethodName = &methodName;
        }

        method_name_metadata_type const &GetMethodNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetMethodNameCore();
        }

        method_name_metadata_type &GetMethodNameCore()
        {
            if (m_pMethodName == NULL)
            {
                type_metadata_type &typeMeta = Map<type_metadata_type>();

                m_pMethodName = typeMeta.MethodNameMetadataHeap().New();
                m_pMethodName->Init(typeMeta);
                m_pMethodName->SetToken(GetToken());
                m_pMethodName->SetResolvedMethod(*this);
            }
            return *m_pMethodName;
        }


        mutable type_metadata_type *m_pTypeAsScope;
        mutable method_name_metadata_type *m_pMethodName;
        mutable mdToken m_mdt;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP