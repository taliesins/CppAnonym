#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IAssemblyMetadataApi { };

    struct DefaultMetadataDispenserApiProtoB8DF5A21;

    struct DefaultTypeMetadataApiProtoB8DF5A21;

    struct DefaultAssemblyMetadataApiProtoB8DF5A21 : 
        Traits::ParentApiOperable,
        Traits::ChildApiOperable, 
        IAssemblyMetadataApi
    {
        typedef DefaultMetadataDispenserApiProtoB8DF5A21 parent_api_type;
        typedef boost::mpl::vector<DefaultTypeMetadataApiProtoB8DF5A21, IMetaDataImport2> child_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H