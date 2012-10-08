#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDER_H

//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAGENERATORLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataGeneratorLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataGeneratorFwd.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultInstructionApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace DefaultInstructionApiHolderDetail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultInstructionApiHolderImpl
        {
            typedef map<
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>,
                pair<MethodBodyWriterLabel, MethodBodyWriter>,
                pair<IMethodNameMetadataLabel, IMethodNameMetadata>,
                pair<IFieldNameMetadataLabel, IFieldNameMetadata>
            > api_cartridges;
        };

    }   // namespace DefaultInstructionApiHolderDetail {

    struct DefaultInstructionApiHolder : 
        DefaultInstructionApiHolderDetail::DefaultInstructionApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDER_H