#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEKEYLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameKeyLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultAssemblyNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultAssemblyNameMetadataApiHolder
    { 
        typedef boost::mpl::map<boost::mpl::pair<AssemblyMetadataLabel, BaseAssemblyMetadata<> >, 
                                boost::mpl::pair<StrongNaming::StrongNameKeyLabel, StrongNaming::BaseStrongNameKey<> >, 
                                boost::mpl::pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport> > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H