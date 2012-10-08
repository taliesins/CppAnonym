// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

//#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
//#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
//#endif

//#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTO_PTR_HPP
//#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hpp>
//#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainMapper.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainConstructor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_APIHOLDERS_DEFAULTHOSTINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultHostInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASEHOSTINFO_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPI_H
#include <Urasandesu/CppAnonym/Hosting/ApiHolders/DefaultRuntimeHostApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOST_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHost.hpp>
#endif

#if 0
#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFO_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_APIHOLDERS_DEFAULTSTRONGNAMEKEYAPIHOLDER_H
#include <Urasandesu/CppAnonym/StrongNaming/ApiHolders/DefaultStrongNameKeyApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEKEY_HPP
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameKey.hpp>
#endif
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/CppAnonym/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_SIGNATUREUTIL_HPP
#include <Urasandesu/CppAnonym/Metadata/SignatureUtil.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/TypeAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_FIELDATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/FieldAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_METHODATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/MethodAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_PROPERTYATTRIBUTES_HPP
#include <Urasandesu/CppAnonym/Metadata/PropertyAttributes.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIModuleMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTITYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultITypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEITYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseITypeMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTIMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultIMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEIMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseIMethodMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFO_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfo.hpp>
#endif

// foward declarations
namespace Urasandesu { namespace CppAnonym {

    //namespace Detail {
    //    
    //    template<class Sequence, class I, class IEnd>
    //    class PersistableHeapProviderImpl;

    //}   // namespace Detail


    //template<class Sequence>
    //class PersistableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct IFieldMetadataApiHolderLabel { };
    struct IFieldMetadataLabel { };
    struct IFieldMetadataHashLabel { };
    struct IFieldMetadataEqualToLabel { };

    struct IPropertyMetadataApiHolderLabel { };
    struct IPropertyMetadataLabel { };
    struct IPropertyMetadataHashLabel { };
    struct IPropertyMetadataEqualToLabel { };

    struct AssemblyMetadataGenerator7FAEDE99ApiHolderLabel { };
    struct AssemblyMetadataGenerator7FAEDE99Label { };
    
    struct ModuleMetadataGenerator7FAEDE99ApiHolderLabel { };
    struct ModuleMetadataGenerator7FAEDE99Label { };

    struct TypeMetadataGenerator7FAEDE99ApiHolderLabel { };
    struct TypeMetadataGenerator7FAEDE99Label { };
    
    struct FieldMetadataGenerator7FAEDE99ApiHolderLabel { };
    struct FieldMetadataGenerator7FAEDE99Label { };

    struct MethodMetadataGenerator7FAEDE99ApiHolderLabel { };
    struct MethodMetadataGenerator7FAEDE99Label { };
    
    struct PropertyMetadataGenerator7FAEDE99ApiHolderLabel { };
    struct PropertyMetadataGenerator7FAEDE99Label { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultIFieldMetadataApiHolder;

    struct DefaultIPropertyMetadataApiHolder;

    struct DefaultAssemblyMetadataGenerator7FAEDE99ApiHolder;

    struct DefaultModuleMetadataGenerator7FAEDE99ApiHolder;

    struct DefaultTypeMetadataGenerator7FAEDE99ApiHolder;

    struct DefaultFieldMetadataGenerator7FAEDE99ApiHolder;

    struct DefaultMethodMetadataGenerator7FAEDE99ApiHolder;

    struct DefaultPropertyMetadataGenerator7FAEDE99ApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_INTERFACES_STRONGNAMEKEYLABEL_HPP
#include <Urasandesu/CppAnonym/StrongNaming/Interfaces/StrongNameKeyLabel.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class IFieldMetadataApiHolder = ApiHolders::DefaultIFieldMetadataApiHolder
    >    
    class BaseIFieldMetadata;

    typedef BaseIFieldMetadata<> IFieldMetadata;
    
    
    
    
    
    template<
        class IFieldMetadataApiHolder = ApiHolders::DefaultIFieldMetadataApiHolder
    >    
    struct BaseIFieldMetadataHash;

    typedef BaseIFieldMetadataHash<> IFieldMetadataHash;
    
    
    
    
    
    template<
        class IFieldMetadataApiHolder = ApiHolders::DefaultIFieldMetadataApiHolder
    >    
    struct BaseIFieldMetadataEqualTo;

    typedef BaseIFieldMetadataEqualTo<> IFieldMetadataEqualTo;





    template<
        class IPropertyMetadataApiHolder = ApiHolders::DefaultIPropertyMetadataApiHolder
    >    
    class BaseIPropertyMetadata;

    typedef BaseIPropertyMetadata<> IPropertyMetadata;
    
    
    
    
    
    template<
        class IPropertyMetadataApiHolder = ApiHolders::DefaultIPropertyMetadataApiHolder
    >    
    struct BaseIPropertyMetadataHash;

    typedef BaseIPropertyMetadataHash<> IPropertyMetadataHash;
    
    
    
    
    
    template<
        class IPropertyMetadataApiHolder = ApiHolders::DefaultIPropertyMetadataApiHolder
    >    
    struct BaseIPropertyMetadataEqualTo;

    typedef BaseIPropertyMetadataEqualTo<> IPropertyMetadataEqualTo;





    template<
        class AssemblyMetadataGenerator7FAEDE99ApiHolder = ApiHolders::DefaultAssemblyMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseAssemblyMetadataGenerator7FAEDE99;

    typedef BaseAssemblyMetadataGenerator7FAEDE99<> AssemblyMetadataGenerator7FAEDE99;





    template<
        class ModuleMetadataGenerator7FAEDE99ApiHolder = ApiHolders::DefaultModuleMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseModuleMetadataGenerator7FAEDE99;

    typedef BaseModuleMetadataGenerator7FAEDE99<> ModuleMetadataGenerator7FAEDE99;





    template<
        class TypeMetadataGenerator7FAEDE99ApiHolder = ApiHolders::DefaultTypeMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseTypeMetadataGenerator7FAEDE99;

    typedef BaseTypeMetadataGenerator7FAEDE99<> TypeMetadataGenerator7FAEDE99;





    template<
        class FieldMetadataGenerator7FAEDE99ApiHolder = ApiHolders::DefaultFieldMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseFieldMetadataGenerator7FAEDE99;

    typedef BaseFieldMetadataGenerator7FAEDE99<> FieldMetadataGenerator7FAEDE99;





    template<
        class MethodMetadataGenerator7FAEDE99ApiHolder = ApiHolders::DefaultMethodMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseMethodMetadataGenerator7FAEDE99;

    typedef BaseMethodMetadataGenerator7FAEDE99<> MethodMetadataGenerator7FAEDE99;





    template<
        class PropertyMetadataGenerator7FAEDE99ApiHolder = ApiHolders::DefaultPropertyMetadataGenerator7FAEDE99ApiHolder
    >    
    class BasePropertyMetadataGenerator7FAEDE99;

