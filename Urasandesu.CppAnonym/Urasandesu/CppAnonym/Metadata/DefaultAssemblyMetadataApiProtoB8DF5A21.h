#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct IAssemblyMetadataApi { };

    struct DefaultMetadataDispenserApiProtoB8DF5A21;
    struct DefaultTypeMetadataApiProtoB8DF5A21;
    struct DefaultAssemblyNameMetadataApiProtoB8DF5A21;

    struct DefaultAssemblyMetadataApiProtoB8DF5A21 : 
        IAssemblyMetadataApi
    {
        typedef boost::mpl::vector<DefaultMetadataDispenserApiProtoB8DF5A21, 
                                   DefaultAssemblyNameMetadataApiProtoB8DF5A21, 
                                   DefaultTypeMetadataApiProtoB8DF5A21, 
                                   IMetaDataImport2> external_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIPROTOB8DF5A21_H