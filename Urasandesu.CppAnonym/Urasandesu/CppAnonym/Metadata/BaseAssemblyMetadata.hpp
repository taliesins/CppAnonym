#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
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
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyMetadata<AssemblyMetadataApiHolder> this_type;
        
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef IMetaDataImport2 metadata_import_api_type;

        typedef ObjectTag<type_metadata_type, QuickHeap> type_metadata_obj_tag_type;
        typedef typename type_decided_by<type_metadata_obj_tag_type>::type type_metadata_heap_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(AsmNameMeta, type_name_metadata_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(AsmNameMeta, type_name_metadata_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(AsmNameMeta, type_name_metadata_heap_type, assembly_name_metadata_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(AsmNameMeta, type_name_metadata_heap_type, assembly_name_metadata_type), 
            boost::mpl::void_
        >::type type_name_metadata_heap_type;

        BaseAssemblyMetadata() : 
            m_mda(mdAssemblyNil),
            m_pMetaDisp(NULL), 
            m_pAsmNameMeta(NULL), 
            m_openFlags(ofRead)
        { }

        void Init(metadata_dispenser_type &metaDisp) const
        {
            _ASSERTE(m_pMetaDisp == NULL);
            m_pMetaDisp = &metaDisp;
        }

        template<class T>
        T const *FindType() const { _ASSERTE(m_pMetaDisp != NULL); return static_cast<metadata_dispenser_type const *>(m_pMetaDisp)->FindType<T>(); }

        template<class T>
        T *FindType() { _ASSERTE(m_pMetaDisp != NULL); return m_pMetaDisp->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        type_name_metadata_type *NewTypeName(std::wstring const &name, TypeKinds const &kind) const
        {
            return GetAssemblyName()->NewTypeName(name, kind);
        }

        mdAssembly GetToken() const
        {
            if (m_mda == mdAssemblyNil)
            {
                this_type *mutableThis = const_cast<this_type *>(this);
                com_meta_data_assembly_import_type &comMetaAsmImp = mutableThis->GetCOMMetaDataAssemblyImport();
                mdAssembly mda = mdAssemblyNil;
                HRESULT hr = comMetaAsmImp.GetAssemblyFromScope(&mda);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_mda = mda;
            }

            return m_mda;
        }

        type_metadata_type const *GetType(std::wstring const &name) const
        {
            if (m_typeStrNameToIndex.find(name) == m_typeStrNameToIndex.end())
            {
                m_typeStrNameToIndex[name] = MAXULONG_PTR;
            }

            SIZE_T index = m_typeStrNameToIndex[name];
            if (index == MAXULONG_PTR)
            {
                this_type *mutableThis = const_cast<this_type *>(this);

                com_meta_data_import_type &comMetaImp = mutableThis->GetCOMMetaDataImport();

                mdTypeDef mdtd = mdTypeDefNil;
                HRESULT hr = comMetaImp.FindTypeDefByName(name.c_str(), NULL, &mdtd);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                type_metadata_type *pTypeMeta = mutableThis->TypeMetadataHeap().New();
                pTypeMeta->Init(*mutableThis);
                pTypeMeta->SetToken(mdtd);

                m_typeStrNameToIndex[name] = mutableThis->TypeMetadataHeap().Size() - 1;
                m_typeTokenToIndex[mdtd] = mutableThis->TypeMetadataHeap().Size() - 1;

                return pTypeMeta;
            }
            else
            {
                return TypeMetadataHeap()[index];
            }
        }

        type_metadata_type const *GetType(mdToken mdtType) const
        {
            if (TypeFromToken(mdtType) == mdtTypeRef)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            else if (TypeFromToken(mdtType) == mdtTypeDef)
            {
                if (m_typeTokenToIndex.find(mdtType) == m_typeTokenToIndex.end())
                {
                    m_typeTokenToIndex[mdtType] = MAXULONG_PTR;
                }

                SIZE_T index = m_typeTokenToIndex[mdtType];
                if (index == MAXULONG_PTR)
                {
                    this_type *mutableThis = const_cast<this_type *>(this);

                    type_metadata_type *pTypeMeta = mutableThis->TypeMetadataHeap().New();
                    pTypeMeta->Init(*mutableThis);
                    pTypeMeta->SetToken(mdtType);

                    std::wstring name = pTypeMeta->GetTypeName()->GetName();
                    m_typeStrNameToIndex[name] = mutableThis->TypeMetadataHeap().Size() - 1;

                    return pTypeMeta;
                }
                else
                {
                    return TypeMetadataHeap()[index];
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
        }

        assembly_name_metadata_type const *GetAssemblyName() const
        {
            if (m_pAsmNameMeta == NULL)
            {
                this_type *mutableThis = const_cast<this_type *>(this);
                metadata_dispenser_type *pMetaDisp = NULL;
                pMetaDisp = mutableThis->FindType<metadata_dispenser_type>();

                m_pAsmNameMeta = pMetaDisp->AssemblyNameMetadataHeap().New();
                m_pAsmNameMeta->SetResolutionScope(*m_pMetaDisp);
                m_pAsmNameMeta->SetToken(GetToken());
                m_pAsmNameMeta->SetResolvedAssembly(*mutableThis);
            }
            return m_pAsmNameMeta;
        }

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadata;

        template<
            class TypeNameMetadataApiHolder
        >
        friend class BaseTypeNameMetadata;

        template<
            class MetadataDispenserApiHolder
        >    
        friend class BaseMetadataDispenser;

        template<
            class AssemblyNameMetadataApiHolder
        >    
        friend class BaseAssemblyNameMetadata;

        type_metadata_heap_type &TypeMetadataHeap()
        {
            return Of<type_metadata_obj_tag_type>();
        }
        
        type_metadata_heap_type const &TypeMetadataHeap() const
        {
            return Of<type_metadata_obj_tag_type>();
        }

        type_name_metadata_heap_type &TypeNameMetadataHeap()
        {
            return const_cast<assembly_name_metadata_type *>(GetAssemblyName())->TypeNameMetadataHeap();
        }
        
        type_name_metadata_heap_type const &TypeNameMetadataHeap() const
        {
            return GetAssemblyName()->TypeNameMetadataHeap();
        }

        com_meta_data_assembly_import_type &GetCOMMetaDataAssemblyImport()
        {
            if (m_pComMetaAsmImp.p == NULL)
            {
                this_type *mutableThis = const_cast<this_type *>(this);
                
                com_meta_data_import_type &comMetaImp = mutableThis->GetCOMMetaDataImport();
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
                this_type *mutableThis = const_cast<this_type *>(this);

                metadata_dispenser_type *pMetaDisp = NULL;
                pMetaDisp = mutableThis->FindType<metadata_dispenser_type>();

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

        //type_metadata_type const *GetTypeFromTokenCore(mdToken mdt) const
        //{
        //    typedef typename type_decided_by<type_metadata_type>::type TypeMetadataHeap;
        //    TypeMetadataHeap const &heap = Of<type_metadata_type>();
        //    return heap.Get(mdt);
        //}

        mutable mdAssembly m_mda;

        boost::filesystem::path m_asmPath;
        DWORD m_openFlags;

        mutable metadata_dispenser_type *m_pMetaDisp;
        mutable assembly_name_metadata_type *m_pAsmNameMeta;
        mutable ATL::CComPtr<com_meta_data_import_type> m_pComMetaImp;
        mutable ATL::CComPtr<com_meta_data_assembly_import_type> m_pComMetaAsmImp;
        //mutable boost::unordered_map<std::wstring, mdToken> m_typeMetas;
        mutable boost::unordered_map<std::wstring, SIZE_T> m_typeStrNameToIndex;
        mutable boost::unordered_map<mdToken, SIZE_T>  m_typeTokenToIndex;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP