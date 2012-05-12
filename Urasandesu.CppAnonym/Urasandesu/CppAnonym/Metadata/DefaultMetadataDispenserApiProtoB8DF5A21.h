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
        typedef boost::mpl::vector<DefaultMetadataInfoApiProtoB8DF5A21, 
                                   DefaultAssemblyMetadataApiProtoB8DF5A21> external_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIPROTOB8DF5A21_H