// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

// Foward Declarations
namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

    struct PEWriterHostApiHolderLabel { };
    struct PEWriterHostLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    struct DefaultPEWriterHostApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class PEWriterHostApiHolder = ApiHolders::DefaultPEWriterHostApiHolder
    >    
    class BasePEWriterHost;

    typedef BasePEWriterHost<> PEWriterHost;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {




namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct IAssemblyNameMetadataApiHolderLabel { };
    struct IAssemblyNameMetadataLabel { };
    struct IAssemblyNameMetadataHashLabel { };
    struct IAssemblyNameMetadataEqualToLabel { };

    struct IAssemblyMetadataApiHolderLabel { };
    struct IAssemblyMetadataLabel { };

    struct IModuleNameMetadataApiHolderLabel { };
    struct IModuleNameMetadataLabel { };
    struct IModuleNameMetadataHashLabel { };
    struct IModuleNameMetadataEqualToLabel { };

    struct IModuleMetadataApiHolderLabel { };
    struct IModuleMetadataLabel { };

    struct ITypeNameMetadataApiHolderLabel { };
    struct ITypeNameMetadataLabel { };
    struct ITypeNameMetadataHashLabel { };
    struct ITypeNameMetadataEqualToLabel { };

    struct ITypeMetadataApiHolderLabel { };
    struct ITypeMetadataLabel { };

    struct IMethodNameMetadataApiHolderLabel { };
    struct IMethodNameMetadataLabel { };
    struct IMethodNameMetadataHashLabel { };
    struct IMethodNameMetadataEqualToLabel { };

    struct IMethodMetadataApiHolderLabel { };
    struct IMethodMetadataLabel { };

    struct IFieldNameMetadataApiHolderLabel { };
    struct IFieldNameMetadataLabel { };
    struct IFieldNameMetadataHashLabel { };
    struct IFieldNameMetadataEqualToLabel { };

    struct IFieldMetadataApiHolderLabel { };
    struct IFieldMetadataLabel { };

    struct IPropertyNameMetadataApiHolderLabel { };
    struct IPropertyNameMetadataLabel { };
    struct IPropertyNameMetadataHashLabel { };
    struct IPropertyNameMetadataEqualToLabel { };

    struct IPropertyMetadataApiHolderLabel { };
    struct IPropertyMetadataLabel { };

    struct ILocalsNameMetadataApiHolderLabel { };
    struct ILocalsNameMetadataLabel { };
    struct ILocalsNameMetadataHashLabel { };
    struct ILocalsNameMetadataEqualToLabel { };

    struct ILocalsMetadataApiHolderLabel { };
    struct ILocalsMetadataLabel { };

    struct AssemblyMetadataGeneratorApiHolderLabel { };
    struct AssemblyMetadataGeneratorLabel { };

    struct ModuleMetadataGeneratorApiHolderLabel { };
    struct ModuleMetadataGeneratorLabel { };

    struct TypeMetadataGeneratorApiHolderLabel { };
    struct TypeMetadataGeneratorLabel { };

    struct FieldMetadataGeneratorApiHolderLabel { };
    struct FieldMetadataGeneratorLabel { };

    struct MethodMetadataGeneratorApiHolderLabel { };
    struct MethodMetadataGeneratorLabel { };

    struct PropertyMetadataGeneratorApiHolderLabel { };
    struct PropertyMetadataGeneratorLabel { };

    struct LocalsNameMetadataGeneratorApiHolderLabel { };
    struct LocalsNameMetadataGeneratorLabel { };

    struct LocalsMetadataGeneratorApiHolderLabel { };
    struct LocalsMetadataGeneratorLabel { };

    //struct InstructionApiHolderLabel { };
    //struct InstructionLabel { };

    struct MetadataSpecialValues
    {
        static std::wstring const TYPE_NAME_OF_VOID;
        static std::wstring const TYPE_NAME_OF_BOOLEAN;
        static std::wstring const TYPE_NAME_OF_CHAR;
        static std::wstring const TYPE_NAME_OF_SBYTE;
        static std::wstring const TYPE_NAME_OF_BYTE;
        static std::wstring const TYPE_NAME_OF_INT16;
        static std::wstring const TYPE_NAME_OF_UINT16;
        static std::wstring const TYPE_NAME_OF_INT32;
        static std::wstring const TYPE_NAME_OF_UINT32;
        static std::wstring const TYPE_NAME_OF_INT64;
        static std::wstring const TYPE_NAME_OF_UINT64;
        static std::wstring const TYPE_NAME_OF_SINGLE;
        static std::wstring const TYPE_NAME_OF_DOUBLE;
        static std::wstring const TYPE_NAME_OF_STRING;
        static std::wstring const TYPE_NAME_OF_INTPTR;
        static std::wstring const TYPE_NAME_OF_OBJECT;
        static std::wstring const TYPE_NAME_OF_VALUETYPE;
        static std::wstring const GENERIC_TYPE_IDENTIFIER;
    };

    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_VOID = L"System.Void";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_BOOLEAN = L"System.Boolean";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_CHAR = L"System.Char";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_SBYTE = L"System.SByte";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_BYTE = L"System.Byte";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT16 = L"System.Int16";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT16 = L"System.UInt16";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT32 = L"System.Int32";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT32 = L"System.UInt32";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT64 = L"System.Int64";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT64 = L"System.UInt64";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_SINGLE = L"System.Single";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_DOUBLE = L"System.Double";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_STRING = L"System.String";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INTPTR = L"System.IntPtr";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_OBJECT = L"System.Object";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_VALUETYPE = L"System.ValueType";
    std::wstring const MetadataSpecialValues::GENERIC_TYPE_IDENTIFIER = L"`";

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultIAssemblyNameMetadataApiHolder;

    struct DefaultIAssemblyMetadataApiHolder;

    struct DefaultIModuleMetadataApiHolder;

    struct DefaultIModuleNameMetadataApiHolder;

    struct DefaultITypeMetadataApiHolder;

    struct DefaultITypeNameMetadataApiHolder;

    struct DefaultIMethodNameMetadataApiHolder;

    struct DefaultIMethodMetadataApiHolder;

    struct DefaultIFieldNameMetadataApiHolder;

    struct DefaultIFieldMetadataApiHolder;

    struct DefaultIPropertyNameMetadataApiHolder;

    struct DefaultIPropertyMetadataApiHolder;

    struct DefaultILocalsNameMetadataApiHolder;

    struct DefaultILocalsMetadataApiHolder;

    struct DefaultAssemblyMetadataGeneratorApiHolder;

    struct DefaultModuleMetadataGeneratorApiHolder;

    struct DefaultTypeMetadataGeneratorApiHolder;

    struct DefaultFieldMetadataGeneratorApiHolder;

    struct DefaultMethodMetadataGeneratorApiHolder;

    struct DefaultPropertyMetadataGeneratorApiHolder;

    struct DefaultLocalsNameMetadataGeneratorApiHolder;

    struct DefaultLocalsMetadataGeneratorApiHolder;

    //struct DefaultInstructionApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class IAssemblyNameMetadataApiHolder = ApiHolders::DefaultIAssemblyNameMetadataApiHolder
    >    
    class BaseIAssemblyNameMetadata;

    typedef BaseIAssemblyNameMetadata<> IAssemblyNameMetadata;




    
    template<
        class IAssemblyNameMetadataApiHolder = ApiHolders::DefaultIAssemblyNameMetadataApiHolder
    >    
    class BaseIAssemblyNameMetadataHash;

    typedef BaseIAssemblyNameMetadataHash<> IAssemblyNameMetadataHash;

    
    
    
    
    template<
        class IAssemblyNameMetadataApiHolder = ApiHolders::DefaultIAssemblyNameMetadataApiHolder
    >    
    class BaseIAssemblyNameMetadataEqualTo;

    typedef BaseIAssemblyNameMetadataEqualTo<> IAssemblyNameMetadataEqualTo;
    
    
    
    
    
    template<
        class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadata;

    typedef BaseIAssemblyMetadata<> IAssemblyMetadata;






    template<
        class IModuleNameMetadataApiHolder = ApiHolders::DefaultIModuleNameMetadataApiHolder
    >    
    class BaseIModuleNameMetadata;

    typedef BaseIModuleNameMetadata<> IModuleNameMetadata;




    
    template<
        class IModuleNameMetadataApiHolder = ApiHolders::DefaultIModuleNameMetadataApiHolder
    >    
    class BaseIModuleNameMetadataHash;

    typedef BaseIModuleNameMetadataHash<> IModuleNameMetadataHash;

    
    
    
    
    template<
        class IModuleNameMetadataApiHolder = ApiHolders::DefaultIModuleNameMetadataApiHolder
    >    
    class BaseIModuleNameMetadataEqualTo;

    typedef BaseIModuleNameMetadataEqualTo<> IModuleNameMetadataEqualTo;






    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata;

    typedef BaseIModuleMetadata<> IModuleMetadata;





    template<
        class ITypeNameMetadataApiHolder = ApiHolders::DefaultITypeNameMetadataApiHolder
    >    
    class BaseITypeNameMetadata;

    typedef BaseITypeNameMetadata<> ITypeNameMetadata;





    template<
        class ITypeNameMetadataApiHolder = ApiHolders::DefaultITypeNameMetadataApiHolder
    >    
    class BaseITypeNameMetadataHash;

    typedef BaseITypeNameMetadataHash<> ITypeNameMetadataHash;

    
    
    
    
    template<
        class ITypeNameMetadataApiHolder = ApiHolders::DefaultITypeNameMetadataApiHolder
    >    
    class BaseITypeNameMetadataEqualTo;

    typedef BaseITypeNameMetadataEqualTo<> ITypeNameMetadataEqualTo;






    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadata;

    typedef BaseITypeMetadata<> ITypeMetadata;





    template<
        class IMethodNameMetadataApiHolder = ApiHolders::DefaultIMethodNameMetadataApiHolder
    >    
    class BaseIMethodNameMetadata;

    typedef BaseIMethodNameMetadata<> IMethodNameMetadata;

    
    
    
    
    template<
        class IMethodNameMetadataApiHolder = ApiHolders::DefaultIMethodNameMetadataApiHolder
    >    
    struct BaseIMethodNameMetadataHash;

    typedef BaseIMethodNameMetadataHash<> IMethodNameMetadataHash;

    
    
    
    
    template<
        class IMethodNameMetadataApiHolder = ApiHolders::DefaultIMethodNameMetadataApiHolder
    >    
    struct BaseIMethodNameMetadataEqualTo;

    typedef BaseIMethodNameMetadataEqualTo<> IMethodNameMetadataEqualTo;






    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadata;

    typedef BaseIMethodMetadata<> IMethodMetadata;





    template<
        class IFieldNameMetadataApiHolder = ApiHolders::DefaultIFieldNameMetadataApiHolder
    >    
    class BaseIFieldNameMetadata;

    typedef BaseIFieldNameMetadata<> IFieldNameMetadata;

    
    
    
    
    template<
        class IFieldNameMetadataApiHolder = ApiHolders::DefaultIFieldNameMetadataApiHolder
    >    
    struct BaseIFieldNameMetadataHash;

    typedef BaseIFieldNameMetadataHash<> IFieldNameMetadataHash;

    
    
    
    
    template<
        class IFieldNameMetadataApiHolder = ApiHolders::DefaultIFieldNameMetadataApiHolder
    >    
    struct BaseIFieldNameMetadataEqualTo;

    typedef BaseIFieldNameMetadataEqualTo<> IFieldNameMetadataEqualTo;






    template<
        class IFieldMetadataApiHolder = ApiHolders::DefaultIFieldMetadataApiHolder
    >    
    class BaseIFieldMetadata;

    typedef BaseIFieldMetadata<> IFieldMetadata;





    template<
        class IPropertyNameMetadataApiHolder = ApiHolders::DefaultIPropertyNameMetadataApiHolder
    >    
    class BaseIPropertyNameMetadata;

    typedef BaseIPropertyNameMetadata<> IPropertyNameMetadata;

    
    
    
    
    template<
        class IPropertyNameMetadataApiHolder = ApiHolders::DefaultIPropertyNameMetadataApiHolder
    >    
    struct BaseIPropertyNameMetadataHash;

    typedef BaseIPropertyNameMetadataHash<> IPropertyNameMetadataHash;

    
    
    
    
    template<
        class IPropertyNameMetadataApiHolder = ApiHolders::DefaultIPropertyNameMetadataApiHolder
    >    
    struct BaseIPropertyNameMetadataEqualTo;

    typedef BaseIPropertyNameMetadataEqualTo<> IPropertyNameMetadataEqualTo;






    template<
        class IPropertyMetadataApiHolder = ApiHolders::DefaultIPropertyMetadataApiHolder
    >    
    class BaseIPropertyMetadata;

    typedef BaseIPropertyMetadata<> IPropertyMetadata;





    template<
        class ILocalsNameMetadataApiHolder = ApiHolders::DefaultILocalsNameMetadataApiHolder
    >    
    class BaseILocalsNameMetadata;

    typedef BaseILocalsNameMetadata<> ILocalsNameMetadata;

    
    
    
    
    template<
        class ILocalsNameMetadataApiHolder = ApiHolders::DefaultILocalsNameMetadataApiHolder
    >    
    struct BaseILocalsNameMetadataHash;

    typedef BaseILocalsNameMetadataHash<> ILocalsNameMetadataHash;

    
    
    
    
    template<
        class ILocalsNameMetadataApiHolder = ApiHolders::DefaultILocalsNameMetadataApiHolder
    >    
    struct BaseILocalsNameMetadataEqualTo;

    typedef BaseILocalsNameMetadataEqualTo<> ILocalsNameMetadataEqualTo;






    template<
        class ILocalsMetadataApiHolder = ApiHolders::DefaultILocalsMetadataApiHolder
    >    
    class BaseILocalsMetadata;

    typedef BaseILocalsMetadata<> ILocalsMetadata;





    template<
        class AssemblyMetadataGeneratorApiHolder = ApiHolders::DefaultAssemblyMetadataGeneratorApiHolder
    >    
    class BaseAssemblyMetadataGenerator;

    typedef BaseAssemblyMetadataGenerator<> AssemblyMetadataGenerator;





    template<
        class ModuleMetadataGeneratorApiHolder = ApiHolders::DefaultModuleMetadataGeneratorApiHolder
    >    
    class BaseModuleMetadataGenerator;

    typedef BaseModuleMetadataGenerator<> ModuleMetadataGenerator;





    template<
        class TypeMetadataGeneratorApiHolder = ApiHolders::DefaultTypeMetadataGeneratorApiHolder
    >    
    class BaseTypeMetadataGenerator;

    typedef BaseTypeMetadataGenerator<> TypeMetadataGenerator;





    template<
        class FieldMetadataGeneratorApiHolder = ApiHolders::DefaultFieldMetadataGeneratorApiHolder
    >    
    class BaseFieldMetadataGenerator;

    typedef BaseFieldMetadataGenerator<> FieldMetadataGenerator;





    template<
        class MethodMetadataGeneratorApiHolder = ApiHolders::DefaultMethodMetadataGeneratorApiHolder
    >    
    class BaseMethodMetadataGenerator;

    typedef BaseMethodMetadataGenerator<> MethodMetadataGenerator;





    template<
        class PropertyMetadataGeneratorApiHolder = ApiHolders::DefaultPropertyMetadataGeneratorApiHolder
    >    
    class BasePropertyMetadataGenerator;

    typedef BasePropertyMetadataGenerator<> PropertyMetadataGenerator;





    template<
        class LocalsNameMetadataGeneratorApiHolder = ApiHolders::DefaultLocalsNameMetadataGeneratorApiHolder
    >    
    class BaseLocalsNameMetadataGenerator;

    typedef BaseLocalsNameMetadataGenerator<> LocalsNameMetadataGenerator;





    template<
        class LocalsMetadataGeneratorApiHolder = ApiHolders::DefaultLocalsMetadataGeneratorApiHolder
    >    
    class BaseLocalsMetadataGenerator;

    typedef BaseLocalsMetadataGenerator<> LocalsMetadataGenerator;





    //template<
    //    class InstructionApiHolder = ApiHolders::DefaultInstructionApiHolder
    //>    
    //class BaseInstruction;

    //typedef BaseInstruction<> Instruction;





    typedef enum CorTokenTypeEx
    {
        // mdtBaseType(0x72000000) を下駄履き。
    } CorTokenTypeEx;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {


#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPI_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHost.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTFIELDNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultFieldNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEFIELDNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseFieldNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPENAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPENAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODBODYWRITERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodBodyWriterApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODBODYWRITER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodBodyWriter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULENAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTPROPERTYNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultPropertyNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEPROPERTYNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BasePropertyNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTLOCALNAMEMETADATAGENERATORAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultLocalNameMetadataGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASELOCALNAMEMETADATAGENERATOR_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseLocalNameMetadataGenerator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTINSTRUCTIONAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultInstructionApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEINSTRUCTION_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseInstruction.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultPEWriterHostApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<AssemblyMetadataGeneratorLabel, AssemblyMetadataGenerator>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultPEWriterHostApiHolder : 
        Detail::DefaultPEWriterHostApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct PEWriterHostApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::PEWriterHostApiHolderLabel, ApiLabel>
    {
    };

    template<
        class PEWriterHostApiHolder
    >    
    class BasePEWriterHost
    {
    public:
        typedef BasePEWriterHost<PEWriterHostApiHolder> this_type;

        typedef typename PEWriterHostApiAt<PEWriterHostApiHolder, Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename PEWriterHostApiAt<PEWriterHostApiHolder, Metadata::Interfaces::AssemblyMetadataGeneratorLabel>::type assembly_metadata_generator_type;

        BasePEWriterHost() : 
            m_pRuntimeHostAsScope(NULL),
            m_portableExecutableKind(PortableExecutableKinds::PEK_IL_ONLY),
            m_imageFileMachine(ImageFileMachine::IFM_I386)
        { }

        void Save(assembly_metadata_generator_type const &asmGen)
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            // Pre Processing ...
        //// Generate the PE format file with using ICeeFileGen
            // ↓ここは遅延評価の Property 化。hmodCorPE を取得できるような形ね。****************************************************************
        //path msCorPEPath(corSystemDirectoryPath);
        //msCorPEPath /= L"mscorpe.dll";
        //HMODULE hmodCorPE = ::LoadLibraryW(msCorPEPath.c_str());
        //if (!hmodCorPE)
        //    BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        //BOOST_SCOPE_EXIT((hmodCorPE))
        //{
        //    ::FreeLibrary(hmodCorPE);
        //}
        //BOOST_SCOPE_EXIT_END

        //{
            // ↓pfnCreateCeeFileGen も遅延評価の Property 化できるね。****************************************************************
        //    // Extract the creating/destroying methods for ICeeFileGen.
        //    typedef HRESULT (__stdcall *CreateCeeFileGenPtr)(ICeeFileGen **ceeFileGen);
        //    typedef HRESULT (__stdcall *DestroyCeeFileGenPtr)(ICeeFileGen **ceeFileGen);
        //    
        //    CreateCeeFileGenPtr pfnCreateCeeFileGen = NULL;
        //    DestroyCeeFileGenPtr pfnDestroyCeeFileGen = NULL;

        //    pfnCreateCeeFileGen = reinterpret_cast<CreateCeeFileGenPtr>(
        //                                    ::GetProcAddress(hmodCorPE, "CreateICeeFileGen"));
        //    if (!pfnCreateCeeFileGen)
        //        BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        //    
            // ↓pfnDestroyCeeFileGen もね。    ****************************************************************
        //    pfnDestroyCeeFileGen = reinterpret_cast<DestroyCeeFileGenPtr>(
        //                                   ::GetProcAddress(hmodCorPE, "DestroyICeeFileGen"));
        //    if (!pfnDestroyCeeFileGen)
        //        BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));

            // ↓pCeeFileGen もね。destructor での解放順番に注意！！pCeeFileGen -> hmodCorPE になるように！****************************************************************
        //    ICeeFileGen* pCeeFileGen = NULL;
        //    hr = pfnCreateCeeFileGen(&pCeeFileGen);
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        //    BOOST_SCOPE_EXIT((pCeeFileGen)(pfnDestroyCeeFileGen))
        //    {
        //        pfnDestroyCeeFileGen(&pCeeFileGen);
        //    }
        //    BOOST_SCOPE_EXIT_END

        //    
        //    
            // ↓ceeFile も Property 化できるね。やはり解放順番に注意が必要ね。ceeFile -> pCeeFileGen -> hmodCorPE
        //    // Prepare to generate the PE format file.
        //    HCEEFILE ceeFile = NULL;
        //    hr = pCeeFileGen->CreateCeeFileEx(&ceeFile, ICEE_CREATE_FILE_PURE_IL);
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        //    BOOST_SCOPE_EXIT((ceeFile)(pCeeFileGen))
        //    {
        //        pCeeFileGen->DestroyCeeFile(&ceeFile);
        //    }
        //    BOOST_SCOPE_EXIT_END
        //    
            // ↓SetName で設定された名前を使うべし。
        //    hr = pCeeFileGen->SetOutputFileName(ceeFile, moduleNameOfMSCorLibPrig);
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        //    
            // ↓SetPortableExecutableKind & SetImageFileMachine で設定された情報から計算すべし・・・。
            //   若干、COMIMAGE_FLAGS_STRONGNAMESIGNED のために asmGen へのアクセスが必要か。
        //    hr = pCeeFileGen->SetComImageFlags(ceeFile, 
        //                         COMIMAGE_FLAGS_ILONLY | COMIMAGE_FLAGS_STRONGNAMESIGNED);
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        //    
            // ↓これどうやって計算するんだっけ？？
            //   →本当は外から設定しないとだめぽ。とりあえずは IMAGE_SUBSYSTEM_WINDOWS_CUI あるね。
        //    hr = pCeeFileGen->SetSubsystem(ceeFile, IMAGE_SUBSYSTEM_WINDOWS_CUI, 4, 0);
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            asmGen.SaveTo(*pMutableThis);

            // Post Processing ...
            //// Sign to the assembly with Strong Naming API.
            //if (!::StrongNameSignatureGenerationEx(moduleNameOfMSCorLibPrig, NULL, 
            //                        pMSCorLibPrigKeyPair.get(), msCorLibPrigKeyPairSize, 
            //                        NULL, NULL, 0))
            //    BOOST_THROW_EXCEPTION(CppAnonymCOMException(::StrongNameErrorInfo()));
        }

        ULONG WriteMethodBody(COR_ILMETHOD_FAT const &rawHeader, SimpleBlob const &rawBody)
        {
            // ↓PortableExecutableFile へ。※fatHeader の計算結果は外から渡す。"C:\Users\Akira\Documents\自己学習\120303\[Metadata API] 生成系とか 6.hpp" のメモも参照のこと。
            // INPUT: mbNowGetInitializeget_Body: SimpleBlob, mdsNowGetInitializeget_BodyLocals: , 
            //    // System.Prig.PDateTime.NowGet.Initializeget_Body method has Fat format header.
            //    // Note that SetLocalVarSigTok is called with StandAloneSig for local variables, 
            //    // and GetSectionBlock is called with setting to DWORD size alignment.
            //    COR_ILMETHOD_FAT fatHeader;
            //    ::ZeroMemory(&fatHeader, sizeof(COR_ILMETHOD_FAT));
            //    fatHeader.SetMaxStack(1);
            //    fatHeader.SetCodeSize(mbNowGetInitializeget_Body.Size());
            //    fatHeader.SetLocalVarSigTok(mdsNowGetInitializeget_BodyLocals);
            //    fatHeader.SetFlags(CorILMethod_InitLocals);
            //    
            //    unsigned headerSize = COR_ILMETHOD::Size(&fatHeader, false);
            //    unsigned totalSize = headerSize + mbNowGetInitializeget_Body.Size();

            //    BYTE *pBuffer = NULL;
            //    hr = pCeeFileGen->GetSectionBlock(textSection, totalSize, sizeof(DWORD), 
            //                                      reinterpret_cast<void**>(&pBuffer));
            //    if (FAILED(hr))
            //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //    ULONG offset = 0;
            //    hr = pCeeFileGen->GetSectionDataLen(textSection, &offset);
            //    if (FAILED(hr))
            //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //    offset -= totalSize;
            //    ULONG codeRVA = 0;
            //    hr = pCeeFileGen->GetMethodRVA(ceeFile, offset, &codeRVA);
            //    if (FAILED(hr))
            //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //    pBuffer += COR_ILMETHOD::Emit(headerSize, &fatHeader, false, pBuffer);
            //    ::memcpy_s(pBuffer, totalSize - headerSize, mbNowGetInitializeget_Body.Ptr(), 
            //               mbNowGetInitializeget_Body.Size());
            //    
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

    private:
        friend typename runtime_host_type;

        void Init(runtime_host_type &runtimeHostAsScope) const
        {
            _ASSERTE(m_pRuntimeHostAsScope == NULL);
            m_pRuntimeHostAsScope = &runtimeHostAsScope;
        }

        void SetName(std::wstring const &name)
        {
            m_name = name;
        }

        void SetPortableExecutableKind(PortableExecutableKinds const &portableExecutableKind)
        {
            m_portableExecutableKind = portableExecutableKind;
        }

        void SetImageFileMachine(ImageFileMachine const &imageFileMachine)
        {
            m_imageFileMachine = imageFileMachine;
        }

        mutable runtime_host_type *m_pRuntimeHostAsScope;
        std::wstring m_name;
        PortableExecutableKinds m_portableExecutableKind;
        ImageFileMachine m_imageFileMachine;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {




namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::StrongNaming;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;

        struct DefaultIAssemblyNameMetadataApiHolderImpl
        {
            typedef map<
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<StrongNameKeyLabel, StrongNameKey>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIAssemblyNameMetadataApiHolder : 
        Detail::DefaultIAssemblyNameMetadataApiHolderImpl
    {
    };
    
    
    
    
    
    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<IAssemblyNameMetadataLabel, IAssemblyNameMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIAssemblyMetadataApiHolder : 
        Detail::DefaultIAssemblyMetadataApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIModuleNameMetadataApiHolderImpl
        {
            typedef map<
                pair<IAssemblyNameMetadataLabel, IAssemblyNameMetadata>,
                pair<IAssemblyNameMetadataHashLabel, IAssemblyNameMetadataHash>,
                pair<IAssemblyNameMetadataEqualToLabel, IAssemblyNameMetadataEqualTo>,
                pair<IModuleMetadataLabel, IModuleMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIModuleNameMetadataApiHolder : 
        Detail::DefaultIModuleNameMetadataApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIModuleMetadataApiHolderImpl
        {
            typedef map<
                pair<IModuleNameMetadataLabel, IModuleNameMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIModuleMetadataApiHolder : 
        Detail::DefaultIModuleMetadataApiHolderImpl
    {
    };







    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultITypeNameMetadataApiHolderImpl
        {
            typedef map<
                pair<IModuleNameMetadataLabel, IModuleNameMetadata>,
                pair<IModuleNameMetadataHashLabel, IModuleNameMetadataHash>,
                pair<IModuleNameMetadataEqualToLabel, IModuleNameMetadataEqualTo>,
                pair<ITypeMetadataLabel, ITypeMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultITypeNameMetadataApiHolder : 
        Detail::DefaultITypeNameMetadataApiHolderImpl
    {
    };






    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultITypeMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultITypeMetadataApiHolder :
        Detail::DefaultITypeMetadataApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIMethodNameMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<ITypeNameMetadataHashLabel, ITypeNameMetadataHash>,
                pair<ITypeNameMetadataEqualToLabel, ITypeNameMetadataEqualTo>,
                pair<IMethodMetadataLabel, IMethodMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIMethodNameMetadataApiHolder : 
        Detail::DefaultIMethodNameMetadataApiHolderImpl 
    {
    };






    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIMethodMetadataApiHolderImpl
        {
            typedef map<
                pair<IMethodNameMetadataLabel, IMethodNameMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIMethodMetadataApiHolder : 
        Detail::DefaultIMethodMetadataApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIFieldNameMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<ITypeNameMetadataHashLabel, ITypeNameMetadataHash>,
                pair<ITypeNameMetadataEqualToLabel, ITypeNameMetadataEqualTo>,
                pair<IFieldMetadataLabel, IFieldMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIFieldNameMetadataApiHolder : 
        Detail::DefaultIFieldNameMetadataApiHolderImpl
    {
    };






    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIFieldMetadataApiHolderImpl
        {
            typedef map<
                pair<IFieldNameMetadataLabel, IFieldNameMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIFieldMetadataApiHolder : 
        Detail::DefaultIFieldMetadataApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIPropertyNameMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<ITypeNameMetadataHashLabel, ITypeNameMetadataHash>,
                pair<ITypeNameMetadataEqualToLabel, ITypeNameMetadataEqualTo>,
                pair<IPropertyMetadataLabel, IPropertyMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIPropertyNameMetadataApiHolder : 
        Detail::DefaultIPropertyNameMetadataApiHolderImpl
    {
    };






    //namespace Detail {

    //    using namespace boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

    //    struct DefaultIMethodMetadataApiHolderImpl
    //    {
    //        typedef map<
    //            pair<IMethodNameMetadataLabel, IMethodNameMetadata>
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultIPropertyMetadataApiHolder
    {
    };





    //namespace Detail {

    //    using namespace boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

    //    struct DefaultILocalsNameMetadataApiHolderImpl
    //    {
    //        typedef map<
    //            pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
    //            pair<ITypeNameMetadataHashLabel, ITypeNameMetadataHash>,
    //            pair<ITypeNameMetadataEqualToLabel, ITypeNameMetadataEqualTo>,
    //            pair<IMethodMetadataLabel, IMethodMetadata>
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultILocalsNameMetadataApiHolder
    {
    };






    //namespace Detail {

    //    using namespace boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

    //    struct DefaultILocalsMetadataApiHolderImpl
    //    {
    //        typedef map<
    //            pair<IMethodNameMetadataLabel, IMethodNameMetadata>
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultILocalsMetadataApiHolder
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultAssemblyMetadataGeneratorApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyNameMetadataGeneratorLabel, AssemblyNameMetadataGenerator>,
                pair<MetadataInfoLabel, MetadataInfo>,
                pair<ModuleMetadataGeneratorLabel, ModuleMetadataGenerator>,
                pair<ModuleNameMetadataGeneratorLabel, ModuleNameMetadataGenerator>,
                pair<IModuleNameMetadataHashLabel, IModuleNameMetadataHash>, 
                pair<IModuleNameMetadataEqualToLabel, IModuleNameMetadataEqualTo>, 
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<PEWriterHostLabel, PEWriterHost> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyMetadataGeneratorApiHolder : 
        Detail::DefaultAssemblyMetadataGeneratorApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultModuleMetadataGeneratorApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<AssemblyMetadataGeneratorLabel, AssemblyMetadataGenerator>,
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<ModuleNameMetadataGeneratorLabel, ModuleNameMetadataGenerator>,
                pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>,
                pair<TypeNameMetadataGeneratorLabel, TypeNameMetadataGenerator>,
                pair<ITypeNameMetadataHashLabel, ITypeNameMetadataHash>,
                pair<ITypeNameMetadataEqualToLabel, ITypeNameMetadataEqualTo>,
                pair<PEWriterHostLabel, PEWriterHost> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultModuleMetadataGeneratorApiHolder : 
        Detail::DefaultModuleMetadataGeneratorApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeMetadataGeneratorApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<ModuleMetadataGeneratorLabel, ModuleMetadataGenerator>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<TypeNameMetadataGeneratorLabel, TypeNameMetadataGenerator>,
                pair<FieldNameMetadataGeneratorLabel, FieldNameMetadataGenerator>,
                pair<IFieldNameMetadataHashLabel, IFieldNameMetadataHash>,
                pair<IFieldNameMetadataEqualToLabel, IFieldNameMetadataEqualTo>,
                pair<FieldMetadataGeneratorLabel, FieldMetadataGenerator>,
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>,
                pair<IMethodNameMetadataHashLabel, IMethodNameMetadataHash>,
                pair<IMethodNameMetadataEqualToLabel, IMethodNameMetadataEqualTo>,
                pair<MethodMetadataGeneratorLabel, MethodMetadataGenerator>,
                pair<PropertyNameMetadataGeneratorLabel, PropertyNameMetadataGenerator>,
                pair<IPropertyNameMetadataHashLabel, IPropertyNameMetadataHash>,
                pair<IPropertyNameMetadataEqualToLabel, IPropertyNameMetadataEqualTo>,
                pair<PropertyMetadataGeneratorLabel, PropertyMetadataGenerator>,
                pair<PEWriterHostLabel, PEWriterHost> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultTypeMetadataGeneratorApiHolder : 
        Detail::DefaultTypeMetadataGeneratorApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultFieldMetadataGeneratorApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>,
                pair<FieldNameMetadataGeneratorLabel, FieldNameMetadataGenerator>,
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<IFieldMetadataLabel, IFieldMetadata>,
                pair<PEWriterHostLabel, PEWriterHost> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultFieldMetadataGeneratorApiHolder : 
        Detail::DefaultFieldMetadataGeneratorApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMethodMetadataGeneratorApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>,
                pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>,
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<PEWriterHostLabel, PEWriterHost> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMethodMetadataGeneratorApiHolder : 
        Detail::DefaultMethodMetadataGeneratorApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultPropertyMetadataGeneratorApiHolderImpl
        {
            typedef map<
                //pair<MetadataDispenserLabel, MetadataDispenser>, 
                //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
                //pair<ModuleMetadataLabel, ModuleMetadata>, 
                //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
                //pair<TypeMetadataLabel, TypeMetadata>, 
                //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
                //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
                //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
                //pair<IMetaDataImport2, IMetaDataImport2>
                pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>,
                pair<PropertyNameMetadataGeneratorLabel, PropertyNameMetadataGenerator>,
                pair<IPropertyMetadataLabel, IPropertyMetadata>,
                pair<PEWriterHostLabel, PEWriterHost> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultPropertyMetadataGeneratorApiHolder : 
        Detail::DefaultPropertyMetadataGeneratorApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultLocalsNameMetadataGeneratorApiHolderImpl
        {
            typedef map<
                pair<MethodBodyWriterLabel, MethodBodyWriter>,
                pair<ITypeNameMetadataLabel, ITypeNameMetadata>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<LocalNameMetadataGeneratorLabel, LocalNameMetadataGenerator>,
                pair<LocalsMetadataGeneratorLabel, LocalsMetadataGenerator>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultLocalsNameMetadataGeneratorApiHolder : 
        Detail::DefaultLocalsNameMetadataGeneratorApiHolderImpl
    {
    };





    //namespace Detail {

    //    using namespace boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Hosting;
    //    using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
    //    using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

    //    struct DefaultLocalsMetadataGeneratorApiHolderImpl
    //    {
    //        typedef map<
    //            //pair<MetadataDispenserLabel, MetadataDispenser>, 
    //            //pair<AssemblyNameMetadataLabel, AssemblyNameMetadata>,
    //            //pair<ModuleMetadataLabel, ModuleMetadata>, 
    //            //pair<ModuleNameMetadataLabel, ModuleNameMetadata>, 
    //            //pair<TypeMetadataLabel, TypeMetadata>, 
    //            //pair<TypeNameMetadataLabel, TypeNameMetadata>, 
    //            //pair<IMetaDataDispenserEx, IMetaDataDispenserEx>, 
    //            //pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>, 
    //            //pair<IMetaDataImport2, IMetaDataImport2>
    //            pair<TypeMetadataGeneratorLabel, TypeMetadataGenerator>,
    //            pair<MethodNameMetadataGeneratorLabel, MethodNameMetadataGenerator>,
    //            pair<ILocalsMetadataLabel, ILocalsMetadata>,
    //            pair<PEWriterHostLabel, PEWriterHost> 
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultLocalsMetadataGeneratorApiHolder
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IAssemblyNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IAssemblyNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IAssemblyNameMetadataApiHolder
    >    
    class BaseIAssemblyNameMetadata
    {
    public:
        typedef BaseIAssemblyNameMetadata<IAssemblyNameMetadataApiHolder> this_type;

        typedef typename IAssemblyNameMetadataApiAt<IAssemblyNameMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;
        typedef typename IAssemblyNameMetadataApiAt<IAssemblyNameMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename IAssemblyNameMetadataApiAt<IAssemblyNameMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

        virtual std::wstring const &GetName() const = 0;
        virtual strong_name_key_type const *GetStrongNameKey() const = 0;
        virtual metadata_dispenser_type const &GetResolutionScope() const = 0;
        virtual i_assembly_metadata_type const &Resolve() const = 0;
    };




    
    template<
        class IAssemblyNameMetadataApiHolder
    >    
    class BaseIAssemblyNameMetadataHash : 
        Traits::HashComputable<BaseIAssemblyNameMetadata<IAssemblyNameMetadataApiHolder> const *>
    {
    public:
        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, HashValue(&v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IAssemblyNameMetadataApiHolder
    >    
    class BaseIAssemblyNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseIAssemblyNameMetadata<IAssemblyNameMetadataApiHolder> const *>
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                    &x->GetResolutionScope() == &y->GetResolutionScope();
        }
    };
    
    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct IAssemblyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IAssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IAssemblyMetadataApiHolder
    >    
    class BaseIAssemblyMetadata
    {
    public:
        typedef BaseIAssemblyMetadata<IAssemblyMetadataApiHolder> this_type;
        
        typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyNameMetadataLabel>::type i_assembly_name_metadata_type;

        virtual mdAssembly GetToken() const = 0;
        virtual i_assembly_name_metadata_type const &GetAssemblyName() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IModuleNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IModuleNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IModuleNameMetadataApiHolder
    >    
    class BaseIModuleNameMetadata
    {
    public:
        typedef BaseIModuleNameMetadata<IModuleNameMetadataApiHolder> this_type;

        typedef typename IModuleNameMetadataApiAt<IModuleNameMetadataApiHolder, Interfaces::IAssemblyNameMetadataLabel>::type i_assembly_name_metadata_type;
        typedef typename IModuleNameMetadataApiAt<IModuleNameMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type i_module_metadata_type;

        virtual std::wstring const &GetName() const = 0;
        virtual i_assembly_name_metadata_type const &GetResolutionScope() const = 0;
        virtual i_module_metadata_type const &Resolve() const = 0;
    };




    
    template<
        class IModuleNameMetadataApiHolder
    >    
    class BaseIModuleNameMetadataHash : 
        Traits::HashComputable<BaseIModuleNameMetadata<IModuleNameMetadataApiHolder> const *>
    {
    public:
        typedef typename IModuleNameMetadataApiAt<IModuleNameMetadataApiHolder, Interfaces::IAssemblyNameMetadataHashLabel>::type i_assembly_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_assembly_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IModuleNameMetadataApiHolder
    >    
    class BaseIModuleNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseIModuleNameMetadata<IModuleNameMetadataApiHolder> const *>
    {
    public:
        typedef typename IModuleNameMetadataApiAt<IModuleNameMetadataApiHolder, Interfaces::IAssemblyNameMetadataEqualToLabel>::type i_assembly_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   i_assembly_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IModuleMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IModuleMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata
    {
    public:
        typedef BaseIModuleMetadata<IModuleMetadataApiHolder> this_type;

        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleNameMetadataLabel>::type i_module_name_metadata_type;

        virtual mdModule GetToken() const = 0;
        virtual i_module_name_metadata_type const &GetModuleName() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ITypeNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ITypeNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ITypeNameMetadataApiHolder
    >    
    class BaseITypeNameMetadata
    {
    public:
        typedef BaseITypeNameMetadata<ITypeNameMetadataApiHolder> this_type;

        typedef typename ITypeNameMetadataApiAt<ITypeNameMetadataApiHolder, Interfaces::IModuleNameMetadataLabel>::type i_module_name_metadata_type;
        typedef typename ITypeNameMetadataApiAt<ITypeNameMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;        

        virtual std::wstring const &GetName() const = 0;
        virtual this_type const *GetBaseTypeName() const = 0;
        virtual i_module_name_metadata_type const &GetResolutionScope() const = 0;
        virtual i_type_metadata_type const &Resolve() const = 0;
        virtual std::vector<COR_SIGNATURE> const &GetSignatures() const = 0;
    };





    template<
        class ITypeNameMetadataApiHolder
    >    
    class BaseITypeNameMetadataHash : 
        Traits::HashComputable<BaseITypeNameMetadata<ITypeNameMetadataApiHolder> const *>
    {
    public:
        typedef typename ITypeNameMetadataApiAt<ITypeNameMetadataApiHolder, Interfaces::IModuleNameMetadataHashLabel>::type i_module_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_module_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class ITypeNameMetadataApiHolder
    >    
    class BaseITypeNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseITypeNameMetadata<ITypeNameMetadataApiHolder> const *>
    {
    public:
        typedef typename ITypeNameMetadataApiAt<ITypeNameMetadataApiHolder, Interfaces::IModuleNameMetadataEqualToLabel>::type i_module_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   i_module_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };






    template<class ApiCartridgesHolder, class ApiLabel>
    struct ITypeMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ITypeMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadata
    {
    public:
        typedef BaseITypeMetadata<ITypeMetadataApiHolder> this_type;

        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual i_type_name_metadata_type const &GetTypeName() const = 0;
        virtual this_type const *GetBaseType() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IMethodNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IMethodNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IMethodNameMetadataApiHolder
    >    
    class BaseIMethodNameMetadata
    {
    public:
        typedef BaseIMethodNameMetadata<IMethodNameMetadataApiHolder> this_type;

        typedef typename IMethodNameMetadataApiAt<IMethodNameMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        typedef typename IMethodNameMetadataApiAt<IMethodNameMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type i_method_metadata_type;

        virtual std::wstring const &GetName() const = 0;
        virtual CallingConventions const &GetCallingConvention() const = 0;
        virtual i_type_name_metadata_type const &GetReturnTypeName() const = 0;
        virtual std::vector<i_type_name_metadata_type const *> const &GetParameterTypeNames() const = 0;
        virtual i_type_name_metadata_type const &GetResolutionScope() const = 0;
        virtual i_method_metadata_type const &Resolve() const = 0;
    };

    
    
    

    template<
        class IMethodNameMetadataApiHolder
    >    
    struct BaseIMethodNameMetadataHash : 
        Traits::HashComputable<BaseIMethodNameMetadata<IMethodNameMetadataApiHolder> const *>
    {
        typedef typename IMethodNameMetadataApiAt<IMethodNameMetadataApiHolder, Interfaces::ITypeNameMetadataHashLabel>::type i_type_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Collections;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, v->GetCallingConvention().Value());
            hash_combine(seed, i_type_name_metadata_hash_type()(&v->GetReturnTypeName()));
            hash_combine(seed, SequenceHashValue(v->GetParameterTypeNames().cbegin(), 
                                                 v->GetParameterTypeNames().cend(), 
                                                 i_type_name_metadata_hash_type()));
            hash_combine(seed, i_type_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class IMethodNameMetadataApiHolder
    >    
    struct BaseIMethodNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseIMethodNameMetadata<IMethodNameMetadataApiHolder> const *>
    {
        typedef typename IMethodNameMetadataApiAt<IMethodNameMetadataApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            using namespace Urasandesu::CppAnonym::Collections;
            using namespace Urasandesu::CppAnonym::Utilities;

            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   x->GetCallingConvention() == y->GetCallingConvention() &&
                   i_type_name_metadata_equal_to_type()(&x->GetReturnTypeName(), &y->GetReturnTypeName()) &&
                   SequenceEqual(x->GetParameterTypeNames().cbegin(), x->GetParameterTypeNames().cend(), 
                                 y->GetParameterTypeNames().cbegin(), y->GetParameterTypeNames().cend()) &&
                   i_type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };






    template<class ApiCartridgesHolder, class ApiLabel>
    struct IMethodMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IMethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IMethodMetadataApiHolder
    >    
    class BaseIMethodMetadata
    {
    public:
        typedef BaseIMethodMetadata<IMethodMetadataApiHolder> this_type;

        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodNameMetadataLabel>::type i_method_name_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual i_method_name_metadata_type const &GetMethodName() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ILocalsNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ILocalsNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ILocalsNameMetadataApiHolder
    >    
    class BaseILocalsNameMetadata
    {
    public:
        typedef BaseILocalsNameMetadata<ILocalsNameMetadataApiHolder> this_type;

        //typedef typename ILocalsNameMetadataApiAt<ILocalsNameMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        //typedef typename ILocalsNameMetadataApiAt<ILocalsNameMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type i_method_metadata_type;

        //virtual std::wstring const &GetName() const = 0;
        //virtual CallingConventions const &GetCallingConvention() const = 0;
        //virtual i_type_name_metadata_type const &GetReturnTypeName() const = 0;
        //virtual std::vector<i_type_name_metadata_type const *> const &GetParameterTypeNames() const = 0;
        //virtual i_type_name_metadata_type const &GetResolutionScope() const = 0;
        //virtual i_method_metadata_type const &Resolve() const = 0;
    };

    
    
    

    template<
        class ILocalsNameMetadataApiHolder
    >    
    struct BaseILocalsNameMetadataHash : 
        Traits::HashComputable<BaseILocalsNameMetadata<ILocalsNameMetadataApiHolder> const *>
    {
        //typedef typename ILocalsNameMetadataApiAt<ILocalsNameMetadataApiHolder, Interfaces::ITypeNameMetadataHashLabel>::type i_type_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //using namespace boost;
            //using namespace Urasandesu::CppAnonym::Collections;

            //_ASSERTE(v != NULL);

            //std::size_t seed = 0;
            //hash_combine(seed, hash_value(v->GetName()));
            //hash_combine(seed, v->GetCallingConvention().Value());
            //hash_combine(seed, i_type_name_metadata_hash_type()(&v->GetReturnTypeName()));
            //hash_combine(seed, SequenceHashValue(v->GetParameterTypeNames().cbegin(), 
            //                                     v->GetParameterTypeNames().cend(), 
            //                                     i_type_name_metadata_hash_type()));
            //hash_combine(seed, i_type_name_metadata_hash_type()(&v->GetResolutionScope()));
            //return seed;
        }
    };
    
    
    
    
    
    template<
        class ILocalsNameMetadataApiHolder
    >    
    struct BaseILocalsNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseILocalsNameMetadata<ILocalsNameMetadataApiHolder> const *>
    {
        //typedef typename ILocalsNameMetadataApiAt<ILocalsNameMetadataApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //using namespace Urasandesu::CppAnonym::Collections;
            //using namespace Urasandesu::CppAnonym::Utilities;

            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       x->GetCallingConvention() == y->GetCallingConvention() &&
            //       i_type_name_metadata_equal_to_type()(&x->GetReturnTypeName(), &y->GetReturnTypeName()) &&
            //       SequenceEqual(x->GetParameterTypeNames().cbegin(), x->GetParameterTypeNames().cend(), 
            //                     y->GetParameterTypeNames().cbegin(), y->GetParameterTypeNames().cend()) &&
            //       i_type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };






    template<class ApiCartridgesHolder, class ApiLabel>
    struct ILocalsMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ILocalsMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ILocalsMetadataApiHolder
    >    
    class BaseILocalsMetadata
    {
    public:
        typedef BaseILocalsMetadata<ILocalsMetadataApiHolder> this_type;

        typedef typename ILocalsMetadataApiAt<ILocalsMetadataApiHolder, Interfaces::IMethodNameMetadataLabel>::type i_method_name_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual i_method_name_metadata_type const &GetMethodName() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IFieldNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IFieldNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IFieldNameMetadataApiHolder
    >    
    class BaseIFieldNameMetadata
    {
    public:
        typedef BaseIFieldNameMetadata<IFieldNameMetadataApiHolder> this_type;

        typedef typename IFieldNameMetadataApiAt<IFieldNameMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        typedef typename IFieldNameMetadataApiAt<IFieldNameMetadataApiHolder, Interfaces::IFieldMetadataLabel>::type i_field_metadata_type;

        virtual std::wstring const &GetName() const = 0;
        virtual i_type_name_metadata_type const &GetFieldTypeName() const = 0;
        virtual i_type_name_metadata_type const &GetResolutionScope() const = 0;
        virtual i_field_metadata_type const &Resolve() const = 0;
    };

    
    
    

    template<
        class IFieldNameMetadataApiHolder
    >    
    struct BaseIFieldNameMetadataHash : 
        Traits::HashComputable<BaseIFieldNameMetadata<IFieldNameMetadataApiHolder> const *>
    {
        typedef typename IFieldNameMetadataApiAt<IFieldNameMetadataApiHolder, Interfaces::ITypeNameMetadataHashLabel>::type i_type_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_type_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class IFieldNameMetadataApiHolder
    >    
    struct BaseIFieldNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseIFieldNameMetadata<IFieldNameMetadataApiHolder> const *>
    {
        typedef typename IFieldNameMetadataApiAt<IFieldNameMetadataApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   i_type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };






    template<class ApiCartridgesHolder, class ApiLabel>
    struct IFieldMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IFieldMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IFieldMetadataApiHolder
    >    
    class BaseIFieldMetadata
    {
    public:
        typedef BaseIFieldMetadata<IFieldMetadataApiHolder> this_type;

        typedef typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::IFieldNameMetadataLabel>::type i_field_name_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual i_field_name_metadata_type const &GetFieldName() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IPropertyNameMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IPropertyNameMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IPropertyNameMetadataApiHolder
    >    
    class BaseIPropertyNameMetadata
    {
    public:
        typedef BaseIPropertyNameMetadata<IPropertyNameMetadataApiHolder> this_type;

        typedef typename IPropertyNameMetadataApiAt<IPropertyNameMetadataApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        typedef typename IPropertyNameMetadataApiAt<IPropertyNameMetadataApiHolder, Interfaces::IPropertyMetadataLabel>::type i_property_metadata_type;

        virtual std::wstring const &GetName() const = 0;
        virtual i_type_name_metadata_type const &GetResolutionScope() const = 0;
        virtual i_property_metadata_type const &Resolve() const = 0;
    };

    
    
    

    template<
        class IPropertyNameMetadataApiHolder
    >    
    struct BaseIPropertyNameMetadataHash : 
        Traits::HashComputable<BaseIPropertyNameMetadata<IPropertyNameMetadataApiHolder> const *>
    {
        typedef typename IPropertyNameMetadataApiAt<IPropertyNameMetadataApiHolder, Interfaces::ITypeNameMetadataHashLabel>::type i_type_name_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_type_name_metadata_hash_type()(&v->GetResolutionScope()));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class IPropertyNameMetadataApiHolder
    >    
    struct BaseIPropertyNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseIPropertyNameMetadata<IPropertyNameMetadataApiHolder> const *>
    {
        typedef typename IPropertyNameMetadataApiAt<IPropertyNameMetadataApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);

            return x->GetName() == y->GetName() &&
                   i_type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };






    template<class ApiCartridgesHolder, class ApiLabel>
    struct IPropertyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IPropertyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IPropertyMetadataApiHolder
    >    
    class BaseIPropertyMetadata
    {
    public:
        typedef BaseIPropertyMetadata<IPropertyMetadataApiHolder> this_type;

        typedef typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::IPropertyNameMetadataLabel>::type i_property_name_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual i_property_name_metadata_type const &GetPropertyName() const = 0;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyMetadataGeneratorApiHolder
    >    
    class BaseAssemblyMetadataGenerator : 
        public AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::IAssemblyMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::ModuleMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyMetadataGenerator<AssemblyMetadataGeneratorApiHolder> this_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::IAssemblyMetadataLabel>::type base_type;

        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::AssemblyNameMetadataGeneratorLabel>::type assembly_name_metadata_generator_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::ModuleMetadataGeneratorLabel>::type module_metadata_generator_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::IModuleNameMetadataHashLabel>::type i_module_name_metadata_hash_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Interfaces::IModuleNameMetadataEqualToLabel>::type i_module_name_metadata_equal_to_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename AssemblyMetadataGeneratorApiAt<AssemblyMetadataGeneratorApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;        

        typedef ObjectTag<module_metadata_generator_type, QuickHeap> module_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<module_metadata_generator_obj_tag_type>::type module_metadata_generator_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(AsmNameMetaGen, module_name_metadata_generator_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(AsmNameMetaGen, module_name_metadata_generator_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(AsmNameMetaGen, module_name_metadata_generator_heap_type, assembly_name_metadata_generator_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(AsmNameMetaGen, module_name_metadata_generator_heap_type, assembly_name_metadata_generator_type), 
            boost::mpl::void_
        >::type module_name_metadata_generator_heap_type;

        BaseAssemblyMetadataGenerator() : 
            m_pDispAsScope(NULL), 
            m_pAsmNameGen(NULL)
        { }

        void Init(metadata_dispenser_type &dispAsScope) const
        {
            _ASSERTE(m_pDispAsScope == NULL);
            m_pDispAsScope = &dispAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pDispAsScope != NULL); return m_pDispAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        mdAssembly GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        typename base_type::i_assembly_name_metadata_type const &GetAssemblyName() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        module_metadata_generator_type *DefineModule(module_name_metadata_generator_type const &modNameGen)
        {
            if (m_modNameGenToIndex.find(&modNameGen) == m_modNameGenToIndex.end())
            {
                m_modNameGenToIndex[&modNameGen] = MAXULONG_PTR;
            }

            SIZE_T index = m_modNameGenToIndex[&modNameGen];
            if (index == MAXULONG_PTR)
            {
                module_metadata_generator_type *pModMetaGen = NULL;
                pModMetaGen = ModuleMetadataGeneratorHeap().New();
                pModMetaGen->Init(*this);
                pModMetaGen->SetModuleName(const_cast<module_name_metadata_generator_type &>(modNameGen));

                m_modNameGenToIndex[&modNameGen] = ModuleMetadataGeneratorHeap().Size() - 1;

                return pModMetaGen;
            }
            else
            {
                return ModuleMetadataGeneratorHeap()[index];
            }
        }
        
        void Save(std::wstring const &name, 
                  Hosting::PortableExecutableKinds const &portableExecutableKind, 
                  Hosting::ImageFileMachine const &imageFileMachine) const
        {
            runtime_host_type const &runtimeHost = Map<runtime_host_type>();
    
            pe_writer_host_type *pPEWriterHost = NULL;
            pPEWriterHost = runtimeHost.NewPEWriter(name, portableExecutableKind, imageFileMachine);
    
            pPEWriterHost->Save(*this);
        }

    private:
        friend typename metadata_dispenser_type;
        friend typename module_name_metadata_generator_type;
        friend typename pe_writer_host_type;

        module_metadata_generator_heap_type &ModuleMetadataGeneratorHeap()
        {
            return Of<module_metadata_generator_obj_tag_type>();
        }
        
        module_metadata_generator_heap_type const &ModuleMetadataGeneratorHeap() const
        {
            return Of<module_metadata_generator_obj_tag_type>();
        }

        module_name_metadata_generator_heap_type &ModuleNameMetadataGeneratorHeap()
        {
            return GetAssemblyNameCore()->ModuleNameMetadataGeneratorHeap();
        }
        
        module_name_metadata_generator_heap_type const &ModuleNameMetadataGeneratorHeap() const
        {
            return GetAssemblyNameCore()->ModuleNameMetadataGeneratorHeap();
        }

        void SaveTo(pe_writer_host_type &peWriterHost) const
        {
            // Resolve
            {
                module_name_metadata_generator_heap_type const &heap = ModuleNameMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->Resolve();
            }
    
            // SaveTo
            {
                module_metadata_generator_heap_type const &heap = ModuleMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->SaveTo(peWriterHost);
            }
        }

        assembly_name_metadata_generator_type const *GetAssemblyNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetAssemblyNameCore();
        }

        assembly_name_metadata_generator_type *GetAssemblyNameCore()
        {
            if (m_pAsmNameGen == NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                //metadata_dispenser_type &metaDisp = Map<metadata_dispenser_type>();

                //m_pAsmNameMeta = metaDisp.AssemblyNameMetadataHeap().New();
                //m_pAsmNameMeta->Init(metaDisp);
                //m_pAsmNameMeta->SetToken(GetToken());
                //m_pAsmNameMeta->SetResolvedAssembly(*this);
            }
            return m_pAsmNameGen;
        }

        void SetAssemblyName(assembly_name_metadata_generator_type &asmNameGen)
        {
            if (m_pAsmNameGen != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException("The heap of current object has to merge from the designated object!!"));
            }
            m_pAsmNameGen = &asmNameGen;
        }
        
        mutable metadata_dispenser_type *m_pDispAsScope;
        mutable assembly_name_metadata_generator_type *m_pAsmNameGen;
        mutable boost::unordered_map<module_name_metadata_generator_type const *, 
                                     SIZE_T, 
                                     i_module_name_metadata_hash_type, 
                                     i_module_name_metadata_equal_to_type> m_modNameGenToIndex;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleMetadataGeneratorApiHolder
    >    
    class BaseModuleMetadataGenerator : 
        public ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::IModuleMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseModuleMetadataGenerator<ModuleMetadataGeneratorApiHolder> this_type;
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::IModuleMetadataLabel>::type base_type;

        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::AssemblyMetadataGeneratorLabel>::type assembly_metadata_generator_type;    
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;    
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataHashLabel>::type i_type_name_metadata_hash_type;
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;
        typedef typename ModuleMetadataGeneratorApiAt<ModuleMetadataGeneratorApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;    

        typedef ObjectTag<type_metadata_generator_type, QuickHeap> type_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<type_metadata_generator_obj_tag_type>::type type_metadata_generator_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ModNameMetaGen, type_name_metadata_generator_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ModNameMetaGen, type_name_metadata_generator_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(ModNameMetaGen, type_name_metadata_generator_heap_type, module_name_metadata_generator_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(ModNameMetaGen, type_name_metadata_generator_heap_type, module_name_metadata_generator_type), 
            boost::mpl::void_
        >::type type_name_metadata_generator_heap_type;

        BaseModuleMetadataGenerator() : 
            m_pAsmMetaGenAsScope(NULL),
            m_pModNameGen(NULL)
        { }

        void Init(assembly_metadata_generator_type &asmMetaGenAsScope) const
        {
            _ASSERTE(m_pAsmMetaGenAsScope == NULL);
            m_pAsmMetaGenAsScope = &asmMetaGenAsScope;
        }

        mdModule GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        typename base_type::i_module_name_metadata_type const &GetModuleName() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        type_metadata_generator_type *DefineType(type_name_metadata_generator_type const &typeNameGen)
        {
            if (m_typeNameGenToIndex.find(&typeNameGen) == m_typeNameGenToIndex.end())
            {
                m_typeNameGenToIndex[&typeNameGen] = MAXULONG_PTR;
            }

            SIZE_T index = m_typeNameGenToIndex[&typeNameGen];
            if (index == MAXULONG_PTR)
            {
                type_metadata_generator_type *pTypeMetaGen = NULL;
                pTypeMetaGen= TypeMetadataGeneratorHeap().New();
                pTypeMetaGen->Init(*this);
                pTypeMetaGen->SetTypeName(const_cast<type_name_metadata_generator_type &>(typeNameGen));

                m_typeNameGenToIndex[&typeNameGen] = TypeMetadataGeneratorHeap().Size() - 1;

                return pTypeMetaGen;
            }
            else
            {
                return TypeMetadataGeneratorHeap()[index];
            }
        }
    
    private:
        friend typename assembly_metadata_generator_type;
        friend typename type_name_metadata_generator_type;

        type_metadata_generator_heap_type &TypeMetadataGeneratorHeap()
        {
            return Of<type_metadata_generator_obj_tag_type>();
        }
        
        type_metadata_generator_heap_type const &TypeMetadataGeneratorHeap() const
        {
            return Of<type_metadata_generator_obj_tag_type>();
        }

        type_name_metadata_generator_heap_type &TypeNameMetadataGeneratorHeap()
        {
            return GetModuleNameCore()->TypeNameMetadataGeneratorHeap();
        }
        
        type_name_metadata_generator_heap_type const &TypeNameMetadataGeneratorHeap() const
        {
            return GetModuleNameCore()->TypeNameMetadataGeneratorHeap();
        }

        void SaveTo(pe_writer_host_type &peWriterHost) const
        {
            // Resolve
            {
                type_name_metadata_generator_heap_type const &heap = TypeNameMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->Resolve();
            }
    
            // SaveTo
            {
                type_metadata_generator_heap_type const &heap = TypeMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->SaveTo(peWriterHost);
            }
        }

        module_name_metadata_generator_type const *GetModuleNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetModuleNameCore();
        }

        module_name_metadata_generator_type *GetModuleNameCore()
        {
            if (m_pModNameGen == NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                //assembly_metadata_type &asmMeta = Map<assembly_metadata_type>();

                //m_pModNameMeta = asmMeta.ModuleNameMetadataHeap().New();
                //m_pModNameMeta->Init(asmMeta);
                //m_pModNameMeta->SetToken(GetToken());
                //m_pModNameMeta->SetResolvedModule(*this);
            }
            return m_pModNameGen;
        }

        void SetModuleName(module_name_metadata_generator_type &modNameGen)
        {
            if (m_pModNameGen != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException("The heap of current object has to merge from the designated object!!"));
            }
            m_pModNameGen = &modNameGen;
        }

        mutable assembly_metadata_generator_type *m_pAsmMetaGenAsScope;
        module_name_metadata_generator_type *m_pModNameGen;
        mutable boost::unordered_map<type_name_metadata_generator_type const *, 
                                     SIZE_T, 
                                     i_type_name_metadata_hash_type, 
                                     i_type_name_metadata_equal_to_type> m_typeNameGenToIndex;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeMetadataGeneratorApiHolder
    >    
    class BaseTypeMetadataGenerator : 
        public TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::ITypeMetadataLabel>::type,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::FieldMetadataGeneratorLabel>::type, QuickHeap>,
                ObjectTag<typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::MethodMetadataGeneratorLabel>::type, QuickHeap>,
                ObjectTag<typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::PropertyMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeMetadataGenerator<TypeMetadataGeneratorApiHolder> this_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::ITypeMetadataLabel>::type base_type;

        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::ModuleMetadataGeneratorLabel>::type module_metadata_generator_type;    
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;    
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::FieldMetadataGeneratorLabel>::type field_metadata_generator_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type field_name_metadata_generator_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::IFieldNameMetadataHashLabel>::type i_field_name_metadata_hash_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::IFieldNameMetadataEqualToLabel>::type i_field_name_metadata_equal_to_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::MethodMetadataGeneratorLabel>::type method_metadata_generator_type;    
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::IMethodNameMetadataHashLabel>::type i_method_name_metadata_hash_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::IMethodNameMetadataEqualToLabel>::type i_method_name_metadata_equal_to_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::PropertyMetadataGeneratorLabel>::type property_metadata_generator_type;    
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::PropertyNameMetadataGeneratorLabel>::type property_name_metadata_generator_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::IPropertyNameMetadataHashLabel>::type i_property_name_metadata_hash_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Interfaces::IPropertyNameMetadataEqualToLabel>::type i_property_name_metadata_equal_to_type;
        typedef typename TypeMetadataGeneratorApiAt<TypeMetadataGeneratorApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;    

        typedef ObjectTag<field_metadata_generator_type, QuickHeap> field_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<field_metadata_generator_obj_tag_type>::type field_metadata_generator_heap_type;

        typedef ObjectTag<method_metadata_generator_type, QuickHeap> method_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<method_metadata_generator_obj_tag_type>::type method_metadata_generator_heap_type;

        typedef ObjectTag<property_metadata_generator_type, QuickHeap> property_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<property_metadata_generator_obj_tag_type>::type property_metadata_generator_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeNameMetaGen, field_name_metadata_generator_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeNameMetaGen, field_name_metadata_generator_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeNameMetaGen, field_name_metadata_generator_heap_type, type_name_metadata_generator_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeNameMetaGen, field_name_metadata_generator_heap_type, type_name_metadata_generator_type), 
            boost::mpl::void_
        >::type field_name_metadata_generator_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeNameMetaGen, method_name_metadata_generator_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeNameMetaGen, method_name_metadata_generator_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeNameMetaGen, method_name_metadata_generator_heap_type, type_name_metadata_generator_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeNameMetaGen, method_name_metadata_generator_heap_type, type_name_metadata_generator_type), 
            boost::mpl::void_
        >::type method_name_metadata_generator_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeNameMetaGen, property_name_metadata_generator_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeNameMetaGen, property_name_metadata_generator_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeNameMetaGen, property_name_metadata_generator_heap_type, type_name_metadata_generator_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeNameMetaGen, property_name_metadata_generator_heap_type, type_name_metadata_generator_type), 
            boost::mpl::void_
        >::type property_name_metadata_generator_heap_type;

        BaseTypeMetadataGenerator() : 
            m_pModMetaGenAsScope(NULL),
            m_pTypeNameGen(NULL)
        { }

        void Init(module_metadata_generator_type &modMetaGenAsScope) const
        {
            _ASSERTE(m_pModMetaGenAsScope == NULL);
            m_pModMetaGenAsScope = &modMetaGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pModMetaGenAsScope != NULL); return m_pModMetaGenAsScope->Map<T>(); }

        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        typename base_type::i_type_name_metadata_type const &GetTypeName() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        typename base_type::this_type const *GetBaseType() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        field_metadata_generator_type *DefineField(field_name_metadata_generator_type const &fieldNameGen)
        {
            if (m_fieldNameGenToIndex.find(&fieldNameGen) == m_fieldNameGenToIndex.end())
            {
                m_fieldNameGenToIndex[&fieldNameGen] = MAXULONG_PTR;
            }

            SIZE_T index = m_fieldNameGenToIndex[&fieldNameGen];
            if (index == MAXULONG_PTR)
            {
                field_metadata_generator_type *pFieldMetaGen = NULL;
                pFieldMetaGen= FieldMetadataGeneratorHeap().New();
                pFieldMetaGen->Init(*this);
                pFieldMetaGen->SetFieldName(const_cast<field_name_metadata_generator_type &>(fieldNameGen));

                m_fieldNameGenToIndex[&fieldNameGen] = FieldMetadataGeneratorHeap().Size() - 1;

                return pFieldMetaGen;
            }
            else
            {
                return FieldMetadataGeneratorHeap()[index];
            }
        }

        method_metadata_generator_type *DefineMethod(method_name_metadata_generator_type const &methodNameGen)
        {
            if (m_methodNameGenToIndex.find(&methodNameGen) == m_methodNameGenToIndex.end())
            {
                m_methodNameGenToIndex[&methodNameGen] = MAXULONG_PTR;
            }

            SIZE_T index = m_methodNameGenToIndex[&methodNameGen];
            if (index == MAXULONG_PTR)
            {
                method_metadata_generator_type *pMethodMetaGen = NULL;
                pMethodMetaGen= MethodMetadataGeneratorHeap().New();
                pMethodMetaGen->Init(*this);
                pMethodMetaGen->SetMethodName(const_cast<method_name_metadata_generator_type &>(methodNameGen));

                m_methodNameGenToIndex[&methodNameGen] = MethodMetadataGeneratorHeap().Size() - 1;

                return pMethodMetaGen;
            }
            else
            {
                return MethodMetadataGeneratorHeap()[index];
            }
        }

        property_metadata_generator_type *DefineProperty(property_name_metadata_generator_type const &propertyNameGen)
        {
            if (m_propNameGenToIndex.find(&propertyNameGen) == m_propNameGenToIndex.end())
            {
                m_propNameGenToIndex[&propertyNameGen] = MAXULONG_PTR;
            }

            SIZE_T index = m_propNameGenToIndex[&propertyNameGen];
            if (index == MAXULONG_PTR)
            {
                property_metadata_generator_type *pPropertyMetaGen = NULL;
                pPropertyMetaGen= PropertyMetadataGeneratorHeap().New();
                pPropertyMetaGen->Init(*this);
                pPropertyMetaGen->SetPropertyName(const_cast<property_name_metadata_generator_type &>(propertyNameGen));

                m_propNameGenToIndex[&propertyNameGen] = PropertyMetadataGeneratorHeap().Size() - 1;

                return pPropertyMetaGen;
            }
            else
            {
                return PropertyMetadataGeneratorHeap()[index];
            }
        }

    private:
        friend typename module_metadata_generator_type;
        friend typename field_name_metadata_generator_type;
        friend typename method_name_metadata_generator_type;
        friend typename method_metadata_generator_type;
        friend typename property_name_metadata_generator_type;

        field_metadata_generator_heap_type &FieldMetadataGeneratorHeap()
        {
            return Of<field_metadata_generator_obj_tag_type>();
        }
        
        field_metadata_generator_heap_type const &FieldMetadataGeneratorHeap() const
        {
            return Of<field_metadata_generator_obj_tag_type>();
        }

        field_name_metadata_generator_heap_type &FieldNameMetadataGeneratorHeap()
        {
            return GetTypeNameCore()->FieldNameMetadataGeneratorHeap();
        }
        
        field_name_metadata_generator_heap_type const &FieldNameMetadataGeneratorHeap() const
        {
            return GetTypeNameCore()->FieldNameMetadataGeneratorHeap();
        }

        method_metadata_generator_heap_type &MethodMetadataGeneratorHeap()
        {
            return Of<method_metadata_generator_obj_tag_type>();
        }
        
        method_metadata_generator_heap_type const &MethodMetadataGeneratorHeap() const
        {
            return Of<method_metadata_generator_obj_tag_type>();
        }

        method_name_metadata_generator_heap_type &MethodNameMetadataGeneratorHeap()
        {
            return GetTypeNameCore()->MethodNameMetadataGeneratorHeap();
        }
        
        method_name_metadata_generator_heap_type const &MethodNameMetadataGeneratorHeap() const
        {
            return GetTypeNameCore()->MethodNameMetadataGeneratorHeap();
        }

        property_metadata_generator_heap_type &PropertyMetadataGeneratorHeap()
        {
            return Of<property_metadata_generator_obj_tag_type>();
        }
        
        property_metadata_generator_heap_type const &PropertyMetadataGeneratorHeap() const
        {
            return Of<property_metadata_generator_obj_tag_type>();
        }

        property_name_metadata_generator_heap_type &PropertyNameMetadataGeneratorHeap()
        {
            return GetTypeNameCore()->PropertyNameMetadataGeneratorHeap();
        }
        
        property_name_metadata_generator_heap_type const &PropertyNameMetadataGeneratorHeap() const
        {
            return GetTypeNameCore()->PropertyNameMetadataGeneratorHeap();
        }

        void SaveTo(pe_writer_host_type &peWriterHost) const
        {
            // Resolve
            {
                field_name_metadata_generator_heap_type const &heap = FieldNameMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->Resolve();
            }
            {
                method_name_metadata_generator_heap_type const &heap = MethodNameMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->Resolve();
            }
            {
                property_name_metadata_generator_heap_type const &heap = PropertyNameMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->Resolve();
            }
    
            // SaveTo
            {
                field_metadata_generator_heap_type const &heap = FieldMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->SaveTo(peWriterHost);
            }
            {
                method_metadata_generator_heap_type const &heap = MethodMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->SaveTo(peWriterHost);
            }
            {
                property_metadata_generator_heap_type const &heap = PropertyMetadataGeneratorHeap();
                SIZE_T size = heap.Size();
                for (SIZE_T n = 0; n < size; ++n)
                    heap[n]->SaveTo(peWriterHost);
            }
        }

        type_name_metadata_generator_type const *GetTypeNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetTypeNameCore();
        }

        type_name_metadata_generator_type *GetTypeNameCore()
        {
            if (m_pTypeNameGen == NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_pTypeNameGen;
        }

        void SetTypeName(type_name_metadata_generator_type &typeNameGen)
        {
            if (m_pTypeNameGen != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException("The heap of current object has to merge from the designated object!!"));
            }
            m_pTypeNameGen = &typeNameGen;
        }
        
        mutable module_metadata_generator_type *m_pModMetaGenAsScope;
        type_name_metadata_generator_type *m_pTypeNameGen;
        mutable boost::unordered_map<field_name_metadata_generator_type const *, 
                                     SIZE_T, 
                                     i_field_name_metadata_hash_type, 
                                     i_field_name_metadata_equal_to_type> m_fieldNameGenToIndex;
        mutable boost::unordered_map<method_name_metadata_generator_type const *, 
                                     SIZE_T, 
                                     i_method_name_metadata_hash_type, 
                                     i_method_name_metadata_equal_to_type> m_methodNameGenToIndex;
        mutable boost::unordered_map<property_name_metadata_generator_type const *, 
                                     SIZE_T, 
                                     i_property_name_metadata_hash_type, 
                                     i_property_name_metadata_equal_to_type> m_propNameGenToIndex;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct FieldMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::FieldMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FieldMetadataGeneratorApiHolder
    >    
    class BaseFieldMetadataGenerator : 
        public FieldMetadataGeneratorApiAt<FieldMetadataGeneratorApiHolder, Interfaces::IFieldMetadataLabel>::type
    {
    public:
        typedef BaseFieldMetadataGenerator<FieldMetadataGeneratorApiHolder> this_type;    
        typedef typename FieldMetadataGeneratorApiAt<FieldMetadataGeneratorApiHolder, Interfaces::IFieldMetadataLabel>::type base_type;

        typedef typename FieldMetadataGeneratorApiAt<FieldMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename FieldMetadataGeneratorApiAt<FieldMetadataGeneratorApiHolder, Interfaces::FieldNameMetadataGeneratorLabel>::type field_name_metadata_generator_type;
        typedef typename FieldMetadataGeneratorApiAt<FieldMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        typedef typename FieldMetadataGeneratorApiAt<FieldMetadataGeneratorApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;

        BaseFieldMetadataGenerator() : 
            m_pTypeMetaGenAsScope(NULL),
            m_pFieldNameGen(NULL),
            m_mdt(mdTokenNil)
        { }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                field_name_metadata_generator_type const &fieldNameGen = GetFieldNameCore();

                std::wstring const &name = fieldNameGen.GetName();

                SimpleBlob sig;

                sig.Put<COR_SIGNATURE>(IMAGE_CEE_CS_CALLCONV_FIELD);

                i_type_name_metadata_type const &fieldTypeName = fieldNameGen.GetFieldTypeName();
                SignatureUtil::PutSignatures(sig, fieldTypeName);
        //// Create Field records.
        //mdFieldDef mdfdNowGetm_body = mdFieldDefNil;
        //{
        //    COR_SIGNATURE pSigBlob[] = {
        //        IMAGE_CEE_CS_CALLCONV_FIELD,    // FIELD
        //        ELEMENT_TYPE_GENERICINST,       // TYPE: GENERICINST
        //        ELEMENT_TYPE_CLASS,             //       CLASS
        //        0x05,                           //       TypeRef: 0x01000001(System.Func`1)
        //        1,                              //       Generics Arguments Count: 1
        //        ELEMENT_TYPE_VALUETYPE,         //       VALUETYPE
        //        0x0D                            //       TypeRef: 0x01000003(System.DateTime)
        //    };                                  
        //    ULONG sigBlobSize = sizeof(pSigBlob) / sizeof(COR_SIGNATURE);
        //    hr = pEmtMSCorLibPrig->DefineField(mdtdNowGet, L"m_body", 
        //                                       fdPrivate | fdStatic, 
        //                                       pSigBlob, sigBlobSize, 
        //                                       ELEMENT_TYPE_VOID, NULL, 0, &mdfdNowGetm_body);
        //    if (FAILED(hr))
        //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        //}
        //    
        //D_COUT1("Token of FieldDef for System.Prig.PDateTime.NowGet.m_body: 0x%|1$08X|", mdfdNowGetm_body);
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_mdt;
        }

        typename base_type::i_field_name_metadata_type const &GetFieldName() const
        {
            return GetFieldNameCore();
        }
    
    private:
        friend typename type_metadata_generator_type;

        void Init(type_metadata_generator_type &typeMetaGenAsScope) const
        {
            _ASSERTE(m_pTypeMetaGenAsScope == NULL);
            m_pTypeMetaGenAsScope = &typeMetaGenAsScope;
        }

        void SaveTo(pe_writer_host_type &peWriterHost) const
        {
            // Resolve
            {
                //field_name_metadata_generator_heap_type const &heap = FieldNameMetadataGeneratorHeap();
                //SIZE_T size = heap.Size();
                //for (SIZE_T n = 0; n < size; ++n)
                //    heap[n]->Resolve();
            }
    
            // SaveTo
            {
                //field_metadata_generator_heap_type const &heap = FieldMetadataGeneratorHeap();
                //SIZE_T size = heap.Size();
                //for (SIZE_T n = 0; n < size; ++n)
                //    heap[n]->SaveTo(peWriterHost);
            }
        }

        field_name_metadata_generator_type const &GetFieldNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetFieldNameCore();
        }

        field_name_metadata_generator_type &GetFieldNameCore()
        {
            if (m_pFieldNameGen == NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return *m_pFieldNameGen;
        }

        void SetFieldName(field_name_metadata_generator_type &fieldNameGen)
        {
            if (m_pFieldNameGen != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException("The heap of current object has to merge from the designated object!!"));
            }
            m_pFieldNameGen = &fieldNameGen;
        }

        mutable type_metadata_generator_type *m_pTypeMetaGenAsScope;
        field_name_metadata_generator_type *m_pFieldNameGen;
        mutable mdToken m_mdt;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataGeneratorApiHolder
    >    
    class BaseMethodMetadataGenerator : 
        public MethodMetadataGeneratorApiAt<MethodMetadataGeneratorApiHolder, Interfaces::IMethodMetadataLabel>::type
    {
    public:
        typedef BaseMethodMetadataGenerator<MethodMetadataGeneratorApiHolder> this_type; 
        typedef typename MethodMetadataGeneratorApiAt<MethodMetadataGeneratorApiHolder, Interfaces::IMethodMetadataLabel>::type base_type;

        typedef typename MethodMetadataGeneratorApiAt<MethodMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename MethodMetadataGeneratorApiAt<MethodMetadataGeneratorApiHolder, Interfaces::MethodNameMetadataGeneratorLabel>::type method_name_metadata_generator_type;
        typedef typename MethodMetadataGeneratorApiAt<MethodMetadataGeneratorApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;        

        BaseMethodMetadataGenerator() : 
            m_pTypeMetaGenAsScope(NULL),
            m_pMethodNameGen(NULL)
        { }

    private:
        friend typename type_metadata_generator_type;
        
        void Init(type_metadata_generator_type &typeMetaGenAsScope) const
        {
            _ASSERTE(m_pTypeMetaGenAsScope == NULL);
            m_pTypeMetaGenAsScope = &typeMetaGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() { _ASSERTE(m_pTypeMetaGenAsScope != NULL); return m_pTypeMetaGenAsScope->Map<T>(); }
      
        template<>
        this_type const &Map<this_type>() const { return *this; }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        typename base_type::i_method_name_metadata_type const &GetMethodName() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        void SaveTo(pe_writer_host_type &peWriterHost) const
        {
            // Resolve
            {
                //field_name_metadata_generator_heap_type const &heap = FieldNameMetadataGeneratorHeap();
                //SIZE_T size = heap.Size();
                //for (SIZE_T n = 0; n < size; ++n)
                //    heap[n]->Resolve();
            }
    
            // SaveTo
            {
                //field_metadata_generator_heap_type const &heap = FieldMetadataGeneratorHeap();
                //SIZE_T size = heap.Size();
                //for (SIZE_T n = 0; n < size; ++n)
                //    heap[n]->SaveTo(peWriterHost);
            }

            ULONG codeRVA = GetMethodNameCore().GetMethodBody().SaveTo(peWriterHost);
            //GetMethodBody().SaveTo(peWriterHost); // こんな感じのショートカットが欲しいところ。
            //// そうなると、こうか・・・
            ////ULONG codeRVA = peWriterHost.MergeMetadata(GetMethodBody());  // これだと、MethodBodyWriter が返す情報、PEFile が知らなきゃいけないのか・・・。
            //ULONG codeRVA = GetMethodBody().SaveTo(peWriterHost);         // こうでもいいな！これだと、MethodBodyWriter が知ってる情報を PEFile に突っ込む、でその結果が返る感じに見える。
            //
            //// ↓SetMethodProps はこのレベルでやりたい。
            ////hr = pEmtMSCorLibPrig->SetMethodProps(mdmdNowGetcctor, -1, codeRVA, 0);
            ////if (FAILED(hr))
            ////    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

        void SetMethodName(method_name_metadata_generator_type &methodNameGen)
        {
            if (m_pMethodNameGen != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            m_pMethodNameGen = &methodNameGen;
        }

        method_name_metadata_generator_type const &GetMethodNameCore() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return pMutableThis->GetMethodNameCore();
        }

        method_name_metadata_generator_type &GetMethodNameCore()
        {
            if (m_pMethodNameGen == NULL)
            {
                type_metadata_generator_type &typeMeta = Map<type_metadata_generator_type>();

                m_pMethodNameGen = typeMeta.MethodNameMetadataGeneratorHeap().New();
                m_pMethodNameGen->Init(typeMeta);
                m_pMethodNameGen->SetResolvedMethod(*this);
            }
            return *m_pMethodNameGen;
        }

        mutable type_metadata_generator_type *m_pTypeMetaGenAsScope;
        method_name_metadata_generator_type *m_pMethodNameGen;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct PropertyMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::PropertyMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class PropertyMetadataGeneratorApiHolder
    >    
    class BasePropertyMetadataGenerator : 
        public PropertyMetadataGeneratorApiAt<PropertyMetadataGeneratorApiHolder, Interfaces::IPropertyMetadataLabel>::type
    {
    public:
        typedef BasePropertyMetadataGenerator<PropertyMetadataGeneratorApiHolder> this_type; 
        typedef typename public PropertyMetadataGeneratorApiAt<PropertyMetadataGeneratorApiHolder, Interfaces::IPropertyMetadataLabel>::type base_type;

        typedef typename PropertyMetadataGeneratorApiAt<PropertyMetadataGeneratorApiHolder, Interfaces::TypeMetadataGeneratorLabel>::type type_metadata_generator_type;
        typedef typename PropertyMetadataGeneratorApiAt<PropertyMetadataGeneratorApiHolder, Interfaces::PropertyNameMetadataGeneratorLabel>::type property_name_metadata_generator_type;
        typedef typename PropertyMetadataGeneratorApiAt<PropertyMetadataGeneratorApiHolder, Hosting::Interfaces::PEWriterHostLabel>::type pe_writer_host_type;        

        BasePropertyMetadataGenerator() : 
            m_pTypeMetaGenAsScope(NULL),
            m_pPropNameGen(NULL)
        { }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        typename base_type::i_property_name_metadata_type const &GetPropertyName() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

    private:
        friend typename type_metadata_generator_type;

        void Init(type_metadata_generator_type &typeMetaGenAsScope) const
        {
            _ASSERTE(m_pTypeMetaGenAsScope == NULL);
            m_pTypeMetaGenAsScope = &typeMetaGenAsScope;
        }

        void SetPropertyName(property_name_metadata_generator_type &propNameGen)
        {
            if (m_pPropNameGen != NULL)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            m_pPropNameGen = &propNameGen;
        }

        void SaveTo(pe_writer_host_type &peWriterHost) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        mutable type_metadata_generator_type *m_pTypeMetaGenAsScope;
        property_name_metadata_generator_type *m_pPropNameGen;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct LocalsNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::LocalsNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class LocalsNameMetadataGeneratorApiHolder
    >    
    class BaseLocalsNameMetadataGenerator : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename LocalsNameMetadataGeneratorApiAt<LocalsNameMetadataGeneratorApiHolder, Interfaces::LocalNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseLocalsNameMetadataGenerator<LocalsNameMetadataGeneratorApiHolder> this_type;

        typedef typename LocalsNameMetadataGeneratorApiAt<LocalsNameMetadataGeneratorApiHolder, Interfaces::MethodBodyWriterLabel>::type method_body_writer_type;
        typedef typename LocalsNameMetadataGeneratorApiAt<LocalsNameMetadataGeneratorApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename LocalsNameMetadataGeneratorApiAt<LocalsNameMetadataGeneratorApiHolder, Interfaces::ITypeNameMetadataLabel>::type i_type_name_metadata_type;
        typedef typename LocalsNameMetadataGeneratorApiAt<LocalsNameMetadataGeneratorApiHolder, Interfaces::LocalNameMetadataGeneratorLabel>::type local_name_metadata_generator_type;
        typedef typename LocalsNameMetadataGeneratorApiAt<LocalsNameMetadataGeneratorApiHolder, Interfaces::LocalsMetadataGeneratorLabel>::type locals_metadata_generator_type;

        typedef ObjectTag<local_name_metadata_generator_type, QuickHeap> local_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<local_name_metadata_generator_obj_tag_type>::type local_name_metadata_generator_heap_type;

        BaseLocalsNameMetadataGenerator() : 
            m_pMethodBodyWriterAsScope(NULL)
        { }

        locals_metadata_generator_type const &Resolve() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        local_name_metadata_generator_type *NewLocalNameMetadataGenerator(i_type_metadata_type const &localType) const
        {
            return NewLocalNameMetadataGenerator(localType.GetTypeName());
        }

        local_name_metadata_generator_type *NewLocalNameMetadataGenerator(i_type_name_metadata_type const &localTypeName) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            local_name_metadata_generator_type *pLocalNameMetaGen = NULL;
            pLocalNameMetaGen = pMutableThis->LocalNameMetadataGeneratorHeap().New();
            pLocalNameMetaGen->Init(*pMutableThis);
            pLocalNameMetaGen->SetLocalType(localTypeName);
            return pLocalNameMetaGen;
        }

    private:
        friend typename method_body_writer_type;

        local_name_metadata_generator_heap_type &LocalNameMetadataGeneratorHeap()
        {
            return Of<local_name_metadata_generator_obj_tag_type>();
        }
        
        local_name_metadata_generator_heap_type const &LocalNameMetadataGeneratorHeap() const
        {
            return Of<local_name_metadata_generator_obj_tag_type>();
        }

        void Init(method_body_writer_type &methodBodyWriterAsScope) const
        {
            _ASSERTE(m_pMethodBodyWriterAsScope == NULL);
            m_pMethodBodyWriterAsScope = &methodBodyWriterAsScope;
        }
    
        //    // SaveTo
        //    {
        //        //field_metadata_generator_heap_type const &heap = FieldMetadataGeneratorHeap();
        //        //SIZE_T size = heap.Size();
        //        //for (SIZE_T n = 0; n < size; ++n)
        //        //    heap[n]->SaveTo(peWriterHost);
        ////// Create StandAloneSig records.
        ////mdSignature mdsNowGetInitializeget_BodyLocals = mdSignatureNil;
        ////{
        ////    COR_SIGNATURE pSigBlob[] = {
        ////        IMAGE_CEE_CS_CALLCONV_LOCAL_SIG,// LOCAL_SIG   
        ////        0x01,                           // Count: 1
        ////        ELEMENT_TYPE_VALUETYPE,         // Type[0]: VALUETYPE
        ////        0x0D                            //          TypeRef: 0x01000003(System.DateTime)
        ////    };                                  
        ////    ULONG sigBlobSize = sizeof(pSigBlob) / sizeof(COR_SIGNATURE);
        ////    hr = pEmtMSCorLibPrig->GetTokenFromSig(pSigBlob, sigBlobSize, 
        ////                                           &mdsNowGetInitializeget_BodyLocals);
        ////    if (FAILED(hr))
        ////        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        ////}
        ////    
        ////D_COUT1("Token of StandAloneSig for System.Prig.PDateTime.NowGet.Initializeget_Body Locals: 0x%|1$08X|", mdsNowGetInitializeget_BodyLocals);
        //    }
        //    // いや、もう一枚かませたほうがいいな・・・。
        //    // Blob heap の Parser も兼ねて・・・。SignatureUtil でやってることもここに統合すればいいかも。
        //    // →BaseSignatureMetadata, signature_metadata_type。ID に当たる機能は無いね。
        //    //   →いや、Read 時に、たとえば各要素の Name から引っ張れるようにしたいパターンがありそう。なんにせよ、unordered_map に入れられるようにしてはおきたい。
        //    //   →BaseSignatureNameMetadata, signature_name_metadata_type。
        //    // →んで、ここから Local**Metadata を取り出せるようにしておく的な。
        //    //   →いや、Signature というか、Blob stream に入ってる情報の抽象という意味では一連の仲間が必要そう。
        //    //     →Base**Signature というか。
        //    //     →今回の Local 変数達を保持する Signature だったら、BaseStandAloneSignature/BaseStandAloneNameSignature/BaseStandAloneNameSignatureGenerator/BaseStandAloneSignatureGenerator とか。

        mutable method_body_writer_type *m_pMethodBodyWriterAsScope;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct LocalsMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::LocalsMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class LocalsMetadataGeneratorApiHolder
    >    
    class BaseLocalsMetadataGenerator
    {
    public:
        typedef BaseLocalsMetadataGenerator<LocalsMetadataGeneratorApiHolder> this_type;

        mdSignature GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }
        //typedef typename LocalsMetadataGeneratorApiAt<LocalsMetadataGeneratorApiHolder, Interfaces::MethodBodyWriterLabel>::type method_body_writer_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, COR_ILMETHOD_Test_01)
    {
        COR_ILMETHOD_FAT fatHeader;
        ::ZeroMemory(&fatHeader, sizeof(COR_ILMETHOD_FAT));
        fatHeader.SetMaxStack(1);
        fatHeader.SetCodeSize(20);
        fatHeader.SetLocalVarSigTok(mdTokenNil);
        fatHeader.SetFlags(0);
                
        unsigned headerSize = COR_ILMETHOD::Size(&fatHeader, false);

        ASSERT_EQ(1, headerSize);
    }

    namespace _45DD35FD {
        
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        namespace Interfaces {

            using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

            struct TestITypeNameMetadataApiHolderLabel { };
            struct TestITypeNameMetadataLabel { };

            struct TestTypeNameMetadataApiHolderLabel { };
            struct TestTypeNameMetadataLabel { };

        }   // namespace Interfaces {

        namespace ApiHolders {

            struct DefaultTestITypeNameMetadataApiHolder;

            struct DefaultTestTypeNameMetadataApiHolder;

        }   // namespace ApiHolders {

        template<
            class TestTypeNameMetadataApiHolder = ApiHolders::DefaultTestTypeNameMetadataApiHolder
        >    
        class BaseTestTypeNameMetadata;

        typedef BaseTestTypeNameMetadata<> TestTypeNameMetadata;

        template<
            class TestITypeNameMetadataApiHolder = ApiHolders::DefaultTestITypeNameMetadataApiHolder
        >    
        class BaseTestITypeNameMetadata;

        typedef BaseTestITypeNameMetadata<> TestITypeNameMetadata;

        namespace ApiHolders {

            //namespace Detail {

            //    using namespace boost::mpl;
            //    using namespace _45DD35FD::Interfaces;

            //    struct DefaultTestTypeNameMetadataApiHolderImpl
            //    {
            //        typedef map<
            //            pair<TestITypeNameMetadataLabel, BaseTestITypeNameMetadata<TestTypeNameMetadata> >
            //        > api_cartridges;
            //    };

            //}   // namespace Detail {

            struct DefaultTestITypeNameMetadataApiHolder
            {
            };

            namespace Detail {

                using namespace boost::mpl;
                using namespace _45DD35FD::Interfaces;

                struct DefaultTestTypeNameMetadataApiHolderImpl
                {
                    typedef map<
                        pair<TestITypeNameMetadataLabel, TestITypeNameMetadata>
                    > api_cartridges;
                };

            }   // namespace Detail {

            struct DefaultTestTypeNameMetadataApiHolder : 
                Detail::DefaultTestTypeNameMetadataApiHolderImpl
            {
            };

        }   // namespace ApiHolders {

        template<class ApiCartridgesHolder, class ApiLabel>
        struct TestITypeNameMetadataApiAt : 
            Traits::ApiAt<ApiCartridgesHolder, Interfaces::TestITypeNameMetadataApiHolderLabel, ApiLabel>
        {
        };

        template<
            class TestITypeNameMetadataApiHolder
        >    
        class BaseTestITypeNameMetadata
        {
        public:
            typedef BaseTestITypeNameMetadata<TestITypeNameMetadataApiHolder> this_type;

            typedef typename TestITypeNameMetadataApiAt<TestITypeNameMetadataApiHolder, Interfaces::IModuleNameMetadataLabel>::type i_module_name_metadata_type;
            typedef typename TestITypeNameMetadataApiAt<TestITypeNameMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
            
            //template<class Derived, class T>
            //T const &Map() const { return const_cast<this_type *>(this)->Map<Derived, T>(); }

            //template<class Derived, class T>
            //T &Map() { return static_cast<Derived *>(this)->Map<T>(); }

            virtual std::wstring const &GetName() const = 0;
            virtual this_type const *GetBaseTypeName() const = 0;
            virtual i_module_name_metadata_type const &GetResolutionScope() const = 0;
            virtual i_type_metadata_type const *Resolve() const = 0;
        };

        template<class ApiCartridgesHolder, class ApiLabel>
        struct TestTypeNameMetadataApiAt : 
            Traits::ApiAt<ApiCartridgesHolder, Interfaces::TestTypeNameMetadataApiHolderLabel, ApiLabel>
        {
        };

        template<
            class TestTypeNameMetadataApiHolder
        >    
        class BaseTestTypeNameMetadata : 
            public TestTypeNameMetadataApiAt<TestTypeNameMetadataApiHolder, Interfaces::TestITypeNameMetadataLabel>::type
        {
        public:
            typedef BaseTestTypeNameMetadata<TestTypeNameMetadataApiHolder> this_type;
            typedef typename TestTypeNameMetadataApiAt<TestTypeNameMetadataApiHolder, Interfaces::TestITypeNameMetadataLabel>::type base_type;
        
            BaseTestTypeNameMetadata() : 
                m_name(L"Hoge!!")
            { }

            //template<class T>
            //T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

            //template<class T>
            //T &Map() { BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException()); }
      
            //template<>
            //this_type const &Map<this_type>() const { const_cast<this_type *>(this)->Map<this_type>(); }
      
            //template<>
            //this_type &Map<this_type>() { return *this; }

            std::wstring const &GetName() const
            {
                return m_name;
            }

            typename base_type::this_type const *GetBaseTypeName() const
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }

            typename base_type::i_module_name_metadata_type const &GetResolutionScope() const
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }

            typename base_type::i_type_metadata_type const *Resolve() const
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }

        private:
            std::wstring m_name;
        };

    }   // namespace 45DD35FD {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, Inheritance_Test_01)
    {
        using namespace _45DD35FD;

        TestTypeNameMetadata typeMeta1;
        TestITypeNameMetadata &typeMeta2 = typeMeta1;
        typeMeta2.GetName();
        //typeMeta2.GetBaseTypeName();
        //typeMeta2.GetResolutionScope();
        //typeMeta2.Resolve();
        TestTypeNameMetadata &typeMeta3 = static_cast<TestTypeNameMetadata &>(typeMeta2);

        ASSERT_TRUE(&typeMeta1 == &typeMeta3);
        ASSERT_STREQ(L"Hoge!!", typeMeta3.GetName().c_str());
    };

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, TypeInfo_Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Utilities;

        TypeInfo t1 = mpl::identity<int>();
        TypeInfo t2 = mpl::identity<int>();
        TypeInfo t3 = mpl::identity<double>();

        ASSERT_TRUE(t1 == t2);
        ASSERT_FALSE(t1 == t3);

        std::vector<TypeInfo> typeInfos;
        typeInfos.push_back(t1);
        typeInfos.push_back(t2);
        typeInfos.push_back(t3);

        TypeInfo t4 = mpl::identity<double>();
        std::vector<TypeInfo>::iterator result = std::find(typeInfos.begin(), typeInfos.end(), t4);
        ASSERT_FALSE(result == typeInfos.end());
        ASSERT_TRUE((*result).Is<double>());
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, StrongNaming_Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        //::_CrtSetBreakAlloc(5404);

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");

        StrongNameInfo const &snInfo = pRuntimeHost->Map<StrongNameInfo>();
        
        StrongNameKey const *pSnKey = NULL;
        pSnKey = snInfo.GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        std::vector<BYTE> const &publicKey = pSnKey->GetPublicKey();

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x19, 0xc4, 0x67, 0xdf, 0x70, 0xd1, 0xae, 0xf6, 
            0x96, 0x95, 0xf6, 0x8e, 0x65, 0xaf, 0x52, 0x46, 
            0x0b, 0x8e, 0x00, 0x94, 0x1f, 0x4a, 0x17, 0x5f, 
            0x4d, 0xf8, 0xd3, 0x70, 0x9f, 0x1a, 0x32, 0xd9, 
            0xf3, 0xff, 0xf6, 0xfd, 0x68, 0xb8, 0x79, 0xdc, 
            0x3d, 0xad, 0x60, 0x63, 0x2a, 0x9b, 0x6d, 0x9a, 
            0x5f, 0xc1, 0x9e, 0xf8, 0xb9, 0xd9, 0xae, 0x7a, 
            0xe9, 0xfe, 0x2a, 0xf2, 0x5e, 0x29, 0x02, 0x1b, 
            0xa2, 0x66, 0xad, 0x0b, 0x83, 0x7f, 0xc8, 0x22, 
            0x2f, 0xf5, 0x51, 0x55, 0x67, 0x68, 0xa1, 0x1b, 
            0xae, 0x1d, 0xe5, 0xf7, 0xca, 0xad, 0xf8, 0xc7, 
            0x78, 0x19, 0xfc, 0xfb, 0x8b, 0x3b, 0x73, 0x0b, 
            0x38, 0xe1, 0xeb, 0xcd, 0x68, 0x3d, 0x12, 0xdd, 
            0x87, 0x4f, 0x42, 0x8f, 0xbb, 0x0d, 0xb5, 0xd6, 
            0x92, 0xda, 0xfa, 0x66, 0xa3, 0xe3, 0x6a, 0x8b, 
            0x28, 0xb2, 0x36, 0xb8, 0xde, 0x56, 0x07, 0xda
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);

        ASSERT_EQ(148, publicKey.size());
        for (UINT i = 0; i < publicKey.size(); ++i)
            ASSERT_EQ(PUB_KEY_BLOB[PUB_KEY_BLOB_SIZE - publicKey.size() + i], publicKey[i]);
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, StrongNaming_Test_02)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");

        StrongNameInfo const &snInfo = pRuntimeHost->Map<StrongNameInfo>();
        
        StrongNameKey const *pSnKey = NULL;
        pSnKey = snInfo.GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        std::vector<BYTE> const &publicKeyToken = pSnKey->GetPublicKeyToken();

        BYTE const PUB_KEY_TOKEN[] = { 0xf3, 0xc5, 0xad, 0xb8, 0x52, 0x21, 0xac, 0x4f };

        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, Test_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        HostInfo hostInfo;
        RuntimeHost const *pRuntimeHost = hostInfo.GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost != NULL);

        MetadataInfo const &metaInfo = pRuntimeHost->Map<MetadataInfo>();

        MetadataDispenser *pMetaDisp = metaInfo.CreateDispenser();
        ASSERT_TRUE(pMetaDisp != NULL);
        
        AssemblyMetadata const *pSystemCore = NULL;
        pSystemCore = pMetaDisp->LoadAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                              L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_TRUE(pSystemCore != NULL);
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());

        AssemblyMetadata const *pMSCorLib = NULL;
        pMSCorLib = pMetaDisp->LoadAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                            L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        ASSERT_TRUE(pMSCorLib != NULL);
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        ModuleMetadata const *pSystemCoreModule = NULL;
        pSystemCoreModule = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_TRUE(pSystemCoreModule != NULL);
        ASSERT_EQ(0x00000001, pSystemCoreModule->GetToken());

        ModuleMetadata const *pMSCorLibModule = NULL;
        pMSCorLibModule = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_TRUE(pMSCorLibModule != NULL);
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        TypeMetadata const *pVoid = pMSCorLibModule->GetType(L"System.Void");
        ASSERT_TRUE(pVoid != NULL);
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        TypeMetadata const *pObject = pMSCorLibModule->GetType(L"System.Object");
        ASSERT_TRUE(pObject != NULL);
        ASSERT_EQ(0x02000002, pObject->GetToken());
        
        TypeMetadata const *pIntPtr = pMSCorLibModule->GetType(L"System.IntPtr");
        ASSERT_TRUE(pIntPtr != NULL);
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        TypeMetadata const *pDateTime = pMSCorLibModule->GetType(L"System.DateTime");
        ASSERT_TRUE(pDateTime != NULL);
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        TypeMetadata const *pFunc1 = pSystemCoreModule->GetType(L"System.Func`1");
        ASSERT_TRUE(pFunc1 != NULL);
        ASSERT_TRUE(pFunc1->IsGenericType());
        ASSERT_TRUE(pFunc1->IsGenericTypeDefinition());
        {
            std::vector<TypeMetadata const *> const &genericArgs = pFunc1->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (UINT i = 0; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_TRUE(genericArgs[i]->IsGenericParameter());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1->GetToken());

        TypeMetadata const *pFunc1DateTime = NULL;
        {
            std::vector<TypeMetadata const *> genericArgs;
            genericArgs.push_back(pDateTime);
            pFunc1DateTime = pFunc1->MakeGenericType(genericArgs);
        }
        ASSERT_TRUE(pFunc1DateTime != NULL);
        ASSERT_TRUE(pFunc1DateTime->IsGenericType());
        ASSERT_FALSE(pFunc1DateTime->IsGenericTypeDefinition());
        {
            std::vector<TypeMetadata const *> const &genericArgs = pFunc1DateTime->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (UINT i = 0; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_FALSE(genericArgs[i]->IsGenericParameter());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1DateTime->GetToken());   // !! CAUTION: This is CORRECT !!

        MethodMetadata const *pFunc1DateTimector = NULL;
        {
            std::vector<ITypeMetadata const *> params;
            params.push_back(pObject);
            params.push_back(pIntPtr);
            pFunc1DateTimector = pFunc1DateTime->GetMethod(L".ctor", CallingConventions::CC_HAS_THIS, *pVoid, params);
        }
        ASSERT_TRUE(pFunc1DateTimector != NULL);
        ASSERT_EQ(0x06000232, pFunc1DateTimector->GetToken());   // !! CAUTION: This is CORRECT !!

        MethodMetadata const *pget_UtcNow = NULL;
        {
            std::vector<ITypeMetadata const *> params;
            pget_UtcNow = pDateTime->GetMethod(L"get_UtcNow", CallingConventions::CC_STANDARD, *pDateTime, params);
        }
        ASSERT_TRUE(pget_UtcNow != NULL);
        ASSERT_EQ(0x060002D3, pget_UtcNow->GetToken());

        MethodMetadata const *pToLocalTime = NULL;
        {
            std::vector<ITypeMetadata const *> params;
            pToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, *pDateTime, params);
        }
        ASSERT_TRUE(pToLocalTime != NULL);
        ASSERT_EQ(0x060002E7, pToLocalTime->GetToken());




#if 0
        StrongNameInfo const &snInfo = pRuntimeHost->Map<StrongNameInfo>();

        AssemblyNameMetadataGenerator *pMSCorLibPrigNameGen = NULL;
        pMSCorLibPrigNameGen = pMetaDisp->NewAssemblyNameGenerator(L"mscorlib.Prig");
        StrongNameKey const *pSnKey = NULL;
        pSnKey = snInfo.GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        pMSCorLibPrigNameGen->SetStrongNameKey(*pSnKey);
        ASSERT_TRUE(pMSCorLibPrigNameGen != NULL);
        ASSERT_STREQ(L"mscorlib.Prig", pMSCorLibPrigNameGen->GetName().c_str());
        ASSERT_TRUE(pMSCorLibPrigNameGen->GetStrongNameKey() != NULL);

        ModuleNameMetadataGenerator *pMSCorLibPrigNameModuleGen = NULL;
        pMSCorLibPrigNameModuleGen = pMSCorLibPrigNameGen->NewModuleNameGenerator(L"mscorlib.Prig.dll");
        ASSERT_TRUE(pMSCorLibPrigNameModuleGen != NULL);
        ASSERT_STREQ(L"mscorlib.Prig.dll", pMSCorLibPrigNameModuleGen->GetName().c_str());

        TypeNameMetadataGenerator *pPDateTimeNameGen = NULL;
        pPDateTimeNameGen = pMSCorLibPrigNameModuleGen->NewTypeNameGenerator(L"System.Prig.PDateTime",
                                                                             TypeAttributes::TA_PUBLIC | 
                                                                             TypeAttributes::TA_ABSTRACT | 
                                                                             TypeAttributes::TA_ANSI_CLASS | 
                                                                             TypeAttributes::TA_SEALED | 
                                                                             TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_TRUE(pPDateTimeNameGen != NULL);
        ASSERT_STREQ(L"System.Prig.PDateTime", pPDateTimeNameGen->GetName().c_str());
        ASSERT_TRUE((pPDateTimeNameGen->GetAttribute().Value() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_FALSE((pPDateTimeNameGen->GetAttribute().Value() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);

        TypeNameMetadataGenerator *pNowGetNameGen = NULL;
        pNowGetNameGen = pPDateTimeNameGen->NewNestedTypeNameGenerator(L"NowGet", 
                                                                       TypeAttributes::TA_ABSTRACT | 
                                                                       TypeAttributes::TA_ANSI_CLASS | 
                                                                       TypeAttributes::TA_SEALED | 
                                                                       TypeAttributes::TA_NESTED_PUBLIC | 
                                                                       TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_TRUE(pNowGetNameGen != NULL);
        ASSERT_STREQ(L"NowGet", pNowGetNameGen->GetName().c_str());
        ASSERT_TRUE((pNowGetNameGen->GetAttribute().Value() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_TRUE((pNowGetNameGen->GetAttribute().Value() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);
        
        FieldNameMetadataGenerator *pm_bodyNameGen = NULL;
        pm_bodyNameGen = pPDateTimeNameGen->NewFieldNameGenerator(L"m_body", 
                                                                  *pFunc1DateTime, 
                                                                  FieldAttributes::FA_PRIVATE | 
                                                                  FieldAttributes::FA_STATIC);
        ASSERT_TRUE(pm_bodyNameGen != NULL);
        ASSERT_STREQ(L"m_body", pm_bodyNameGen->GetName().c_str());
        ASSERT_TRUE(&pm_bodyNameGen->GetFieldTypeName().Resolve() == pFunc1DateTime);
        ASSERT_TRUE((pm_bodyNameGen->GetAttribute().Value() & FieldAttributes::FA_PRIVATE) == FieldAttributes::FA_PRIVATE);
        ASSERT_FALSE((pm_bodyNameGen->GetAttribute().Value() & FieldAttributes::FA_PUBLIC) == FieldAttributes::FA_PUBLIC);

        MethodNameMetadataGenerator *pget_BodyNameGen = NULL;
        pget_BodyNameGen = pPDateTimeNameGen->NewMethodNameGenerator(L"get_Body", 
                                                                     CallingConventions::CC_STANDARD, 
                                                                     *pFunc1DateTime, 
                                                                     std::vector<ITypeMetadata const *>(), 
                                                                     MethodAttributes::MA_PUBLIC | 
                                                                     MethodAttributes::MA_HIDE_BY_SIG | 
                                                                     MethodAttributes::MA_SPECIAL_NAME | 
                                                                     MethodAttributes::MA_STATIC);
        ASSERT_TRUE(pget_BodyNameGen != NULL);
        ASSERT_STREQ(L"get_Body", pget_BodyNameGen->GetName().c_str());
        ASSERT_EQ(CallingConventions::CC_STANDARD, pget_BodyNameGen->GetCallingConvention().Value());
        ASSERT_TRUE(&pget_BodyNameGen->GetReturnTypeName().Resolve() == pFunc1DateTime);
        ASSERT_EQ(0, pget_BodyNameGen->GetParameterTypeNames().size());
        ASSERT_TRUE((pget_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pget_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        std::vector<ITypeMetadata const *> set_BodyParams;
        set_BodyParams.push_back(pFunc1DateTime);
        MethodNameMetadataGenerator *pset_BodyNameGen = NULL;
        pset_BodyNameGen = pPDateTimeNameGen->NewMethodNameGenerator(L"set_Body",
                                                                     CallingConventions::CC_STANDARD, 
                                                                     *pVoid, 
                                                                     set_BodyParams, 
                                                                     MethodAttributes::MA_PUBLIC | 
                                                                     MethodAttributes::MA_HIDE_BY_SIG | 
                                                                     MethodAttributes::MA_SPECIAL_NAME | 
                                                                     MethodAttributes::MA_STATIC);
        ASSERT_TRUE(pset_BodyNameGen != NULL);
        ASSERT_STREQ(L"set_Body", pset_BodyNameGen->GetName().c_str());
        ASSERT_EQ(CallingConventions::CC_STANDARD, pset_BodyNameGen->GetCallingConvention().Value());
        ASSERT_TRUE(&pset_BodyNameGen->GetReturnTypeName().Resolve() == pVoid);
        ASSERT_EQ(1, pset_BodyNameGen->GetParameterTypeNames().size());
        ASSERT_TRUE((pset_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pset_BodyNameGen->GetAttribute().Value() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        PropertyNameMetadataGenerator *pBodyNameGen = NULL;
        pBodyNameGen = pPDateTimeNameGen->NewPropertyNameGenerator(L"Body", 
                                                                   *pFunc1DateTime, 
                                                                   std::vector<TypeMetadata const *>(), 
                                                                   PropertyAttributes::PA_NONE);
        pBodyNameGen->SetGetMethod(*pget_BodyNameGen);
        pBodyNameGen->SetSetMethod(*pset_BodyNameGen);
        ASSERT_TRUE(pBodyNameGen != NULL);
        ASSERT_STREQ(L"Body", pBodyNameGen->GetName().c_str());
        ASSERT_TRUE(&pBodyNameGen->GetPropertyType() == pFunc1DateTime);
        ASSERT_EQ(0, pBodyNameGen->GetParameterTypes().size());
        ASSERT_TRUE((pBodyNameGen->GetAttribute().Value() & PropertyAttributes::PA_NONE) == PropertyAttributes::PA_NONE);
        ASSERT_FALSE((pBodyNameGen->GetAttribute().Value() & PropertyAttributes::PA_SPECIAL_NAME) == PropertyAttributes::PA_SPECIAL_NAME);
        ASSERT_TRUE(pBodyNameGen->GetGetMethod() == pget_BodyNameGen);
        ASSERT_TRUE(pBodyNameGen->GetSetMethod() == pset_BodyNameGen);

        MethodNameMetadataGenerator *pNowGetcctorNameGen = NULL;
        pNowGetcctorNameGen = pNowGetNameGen->NewMethodNameGenerator(L".cctor", 
                                                                     CallingConventions::CC_STANDARD, 
                                                                     *pVoid, 
                                                                     std::vector<ITypeMetadata const *>(),
                                                                     MethodAttributes::MA_PUBLIC | 
                                                                     MethodAttributes::MA_HIDE_BY_SIG | 
                                                                     MethodAttributes::MA_SPECIAL_NAME | 
                                                                     MethodAttributes::MA_STATIC);
        
        MethodNameMetadataGenerator *pInitializeget_BodyNameGen = NULL;
        pInitializeget_BodyNameGen = pNowGetNameGen->NewMethodNameGenerator(L"Initializeget_Body", 
                                                                            CallingConventions::CC_STANDARD, 
                                                                            *pDateTime, 
                                                                            std::vector<ITypeMetadata const *>(), 
                                                                            MethodAttributes::MA_PUBLIC | 
                                                                            MethodAttributes::MA_HIDE_BY_SIG | 
                                                                            MethodAttributes::MA_SPECIAL_NAME | 
                                                                            MethodAttributes::MA_STATIC);

        {
            MethodBodyWriter &body = pget_BodyNameGen->GetMethodBody();
            body.Emit(OpCodes::Ldsfld, *pm_bodyNameGen);
            body.Emit(OpCodes::Ret);
            {
                std::vector<Instruction const *> const &insts = body.GetInstructions();
                ASSERT_EQ(2, insts.size());
                for (UINT i = 0; i < insts.size(); ++i)
                {
                    OpCode const &op = insts[i]->GetOpCode();
                    boost::any const &operand = insts[i]->GetOprand();
                    switch (i)
                    {
                        case 0:
                            ASSERT_EQ(&OpCodes::Ldsfld, &op);
                            ASSERT_EQ(pm_bodyNameGen, boost::any_cast<IFieldNameMetadata const *>(operand));
                            break;
                        case 1:
                            ASSERT_EQ(&OpCodes::Ret, &op);
                            ASSERT_TRUE(operand.empty());
                            break;
                        default:
                            FAIL() << "We shouldn't get here!!";
                    }
                }
            }
        }
        {
            MethodBodyWriter &body = pset_BodyNameGen->GetMethodBody();
            body.Emit(OpCodes::Ldarg_0);
            body.Emit(OpCodes::Stsfld, *pm_bodyNameGen);
            body.Emit(OpCodes::Ret);
        }
        {
            MethodBodyWriter &body = pNowGetcctorNameGen->GetMethodBody();
            body.Emit(OpCodes::Ldnull);
            body.Emit(OpCodes::Ldftn, *pInitializeget_BodyNameGen);
            body.Emit(OpCodes::Newobj, *pFunc1DateTimector);
            body.Emit(OpCodes::Stsfld, *pm_bodyNameGen);
            body.Emit(OpCodes::Ret);
        }
        {
            MethodBodyWriter &body = pInitializeget_BodyNameGen->GetMethodBody();
            LocalNameMetadataGenerator *p1 = NULL; 
            p1 = body.GetLocalsName().NewLocalNameMetadataGenerator(*pDateTime);
            body.Emit(OpCodes::Call, *pget_UtcNow);
            body.Emit(OpCodes::Stloc_0);
            body.Emit(OpCodes::Ldloca, 0x00);
            body.Emit(OpCodes::Call, *pToLocalTime);
            body.Emit(OpCodes::Ret);
        }

        pMSCorLibPrigNameGen->Save(L"mscorlib.Prig.dll", PortableExecutableKinds::PEK_IL_ONLY, ImageFileMachine::IFM_I386);
#endif
    }
}
