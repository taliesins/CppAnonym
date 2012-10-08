#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ITYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ITypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseITypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultITypeMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultITypeMetadataApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultITypeMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>
            > api_cartridges;
        };

    }   // namespace DefaultITypeMetadataApiHolderDetail {

    struct DefaultITypeMetadataApiHolder : 
        DefaultITypeMetadataApiHolderDetail::DefaultITypeMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H