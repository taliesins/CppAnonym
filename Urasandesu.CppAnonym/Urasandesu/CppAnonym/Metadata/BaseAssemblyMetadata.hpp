#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

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

                fusion_info_type const *pFuInfo = Map<fusion_info_type>();
                assembly_info_type *pAsmInfo;
                pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, m_name); // [2012/09/03 22:17:56] この辺実装中。。。まだまだビルドは通らない。
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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP