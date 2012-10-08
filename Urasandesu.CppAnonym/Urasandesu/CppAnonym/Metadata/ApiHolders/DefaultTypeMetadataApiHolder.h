#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultTypeMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                                boost::mpl::pair<Interfaces::AssemblyMetadataLabel, BaseAssemblyMetadata<> >, 
                                boost::mpl::pair<Interfaces::MethodMetadataLabel, BaseMethodMetadata<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H