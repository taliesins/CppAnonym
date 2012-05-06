#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#define URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    struct DefaultStrongNameInfoApiProto4236D495;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataInfoApiProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct DefaultFusionInfoApiProto3CBCB74B;
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct IRuntimeHostApi { };

    struct DefaultRuntimeHostApiProto07F03042 : 
        IRuntimeHostApi
    {
        typedef boost::mpl::vector<StrongNaming::DefaultStrongNameInfoApiProto4236D495, 
                                   Metadata::DefaultMetadataInfoApiProtoB8DF5A21, 
                                   Fusion::DefaultFusionInfoApiProto3CBCB74B> external_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H