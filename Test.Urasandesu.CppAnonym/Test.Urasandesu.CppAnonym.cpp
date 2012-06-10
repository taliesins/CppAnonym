// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_HPP
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_HPP
#include <Urasandesu/CppAnonym/Traits/HashComputable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_INTERFACES_METADATAINFOLABEL_HPP
#include <Urasandesu/CppAnonym/Metadata/Interfaces/MetadataInfoLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPOINTER_H
#include <Urasandesu/CppAnonym/Utilities/AnyPointer.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

// Forward Declarations
namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct MetadataDispenserApiHolderLabelProto0E2B4910;

    struct AssemblyMetadataApiHolderLabelProtoD4355BC5;

    struct AssemblyNameMetadataApiHolderLabelProto5DA26C79;

    struct TypeMetadataApiHolderLabelProtoA1348031;

    struct TypeNameMetadataApiHolderLabelProto28252D3B;

    struct MethodMetadataApiHolderLabelProto42ABC8D4;

    struct MethodNameMetadataApiHolderLabelProto905E2503;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultMetadataDispenserApiHolderProto0E2B4910;

    struct DefaultAssemblyMetadataApiHolderProtoD4355BC5;

    struct DefaultAssemblyNameMetadataApiHolderProto5DA26C79;

    struct DefaultTypeMetadataApiHolderProtoA1348031;

    struct DefaultTypeNameMetadataApiHolderProto28252D3B;

    struct DefaultMethodMetadataApiHolderProto42ABC8D4;

    struct DefaultMethodNameMetadataApiHolderProto905E2503;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct MetadataDispenserLabelProto0E2B4910;

    struct AssemblyMetadataLabelProtoD4355BC5;

    struct AssemblyNameMetadataLabelProto5DA26C79;

    struct TypeMetadataLabelProtoA1348031;

    struct TypeNameMetadataLabelProto28252D3B;

    struct MethodMetadataLabelProto42ABC8D4;

    struct MethodNameMetadataLabelProto905E2503;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class MetadataDispenserApiHolder = ApiHolders::DefaultMetadataDispenserApiHolderProto0E2B4910
    >
    class BaseMetadataDispenserProto0E2B4910;

    typedef BaseMetadataDispenserProto0E2B4910<> MetadataDispenserProto0E2B4910;





    template<
        class AssemblyMetadataApiHolder = ApiHolders::DefaultAssemblyMetadataApiHolderProtoD4355BC5
    >
    class BaseAssemblyMetadataProtoD4355BC5;

    typedef BaseAssemblyMetadataProtoD4355BC5<> AssemblyMetadataProtoD4355BC5;




    
    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolderProto5DA26C79
    >
    class BaseAssemblyNameMetadataProto5DA26C79;

    typedef BaseAssemblyNameMetadataProto5DA26C79<> AssemblyNameMetadataProto5DA26C79;





    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolderProto5DA26C79
    >    
    struct BaseAssemblyNameMetadataEqualTo;

    typedef BaseAssemblyNameMetadataEqualTo<> AssemblyNameMetadataEqualTo;

    template<
        class AssemblyNameMetadataApiHolder = ApiHolders::DefaultAssemblyNameMetadataApiHolderProto5DA26C79
    >    
    struct BaseAssemblyNameMetadataHash;

    typedef BaseAssemblyNameMetadataHash<> AssemblyNameMetadataHash;





    template<
        class TypeMetadataApiHolder = ApiHolders::DefaultTypeMetadataApiHolderProtoA1348031
    >    
    class BaseTypeMetadataProtoA1348031;

    typedef BaseTypeMetadataProtoA1348031<> TypeMetadataProtoA1348031;



    
    
    template<
        class TypeNameMetadataApiHolder = ApiHolders::DefaultTypeNameMetadataApiHolderProto28252D3B
    >
    class BaseTypeNameMetadataProto28252D3B;

    typedef BaseTypeNameMetadataProto28252D3B<> TypeNameMetadataProto28252D3B;




    
    template<
        class TypeNameMetadataApiHolder = ApiHolders::DefaultTypeNameMetadataApiHolderProto28252D3B
    >    
    struct BaseTypeNameMetadataEqualTo;

    typedef BaseTypeNameMetadataEqualTo<> TypeNameMetadataEqualTo;

    template<
        class TypeNameMetadataApiHolder = ApiHolders::DefaultTypeNameMetadataApiHolderProto28252D3B
    >    
    struct BaseTypeNameMetadataHash;

    typedef BaseTypeNameMetadataHash<> TypeNameMetadataHash;





    template<
        class MethodMetadataApiHolder = ApiHolders::DefaultMethodMetadataApiHolderProto42ABC8D4
    >
    class BaseMethodMetadataProto42ABC8D4;

    typedef BaseMethodMetadataProto42ABC8D4<> MethodMetadataProto42ABC8D4;


    
    
    
    template<
        class MethodNameMetadataApiHolder = ApiHolders::DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    class BaseMethodNameMetadataProto905E2503;

    typedef BaseMethodNameMetadataProto905E2503<> MethodNameMetadataProto905E2503;



    
    
    template<
        class MethodNameMetadataApiHolder = ApiHolders::DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    struct BaseMethodNameMetadataEqualTo;

    typedef BaseMethodNameMetadataEqualTo<> MethodNameMetadataEqualTo;

    template<
        class MethodNameMetadataApiHolder = ApiHolders::DefaultMethodNameMetadataApiHolderProto905E2503
    >    
    struct BaseMethodNameMetadataHash;

    typedef BaseMethodNameMetadataHash<> MethodNameMetadataHash;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct MetadataDispenserApiHolderLabelProto0E2B4910 { };

    struct AssemblyMetadataApiHolderLabelProtoD4355BC5 { };

    struct AssemblyNameMetadataApiHolderLabelProto5DA26C79 { };

    struct TypeMetadataApiHolderLabelProtoA1348031 { };

    struct TypeNameMetadataApiHolderLabelProto28252D3B { };

    struct MethodMetadataApiHolderLabelProto42ABC8D4 { };

    struct MethodNameMetadataApiHolderLabelProto905E2503 { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultMetadataDispenserApiHolderProto0E2B4910 { };

    struct DefaultAssemblyMetadataApiHolderProtoD4355BC5 { };

    struct DefaultAssemblyNameMetadataApiHolderProto5DA26C79 { };

    struct DefaultTypeMetadataApiHolderProtoA1348031 { };

    struct DefaultTypeNameMetadataApiHolderProto28252D3B { };

    struct DefaultMethodMetadataApiHolderProto42ABC8D4 { };

    struct DefaultMethodNameMetadataApiHolderProto905E2503 { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct MetadataDispenserLabelProto0E2B4910 { };

    struct AssemblyMetadataLabelProtoD4355BC5 { };

    struct AssemblyNameMetadataLabelProto5DA26C79 { };

    struct TypeMetadataLabelProtoA1348031 { };

    struct TypeNameMetadataLabelProto28252D3B { };

    struct MethodMetadataLabelProto42ABC8D4 { };

    struct MethodNameMetadataLabelProto905E2503 { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenserProto0E2B4910ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataDispenserApiHolderLabelProto0E2B4910, ApiLabel>
    {
    };

    template<
        class MetadataDispenserApiHolder
    >
    class BaseMetadataDispenserProto0E2B4910 : 
        public HeapProvider<
            mdAssembly, 
            boost::mpl::vector<
                typename MetadataDispenserProto0E2B4910ApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabelProtoD4355BC5>::type
            >
        >,
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename MetadataDispenserProto0E2B4910ApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataLabelProto5DA26C79>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseMetadataDispenserProto0E2B4910<MetadataDispenserApiHolder> this_type;

        typedef typename MetadataDispenserProto0E2B4910ApiAt<MetadataDispenserApiHolder, Interfaces::MetadataInfoLabel>::type metadata_info_type;
        typedef typename MetadataDispenserProto0E2B4910ApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyNameMetadataLabelProto5DA26C79>::type assembly_name_metadata_type;
        typedef typename MetadataDispenserProto0E2B4910ApiAt<MetadataDispenserApiHolder, Interfaces::AssemblyMetadataLabelProtoD4355BC5>::type assembly_metadata_type;

        typedef ObjectTag<assembly_name_metadata_type, QuickHeap> assembly_name_metadata_obj_tag_type;
        typedef SimpleHeapProvider<boost::mpl::vector<assembly_name_metadata_obj_tag_type> > simple_heap_provider_type;
        typedef typename simple_heap_provider_type::type_decided_by<assembly_name_metadata_obj_tag_type>::type assembly_name_metadata_heap_type;

        typedef HeapProvider<mdAssembly, boost::mpl::vector<assembly_metadata_type> > heap_provider_type;
        typedef typename heap_provider_type::type_decided_by<assembly_metadata_type>::type assembly_metadata_heap_type;

        BaseMetadataDispenserProto0E2B4910() : 
            m_pMetaInfo(NULL)
        { }

        void Init(metadata_info_type &metaInfo) const
        {
            // This method implementation is temporary.
            m_pMetaInfo = &metaInfo;
        }

        template<class T>
        T const *FindType() const { return static_cast<metadata_info_type const *>(m_pMetaInfo)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMetaDispAsScope->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        assembly_name_metadata_type *NewAssemblyName(std::wstring const &name) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            assembly_name_metadata_type *pAsmNameMeta = NULL;
            pAsmNameMeta = mutableThis->AssemblyNameMetadataHeap().New();
            pAsmNameMeta->SetName(name);
            pAsmNameMeta->SetResolutionScope(*mutableThis);
            return pAsmNameMeta;
        }

        assembly_metadata_type const *LoadAssemblyFromFile(boost::filesystem::path const &asmPath) const
        {
            // This method implementation is temporary.
            this_type *mutableThis = const_cast<this_type *>(this);

            assembly_metadata_type *pAsmMeta = NULL;
            pAsmMeta = mutableThis->AssemblyMetadataHeap().New(0x20000001);
            pAsmMeta->Init(*mutableThis);
            return pAsmMeta;
        }
    
    private:
        template<
            class AssemblyMetadataApiHolder
        >
        friend class BaseAssemblyMetadataProtoD4355BC5;
        
        assembly_name_metadata_heap_type &AssemblyNameMetadataHeap()
        {
            return simple_heap_provider_type::Of<assembly_name_metadata_obj_tag_type>();
        }
        
        assembly_name_metadata_heap_type const &AssemblyNameMetadataHeap() const
        {
            return simple_heap_provider_type::Of<assembly_name_metadata_obj_tag_type>();
        }

        assembly_metadata_heap_type &AssemblyMetadataHeap()
        {
            return heap_provider_type::Of<assembly_metadata_type>();
        }
        
        assembly_metadata_heap_type const &AssemblyMetadataHeap() const
        {
            return heap_provider_type::Of<assembly_metadata_type>();
        }

        mutable metadata_info_type *m_pMetaInfo;
    };
    
    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataProtoD4355BC5ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataApiHolderLabelProtoD4355BC5, ApiLabel>
    {
    };

    template<
        class AssemblyMetadataApiHolder
    >
    class BaseAssemblyMetadataProtoD4355BC5 : 
        public IHeapContent<mdAssembly>, 
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                typename AssemblyMetadataProtoD4355BC5ApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabelProtoA1348031>::type
            >
        >
    {
    public:
        typedef BaseAssemblyMetadataProtoD4355BC5<AssemblyMetadataApiHolder> this_type;

        typedef typename AssemblyMetadataProtoD4355BC5ApiAt<AssemblyMetadataApiHolder, Interfaces::MetadataDispenserLabelProto0E2B4910>::type metadata_dispenser_type;;
        typedef typename AssemblyMetadataProtoD4355BC5ApiAt<AssemblyMetadataApiHolder, Interfaces::AssemblyNameMetadataLabelProto5DA26C79>::type assembly_name_metadata_type;
        typedef typename AssemblyMetadataProtoD4355BC5ApiAt<AssemblyMetadataApiHolder, Interfaces::TypeNameMetadataLabelProto28252D3B>::type type_name_metadata_type;
        typedef typename AssemblyMetadataProtoD4355BC5ApiAt<AssemblyMetadataApiHolder, Interfaces::TypeMetadataLabelProtoA1348031>::type type_metadata_type;

        typedef HeapProvider<mdToken, boost::mpl::vector<type_metadata_type> > heap_provider_type;
        typedef typename heap_provider_type::type_decided_by<type_metadata_type>::type type_metadata_heap_type;

        typedef typename assembly_name_metadata_type::type_name_metadata_heap_type type_name_metadata_heap_type;

        BaseAssemblyMetadataProtoD4355BC5() : 
            m_pMetaDisp(NULL), 
            m_pAsmNameMeta(NULL)
        { }

        void Init(metadata_dispenser_type &metaDisp) const
        {
            // This method implementation is temporary.
            m_pMetaDisp = &metaDisp;
        }

        template<class T>
        T const *FindType() const { return static_cast<metadata_info_type const *>(m_pMetaInfo)->FindType<T>(); }

        template<class T>
        T *FindType() { return m_pMetaDispAsScope->FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        type_name_metadata_type *NewTypeName(std::wstring const &name, TypeKinds const &kind) const
        {
            return GetAssemblyName()->NewTypeName(name, kind);
        }

        type_metadata_type const *GetType(std::wstring const &name) const
        {
            // This method implementation is temporary.
            this_type *mutableThis = const_cast<this_type *>(this);

            type_metadata_type *pTypeMeta = NULL;
            pTypeMeta = mutableThis->TypeMetadataHeap().New(0x02000001);
            pTypeMeta->Init(*mutableThis);
            return pTypeMeta;
        }

        assembly_name_metadata_type const *GetAssemblyName() const
        {
            _ASSERTE(m_pMetaDisp != NULL);
            
            if (m_pAsmNameMeta == NULL)
            {
                m_pAsmNameMeta = m_pMetaDisp->AssemblyNameMetadataHeap().New();
                m_pAsmNameMeta->SetResolutionScope(*m_pMetaDisp);
                m_pAsmNameMeta->SetToken(GetKey());
            }
            return m_pAsmNameMeta;
        }

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadataProtoA1348031;

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

        mutable metadata_dispenser_type *m_pMetaDisp;
        mutable assembly_name_metadata_type *m_pAsmNameMeta;
    };
    
    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyNameMetadataProto5DA26C79ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyNameMetadataApiHolderLabelProto5DA26C79, ApiLabel>
    {
    };

    template<
        class AssemblyNameMetadataApiHolder
    >
    class BaseAssemblyNameMetadataProto5DA26C79 : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename AssemblyNameMetadataProto5DA26C79ApiAt<AssemblyNameMetadataApiHolder, Interfaces::TypeNameMetadataLabelProto28252D3B>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseAssemblyNameMetadataProto5DA26C79<AssemblyNameMetadataApiHolder> this_type;

        typedef typename AssemblyNameMetadataProto5DA26C79ApiAt<AssemblyNameMetadataApiHolder, Interfaces::MetadataDispenserLabelProto0E2B4910>::type metadata_dispenser_type;
        typedef typename AssemblyNameMetadataProto5DA26C79ApiAt<AssemblyNameMetadataApiHolder, Interfaces::AssemblyMetadataLabelProtoD4355BC5>::type assembly_metadata_type;
        typedef typename AssemblyNameMetadataProto5DA26C79ApiAt<AssemblyNameMetadataApiHolder, Interfaces::TypeNameMetadataLabelProto28252D3B>::type type_name_metadata_type;
        typedef typename AssemblyNameMetadataProto5DA26C79ApiAt<AssemblyNameMetadataApiHolder, Fusion::Interfaces::FusionInfoLabel>::type fusion_info_type;
        

        typedef ObjectTag<type_name_metadata_type, QuickHeap> type_name_metadata_obj_tag_type;
        typedef typename type_decided_by<type_name_metadata_obj_tag_type>::type type_name_metadata_heap_type;

        BaseAssemblyNameMetadataProto5DA26C79() : 
            m_pDispAsScope(NULL), 
            m_pAsmResolved(NULL)
        { }

        void Init(/*metadata_dispenser_type &metaDisp, metadata_import_api_type &metaImpApi*/) const
        {
            //_ASSERTE(m_pMetaDisp == NULL);
            //_ASSERTE(m_pMetaImpApi.p == NULL);
            //
            //m_pMetaDisp = &metaDisp;
            //m_pMetaImpApi = &metaImpApi;
        }

        template<class T>
        T const *FindType() const { return GetResolutionScope().FindType<T>(); }

        template<class T>
        T *FindType() { return const_cast<metadata_dispenser_type &>(GetResolutionScope()).FindType<T>(); }
      
        template<>
        this_type const *FindType<this_type>() const { return this; }
      
        template<>
        this_type *FindType<this_type>() { return this; }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                         L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86";
            }
            return m_name;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        metadata_dispenser_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pDispAsScope != NULL);
            return *m_pDispAsScope;
        }

        void SetResolutionScope(metadata_dispenser_type &metaDispAsScope)
        {
            m_pDispAsScope = &metaDispAsScope;
        }

        type_name_metadata_type *NewTypeName(std::wstring const &name, TypeKinds const &kind) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            type_name_metadata_type *pTypeNameMeta = NULL;
            pTypeNameMeta = mutableThis->TypeNameMetadataHeap().New();
            pTypeNameMeta->SetName(name);
            pTypeNameMeta->SetKind(kind);
            pTypeNameMeta->SetResolutionScope(*mutableThis);
            return pTypeNameMeta;
        }
        
        assembly_metadata_type const *Resolve() const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Fusion;

            if (m_pAsmResolved == NULL)
            {
                fusion_info_type const *pFuInfo = FindType<fusion_info_type>();
                shared_ptr<AssemblyInfo> pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, GetName());

                m_pAsmResolved = GetResolutionScope().LoadAssemblyFromFile(pAsmInfo->GetAssemblyPath());
            }

            return m_pAsmResolved;
        }

    private:
        template<
            class AssemblyMetadataApiHolder
        >
        friend class BaseAssemblyMetadataProtoD4355BC5;

        type_name_metadata_heap_type &TypeNameMetadataHeap()
        {
            return Of<type_name_metadata_obj_tag_type>();
        }
        
        type_name_metadata_heap_type const &TypeNameMetadataHeap() const
        {
            return Of<type_name_metadata_obj_tag_type>();
        }

        void SetToken(mdAssembly mda)
        {
            m_mda = mda;
        }

        mutable std::wstring m_name;
        metadata_dispenser_type *m_pDispAsScope;
        mutable assembly_metadata_type const *m_pAsmResolved;
        mdAssembly m_mda;
    };

    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataProtoA1348031ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadataApiHolderLabelProtoA1348031, ApiLabel>
    {
    };

    template<
        class TypeMetadataApiHolder
    >    
    class BaseTypeMetadataProtoA1348031 : 
        public IHeapContent<mdToken>, 
        public HeapProvider<
            mdToken, 
            boost::mpl::vector<
                typename TypeMetadataProtoA1348031ApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabelProto42ABC8D4>::type
            >
        >
    {
    public:
        typedef BaseTypeMetadataProtoA1348031<TypeMetadataApiHolder> this_type;

        typedef typename TypeMetadataProtoA1348031ApiAt<TypeMetadataApiHolder, Interfaces::AssemblyMetadataLabelProtoD4355BC5>::type assembly_metadata_type;
        typedef typename TypeMetadataProtoA1348031ApiAt<TypeMetadataApiHolder, Interfaces::TypeNameMetadataLabelProto28252D3B>::type type_name_metadata_type;
        typedef typename TypeMetadataProtoA1348031ApiAt<TypeMetadataApiHolder, Interfaces::MethodNameMetadataLabelProto905E2503>::type method_name_metadata_type;
        typedef typename TypeMetadataProtoA1348031ApiAt<TypeMetadataApiHolder, Interfaces::MethodMetadataLabelProto42ABC8D4>::type method_metadata_type;

        typedef HeapProvider<mdToken, boost::mpl::vector<method_metadata_type> > heap_provider_type;
        typedef typename heap_provider_type::type_decided_by<method_metadata_type>::type method_metadata_heap_type;

        typedef typename type_name_metadata_type::method_name_metadata_heap_type method_name_metadata_heap_type;

        BaseTypeMetadataProtoA1348031() : 
            m_pAsmMeta(NULL), 
            m_pTypeNameMeta(NULL)
        { }

        void Init(assembly_metadata_type &asmMeta) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pAsmMeta == NULL);

            m_pAsmMeta = &asmMeta;
        }

        method_metadata_type const *GetMethod(std::wstring const &name, 
                                              CallingConventions const &callingConvention, 
                                              this_type const &retType, 
                                              std::vector<this_type const *> const &paramTypes) const
        {
            // This method implementation is temporary.
            this_type *mutableThis = const_cast<this_type *>(this);

            method_metadata_type *pMethodMeta = NULL;
            pMethodMeta = mutableThis->MethodMetadataHeap().New(0x06000001);
            pMethodMeta->Init(*mutableThis);
            return pMethodMeta;
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 type_name_metadata_type const &retTypeName, 
                                                 std::vector<type_name_metadata_type const *> const &paramTypeNames) const
        {
            return GetTypeName()->NewMethodName(name, callingConvention, retTypeName, paramTypeNames);
        }

        type_name_metadata_type const *GetTypeName() const
        {
            _ASSERTE(m_pAsmMeta != NULL);

            if (m_pTypeNameMeta == NULL)
            {
                m_pTypeNameMeta = m_pAsmMeta->TypeNameMetadataHeap().New();
                m_pTypeNameMeta->SetResolutionScope(*m_pAsmMeta);
                m_pTypeNameMeta->SetToken(GetKey());
            }
            return m_pTypeNameMeta;
        }

    private:
        template<
            class MethodMetadataApiHolder
        >
        friend class BaseMethodMetadataProto42ABC8D4;

        method_metadata_heap_type &MethodMetadataHeap()
        {
            return heap_provider_type::Of<method_metadata_type>();
        }
        
        method_metadata_heap_type const &MethodMetadataHeap() const
        {
            return heap_provider_type::Of<method_metadata_type>();
        }

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return const_cast<type_name_metadata_type *>(GetTypeName())->MethodNameMetadataHeap();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return GetTypeName()->MethodNameMetadataHeap();
        }

        mutable assembly_metadata_type *m_pAsmMeta;
        mutable type_name_metadata_type *m_pTypeNameMeta;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeNameMetadataProto28252D3BApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeNameMetadataApiHolderLabelProto28252D3B, ApiLabel>
    {
    };

    template<
        class TypeNameMetadataApiHolder
    >
    class BaseTypeNameMetadataProto28252D3B : 
        public SimpleHeapProvider<
            boost::mpl::vector<
                ObjectTag<typename TypeNameMetadataProto28252D3BApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabelProto905E2503>::type, QuickHeap>
            >
        >
    {
    public:
        typedef BaseTypeNameMetadataProto28252D3B<TypeNameMetadataApiHolder> this_type;

        typedef typename TypeNameMetadataProto28252D3BApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyMetadataLabelProtoD4355BC5>::type assembly_metadata_type;
        typedef typename TypeNameMetadataProto28252D3BApiAt<TypeNameMetadataApiHolder, Interfaces::AssemblyNameMetadataLabelProto5DA26C79>::type assembly_name_metadata_type;
        typedef typename TypeNameMetadataProto28252D3BApiAt<TypeNameMetadataApiHolder, Interfaces::TypeMetadataLabelProtoA1348031>::type type_metadata_type;
        typedef typename TypeNameMetadataProto28252D3BApiAt<TypeNameMetadataApiHolder, Interfaces::MethodNameMetadataLabelProto905E2503>::type method_name_metadata_type;

        typedef ObjectTag<method_name_metadata_type, QuickHeap> method_name_metadata_obj_tag_type;
        typedef typename type_decided_by<method_name_metadata_obj_tag_type>::type method_name_metadata_heap_type;

        BaseTypeNameMetadataProto28252D3B() : 
            m_pAsmNameAsScope(NULL), 
            m_pAsmAsScope(NULL), 
            m_pTypeResolved(NULL), 
            m_mdt(mdTokenNil)
        { }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"System.Console";
            }
            return m_name;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        TypeKinds const &GetKind() const
        {
            return m_kind;
        }

        void SetKind(TypeKinds const &kind)
        {
            m_kind = kind;
        }

        assembly_name_metadata_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pAsmNameAsScope != NULL);
            return *m_pAsmNameAsScope;
        }

        void SetResolutionScope(assembly_name_metadata_type &asmNameAsScope)
        {
            m_pAsmNameAsScope = &asmNameAsScope;
        }

        void SetResolutionScope(assembly_metadata_type &asmAsScope)
        {
            m_pAsmAsScope = &asmAsScope;
        }

        method_name_metadata_type *NewMethodName(std::wstring const &name, 
                                                 CallingConventions const &callingConvention, 
                                                 this_type const &retTypeName, 
                                                 std::vector<this_type const *> const &paramTypeNames) const
        {
            this_type *mutableThis = const_cast<this_type *>(this);

            method_name_metadata_type *pMethodNameMeta = NULL;
            pMethodNameMeta = mutableThis->MethodNameMetadataHeap().New();
            pMethodNameMeta->SetName(name);
            pMethodNameMeta->SetCallingConvention(callingConvention);
            pMethodNameMeta->SetReturnTypeName(retTypeName);
            pMethodNameMeta->SetParameterTypeNames(paramTypeNames);
            pMethodNameMeta->SetResolutionScope(*mutableThis);
            return pMethodNameMeta;
        }

        type_metadata_type const *Resolve() const
        {
            // This method implementation is temporary.
            if (m_pAsmAsScope == NULL)
                m_pAsmAsScope = GetResolutionScope().Resolve();
            
            if (m_pTypeResolved == NULL)
                m_pTypeResolved = m_pAsmAsScope->GetType(m_name);
            return m_pTypeResolved;
        }

    private:
        template<
            class TypeMetadataApiHolder
        >    
        friend class BaseTypeMetadataProtoA1348031;

        method_name_metadata_heap_type &MethodNameMetadataHeap()
        {
            return Of<method_name_metadata_obj_tag_type>();
        }
        
        method_name_metadata_heap_type const &MethodNameMetadataHeap() const
        {
            return Of<method_name_metadata_obj_tag_type>();
        }

        void SetToken(mdToken mdt)
        {
            m_mdt = mdt;
        }

        mutable std::wstring m_name;
        TypeKinds m_kind;
        assembly_name_metadata_type *m_pAsmNameAsScope;
        mdToken m_mdt;
        mutable assembly_metadata_type const *m_pAsmAsScope;
        mutable type_metadata_type const *m_pTypeResolved;
    };


    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataProto905E2503ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataApiHolderLabelProto42ABC8D4, ApiLabel>
    {
    };

    template<
        class MethodMetadataApiHolder
    >
    class BaseMethodMetadataProto42ABC8D4 : 
        public IHeapContent<mdToken>
    {
    public:
        typedef BaseMethodMetadataProto42ABC8D4<MethodMetadataApiHolder> this_type;

        typedef typename MethodMetadataProto905E2503ApiAt<MethodMetadataApiHolder, Interfaces::TypeMetadataLabelProtoA1348031>::type type_metadata_type;
        typedef typename MethodMetadataProto905E2503ApiAt<MethodMetadataApiHolder, Interfaces::MethodNameMetadataLabelProto905E2503>::type method_name_metadata_type;        

        BaseMethodMetadataProto42ABC8D4() :
            m_pTypeMeta(NULL),
            m_pMethodNameMeta(NULL)
        { }
        
        void Init(type_metadata_type &typeMeta) const
        {
            // This method implementation is temporary.
            _ASSERTE(m_pTypeMeta == NULL);

            m_pTypeMeta = &typeMeta;
        }

        method_name_metadata_type const *GetMethodName() const
        {
            _ASSERTE(m_pTypeMeta != NULL);

            if (m_pMethodNameMeta == NULL)
            {
                m_pMethodNameMeta = m_pTypeMeta->MethodNameMetadataHeap().New();
                m_pMethodNameMeta->SetResolutionScope(*m_pTypeMeta);
                m_pMethodNameMeta->SetToken(GetKey());
            }
            return m_pMethodNameMeta;
        }

    private:
        mutable type_metadata_type *m_pTypeMeta;
        mutable method_name_metadata_type *m_pMethodNameMeta;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodNameMetadataProto905E2503ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodNameMetadataApiHolderLabelProto905E2503, ApiLabel>
    {
    };

    template<
        class MethodNameMetadataApiHolder
    >    
    class BaseMethodNameMetadataProto905E2503 : 
        boost::noncopyable
    {
    public:
        typedef BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> this_type;

        typedef typename MethodNameMetadataProto905E2503ApiAt<MethodNameMetadataApiHolder, Interfaces::TypeMetadataLabelProtoA1348031>::type type_metadata_type;
        typedef typename MethodNameMetadataProto905E2503ApiAt<MethodNameMetadataApiHolder, Interfaces::TypeNameMetadataLabelProto28252D3B>::type type_name_metadata_type;
        typedef typename MethodNameMetadataProto905E2503ApiAt<MethodNameMetadataApiHolder, Interfaces::MethodMetadataLabelProto42ABC8D4>::type method_metadata_type;

        BaseMethodNameMetadataProto905E2503() : 
            m_pRetTypeName(NULL), 
            m_pTypeNameAsScope(NULL), 
            m_pTypeAsScope(NULL), 
            m_pMethodResolved(NULL), 
            m_mdt(mdTokenNil)
        { }

        std::wstring const &GetName() const
        {
            // This method implementation is temporary.
            if (m_name.empty())
            {
                m_name = L"WriteLine";
            }
            return m_name;
        }

        void SetName(std::wstring const &name)
        {
            // Should be immutable...
            m_name = name;
        }

        CallingConventions const &GetCallingConvention() const
        {
            return m_callingConvention;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            m_callingConvention = callingConvention;
        }

        type_name_metadata_type const &GetReturnTypeName() const
        {
            _ASSERTE(m_pRetTypeName != NULL);
            return *m_pRetTypeName;
        }

        void SetReturnTypeName(type_name_metadata_type const &retTypeName)
        {
            m_pRetTypeName = &retTypeName;
        }

        std::vector<type_name_metadata_type const *> const &GetParameterTypeNames() const
        {
            return m_paramTypeNames;
        }

        void SetParameterTypeNames(std::vector<type_name_metadata_type const *> const &paramTypeNames)
        {
            m_paramTypeNames = paramTypeNames;
        }

        type_name_metadata_type const &GetResolutionScope() const
        {
            _ASSERTE(m_pTypeNameAsScope != NULL);
            return *m_pTypeNameAsScope;
        }

        void SetResolutionScope(type_name_metadata_type &typeNameMetaAsScope)
        {
            m_pTypeNameAsScope = &typeNameMetaAsScope;
        }

        void SetResolutionScope(type_metadata_type &typeMetaAsScope)
        {
            m_pTypeAsScope = &typeMetaAsScope;
        }

        method_metadata_type const *Resolve() const
        {
            // This method implementation is temporary.
            if (m_pTypeAsScope == NULL)
                m_pTypeAsScope = GetResolutionScope().Resolve();
            
            if (m_pMethodResolved == NULL)
            {
                type_metadata_type const *pRetType = NULL;
                pRetType = GetReturnTypeName().Resolve();
                std::vector<type_name_metadata_type const *> const &paramTypeNames = GetParameterTypeNames();
                typedef std::vector<type_name_metadata_type const *>::const_iterator ConstTypeNameMetadataIterator;
                std::vector<type_metadata_type const *> paramTypes(paramTypeNames.size());
                for (ConstTypeNameMetadataIterator i = paramTypeNames.cbegin(), i_end = paramTypeNames.cend(); i != i_end; ++i)
                    paramTypes.push_back((*i)->Resolve());
                m_pMethodResolved = m_pTypeAsScope->GetMethod(GetName(), GetCallingConvention(), *pRetType, paramTypes);
            }
            return m_pMethodResolved;
        }

    private:
        template<
            class MethodMetadataApiHolder
        >
        friend class BaseMethodMetadataProto42ABC8D4;

        void SetToken(mdToken mdt)
        {
            m_mdt = mdt;
        }

        mutable std::wstring m_name;
        CallingConventions m_callingConvention;
        type_name_metadata_type const *m_pRetTypeName;
        std::vector<type_name_metadata_type const *> m_paramTypeNames;
        type_name_metadata_type *m_pTypeNameAsScope;
        mdToken m_mdt;
        mutable type_metadata_type const *m_pTypeAsScope;
        mutable method_metadata_type const *m_pMethodResolved;
    };

    
    
    
    
    template<
        class MethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataEqualTo : 
        Traits::EqualityComparable<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> const *>
    {
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x != NULL && y != NULL);
            
            return x->m_name == y->m_name;
        }
    };

    template<
        class MethodNameMetadataApiHolder
    >    
    struct BaseMethodNameMetadataHash : 
        Traits::HashComputable<BaseMethodNameMetadataProto905E2503<MethodNameMetadataApiHolder> const *>
    {
        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v != NULL);
            
            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->m_name));
            return seed;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class T>
    struct Predicatable : 
        std::unary_function<T, bool>
    {
        typedef typename boost::call_traits<T>::param_type param_type;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Mock9254318F {
    
    typedef std::vector<boost::any> AnyVector;

    class MockMetadataInfo
    {
    public:
        template<class T>
        T const *FindType() const 
        {
            using namespace boost;

            struct IsT : 
                Urasandesu::CppAnonym::Traits::Predicatable<any> 
            {
                result_type operator()(param_type v) const
                {
                    return !v.empty() && v.type() == typeid(shared_ptr<T>);
                }
            };

            AnyVector::iterator result;
            result = std::find_if(m_typePtrs.begin(), m_typePtrs.end(), IsT()); 
            _ASSERTE(result != m_typePtrs.end());

            return any_cast<shared_ptr<T> >(*result).get();
        }

        mutable AnyVector m_typePtrs;
    };

    class MockRuntimeHost
    {
    public:
        boost::filesystem::path const &GetCORSystemDirectoryPath() const
        {
            return m_corSystemDirectoryPath;
        }

        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

}   // namespace Mock9254318F {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, CombinationOfResolutionWayTest_All_01)
    {
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Metadata;


        struct TestApiHolder
        {
            typedef mpl::map<
                mpl::pair<Metadata::Interfaces::MetadataDispenserLabelProto0E2B4910, BaseMetadataDispenserProto0E2B4910<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyMetadataLabelProtoD4355BC5, BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyNameMetadataLabelProto5DA26C79, BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeMetadataLabelProtoA1348031, BaseTypeMetadataProtoA1348031<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeNameMetadataLabelProto28252D3B, BaseTypeNameMetadataProto28252D3B<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodMetadataLabelProto42ABC8D4, BaseMethodMetadataProto42ABC8D4<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodNameMetadataLabelProto905E2503, BaseMethodNameMetadataProto905E2503<TestApiHolder> >, 
                
                mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Mock9254318F::MockRuntimeHost>, 
                mpl::pair<Metadata::Interfaces::MetadataInfoLabel, Mock9254318F::MockMetadataInfo>, 
                mpl::pair<Fusion::Interfaces::FusionInfoLabel, BaseFusionInfo<TestApiHolder> > 
            > api_cartridges;
        };

        typedef Mock9254318F::MockRuntimeHost RuntimeHost; 
        typedef Mock9254318F::MockMetadataInfo MetadataInfo;
        typedef BaseFusionInfo<TestApiHolder> FusionInfo;

        typedef BaseMetadataDispenserProto0E2B4910<TestApiHolder> MetadataDispenser;
        typedef BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> AssemblyMetadata;
        typedef BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> AssemblyNameMetadata;
        typedef BaseTypeMetadataProtoA1348031<TestApiHolder> TypeMetadata;
        typedef BaseTypeNameMetadataProto28252D3B<TestApiHolder> TypeNameMetadata;
        typedef BaseMethodMetadataProto42ABC8D4<TestApiHolder> MethodMetadata;
        typedef BaseMethodNameMetadataProto905E2503<TestApiHolder> MethodNameMetadata;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyNameMetadata *pMSCorLibName = NULL;
        {
            std::wstring name(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                              L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
            pMSCorLibName = pMetaDisp->NewAssemblyName(name);
        }

        ASSERT_STREQ(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                     L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86", pMSCorLibName->GetName().c_str());
        
        AssemblyMetadata const *pMSCorLib = NULL;
        pMSCorLib = pMSCorLibName->Resolve();
        ASSERT_EQ(0x20000001, pMSCorLib->GetKey());
        
        TypeNameMetadata *pConsoleName = NULL;
        {
            std::wstring name(L"System.Console");
            TypeKinds kind(TypeKinds::TK_CLASS);
            pConsoleName = pMSCorLibName->NewTypeName(name, kind);
        }

        ASSERT_STREQ(L"System.Console", pConsoleName->GetName().c_str());

        TypeMetadata const *pConsole = NULL;
        pConsole = pConsoleName->Resolve();
        ASSERT_EQ(0x02000001, pConsole->GetKey());

        MethodNameMetadata *pWriteLineName = NULL;
        {
            std::wstring name(L"WriteLine");
            CallingConventions callingConvention(CallingConventions::CC_STANDARD);
            TypeNameMetadata const *pRetTypeName = pMSCorLibName->NewTypeName(L"System.Void", TypeKinds::TK_VOID);
            std::vector<TypeNameMetadata const *> paramTypeNames;
            paramTypeNames.push_back(pMSCorLibName->NewTypeName(L"System.String", TypeKinds::TK_STRING));
            pWriteLineName = pConsoleName->NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);
        }

        //MethodMetadata *pWriteLine = NULL;
        //{
        //    pWriteLine = pWriteLineName->Resolve();
        //}


    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, CombinationOfResolutionWayTest_FromAssembly_01)
    {
        namespace mpl = boost::mpl;
        namespace fs = boost::filesystem;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Metadata;


        struct TestApiHolder
        {
            typedef mpl::map<
                mpl::pair<Metadata::Interfaces::MetadataDispenserLabelProto0E2B4910, BaseMetadataDispenserProto0E2B4910<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyMetadataLabelProtoD4355BC5, BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyNameMetadataLabelProto5DA26C79, BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeMetadataLabelProtoA1348031, BaseTypeMetadataProtoA1348031<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeNameMetadataLabelProto28252D3B, BaseTypeNameMetadataProto28252D3B<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodMetadataLabelProto42ABC8D4, BaseMethodMetadataProto42ABC8D4<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodNameMetadataLabelProto905E2503, BaseMethodNameMetadataProto905E2503<TestApiHolder> >, 
                
                mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Mock9254318F::MockRuntimeHost>, 
                mpl::pair<Metadata::Interfaces::MetadataInfoLabel, Mock9254318F::MockMetadataInfo>, 
                mpl::pair<Fusion::Interfaces::FusionInfoLabel, BaseFusionInfo<TestApiHolder> > 
            > api_cartridges;
        };

        typedef Mock9254318F::MockRuntimeHost RuntimeHost; 
        typedef Mock9254318F::MockMetadataInfo MetadataInfo;
        typedef BaseFusionInfo<TestApiHolder> FusionInfo;

        typedef BaseMetadataDispenserProto0E2B4910<TestApiHolder> MetadataDispenser;
        typedef BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> AssemblyMetadata;
        typedef BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> AssemblyNameMetadata;
        typedef BaseTypeMetadataProtoA1348031<TestApiHolder> TypeMetadata;
        typedef BaseTypeNameMetadataProto28252D3B<TestApiHolder> TypeNameMetadata;
        typedef BaseMethodMetadataProto42ABC8D4<TestApiHolder> MethodMetadata;
        typedef BaseMethodNameMetadataProto905E2503<TestApiHolder> MethodNameMetadata;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }

        AssemblyNameMetadata const *pMSCorLibName = NULL;
        pMSCorLibName = pMSCorLib->GetAssemblyName();

        TypeNameMetadata *pConsoleName = NULL;
        {
            std::wstring name(L"System.Console");
            TypeKinds kind(TypeKinds::TK_CLASS);
            pConsoleName = pMSCorLib->NewTypeName(name, kind);
        }

        ASSERT_STREQ(L"System.Console", pConsoleName->GetName().c_str());

        TypeMetadata const *pConsole = NULL;
        pConsole = pConsoleName->Resolve();
        ASSERT_EQ(0x02000001, pConsole->GetKey());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, CombinationOfResolutionWayTest_FromType_01)
    {
        namespace fs = boost::filesystem;
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Metadata;


        struct TestApiHolder
        {
            typedef mpl::map<
                mpl::pair<Metadata::Interfaces::MetadataDispenserLabelProto0E2B4910, BaseMetadataDispenserProto0E2B4910<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyMetadataLabelProtoD4355BC5, BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyNameMetadataLabelProto5DA26C79, BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeMetadataLabelProtoA1348031, BaseTypeMetadataProtoA1348031<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeNameMetadataLabelProto28252D3B, BaseTypeNameMetadataProto28252D3B<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodMetadataLabelProto42ABC8D4, BaseMethodMetadataProto42ABC8D4<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodNameMetadataLabelProto905E2503, BaseMethodNameMetadataProto905E2503<TestApiHolder> >, 
                
                mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Mock9254318F::MockRuntimeHost>, 
                mpl::pair<Metadata::Interfaces::MetadataInfoLabel, Mock9254318F::MockMetadataInfo>, 
                mpl::pair<Fusion::Interfaces::FusionInfoLabel, BaseFusionInfo<TestApiHolder> > 
            > api_cartridges;
        };

        typedef Mock9254318F::MockRuntimeHost RuntimeHost; 
        typedef Mock9254318F::MockMetadataInfo MetadataInfo;
        typedef BaseFusionInfo<TestApiHolder> FusionInfo;

        typedef BaseMetadataDispenserProto0E2B4910<TestApiHolder> MetadataDispenser;
        typedef BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> AssemblyMetadata;
        typedef BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> AssemblyNameMetadata;
        typedef BaseTypeMetadataProtoA1348031<TestApiHolder> TypeMetadata;
        typedef BaseTypeNameMetadataProto28252D3B<TestApiHolder> TypeNameMetadata;
        typedef BaseMethodMetadataProto42ABC8D4<TestApiHolder> MethodMetadata;
        typedef BaseMethodNameMetadataProto905E2503<TestApiHolder> MethodNameMetadata;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }

        TypeMetadata const *pConsole = NULL;
        {
            std::wstring name(L"System.Console");
            pConsole = pMSCorLib->GetType(name);
        }

        TypeNameMetadata const *pConsoleName = NULL;
        pConsoleName = pConsole->GetTypeName();

        ASSERT_STREQ(L"System.Console", pConsoleName->GetName().c_str());

        MethodNameMetadata *pWriteLineName = NULL;
        {
            std::wstring name(L"WriteLine");
            CallingConventions callingConvention(CallingConventions::CC_STANDARD);
            TypeNameMetadata const *pRetTypeName = pMSCorLib->NewTypeName(L"System.Void", TypeKinds::TK_VOID);
            std::vector<TypeNameMetadata const *> paramTypeNames;
            paramTypeNames.push_back(pMSCorLib->NewTypeName(L"System.String", TypeKinds::TK_STRING));
            pWriteLineName = pConsole->NewMethodName(name, callingConvention, *pRetTypeName, paramTypeNames);
        }

        ASSERT_STREQ(L"WriteLine", pWriteLineName->GetName().c_str());

        MethodMetadata const *pWriteLine = NULL;
        pWriteLine = pWriteLineName->Resolve();
        ASSERT_EQ(0x06000001, pWriteLine->GetKey());
    }



    CPPANONYM_TEST(Urasandesu_CppAnonym_Test, CombinationOfResolutionWayTest_FromMethod_01)
    {
        namespace fs = boost::filesystem;
        namespace mpl = boost::mpl;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Metadata;


        struct TestApiHolder
        {
            typedef mpl::map<
                mpl::pair<Metadata::Interfaces::MetadataDispenserLabelProto0E2B4910, BaseMetadataDispenserProto0E2B4910<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyMetadataLabelProtoD4355BC5, BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::AssemblyNameMetadataLabelProto5DA26C79, BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeMetadataLabelProtoA1348031, BaseTypeMetadataProtoA1348031<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::TypeNameMetadataLabelProto28252D3B, BaseTypeNameMetadataProto28252D3B<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodMetadataLabelProto42ABC8D4, BaseMethodMetadataProto42ABC8D4<TestApiHolder> >, 
                mpl::pair<Metadata::Interfaces::MethodNameMetadataLabelProto905E2503, BaseMethodNameMetadataProto905E2503<TestApiHolder> >, 
                
                mpl::pair<Hosting::Interfaces::RuntimeHostLabel, Mock9254318F::MockRuntimeHost>, 
                mpl::pair<Metadata::Interfaces::MetadataInfoLabel, Mock9254318F::MockMetadataInfo>, 
                mpl::pair<Fusion::Interfaces::FusionInfoLabel, BaseFusionInfo<TestApiHolder> > 
            > api_cartridges;
        };

        typedef Mock9254318F::MockRuntimeHost RuntimeHost; 
        typedef Mock9254318F::MockMetadataInfo MetadataInfo;
        typedef BaseFusionInfo<TestApiHolder> FusionInfo;

        typedef BaseMetadataDispenserProto0E2B4910<TestApiHolder> MetadataDispenser;
        typedef BaseAssemblyMetadataProtoD4355BC5<TestApiHolder> AssemblyMetadata;
        typedef BaseAssemblyNameMetadataProto5DA26C79<TestApiHolder> AssemblyNameMetadata;
        typedef BaseTypeMetadataProtoA1348031<TestApiHolder> TypeMetadata;
        typedef BaseTypeNameMetadataProto28252D3B<TestApiHolder> TypeNameMetadata;
        typedef BaseMethodMetadataProto42ABC8D4<TestApiHolder> MethodMetadata;
        typedef BaseMethodNameMetadataProto905E2503<TestApiHolder> MethodNameMetadata;

        shared_ptr<RuntimeHost> pRuntimeHost(make_shared<RuntimeHost>());
        pRuntimeHost->m_corSystemDirectoryPath = L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\";

        shared_ptr<FusionInfo> pFusionInfo(make_shared<FusionInfo>());
        pFusionInfo->Init(*pRuntimeHost);

        shared_ptr<MetadataInfo> pMetaInfo(make_shared<MetadataInfo>());
        pMetaInfo->m_typePtrs.push_back(pFusionInfo);
        
        shared_ptr<MetadataDispenser> pMetaDisp(make_shared<MetadataDispenser>());
        pMetaDisp->Init(*pMetaInfo);

        AssemblyMetadata const *pMSCorLib = NULL;
        {
            fs::path asmPath(L"C:\\windows\\assembly\\GAC_32\\mscorlib\\2.0.0.0__b77a5c561934e089\\mscorlib.dll");
            pMSCorLib = pMetaDisp->LoadAssemblyFromFile(asmPath);
        }

        TypeMetadata const *pConsole = NULL;
        {
            std::wstring name(L"System.Console");
            pConsole = pMSCorLib->GetType(name);
        }

        MethodMetadata const *pWriteLine = NULL;
        {
            std::wstring name(L"WriteLine");
            CallingConventions callingConvention(CallingConventions::CC_STANDARD);
            TypeMetadata const *pRetType = pMSCorLib->GetType(L"System.Void");
            std::vector<TypeMetadata const *> paramTypes;
            paramTypes.push_back(pMSCorLib->GetType(L"System.String"));
            pWriteLine = pConsole->GetMethod(name, callingConvention, *pRetType, paramTypes);
        }

        MethodNameMetadata const *pWriteLineName = NULL;
        pWriteLineName = pWriteLine->GetMethodName();

        ASSERT_STREQ(L"WriteLine", pWriteLineName->GetName().c_str());
    }
}