    typedef BasePropertyMetadataGenerator7FAEDE99<> PropertyMetadataGenerator7FAEDE99;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {



#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATADISPENSER_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataDispenser.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEASSEMBLYMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseAssemblyMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMODULEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultModuleMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMODULEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseModuleMetadata.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTTYPEMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultTypeMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASETYPEMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseTypeMetadata.hpp>
#endif

#if 0
#ifndef URASANDESU_CPPANONYM_METADATA_APIHOLDERS_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/CppAnonym/Metadata/ApiHolders/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETHODMETADATA_HPP
#include <Urasandesu/CppAnonym/Metadata/BaseMethodMetadata.hpp>
#endif
#endif

namespace Urasandesu { namespace CppAnonym {

    //namespace Detail {

    //    namespace mpl = boost::mpl;
    //    using namespace boost;

    //    template<class Sequence, class I, class IEnd>
    //    class ATL_NO_VTABLE PersistableHeapProviderImpl : 
    //        SimpleHeapProvider<
    //            mpl::vector<
    //                ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
    //            >
    //        >,
    //        public PersistableHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
    //    {
    //    public:
    //        typedef PersistableHeapProviderImpl<Sequence, I, IEnd> this_type;
    //        typedef typename mpl::deref<I>::type object_type;
    //        typedef shared_ptr<object_type> sp_object_type;
    //        typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
    //        typedef typename provider_of<obj_tag_type>::type provider_type;
    //        typedef std::vector<object_type *> object_ptr_vector_type;

    //        virtual ~PersistableHeapProviderImpl()
    //        {
    //            provider_type &provider = ProviderOf<obj_tag_type>();
    //            typedef object_ptr_vector_type::reverse_iterator ReverseIterator;
    //            for (ReverseIterator ri = Objects().rbegin(), ri_end = Objects().rend(); ri != ri_end; ++ri)
    //                provider.Heap().Delete(*ri);
    //        }

    //        static sp_object_type NewStaticObject()
    //        {
    //            return sp_object_type(provider_type::StaticHeap().New(), deleter(provider_type::StaticHeap()));
    //        }

    //        sp_object_type NewObject()
    //        {
    //            provider_type &provider = ProviderOf<obj_tag_type>();
    //            return sp_object_type(provider.Heap().New(), deleter(provider.Heap()));
    //        }

    //        typename object_ptr_vector_type::size_type Register(sp_object_type const &p)
    //        {
    //            if (deleter *pDel = get_deleter<deleter>(p))
    //            {
    //                pDel->DisableDeletion();
    //                Objects().push_back(p.get());
    //                return Objects().size() - 1;
    //            }
    //            else
    //            {
    //                return MAXSIZE_T;
    //            }
    //        }

    //        object_type *operator[](typename object_ptr_vector_type::size_type n)
    //        {
    //            return Objects()[n];
    //        }
    //    
    //    private:
    //        shared_ptr<object_ptr_vector_type> m_pObjects;

    //        object_ptr_vector_type &Objects()
    //        {
    //            if (!m_pObjects.get())
    //                m_pObjects = make_shared<object_ptr_vector_type>();
    //            return *m_pObjects.get();
    //        }

    //        class deleter
    //        {
    //        public:
    //            deleter(typename provider_type::object_heap_type &heap) : m_pHeap(&heap) { m_disabled[0] = false; }
    //            void operator()(object_type *p) { if (!m_disabled[0]) m_pHeap->Delete(p); }
    //            void DisableDeletion() { m_disabled[0] = true; }
    //        private:
    //            typename provider_type::object_heap_type *m_pHeap;
    //            bool m_disabled[1];
    //        };
    //    };

    //    template<class Sequence>
    //    class PersistableHeapProviderImpl<Sequence, 
    //                                         typename Traits::DistinctEnd<Sequence>::type, 
    //                                         typename Traits::DistinctEnd<Sequence>::type> : 
    //        noncopyable
    //    {
    //    };

    //}   // namespace Detail


    //template<class Sequence>
    //class ATL_NO_VTABLE PersistableHeapProvider : 
    //    public Detail::PersistableHeapProviderImpl<Sequence, 
    //                                              typename Traits::DistinctBegin<Sequence>::type, 
    //                                              typename Traits::DistinctEnd<Sequence>::type>
    //{
    //public:
    //    typedef PersistableHeapProvider<Sequence> this_type;
    //    typedef Sequence sequence_type;

    //    template<class T>
    //    struct provider_of
    //    {
    //        typedef Detail::PersistableHeapProviderImpl<
    //            Sequence,
    //            typename boost::mpl::find<
    //                typename Traits::Distinct<Sequence>::type,
    //                T
    //            >::type,
    //            typename Traits::DistinctEnd<Sequence>::type
    //        > type;
    //    };

    //    template<class T>
    //    inline typename provider_of<T>::type &ProviderOf() const
    //    {
    //        this_type *pMutableThis = const_cast<this_type *>(this);
    //        return static_cast<typename provider_of<T>::type &>(*pMutableThis);
    //    }
    //};

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

#if 0
    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIFieldMetadataApiHolderImpl
        {
            typedef map<
                pair<IFieldMetadataLabel, IFieldMetadata>,
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIFieldMetadataApiHolder : 
        Detail::DefaultIFieldMetadataApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIPropertyMetadataApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<IPropertyMetadataLabel, IPropertyMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIPropertyMetadataApiHolder : 
        Detail::DefaultIPropertyMetadataApiHolderImpl
    {
    };

    
    
    
    
    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultAssemblyMetadataGenerator7FAEDE99ApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadataLabel, IAssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<ModuleMetadataGenerator7FAEDE99Label, ModuleMetadataGenerator7FAEDE99>,
                pair<IModuleMetadataHashLabel, IModuleMetadataHash>,
                pair<IModuleMetadataEqualToLabel, IModuleMetadataEqualTo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyMetadataGenerator7FAEDE99ApiHolder : 
        Detail::DefaultAssemblyMetadataGenerator7FAEDE99ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultModuleMetadataGenerator7FAEDE99ApiHolderImpl
        {
            typedef map<
                pair<IModuleMetadataLabel, IModuleMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<AssemblyMetadataGenerator7FAEDE99Label, AssemblyMetadataGenerator7FAEDE99>,
                pair<TypeMetadataGenerator7FAEDE99Label, TypeMetadataGenerator7FAEDE99>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultModuleMetadataGenerator7FAEDE99ApiHolder : 
        Detail::DefaultModuleMetadataGenerator7FAEDE99ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeMetadataGenerator7FAEDE99ApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadataLabel, ITypeMetadata>,
                pair<ITypeMetadataHashLabel, ITypeMetadataHash>,
                pair<ITypeMetadataEqualToLabel, ITypeMetadataEqualTo>,
                pair<ModuleMetadataGenerator7FAEDE99Label, ModuleMetadataGenerator7FAEDE99>,
                pair<MetadataDispenserLabel, MetadataDispenser>,
                pair<FieldMetadataGenerator7FAEDE99Label, FieldMetadataGenerator7FAEDE99>,
                pair<IFieldMetadataHashLabel, IFieldMetadataHash>,
                pair<IFieldMetadataEqualToLabel, IFieldMetadataEqualTo>,
                pair<MethodMetadataGenerator7FAEDE99Label, MethodMetadataGenerator7FAEDE99>,
                pair<IMethodMetadataHashLabel, IMethodMetadataHash>,
                pair<IMethodMetadataEqualToLabel, IMethodMetadataEqualTo>,
                pair<PropertyMetadataGenerator7FAEDE99Label, PropertyMetadataGenerator7FAEDE99>,
                pair<IPropertyMetadataHashLabel, IPropertyMetadataHash>,                 
                pair<IPropertyMetadataEqualToLabel, IPropertyMetadataEqualTo> 
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultTypeMetadataGenerator7FAEDE99ApiHolder : 
        Detail::DefaultTypeMetadataGenerator7FAEDE99ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultFieldMetadataGenerator7FAEDE99ApiHolderImpl
        {
            typedef map<
                pair<IFieldMetadataLabel, IFieldMetadata>,
                pair<TypeMetadataGenerator7FAEDE99Label, TypeMetadataGenerator7FAEDE99>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultFieldMetadataGenerator7FAEDE99ApiHolder : 
        Detail::DefaultFieldMetadataGenerator7FAEDE99ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMethodMetadataGenerator7FAEDE99ApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadataLabel, IMethodMetadata>,
                pair<TypeMetadataGenerator7FAEDE99Label, TypeMetadataGenerator7FAEDE99>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMethodMetadataGenerator7FAEDE99ApiHolder : 
        Detail::DefaultMethodMetadataGenerator7FAEDE99ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultPropertyMetadataGenerator7FAEDE99ApiHolderImpl
        {
            typedef map<
                pair<TypeMetadataGenerator7FAEDE99Label, TypeMetadataGenerator7FAEDE99>,
                pair<MethodMetadataGenerator7FAEDE99Label, MethodMetadataGenerator7FAEDE99>,
                pair<IPropertyMetadataLabel, IPropertyMetadata>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultPropertyMetadataGenerator7FAEDE99ApiHolder : 
        Detail::DefaultPropertyMetadataGenerator7FAEDE99ApiHolderImpl
    {
    };
#endif

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#if 0
    template<class ApiCartridgesHolder, class ApiLabel>
    struct IFieldMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IFieldMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IFieldMetadataApiHolder
    >    
    class BaseIFieldMetadata
    {
    public:
        typedef BaseIFieldMetadata<IFieldMetadataApiHolder> this_type;

        typedef typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::IFieldMetadataLabel>::type i_field_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetResolutionScope() const = 0;
    };

    
    
    

    template<
        class IFieldMetadataApiHolder
    >    
    struct BaseIFieldMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::IFieldMetadataLabel>::type const> >
    {
        typedef typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_type_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class IFieldMetadataApiHolder
    >    
    struct BaseIFieldMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::IFieldMetadataLabel>::type const> >
    {
        //typedef typename IFieldMetadataApiAt<IFieldMetadataApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       i_type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IPropertyMetadataApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IPropertyMetadataApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IPropertyMetadataApiHolder
    >    
    class BaseIPropertyMetadata
    {
    public:
        typedef BaseIPropertyMetadata<IPropertyMetadataApiHolder> this_type;

        typedef typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::ITypeMetadataLabel>::type i_type_metadata_type;
        typedef typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::IPropertyMetadataLabel>::type i_property_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetResolutionScope() const = 0;
    };

    
    
    

    template<
        class IPropertyMetadataApiHolder
    >    
    struct BaseIPropertyMetadataHash : 
        Traits::HashComputable<boost::shared_ptr<typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::IPropertyMetadataLabel>::type const> >
    {
        typedef typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_type_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };
    
    
    
    
    
    template<
        class IPropertyMetadataApiHolder
    >    
    struct BaseIPropertyMetadataEqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::IPropertyMetadataLabel>::type const> >
    {
        //typedef typename IPropertyMetadataApiAt<IPropertyMetadataApiHolder, Interfaces::ITypeNameMetadataEqualToLabel>::type i_type_name_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       i_type_name_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };

    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadataGenerator7FAEDE99ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadataGenerator7FAEDE99ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseAssemblyMetadataGenerator7FAEDE99 : 
        public SmartPtrChain<
            BaseAssemblyMetadataGenerator7FAEDE99<AssemblyMetadataGenerator7FAEDE99ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename AssemblyMetadataGenerator7FAEDE99ApiAt<AssemblyMetadataGenerator7FAEDE99ApiHolder, Interfaces::MetadataDispenserLabel>::type>
            >
        >,
        public AssemblyMetadataGenerator7FAEDE99ApiAt<AssemblyMetadataGenerator7FAEDE99ApiHolder, Interfaces::IAssemblyMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseAssemblyMetadataGenerator7FAEDE99<AssemblyMetadataGenerator7FAEDE99ApiHolder> this_type;
        typedef typename AssemblyMetadataGenerator7FAEDE99ApiAt<AssemblyMetadataGenerator7FAEDE99ApiHolder, Interfaces::IAssemblyMetadataLabel>::type base_type;

        typedef typename AssemblyMetadataGenerator7FAEDE99ApiAt<AssemblyMetadataGenerator7FAEDE99ApiHolder, Interfaces::ModuleMetadataGenerator7FAEDE99Label>::type module_metadata_generator_type;
        typedef typename AssemblyMetadataGenerator7FAEDE99ApiAt<AssemblyMetadataGenerator7FAEDE99ApiHolder, Interfaces::IModuleMetadataHashLabel>::type i_module_metadata_hash_type;
        typedef typename AssemblyMetadataGenerator7FAEDE99ApiAt<AssemblyMetadataGenerator7FAEDE99ApiHolder, Interfaces::IModuleMetadataEqualToLabel>::type i_module_metadata_equal_to_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(AsmGen, module_metadata_generator_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(AsmGen, module_metadata_generator_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(AsmGen, module_metadata_generator_provider_type, typename base_type::metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(AsmGen, module_metadata_generator_provider_type, typename base_type::metadata_dispenser_type), 
            boost::mpl::void_
        >::type module_metadata_generator_provider_type;

        typedef typename chain_from<typename base_type::metadata_dispenser_type>::type assembly_metadata_generator_chain_type;
        
        mdAssembly GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
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
            if (!m_pSnKey)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_pSnKey;
        }

        boost::shared_ptr<typename base_type::metadata_dispenser_type const> GetResolutionScope() const
        {
            return Map<typename base_type::metadata_dispenser_type>();
        }

        void SetStrongNameKey(boost::shared_ptr<typename base_type::strong_name_key_type const> const &pSnKey)
        {
            m_pSnKey = pSnKey;
        }

        boost::shared_ptr<module_metadata_generator_type> DefineModule(std::wstring const &name)
        {
            boost::shared_ptr<module_metadata_generator_type> pModGen;
            pModGen = NewModuleGenerator(name);

            boost::shared_ptr<module_metadata_generator_type> pExistingModGen;
            if (!TryGetModuleGenerator(*pModGen, pExistingModGen))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                module_metadata_generator_provider_type &provider = pDisp->ProviderOf<module_metadata_generator_type>();
                m_modGenToIndex[pModGen] = provider.Register(pModGen);
                return pModGen;
            }
            else
            {
                return pExistingModGen;
            }
        }

    private:
        friend typename typename base_type::metadata_dispenser_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        boost::shared_ptr<module_metadata_generator_type> NewModuleGenerator(std::wstring const &name) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            module_metadata_generator_provider_type &provider = pDisp->ProviderOf<module_metadata_generator_type>();
            assembly_metadata_generator_chain_type &chain = ChainFrom<typename base_type::metadata_dispenser_type>();
            boost::shared_ptr<module_metadata_generator_type> pModGen = chain.NewObject<module_metadata_generator_type>(provider);
            pModGen->SetName(name);
            return pModGen;
        }

        bool TryGetModuleGenerator(module_metadata_generator_type const &keyModGen, boost::shared_ptr<module_metadata_generator_type> &pExistingModGen) const
        {
            boost::shared_ptr<module_metadata_generator_type const> pKeyModGen(&keyModGen, Utilities::MakeNullDeleter(&keyModGen));
            if (m_modGenToIndex.find(pKeyModGen) == m_modGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_modGenToIndex[pKeyModGen];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                module_metadata_generator_provider_type &provider = pDisp->ProviderOf<module_metadata_generator_type>();
                pExistingModGen = provider[index];
                return true;
            }
        }

        std::wstring m_name;
        boost::shared_ptr<typename base_type::strong_name_key_type const> m_pSnKey;
        mutable boost::unordered_map<boost::shared_ptr<module_metadata_generator_type const>, 
                                     size_t, 
                                     i_module_metadata_hash_type, 
                                     i_module_metadata_equal_to_type> m_modGenToIndex;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleMetadataGenerator7FAEDE99ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleMetadataGenerator7FAEDE99ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseModuleMetadataGenerator7FAEDE99 : 
        public SmartPtrChain<
            BaseModuleMetadataGenerator7FAEDE99<ModuleMetadataGenerator7FAEDE99ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::AssemblyMetadataGenerator7FAEDE99Label>::type>
            >
        >,
        public ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::IModuleMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseModuleMetadataGenerator7FAEDE99<ModuleMetadataGenerator7FAEDE99ApiHolder> this_type;
        typedef typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::IModuleMetadataLabel>::type base_type;
        
        typedef typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::AssemblyMetadataGenerator7FAEDE99Label>::type assembly_metadata_generator_type;
        typedef typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type type_metadata_generator_type;        
        typedef typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;
        typedef typename ModuleMetadataGenerator7FAEDE99ApiAt<ModuleMetadataGenerator7FAEDE99ApiHolder, Interfaces::ITypeMetadataEqualToLabel>::type i_type_metadata_equal_to_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ModGen, type_metadata_generator_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ModGen, type_metadata_generator_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(ModGen, type_metadata_generator_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(ModGen, type_metadata_generator_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type type_metadata_generator_provider_type;

        typedef typename chain_from<assembly_metadata_generator_type>::type module_metadata_generator_chain_type;

        mdModule GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
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
            return Map<assembly_metadata_generator_type>();
        }

        boost::shared_ptr<type_metadata_generator_type> DefineType(std::wstring const &name, TypeAttributes const &attr)
        {
            boost::shared_ptr<type_metadata_generator_type> pTypeGen;
            pTypeGen = NewTypeGenerator(name, attr);

            boost::shared_ptr<type_metadata_generator_type> pExistingTypeGen;
            if (!TryGetTypeGenerator(*pTypeGen, pExistingTypeGen))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_generator_provider_type &provider = pDisp->ProviderOf<type_metadata_generator_type>();
                m_typeGenToIndex[pTypeGen] = provider.Register(pTypeGen);
                return pTypeGen;
            }
            else
            {
                return pExistingTypeGen;
            }
        }

    private:
        friend typename assembly_metadata_generator_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        boost::shared_ptr<type_metadata_generator_type> NewTypeGenerator(std::wstring const &name, TypeAttributes const &attr) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            type_metadata_generator_provider_type &provider = pDisp->ProviderOf<type_metadata_generator_type>();
            module_metadata_generator_chain_type &chain = ChainFrom<assembly_metadata_generator_type>();
            boost::shared_ptr<type_metadata_generator_type> pTypeGen = chain.NewObject<type_metadata_generator_type>(provider);
            pTypeGen->SetName(name);
            pTypeGen->SetAttribute(attr);
            return pTypeGen;
        }

        bool TryGetTypeGenerator(type_metadata_generator_type const &keyTypeGen, boost::shared_ptr<type_metadata_generator_type> &pExistingTypeGen) const
        {
            boost::shared_ptr<type_metadata_generator_type const> pKeyTypeGen(&keyTypeGen, Utilities::MakeNullDeleter(&keyTypeGen));
            if (m_typeGenToIndex.find(pKeyTypeGen) == m_typeGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_typeGenToIndex[pKeyTypeGen];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_generator_provider_type &provider = pDisp->ProviderOf<type_metadata_generator_type>();
                pExistingTypeGen = provider[index];
                return true;
            }
        }

        std::wstring m_name;
        mutable boost::unordered_map<boost::shared_ptr<type_metadata_generator_type const>, 
                                     size_t, 
                                     i_type_metadata_hash_type, 
                                     i_type_metadata_equal_to_type> m_typeGenToIndex;        
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadataGenerator7FAEDE99ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadataGenerator7FAEDE99ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseTypeMetadataGenerator7FAEDE99 : 
        public SmartPtrChain<
            BaseTypeMetadataGenerator7FAEDE99<TypeMetadataGenerator7FAEDE99ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<BaseTypeMetadataGenerator7FAEDE99<TypeMetadataGenerator7FAEDE99ApiHolder> >,
                SmartPtrChainInfo<typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::ModuleMetadataGenerator7FAEDE99Label>::type>
            >
        >,
        public TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::ITypeMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseTypeMetadataGenerator7FAEDE99<TypeMetadataGenerator7FAEDE99ApiHolder> this_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::ITypeMetadataLabel>::type base_type;

        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::ModuleMetadataGenerator7FAEDE99Label>::type module_metadata_generator_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::MetadataDispenserLabel>::type metadata_dispenser_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::ITypeMetadataHashLabel>::type i_type_metadata_hash_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::ITypeMetadataEqualToLabel>::type i_type_metadata_equal_to_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::FieldMetadataGenerator7FAEDE99Label>::type field_metadata_generator_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::IFieldMetadataHashLabel>::type i_field_metadata_hash_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::IFieldMetadataEqualToLabel>::type i_field_metadata_equal_to_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::MethodMetadataGenerator7FAEDE99Label>::type method_metadata_generator_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::IMethodMetadataHashLabel>::type i_method_metadata_hash_type; 
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::IMethodMetadataEqualToLabel>::type i_method_metadata_equal_to_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::PropertyMetadataGenerator7FAEDE99Label>::type property_metadata_generator_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::IPropertyMetadataHashLabel>::type i_property_metadata_hash_type;
        typedef typename TypeMetadataGenerator7FAEDE99ApiAt<TypeMetadataGenerator7FAEDE99ApiHolder, Interfaces::IPropertyMetadataEqualToLabel>::type i_property_metadata_equal_to_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeGen, type_metadata_generator_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeGen, type_metadata_generator_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeGen, type_metadata_generator_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeGen, type_metadata_generator_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type type_metadata_generator_provider_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeGen, field_metadata_generator_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeGen, field_metadata_generator_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeGen, field_metadata_generator_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeGen, field_metadata_generator_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type field_metadata_generator_provider_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeGen, method_metadata_generator_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeGen, method_metadata_generator_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeGen, method_metadata_generator_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeGen, method_metadata_generator_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type method_metadata_generator_provider_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TypeGen, property_metadata_generator_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(TypeGen, property_metadata_generator_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(TypeGen, property_metadata_generator_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(TypeGen, property_metadata_generator_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type property_metadata_generator_provider_type;

        typedef typename chain_from<this_type>::type type_metadata_generator_chain_type;

        BaseTypeMetadataGenerator7FAEDE99() : 
            m_attrInitialized(false),
            m_attr(TypeAttributes::TA_VISIBILITY_MASK)
        { }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        boost::shared_ptr<typename base_type::this_type const> GetBaseType() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        boost::shared_ptr<typename base_type::i_module_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<module_metadata_generator_type>();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        bool IsGenericParameter() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        TypeAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

        boost::shared_ptr<this_type> DefineNestedType(std::wstring const &name, TypeAttributes const &attr)
        {
            boost::shared_ptr<this_type> pNestedTypeGen;
            pNestedTypeGen = NewNestedTypeGenerator(name, attr);

            boost::shared_ptr<this_type> pExistingNestedTypeGen;
            if (!TryGetNestedTypeGenerator(*pNestedTypeGen, pExistingNestedTypeGen))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_generator_provider_type &provider = pDisp->ProviderOf<this_type>();
                m_nestedTypeGenToIndex[pNestedTypeGen] = provider.Register(pNestedTypeGen);
                return pNestedTypeGen;
            }
            else
            {
                return pExistingNestedTypeGen;
            }
        }

        boost::shared_ptr<field_metadata_generator_type> DefineField(std::wstring const &name, 
                                                                     boost::shared_ptr<typename base_type::this_type const> const &pFieldType, 
                                                                     FieldAttributes const &attr)
        {
            boost::shared_ptr<field_metadata_generator_type> pFieldGen;
            pFieldGen = NewFieldGenerator(name, pFieldType, attr);

            boost::shared_ptr<field_metadata_generator_type> pExistingFieldGen;
            if (!TryGetFieldGenerator(*pFieldGen, pExistingFieldGen))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                field_metadata_generator_provider_type &provider = pDisp->ProviderOf<field_metadata_generator_type>();
                m_fieldGenToIndex[pFieldGen] = provider.Register(pFieldGen);
                return pFieldGen;
            }
            else
            {
                return pExistingFieldGen;
            }
        }

        boost::shared_ptr<method_metadata_generator_type> DefineMethod(std::wstring const &name, 
                                                                       CallingConventions const &callingConvention, 
                                                                       boost::shared_ptr<typename base_type::this_type const> const &pRetType, 
                                                                       std::vector<boost::shared_ptr<typename base_type::this_type const> > const &paramTypes,
                                                                       MethodAttributes const &attr)
        {
            boost::shared_ptr<method_metadata_generator_type> pMethodGen;
            pMethodGen = NewMethodGenerator(name, callingConvention, pRetType, paramTypes, attr);

            boost::shared_ptr<method_metadata_generator_type> pExistingMethodGen;
            if (!TryGetMethodGenerator(*pMethodGen, pExistingMethodGen))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                method_metadata_generator_provider_type &provider = pDisp->ProviderOf<method_metadata_generator_type>();
                m_methodGenToIndex[pMethodGen] = provider.Register(pMethodGen);
                return pMethodGen;
            }
            else
            {
                return pExistingMethodGen;
            }
        }

        boost::shared_ptr<property_metadata_generator_type> DefineProperty(std::wstring const &name, 
                                                                           boost::shared_ptr<typename base_type::this_type const> const &pPropType,
                                                                           std::vector<boost::shared_ptr<typename base_type::this_type const> > const &paramTypes,
                                                                           PropertyAttributes const &attr) const
        {
            boost::shared_ptr<property_metadata_generator_type> pPropGen;
            pPropGen = NewPropertyGenerator(name, pPropType, paramTypes, attr);

            boost::shared_ptr<property_metadata_generator_type> pExistingPropGen;
            if (!TryGetPropertyGenerator(*pPropGen, pExistingPropGen))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                property_metadata_generator_provider_type &provider = pDisp->ProviderOf<property_metadata_generator_type>();
                m_propGenToIndex[pPropGen] = provider.Register(pPropGen);
                return pPropGen;
            }
            else
            {
                return pExistingPropGen;
            }
        }

    private:
        friend typename module_metadata_generator_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetAttribute(TypeAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        boost::shared_ptr<this_type> NewNestedTypeGenerator(std::wstring const &name, TypeAttributes const &attr) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            type_metadata_generator_provider_type &provider = pDisp->ProviderOf<this_type>();
            type_metadata_generator_chain_type &chain = ChainFrom<this_type>();
            boost::shared_ptr<this_type> pTypeGen = chain.NewObject<this_type>(provider);
            pTypeGen->SetName(name);
            pTypeGen->SetAttribute(attr);
            return pTypeGen;
        }

        bool TryGetNestedTypeGenerator(this_type const &keyNestedTypeGen, boost::shared_ptr<this_type> &pExistingNestedTypeGen) const
        {
            boost::shared_ptr<this_type const> pKeyNestedTypeGen(&keyNestedTypeGen, Utilities::MakeNullDeleter(&keyNestedTypeGen));
            if (m_nestedTypeGenToIndex.find(pKeyNestedTypeGen) == m_nestedTypeGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_nestedTypeGenToIndex[pKeyNestedTypeGen];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                type_metadata_generator_provider_type &provider = pDisp->ProviderOf<this_type>();
                pExistingNestedTypeGen = provider[index];
                return true;
            }
        }

        boost::shared_ptr<field_metadata_generator_type> NewFieldGenerator(std::wstring const &name, 
                                                                           boost::shared_ptr<typename base_type::this_type const> const &pFieldType, 
                                                                           FieldAttributes const &attr) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            field_metadata_generator_provider_type &provider = pDisp->ProviderOf<field_metadata_generator_type>();
            boost::shared_ptr<field_metadata_generator_type> pFieldGen = NewObjectFirst<field_metadata_generator_type>(provider);
            pFieldGen->SetName(name);
            pFieldGen->SetFieldType(pFieldType);
            pFieldGen->SetAttribute(attr);
            return pFieldGen;
        }

        bool TryGetFieldGenerator(field_metadata_generator_type const &keyFieldGen, boost::shared_ptr<field_metadata_generator_type> &pExistingFieldGen) const
        {
            boost::shared_ptr<field_metadata_generator_type const> pKeyFieldGen(&keyFieldGen, Utilities::MakeNullDeleter(&keyFieldGen));
            if (m_fieldGenToIndex.find(pKeyFieldGen) == m_fieldGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_fieldGenToIndex[pKeyFieldGen];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                field_metadata_generator_provider_type &provider = pDisp->ProviderOf<field_metadata_generator_type>();
                pExistingFieldGen = provider[index];
                return true;
            }
        }

        boost::shared_ptr<method_metadata_generator_type> NewMethodGenerator(std::wstring const &name, 
                                                                             CallingConventions const &callingConvention, 
                                                                             boost::shared_ptr<typename base_type::this_type const> const &pRetType, 
                                                                             std::vector<boost::shared_ptr<typename base_type::this_type const> > const &paramTypes,
                                                                             MethodAttributes const &attr) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            method_metadata_generator_provider_type &provider = pDisp->ProviderOf<method_metadata_generator_type>();
            boost::shared_ptr<method_metadata_generator_type> pMethodGen = NewObjectFirst<method_metadata_generator_type>(provider);
            pMethodGen->SetName(name);
            pMethodGen->SetCallingConvention(callingConvention);
            pMethodGen->SetReturnType(pRetType);
            pMethodGen->SetParameterTypes(paramTypes);
            pMethodGen->SetAttribute(attr);
            return pMethodGen;
        }

        bool TryGetMethodGenerator(method_metadata_generator_type const &keyMethodGen, boost::shared_ptr<method_metadata_generator_type> &pExistingMethodGen) const
        {
            boost::shared_ptr<method_metadata_generator_type const> pKeyMethodGen(&keyMethodGen, Utilities::MakeNullDeleter(&keyMethodGen));
            if (m_methodGenToIndex.find(pKeyMethodGen) == m_methodGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_methodGenToIndex[pKeyMethodGen];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                method_metadata_generator_provider_type &provider = pDisp->ProviderOf<method_metadata_generator_type>();
                pExistingMethodGen = provider[index];
                return true;
            }
        }

        boost::shared_ptr<property_metadata_generator_type> NewPropertyGenerator(std::wstring const &name, 
                                                                                 boost::shared_ptr<typename base_type::this_type const> const &pPropType,
                                                                                 std::vector<boost::shared_ptr<typename base_type::this_type const> > const &paramTypes,
                                                                                 PropertyAttributes const &attr) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            property_metadata_generator_provider_type &provider = pDisp->ProviderOf<property_metadata_generator_type>();
            boost::shared_ptr<property_metadata_generator_type> pPropGen = NewObjectFirst<property_metadata_generator_type>(provider);
            pPropGen->SetName(name);
            pPropGen->SetPropertyType(pPropType);
            pPropGen->SetParameterTypes(paramTypes);
            pPropGen->SetAttribute(attr);
            return pPropGen;
        }

        bool TryGetPropertyGenerator(property_metadata_generator_type const &keyPropGen, boost::shared_ptr<property_metadata_generator_type> &pExistingPropGen) const
        {
            boost::shared_ptr<property_metadata_generator_type const> pKeyPropGen(&keyPropGen, Utilities::MakeNullDeleter(&keyPropGen));
            if (m_propGenToIndex.find(pKeyPropGen) == m_propGenToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_propGenToIndex[pKeyPropGen];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                property_metadata_generator_provider_type &provider = pDisp->ProviderOf<property_metadata_generator_type>();
                pExistingPropGen = provider[index];
                return true;
            }
        }

        std::wstring m_name;
        bool m_attrInitialized;
        TypeAttributes m_attr;
        mutable boost::unordered_map<boost::shared_ptr<this_type const>, 
                                     size_t, 
                                     i_type_metadata_hash_type, 
                                     i_type_metadata_equal_to_type> m_nestedTypeGenToIndex;
        mutable boost::unordered_map<boost::shared_ptr<field_metadata_generator_type const>, 
                                     size_t, 
                                     i_field_metadata_hash_type, 
                                     i_field_metadata_equal_to_type> m_fieldGenToIndex;        
        mutable boost::unordered_map<boost::shared_ptr<method_metadata_generator_type const>, 
                                     size_t, 
                                     i_method_metadata_hash_type, 
                                     i_method_metadata_equal_to_type> m_methodGenToIndex;
        mutable boost::unordered_map<boost::shared_ptr<property_metadata_generator_type const>, 
                                     size_t, 
                                     i_property_metadata_hash_type, 
                                     i_property_metadata_equal_to_type> m_propGenToIndex;                                     
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct FieldMetadataGenerator7FAEDE99ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::FieldMetadataGenerator7FAEDE99ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FieldMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseFieldMetadataGenerator7FAEDE99 : 
        public SmartPtrChain<
            BaseFieldMetadataGenerator7FAEDE99<FieldMetadataGenerator7FAEDE99ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename FieldMetadataGenerator7FAEDE99ApiAt<FieldMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type>
            >
        >,
        public FieldMetadataGenerator7FAEDE99ApiAt<FieldMetadataGenerator7FAEDE99ApiHolder, Interfaces::IFieldMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseFieldMetadataGenerator7FAEDE99<FieldMetadataGenerator7FAEDE99ApiHolder> this_type;
        typedef typename FieldMetadataGenerator7FAEDE99ApiAt<FieldMetadataGenerator7FAEDE99ApiHolder, Interfaces::IFieldMetadataLabel>::type base_type;

        typedef typename FieldMetadataGenerator7FAEDE99ApiAt<FieldMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type type_metadata_generator_type;

        BaseFieldMetadataGenerator7FAEDE99() : 
            m_attrInitialized(false),
            m_attr(FieldAttributes::FA_FIELD_ACCESS_MASK)
        { }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<type_metadata_generator_type>();
        }

        FieldAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

    private:
        friend typename type_metadata_generator_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetFieldType(boost::shared_ptr<typename base_type::i_type_metadata_type const> const &pFieldType)
        {
            _ASSERTE(!m_pFieldType);
            m_pFieldType = pFieldType;
        }

        void SetAttribute(FieldAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        std::wstring m_name;
        boost::shared_ptr<typename base_type::i_type_metadata_type const> m_pFieldType;
        bool m_attrInitialized;
        FieldAttributes m_attr;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadataGenerator7FAEDE99ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadataGenerator7FAEDE99ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadataGenerator7FAEDE99ApiHolder
    >    
    class BaseMethodMetadataGenerator7FAEDE99 : 
        public SmartPtrChain<
            BaseMethodMetadataGenerator7FAEDE99<MethodMetadataGenerator7FAEDE99ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MethodMetadataGenerator7FAEDE99ApiAt<MethodMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type>
            >
        >,
        public MethodMetadataGenerator7FAEDE99ApiAt<MethodMetadataGenerator7FAEDE99ApiHolder, Interfaces::IMethodMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseMethodMetadataGenerator7FAEDE99<MethodMetadataGenerator7FAEDE99ApiHolder> this_type;
        typedef typename MethodMetadataGenerator7FAEDE99ApiAt<MethodMetadataGenerator7FAEDE99ApiHolder, Interfaces::IMethodMetadataLabel>::type base_type;

        typedef typename MethodMetadataGenerator7FAEDE99ApiAt<MethodMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type type_metadata_generator_type;

        BaseMethodMetadataGenerator7FAEDE99() : 
            m_callingConvention(CallingConventions::CC_NO_VALUE), 
            m_paramTypesInitialized(false),
            m_attrInitialized(false),
            m_attr(MethodAttributes::MA_MEMBER_ACCESS_MASK)
        { }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        CallingConventions const &GetCallingConvention() const
        {
            if (m_callingConvention == CallingConventions::CC_NO_VALUE)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_callingConvention;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetReturnType() const
        {
            if (!m_pRetType)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_pRetType;
        }

        std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > const &GetParameterTypes() const
        {
            if (!m_paramTypesInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_paramTypes;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<type_metadata_generator_type>();
        }

        MethodAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

    private:
        friend typename type_metadata_generator_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetCallingConvention(CallingConventions const &callingConvention)
        {
            _ASSERTE(callingConvention != CallingConventions::CC_NO_VALUE);
            _ASSERTE(m_callingConvention == CallingConventions::CC_NO_VALUE);
            m_callingConvention = callingConvention;
        }

        void SetReturnType(boost::shared_ptr<typename base_type::i_type_metadata_type const> const &pRetType)
        {
            _ASSERTE(!m_pRetType);
            m_pRetType = pRetType;
        }

        void SetParameterTypes(std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        void SetAttribute(MethodAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        std::wstring m_name;
        CallingConventions m_callingConvention;
        boost::shared_ptr<typename base_type::i_type_metadata_type const> m_pRetType;
        bool m_paramTypesInitialized;
        std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > m_paramTypes;
        bool m_attrInitialized;
        MethodAttributes m_attr;
    };

    template<class ApiCartridgesHolder, class ApiLabel>
    struct PropertyMetadataGenerator7FAEDE99ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::PropertyMetadataGenerator7FAEDE99ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class PropertyMetadataGenerator7FAEDE99ApiHolder
    >    
    class BasePropertyMetadataGenerator7FAEDE99 : 
        public SmartPtrChain<
            BasePropertyMetadataGenerator7FAEDE99<PropertyMetadataGenerator7FAEDE99ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename PropertyMetadataGenerator7FAEDE99ApiAt<PropertyMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type>
            >
        >,
        public PropertyMetadataGenerator7FAEDE99ApiAt<PropertyMetadataGenerator7FAEDE99ApiHolder, Interfaces::IPropertyMetadataLabel>::type,
        public SimpleDisposable
    {
    public:
        typedef BasePropertyMetadataGenerator7FAEDE99<PropertyMetadataGenerator7FAEDE99ApiHolder> this_type;
        typedef typename PropertyMetadataGenerator7FAEDE99ApiAt<PropertyMetadataGenerator7FAEDE99ApiHolder, Interfaces::IPropertyMetadataLabel>::type base_type;

        typedef typename PropertyMetadataGenerator7FAEDE99ApiAt<PropertyMetadataGenerator7FAEDE99ApiHolder, Interfaces::TypeMetadataGenerator7FAEDE99Label>::type type_metadata_generator_type;
        typedef typename PropertyMetadataGenerator7FAEDE99ApiAt<PropertyMetadataGenerator7FAEDE99ApiHolder, Interfaces::MethodMetadataGenerator7FAEDE99Label>::type method_metadata_generator_type;

        BasePropertyMetadataGenerator7FAEDE99() : 
            m_paramTypesInitialized(false),
            m_attrInitialized(false),
            m_attr(PropertyAttributes::PA_NONE)
        { }

        mdToken GetToken() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        std::wstring const &GetName() const
        {
            if (m_name.empty())
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_name;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<type_metadata_generator_type>();
        }

        boost::shared_ptr<method_metadata_generator_type const> GetGetMethod() const
        {
            return m_pGetMethod;
        }

        boost::shared_ptr<method_metadata_generator_type const> GetSetMethod() const
        {
            return m_pSetMethod;
        }

        void SetGetMethod(boost::shared_ptr<method_metadata_generator_type const> const &pGetMethod)
        {
            m_pGetMethod = pGetMethod;
        }

        void SetSetMethod(boost::shared_ptr<method_metadata_generator_type const> const &pSetMethod)
        {
            m_pSetMethod = pSetMethod;
        }

        boost::shared_ptr<typename base_type::i_type_metadata_type const> GetPropertyType() const
        {
            if (!m_pPropType)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_pPropType;
        }

        std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > const &GetParameterTypes() const
        {
            if (!m_paramTypesInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_paramTypes;
        }

        PropertyAttributes const &GetAttribute() const
        {
            if (!m_attrInitialized)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            return m_attr;
        }

    private:
        friend typename type_metadata_generator_type;
        
        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetPropertyType(boost::shared_ptr<typename base_type::i_type_metadata_type const> const &pPropType)
        {
            _ASSERTE(!m_pPropType);
            m_pPropType = pPropType;
        }

        void SetParameterTypes(std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        void SetAttribute(PropertyAttributes const &attr)
        {
            _ASSERTE(!m_attrInitialized);
            m_attr = attr;
            m_attrInitialized = true;
        }

        std::wstring m_name;
        boost::shared_ptr<typename base_type::i_type_metadata_type const> m_pPropType;
        bool m_paramTypesInitialized;
        std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> > m_paramTypes;
        bool m_attrInitialized;
        PropertyAttributes m_attr;
        boost::shared_ptr<method_metadata_generator_type const> m_pGetMethod;
        boost::shared_ptr<method_metadata_generator_type const> m_pSetMethod;
    };

#endif

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTASSEMBLYINFOAPIHOLDER_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultAssemblyInfoApiHolder.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEASSEMBLYINFO_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseAssemblyInfo.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test2.*
namespace {

    namespace _6C8E937E {

        struct A
        {
            template<class T>
            boost::shared_ptr<T> F(T *p)
            {
                return boost::shared_ptr<T>(p);
            }

            template<class T>
            void G(T *p)
            {
                shared_ptr<T> p_ = F<T>(p);      // ???
                std::cout << *p_ << std::endl;
            }
        }; 

    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, ADL_Test_01)
    {
        using namespace _6C8E937E;

        A().G<int>(new int(10));
    }

    
    
    
    
    namespace _B3C3B24D {

    using namespace Urasandesu::CppAnonym;
    using namespace Urasandesu::CppAnonym::Utilities;

    struct Hoge;
    struct Piyo;

    struct Hoge
    {
        Hoge() : m_pPiyo(boost::make_shared<Piyo>()) { std::cout << "Hoge " << *reinterpret_cast<int *>(this) << " is constructed !!" << std::endl; }
        virtual ~Hoge() { std::cout << "Hoge " << *reinterpret_cast<int *>(this) << " is destructed !!" << std::endl; }

        int m_value;
        boost::shared_ptr<Piyo> m_pPiyo;
    };

    struct Piyo
    {
        Piyo() { std::cout << "Piyo " << *reinterpret_cast<int *>(this) << " is constructed !!" << std::endl; }
        virtual ~Piyo() { std::cout << "Piyo " << *reinterpret_cast<int *>(this) << " is destructed !!" << std::endl; }

        int m_value;
    };

    }   // namespace _B3C3B24D {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, TempPtr_Test_01)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace _B3C3B24D;

        {
            TempPtr<Hoge> pHoge(new Hoge());
            pHoge->m_value = 10;
        }

        {
            Hoge *pHoge = NULL;
            {
                TempPtr<Hoge> pHoge_(new Hoge());
                pHoge_->m_value = 10;
                pHoge_.Persist();
                pHoge = pHoge_.Get();
            }
            delete pHoge;
        }
        {
            static TempPtr<Hoge> pHoge(new Hoge());
        }

        struct Factory
        {
            static TempPtr<Hoge> Create()
            {
                return TempPtr<Hoge>(new Hoge());
            }
        };

        TempPtr<Hoge> pHoge(Factory::Create());
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, TempPtr_Test_02)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace _B3C3B24D;

        struct HogeHeap
        {
            Hoge *New() { return new Hoge(); }
            void Delete(Hoge *p) { delete p; } 
        };
        typedef HeapDeleter<HogeHeap> HogeHeapDeleter;

        HogeHeap heap;

        {
            TempPtr<Hoge> pHoge(heap.New(), HogeHeapDeleter(heap));
            pHoge->m_value = 10;
        }

        {
            Hoge *pHoge = NULL;
            {
                TempPtr<Hoge> pHoge_(heap.New(), HogeHeapDeleter(heap));
                pHoge_->m_value = 10;
                pHoge_.Persist();
                pHoge = pHoge_.Get();
            }
            heap.Delete(pHoge);
        }
        {
            static TempPtr<Hoge> pHoge(heap.New(), HogeHeapDeleter(heap));   // こっちで使う場合は、Heap を表す object も static 領域にある必要がある。
        }
    }

    
    
    
    
    namespace _3A0FFF2F {

    using namespace Urasandesu::CppAnonym;
    using namespace Urasandesu::CppAnonym::Utilities;
    
    struct Hoge;
    struct Piyo;

    struct Hoge : 
        PersistableHeapProvider<boost::mpl::vector<Hoge, Piyo> >
    {
        typedef Hoge this_type;
        typedef Piyo piyo_type;

        typedef provider_of<this_type>::type hoge_provider_type;        
        typedef provider_of<piyo_type>::type piyo_provider_type;

        Hoge() { std::cout << "Hoge " << *reinterpret_cast<int *>(this) << " is constructed !!" << std::endl; }
        virtual ~Hoge() { std::cout << "Hoge " << *reinterpret_cast<int *>(this) << " is destructed !!" << std::endl; }

        static this_type *NewHoge()
        {
            TempPtr<this_type> pHoge(hoge_provider_type::NewStaticObject());
            size_t index = hoge_provider_type::RegisterStaticObject(pHoge);
            return pHoge.Get();
        }

        piyo_type *NewPiyo(bool occurredException = false)
        {
            piyo_provider_type &provider = ProviderOf<piyo_type>();
            TempPtr<piyo_type> pPiyo(provider.NewObject());

            if (occurredException)
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());

            size_t index = provider.RegisterObject(pPiyo);
            return pPiyo.Get();
        }
    };

    struct Piyo
    {
        Piyo() { std::cout << "Piyo " << *reinterpret_cast<int *>(this) << " is constructed !!" << std::endl; }
        virtual ~Piyo() { std::cout << "Piyo " << *reinterpret_cast<int *>(this) << " is destructed !!" << std::endl; }
        
        std::vector<boost::shared_ptr<int> > m_ints;
    };

    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, PersistableHeapProvider_Test_01)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace _3A0FFF2F;

        Hoge *pHoge = Hoge::NewHoge();

        // normally case
        {
            Piyo *pPiyo = pHoge->NewPiyo();
            pPiyo->m_ints.push_back(shared_ptr<int>(new int()));
            pPiyo->m_ints.push_back(shared_ptr<int>(new int()));
            pPiyo->m_ints.push_back(shared_ptr<int>(new int()));
            pPiyo->m_ints.push_back(shared_ptr<int>(new int()));
            pPiyo->m_ints.push_back(shared_ptr<int>(new int()));
        }

        // error case
        {
            try
            {
                Piyo *pPiyo = pHoge->NewPiyo(true);
                FAIL() << "We shouldn't get here.";
            }
            catch (CppAnonymNotImplementedException &)
            { }
        }
    }

#if 0
    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, StrongNaming_Test_01)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        shared_ptr<HostInfo const> pHostInfo = HostInfo::NewHost();
        shared_ptr<RuntimeHost const> pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");

        shared_ptr<StrongNameInfo const> pSnInfo = pRuntimeHost->Map<StrongNameInfo>();
        
        shared_ptr<StrongNameKey const> pSnKey;
        pSnKey = pSnInfo->GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        std::vector<BYTE> const &publicKey = pSnKey->GetPublicKey();

        BYTE const PUB_KEY_BLOB[] = {
            0x00, 0x24, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 
            0x94, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 
            0x00, 0x24, 0x00, 0x00, 0x52, 0x53, 0x41, 0x31, 
            0x00, 0x04, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x19, 0xc4, 0x67, 0xdf, 0x70, 0xd1, 0xae, 0xf6, 
            0x96, 0x95, 0xf6, 0x8e, 0x65, 0xaf, 0x52, 0x46, 
            0x0b, 0x8e, 0x00, 0x94, 0x1f, 0x4a, 0x17, 0x5f, 
            0x4d, 0xf8, 0xd3, 0x70, 0x9f, 0x1a, 0x32, 0xd9, 
            0xf3, 0xff, 0xf6, 0xfd, 0x68, 0xb8, 0x79, 0xdc, 
            0x3d, 0xad, 0x60, 0x63, 0x2a, 0x9b, 0x6d, 0x9a, 
            0x5f, 0xc1, 0x9e, 0xf8, 0xb9, 0xd9, 0xae, 0x7a, 
            0xe9, 0xfe, 0x2a, 0xf2, 0x5e, 0x29, 0x02, 0x1b, 
            0xa2, 0x66, 0xad, 0x0b, 0x83, 0x7f, 0xc8, 0x22, 
            0x2f, 0xf5, 0x51, 0x55, 0x67, 0x68, 0xa1, 0x1b, 
            0xae, 0x1d, 0xe5, 0xf7, 0xca, 0xad, 0xf8, 0xc7, 
            0x78, 0x19, 0xfc, 0xfb, 0x8b, 0x3b, 0x73, 0x0b, 
            0x38, 0xe1, 0xeb, 0xcd, 0x68, 0x3d, 0x12, 0xdd, 
            0x87, 0x4f, 0x42, 0x8f, 0xbb, 0x0d, 0xb5, 0xd6, 
            0x92, 0xda, 0xfa, 0x66, 0xa3, 0xe3, 0x6a, 0x8b, 
            0x28, 0xb2, 0x36, 0xb8, 0xde, 0x56, 0x07, 0xda
        };
        DWORD const PUB_KEY_BLOB_SIZE = sizeof(PUB_KEY_BLOB) / sizeof(BYTE);

        ASSERT_EQ(148, publicKey.size());
        for (UINT i = 0; i < publicKey.size(); ++i)
            ASSERT_EQ(PUB_KEY_BLOB[PUB_KEY_BLOB_SIZE - publicKey.size() + i], publicKey[i]);
    }

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, StrongNaming_Test_02)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        shared_ptr<HostInfo const> pHostInfo = HostInfo::NewHost();
        shared_ptr<RuntimeHost const> pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");

        shared_ptr<StrongNameInfo const> pSnInfo = pRuntimeHost->Map<StrongNameInfo>();
        
        shared_ptr<StrongNameKey const> pSnKey;
        pSnKey = pSnInfo->GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        std::vector<BYTE> const &publicKeyToken = pSnKey->GetPublicKeyToken();

        BYTE const PUB_KEY_TOKEN[] = { 0xf3, 0xc5, 0xad, 0xb8, 0x52, 0x21, 0xac, 0x4f };

        ASSERT_EQ(8, publicKeyToken.size());
        for (UINT i = 0; i < publicKeyToken.size(); ++i)
            ASSERT_EQ(PUB_KEY_TOKEN[i], publicKeyToken[i]);
    }
#endif

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, Test_01)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Utilities;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        //::_CrtSetBreakAlloc(5787);

        //typedef HostInfo HostInfo;
        //typedef RuntimeHost RuntimeHost;
        //typedef MetadataInfo MetadataInfo;
        //typedef MetadataDispenser MetadataDispenser;
        //typedef AssemblyMetadata AssemblyMetadata;
        //typedef ModuleMetadata ModuleMetadata;
        //typedef ITypeMetadata ITypeMetadata;
        //typedef TypeMetadata TypeMetadata;
        //typedef MethodMetadata MethodMetadata;
        typedef AssemblyMetadataGenerator7FAEDE99 AssemblyMetadataGenerator;
        typedef ModuleMetadataGenerator7FAEDE99 ModuleMetadataGenerator;
        typedef TypeMetadataGenerator7FAEDE99 TypeMetadataGenerator;
        typedef FieldMetadataGenerator7FAEDE99 FieldMetadataGenerator;
        typedef MethodMetadataGenerator7FAEDE99 MethodMetadataGenerator;
        typedef PropertyMetadataGenerator7FAEDE99 PropertyMetadataGenerator;

        HostInfo const *pHostInfo = HostInfo::CreateHost();

        RuntimeHost const *pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost != NULL);

        MetadataInfo const *pMetaInfo = pRuntimeHost->Map<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo != NULL);

