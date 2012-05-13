#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPI_H
#define URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPI_H

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultAssemblyMetadataApi
    {        
        typedef IMetaDataImport2 IImport;
        static IID const IID_IImport;
        ATL::CComPtr<IImport> Import;
        typedef IMetaDataAssemblyImport IAssemblyImport;
        static IID const IID_IAssemblyImport;
        ATL::CComPtr<IAssemblyImport> AssemblyImport;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTASSEMBLYMETADATAAPI_H