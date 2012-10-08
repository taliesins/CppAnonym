#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_LOCALNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/LocalNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseLocalNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultILGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        //typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        //typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        //typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        //typedef typename ILGeneratorApiAt<ILGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        struct DefaultILGeneratorApiHolderImpl
        {
            typedef map<
                pair<FieldNameMetadataGeneratorLabel, FieldNameMetadataGenerator>, 
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>,
                pair<MethodMetadataLabel, MethodMetadata>, 
                pair<TypeMetadataLabel, TypeMetadata>, 
                pair<LocalNameMetadataGeneratorLabel, LocalNameMetadataGenerator>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultILGeneratorApiHolder : 
        Detail::DefaultILGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTILGENERATORAPIHOLDER_H