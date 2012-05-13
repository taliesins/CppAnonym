#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EXTERNALAPISTRATEGIES_H
#include <Urasandesu/CppAnonym/Traits/ExternalApiStrategies.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTTYPEMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultTypeMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATAPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadataProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTMETHODMETADATAAPIPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/DefaultMethodMetadataApiProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
#include <Urasandesu/CppAnonym/SimpleBlob.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTHASH_H
#include <Urasandesu/CppAnonym/Utilities/DefaultHash.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H
#include <Urasandesu/CppAnonym/Utilities/AnyPointer.h>
#endif

#ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
#include <Urasandesu/CppAnonym/DefaultSTDMETHODWrapper.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class Base>
    class CComObjectSlim : 
        public ATL::CComObjectNoLock<Base>
    {
    public:
        static HRESULT CreateInstance(CComObjectSlim<Base>** ppObj)
        {
            if (ppObj == NULL) return E_POINTER;
            *ppObj = NULL;

            HRESULT hr = E_FAIL;
            std::auto_ptr<CComObjectSlim<Base>> pObj(new CComObjectSlim<Base>());

            pObj->SetVoid(NULL);                    // Declared in CComObjectRootBase.
            pObj->InternalFinalConstructAddRef();   // Declared in user class DECLARE_PROTECT_FINAL_CONSTRUCT.

            hr = pObj->_AtlInitialConstruct();      // Declared in CComObjectRootEx.
            if (FAILED(hr)) return hr;

            hr = pObj->FinalConstruct();            // Declared in user class.
            if (FAILED(hr)) return hr;

            hr = pObj->_AtlFinalConstruct();        // Declared in CComObjectRootBase.
            pObj->InternalFinalConstructRelease();  // Declared in user class DECLARE_PROTECT_FINAL_CONSTRUCT.

            *ppObj = pObj.release();
            return S_OK;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace {

    class ATL_NO_VTABLE MyMetaDataImport;
    typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MyMetaDataImport> MyMetaDataImportObject;

}

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class Base
    >
    class ATL_NO_VTABLE IMetaDataImport2Impl : public Base
    {
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_VOID_WRAPPER(CloseEnum, ((HCORENUM, hEnum)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(CountEnum, ((HCORENUM, hEnum))((ULONG *, pulCount)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ResetEnum, ((HCORENUM, hEnum))((ULONG, ulPos)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeDefs, ((HCORENUM *, phEnum))((mdTypeDef *, rTypeDefs))((ULONG, cMax))((ULONG *, pcTypeDefs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumInterfaceImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdInterfaceImpl *, rImpls))((ULONG, cMax))((ULONG*, pcImpls)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeRefs, ((HCORENUM *, phEnum))((mdTypeRef *, rTypeRefs))((ULONG, cMax))((ULONG*, pcTypeRefs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindTypeDefByName, ((LPCWSTR, szTypeDef))((mdToken, tkEnclosingClass))((mdTypeDef *, ptd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetScopeProps, ((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((GUID *, pmvid)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetModuleFromScope, ((mdModule *, pmd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeDefProps, ((mdTypeDef, td))((LPWSTR, szTypeDef))((ULONG, cchTypeDef))((ULONG *, pchTypeDef))((DWORD *, pdwTypeDefFlags))((mdToken *, ptkExtends)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetInterfaceImplProps, ((mdInterfaceImpl, iiImpl))((mdTypeDef *, pClass))((mdToken *, ptkIface)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeRefProps, ((mdTypeRef, tr))((mdToken *, ptkResolutionScope))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(ResolveTypeRef, ((mdTypeRef, tr))((REFIID, riid))((IUnknown **, ppIScope))((mdTypeDef *, ptd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMembers, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMembersWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdToken *, rMembers))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethods, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdMethodDef *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumFields, ((HCORENUM *, phEnum))((mdTypeDef, cl))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumFieldsWithName, ((HCORENUM *, phEnum))((mdTypeDef, cl))((LPCWSTR, szName))((mdFieldDef *, rFields))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumParams, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdParamDef *, rParams))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMemberRefs, ((HCORENUM *, phEnum))((mdToken, tkParent))((mdMemberRef *, rMemberRefs))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodImpls, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdToken *, rMethodBody))((mdToken *, rMethodDecl))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumPermissionSets, ((HCORENUM *, phEnum))((mdToken, tk))((DWORD, dwActions))((mdPermission *, rPermission))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMember, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdToken *, pmb)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMethod, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMethodDef *, pmb)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindField, ((mdTypeDef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdFieldDef *, pmb)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindMemberRef, ((mdTypeRef, td))((LPCWSTR, szName))((PCCOR_SIGNATURE, pvSigBlob))((ULONG, cbSigBlob))((mdMemberRef *, pmr)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodProps, ((mdMethodDef, mb))((mdTypeDef *, pClass))((LPWSTR, szMethod))((ULONG, cchMethod))((ULONG *, pchMethod))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMemberRefProps, ((mdMemberRef, mr))((mdToken *, ptk))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pbSig)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumProperties, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdProperty *, rProperties))((ULONG, cMax))((ULONG *, pcProperties)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumEvents, ((HCORENUM *, phEnum))((mdTypeDef, td))((mdEvent *, rEvents))((ULONG, cMax))((ULONG *, pcEvents)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetEventProps, ((mdEvent, ev))((mdTypeDef *, pClass))((LPCWSTR, szEvent))((ULONG, cchEvent))((ULONG *, pchEvent))((DWORD *, pdwEventFlags))((mdToken *, ptkEventType))((mdMethodDef *, pmdAddOn))((mdMethodDef *, pmdRemoveOn))((mdMethodDef *, pmdFire))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodSemantics, ((HCORENUM *, phEnum))((mdMethodDef, mb))((mdToken *, rEventProp))((ULONG, cMax))((ULONG *, pcEventProp)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodSemantics, ((mdMethodDef, mb))((mdToken, tkEventProp))((DWORD *, pdwSemanticsFlags)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetClassLayout, ((mdTypeDef, td))((DWORD *, pdwPackSize))((COR_FIELD_OFFSET *, rFieldOffset))((ULONG, cMax))((ULONG *, pcFieldOffset))((ULONG *, pulClassSize)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetFieldMarshal, ((mdToken, tk))((PCCOR_SIGNATURE *, ppvNativeType))((ULONG *, pcbNativeType)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetRVA, ((mdToken, tk))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPermissionSetProps, ((mdPermission, pm))((DWORD *, pdwAction))((void const **, ppvPermission))((ULONG *, pcbPermission)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetSigFromToken, ((mdSignature, mdSig))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetModuleRefProps, ((mdModuleRef, mur))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumModuleRefs, ((HCORENUM *, phEnum))((mdModuleRef *, rModuleRefs))((ULONG, cmax))((ULONG *, pcModuleRefs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetTypeSpecFromToken, ((mdTypeSpec, typespec))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pcbSig)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNameFromToken, ((mdToken, tk))((MDUTF8CSTR *, pszUtf8NamePtr)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumUnresolvedMethods, ((HCORENUM *, phEnum))((mdToken *, rMethods))((ULONG, cMax))((ULONG *, pcTokens)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetUserString, ((mdString, stk))((LPWSTR, szString))((ULONG, cchString))((ULONG *, pchString)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPinvokeMap, ((mdToken, tk))((DWORD *, pdwMappingFlags))((LPWSTR, szImportName))((ULONG, cchImportName))((ULONG *, pchImportName))((mdModuleRef *, pmrImportDLL)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumSignatures, ((HCORENUM *, phEnum))((mdSignature *, rSignatures))((ULONG, cmax))((ULONG *, pcSignatures)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumTypeSpecs, ((HCORENUM *, phEnum))((mdTypeSpec *, rTypeSpecs))((ULONG, cmax))((ULONG *, pcTypeSpecs)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumUserStrings, ((HCORENUM *, phEnum))((mdString *, rStrings))((ULONG, cmax))((ULONG *, pcStrings)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetParamForMethodIndex, ((mdMethodDef, md))((ULONG, ulParamSeq))((mdParamDef *, ppd)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumCustomAttributes, ((HCORENUM *, phEnum))((mdToken, tk))((mdToken, tkType))((mdCustomAttribute *, rCustomAttributes))((ULONG, cMax))((ULONG *, pcCustomAttributes)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetCustomAttributeProps, ((mdCustomAttribute, cv))((mdToken *, ptkObj))((mdToken *, ptkType))((void const **, ppBlob))((ULONG *, pcbSize)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(FindTypeRef, ((mdToken, tkResolutionScope))((LPCWSTR, szName))((mdTypeRef *, ptr)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMemberProps, ((mdToken, mb))((mdTypeDef *, pClass))((LPWSTR, szMember))((ULONG, cchMember))((ULONG *, pchMember))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((ULONG *, pulCodeRVA))((DWORD *, pdwImplFlags))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetFieldProps, ((mdFieldDef, mb))((mdTypeDef *, pClass))((LPWSTR, szField))((ULONG, cchField))((ULONG *, pchField))((DWORD *, pdwAttr))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPropertyProps, ((mdProperty, prop))((mdTypeDef *, pClass))((LPCWSTR, szProperty))((ULONG, cchProperty))((ULONG *, pchProperty))((DWORD *, pdwPropFlags))((PCCOR_SIGNATURE *, ppvSig))((ULONG *, pbSig))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppDefaultValue))((ULONG *, pcchDefaultValue))((mdMethodDef *, pmdSetter))((mdMethodDef *, pmdGetter))((mdMethodDef *, rmdOtherMethod))((ULONG, cMax))((ULONG *, pcOtherMethod)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetParamProps, ((mdParamDef, tk))((mdMethodDef *, pmd))((ULONG *, pulSequence))((LPWSTR, szName))((ULONG, cchName))((ULONG *, pchName))((DWORD *, pdwAttr))((DWORD *, pdwCPlusTypeFlag))((UVCP_CONSTANT *, ppValue))((ULONG *, pcchValue)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetCustomAttributeByName, ((mdToken, tkObj))((LPCWSTR, szName))((const void **, ppData))((ULONG *, pcbData)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD__WRAPPER(BOOL, IsValidToken, ((mdToken, tk)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNestedClassProps, ((mdTypeDef, tdNestedClass))((mdTypeDef *, ptdEnclosingClass)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetNativeCallConvFromSig, ((void const *, pvSig))((ULONG, cbSig))((ULONG *, pCallConv)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(IsGlobal, ((mdToken, pd))((int *, pbGlobal)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumGenericParams, ((HCORENUM *, phEnum))((mdToken, tk))((mdGenericParam *, rGenericParams))((ULONG, cMax))((ULONG *, pcGenericParams)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetGenericParamProps, ((mdGenericParam, gp))((ULONG *, pulParamSeq))((DWORD *, pdwParamFlags))((mdToken *, ptOwner))((DWORD *, reserved))((LPWSTR, wzname))((ULONG, cchName))((ULONG *, pchName)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetMethodSpecProps, ((mdMethodSpec, mi))((mdToken *, tkParent))((PCCOR_SIGNATURE *, ppvSigBlob))((ULONG *, pcbSigBlob)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumGenericParamConstraints, ((HCORENUM *, phEnum))((mdGenericParam, tk))((mdGenericParamConstraint *, rGenericParamConstraints))((ULONG, cMax))((ULONG *, pcGenericParamConstraints)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetGenericParamConstraintProps, ((mdGenericParamConstraint, gpc))((mdGenericParam *, ptGenericParam))((mdToken *, ptkConstraintType)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetPEKind, ((DWORD*, pdwPEKind))((DWORD*, pdwMAchine)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(GetVersionString, ((LPWSTR, pwzBuf))((DWORD, ccBufSize))((DWORD *, pccBufSize)))
        CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(EnumMethodSpecs, ((HCORENUM *, phEnum))((mdToken, tk))((mdMethodSpec *, rMethodSpecs))((ULONG, cMax))((ULONG *, pcMethodSpecs)))
    };

    struct IAssemblyNameMetadataApi { };

    template<
        class AssemblyNameMetadataApiType
    >    
    class BaseAssemblyNameMetadataProtoB8DF5A21
    {
    public:
        std::wstring const &GetName() const
        {
            return m_name;
        }

    private:
        mutable std::wstring m_name;
    };

    struct IAssemblyMetadataApi { };
    
    struct DefaultAssemblyMetadataApiProtoB8DF5A21 : 
        IAssemblyMetadataApi
    {
        typedef boost::mpl::vector<DefaultTypeMetadataApiProtoB8DF5A21, 
                                   IMetaDataImport2> external_api_types;
    };

    template<
        class AssemblyMetadataApiType
    >    
    class BaseAssemblyMetadataProtoB8DF5A21
    {
    public:
        typedef BaseAssemblyMetadataProtoB8DF5A21<AssemblyMetadataApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, IMetaDataImport2>::type metadata_import_api_type;

        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, IAssemblyNameMetadataApi>::type assembly_name_metadata_api_type;
        typedef BaseAssemblyNameMetadataProtoB8DF5A21<assembly_name_metadata_api_type> assembly_name_metadata_type;

        typedef typename Traits::ExternalApiOrDefault<AssemblyMetadataApiType, IAssemblyMetadataApi, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;

        template<class T>
        T const *FindType() const 
        {
            if (m_pType.IsEmpty())
            {
                m_pType = new T();
            } 
            return m_pType;
        }

        type_metadata_type const *GetType(std::wstring const &name, TypeKinds const &kind) const
        {
            if (name == CONSOLE_NAME)
            {
                if (m_pConsole.IsEmpty())
                {
                    this_type *mutableThis = const_cast<this_type *>(this);

                    MyMetaDataImportObject *pMetaImpApi_ = NULL;
                    MyMetaDataImportObject::CreateInstance(&pMetaImpApi_); 
                    ATL::CComPtr<metadata_import_api_type> pMetaImpApi(pMetaImpApi_);

                    m_pConsole = new type_metadata_type();
                    type_metadata_type *pConsole = m_pConsole;
                    pConsole->Init(*mutableThis, *pMetaImpApi);
                    pConsole->SetName(name);
                    pConsole->SetKind(TypeKinds::TK_CLASS);
                }
                return m_pConsole;
            }
            return NULL;
        }

        void SetName(std::wstring const &name)
        {
        }

    private:
        static std::wstring const CONSOLE_NAME;
        mutable Utilities::AnyPointer m_pType;
        mutable Utilities::AnyPointer m_pConsole;
    };
    
    template<
        class AssemblyMetadataApiType
    >    
    std::wstring const BaseAssemblyMetadataProtoB8DF5A21<AssemblyMetadataApiType>::CONSOLE_NAME = std::wstring(L"System.Console");



    struct IMetadataDispenserApi { };

    template<
        class MetadataDispenserApiType
    >    
    class BaseMetadataDispenserProtoB8DF5A21
    {
    public:
        typedef BaseMetadataDispenserProtoB8DF5A21<MetadataDispenserApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<MetadataDispenserApiType, IMetadataDispenserApi, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;
        
        assembly_metadata_type const *LoadAssembly(std::wstring const &name) const
        {
            if (m_pMSCorLib.IsEmpty())
            {
                m_pMSCorLib = new assembly_metadata_type();
                assembly_metadata_type *pMSCorLib = m_pMSCorLib;
                pMSCorLib->SetName(L"mscorlib, Version=2.0.0.0," 
                                   L" Culture=neutral, PublicKeyToken=b77a5c561934e089");
            }
            return m_pMSCorLib;
        }

    private:
        mutable Utilities::AnyPointer m_pMSCorLib;
    };


    class Instruction
    {
    public:
        Instruction() : 
            m_pOpCode(NULL)
        { }
    
        OpCodeProtoB8DF5A21 const &GetOpCode() const
        {
            return *m_pOpCode;
        }
        
        void SetOpCode(OpCodeProtoB8DF5A21 const &opCode)
        {
            m_pOpCode = &opCode;
        }

        boost::any const &GetOprand() const
        {
            return m_oprand;
        }

        void SetOprand(boost::any const &oprand)
        {
            m_oprand = oprand;
        }

    private:
        OpCodeProtoB8DF5A21 const *m_pOpCode;
        boost::any m_oprand;
    };
    
    struct IILGeneratorApi { };

    struct DefaultILGeneratorApiProtoB8DF5A21 : 
        IILGeneratorApi
    { 
        typedef boost::mpl::vector<DefaultMethodMetadataApiProtoB8DF5A21> external_api_types;
    };

    template<
        class ILGeneratorApiType = DefaultILGeneratorApiProtoB8DF5A21
    >
    class BaseILGeneratorProtoB8DF5A21 :
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator>
            >
        >
    {
    public:
        typedef BaseILGeneratorProtoB8DF5A21<ILGeneratorApiType> this_type;

        typedef typename Traits::ExternalApiOrDefault<ILGeneratorApiType, IILGeneratorApi, IMethodMetadataApi>::type method_metadata_api_type;
        typedef BaseMethodMetadataProtoB8DF5A21<method_metadata_api_type> method_metadata_type;

        typedef typename Traits::ExternalApiOrDefault<method_metadata_api_type, IMethodMetadataApi, ITypeMetadataApi>::type type_metadata_api_type;
        typedef BaseTypeMetadataProtoB8DF5A21<type_metadata_api_type> type_metadata_type;

        typedef typename Traits::ExternalApiOrDefault<type_metadata_api_type, ITypeMetadataApi, IAssemblyMetadataApi>::type assembly_metadata_api_type;
        typedef BaseAssemblyMetadataProtoB8DF5A21<assembly_metadata_api_type> assembly_metadata_type;

        typedef typename Traits::ExternalApiOrDefault<assembly_metadata_api_type, IAssemblyMetadataApi, IMetadataDispenserApi>::type metadata_dispenser_api_type;
        typedef BaseMetadataDispenserProtoB8DF5A21<metadata_dispenser_api_type> metadata_dispenser_type;

        typedef ObjectTag<Instruction, VeryQuickHeapButMustUseSubscriptOperator> instruction_obj_tag_type;
        typedef typename type_decided_by<instruction_obj_tag_type>::type instruction_heap_type;

        BaseILGeneratorProtoB8DF5A21() : 
            m_pMethodMeta(NULL),
            m_instructionsInitialized(false)
        { }
        
        void Init(method_metadata_type &methodMeta) const
        {
            _ASSERTE(m_pMethodMeta == NULL);
            
            m_pMethodMeta = &methodMeta;
        }

        template<class T>
        T const *FindType() const { return static_cast<method_metadata_type const *>(m_pMethodMeta)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMethodMeta->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        void EmitWriteLine(LPCWSTR s)
        {
            typedef OpCodesProtoB8DF5A21 OpCodes;
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Ldstr);
                pInst->SetOprand(std::wstring(s));
            }
            {
                Instruction *pInst = InstructionHeap().New();
                pInst->SetOpCode(OpCodes::Call);

                this_type const *immutableThis = this;

                metadata_dispenser_type const *pMetaDisp = immutableThis->FindType<metadata_dispenser_type>();
                
                std::wstring const msCorLibName(L"mscorlib, Version=2.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089");
                assembly_metadata_type const *pMSCorLib = pMetaDisp->LoadAssembly(msCorLibName);
                
                std::wstring const consoleName(L"System.Console");
                type_metadata_type const *pConsole = pMSCorLib->GetType(consoleName, TypeKinds::TK_CLASS);
                
                std::wstring const writeLineName(L"WriteLine");
                CallingConventions cc = CallingConventions::CC_STANDARD;
                type_metadata_type const *pRetType = pMSCorLib->GetType(L"System.Void", TypeKinds::TK_VOID);
                std::vector<type_metadata_type const *> paramTypes;
                paramTypes.push_back(pMSCorLib->GetType(L"System.String", TypeKinds::TK_STRING));
                method_metadata_type const *pWriteLine = pConsole->GetMethod(writeLineName, cc, pRetType, paramTypes);

                pInst->SetOprand(pWriteLine);
            }
            m_instructionsInitialized = false;
        }

        void Emit(OpCodeProtoB8DF5A21 const &op)
        {
            Instruction *pInst = InstructionHeap().New();
            pInst->SetOpCode(op);
            m_instructionsInitialized = false;
        }

        std::vector<Instruction const *> const &GetInstructions() const
        {
            if (!m_instructionsInitialized)
            {
                SIZE_T size = InstructionHeap().Size();
                std::vector<Instruction const *> instructions(size);
                for (SIZE_T i = 0; i < size; ++i)
                    instructions[i] = InstructionHeap()[i];
                instructions.swap(m_instructions);
                m_instructionsInitialized = true;
            }
            return m_instructions;
        }

    private:
        instruction_heap_type &InstructionHeap()
        {
            return Of<instruction_obj_tag_type>();
        }
        
        instruction_heap_type const &InstructionHeap() const
        {
            return Of<instruction_obj_tag_type>();
        }

        mutable method_metadata_type *m_pMethodMeta;
        mutable bool m_instructionsInitialized;
        mutable std::vector<Instruction const *> m_instructions;
    };

    typedef BaseILGeneratorProtoB8DF5A21<> ILGeneratorProtoB8DF5A21;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test.*
namespace {

    void SetupApis(boost::filesystem::path const &asmPath, 
                   std::wstring const &typeName, 
                   IMetaDataDispenserEx **ppMetaDispApi, 
                   IMetaDataImport2 **ppMetaImpApi, 
                   mdTypeDef &mdtd)
    {
        namespace fs = boost::filesystem;

        ASSERT_HRESULT_SUCCEEDED(
            ::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, 
                               CLSCTX_INPROC_SERVER, 
                               IID_IMetaDataDispenserEx, 
                               reinterpret_cast<void **>(ppMetaDispApi))
        ); 

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaDispApi)->OpenScope(asmPath.c_str(), ofRead, 
                                        IID_IMetaDataImport2, 
                                        reinterpret_cast<IUnknown **>(ppMetaImpApi))
        );

        ASSERT_HRESULT_SUCCEEDED(
            (*ppMetaImpApi)->FindTypeDefByName(typeName.c_str(), NULL, &mdtd)
        );
    }

    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        std::wstring typeName(L"System.Func`1");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);
        mdToken mdt = typeMeta.GetToken();


        // Assert
        ASSERT_EQ(0x02000058, mdt);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_02)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi;

        struct TestMethodMetadataApi : 
            IMethodMetadataApi
        {
            typedef boost::mpl::vector<TestTypeMetadataApi, IMetaDataImport2> external_api_types;
        };

        struct TestTypeMetadataApi : 
            ITypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        fs::path asmPath(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        std::wstring typeName(L"System.Func`1");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);

        
        std::wstring name(L".ctor");
        
        CallingConventions callConvention = CallingConventions::CC_HAS_THIS;
        
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VOID);
        
        std::vector<TypeMetadata const *> paramTypes;
        TypeMetadata paramType0(TypeKinds::TK_OBJECT);
        paramTypes.push_back(&paramType0);
        TypeMetadata paramType1(TypeKinds::TK_I);
        paramTypes.push_back(&paramType1);
        
        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        ASSERT_FALSE(pMethodMeta == NULL);
        mdToken mdt = pMethodMeta->GetToken();

        MethodMetadata const *pMethodMeta2 = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);


        // Assert
        ASSERT_EQ(0x06000232, mdt);
        ASSERT_EQ(pMethodMeta, pMethodMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_03)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        // Arrange
        struct TestTypeMetadataApi;

        struct TestMethodMetadataApi : 
            IMethodMetadataApi
        {
            typedef boost::mpl::vector<TestTypeMetadataApi, IMetaDataImport2> external_api_types;
        };

        struct TestTypeMetadataApi : 
            ITypeMetadataApi  
        {
            typedef INT assembly_metadata_api_type;
            typedef INT method_metadata_api_type;
            typedef boost::mpl::vector<TestMethodMetadataApi, IMetaDataImport2> external_api_types;
        };

        typedef BaseTypeMetadataProtoB8DF5A21<TestTypeMetadataApi> TypeMetadata;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;
        typedef TypeMetadata::method_metadata_type MethodMetadata;

        fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
        std::wstring typeName(L"System.DateTime");
        ATL::CComPtr<IMetaDataDispenserEx> pMetaDispApi;
        ATL::CComPtr<IMetaDataImport2> pMetaImpApi;
        mdTypeDef mdtd = mdTypeDefNil;
        SetupApis(asmPath, typeName, &pMetaDispApi, &pMetaImpApi, mdtd);


        // Act
        AssemblyMetadata asmMeta;
        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);
        typeMeta.SetKey(mdtd);

        
        std::wstring name(L"get_Now");
        
        CallingConventions callConvention = CallingConventions::CC_STANDARD;
        
        TypeMetadata retType;
        retType.SetKind(TypeKinds::TK_VALUETYPE);
        retType.SetKey(mdtd);
        
        std::vector<TypeMetadata const *> paramTypes;

        MethodMetadata const *pMethodMeta = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);
        ASSERT_FALSE(pMethodMeta == NULL);
        mdToken mdt = pMethodMeta->GetToken();

        MethodMetadata const *pMethodMeta2 = typeMeta.GetMethod(name, callConvention, &retType, paramTypes);


        // Assert
        ASSERT_EQ(0x060002D2, mdt);
        ASSERT_EQ(pMethodMeta, pMethodMeta2);
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_04)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;
     
        typedef OpCodesProtoB8DF5A21 OpCodes;
        ASSERT_STREQ(L"CEE_NOP,nop,Pop0,Push0,InlineNone,IPrimitive,1,0xFF,0x00,NEXT", OpCodes::Nop.CStr());
        ASSERT_EQ(OpCodeTypes::CEE_NOP, OpCodes::Nop.GetType().Value());
        ASSERT_STREQ(L"nop", OpCodes::Nop.GetName().c_str());
        ASSERT_EQ(StackBehaviourTypes::SBT_POP0, OpCodes::Nop.GetBehaviour0().GetType().Value());
        ASSERT_EQ(StackBehaviourTypes::SBT_PUSH0, OpCodes::Nop.GetBehaviour1().GetType().Value());
        ASSERT_EQ(OperandParamTypes::OPT_INLINE_NONE, OpCodes::Nop.GetOperandParam().GetType().Value());
        ASSERT_EQ(OpCodeKindTypes::OKT_I_PRIMITIVE, OpCodes::Nop.GetOpCodeKind().GetType().Value());
        ASSERT_EQ(1, OpCodes::Nop.GetLength());
        ASSERT_EQ(0xFF, OpCodes::Nop.GetByte1());
        ASSERT_EQ(0x00, OpCodes::Nop.GetByte2());
        ASSERT_EQ(ControlFlowTypes::CFT_NEXT, OpCodes::Nop.GetControlFlow().GetType().Value());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_05)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
        expected += StackBehaviours::PopRef();
     
        typedef OpCodesProtoB8DF5A21 OpCodes;
        ASSERT_STREQ(L"CEE_STELEM_REF,stelem.ref,PopRef+PopI+PopRef,Push0,InlineNone,IObjModel,1,0xFF,0xA2,NEXT", OpCodes::Stelem_Ref.CStr());
        ASSERT_TRUE(expected == OpCodes::Stelem_Ref.GetBehaviour0());
    }

    
    TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_06)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;

        StackBehaviour expected = StackBehaviours::PopRef();
        expected += StackBehaviours::PopI();
     
        typedef OpCodesProtoB8DF5A21 OpCodes;
        ASSERT_TRUE(expected != OpCodes::Stfld.GetBehaviour0());
    }

    
#define CPPANONYM_TEST(test_case_name, test_name) \
    class GTEST_TEST_CLASS_NAME_(test_case_name, test_name); \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)); \
    TEST(test_case_name, test_name) \
    { \
        using namespace Urasandesu::CppAnonym; \
        try \
        { \
            CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)()); \
        } \
        catch (CppAnonymException &e) \
        { \
            std::cout << boost::diagnostic_information(e) << std::endl; \
            throw; \
        } \
        catch (...) \
        { \
            std::cout << boost::diagnostic_information(boost::current_exception()) << std::endl; \
            throw; \
        } \
    } \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name))

    CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_08)
    {
        using namespace std;
        using namespace Urasandesu::CppAnonym;

        cout << "Hello, World!!" << endl;

        //int i = 10;
        //ASSERT_EQ(3, i);

        BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
    }


    //class ATL_NO_VTABLE MyMetaDataImport;
    //typedef Urasandesu::CppAnonym::Utilities::CComObjectSlim<MyMetaDataImport> MyMetaDataImportObject;

    class ATL_NO_VTABLE MyMetaDataImport : 
        public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
        public Urasandesu::CppAnonym::Metadata::IMetaDataImport2Impl<IMetaDataImport2>
    {
    public:
        MyMetaDataImport() { }

    BEGIN_COM_MAP(MyMetaDataImport)
        COM_INTERFACE_ENTRY_IID(IID_IMetaDataImport2, IMetaDataImport2)
    END_COM_MAP()

        DECLARE_PROTECT_FINAL_CONSTRUCT()

        HRESULT FinalConstruct() { return S_OK; }
        void FinalRelease() { }
    };

    CPPANONYM_TEST(Urasandesu_CppAnonym_Hosting_BaseTypeMetadataProtoB8DF5A21Test, Test_07)
    {
        // TODO: せっかく NotImplementedException スローしてるのに Google Test で丸められちゃう。カスタム class 作ったほうが良さそうね。
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Metadata;
        using boost::any_cast;

        typedef OpCodesProtoB8DF5A21 OpCodes;
        typedef OpCodeProtoB8DF5A21 OpCode;
        typedef ILGeneratorProtoB8DF5A21 ILGenerator;
        typedef ILGeneratorProtoB8DF5A21::method_metadata_type MethodMetadata;
        typedef MethodMetadata::type_metadata_type TypeMetadata;
        typedef MethodMetadata::metadata_import_api_type MetaDataImportApi;
        typedef TypeMetadata::assembly_metadata_type AssemblyMetadata;

        AssemblyMetadata asmMeta;
        
        MyMetaDataImportObject *pMetaImpApi_ = NULL;
        ASSERT_HRESULT_SUCCEEDED(MyMetaDataImportObject::CreateInstance(&pMetaImpApi_)); 
        ATL::CComPtr<MetaDataImportApi> pMetaImpApi(pMetaImpApi_);
        //MetaDataImportApi *pMetaImpApi = NULL;

        TypeMetadata typeMeta;
        typeMeta.Init(asmMeta, *pMetaImpApi);

        MethodMetadata methodMeta;
        methodMeta.Init(typeMeta, *pMetaImpApi); 
        
        ILGenerator gen;
        gen.Init(methodMeta);
        gen.EmitWriteLine(L"Hello, world!!");
        gen.Emit(OpCodes::Ret);

        std::vector<Instruction const *> const &insts = gen.GetInstructions();
        ASSERT_EQ(3, insts.size());
        {
            OpCode const &op = insts[0]->GetOpCode();
            std::wstring const &s = any_cast<std::wstring const &>(insts[0]->GetOprand());
            ASSERT_EQ(&OpCodes::Ldstr, &op);
            ASSERT_STREQ(L"Hello, world!!", s.c_str());
        }
        {
            OpCode const &op = insts[1]->GetOpCode();
            MethodMetadata const *pMethodMeta = any_cast<MethodMetadata const *>(insts[1]->GetOprand());
            ASSERT_EQ(&OpCodes::Call, &op);
            ASSERT_STREQ(L"WriteLine", pMethodMeta->GetName().c_str());
        }
        {
            OpCode const &op = insts[2]->GetOpCode();
            ASSERT_EQ(&OpCodes::Ret, &op);
        }
    }
}
