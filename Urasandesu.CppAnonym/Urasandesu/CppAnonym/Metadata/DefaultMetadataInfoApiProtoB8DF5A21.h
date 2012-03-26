#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_TRAITS_PARENTAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ParentApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CHILDAPIOPERABLE_H
#include <Urasandesu/CppAnonym/Traits/ChildApiOperable.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultRuntimeHostApiProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMetadataDispenserApiProtoB8DF5A21;

    struct IMetadataInfoApi { };

    struct DefaultMetadataInfoApiProtoB8DF5A21 : 
        Traits::ParentApiOperable,
        Traits::ChildApiOperable, 
        IMetadataInfoApi
    {
        typedef Hosting::DefaultRuntimeHostApiProto07F03042 parent_api_type;
        typedef boost::mpl::vector<DefaultMetadataDispenserApiProtoB8DF5A21> child_api_types;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIPROTOB8DF5A21_H