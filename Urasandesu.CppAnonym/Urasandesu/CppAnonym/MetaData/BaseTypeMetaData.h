#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_H
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#ifdef UNT
#error This .h reserves the word "UNT" that means "Urasandesu::CppAnonym::Traits".
#endif
#define UNT Urasandesu::CppAnonym::Traits

    template<
        class HeapManagerType,
        class ApiType
    >        
    class ATL_NO_VTABLE IMetadataApiOperable;

    template<
        class AssemblyMetadataApiType
    >
    class BaseAssemblyMetadata;

    struct DefaultAssemblyMetadataApi;

    template<
        class AssemblyMetadataApiType
    >
    class BaseModuleMetadata;

    template<
        class AssemblyMetadataApiType
    >
    class BaseMethodMetadata;

    template<
        class AssemblyMetadataApiType = boost::use_default
    >
    class BaseTypeMetadata : 
        public IMetadataApiOperable<
            BaseAssemblyMetadata<AssemblyMetadataApiType>, 
            typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type
        >
    {
    public:
        BaseTypeMetadata() : 
            m_pModMeta(NULL)
        { }
        
        BaseModuleMetadata<AssemblyMetadataApiType> *GetModule()
        {
            HRESULT hr = E_FAIL;
            
            if (m_pModMeta == NULL)
            {
                mdModule mdm = mdModuleNil;
                hr = GetApi()->Import->GetModuleFromScope(&mdm);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                m_pModMeta = CreateIfNecessary<BaseModuleMetadata<AssemblyMetadataApiType>>(mdm);
            }
            return m_pModMeta;
        }

        BaseMethodMetadata<AssemblyMetadataApiType> *GetMethod(mdMethodDef mdmd)
        {
            HRESULT hr = E_FAIL;
            
            // TODO: Set its properties if the token is valid.
            mdTypeDef mdtd = mdTypeDefNil;      
            WCHAR methodName[MAX_SYM_NAME] = { 0 };
            ULONG methodNameSize = sizeof(methodName);
            DWORD methodAttr = 0;
            PCCOR_SIGNATURE pMethodSig = NULL;
            ULONG methodSigSize = 0;
            ULONG methodRva = 0;
            DWORD methodImplFlg = 0;            
            hr = GetApi()->Import->GetMethodProps(mdmd, &mdtd, methodName, 
                                            methodNameSize, &methodNameSize, &methodAttr, 
                                            &pMethodSig, &methodSigSize, &methodRva, 
                                            &methodImplFlg);
            if (FAILED(hr))
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            
            return CreateIfNecessary<BaseMethodMetadata<AssemblyMetadataApiType>>(mdmd);
        }
        
    private:
        BaseModuleMetadata<AssemblyMetadataApiType> *m_pModMeta;
    };

    typedef BaseTypeMetadata<boost::use_default> TypeMetadata;

#undef UNT

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_H