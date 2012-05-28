#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultILGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultILGeneratorApiHolderImpl
        {
            typedef map<pair<MethodMetadataLabel, BaseMethodMetadata<> >, 
                        pair<TypeMetadataLabel, BaseTypeMetadata<> >, 
                        pair<AssemblyMetadataLabel, BaseAssemblyMetadata<> >, 
                        pair<MetadataDispenserLabel, BaseMetadataDispenser<> > > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultILGeneratorApiHolder : 
        DefaultILGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H