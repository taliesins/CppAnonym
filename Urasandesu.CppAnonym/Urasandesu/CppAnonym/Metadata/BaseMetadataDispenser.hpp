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
                typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type
            >
        >,
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

        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabel>::type assembly_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::IAssemblyMetadataHashLabel>::type i_assembly_metadata_hash_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::IAssemblyMetadataEqualToLabel>::type i_assembly_metadata_equal_to_type;
        //typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataLabel>::type module_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataLabel>::type method_metadata_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataGenerator7FAEDE99Label>::type assembly_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::ModuleMetadataGenerator7FAEDE99Label>::type module_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type type_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::FieldMetadataGenerator7FAEDE99Label>::type field_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::MethodMetadataGenerator7FAEDE99Label>::type method_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, Interfaces::PropertyMetadataGenerator7FAEDE99Label>::type property_metadata_generator_type;
        typedef typename MetadataDispenserApiAt<MetadataDispenserApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;

        typedef typename providing_type_at<0>::type assembly_metadata_type;
        typedef typename providing_type_at<1>::type module_metadata_type;        

        typedef typename provider_of<assembly_metadata_type>::type assembly_metadata_provider_type;
        typedef typename provider_of<module_metadata_type>::type module_metadata_provider_type;
        typedef typename provider_of<type_metadata_type>::type type_metadata_provider_type;
        typedef typename provider_of<method_metadata_type>::type method_metadata_provider_type;
        typedef typename provider_of<assembly_metadata_generator_type>::type assembly_metadata_generator_provider_type;
        typedef typename provider_of<module_metadata_generator_type>::type module_metadata_generator_provider_type;
        typedef typename provider_of<type_metadata_generator_type>::type type_metadata_generator_provider_type;
        typedef typename provider_of<field_metadata_generator_type>::type field_metadata_generator_provider_type;
        typedef typename provider_of<method_metadata_generator_type>::type method_metadata_generator_provider_type;
        typedef typename provider_of<property_metadata_generator_type>::type property_metadata_generator_provider_type;

        typedef typename chaining_previous_type_at<0>::type metadata_dispenser_previous_type;
        typedef typename chain_from<metadata_dispenser_previous_type>::type metadata_dispenser_chain_type; 
        typedef metadata_dispenser_previous_type metadata_info_type;

        BaseMetadataDispenser()
        { }

        assembly_metadata_type const *GetAssembly(std::wstring const &fullName) const
        {
            TempPtr<assembly_metadata_type> pNewAsm = NewAssembly(fullName);

            assembly_metadata_type *pExistingAsm;
            if (!TryGetAssembly(*pNewAsm, pExistingAsm))
            {
                assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
                m_asmToIndex[pNewAsm.Get()] = provider.RegisterObject(pNewAsm);
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

        Utilities::TempPtr<assembly_metadata_type> NewAssembly(std::wstring const &fullName) const
        {
            assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
            metadata_dispenser_chain_type &chain = ChainFrom<metadata_dispenser_previous_type>();
            TempPtr<assembly_metadata_type> pAsm = chain.NewObject<assembly_metadata_type>(provider);
            pAsm->SetName(fullName);
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

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP