#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULEMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP