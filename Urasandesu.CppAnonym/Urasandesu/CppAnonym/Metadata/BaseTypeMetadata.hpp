#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP