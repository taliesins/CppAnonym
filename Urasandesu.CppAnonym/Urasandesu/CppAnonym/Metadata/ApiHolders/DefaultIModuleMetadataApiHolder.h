#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_IMODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/IModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIModuleMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_IASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/IAssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIModuleMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultIModuleMetadataApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIModuleMetadataApiHolderImpl
        {
            typedef map<
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<IAssemblyMetadataHashLabel, IAssemblyMetadataHash>,
                pair<IAssemblyMetadataEqualToLabel, IAssemblyMetadataEqualTo>
            > api_cartridges;
        };

    }   // namespace DefaultIModuleMetadataApiHolderDetail {

    struct DefaultIModuleMetadataApiHolder : 
        DefaultIModuleMetadataApiHolderDetail::DefaultIModuleMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDER_H