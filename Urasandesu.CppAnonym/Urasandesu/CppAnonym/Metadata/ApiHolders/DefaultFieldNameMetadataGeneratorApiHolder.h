#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDER_H

//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataFwd.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultFieldNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultFieldNameMetadataGeneratorApiHolderImpl
        {
            //typedef map<
            //    pair<AssemblyMetadataLabel, AssemblyMetadata>,
            //    pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
            //    pair<AssemblyNameMetadataHashLabel, AssemblyNameMetadataHash>,
            //    pair<AssemblyNameMetadataEqualToLabel, AssemblyNameMetadataEqualTo>,
            //    pair<ModuleMetadataLabel, ModuleMetadata>,
            //    pair<ModuleNameMetadataLabel, ModuleNameMetadata>,
            //    pair<ModuleNameMetadataHashLabel, ModuleNameMetadataHash>,
            //    pair<ModuleNameMetadataEqualToLabel, ModuleNameMetadataEqualTo>,
            //    pair<TypeMetadataLabel, TypeMetadata>,
            //    pair<MethodNameMetadataLabel, MethodNameMetadata>,
            //    pair<IMetaDataImport2, IMetaDataImport2>
            //> api_cartridges;
            typedef map<
                pair<TypeNameMetadataGeneratorLabel, TypeNameMetadataGenerator>,
                pair<TypeMetadataLabel, TypeMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultFieldNameMetadataGeneratorApiHolder : 
        Detail::DefaultFieldNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDER_H