        MetadataDispenser *pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaDisp != NULL);

        AssemblyMetadata const *pSystemCore = NULL;
        pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                             L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());
        
        AssemblyMetadata const *pMSCorLib = NULL;
        pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                           L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        ModuleMetadata const *pSystemCoreModule = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_EQ(0x00000001, pSystemCoreModule->GetToken());
        
        ModuleMetadata const *pMSCorLibModule = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        TypeMetadata const *pVoid = pMSCorLibModule->GetType(L"System.Void");
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        TypeMetadata const *pObject = pMSCorLibModule->GetType(L"System.Object");
        ASSERT_EQ(0x02000002, pObject->GetToken());

        TypeMetadata const *pIntPtr = pMSCorLibModule->GetType(L"System.IntPtr");
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        TypeMetadata const *pDateTime = pMSCorLibModule->GetType(L"System.DateTime");
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        TypeMetadata const *pFunc1 = pSystemCoreModule->GetType(L"System.Func`1");
        ASSERT_TRUE(pFunc1->IsGenericType());
        ASSERT_TRUE(pFunc1->IsGenericTypeDefinition());
        {
            TempPtrVector<ITypeMetadata const> const &genericArgs = pFunc1->GetGenericArguments();  // うーん・・・静的オブジェクトの初期化順序実装依存だって忘れてた・・・もう一回！
#if 0
            ASSERT_EQ(1, genericArgs.size());
            for (UINT i = 0; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_TRUE(genericArgs[i]->IsGenericParameter());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
#endif
        }
        ASSERT_EQ(0x02000058, pFunc1->GetToken());

#if 0
        shared_ptr<TypeMetadata const> pFunc1DateTime;
        {
            std::vector<shared_ptr<ITypeMetadata const> > genericArgs;
            genericArgs.push_back(pDateTime);
            pFunc1DateTime = pFunc1->MakeGenericType(genericArgs);
        }
        ASSERT_TRUE(pFunc1DateTime->IsGenericType());
        ASSERT_FALSE(pFunc1DateTime->IsGenericTypeDefinition());
        {
            std::vector<shared_ptr<ITypeMetadata const> > const &genericArgs = pFunc1DateTime->GetGenericArguments();
            ASSERT_EQ(1, genericArgs.size());
            for (UINT i = 0; i < genericArgs.size(); ++i)
            {
                switch (i)
                {
                    case 0:
                        ASSERT_FALSE(genericArgs[i]->IsGenericParameter());
                        break;
                    default:
                        FAIL() << "We shouldn't get here!!";
                }
            }
        }
        ASSERT_EQ(0x02000058, pFunc1DateTime->GetToken());   // !! CAUTION: This is CORRECT !!

        shared_ptr<MethodMetadata const> pFunc1DateTimector;
        {
            std::vector<shared_ptr<ITypeMetadata const> > params;
            params.push_back(pObject);
            params.push_back(pIntPtr);
            pFunc1DateTimector = pFunc1DateTime->GetMethod(L".ctor", CallingConventions::CC_HAS_THIS, pVoid, params);
        }
        ASSERT_EQ(0x06000232, pFunc1DateTimector->GetToken());   // !! CAUTION: This is CORRECT !!

        shared_ptr<MethodMetadata const> pget_UtcNow;
        {
            std::vector<shared_ptr<ITypeMetadata const> > params;
            pget_UtcNow = pDateTime->GetMethod(L"get_UtcNow", CallingConventions::CC_STANDARD, pDateTime, params);
        }
        ASSERT_EQ(0x060002D3, pget_UtcNow->GetToken());

        shared_ptr<MethodMetadata const> pToLocalTime;
        {
            std::vector<shared_ptr<ITypeMetadata const> > params;
            pToLocalTime = pDateTime->GetMethod(L"ToLocalTime", CallingConventions::CC_HAS_THIS, pDateTime, params);
        }
        ASSERT_EQ(0x060002E7, pToLocalTime->GetToken());




        shared_ptr<StrongNameInfo const> pSnInfo = pRuntimeHost->Map<StrongNameInfo>();

        shared_ptr<AssemblyMetadataGenerator> pMSCorLibPrigGen;
        pMSCorLibPrigGen = pMetaDisp->DefineAssembly(L"mscorlib.Prig");
        shared_ptr<StrongNameKey const> pSnKey;
        pSnKey = pSnInfo->GetStrongNameKey(L"..\\Test.prig\\mscorlib.Prig.snk");
        pMSCorLibPrigGen->SetStrongNameKey(pSnKey);
        ASSERT_STREQ(L"mscorlib.Prig", pMSCorLibPrigGen->GetName().c_str());
        ASSERT_TRUE(pMSCorLibPrigGen->GetStrongNameKey());

        shared_ptr<ModuleMetadataGenerator> pMSCorLibPrigModGen;
        pMSCorLibPrigModGen = pMSCorLibPrigGen->DefineModule(L"mscorlib.Prig.dll");
        ASSERT_STREQ(L"mscorlib.Prig.dll", pMSCorLibPrigModGen->GetName().c_str());

        shared_ptr<TypeMetadataGenerator> pPDateTimeGen;
        pPDateTimeGen = pMSCorLibPrigModGen->DefineType(L"System.Prig.PDateTime",
                                                        TypeAttributes::TA_PUBLIC | 
                                                        TypeAttributes::TA_ABSTRACT | 
                                                        TypeAttributes::TA_ANSI_CLASS | 
                                                        TypeAttributes::TA_SEALED | 
                                                        TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_STREQ(L"System.Prig.PDateTime", pPDateTimeGen->GetName().c_str());
        ASSERT_TRUE((pPDateTimeGen->GetAttribute().Value() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_FALSE((pPDateTimeGen->GetAttribute().Value() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);

        shared_ptr<TypeMetadataGenerator> pNowGetGen;
        pNowGetGen = pPDateTimeGen->DefineNestedType(L"NowGet", 
                                                     TypeAttributes::TA_ABSTRACT | 
                                                     TypeAttributes::TA_ANSI_CLASS | 
                                                     TypeAttributes::TA_SEALED | 
                                                     TypeAttributes::TA_NESTED_PUBLIC | 
                                                     TypeAttributes::TA_BEFORE_FIELD_INIT);
        ASSERT_STREQ(L"NowGet", pNowGetGen->GetName().c_str());
        ASSERT_TRUE((pNowGetGen->GetAttribute().Value() & TypeAttributes::TA_ANSI_CLASS) == TypeAttributes::TA_ANSI_CLASS);
        ASSERT_TRUE((pNowGetGen->GetAttribute().Value() & TypeAttributes::TA_NESTED_PUBLIC) == TypeAttributes::TA_NESTED_PUBLIC);
        
        shared_ptr<FieldMetadataGenerator> pm_bodyGen;
        pm_bodyGen = pPDateTimeGen->DefineField(L"m_body", 
                                                pFunc1DateTime, 
                                                FieldAttributes::FA_PRIVATE | 
                                                FieldAttributes::FA_STATIC);
        ASSERT_STREQ(L"m_body", pm_bodyGen->GetName().c_str());
        ASSERT_TRUE((pm_bodyGen->GetAttribute().Value() & FieldAttributes::FA_PRIVATE) == FieldAttributes::FA_PRIVATE);
        ASSERT_FALSE((pm_bodyGen->GetAttribute().Value() & FieldAttributes::FA_PUBLIC) == FieldAttributes::FA_PUBLIC);

        shared_ptr<MethodMetadataGenerator> pget_BodyGen;
        pget_BodyGen = pPDateTimeGen->DefineMethod(L"get_Body", 
                                                   CallingConventions::CC_STANDARD, 
                                                   pFunc1DateTime, 
                                                   std::vector<shared_ptr<ITypeMetadata const> >(), 
                                                   MethodAttributes::MA_PUBLIC | 
                                                   MethodAttributes::MA_HIDE_BY_SIG | 
                                                   MethodAttributes::MA_SPECIAL_NAME | 
                                                   MethodAttributes::MA_STATIC);
        ASSERT_STREQ(L"get_Body", pget_BodyGen->GetName().c_str());
        ASSERT_EQ(CallingConventions::CC_STANDARD, pget_BodyGen->GetCallingConvention().Value());
        ASSERT_TRUE(pget_BodyGen->GetReturnType() == pFunc1DateTime);
        ASSERT_EQ(0, pget_BodyGen->GetParameterTypes().size());
        ASSERT_TRUE((pget_BodyGen->GetAttribute().Value() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pget_BodyGen->GetAttribute().Value() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        std::vector<shared_ptr<ITypeMetadata const> > set_BodyParams;
        set_BodyParams.push_back(pFunc1DateTime);
        shared_ptr<MethodMetadataGenerator> pset_BodyGen;
        pset_BodyGen = pPDateTimeGen->DefineMethod(L"set_Body",
                                                   CallingConventions::CC_STANDARD, 
                                                   pVoid, 
                                                   set_BodyParams, 
                                                   MethodAttributes::MA_PUBLIC | 
                                                   MethodAttributes::MA_HIDE_BY_SIG | 
                                                   MethodAttributes::MA_SPECIAL_NAME | 
                                                   MethodAttributes::MA_STATIC);
        ASSERT_STREQ(L"set_Body", pset_BodyGen->GetName().c_str());
        ASSERT_EQ(CallingConventions::CC_STANDARD, pset_BodyGen->GetCallingConvention().Value());
        ASSERT_TRUE(pset_BodyGen->GetReturnType() == pVoid);
        ASSERT_EQ(1, pset_BodyGen->GetParameterTypes().size());
        ASSERT_TRUE((pset_BodyGen->GetAttribute().Value() & MethodAttributes::MA_PUBLIC) == MethodAttributes::MA_PUBLIC);
        ASSERT_FALSE((pset_BodyGen->GetAttribute().Value() & MethodAttributes::MA_PRIVATE) == MethodAttributes::MA_PRIVATE);

        shared_ptr<PropertyMetadataGenerator> pBodyGen;
        pBodyGen = pPDateTimeGen->DefineProperty(L"Body", 
                                                 pFunc1DateTime, 
                                                 std::vector<shared_ptr<ITypeMetadata const> >(), 
                                                 PropertyAttributes::PA_NONE);
        pBodyGen->SetGetMethod(pget_BodyGen);
        pBodyGen->SetSetMethod(pset_BodyGen);
        ASSERT_STREQ(L"Body", pBodyGen->GetName().c_str());
        ASSERT_TRUE(pBodyGen->GetPropertyType() == pFunc1DateTime);
        ASSERT_EQ(0, pBodyGen->GetParameterTypes().size());
        ASSERT_TRUE((pBodyGen->GetAttribute().Value() & PropertyAttributes::PA_NONE) == PropertyAttributes::PA_NONE);
        ASSERT_FALSE((pBodyGen->GetAttribute().Value() & PropertyAttributes::PA_SPECIAL_NAME) == PropertyAttributes::PA_SPECIAL_NAME);
        ASSERT_TRUE(pBodyGen->GetGetMethod() == pget_BodyGen);
        ASSERT_TRUE(pBodyGen->GetSetMethod() == pset_BodyGen);

#endif
    }


}
