#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IMetadataDispenserApi { };

    struct DefaultMetadataInfoApiProtoB8DF5A21;

    struct DefaultAssemblyMetadataApiProtoB8DF5A21;

    struct DefaultMetadataDispenserApiProtoB8DF5A21 : 
        IMetadataDispenserApi
    {
        typedef DefaultMetadataInfoApiProtoB8DF5A21 parent_api_type;
        typedef boost::mpl::vector<DefaultAssemblyMetadataApiProtoB8DF5A21> child_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H