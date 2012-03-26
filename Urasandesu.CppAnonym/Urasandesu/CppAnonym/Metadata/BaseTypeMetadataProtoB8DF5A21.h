#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct DefaultMethodMetadataApiProtoB8DF5A21
    {
    };

    template<
        class MethodMetadataApiType = DefaultMethodMetadataApiProtoB8DF5A21
    >    
    class BaseMethodMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>
    {
    };

    namespace Detail {

        struct TypeKindsDef
        {
            enum type
            {
                TK_END = ELEMENT_TYPE_END, 
                TK_VOID = ELEMENT_TYPE_VOID, 
                TK_BOOLEAN = ELEMENT_TYPE_BOOLEAN, 
                TK_CHAR = ELEMENT_TYPE_CHAR, 
                TK_I1 = ELEMENT_TYPE_I1, 
                TK_U1 = ELEMENT_TYPE_U1, 
                TK_I2 = ELEMENT_TYPE_I2, 
                TK_U2 = ELEMENT_TYPE_U2, 
                TK_I4 = ELEMENT_TYPE_I4, 
                TK_U4 = ELEMENT_TYPE_U4, 
                TK_I8 = ELEMENT_TYPE_I8, 
                TK_U8 = ELEMENT_TYPE_U8, 
                TK_R4 = ELEMENT_TYPE_R4, 
                TK_R8 = ELEMENT_TYPE_R8, 
                TK_STRING = ELEMENT_TYPE_STRING, 
                TK_PTR = ELEMENT_TYPE_PTR, 
                TK_BYREF = ELEMENT_TYPE_BYREF, 
                TK_VALUETYPE = ELEMENT_TYPE_VALUETYPE, 
                TK_CLASS = ELEMENT_TYPE_CLASS, 
                TK_VAR = ELEMENT_TYPE_VAR, 
                TK_ARRAY = ELEMENT_TYPE_ARRAY, 
                TK_GENERICINST = ELEMENT_TYPE_GENERICINST, 
                TK_TYPEDBYREF = ELEMENT_TYPE_TYPEDBYREF, 
                TK_I = ELEMENT_TYPE_I, 
                TK_U = ELEMENT_TYPE_U, 
                TK_FNPTR = ELEMENT_TYPE_FNPTR, 
                TK_OBJECT = ELEMENT_TYPE_OBJECT, 
                TK_SZARRAY = ELEMENT_TYPE_SZARRAY, 
                TK_MVAR = ELEMENT_TYPE_MVAR, 
                TK_CMOD_REQD = ELEMENT_TYPE_CMOD_REQD, 
                TK_CMOD_OPT = ELEMENT_TYPE_CMOD_OPT, 
                TK_INTERNAL = ELEMENT_TYPE_INTERNAL, 
                TK_MAX = ELEMENT_TYPE_MAX, 
                TK_MODIFIER = ELEMENT_TYPE_MODIFIER, 
                TK_SENTINEL = ELEMENT_TYPE_SENTINEL, 
                TK_PINNED = ELEMENT_TYPE_PINNED, 
                TK_R4_HFA = ELEMENT_TYPE_R4_HFA, 
                TK_R8_HFA = ELEMENT_TYPE_R8_HFA, 
                TK_UNREACHED
            };
        };

        struct CallingConventionsDef
        {
            enum type
            {
                CC_STANDARD, 
                CC_VAR_ARGS, 
                CC_ANY, 
                CC_HAS_THIS, 
                CC_EXPLICIT_THIS, 
                CC_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::TypeKindsDef> TypeKinds;
    typedef SafeEnum<Detail::CallingConventionsDef> CallingConventions;

    
    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21;

    struct DefaultTypeMetadataApiProtoB8DF5A21;

    struct IAssemblyMetadataApi;

    struct IMethodMetadataApi;


    template<
        class TypeMetadataApiType = DefaultTypeMetadataApiProtoB8DF5A21
    >    
    class BaseTypeMetadataProtoB8DF5A21 : 
        public IHeapContent<mdToken>
    {
    public:
        typedef BaseTypeMetadataProtoB8DF5A21<TypeMetadataApiType> this_type;
        typedef typename Traits::ParentApiOrDefault<TypeMetadataApiType, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;
        //typedef typename TypeMetadataApiType::metadata_import_api_type metadata_import_api_type;
        typedef typename Traits::ChildApiOrDefault<TypeMetadataApiType, IMetaDataImport2>::type metadata_import_api_type;
        typedef typename Traits::ChildApiOrDefault<TypeMetadataApiType, IMethodMetadataApi>::type method_metadata_api_type;
        typedef BaseMethodMetadataProtoB8DF5A21<method_metadata_api_type> method_metadata_type;


        void Init(assembly_metadata_type &asmMeta, metadata_import_api_type *metaImpApi) const
        {
        }

        inline TypeKinds const &GetKind() const
        {
            return TypeKind::TK_END;
        }

        inline void SetKind(TypeKinds const &kind)
        {
        }

        inline mdToken GetToken() const
        {
            return GetKey();
        }

        method_metadata_type const *GetMethod(std::wstring const &name, CallingConventions const &callConvention, this_type const *pRetType, std::vector<this_type const *> const &paramTypes)
        {
            return NULL;
        }
    };

    typedef BaseTypeMetadataProtoB8DF5A21<> TypeMetadataProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H