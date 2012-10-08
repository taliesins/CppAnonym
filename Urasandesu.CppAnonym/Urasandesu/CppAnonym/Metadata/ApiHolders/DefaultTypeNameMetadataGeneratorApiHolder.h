#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H

//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAFWD_HPP
//#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataFwd.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_FIELDNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/FieldNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseFieldNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_PROPERTYNAMEMETADATAGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/PropertyNameMetadataGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEPROPERTYNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BasePropertyNameMetadataGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeNameMetadataGeneratorApiHolderImpl
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
                pair<ModuleNameMetadataGeneratorLabel, ModuleNameMetadataGenerator>, 
                pair<TypeMetadataLabel, TypeMetadata>, 
                pair<FieldNameMetadataGeneratorLabel, FieldNameMetadataGenerator>, 
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>, 
                pair<PropertyNameMetadataGeneratorLabel, PropertyNameMetadataGenerator>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultTypeNameMetadataGeneratorApiHolder : 
        Detail::DefaultTypeNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H