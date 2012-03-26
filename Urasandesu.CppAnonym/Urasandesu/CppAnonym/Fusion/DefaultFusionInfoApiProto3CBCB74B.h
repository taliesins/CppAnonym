#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H
#define URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultRuntimeHostApiProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct IFusionInfoApi { };

    struct DefaultFusionInfoApiProto3CBCB74B : 
        Traits::ParentApiOperable,
        Traits::ChildApiOperable, 
        IFusionInfoApi
    {
        typedef Hosting::DefaultRuntimeHostApiProto07F03042 parent_api_type;
    };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H