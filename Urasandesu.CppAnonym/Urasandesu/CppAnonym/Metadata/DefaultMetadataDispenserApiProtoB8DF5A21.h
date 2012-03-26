#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IMetadataDispenserApi { };

    struct DefaultMetadataInfoApiProtoB8DF5A21;

    struct DefaultAssemblyMetadataApiProtoB8DF5A21;

    struct DefaultMetadataDispenserApiProtoB8DF5A21 : 
        Traits::ParentApiOperable,
        Traits::ChildApiOperable, 
        IMetadataDispenserApi
    {
        typedef DefaultMetadataInfoApiProtoB8DF5A21 parent_api_type;
        typedef boost::mpl::vector<DefaultAssemblyMetadataApiProtoB8DF5A21> child_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H