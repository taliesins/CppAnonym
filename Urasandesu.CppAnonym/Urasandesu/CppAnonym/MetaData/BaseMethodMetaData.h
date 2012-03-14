#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_H

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
    class BaseTypeMetadata;

    template<
        class AssemblyMetadataApiType = boost::use_default
    >
    class BaseMethodMetadata : 
        public IMetadataApiOperable<
            BaseAssemblyMetadata<AssemblyMetadataApiType>, 
            typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type
        >
    {
    public:
        BaseMethodMetadata() :
            m_pTypeMeta(NULL)
        { }
        
        BaseTypeMetadata<AssemblyMetadataApiType> *GetDeclaringType()
        {
            HRESULT hr = E_FAIL;
            
            if (m_pTypeMeta == NULL)
            {
                mdTypeDef mdtd = mdTypeDefNil;      
                WCHAR methodName[MAX_SYM_NAME] = { 0 };
                ULONG methodNameSize = sizeof(methodName);
                DWORD methodAttr = 0;
                PCCOR_SIGNATURE pMethodSig = NULL;
                ULONG methodSigSize = 0;
                ULONG methodRva = 0;
                DWORD methodImplFlg = 0;
                hr = GetApi()->Import->GetMethodProps(GetToken(), &mdtd, methodName, 
                                            methodNameSize, &methodNameSize, &methodAttr, 
                                            &pMethodSig, &methodSigSize, &methodRva, 
                                            &methodImplFlg);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                m_pTypeMeta = CreateIfNecessary<BaseTypeMetadata<AssemblyMetadataApiType>>(mdtd);
            }
            return m_pTypeMeta;
        }

        //BaseMethodBodyMetadata<AssemblyMetadataApiType> *GetMethodBody()
        //{
        //    HRESULT hr = E_FAIL;
        //    
        //    CComPtr<ICeeGen> pCeeGen;
        //    hr = GetApi()->Import->QueryInterface(IID_ICeeGen, reinterpret_cast<void **>(&pCeeGen));
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        //    
        //    BOOST_THROW_EXCEPTION(CppAnonymException("Not Implemented!!"));
        //    return NULL;
        //}
        
    private:
        BaseTypeMetadata<AssemblyMetadataApiType> *m_pTypeMeta;
    };

    typedef BaseMethodMetadata<boost::use_default> MethodMetadata;

#undef UNT

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_H