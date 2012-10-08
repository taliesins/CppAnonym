#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_IMETHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/IMethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIMethodMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ITYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ITypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseITypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultIMethodMetadataApiHolderDetail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIMethodMetadataApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataLabel, ITypeMetadata>
            > api_cartridges;
        };

    }   // namespace DefaultIMethodMetadataApiHolderDetail {

    struct DefaultIMethodMetadataApiHolder : 
        DefaultIMethodMetadataApiHolderDetail::DefaultIMethodMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H