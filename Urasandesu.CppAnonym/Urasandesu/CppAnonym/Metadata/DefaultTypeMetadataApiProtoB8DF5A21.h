#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct ITypeMetadataApi { };

    struct DefaultMethodMetadataApiProtoB8DF5A21;

    struct DefaultAssemblyMetadataApiProtoB8DF5A21;

    struct DefaultTypeMetadataApiProtoB8DF5A21 : 
        ITypeMetadataApi
    {
        typedef boost::mpl::vector<IMetaDataImport2, 
                                   DefaultAssemblyMetadataApiProtoB8DF5A21, 
                                   DefaultMethodMetadataApiProtoB8DF5A21> external_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H