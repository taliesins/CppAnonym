#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYMETADATA_H
#define URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYMETADATA_H

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
        class AssemblyMetadataApiType = boost::use_default
    >
    class BaseMethodBodyMetadata : 
        public IMetadataApiOperable<
            BaseAssemblyMetadata<AssemblyMetadataApiType>, 
            typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type
        >
    {
    };

    typedef BaseMethodBodyMetadata<boost::use_default> MethodBodyMetadata;

#undef UNT

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYMETADATA_H