﻿#pragma once
#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H
#define URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_HOSTINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/HostInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFOFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        struct DefaultRuntimeHostApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<MetadataInfoLabel, MetadataInfo>
                //pair<StrongNameInfoLabel, StrongNameInfo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultRuntimeHostApiHolder : 
        Detail::DefaultRuntimeHostApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

#endif  // URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTRUNTIMEHOSTAPIHOLDER_H