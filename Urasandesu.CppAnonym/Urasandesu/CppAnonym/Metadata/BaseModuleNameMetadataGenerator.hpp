#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
//#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
//#include <Urasandesu/CppAnonym/ObjectTag.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataApiHolderLabel.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleNameMetadataGeneratorApiHolder
    >    
    class BaseModuleNameMetadataGenerator : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseModuleNameMetadataGenerator<ModuleNameMetadataGeneratorApiHolder> this_type;

        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::AssemblyNameMetadataGeneratorLabel>::type assembly_name_metadata_generator_type;
        typedef typename ModuleNameMetadataGeneratorApiAt<ModuleNameMetadataGeneratorApiHolder, Interfaces::TypeNameMetadataGeneratorLabel>::type type_name_metadata_generator_type;

        typedef ObjectTag<type_name_metadata_generator_type, QuickHeap> type_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<type_name_metadata_generator_obj_tag_type>::type type_name_metadata_generator_heap_type;

        BaseModuleNameMetadataGenerator() : 
            m_pAsmNameGenAsScope(NULL), 
            m_nameInitialized(false)
        { }

        void Init(assembly_name_metadata_generator_type &asmNameGenAsScope) const
        {
            _ASSERTE(m_pAsmNameGenAsScope == NULL);
            m_pAsmNameGenAsScope = &asmNameGenAsScope;
        }

        template<class T>
        T const &Map() const { return const_cast<this_type *>(this)->Map<T>(); }

        template<class T>
        T &Map() 
        { 
            //_ASSERTE(m_pModNameAsScope != NULL || m_pModAsScope != NULL);
            //if (m_pModNameAsScope != NULL)
            //    return m_pModNameAsScope->Map<T>();
            //else
            //    return m_pModAsScope->GetModuleNameCore()->Map<T>();
            _ASSERTE(m_pAsmNameGenAsScope != NULL);
            return m_pAsmNameGenAsScope->Map<T>();
        }
      
        template<>
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                m_nameInitialized = true;
            }
            return m_name;
        }

        type_name_metadata_generator_type *NewTypeNameGenerator(std::wstring const &name, TypeAttributes const &attr)
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            type_name_metadata_generator_type *pTypeNameMetaGen = NULL;
            pTypeNameMetaGen = pMutableThis->TypeNameMetadataGeneratorHeap().New();
            pTypeNameMetaGen->Init(*pMutableThis);
            pTypeNameMetaGen->SetName(name);
            pTypeNameMetaGen->SetAttribute(attr);
            return pTypeNameMetaGen;
        }

    private:
        friend typename assembly_name_metadata_generator_type;

        type_name_metadata_generator_heap_type &TypeNameMetadataGeneratorHeap()
        {
            return Of<type_name_metadata_generator_obj_tag_type>();
        }
        
        type_name_metadata_generator_heap_type const &TypeNameMetadataGeneratorHeap() const
        {
            return Of<type_name_metadata_generator_obj_tag_type>();
        }


        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }

        mutable assembly_name_metadata_generator_type *m_pAsmNameGenAsScope;
        mutable bool m_nameInitialized;
        mutable std::wstring m_name;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULENAMEMETADATAGENERATOR_HPP