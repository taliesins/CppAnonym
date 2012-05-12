#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H
#define URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultRuntimeHostApiProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct IFusionInfoApi { };

    struct DefaultFusionInfoApiProto3CBCB74B : 
        IFusionInfoApi
    {
        typedef boost::mpl::vector<Hosting::DefaultRuntimeHostApiProto07F03042> external_api_types;
    };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H