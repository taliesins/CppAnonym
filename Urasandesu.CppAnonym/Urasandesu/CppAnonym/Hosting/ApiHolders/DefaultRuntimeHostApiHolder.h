#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#define URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    struct DefaultRuntimeHostApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<StrongNaming::Interfaces::StrongNameInfoLabel, StrongNaming::BaseStrongNameInfo<> >, 
                                boost::mpl::pair<Metadata::Interfaces::MetadataInfoLabel, Metadata::BaseMetadataInfo<> >, 
                                boost::mpl::pair<Fusion::Interfaces::FusionInfoLabel, Fusion::BaseFusionInfo<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H