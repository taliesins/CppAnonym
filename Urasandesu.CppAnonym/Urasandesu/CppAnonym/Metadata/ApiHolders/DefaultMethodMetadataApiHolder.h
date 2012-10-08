#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultMethodMetadataApiHolder
    {
        typedef boost::mpl::map<boost::mpl::pair<IMetaDataImport2, IMetaDataImport2>, 
                                boost::mpl::pair<Interfaces::TypeMetadataLabel, BaseTypeMetadata<> > > api_cartridges;
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H