#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#define URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H

//#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
//#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
//#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataInfoApiProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct DefaultFusionInfoApiProto3CBCB74B;
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct IRuntimeHostApi { };

    struct DefaultRuntimeHostApiProto07F03042 : 
        //Traits::ChildApiOperable, 
        IRuntimeHostApi
    {
        //typedef INT strong_naming_info_api_type;
        //typedef Metadata::DefaultMetadataInfoApiProtoB8DF5A21 metadata_info_api_type;
        //typedef Fusion::DefaultFusionInfoApiProto3CBCB74B fusion_info_api_type;
        typedef boost::mpl::vector<INT, 
                                   Metadata::DefaultMetadataInfoApiProtoB8DF5A21, 
                                   Fusion::DefaultFusionInfoApiProto3CBCB74B> child_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H