#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMethodMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                                boost::mpl::pair<TypeMetadataLabel, BaseTypeMetadata<> > > api_cartridges;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIHOLDER_H