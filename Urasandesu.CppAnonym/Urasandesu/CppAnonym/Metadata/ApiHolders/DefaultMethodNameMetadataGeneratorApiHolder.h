#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H
#define URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H

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

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ILGENERATORLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ILGeneratorLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEILGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseILGeneratorFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataGeneratorApiHolderFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMethodNameMetadataGeneratorApiHolderImpl
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
                pair<TypeMetadataLabel, TypeMetadata>, 
                pair<ILGeneratorLabel, ILGenerator>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMethodNameMetadataGeneratorApiHolder : 
        Detail::DefaultMethodNameMetadataGeneratorApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H