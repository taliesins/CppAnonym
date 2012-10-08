#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP

//#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
//#include <Urasandesu/CppAnonym/ObjectTag.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
//#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP
//#include <Urasandesu/CppAnonym/Utilities/StackAllocator.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
//#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAAPIHOLDERLABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataApiHolderLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_MODULENAMEMETADATALABEL_HPP
//#include <Urasandesu/CppAnonym/Metadata/Interfaces/ModuleNameMetadataLabel.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
//#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
//#endif

#ifndef URASANDESU_CPPANONYM_METADATA_PORTABLEEXECUTABLEKINDS_HPP
#include <Urasandesu/CppAnonym/Metadata/PortableExecutableKinds.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_IMAGEFILEMACHINE_HPP
#include <Urasandesu/CppAnonym/Metadata/ImageFileMachine.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATAGENERATORAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataGeneratorApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATORFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyNameMetadataGeneratorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyNameMetadataGeneratorApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyNameMetadataGeneratorApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyNameMetadataGeneratorApiHolder
    >    
    class BaseAssemblyNameMetadataGenerator : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyNameMetadataGenerator<AssemblyNameMetadataGeneratorApiHolder> this_type;

        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::AssemblyMetadataGeneratorLabel>::type assembly_metadata_generator_type;
        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, Interfaces::ModuleNameMetadataGeneratorLabel>::type module_name_metadata_generator_type;
        typedef typename AssemblyNameMetadataGeneratorApiAt<AssemblyNameMetadataGeneratorApiHolder, StrongNaming::Interfaces::StrongNameKeyLabel>::type strong_name_key_type;

        typedef ObjectTag<module_name_metadata_generator_type, QuickHeap> module_name_metadata_generator_obj_tag_type;
        typedef typename type_decided_by<module_name_metadata_generator_obj_tag_type>::type module_name_metadata_generator_heap_type;

        BaseAssemblyNameMetadataGenerator() : 
            m_pDispAsScope(NULL), 
            m_nameInitialized(false), 
            m_pResolvedAsmGen(NULL), 
            m_pSnKey(NULL)
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
        this_type const &Map<this_type>() const { return const_cast<this_type *>(this)->Map<this_type>(); }
      
        template<>
        this_type &Map<this_type>() { return *this; }

        std::wstring const &GetName() const
        {
            if (!m_nameInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        strong_name_key_type const *GetStrongNameKey() const
        {
            return m_pSnKey;
        }

        void SetStrongNameKey(strong_name_key_type const &snKey)
        {
            m_pSnKey = &snKey;
        }

        module_name_metadata_generator_type *NewModuleNameGenerator(std::wstring const &name) const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);

            module_name_metadata_generator_type *pModNameMetaGen = NULL;
            pModNameMetaGen = pMutableThis->ModuleNameMetadataGeneratorHeap().New();
            pModNameMetaGen->Init(*pMutableThis);
            pModNameMetaGen->SetName(name);
            return pModNameMetaGen;
        }

        assembly_metadata_generator_type *Resolve()
        {
            return ResolveCore();
        }

    private:
        friend typename metadata_dispenser_type;

        module_name_metadata_generator_heap_type &ModuleNameMetadataGeneratorHeap()
        {
            return Of<module_name_metadata_generator_obj_tag_type>();
        }
        
        module_name_metadata_generator_heap_type const &ModuleNameMetadataGeneratorHeap() const
        {
            return Of<module_name_metadata_generator_obj_tag_type>();
        }

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!m_nameInitialized);
            m_name = name;
            m_nameInitialized = true;
        }
        
        assembly_metadata_generator_type *ResolveCore()
        {
            if (m_pResolvedAsmGen == NULL)
            {
                metadata_dispenser_type &metaDisp = Map<metadata_dispenser_type>();
                m_pResolvedAsmGen = metaDisp.DefineAssembly(GetName(), *GetStrongNameKey());
            }
            return m_pResolvedAsmGen;
        }

        mutable metadata_dispenser_type *m_pDispAsScope;
        mutable bool m_nameInitialized;
        mutable std::wstring m_name;
        mutable assembly_metadata_generator_type *m_pResolvedAsmGen;
        mutable strong_name_key_type const *m_pSnKey;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYNAMEMETADATAGENERATOR_HPP