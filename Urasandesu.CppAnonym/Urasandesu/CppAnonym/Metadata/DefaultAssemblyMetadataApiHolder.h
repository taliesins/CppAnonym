#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_METADATADISPENSERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataDispenserLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultAssemblyMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<MetadataDispenserLabel, BaseMetadataDispenser<> >, 
                                boost::mpl::pair<AssemblyNameMetadataLabel, BaseAssemblyNameMetadata<> >, 
                                boost::mpl::pair<TypeMetadataLabel, BaseTypeMetadata<> >, 
                                boost::mpl::pair<IMetaDataImport2, IMetaDataImport2> > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPIHOLDER_H