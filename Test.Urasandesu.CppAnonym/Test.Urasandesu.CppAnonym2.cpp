// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

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

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIAssemblyMetadata.hpp>
#endif

// foward declarations
namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    //struct IAssemblyMetadataApiHolderLabel { };
    //struct IAssemblyMetadataLabel { };
    //struct IAssemblyMetadataHashLabel { };
    //struct IAssemblyMetadataEqualToLabel { };

    struct IModuleMetadataApiHolderLabel { };
    struct IModuleMetadataLabel { };
    struct IModuleMetadataHashLabel { };
    struct IModuleMetadataEqualToLabel { };

    struct ITypeMetadataApiHolderLabel { };
    struct ITypeMetadataLabel { };
    struct ITypeMetadataHashLabel { };
    struct ITypeMetadataEqualToLabel { };

    struct IMethodMetadataApiHolderLabel { };
    struct IMethodMetadataLabel { };
    struct IMethodMetadataHashLabel { };
    struct IMethodMetadataEqualToLabel { };

    struct MetadataInfoApiHolderLabel { };
    //struct MetadataInfoLabel { };

    struct MetadataDispenserApiHolderLabel { };
    //struct MetadataDispenserLabel { };

    struct AssemblyMetadataApiHolderLabel { };
    struct AssemblyMetadataLabel { };

    struct ModuleMetadataApiHolderLabel { };
    struct ModuleMetadataLabel { };

    struct TypeMetadataApiHolderLabel { };
    struct TypeMetadataLabel { };

    struct MethodMetadataApiHolderLabel { };
    struct MethodMetadataLabel { };

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

    //struct DefaultIAssemblyMetadataApiHolder;

    struct DefaultIModuleMetadataApiHolder;

    struct DefaultITypeMetadataApiHolder;

    struct DefaultIMethodMetadataApiHolder;

    struct DefaultMetadataInfoApiHolder;

    struct DefaultMetadataDispenserApiHolder;

    struct DefaultAssemblyMetadataApiHolder;

    struct DefaultModuleMetadataApiHolder;

    struct DefaultTypeMetadataApiHolder;

    struct DefaultMethodMetadataApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    //template<
    //    class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    //>    
    //class BaseIAssemblyMetadata;

    //typedef BaseIAssemblyMetadata<> IAssemblyMetadata;




    //
    //template<
    //    class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    //>    
    //class BaseIAssemblyMetadataHash;

    //typedef BaseIAssemblyMetadataHash<> IAssemblyMetadataHash;

    //
    //
    //
    //
    //template<
    //    class IAssemblyMetadataApiHolder = ApiHolders::DefaultIAssemblyMetadataApiHolder
    //>    
    //class BaseIAssemblyMetadataEqualTo;

    //typedef BaseIAssemblyMetadataEqualTo<> IAssemblyMetadataEqualTo;





    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadata;

    typedef BaseIModuleMetadata<> IModuleMetadata;




    
    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataHash;

    typedef BaseIModuleMetadataHash<> IModuleMetadataHash;

    
    
    
    
    template<
        class IModuleMetadataApiHolder = ApiHolders::DefaultIModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataEqualTo;

    typedef BaseIModuleMetadataEqualTo<> IModuleMetadataEqualTo;





    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadata;

    typedef BaseITypeMetadata<> ITypeMetadata;




    
    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadataHash;

    typedef BaseITypeMetadataHash<> ITypeMetadataHash;

    
    
    
    
    template<
        class ITypeMetadataApiHolder = ApiHolders::DefaultITypeMetadataApiHolder
    >    
    class BaseITypeMetadataEqualTo;

    typedef BaseITypeMetadataEqualTo<> ITypeMetadataEqualTo;





    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadata;

    typedef BaseIMethodMetadata<> IMethodMetadata;




    
    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataHash;

    typedef BaseIMethodMetadataHash<> IMethodMetadataHash;

    
    
    
    
    template<
        class IMethodMetadataApiHolder = ApiHolders::DefaultIMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataEqualTo;

    typedef BaseIMethodMetadataEqualTo<> IMethodMetadataEqualTo;

    
    
    
    
    template<
        class MetadataInfoApiHolder = ApiHolders::DefaultMetadataInfoApiHolder
    >    
    class BaseMetadataInfo;

    typedef BaseMetadataInfo<> MetadataInfo;





    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser;

    typedef BaseMetadataDispenser<> MetadataDispenser;





    template<
        class AssemblyMetadataApiHolder = ApiHolders::DefaultAssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata;

    typedef BaseAssemblyMetadata<> AssemblyMetadata;





    template<
        class ModuleMetadataApiHolder = ApiHolders::DefaultModuleMetadataApiHolder
    >    
    class BaseModuleMetadata;

    typedef BaseModuleMetadata<> ModuleMetadata;





    template<
        class TypeMetadataApiHolder = ApiHolders::DefaultTypeMetadataApiHolder
    >    
    class BaseTypeMetadata;

    typedef BaseTypeMetadata<> TypeMetadata;





    template<
        class MethodMetadataApiHolder = ApiHolders::DefaultMethodMetadataApiHolder
    >    
    class BaseMethodMetadata;

    typedef BaseMethodMetadata<> MethodMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

    struct FusionInfoApiHolderLabel { };
    //struct FusionInfoLabel { };

    struct AssemblyInfoApiHolderLabel { };
    struct AssemblyInfoLabel { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

    struct DefaultFusionInfoApiHolder;

    struct DefaultAssemblyInfoApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<
        class FusionInfoApiHolder = ApiHolders::DefaultFusionInfoApiHolder
    >    
    class BaseFusionInfo;

    typedef BaseFusionInfo<> FusionInfo;





    template<
        class AssemblyInfoApiHolder = ApiHolders::DefaultAssemblyInfoApiHolder
    >    
    class BaseAssemblyInfo;

    typedef BaseAssemblyInfo<> AssemblyInfo;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {





namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    //namespace Detail {

    //    using namespace boost::mpl;
    //    using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
    //    using namespace Urasandesu::CppAnonym::StrongNaming;
    //    using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;

    //    struct DefaultIAssemblyMetadataApiHolderImpl
    //    {
    //        typedef map<
    //            pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
    //            pair<MetadataDispenserLabel, MetadataDispenser>
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    //struct DefaultIAssemblyMetadataApiHolder : 
    //    Detail::DefaultIAssemblyMetadataApiHolderImpl
    //{
    //};





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIModuleMetadataApiHolderImpl
        {
            typedef map<
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<IAssemblyMetadataHashLabel, IAssemblyMetadataHash>,
                pair<IAssemblyMetadataEqualToLabel, IAssemblyMetadataEqualTo>
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

        struct DefaultITypeMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>
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

        struct DefaultIMethodMetadataApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataLabel, ITypeMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIMethodMetadataApiHolder : 
        Detail::DefaultIMethodMetadataApiHolderImpl
    {
    };

    
    
    
    
    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<MetadataDispenserLabel, MetadataDispenser>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMetadataInfoApiHolder : 
        Detail::DefaultMetadataInfoApiHolderImpl
    {
    };





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
                pair<MethodMetadataLabel, MethodMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMetadataDispenserApiHolder : 
        Detail::DefaultMetadataDispenserApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion;

        struct DefaultAssemblyMetadataApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<AssemblyInfoLabel, AssemblyInfo>,
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>,
                pair<IModuleMetadataEqualToLabel, IModuleMetadataEqualTo>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<MethodMetadataLabel, MethodMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultAssemblyMetadataApiHolder : 
        Detail::DefaultAssemblyMetadataApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultModuleMetadataApiHolderImpl
        {
            typedef map<
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>,
                pair<MetadataDispenserLabel, MetadataDispenser>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultModuleMetadataApiHolder : 
        Detail::DefaultModuleMetadataApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<ModuleMetadataLabel, ModuleMetadata>,
                pair<MethodMetadataLabel, MethodMetadata>,
                pair<IMethodMetadataHashLabel, IMethodMetadataHash>,
                pair<IMethodMetadataEqualToLabel, IMethodMetadataEqualTo>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultTypeMetadataApiHolder : 
        Detail::DefaultTypeMetadataApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMethodMetadataApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<TypeMetadataLabel, TypeMetadata>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultMethodMetadataApiHolder : 
        Detail::DefaultMethodMetadataApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct SignatureUtil
    {
        template<class SignatureHolder>
        static void PutSignatures(SimpleBlob &sb, SignatureHolder const &sigHolder)
        {
            typedef std::vector<COR_SIGNATURE>::const_iterator Iterator;
            std::vector<COR_SIGNATURE> const &sigs = sigHolder.GetSignatures();
            for (Iterator i = sigs.cbegin(), i_end = sigs.cend(); i != i_end; ++i)
                sb.Put<COR_SIGNATURE>(*i);
        }
    };

    
    
    
    
    //template<class ApiCartridgesHolder, class ApiLabel>
    //struct IAssemblyMetadataApiAt : 
    //    Traits::ApiAt<ApiCartridgesHolder, Interfaces::IAssemblyMetadataApiHolderLabel, ApiLabel>
    //{
    //};

    //template<
    //    class IAssemblyMetadataApiHolder
    //>    
    //class BaseIAssemblyMetadata
    //{
    //public:
    //    typedef BaseIAssemblyMetadata<IAssemblyMetadataApiHolder> this_type;

    //    typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;
    //    typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
    //    typedef typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

    //    virtual mdAssembly GetToken() const = 0;
    //    virtual std::wstring const &GetName() const = 0;
    //    virtual boost::shared_ptr<strong_name_key_type const> GetStrongNameKey() const = 0;
    //    virtual boost::shared_ptr<metadata_dispenser_type const> GetResolutionScope() const = 0;
    //};




    //
    //template<
    //    class IAssemblyMetadataApiHolder
    //>    
    //class BaseIAssemblyMetadataHash : 
    //    Traits::HashComputable<boost::shared_ptr<typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type const> >
    //{
    //public:
    //    result_type operator()(param_type v) const
    //    {
    //        using namespace boost;
    //        using namespace Urasandesu::CppAnonym::Utilities;

    //        _ASSERTE(v);

    //        std::size_t seed = 0;
    //        hash_combine(seed, hash_value(v->GetName()));
    //        hash_combine(seed, HashValue(v->GetResolutionScope().get()));
    //        return seed;
    //    }
    //};

    //
    //
    //
    //
    //template<
    //    class IAssemblyMetadataApiHolder
    //>    
    //class BaseIAssemblyMetadataEqualTo : 
    //    Traits::EqualityComparable<boost::shared_ptr<typename IAssemblyMetadataApiAt<IAssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type const> >
    //{
    //public:
    //    result_type operator()(param_type x, param_type y) const
    //    {
    //        _ASSERTE(x && y);

    //        return x->GetName() == y->GetName() &&
    //               x->GetResolutionScope() == y->GetResolutionScope();
    //    }
    //};





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

        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type i_assembly_metadata_type;

        virtual mdModule GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<i_assembly_metadata_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type const> >
    {
    public:
        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataHashLabel>::type i_assembly_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_assembly_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IModuleMetadataApiHolder
    >    
    class BaseIModuleMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type const> >
    {
    public:
        typedef typename IModuleMetadataApiAt<IModuleMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x && y);

            return x->GetName() == y->GetName() &&
                   i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
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

        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type i_module_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<this_type const> GetBaseType() const = 0;
        virtual boost::shared_ptr<i_module_metadata_type const> GetResolutionScope() const = 0;
        virtual std::vector<COR_SIGNATURE> const &GetSignatures() const = 0;
        virtual bool IsGenericParameter() const = 0;
    };




    
    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type const> >
    {
    public:
        typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IModuleMetadataHashLabel>::type i_module_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_module_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class ITypeMetadataApiHolder
    >    
    class BaseITypeMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type const> >
    {
    public:
        //typedef typename ITypeMetadataApiAt<ITypeMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
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

        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type i_method_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual CallingConventions const &GetCallingConvention() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetReturnType() const = 0;
        virtual std::vector<boost::shared_ptr<i_type_metadata_type const> > const &GetParameterTypes() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type const> >
    {
    public:
        typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Collections;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, v->GetCallingConvention().Value());
            hash_combine(seed, i_type_metadata_hash_type()(v->GetReturnType()));
            hash_combine(seed, SequenceHashValue(v->GetParameterTypes().cbegin(), 
                                                 v->GetParameterTypes().cend(), 
                                                 i_type_metadata_hash_type()));
            hash_combine(seed, i_type_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IMethodMetadataApiHolder
    >    
    class BaseIMethodMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type const> >
    {
    public:
        //typedef typename IMethodMetadataApiAt<IMethodMetadataApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x && y);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
        }
    };

    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataInfoApiHolder
    >    
    class BaseMetadataInfo : 
        public SmartPtrChain<
            BaseMetadataInfo<MetadataInfoApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataInfo<MetadataInfoApiHolder> this_type;

        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename MetadataInfoApiAt<MetadataInfoApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        typedef typename provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;

        typedef typename chain_from<runtime_host_type>::type metadata_info_chain_type; 

        BaseMetadataInfo()
        { }

        boost::shared_ptr<metadata_dispenser_type> CreateDispenser() const
        {
            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            boost::shared_ptr<metadata_dispenser_type> pDisp = NewDispenser();
            provider.Register(pDisp);
            return pDisp;
        }

    private:
        friend typename runtime_host_type;

        boost::shared_ptr<metadata_dispenser_type> NewDispenser() const
        {
            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            metadata_info_chain_type &chain = ChainFrom<runtime_host_type>();
            return chain.NewObject<metadata_dispenser_type>(provider);
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenserApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataDispenserApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser : 
        public SmartPtrChain<
            BaseMetadataDispenser<MetadataDispenserApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type,
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataLabel>::type,
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type,
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataDispenser<MetadataDispenserApiHolder> this_type;

        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::IAssemblyMetadataHashLabel>::type i_assembly_metadata_hash_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;

        typedef typename provider_of<assembly_metadata_type>::type assembly_metadata_provider_type;
        typedef typename provider_of<module_metadata_type>::type module_metadata_provider_type;
        typedef typename provider_of<type_metadata_type>::type type_metadata_provider_type;
        typedef typename provider_of<method_metadata_type>::type method_metadata_provider_type;

        typedef typename chain_from<metadata_info_type>::type metadata_dispenser_chain_type; 

        BaseMetadataDispenser()
        { }

        boost::shared_ptr<assembly_metadata_type const> GetAssembly(std::wstring const &fullName) const
        {
            boost::shared_ptr<assembly_metadata_type> pNewAsm;
            pNewAsm = NewAssembly(fullName);

            boost::shared_ptr<assembly_metadata_type> pExistingAsm;
            if (!TryGetAssembly(*pNewAsm, pExistingAsm))
            {
                assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
                m_asmToIndex[pNewAsm] = provider.Register(pNewAsm);
                return pNewAsm;
            }
            else
            {
                return pExistingAsm;
            }
        }

    private:
        friend typename metadata_info_type;
        friend typename assembly_metadata_type;

        boost::shared_ptr<assembly_metadata_type> NewAssembly(std::wstring const &fullName) const
        {
            assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
            metadata_dispenser_chain_type &chain = ChainFrom<metadata_info_type>();
            boost::shared_ptr<assembly_metadata_type> pAsm = chain.NewObject<assembly_metadata_type>(provider);
            pAsm->SetName(fullName);
            return pAsm;
        }

        bool TryGetAssembly(assembly_metadata_type const &keyAsm, boost::shared_ptr<assembly_metadata_type> &pExistingAsm) const
        {
            boost::shared_ptr<assembly_metadata_type const> pKeyAsm(&keyAsm, Utilities::MakeNullDeleter(&keyAsm));
            if (m_asmToIndex.find(pKeyAsm) == m_asmToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_asmToIndex[pKeyAsm];
                assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
                pExistingAsm = provider[index];
                return true;
            }
        }

        com_meta_data_dispenser_type &GetCOMMetaDataDispenser()
        {
            if (m_pComMetaDisp.p == NULL)
            {
                HRESULT hr = ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, 
                                                IID_IMetaDataDispenserEx, 
                                                reinterpret_cast<void **>(&m_pComMetaDisp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaDisp;
        }

        mutable boost::unordered_map<boost::shared_ptr<assembly_metadata_type const>, 
                                     size_t, 
                                     i_assembly_metadata_hash_type, 
                                     i_assembly_metadata_equal_to_type> m_asmToIndex;
        mutable ATL::CComPtr<com_meta_data_dispenser_type> m_pComMetaDisp;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyMetadataApiHolder
    >    
    class BaseAssemblyMetadata : 
        public SmartPtrChain<
            BaseAssemblyMetadata<AssemblyMetadataApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type>
            >
        >,
        public AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseAssemblyMetadata<AssemblyMetadataApiHolder> this_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IAssemblyMetadataLabel>::type base_type;

        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;        
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Fusion::Interfaces::AssemblyInfoLabel>::type assembly_info_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IModuleMetadataHashLabel>::type i_module_metadata_hash_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::IModuleMetadataEqualToLabel>::type i_module_metadata_equal_to_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;        
        
        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Asm, module_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Asm, module_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Asm, module_metadata_provider_type, typename base_type::metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Asm, module_metadata_provider_type, typename base_type::metadata_dispenser_type), 
            boost::mpl::void_
        >::type module_metadata_provider_type;
        
        typedef typename chain_from<typename base_type::metadata_dispenser_type>::type assembly_metadata_chain_type; 

        BaseAssemblyMetadata() : 
            m_mda(mdAssemblyNil),
            m_openFlags(ofRead)
        { }

        mdAssembly GetToken() const
        {
            if (m_mda == mdAssemblyNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                com_meta_data_assembly_import_type &comMetaAsmImp = pMutableThis->GetCOMMetaDataAssemblyImport();
                HRESULT hr = comMetaAsmImp.GetAssemblyFromScope(&m_mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }

            return m_mda;
        }
        
        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }
        
        boost::shared_ptr<typename base_type::strong_name_key_type const> GetStrongNameKey() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }
        
        boost::shared_ptr<typename base_type::metadata_dispenser_type const> GetResolutionScope() const
        {
            return MapFirst<typename base_type::metadata_dispenser_type>();
        }

        boost::shared_ptr<module_metadata_type const> GetModule(std::wstring const &name) const
        {
            boost::shared_ptr<module_metadata_type> pMod;
            pMod = NewModule(name);

            boost::shared_ptr<module_metadata_type> pExistingMod;
            if (!TryGetModule(*pMod, pExistingMod))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
                m_modToIndex[pMod] = provider.Register(pMod);
                return pMod;
            }
            else
            {
                return pExistingMod;
            }
        }

    private:
        friend typename base_type::metadata_dispenser_type;
        friend typename module_metadata_type;
        friend typename type_metadata_type;
        friend typename method_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        boost::shared_ptr<module_metadata_type> NewModule(std::wstring const &name) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
            assembly_metadata_chain_type &chain = ChainFrom<typename base_type::metadata_dispenser_type>();
            boost::shared_ptr<module_metadata_type> pMod = chain.NewObject<module_metadata_type>(provider);
            pMod->SetName(name);
            return pMod;
        }

        bool TryGetModule(module_metadata_type const &keyMod, boost::shared_ptr<module_metadata_type> &pExistingMod) const
        {
            boost::shared_ptr<module_metadata_type const> pKeyMod(&keyMod, Utilities::MakeNullDeleter(&keyMod));
            if (m_modToIndex.find(pKeyMod) == m_modToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_modToIndex[pKeyMod];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                module_metadata_provider_type &provider = pDisp->ProviderOf<module_metadata_type>();
                pExistingMod = provider[index];
                return true;
            }
        }

        com_meta_data_assembly_import_type &GetCOMMetaDataAssemblyImport()
        {
            if (m_pComMetaAsmImp.p == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                
                com_meta_data_import_type &comMetaImp = pMutableThis->GetCOMMetaDataImport();
                HRESULT hr = comMetaImp.QueryInterface(IID_IMetaDataAssemblyImport, 
                                               reinterpret_cast<void **>(&m_pComMetaAsmImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaAsmImp;
        }

        com_meta_data_import_type &GetCOMMetaDataImport()
        {
            namespace fs = boost::filesystem;

            if (m_pComMetaImp.p == NULL)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                boost::shared_ptr<metadata_dispenser_type> pMetaDisp;
                pMetaDisp = pMutableThis->MapFirst<metadata_dispenser_type>();

                com_meta_data_dispenser_type &comMetaDisp = pMetaDisp->GetCOMMetaDataDispenser();

                fs::path const &asmPath = GetAssemblyFilePath();
                DWORD openFlags = GetOpenFlags();
                REFIID riid = GetCOMMetaDataImportIID();
                HRESULT hr = comMetaDisp.OpenScope(asmPath.c_str(), openFlags, 
                                                   riid, reinterpret_cast<IUnknown **>(&m_pComMetaImp));
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComMetaImp.p;
        }

        boost::filesystem::path const &GetAssemblyFilePath() const
        {
            using namespace Urasandesu::CppAnonym::Fusion;

            if (m_asmPath.empty())
            {
                _ASSERTE(!m_name.empty());

                boost::shared_ptr<fusion_info_type const> pFuInfo;
                pFuInfo = Map<fusion_info_type>();
                boost::shared_ptr<assembly_info_type> pAsmInfo;
                pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, m_name);
                m_asmPath = pAsmInfo->GetAssemblyPath();
            }
            return m_asmPath;
        }

        void SetAssemblyFilePath(boost::filesystem::path const &asmPath)
        {
            _ASSERTE(!asmPath.empty());
            _ASSERTE(m_asmPath.empty());
            
            m_asmPath = asmPath;
        }

        DWORD GetOpenFlags() const
        {
            return m_openFlags;
        }

        void SetOpenFlags(DWORD openFlags)
        {
            _ASSERTE(openFlags != ofRead);
            _ASSERTE(m_openFlags == ofRead);

            m_openFlags = openFlags;
        }

        REFIID GetCOMMetaDataImportIID()
        {
            return IID_IMetaDataImport2;
        }

        mutable mdAssembly m_mda;
        std::wstring m_name;
        mutable boost::filesystem::path m_asmPath;
        DWORD m_openFlags;
        mutable ATL::CComPtr<com_meta_data_assembly_import_type> m_pComMetaAsmImp;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pComMetaImp;
        mutable boost::unordered_map<boost::shared_ptr<module_metadata_type const>, 
                                     size_t, 
                                     i_module_metadata_hash_type, 
                                     i_module_metadata_equal_to_type> m_modToIndex;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleMetadataApiHolder
    >    
    class BaseModuleMetadata : 
        public SmartPtrChain<
            BaseModuleMetadata<ModuleMetadataApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type>
            >
        >,
        public ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseModuleMetadata<ModuleMetadataApiHolder> this_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::IModuleMetadataLabel>::type base_type;

        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::ITypeMetadataEqualToLabel>::type i_type_metadata_equal_to_type;
        typedef typename ModuleMetadataApiAt<ModuleMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Mod, type_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Mod, type_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Mod, type_metadata_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Mod, type_metadata_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type type_metadata_provider_type;

        typedef typename chain_from<assembly_metadata_type>::type module_metadata_chain_type; 

        BaseModuleMetadata() : 
            m_mdm(mdModuleNil)
        { }

        mdModule GetToken() const
        {
            if (m_mdm == mdModuleNil)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);
                boost::shared_ptr<assembly_metadata_type> pAsm = pMutableThis->MapFirst<assembly_metadata_type>();

                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.GetModuleFromScope(&m_mdm);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return m_mdm;
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        boost::shared_ptr<typename base_type::i_assembly_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<assembly_metadata_type>();
        }

        boost::shared_ptr<type_metadata_type const> GetType(std::wstring const &name) const
        {
            boost::shared_ptr<type_metadata_type> pType;
            pType = NewType(name);

            boost::shared_ptr<type_metadata_type> pExistingType;
            if (!TryGetType(*pType, pExistingType))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_provider_type &provider = pDisp->ProviderOf<type_metadata_type>();
                m_typeToIndex[pType] = provider.Register(pType);
                return pType;
            }
            else
            {
                return pExistingType;
            }
        }

    private:
        friend typename assembly_metadata_type;
        friend typename type_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        boost::shared_ptr<type_metadata_type> NewType(std::wstring const &name) const
        {
            boost::shared_ptr<type_metadata_type> pType = NewTypeCore();
            pType->SetName(name);
            return pType;
        }

        boost::shared_ptr<type_metadata_type> NewType(mdToken mdt) const
        {
            boost::shared_ptr<type_metadata_type> pType = NewTypeCore();
            pType->SetToken(mdt);
            return pType;
        }

        boost::shared_ptr<type_metadata_type> NewTypeCore() const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            type_metadata_provider_type &provider = pDisp->ProviderOf<type_metadata_type>();
            module_metadata_chain_type &chain = ChainFrom<assembly_metadata_type>();
            return chain.NewObject<type_metadata_type>(provider);
        }

        bool TryGetType(type_metadata_type const &keyType, boost::shared_ptr<type_metadata_type> &pExistingType) const
        {
            boost::shared_ptr<type_metadata_type const> pKeyType(&keyType, Utilities::MakeNullDeleter(&keyType));
            if (m_typeToIndex.find(pKeyType) == m_typeToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_typeToIndex[pKeyType];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_provider_type &provider = pDisp->ProviderOf<type_metadata_type>();
                pExistingType = provider[index];
                return true;
            }
        }

        mutable mdModule m_mdm;
        std::wstring m_name;
        mutable boost::unordered_map<boost::shared_ptr<type_metadata_type const>, 
                                     SIZE_T, 
                                     i_type_metadata_hash_type, 
                                     i_type_metadata_equal_to_type> m_typeToIndex;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadata : 
        public SmartPtrChain<
            BaseTypeMetadata<TypeMetadataApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<BaseTypeMetadata<TypeMetadataApiHolder> >,
                SmartPtrChainInfo<typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type>
            >
        >,
        public TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseTypeMetadata<TypeMetadataApiHolder> this_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type base_type;

        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;        
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::IMethodMetadataHashLabel>::type i_method_metadata_hash_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, Interfaces::IMethodMetadataEqualToLabel>::type i_method_metadata_equal_to_type;
        typedef typename TypeMetadataApiAt<TypeMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;        

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Type, type_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Type, type_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Type, type_metadata_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Type, type_metadata_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type type_metadata_provider_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Type, method_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Type, method_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Type, method_metadata_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Type, method_metadata_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type method_metadata_provider_type;        

        typedef typename chain_from<this_type>::type nested_type_metadata_chain_type; 
        typedef typename chain_from<module_metadata_type>::type type_metadata_chain_type; 

        BaseTypeMetadata() : 
            m_mdt(mdTokenNil),
            m_genericArgsInit(false),
            m_kindInitialized(false),
            m_kind(TypeKinds::TK_END),
            m_filled(false)
        { }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                if (boost::shared_ptr<this_type> p = MapFirstAncestor<this_type>())
                {
                    return p->GetToken();
                }
                else
                {
                    _ASSERTE(!m_name.empty());

                    this_type *pMutableThis = const_cast<this_type *>(this);

                    boost::shared_ptr<assembly_metadata_type> pAsmMeta = MapFirst<assembly_metadata_type>();
                
                    com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

                    HRESULT hr = comMetaImp.FindTypeDefByName(m_name.c_str(), NULL, &m_mdt);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
            }
            return m_mdt;
        }
        
        std::wstring const &GetName() const
        {
            if (m_name.empty())
                FillPropertiesIfNecessary();
            return m_name;
        }

        boost::shared_ptr<typename base_type::this_type const> GetBaseType() const
        {
            if (!m_pBaseType)
                FillPropertiesIfNecessary();
            return m_pBaseType;
        }

        boost::shared_ptr<typename base_type::i_module_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<module_metadata_type>();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.empty())
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

        std::vector<boost::shared_ptr<base_type const> > const &GetGenericArguments() const
        {
            if (!m_genericArgsInit)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                boost::shared_ptr<assembly_metadata_type> pAsm = pMutableThis->MapFirst<assembly_metadata_type>();
                boost::shared_ptr<module_metadata_type> pMod = pMutableThis->MapFirst<module_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HCORENUM hEnum = NULL;
                    BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                    {
                        if (hEnum)
                            comMetaImp.CloseEnum(hEnum);
                    }
                    BOOST_SCOPE_EXIT_END
                boost::array<mdGenericParam, 16> m_mdgps;
                ULONG count = 0;
                HRESULT hr = E_FAIL;
                mdToken mdtTarget = GetToken();
                do
                {
                    hr = comMetaImp.EnumGenericParams(&hEnum, mdtTarget, m_mdgps.c_array(), m_mdgps.size(), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_genericArgs.reserve(m_genericArgs.size() + count);
                    for (UINT i = 0; i < count; ++i)
                    {
                        boost::shared_ptr<this_type> pType;
                        pType = pMod->NewType(m_mdgps[i]);
                        m_genericArgs.push_back(pType);
                    }
                } while (0 < count);

                m_genericArgsInit = true;
            }
            return m_genericArgs;
        }

        bool IsGenericParameter() const
        {
            return TypeFromToken(GetToken()) == mdtGenericParam;
        }

        bool IsGenericType() const
        {
            return !GetGenericArguments().empty();
        }
        
        bool IsGenericTypeDefinition() const
        {
            if (!IsGenericType())
            {
                return false;
            }
            else
            {
                nested_type_metadata_chain_type &chain = ChainFrom<this_type>();
                boost::shared_ptr<base_type> pGenericTypeDef = chain.GetPrevious().lock();
                return !pGenericTypeDef;
            }
        }

        boost::shared_ptr<this_type const> MakeGenericType(std::vector<boost::shared_ptr<base_type const> > const &genericArgs) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            type_metadata_provider_type &provider = pDisp->ProviderOf<this_type>();
            nested_type_metadata_chain_type &chain = ChainFrom<this_type>();
            boost::shared_ptr<this_type> pType = chain.NewObject<this_type>(provider);
            pType->SetGenericArguments(genericArgs);
            return pType;
        }

        boost::shared_ptr<method_metadata_type const> GetMethod(std::wstring const &name, 
                                                                CallingConventions const &callingConvention, 
                                                                boost::shared_ptr<base_type const> const &pRetType, 
                                                                std::vector<boost::shared_ptr<base_type const> > const &paramTypes) const
        {
            boost::shared_ptr<method_metadata_type> pMethod;
            pMethod = NewMethod(name, callingConvention, pRetType, paramTypes);

            boost::shared_ptr<method_metadata_type> pExistingMethod;
            if (!TryGetMethod(*pMethod, pExistingMethod))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                method_metadata_provider_type &provider = pDisp->ProviderOf<method_metadata_type>();
                m_methodToIndex[pMethod] = provider.Register(pMethod);
                return pMethod;
            }
            else
            {
                return pExistingMethod;
            }
        }

    private:
        friend typename module_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetToken(mdToken mdt)
        {
            _ASSERTE(!IsNilToken(mdt));
            _ASSERTE(m_mdt == mdTokenNil);
            m_mdt = mdt;
        }

        void SetGenericArguments(std::vector<boost::shared_ptr<base_type const> > const &genericArgs)
        {
            _ASSERTE(!m_genericArgsInit);
            _ASSERTE(genericArgs.size() != 0);
            m_genericArgs = genericArgs;
            m_genericArgsInit = true;
        }

        boost::shared_ptr<method_metadata_type> NewMethod(std::wstring const &name, 
                                                          CallingConventions const &callingConvention, 
                                                          boost::shared_ptr<base_type const> const &pRetType, 
                                                          std::vector<boost::shared_ptr<base_type const> > const &paramTypes) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            method_metadata_provider_type &provider = pDisp->ProviderOf<method_metadata_type>();
            boost::shared_ptr<method_metadata_type> pMethod = NewObjectFirst<method_metadata_type>(provider);
            pMethod->SetName(name);
            pMethod->SetCallingConvention(callingConvention);
            pMethod->SetReturnType(pRetType);
            pMethod->SetParameterTypes(paramTypes);
            return pMethod;
        }

        bool TryGetMethod(method_metadata_type const &keyMethod, boost::shared_ptr<method_metadata_type> &pExistingMethod) const
        {
            boost::shared_ptr<method_metadata_type const> pKeyMethod(&keyMethod, Utilities::MakeNullDeleter(&keyMethod));
            if (m_methodToIndex.find(pKeyMethod) == m_methodToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_methodToIndex[pKeyMethod];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                method_metadata_provider_type &provider = pDisp->ProviderOf<method_metadata_type>();
                pExistingMethod = provider[index];
                return true;
            }
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;

            this_type *pMutableThis = const_cast<this_type *>(this);

            boost::shared_ptr<module_metadata_type> pMod = MapFirst<module_metadata_type>();
            boost::shared_ptr<assembly_metadata_type> pAsm = pMod->MapFirst<assembly_metadata_type>();

            com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

            mdToken mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtTypeRef)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            else if (TypeFromToken(mdtTarget) == mdtTypeDef)
            {
                WCHAR name[MAX_SYM_NAME] = { 0 };
                ULONG nameSize = sizeof(name);
                DWORD attr = 0;
                mdToken mdtExt = mdTokenNil;
                HRESULT hr = comMetaImp.GetTypeDefProps(mdtTarget, name, nameSize, 
                                                        &nameSize, &attr, &mdtExt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_name = name;
                if (!IsNilToken(mdtExt) && 
                    (TypeFromToken(mdtExt) == mdtTypeDef ||
                     TypeFromToken(mdtExt) == mdtTypeRef))
                {
                    m_pBaseType = pMod->NewType(mdtExt);
                }
                else if (!IsNilToken(mdtExt))
                {
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }


            m_filled = true;
        }

        TypeKinds const &GetKind() const
        {
            using Interfaces::MetadataSpecialValues;

            if (!m_kindInitialized)
            {
                std::wstring const &name = GetName();
                if (name == MetadataSpecialValues::TYPE_NAME_OF_VOID) m_kind = TypeKinds::TK_VOID;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_BOOLEAN) m_kind = TypeKinds::TK_BOOLEAN;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_CHAR) m_kind = TypeKinds::TK_CHAR;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_SBYTE) m_kind = TypeKinds::TK_I1;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_BYTE) m_kind = TypeKinds::TK_U1;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT16) m_kind = TypeKinds::TK_I2;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT16) m_kind = TypeKinds::TK_U2;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT32) m_kind = TypeKinds::TK_I4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT32) m_kind = TypeKinds::TK_U4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT64) m_kind = TypeKinds::TK_I8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT64) m_kind = TypeKinds::TK_U8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_SINGLE) m_kind = TypeKinds::TK_R4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_DOUBLE) m_kind = TypeKinds::TK_R8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_STRING) m_kind = TypeKinds::TK_STRING;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INTPTR) m_kind = TypeKinds::TK_I;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_OBJECT) m_kind = TypeKinds::TK_OBJECT;
                else
                {
                    if (name.find(MetadataSpecialValues::GENERIC_TYPE_IDENTIFIER) != std::wstring::npos)
                    {
                        m_kind = TypeKinds::TK_GENERICINST;
                    }
                    else
                    {
                        boost::shared_ptr<base_type const> pBaseType = GetBaseType();
                        if (pBaseType && pBaseType->GetName() == MetadataSpecialValues::TYPE_NAME_OF_VALUETYPE)
                        {
                            m_kind = TypeKinds::TK_VALUETYPE;
                        }
                        else
                        {
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        }
                    }
                }

                m_kindInitialized = true;
            }
            return m_kind;
        }

        static void PushBackSignatures(std::vector<COR_SIGNATURE> &sigs, this_type const &this_)
        {
            TypeKinds const &typeKind = this_.GetKind();
            switch (typeKind.Value())
            {
                case TypeKinds::TK_VOID:
                case TypeKinds::TK_I:
                case TypeKinds::TK_OBJECT:
                case TypeKinds::TK_STRING:
                    sigs.push_back(typeKind.Value());
                    break;

                case TypeKinds::TK_VALUETYPE:
                    sigs.push_back(typeKind.Value());
                    {
                        BYTE pData[4] = { 0 };
                        ULONG length = ::CorSigCompressToken(this_.GetToken(), pData);
                        for (BYTE const *i = pData, *i_end = i + length; i != i_end; ++i)
                            sigs.push_back(*i);
                    }
                    break;

                case TypeKinds::TK_GENERICINST:
                    sigs.push_back(typeKind.Value());
                    {
                    }
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;

                default:
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;
            }
        }

        mutable std::wstring m_name;
        mutable boost::shared_ptr<base_type const> m_pBaseType;
        mutable mdToken m_mdt;
        mutable bool m_genericArgsInit;
        mutable bool m_kindInitialized;
        mutable TypeKinds m_kind;
        mutable std::vector<COR_SIGNATURE> m_sigs;
        mutable std::vector<boost::shared_ptr<base_type const> > m_genericArgs;
        mutable boost::unordered_map<boost::shared_ptr<method_metadata_type const>, 
                                     size_t, 
                                     i_method_metadata_hash_type, 
                                     i_method_metadata_equal_to_type> m_methodToIndex;        
        mutable bool m_filled;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataApiHolder
    >    
    class BaseMethodMetadata : 
        public SmartPtrChain<
            BaseMethodMetadata<MethodMetadataApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type>
            >
        >,
        public MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseMethodMetadata<MethodMetadataApiHolder> this_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::IMethodMetadataLabel>::type base_type;

        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename MethodMetadataApiAt<MethodMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;        
        
        BaseMethodMetadata() : 
            m_mdt(mdTokenNil),
            m_callingConvention(CallingConventions::CC_NO_VALUE),
            m_retTypeInitialized(false), 
            m_paramTypesInitialized(false)
        { }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                _ASSERTE(!m_name.empty());

                SimpleBlob sig;

                _ASSERTE(m_callingConvention != CallingConventions::CC_NO_VALUE);
                SignatureUtil::PutSignatures(sig, m_callingConvention);

                _ASSERTE(m_paramTypesInitialized);
                sig.Put<COR_SIGNATURE>(m_paramTypes.size());

                _ASSERTE(m_retTypeInitialized);
                SignatureUtil::PutSignatures(sig, *m_pRetType);

                typedef std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> >::const_iterator ConstIterator;
                for (ConstIterator ci = m_paramTypes.cbegin(), ci_end = m_paramTypes.cend(); ci != ci_end; ++ci)
                    SignatureUtil::PutSignatures(sig, **ci);

                this_type *pMutableThis = const_cast<this_type *>(this);

                boost::shared_ptr<assembly_metadata_type> pAsm = MapFirst<assembly_metadata_type>();
                boost::shared_ptr<type_metadata_type> pType = MapFirst<type_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.FindMethod(pType->GetToken(), m_name.c_str(), 
                                                   sig.Ptr(), sig.Size(), &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return m_mdt;
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        CallingConventions const &GetCallingConvention() const
        {
            if (m_callingConvention == CallingConventions::CC_NO_VALUE)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_callingConvention;
        }
        
        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetReturnType() const
        {
            if (!m_retTypeInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_pRetType;
        }

        std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > const &GetParameterTypes() const
        {
            if (!m_paramTypesInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_paramTypes;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<type_metadata_type>();
        }

    private:
        friend typename type_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            _ASSERTE(callingConvention != CallingConventions::CC_NO_VALUE);
            _ASSERTE(m_callingConvention == CallingConventions::CC_NO_VALUE);
            m_callingConvention = callingConvention;
        }

        void SetReturnType(boost::shared_ptr<i_type_metadata_type const> const &pRetType)
        {
            _ASSERTE(!m_retTypeInitialized);
            m_pRetType = pRetType;
            m_retTypeInitialized = true;
        }

        void SetParameterTypes(std::vector<boost::shared_ptr<i_type_metadata_type const> > const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        mutable mdToken m_mdt;
        std::wstring m_name;
        CallingConventions m_callingConvention;
        bool m_retTypeInitialized; 
        boost::shared_ptr<i_type_metadata_type const> m_pRetType;
        bool m_paramTypesInitialized; 
        std::vector<boost::shared_ptr<i_type_metadata_type const> > m_paramTypes;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;

        struct DefaultFusionInfoApiHolderImpl
        {
            typedef map<
                pair<RuntimeHostLabel, RuntimeHost>,
                pair<AssemblyInfoLabel, AssemblyInfo>,
                pair<IAssemblyCache, IAssemblyCache>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultFusionInfoApiHolder : 
        Detail::DefaultFusionInfoApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;

        struct DefaultAssemblyInfoApiHolderImpl
        {
            typedef map<
                pair<FusionInfoLabel, FusionInfo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyInfoApiHolder : 
        Detail::DefaultAssemblyInfoApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct FusionInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::FusionInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FusionInfoApiHolder
    >    
    class BaseFusionInfo : 
        public SmartPtrChain<
            BaseFusionInfo<FusionInfoApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename FusionInfoApiAt<FusionInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type>
            >
        >,
        SmartHeapProvider<
            boost::mpl::vector<
                typename FusionInfoApiAt<FusionInfoApiHolder, Interfaces::AssemblyInfoLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseFusionInfo<FusionInfoApiHolder> this_type;
        
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, Interfaces::AssemblyInfoLabel>::type assembly_info_type;
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, IAssemblyCache>::type com_assembly_cache_type;

        typedef typename provider_of<assembly_info_type>::type assembly_info_provider_type;

        BaseFusionInfo()
        { }

        boost::shared_ptr<assembly_info_type> QueryAssemblyInfo(
                  AssemblyQueryTypes const &type, std::wstring const &assemblyName) const
        {
            using namespace boost::filesystem;

            this_type *pMutableThis = const_cast<this_type *>(this);

            WCHAR buffer[MAX_PATH] = { 0 };
            ASSEMBLY_INFO asmInfo;
            ::ZeroMemory(&asmInfo, sizeof(ASSEMBLY_INFO));
            asmInfo.cbAssemblyInfo = sizeof(ASSEMBLY_INFO);
            asmInfo.pszCurrentAssemblyPathBuf = buffer;
            asmInfo.cchBuf = MAX_PATH;
            HRESULT hr = pMutableThis->GetCOMAssemblyCache().QueryAssemblyInfo(type.Value(), assemblyName.c_str(), &asmInfo);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            ULONGLONG assemblySizeInKB = 0;
            ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), 
                       &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

            assembly_info_provider_type &provider = ProviderOf<assembly_info_type>();
            boost::shared_ptr<assembly_info_type> pAsmInfo = provider.NewObject();
            pAsmInfo->SetAssemblySizeInKB(assemblySizeInKB);
            pAsmInfo->SetAssemblyPath(asmInfo.pszCurrentAssemblyPathBuf);
            return pAsmInfo;
        }

    private:
        friend typename runtime_host_type;

        void Init(boost::weak_ptr<runtime_host_type> const &pRuntimeAsScope) const
        {
            _ASSERTE(m_pRuntimeAsScope.use_count() == 0);
            m_pRuntimeAsScope = pRuntimeAsScope;
        }

        void SetThis(boost::weak_ptr<this_type> const &pThis) const
        {
            _ASSERTE(m_pThis.use_count() == 0);
            m_pThis = pThis;
        }

        void SetVersion(std::wstring const &version)
        {
            _ASSERTE(!version.empty());
            _ASSERTE(m_version.empty());
            m_version = version;
        }

        com_assembly_cache_type &GetCOMAssemblyCache()
        {
            using namespace boost::filesystem;
            
            if (m_pComAsmCache.p == NULL)
            {
                boost::shared_ptr<runtime_host_type> pRuntimeHost = MapFirst<runtime_host_type>();

                path const &corSysDirPath = pRuntimeHost->GetCORSystemDirectoryPath();
                path fusionPath = corSysDirPath;
                fusionPath /= L"fusion.dll";

                HMODULE hmodCorEE = ::LoadLibraryW(fusionPath.c_str());
                if (hmodCorEE == NULL)
                    BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
                BOOST_SCOPE_EXIT((hmodCorEE))
                {
                    ::FreeLibrary(hmodCorEE);
                }
                BOOST_SCOPE_EXIT_END

                typedef HRESULT (__stdcall *CreateAsmCachePtr)(IAssemblyCache **ppAsmCache, DWORD dwReserved);

                CreateAsmCachePtr pfnCreateAsmCache = NULL;
                pfnCreateAsmCache = reinterpret_cast<CreateAsmCachePtr>(
                                                ::GetProcAddress(hmodCorEE, "CreateAssemblyCache"));
                if (!pfnCreateAsmCache)
                    BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        
                HRESULT hr = pfnCreateAsmCache(&m_pComAsmCache, 0);
                if (FAILED(hr)) 
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComAsmCache;
        }
        
        mutable boost::weak_ptr<runtime_host_type> m_pRuntimeAsScope;
        mutable boost::weak_ptr<this_type> m_pThis;
        std::wstring m_version;
        mutable ATL::CComPtr<com_assembly_cache_type> m_pComAsmCache;
    };

    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyInfoApiHolder
    >    
    class BaseAssemblyInfo
    {
    public:
        typedef BaseAssemblyInfo<AssemblyInfoApiHolder> this_type;

        typedef typename AssemblyInfoApiAt<AssemblyInfoApiHolder, Interfaces::FusionInfoLabel>::type fusion_info_type;

        BaseAssemblyInfo() :
            m_assemblySizeInKB(0)
        { }
        
        ULONGLONG GetAssemblySizeInKB() const 
        { 
            return m_assemblySizeInKB; 
        }
        
        boost::filesystem::path const &GetAssemblyPath() const 
        { 
            return m_assemblyPath; 
        }

    private:
        friend typename fusion_info_type;

        void SetAssemblySizeInKB(ULONGLONG assemblySizeInKB)
        { 
            m_assemblySizeInKB = assemblySizeInKB; 
        }
        
        void SetAssemblyPath(boost::filesystem::path const &assemblyPath)
        { 
            m_assemblyPath = assemblyPath; 
        }

        ULONGLONG m_assemblySizeInKB;
        boost::filesystem::path m_assemblyPath;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test2.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, Test_01)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        //typedef HostInfo HostInfo;
        //typedef RuntimeHost RuntimeHost;
        //typedef MetadataInfo MetadataInfo;
        //typedef MetadataDispenser MetadataDispenser;
        //typedef AssemblyMetadata AssemblyMetadata;
        //typedef ModuleMetadata ModuleMetadata;
        //typedef ITypeMetadata ITypeMetadata;
        //typedef TypeMetadata TypeMetadata;
        //typedef MethodMetadata MethodMetadata;

        shared_ptr<HostInfo const> pHostInfo = HostInfo::NewHost();

        shared_ptr<RuntimeHost const> pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost);

        shared_ptr<MetadataInfo const> pMetaInfo = pRuntimeHost->Map<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo);

        shared_ptr<MetadataDispenser> pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaDisp);

        shared_ptr<AssemblyMetadata const> pSystemCore;
        pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                             L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());
        
        shared_ptr<AssemblyMetadata const> pMSCorLib;
        pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                           L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        shared_ptr<ModuleMetadata const> pSystemCoreModule = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_EQ(0x00000001, pSystemCoreModule->GetToken());
        
        shared_ptr<ModuleMetadata const> pMSCorLibModule = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        shared_ptr<TypeMetadata const> pVoid = pMSCorLibModule->GetType(L"System.Void");
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        shared_ptr<TypeMetadata const> pObject = pMSCorLibModule->GetType(L"System.Object");
        ASSERT_EQ(0x02000002, pObject->GetToken());

        shared_ptr<TypeMetadata const> pIntPtr = pMSCorLibModule->GetType(L"System.IntPtr");
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        shared_ptr<TypeMetadata const> pDateTime = pMSCorLibModule->GetType(L"System.DateTime");
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        shared_ptr<TypeMetadata const> pFunc1 = pSystemCoreModule->GetType(L"System.Func`1");
        ASSERT_TRUE(pFunc1->IsGenericType());
        ASSERT_TRUE(pFunc1->IsGenericTypeDefinition());
        {
            std::vector<shared_ptr<ITypeMetadata const> > const &genericArgs = pFunc1->GetGenericArguments();
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

        shared_ptr<TypeMetadata const> pFunc1DateTime;
        {
            std::vector<shared_ptr<ITypeMetadata const> > genericArgs;
            genericArgs.push_back(pDateTime);
            pFunc1DateTime = pFunc1->MakeGenericType(genericArgs);
        }
        ASSERT_TRUE(pFunc1DateTime->IsGenericType());
        ASSERT_FALSE(pFunc1DateTime->IsGenericTypeDefinition());
        {
            std::vector<shared_ptr<ITypeMetadata const> > const &genericArgs = pFunc1DateTime->GetGenericArguments();
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

        shared_ptr<MethodMetadata const> pFunc1DateTimector;
        {
            std::vector<shared_ptr<ITypeMetadata const> > params;
            params.push_back(pObject);
            params.push_back(pIntPtr);
            pFunc1DateTimector = pFunc1DateTime->GetMethod(L".ctor", CallingConventions::CC_HAS_THIS, pVoid, params);
        }
        ASSERT_EQ(0x06000232, pFunc1DateTimector->GetToken());   // !! CAUTION: This is CORRECT !!

        shared_ptr<MethodMetadata const> pget_UtcNow;
        {
            std::vector<shared_ptr<ITypeMetadata const> > params;
            pget_UtcNow = pDateTime->GetMethod(L"get_UtcNow", CallingConventions::CC_STANDARD, pDateTime, params);
        }
        ASSERT_EQ(0x060002D3, pget_UtcNow->GetToken());

        shared_ptr<MethodMetadata const> pToLocalTime;
        {
            std::vector<shared_ptr<ITypeMetadata const> > params;
            pToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, pDateTime, params);
        }
        ASSERT_EQ(0x060002E7, pToLocalTime->GetToken());




#if 0
#endif
    }


}
