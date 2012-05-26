#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODNAMEMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODNAMEMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODNAMEMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMethodNameMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMethodNameMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<TypeMetadataLabel, BaseTypeMetadata<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODNAMEMETADATAAPIHOLDER_H