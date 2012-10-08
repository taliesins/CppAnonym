#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    //struct DefaultAssemblyMetadataApiHolder;

    struct DefaultMetadataDispenserApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Interfaces::MetadataInfoLabel, BaseMetadataInfo<> >, 
                                boost::mpl::pair<Interfaces::AssemblyMetadataLabel, BaseAssemblyMetadata<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H