#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultTypeMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                                boost::mpl::pair<AssemblyMetadataLabel, BaseAssemblyMetadata<> >, 
                                boost::mpl::pair<MethodMetadataLabel, BaseMethodMetadata<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIHOLDER_H