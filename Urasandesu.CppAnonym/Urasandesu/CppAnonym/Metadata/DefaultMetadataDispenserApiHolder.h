#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_METADATAINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataDispenserApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyMetadataLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    //struct DefaultAssemblyMetadataApiHolder;

    struct DefaultMetadataDispenserApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<MetadataInfoLabel, BaseMetadataInfo<> >, 
                                boost::mpl::pair<AssemblyMetadataLabel, BaseAssemblyMetadata<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATADISPENSERAPIHOLDER_H