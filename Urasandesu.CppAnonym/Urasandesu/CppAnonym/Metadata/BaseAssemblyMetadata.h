#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_H
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_H

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
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
    class BaseTypeMetadata;

    template<
        class AssemblyMetadataApiType
    >
    class BaseMethodMetadata;

    template<
        class AssemblyMetadataApiType = boost::use_default
    >
    class BaseAssemblyMetadata : 
        public IMetadataApiOperable<
            BaseAssemblyMetadata<AssemblyMetadataApiType>, 
            typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type
        >
    {
        CPPANONYM_BEGIN_HEAP_PROVIDER_DECLARATION()
            CPPANONYM_HEAP_PROVIDER(BaseModuleMetadata<AssemblyMetadataApiType>, mdToken, m_pModMetaFactory);
            CPPANONYM_HEAP_PROVIDER(BaseTypeMetadata<AssemblyMetadataApiType>, mdToken, m_pTypeMetaFactory);
            CPPANONYM_HEAP_PROVIDER(BaseMethodMetadata<AssemblyMetadataApiType>, mdToken, m_pMethodMetaFactory);
        CPPANONYM_END_HEAP_PROVIDER_DECLARATION()
    };

    typedef BaseAssemblyMetadata<boost::use_default> AssemblyMetadata;

#undef UNT

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_H