#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_H
#define URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_H

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
    class BaseModuleMetadata : 
        public IMetadataApiOperable<
            BaseAssemblyMetadata<AssemblyMetadataApiType>, 
            typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type
        >
    {
    public:
        BaseAssemblyMetadata<AssemblyMetadataApiType> *GetAssembly()
        {
            HRESULT hr = E_FAIL;
            
            BaseAssemblyMetadata<AssemblyMetadataApiType> *pAsmMeta = NULL;
            pAsmMeta = GetHeapManager();
            if (pAsmMeta->GetToken() == -1)
            {
                if (GetApi()->AssemblyImport.p == NULL)
                {
                    hr = GetApi()->Import->QueryInterface(api_type::IID_IAssemblyImport, 
                                    reinterpret_cast<void **>(&GetApi()->AssemblyImport));
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
                
                mdAssembly mda = mdAssemblyNil;
                hr = GetApi()->AssemblyImport->GetAssemblyFromScope(&mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                pAsmMeta->SetToken(mda);
            }
            return pAsmMeta;
        }
        
        BaseTypeMetadata<AssemblyMetadataApiType> *GetType(mdTypeDef mdtd)
        {
            BaseTypeMetadata<AssemblyMetadataApiType> *pTypeMeta = NULL;
            pTypeMeta = CreateIfNecessary<BaseTypeMetadata<AssemblyMetadataApiType>>(mdtd);
            return pTypeMeta;
        }
        
    private:
        boost::unordered_map<mdToken, SIZE_T> m_typeIndexes;
    };

    typedef BaseModuleMetadata<boost::use_default> ModuleMetadata;

#undef UNT

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_H