#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#define URASANDESU_CPPANONYM_HOSTING_DEFAULTRUNTIMEHOSTAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_RUNTIMEHOSTAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/RuntimeHostApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/DefaultFusionInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_FUSIONINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/FusionInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_FUSIONINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/FusionInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_DEFAULTSTRONGNAMEINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/DefaultStrongNameInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATAINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATAINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/MetadataInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETADATAINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMetadataInfoApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultRuntimeHostApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<StrongNaming::StrongNameInfoLabel, StrongNaming::BaseStrongNameInfo<> >, 
                                boost::mpl::pair<Metadata::MetadataInfoLabel, Metadata::BaseMetadataInfo<> >, 
                                boost::mpl::pair<Fusion::FusionInfoLabel, Fusion::BaseFusionInfo<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

#endif  // URASANDESU_CPPANONYM_HOSTING_DEFAULTRUNTIMEHOSTAPIHOLDER_H