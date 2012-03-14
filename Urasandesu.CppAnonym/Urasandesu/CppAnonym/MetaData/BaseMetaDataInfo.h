#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
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

    struct DefaultInfoMetadataApi;
    struct DefaultAssemblyMetadataApi;

    template<
        class InfoMetadataApiType = boost::use_default,
        class AssemblyMetadataApiType = boost::use_default
    >    
    class BaseMetadataInfo
    {
    public:
        typedef typename UNT::Replace<InfoMetadataApiType, boost::use_default, DefaultInfoMetadataApi>::type info_meta_data_api_type;
        typedef typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type assembly_meta_data_api_type;
    
    private:
        CPPANONYM_BEGIN_HEAP_PROVIDER_DECLARATION()
            CPPANONYM_HEAP_PROVIDER(info_meta_data_api_type, mdToken, m_pInfoMetaApiFactory);
            CPPANONYM_HEAP_PROVIDER(assembly_meta_data_api_type, mdToken, m_pAsmMetaApiFactory);
            CPPANONYM_HEAP_PROVIDER(BaseAssemblyMetadata<AssemblyMetadataApiType>, mdToken, m_pAsmMetaFactory);
        CPPANONYM_END_HEAP_PROVIDER_DECLARATION()

    public:
        BaseMetadataInfo() : 
            m_pInfoMetaApi(NULL)
        { }

        template<class T>
        T *CreatePseudo()
        {
            T *pObj = NewPseudo<T>();
            pObj->Init(pObj, NewPseudo<assembly_meta_data_api_type>());
            return pObj;
        }

    private:
        info_meta_data_api_type *GetInfoMetaApi()
        {
            BOOST_THROW_EXCEPTION(CppAnonymException("Not Implemented!!"));
            return NULL;
        }
        info_meta_data_api_type *m_pInfoMetaApi;
    };

    typedef BaseMetadataInfo<boost::use_default, boost::use_default> MetadataInfo;

#undef UNT

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_H