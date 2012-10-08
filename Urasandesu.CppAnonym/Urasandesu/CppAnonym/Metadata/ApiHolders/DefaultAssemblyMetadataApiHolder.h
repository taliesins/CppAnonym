#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultAssemblyMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<Interfaces::MetadataDispenserLabel, BaseMetadataDispenser<> >, 
                                boost::mpl::pair<Interfaces::AssemblyNameMetadataLabel, BaseAssemblyNameMetadata<> >, 
                                boost::mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<> >, 
                                boost::mpl::pair<IMetaDataImport2, IMetaDataImport2> > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H