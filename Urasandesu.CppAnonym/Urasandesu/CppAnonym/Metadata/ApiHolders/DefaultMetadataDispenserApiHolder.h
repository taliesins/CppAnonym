#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METHODMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MethodMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataDispenserApiHolderImpl
        {
            typedef map<
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<IAssemblyMetadataHashLabel, IAssemblyMetadataHash>,
                pair<IAssemblyMetadataEqualToLabel, IAssemblyMetadataEqualTo>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<MethodMetadataLabel, MethodMetadata>,
                pair<AssemblyMetadataGenerator7FAEDE99Label, AssemblyMetadataGenerator7FAEDE99>,
                pair<ModuleMetadataGenerator7FAEDE99Label, ModuleMetadataGenerator7FAEDE99>,
                pair<TypeMetadataGenerator7FAEDE99Label, TypeMetadataGenerator7FAEDE99>,
                pair<FieldMetadataGenerator7FAEDE99Label, FieldMetadataGenerator7FAEDE99>,
                pair<MethodMetadataGenerator7FAEDE99Label, MethodMetadataGenerator7FAEDE99>,
                pair<PropertyMetadataGenerator7FAEDE99Label, PropertyMetadataGenerator7FAEDE99>                
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMetadataDispenserApiHolder : 
        Detail::DefaultMetadataDispenserApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H