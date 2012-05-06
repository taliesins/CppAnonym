#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultRuntimeHostApiProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataDispenserApiProtoB8DF5A21;

    struct IMetadataInfoApi { };

    struct DefaultMetadataInfoApiProtoB8DF5A21 : 
        IMetadataInfoApi
    {
        //typedef Hosting::DefaultRuntimeHostApiProto07F03042 parent_api_type;
        typedef boost::mpl::vector<Hosting::DefaultRuntimeHostApiProto07F03042, 
                                   DefaultMetadataDispenserApiProtoB8DF5A21> external_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H