#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMethodMetadataApiHolderImpl
        {
            typedef map<
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<TypeNameMetadataHashLabel, TypeNameMetadataHash>, 
                //pair<TypeNameMetadataEqualToLabel, TypeNameMetadataEqualTo>, 
                //pair<IMethodNameMetadataLabel, IMethodNameMetadata>,
                //pair<MethodNameMetadataLabel, MethodNameMetadata>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<MethodNameMetadataLabel, MethodNameMetadata>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMethodMetadataApiHolder : 
        Detail::DefaultMethodMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H