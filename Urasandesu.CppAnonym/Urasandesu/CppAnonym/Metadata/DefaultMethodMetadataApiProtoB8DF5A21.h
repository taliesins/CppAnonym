#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultTypeMetadataApiProtoB8DF5A21;

    struct IMethodMetadataApi { };

    struct DefaultMethodMetadataApiProtoB8DF5A21 : 
        IMethodMetadataApi
    {
        typedef boost::mpl::vector<IMetaDataImport2, 
                                   DefaultTypeMetadataApiProtoB8DF5A21> external_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIPROTOB8DF5A21_H