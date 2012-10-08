#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSERFWD_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenserFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenserApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataDispenserApiHolderLabel, ApiLabel>
    {
    };

    namespace MetadataDispenserDetail {

        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        template<
            class MetadataDispenserApiHolder
        >    
        struct MetadataDispenserFacade
        {
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataInfoLabel>::type metadata_info_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataDispenserLabel>::type metadata_dispenser_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, AssemblyMetadataLabel>::type assembly_metadata_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, AssemblyMetadataPersistedHandlerLabel>::type assembly_metadata_persisted_handler_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, ModuleMetadataLabel>::type module_metadata_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, ModuleMetadataPersistedHandlerLabel>::type module_metadata_persisted_handler_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, TypeMetadataLabel>::type type_metadata_type;
            typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, TypeMetadataPersistedHandlerLabel>::type type_metadata_persisted_handler_type;
            //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, MetadataDispenserPersistedHandlerLabel>::type metadata_dispenser_persisted_handler_type;
            //typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type,
            //typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataLabel>::type,
            //typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type

            
            typedef mpl::vector<
                DisposingInfo<assembly_metadata_type, assembly_metadata_persisted_handler_type>,
                DisposingInfo<module_metadata_type, module_metadata_persisted_handler_type>,
                DisposingInfo<type_metadata_type, type_metadata_persisted_handler_type>
            > disposing_info_types;
            typedef DisposableHeapProvider<disposing_info_types> base_heap_provider_type;


            typedef typename base_heap_provider_type::provider_of<assembly_metadata_type>::type assembly_metadata_provider_type;
            typedef typename base_heap_provider_type::provider_of<module_metadata_type>::type module_metadata_provider_type;
            typedef typename base_heap_provider_type::provider_of<type_metadata_type>::type type_metadata_provider_type;


            //CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(MetadataDispenserProvider, metadata_dispenser_provider_type);
            //CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(MetadataDispenserProvider, metadata_dispenser_provider_type);
            //typedef typename mpl::eval_if<
            //    CPP_ANONYM_HAS_MEMBER_TYPE(MetadataDispenserProvider, metadata_info_type), 
            //    CPP_ANONYM_GET_MEMBER_TYPE(MetadataDispenserProvider, metadata_info_type), 
            //    mpl::void_
            //>::type metadata_dispenser_provider_type;


            typedef metadata_info_type metadata_dispenser_previous_type;
            
            
            typedef mpl::vector<
                SmartPtrChainInfo<metadata_dispenser_previous_type>
            > chain_info_types;
            typedef SmartPtrChain<metadata_dispenser_type, chain_info_types> base_ptr_chain_type;
            
            
            typedef typename base_ptr_chain_type::chain_from<metadata_dispenser_previous_type>::type metadata_dispenser_chain_type;
        };

    }   // namespace MetadataDispenserDetail {

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenser : 
        public MetadataDispenserDetail::MetadataDispenserFacade<MetadataDispenserApiHolder>::base_ptr_chain_type, 
        public MetadataDispenserDetail::MetadataDispenserFacade<MetadataDispenserApiHolder>::base_heap_provider_type,
        //public SmartPtrChain<
        //    BaseMetadataDispenser<MetadataDispenserApiHolder>,
        //    boost::mpl::vector<
        //        SmartPtrChainInfo<typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type>
        //    >
        //>,
        //public DisposableHeapProvider<
        //    boost::mpl::vector<
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataLabel>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type
        //    >
        //>,
        //public DisposableHeapProvider<
        //    boost::mpl::vector<
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataLabel>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataGenerator7FAEDE99Label>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataGenerator7FAEDE99Label>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::FieldMetadataGenerator7FAEDE99Label>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataGenerator7FAEDE99Label>::type,
        //        typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::PropertyMetadataGenerator7FAEDE99Label>::type
        //    >
        //>,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataDispenser<MetadataDispenserApiHolder> this_type;

        typedef MetadataDispenserDetail::MetadataDispenserFacade<MetadataDispenserApiHolder> facade;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::assembly_metadata_type assembly_metadata_type;
        typedef typename facade::assembly_metadata_persisted_handler_type assembly_metadata_persisted_handler_type;
        typedef typename facade::module_metadata_type module_metadata_type;
        typedef typename facade::module_metadata_persisted_handler_type module_metadata_persisted_handler_type;
        typedef typename facade::type_metadata_type type_metadata_type;
        typedef typename facade::type_metadata_persisted_handler_type type_metadata_persisted_handler_type;
        typedef typename facade::assembly_metadata_provider_type assembly_metadata_provider_type;
        typedef typename facade::module_metadata_provider_type module_metadata_provider_type;
        typedef typename facade::type_metadata_provider_type type_metadata_provider_type;
        typedef typename facade::metadata_dispenser_previous_type metadata_dispenser_previous_type;
        typedef typename facade::metadata_dispenser_chain_type metadata_dispenser_chain_type;

        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::IAssemblyMetadataHashLabel>::type i_assembly_metadata_hash_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;
        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataGenerator7FAEDE99Label>::type assembly_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataGenerator7FAEDE99Label>::type module_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type type_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::FieldMetadataGenerator7FAEDE99Label>::type field_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataGenerator7FAEDE99Label>::type method_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::PropertyMetadataGenerator7FAEDE99Label>::type property_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;

        //typedef int assembly_metadata_type;
        //typedef typename providing_type_at<0>::type assembly_metadata_type;
        //typedef int module_metadata_type;
        //typedef typename providing_type_at<1>::type module_metadata_type;        

        //typedef int module_metadata_provider_type;
        //typedef int type_metadata_provider_type;
        typedef int method_metadata_provider_type;
        typedef int assembly_metadata_generator_provider_type;
        typedef int module_metadata_generator_provider_type;
        typedef int type_metadata_generator_provider_type;
        typedef int field_metadata_generator_provider_type;
        typedef int method_metadata_generator_provider_type;
        typedef int property_metadata_generator_provider_type;
        //typedef typename provider_of<assembly_metadata_type>::type assembly_metadata_provider_type;
        //typedef typename provider_of<module_metadata_type>::type module_metadata_provider_type;
        //typedef typename provider_of<type_metadata_type>::type type_metadata_provider_type;
        //typedef typename provider_of<method_metadata_type>::type method_metadata_provider_type;
        //typedef typename provider_of<assembly_metadata_generator_type>::type assembly_metadata_generator_provider_type;
        //typedef typename provider_of<module_metadata_generator_type>::type module_metadata_generator_provider_type;
        //typedef typename provider_of<type_metadata_generator_type>::type type_metadata_generator_provider_type;
        //typedef typename provider_of<field_metadata_generator_type>::type field_metadata_generator_provider_type;
        //typedef typename provider_of<method_metadata_generator_type>::type method_metadata_generator_provider_type;
        //typedef typename provider_of<property_metadata_generator_type>::type property_metadata_generator_provider_type;

        //typedef int metadata_dispenser_previous_type;
        //typedef int metadata_dispenser_chain_type;
        //typedef int metadata_info_type;
        //typedef typename chaining_previous_type_at<0>::type metadata_dispenser_previous_type;
        //typedef typename chain_from<metadata_dispenser_previous_type>::type metadata_dispenser_chain_type; 
        //typedef metadata_dispenser_previous_type metadata_info_type;

        BaseMetadataDispenser()
        { }

        assembly_metadata_type const *GetAssembly(std::wstring const &fullName) const
        {
            using namespace Urasandesu::CppAnonym::Utilities;
            
            TempPtr<assembly_metadata_type> pNewAsm = NewAssembly(fullName);

            assembly_metadata_type *pExistingAsm;
            if (!TryGetAssembly(*pNewAsm, pExistingAsm))
            {
                pNewAsm.Persist();
                return pNewAsm.Get();
            }
            else
            {
                return pExistingAsm;
            }
        }

        boost::shared_ptr<assembly_metadata_generator_type> DefineAssembly(std::wstring const &fullName)
        {
            boost::shared_ptr<assembly_metadata_generator_type> pNewAsmGen;
            pNewAsmGen = NewAssemblyGenerator(fullName);

            boost::shared_ptr<assembly_metadata_generator_type> pExistingAsmGen;
            if (!TryGetAssemblyGenerator(*pNewAsmGen, pExistingAsmGen))
            {
                assembly_metadata_generator_provider_type &provider = ProviderOf<assembly_metadata_generator_type>();
                m_asmGenToIndex[pNewAsmGen] = provider.Register(pNewAsmGen);
                return pNewAsmGen;
            }
            else
            {
                return pExistingAsmGen;
            }
        }

    private:
        friend typename metadata_dispenser_previous_type;
        friend typename assembly_metadata_type;
        friend typename assembly_metadata_persisted_handler_type;

        Utilities::TempPtr<assembly_metadata_type> NewAssembly(std::wstring const &fullName) const
        {
            using namespace Urasandesu::CppAnonym::Utilities;

            assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
            metadata_dispenser_chain_type &chain = ChainFrom<metadata_dispenser_previous_type>();
            TempPtr<assembly_metadata_type> pAsm = chain.NewObject<assembly_metadata_type>(provider);
            pAsm->SetName(fullName);
            assembly_metadata_persisted_handler_type handler(const_cast<this_type *>(this));
            provider.AddPersistedHandler(pAsm, handler);
            //struct pAsm_Persisted
            //{
            //    typedef TempPtr<assembly_metadata_type> sender_type;

            //    pAsm_Persisted(this_type &this_) : 
            //        m_pThis(&this_)
            //    { }
            //    
            //    void operator()(sender_type *pSender, void *pArg)
            //    {
            //        sender_type &pAsm = *pSender;
            //        assembly_metadata_provider_type &provider = m_pThis->ProviderOf<assembly_metadata_type>();
            //        m_pThis->m_asmToIndex[pAsm.Get()] = provider.RegisterObject(pAsm);
            //    }
            //    
            //    this_type *m_pThis;
            //};
            //pAsm.AddPersistedHandler(pAsm_Persisted(const_cast<this_type &>(*this)));
            return pAsm;
        }

        bool TryGetAssembly(assembly_metadata_type const &keyAsm, assembly_metadata_type *&pExistingAsm) const
        {
            if (m_asmToIndex.find(&keyAsm) == m_asmToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_asmToIndex[&keyAsm];
                assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
                pExistingAsm = provider.GetObject(index);
                return true;
            }
        }

        boost::shared_ptr<assembly_metadata_generator_type> NewAssemblyGenerator(std::wstring const &fullName) const
        {
            assembly_metadata_generator_provider_type &provider = ProviderOf<assembly_metadata_generator_type>();
            metadata_dispenser_chain_type &chain = ChainFrom<metadata_info_type>();
            boost::shared_ptr<assembly_metadata_generator_type> pAsmGen = chain.NewObject<assembly_metadata_generator_type>(provider);
            pAsmGen->SetName(fullName);
            return pAsmGen;
        }

        bool TryGetAssemblyGenerator(assembly_metadata_generator_type const &keyAsmGen, boost::shared_ptr<assembly_metadata_generator_type> &pExistingAsmGen) const
        {
            boost::shared_ptr<assembly_metadata_generator_type const> pKeyAsmGen(&keyAsmGen, Utilities::MakeNullDeleter(&keyAsmGen));
            if (m_asmGenToIndex.find(pKeyAsmGen) == m_asmGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_asmGenToIndex[pKeyAsmGen];
                assembly_metadata_generator_provider_type &provider = ProviderOf<assembly_metadata_generator_type>();
                pExistingAsmGen = provider[index];
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

        mutable boost::unordered_map<assembly_metadata_type const *, 
                                     size_t, 
                                     i_assembly_metadata_hash_type, 
                                     i_assembly_metadata_equal_to_type> m_asmToIndex;
        //mutable boost::unordered_map<boost::shared_ptr<assembly_metadata_generator_type const>, 
        //                             size_t, 
        //                             i_assembly_metadata_hash_type, 
        //                             i_assembly_metadata_equal_to_type> m_asmGenToIndex;        
        mutable ATL::CComPtr<com_meta_data_dispenser_type> m_pComMetaDisp;
    };





    namespace MetadataDispenserDetail {

        template<
            class MetadataDispenserApiHolder
        >    
        struct MetadataDispenserPersistedHandlerFacade : 
            MetadataDispenserFacade<MetadataDispenserApiHolder>
        {
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(MetadataDispenserProvider, metadata_dispenser_provider_type);
            CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(MetadataDispenserProvider, metadata_dispenser_provider_type);
            typedef typename mpl::eval_if<
                CPP_ANONYM_HAS_MEMBER_TYPE(MetadataDispenserProvider, metadata_info_type), 
                CPP_ANONYM_GET_MEMBER_TYPE(MetadataDispenserProvider, metadata_info_type), 
                mpl::void_
            >::type metadata_dispenser_provider_type;
        };

    }   // namespace MetadataDispenserDetail {

    template<
        class MetadataDispenserApiHolder
    >    
    class BaseMetadataDispenserPersistedHandler
    {
    public:
        typedef MetadataDispenserDetail::MetadataDispenserPersistedHandlerFacade<MetadataDispenserApiHolder> facade;
        typedef typename facade::metadata_info_type metadata_info_type;
        typedef typename facade::metadata_dispenser_type metadata_dispenser_type;
        typedef typename facade::metadata_dispenser_provider_type metadata_dispenser_provider_type;
        
        typedef Utilities::TempPtr<metadata_dispenser_type> sender_type;

        BaseMetadataDispenserPersistedHandler(metadata_info_type *pMetaInfo) : 
            m_pMetaInfo(pMetaInfo)
        { }
        
        void operator()(sender_type *pSender, void *pArg)
        {
            sender_type &pDisp = *pSender;
            metadata_dispenser_provider_type &provider = m_pMetaInfo->ProviderOf<metadata_dispenser_type>();
            provider.RegisterObject(pDisp);
        }

    private:        
        metadata_info_type *m_pMetaInfo;
    //public:
    //    typedef RuntimeHostDetail::RuntimeHostPersistedHandlerFacade<RuntimeHostApiHolder> facade;
    //    typedef typename facade::host_info_type host_info_type;
    //    typedef typename facade::runtime_host_type runtime_host_type;
    //    typedef typename facade::runtime_host_provider_type runtime_host_provider_type;

    //    typedef Utilities::TempPtr<runtime_host_type> sender_type;

    //    BaseRuntimeHostPersistedHandler(host_info_type *pHostInfo, std::wstring const &version) : 
    //        m_pHostInfo(pHostInfo),
    //        m_version(version)
    //    { }
    //            
    //    void operator()(sender_type *pSender, void *pArg)
    //    {
    //        sender_type &pRuntime = *pSender;
    //        runtime_host_provider_type &provider = m_pHostInfo->ProviderOf<runtime_host_type>();
    //        m_pHostInfo->m_versionToIndex[m_version] = provider.RegisterObject(pRuntime);
    //    }

    //private:                
    //    host_info_type *m_pHostInfo;
    //    std::wstring m_version;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP