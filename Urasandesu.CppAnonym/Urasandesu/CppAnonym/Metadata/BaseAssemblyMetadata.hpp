#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#define URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEINFOLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameInfoLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEYFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKeyFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABELFWD_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATADISPENSERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataDispenserLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATAFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadataFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYMETADATAAPIHOLDERLABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyMetadataApiHolderLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_ASSEMBLYNAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/AssemblyNameMetadataLabelFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_TYPENAMEMETADATALABELFWD_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/TypeNameMetadataLabelFwd.hpp>
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
        public IHeapContent<mdAssembly>, 
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type
            >
        >
    {
    public:
        typedef BaseAssemblyMetadata<AssemblyMetadataApiHolder> this_type;
        
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::AssemblyNameMetadataLabel>::type assembly_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeNameMetadataLabel>::type type_name_metadata_type;
        typedef typename AssemblyMetadataApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabel>::type type_metadata_type;
        typedef IMetaDataImport2 metadata_import_api_type;

        typedef HeapProvider<mdToken, boost::mpl::vector<type_metadata_type> > heap_provider_type;
        typedef typename heap_provider_type::type_decided_by<type_metadata_type>::type type_metadata_heap_type;

//#define CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(t, member) \
//    template<class T, class Tag = boost::mpl::void_> \
//    struct Has_##t_##member \
//    { \
//        typedef boost::mpl::false_ type; \
//        static const bool value = false; \
//    }; \
//    \
//    template<class T> \
//    struct Has_##t_##member<T, typename boost::mpl::apply<boost::mpl::always<boost::mpl::void_>, typename T::member>::type> \
//    { \
//        typedef boost::mpl::true_ type; \
//        static const bool value = true; \
//    };
//
//#define CPP_ANONYM_HAS_MEMBER_TYPE(t, member) \
//    Has_##t_##member<t>

//#define CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(t, member) \
//    template<class T> \
//    struct Get_##t_##member \
//    { \
//        typedef typename T::member type; \
//    };
//
//#define CPP_ANONYM_GET_MEMBER_TYPE(t, member) \
//    Get_##t_##member<t>

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(assembly_name_metadata_type, type_name_metadata_heap_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(assembly_name_metadata_type, type_name_metadata_heap_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(assembly_name_metadata_type, type_name_metadata_heap_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(assembly_name_metadata_type, type_name_metadata_heap_type), 
            boost::mpl::void_
        >::type type_name_metadata_heap_type;
        //typedef typename assembly_name_metadata_type::type_name_metadata_heap_type type_name_metadata_heap_type;

        BaseAssemblyMetadata() : 
            m_pMetaDisp(NULL), 
            m_token(mdAssemblyNil), 
            m_pAsmNameMeta(NULL)
        { }

        __declspec(deprecated("This method is temporarily deprecated."))
        void Init(metadata_dispenser_type &metaDisp, metadata_import_api_type &metaImpApi) const
        {
            _ASSERTE(m_pMetaDisp == NULL);
            _ASSERTE(m_pMetaImpApi.p == NULL);
            
            m_pMetaDisp = &metaDisp;
            m_pMetaImpApi = &metaImpApi;
        }

        void Init(metadata_dispenser_type &metaDisp) const
        {
            // This method implementation is temporary.
            m_pMetaDisp = &metaDisp;
        }

        template<class T>
        T const *FindType() const { return static_cast<metadata_dispenser_type const *>(m_pMetaDisp)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMetaDisp->FindType<T>(); }
      
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
            _ASSERTE(m_pMetaImpApi.p != NULL);

            if (m_token == mdAssemblyNil)
            {
                HRESULT hr = E_FAIL;

                if (m_pMetaAsmImpApi.p == NULL)
                {
                    hr = m_pMetaImpApi->QueryInterface(IID_IMetaDataAssemblyImport, 
                                                       reinterpret_cast<void **>(&m_pMetaAsmImpApi));
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }

                hr = m_pMetaAsmImpApi->GetAssemblyFromScope(&m_token);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }

            return m_token;
        }

        type_metadata_type const *GetType(std::wstring const &name) const
        {
            // This method implementation is temporary.
            this_type *mutableThis = const_cast<this_type *>(this);

            type_metadata_type *pTypeMeta = NULL;
            pTypeMeta = mutableThis->TypeMetadataHeap().New(0x02000001);
            pTypeMeta->Init(*mutableThis);
            return pTypeMeta;
            //_ASSERTE(m_pMetaImpApi.p != NULL);

            //if (m_typeMetas.find(name) == m_typeMetas.end())
            //{
            //    m_typeMetas[name] = mdTokenNil;
            //}

            //mdToken mdt = m_typeMetas[name];
            //if (mdt == mdTokenNil)
            //{
            //    mdTypeDef mdtd = mdTypeDefNil;
            //    HRESULT hr = m_pMetaImpApi->FindTypeDefByName(name.c_str(), NULL, &mdtd);
            //    if (FAILED(hr))
            //        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            //    this_type *mutableThis = const_cast<this_type *>(this);
            //    typedef typename type_decided_by<type_metadata_type>::type TypeMetadataHeap;
            //    TypeMetadataHeap &heap = mutableThis->Of<type_metadata_type>();
            //    type_metadata_type *pTypeMeta = heap.New(mdtd);
            //    pTypeMeta->Init(*mutableThis, *m_pMetaImpApi);

            //    m_typeMetas[name] = mdtd;

            //    return pTypeMeta;
            //}
            //else
            //{
            //    return GetTypeFromTokenCore(mdt);
            //}
        }

        assembly_name_metadata_type const *GetAssemblyName() const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pMetaDisp != NULL);
            
            if (m_pAsmNameMeta == NULL)
            {
                m_pAsmNameMeta = m_pMetaDisp->AssemblyNameMetadataHeap().New();
                m_pAsmNameMeta->SetResolutionScope(*m_pMetaDisp);
                m_pAsmNameMeta->SetToken(GetKey());
            }
            return m_pAsmNameMeta;
            //typedef typename type_decided_by<assembly_name_metadata_type>::type AssemblyNameMetadataHeap;
            //AssemblyNameMetadataHeap const &heap = Of<assembly_name_metadata_type>();
            //if (heap.Exists(GetToken()))
            //{
            //    return heap.Get(GetToken());
            //}
            //else
            //{
            //    AssemblyNameMetadataHeap *pHeap = const_cast<AssemblyNameMetadataHeap *>(&heap);
            //    assembly_name_metadata_type const *pAsmNameMeta = pHeap->New(GetToken());
            //    this_type *mutableThis = const_cast<this_type *>(this);
            //    pAsmNameMeta->Init(*mutableThis, *m_pMetaAsmImpApi);
            //    return pAsmNameMeta;
            //}
        }

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadata;

        type_metadata_heap_type &TypeMetadataHeap()
        {
            return heap_provider_type::Of<type_metadata_type>();
        }
        
        type_metadata_heap_type const &TypeMetadataHeap() const
        {
            return heap_provider_type::Of<type_metadata_type>();
        }

        type_name_metadata_heap_type &TypeNameMetadataHeap()
        {
            return const_cast<assembly_name_metadata_type *>(GetAssemblyName())->TypeNameMetadataHeap();
        }
        
        type_name_metadata_heap_type const &TypeNameMetadataHeap() const
        {
            return GetAssemblyName()->TypeNameMetadataHeap();
        }

        type_metadata_type const *GetTypeFromTokenCore(mdToken mdt) const
        {
            typedef typename type_decided_by<type_metadata_type>::type TypeMetadataHeap;
            TypeMetadataHeap const &heap = Of<type_metadata_type>();
            return heap.Get(mdt);
        }

        mutable metadata_dispenser_type *m_pMetaDisp;
        mutable assembly_name_metadata_type *m_pAsmNameMeta;
        mutable ATL::CComPtr<metadata_import_api_type> m_pMetaImpApi;
        mutable ATL::CComPtr<IMetaDataAssemblyImport> m_pMetaAsmImpApi;
        mutable mdAssembly m_token;
        mutable boost::unordered_map<std::wstring, mdToken> m_typeMetas;
    };

    typedef BaseAssemblyMetadata<> AssemblyMetadata;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP