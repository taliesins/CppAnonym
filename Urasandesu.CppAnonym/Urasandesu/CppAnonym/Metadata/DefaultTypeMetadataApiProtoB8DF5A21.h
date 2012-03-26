#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct ITypeMetadataApi { };

    struct DefaultAssemblyMetadataApiProtoB8DF5A21;

    struct DefaultTypeMetadataApiProtoB8DF5A21 : 
        Traits::ParentApiOperable,
        Traits::ChildApiOperable, 
        ITypeMetadataApi
    {
        typedef DefaultAssemblyMetadataApiProtoB8DF5A21 parent_api_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H