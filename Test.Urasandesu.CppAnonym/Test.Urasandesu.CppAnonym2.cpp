// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

// foward declarations
namespace Urasandesu { namespace CppAnonym {

    struct SmartPtrChainMapper;

    
    
    
    
    struct SmartPtrChainConstructor;





    template<
        class Previous, 
        class Mapper = SmartPtrChainMapper,
        class Constructor = SmartPtrChainConstructor
    >
    struct SmartPtrChainInfo;
    
    
    
    
    
    namespace Detail {
        
        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProvider5B4288A9Impl;

    }   // namespace Detail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider5B4288A9;





    namespace Detail {
        
        template<class Sequence, class I, class IEnd>
        class SmartHeapProviderImpl;

    }   // namespace Detail


    template<class Sequence>
    class SmartHeapProvider;

    
    
    
    
    namespace Detail {
        
        template<class Sequence, class I, class IEnd>
        class DisposableHeapProviderImpl;

    }   // namespace Detail


    template<class Sequence>
    class DisposableHeapProvider;

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    struct NullDeleter;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

    struct HostInfo5B4288A9ApiHolderLabel { };
    struct HostInfo5B4288A9Label { };

    struct RuntimeHost5B4288A9ApiHolderLabel { };
    struct RuntimeHost5B4288A9Label { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    struct DefaultHostInfo5B4288A9ApiHolder;

    struct DefaultRuntimeHost5B4288A9ApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfo5B4288A9ApiHolder = ApiHolders::DefaultHostInfo5B4288A9ApiHolder
    >    
    class BaseHostInfo5B4288A9;

    typedef BaseHostInfo5B4288A9<> HostInfo5B4288A9;





    template<
        class RuntimeHost5B4288A9ApiHolder = ApiHolders::DefaultRuntimeHost5B4288A9ApiHolder
    >    
    class BaseRuntimeHost5B4288A9;

    typedef BaseRuntimeHost5B4288A9<> RuntimeHost5B4288A9;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

    struct StrongNameInfo5B4288A9ApiHolderLabel { };
    struct StrongNameInfo5B4288A9Label { };

    struct StrongNameKey5B4288A9ApiHolderLabel { };
    struct StrongNameKey5B4288A9Label { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

    struct DefaultStrongNameInfo5B4288A9ApiHolder;

    struct DefaultStrongNameKey5B4288A9ApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<
        class StrongNameInfo5B4288A9ApiHolder = ApiHolders::DefaultStrongNameInfo5B4288A9ApiHolder
    >    
    class BaseStrongNameInfo5B4288A9;

    typedef BaseStrongNameInfo5B4288A9<> StrongNameInfo5B4288A9;





    template<
        class StrongNameKey5B4288A9ApiHolder = ApiHolders::DefaultStrongNameKey5B4288A9ApiHolder
    >    
    class BaseStrongNameKey5B4288A9;

    typedef BaseStrongNameKey5B4288A9<> StrongNameKey5B4288A9;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

    struct IAssemblyMetadata5B4288A9ApiHolderLabel { };
    struct IAssemblyMetadata5B4288A9Label { };
    struct IAssemblyMetadata5B4288A9HashLabel { };
    struct IAssemblyMetadata5B4288A9EqualToLabel { };

    struct IModuleMetadata5B4288A9ApiHolderLabel { };
    struct IModuleMetadata5B4288A9Label { };
    struct IModuleMetadata5B4288A9HashLabel { };
    struct IModuleMetadata5B4288A9EqualToLabel { };

    struct ITypeMetadata5B4288A9ApiHolderLabel { };
    struct ITypeMetadata5B4288A9Label { };
    struct ITypeMetadata5B4288A9HashLabel { };
    struct ITypeMetadata5B4288A9EqualToLabel { };

    struct IMethodMetadata5B4288A9ApiHolderLabel { };
    struct IMethodMetadata5B4288A9Label { };
    struct IMethodMetadata5B4288A9HashLabel { };
    struct IMethodMetadata5B4288A9EqualToLabel { };

    struct MetadataInfo5B4288A9ApiHolderLabel { };
    struct MetadataInfo5B4288A9Label { };

    struct MetadataDispenser5B4288A9ApiHolderLabel { };
    struct MetadataDispenser5B4288A9Label { };

    struct AssemblyMetadata5B4288A9ApiHolderLabel { };
    struct AssemblyMetadata5B4288A9Label { };

    struct ModuleMetadata5B4288A9ApiHolderLabel { };
    struct ModuleMetadata5B4288A9Label { };

    struct TypeMetadata5B4288A9ApiHolderLabel { };
    struct TypeMetadata5B4288A9Label { };

    struct MethodMetadata5B4288A9ApiHolderLabel { };
    struct MethodMetadata5B4288A9Label { };

    struct MetadataSpecialValues
    {
        static std::wstring const TYPE_NAME_OF_VOID;
        static std::wstring const TYPE_NAME_OF_BOOLEAN;
        static std::wstring const TYPE_NAME_OF_CHAR;
        static std::wstring const TYPE_NAME_OF_SBYTE;
        static std::wstring const TYPE_NAME_OF_BYTE;
        static std::wstring const TYPE_NAME_OF_INT16;
        static std::wstring const TYPE_NAME_OF_UINT16;
        static std::wstring const TYPE_NAME_OF_INT32;
        static std::wstring const TYPE_NAME_OF_UINT32;
        static std::wstring const TYPE_NAME_OF_INT64;
        static std::wstring const TYPE_NAME_OF_UINT64;
        static std::wstring const TYPE_NAME_OF_SINGLE;
        static std::wstring const TYPE_NAME_OF_DOUBLE;
        static std::wstring const TYPE_NAME_OF_STRING;
        static std::wstring const TYPE_NAME_OF_INTPTR;
        static std::wstring const TYPE_NAME_OF_OBJECT;
        static std::wstring const TYPE_NAME_OF_VALUETYPE;
        static std::wstring const GENERIC_TYPE_IDENTIFIER;
    };

    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_VOID = L"System.Void";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_BOOLEAN = L"System.Boolean";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_CHAR = L"System.Char";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_SBYTE = L"System.SByte";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_BYTE = L"System.Byte";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT16 = L"System.Int16";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT16 = L"System.UInt16";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT32 = L"System.Int32";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT32 = L"System.UInt32";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INT64 = L"System.Int64";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_UINT64 = L"System.UInt64";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_SINGLE = L"System.Single";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_DOUBLE = L"System.Double";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_STRING = L"System.String";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_INTPTR = L"System.IntPtr";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_OBJECT = L"System.Object";
    std::wstring const MetadataSpecialValues::TYPE_NAME_OF_VALUETYPE = L"System.ValueType";
    std::wstring const MetadataSpecialValues::GENERIC_TYPE_IDENTIFIER = L"`";

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    struct DefaultIAssemblyMetadata5B4288A9ApiHolder;

    struct DefaultIModuleMetadata5B4288A9ApiHolder;

    struct DefaultITypeMetadata5B4288A9ApiHolder;

    struct DefaultIMethodMetadata5B4288A9ApiHolder;

    struct DefaultMetadataInfo5B4288A9ApiHolder;

    struct DefaultMetadataDispenser5B4288A9ApiHolder;

    struct DefaultAssemblyMetadata5B4288A9ApiHolder;

    struct DefaultModuleMetadata5B4288A9ApiHolder;

    struct DefaultTypeMetadata5B4288A9ApiHolder;

    struct DefaultMethodMetadata5B4288A9ApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class IAssemblyMetadata5B4288A9ApiHolder = ApiHolders::DefaultIAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseIAssemblyMetadata5B4288A9;

    typedef BaseIAssemblyMetadata5B4288A9<> IAssemblyMetadata5B4288A9;




    
    template<
        class IAssemblyMetadata5B4288A9ApiHolder = ApiHolders::DefaultIAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseIAssemblyMetadata5B4288A9Hash;

    typedef BaseIAssemblyMetadata5B4288A9Hash<> IAssemblyMetadata5B4288A9Hash;

    
    
    
    
    template<
        class IAssemblyMetadata5B4288A9ApiHolder = ApiHolders::DefaultIAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseIAssemblyMetadata5B4288A9EqualTo;

    typedef BaseIAssemblyMetadata5B4288A9EqualTo<> IAssemblyMetadata5B4288A9EqualTo;





    template<
        class IModuleMetadata5B4288A9ApiHolder = ApiHolders::DefaultIModuleMetadata5B4288A9ApiHolder
    >    
    class BaseIModuleMetadata5B4288A9;

    typedef BaseIModuleMetadata5B4288A9<> IModuleMetadata5B4288A9;




    
    template<
        class IModuleMetadata5B4288A9ApiHolder = ApiHolders::DefaultIModuleMetadata5B4288A9ApiHolder
    >    
    class BaseIModuleMetadata5B4288A9Hash;

    typedef BaseIModuleMetadata5B4288A9Hash<> IModuleMetadata5B4288A9Hash;

    
    
    
    
    template<
        class IModuleMetadata5B4288A9ApiHolder = ApiHolders::DefaultIModuleMetadata5B4288A9ApiHolder
    >    
    class BaseIModuleMetadata5B4288A9EqualTo;

    typedef BaseIModuleMetadata5B4288A9EqualTo<> IModuleMetadata5B4288A9EqualTo;





    template<
        class ITypeMetadata5B4288A9ApiHolder = ApiHolders::DefaultITypeMetadata5B4288A9ApiHolder
    >    
    class BaseITypeMetadata5B4288A9;

    typedef BaseITypeMetadata5B4288A9<> ITypeMetadata5B4288A9;




    
    template<
        class ITypeMetadata5B4288A9ApiHolder = ApiHolders::DefaultITypeMetadata5B4288A9ApiHolder
    >    
    class BaseITypeMetadata5B4288A9Hash;

    typedef BaseITypeMetadata5B4288A9Hash<> ITypeMetadata5B4288A9Hash;

    
    
    
    
    template<
        class ITypeMetadata5B4288A9ApiHolder = ApiHolders::DefaultITypeMetadata5B4288A9ApiHolder
    >    
    class BaseITypeMetadata5B4288A9EqualTo;

    typedef BaseITypeMetadata5B4288A9EqualTo<> ITypeMetadata5B4288A9EqualTo;





    template<
        class IMethodMetadata5B4288A9ApiHolder = ApiHolders::DefaultIMethodMetadata5B4288A9ApiHolder
    >    
    class BaseIMethodMetadata5B4288A9;

    typedef BaseIMethodMetadata5B4288A9<> IMethodMetadata5B4288A9;




    
    template<
        class IMethodMetadata5B4288A9ApiHolder = ApiHolders::DefaultIMethodMetadata5B4288A9ApiHolder
    >    
    class BaseIMethodMetadata5B4288A9Hash;

    typedef BaseIMethodMetadata5B4288A9Hash<> IMethodMetadata5B4288A9Hash;

    
    
    
    
    template<
        class IMethodMetadata5B4288A9ApiHolder = ApiHolders::DefaultIMethodMetadata5B4288A9ApiHolder
    >    
    class BaseIMethodMetadata5B4288A9EqualTo;

    typedef BaseIMethodMetadata5B4288A9EqualTo<> IMethodMetadata5B4288A9EqualTo;

    
    
    
    
    template<
        class MetadataInfo5B4288A9ApiHolder = ApiHolders::DefaultMetadataInfo5B4288A9ApiHolder
    >    
    class BaseMetadataInfo5B4288A9;

    typedef BaseMetadataInfo5B4288A9<> MetadataInfo5B4288A9;





    template<
        class MetadataDispenser5B4288A9ApiHolder = ApiHolders::DefaultMetadataDispenser5B4288A9ApiHolder
    >    
    class BaseMetadataDispenser5B4288A9;

    typedef BaseMetadataDispenser5B4288A9<> MetadataDispenser5B4288A9;





    template<
        class AssemblyMetadata5B4288A9ApiHolder = ApiHolders::DefaultAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseAssemblyMetadata5B4288A9;

    typedef BaseAssemblyMetadata5B4288A9<> AssemblyMetadata5B4288A9;





    template<
        class ModuleMetadata5B4288A9ApiHolder = ApiHolders::DefaultModuleMetadata5B4288A9ApiHolder
    >    
    class BaseModuleMetadata5B4288A9;

    typedef BaseModuleMetadata5B4288A9<> ModuleMetadata5B4288A9;





    template<
        class TypeMetadata5B4288A9ApiHolder = ApiHolders::DefaultTypeMetadata5B4288A9ApiHolder
    >    
    class BaseTypeMetadata5B4288A9;

    typedef BaseTypeMetadata5B4288A9<> TypeMetadata5B4288A9;





    template<
        class MethodMetadata5B4288A9ApiHolder = ApiHolders::DefaultMethodMetadata5B4288A9ApiHolder
    >    
    class BaseMethodMetadata5B4288A9;

    typedef BaseMethodMetadata5B4288A9<> MethodMetadata5B4288A9;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

    struct FusionInfo5B4288A9ApiHolderLabel { };
    struct FusionInfo5B4288A9Label { };

    struct AssemblyInfo5B4288A9ApiHolderLabel { };
    struct AssemblyInfo5B4288A9Label { };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace Interfaces {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

    struct DefaultFusionInfo5B4288A9ApiHolder;

    struct DefaultAssemblyInfo5B4288A9ApiHolder;

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<
        class FusionInfo5B4288A9ApiHolder = ApiHolders::DefaultFusionInfo5B4288A9ApiHolder
    >    
    class BaseFusionInfo5B4288A9;

    typedef BaseFusionInfo5B4288A9<> FusionInfo5B4288A9;





    template<
        class AssemblyInfo5B4288A9ApiHolder = ApiHolders::DefaultAssemblyInfo5B4288A9ApiHolder
    >    
    class BaseAssemblyInfo5B4288A9;

    typedef BaseAssemblyInfo5B4288A9<> AssemblyInfo5B4288A9;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {





namespace Urasandesu { namespace CppAnonym {

    struct CppAnonymObjectDisposedException : CppAnonymException
    {
        CppAnonymObjectDisposedException();
        CppAnonymObjectDisposedException(std::string const &what);
        CppAnonymObjectDisposedException(std::wstring const &what);
        CppAnonymObjectDisposedException(std::string const &what, CppAnonymException &innerException);
        CppAnonymObjectDisposedException(std::wstring const &what, CppAnonymException &innerException);
    };

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException() : 
        CppAnonymException()
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::string const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::wstring const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }

    CppAnonymObjectDisposedException::CppAnonymObjectDisposedException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }





    struct CppAnonymInvalidOperationException : CppAnonymException
    {
        CppAnonymInvalidOperationException();
        CppAnonymInvalidOperationException(std::string const &what);
        CppAnonymInvalidOperationException(std::wstring const &what);
        CppAnonymInvalidOperationException(std::string const &what, CppAnonymException &innerException);
        CppAnonymInvalidOperationException(std::wstring const &what, CppAnonymException &innerException);
    };

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException() : 
        CppAnonymException()
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::string const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::wstring const &what) : 
        CppAnonymException(what)
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::string const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }

    CppAnonymInvalidOperationException::CppAnonymInvalidOperationException(std::wstring const &what, CppAnonymException &innerException) : 
        CppAnonymException(what, innerException)
    { }





    struct SignatureUtil
    {
        template<class SignatureHolder>
        static void PutSignatures(SimpleBlob &sb, SignatureHolder const &sigHolder)
        {
            typedef std::vector<COR_SIGNATURE>::const_iterator Iterator;
            std::vector<COR_SIGNATURE> const &sigs = sigHolder.GetSignatures();
            for (Iterator i = sigs.cbegin(), i_end = sigs.cend(); i != i_end; ++i)
                sb.Put<COR_SIGNATURE>(*i);
        }
    };





    class ATL_NO_VTABLE SimpleDisposable
    {
    public:
        void Dispose() { m_disposed = true; }
        bool Disposed() const { return m_disposed; }
        void CheckDisposed() const 
        {
            if (m_disposed)
                BOOST_THROW_EXCEPTION(CppAnonymObjectDisposedException());
        }
    protected:
        SimpleDisposable() : 
            m_disposed(false)
        { }
    
    private:
        bool m_disposed;
    };




    struct SmartPtrChainMapper
    {
        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapFirstAncestor(Current const &current) 
        { 
            boost::shared_ptr<Previous> pPrevious;
            pPrevious = current.ChainFrom<Previous>().GetPrevious().lock();
            return pPrevious ? pPrevious->MapFirst<T>() : boost::shared_ptr<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapAncestor(Current const &current) 
        { 
            boost::shared_ptr<Previous> pPrevious;
            pPrevious = current.ChainFrom<Previous>().GetPrevious().lock();
            return pPrevious ? pPrevious->Map<T>() : boost::shared_ptr<T>();
        }

        template<
            class Current
        >
        static boost::shared_ptr<Current> MapFirst(Current const &current) 
        { 
            boost::shared_ptr<Current> pCurrent;
            pCurrent = current.GetCurrent().lock();
            return pCurrent;
        }

        template<
            class Current
        >
        static boost::shared_ptr<Current> Map(Current const &current) 
        { 
            boost::shared_ptr<Current> pCurrent;
            pCurrent = current.GetCurrent().lock();
            return pCurrent;
        }
    };

    
    
    
    
    struct SmartPtrChainConstructor
    {
        template<
            class T,
            class HeapProvider
        >
        static boost::shared_ptr<T> NewRootObject()
        {
            boost::shared_ptr<T> pObj = HeapProvider::NewStaticObject();
            pObj->SetCurrent(pObj);
            return pObj;
        }

        template<
            class T,
            class Current,
            class HeapProvider
        >
        static boost::shared_ptr<T> NewObject(Current const &current, HeapProvider &provider)
        {
            typedef typename Current::current_type previous_type;
            boost::shared_ptr<T> pObj = provider.NewObject();
            pObj->ChainFrom<previous_type>().SetPrevious(current.GetCurrent());
            pObj->ChainFrom<previous_type>().SetCurrent(pObj);
            return pObj;
        }
    };





    template<
        class Previous, 
        class Mapper,
        class Constructor
    >
    struct SmartPtrChainInfo
    {
        typedef Previous previous_type;
        typedef Mapper mapper_type;
        typedef Constructor constructor_type;
    };





    namespace Detail {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Current, class ChainInfoSequence, class I, class IEnd>
        class ATL_NO_VTABLE SmartPtrChainImpl : 
            public SmartPtrChainImpl<Current, ChainInfoSequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SmartPtrChainImpl<Current, ChainInfoSequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type chain_info_type;
            typedef typename Current current_type;
            typedef typename chain_info_type::previous_type previous_type;
            typedef typename chain_info_type::mapper_type mapper_type;
            typedef typename chain_info_type::constructor_type constructor_type;

            template<class T>
            boost::shared_ptr<T> MapFirstAncestor() const
            {
                return mapper_type::MapFirstAncestor<T, previous_type>(static_cast<current_type const &>(*this)); 
            }

            template<class T>
            boost::shared_ptr<T> MapFirst() const
            {
                return mapper_type::MapFirstAncestor<T, previous_type>(static_cast<current_type const &>(*this)); 
            }

            template<>
            boost::shared_ptr<current_type> MapFirst<current_type>() const
            { 
                return mapper_type::MapFirst<current_type>(static_cast<current_type const &>(*this));
            }

            template<class T>
            boost::shared_ptr<T> Map() const
            {
                return mapper_type::MapAncestor<T, previous_type>(static_cast<current_type const &>(*this)); 
            }

            template<>
            boost::shared_ptr<current_type> Map<current_type>() const
            { 
                return mapper_type::Map<current_type>(static_cast<current_type const &>(*this));
            }

            template<
                class T,
                class HeapProvider
            >
            static boost::shared_ptr<T> NewRootObject()
            {
                return constructor_type::NewRootObject<T, HeapProvider>();
            }

            template<
                class T,
                class HeapProvider
            >
            boost::shared_ptr<T> NewObject(HeapProvider &provider) const
            {
                return constructor_type::NewObject<T>(static_cast<current_type const &>(*this), provider);
            }
            
            boost::weak_ptr<previous_type> GetPrevious() const
            {
                return m_pPrevious;
            }

            void SetPrevious(boost::weak_ptr<previous_type> const &pPrevious)
            {
                _ASSERTE(m_pPrevious.expired());
                m_pPrevious = pPrevious;
            }

        private:
            boost::weak_ptr<previous_type> m_pPrevious;
        };

        template<class Current, class ChainInfoSequence>
        class ATL_NO_VTABLE SmartPtrChainImpl<Current, 
                                              ChainInfoSequence, 
                                              typename Traits::DistinctEnd<ChainInfoSequence>::type, 
                                              typename Traits::DistinctEnd<ChainInfoSequence>::type> : 
            noncopyable
        {
        public:
            typedef typename Current current_type;
            
            boost::weak_ptr<current_type> GetCurrent() const
            {
                return m_pCurrent;
            }

            void SetCurrent(boost::weak_ptr<current_type> const &pCurrent)
            {
                _ASSERTE(m_pCurrent.expired());
                m_pCurrent = pCurrent;
            }

        private:
            boost::weak_ptr<current_type> m_pCurrent;
        };

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(ChainInfo, previous_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(ChainInfo, previous_type);

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type);

        template<class Last, class Current>
        struct FlattenChainInfoImpl
        {
            typedef typename mpl::eval_if<
                                CPP_ANONYM_HAS_MEMBER_TYPE(ChainInfo, previous_type, Current),
                                CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, Current),
                                mpl::identity<Current> >::type current_type;

            typedef typename mpl::eval_if<
                                mpl::and_<
                                    CPP_ANONYM_HAS_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type, current_type),
                                    mpl::not_<boost::is_same<Last, current_type> >
                                >,
                                CPP_ANONYM_GET_MEMBER_TYPE(SmartPtrChain, chain_info_sequence_type, current_type),
                                mpl::identity<mpl::vector<current_type> > >::type chain_info_sequence_type;

            typedef typename mpl::eval_if<
                                boost::is_same<chain_info_sequence_type, mpl::vector<current_type> >, 
                                chain_info_sequence_type,
                                mpl::fold<
                                    chain_info_sequence_type, 
                                    mpl::vector<current_type>,
                                    mpl::copy<
                                        FlattenChainInfoImpl<current_type, mpl::_2>, 
                                        mpl::back_inserter<mpl::_1> > > >::type type; 
        };

        template<class T>
        struct FlattenChainInfo : 
            FlattenChainInfoImpl<mpl::void_, T>
        {
        };

        template<class Current, class T>
        class IsMappable
        {
        private:
            typedef Current current;
            typedef typename FlattenChainInfo<current>::type all_mappable_types;
            typedef typename mpl::find<all_mappable_types, T>::type i;
            typedef typename mpl::end<all_mappable_types>::type i_end;

        public:
            typedef typename mpl::not_<boost::is_same<i, i_end> > type;
        };

    }   // namespace Detail


    template<class Current, class ChainInfoSequence>
    class ATL_NO_VTABLE SmartPtrChain : 
        public Detail::SmartPtrChainImpl<Current, 
                                         ChainInfoSequence, 
                                         typename Traits::DistinctBegin<ChainInfoSequence>::type, 
                                         typename Traits::DistinctEnd<ChainInfoSequence>::type>
    {
    public:
        typedef SmartPtrChain<Current, ChainInfoSequence> this_type;
        typedef ChainInfoSequence chain_info_sequence_type;

        template<class Previous>
        struct chain_from
        {
            typedef Detail::SmartPtrChainImpl<
                Current,
                chain_info_sequence_type,
                typename boost::mpl::find_if<
                    typename Traits::Distinct<chain_info_sequence_type>::type,
                    boost::is_same<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, boost::mpl::_1), Previous>
                >::type,
                typename Traits::DistinctEnd<chain_info_sequence_type>::type
            > type;
        };

        template<class Previous>
        inline typename chain_from<Previous>::type &ChainFrom() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename chain_from<Previous>::type &>(*pMutableThis);
        }

        template<class T>
        boost::shared_ptr<T> MapFirstAncestor() const
        {
            namespace mpl = boost::mpl;

            typedef mpl::filter_view<chain_info_sequence_type, Detail::IsMappable<mpl::_, T> >::type MappableTypes;
            
            container<T> container;
            map_first_ancestor_selector<T> selector(*this, container);
            mpl::for_each<MappableTypes, wrap<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, mpl::_) > >(selector);
            return container.m_p;
        }

        template<class T>
        boost::shared_ptr<T> MapFirst() const
        {
            namespace mpl = boost::mpl;

            typedef mpl::filter_view<chain_info_sequence_type, Detail::IsMappable<mpl::_, T> >::type MappableTypes;
            
            container<T> container;
            map_first_selector<T> selector(*this, container);
            mpl::for_each<MappableTypes, wrap<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, mpl::_) > >(selector);
            return container.m_p;
        }

        template<>
        boost::shared_ptr<Current> MapFirst<Current>() const
        {
            return Map<Current>();
        }

        template<
            class T,
            class HeapProvider
        >
        boost::shared_ptr<T> NewObjectFirst(HeapProvider &provider) const
        {
            namespace mpl = boost::mpl;

            container<T> container;
            new_object_first_selector<T, HeapProvider> selector(*this, provider, container);
            mpl::for_each<chain_info_sequence_type, wrap<Detail::CPP_ANONYM_GET_MEMBER_TYPE(ChainInfo, previous_type, mpl::_) > >(selector);
            _ASSERTE(container.m_p);
            return container.m_p;
        }

    private:
        template<class T>
        struct wrap
        {
        };

        template<class T>
        struct container
        {
            boost::shared_ptr<T> m_p;
        };

        template<class T>
        struct map_first_ancestor_selector
        {
            map_first_ancestor_selector(this_type const &this_, container<T> &container) : 
                m_pThis(&this_),
                m_pContainer(&container)
            { }

            template<class Previous>
            void operator()(wrap<Previous> const &)
            {
                if (!m_pContainer->m_p)
                {
                    typedef typename chain_from<Previous>::type PreviousChain;
                    PreviousChain &chain = m_pThis->ChainFrom<Previous>();
                    m_pContainer->m_p = chain.MapFirstAncestor<T>();
                }
            }

            this_type const *m_pThis;
            container<T> *m_pContainer;
        };

        template<class T>
        struct map_first_selector
        {
            map_first_selector(this_type const &this_, container<T> &container) : 
                m_pThis(&this_),
                m_pContainer(&container)
            { }

            template<class Previous>
            void operator()(wrap<Previous> const &)
            {
                if (!m_pContainer->m_p)
                {
                    typedef typename chain_from<Previous>::type PreviousChain;
                    PreviousChain &chain = m_pThis->ChainFrom<Previous>();
                    m_pContainer->m_p = chain.MapFirst<T>();
                }
            }

            this_type const *m_pThis;
            container<T> *m_pContainer;
        };

        template<
            class T,
            class HeapProvider
        >
        struct new_object_first_selector
        {
            new_object_first_selector(this_type const &this_, HeapProvider &provider, container<T> &container) : 
                m_pThis(&this_),
                m_pProvider(&provider),
                m_pContainer(&container)
            { }

            template<class Previous>
            void operator()(wrap<Previous> const &)
            {
                if (!m_pContainer->m_p)
                {
                    typedef typename chain_from<Previous>::type PreviousChain;
                    PreviousChain &chain = m_pThis->ChainFrom<Previous>();
                    m_pContainer->m_p = chain.NewObject<T>(*m_pProvider);
                }
            }

            this_type const *m_pThis;
            HeapProvider *m_pProvider;
            container<T> *m_pContainer;
        };
    };





    namespace Detail {
        
        namespace mpl = boost::mpl;
        using namespace boost;

        template<class ObjectTagSequence, class I, class IEnd>
        class ATL_NO_VTABLE SimpleHeapProvider5B4288A9Impl : 
            public SimpleHeapProvider5B4288A9Impl<ObjectTagSequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SimpleHeapProvider5B4288A9Impl<ObjectTagSequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_tag_type;
            typedef typename object_tag_type::object_type object_type;
            typedef typename object_tag_type::tag_type tag_type;
            typedef SimpleHeap<object_type, tag_type> object_heap_type;

            static object_heap_type &StaticHeap()
            {
                static object_heap_type heap;
                return heap;
            }

            object_heap_type &Heap()
            {
                if (!m_pHeap.get())
                    m_pHeap = make_shared<object_heap_type>();
                return *m_pHeap.get();
            }
        
        private:
            shared_ptr<object_heap_type> m_pHeap;
        };

        template<class ObjectTagSequence>
        class ATL_NO_VTABLE SimpleHeapProvider5B4288A9Impl<ObjectTagSequence, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type, 
                                             typename Traits::DistinctEnd<ObjectTagSequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class ObjectTagSequence>
    class ATL_NO_VTABLE SimpleHeapProvider5B4288A9 : 
        public Detail::SimpleHeapProvider5B4288A9Impl<ObjectTagSequence, 
                                 typename Traits::DistinctBegin<ObjectTagSequence>::type, 
                                 typename Traits::DistinctEnd<ObjectTagSequence>::type>
    {
    public:
        typedef SimpleHeapProvider5B4288A9<ObjectTagSequence> this_type;

        template<class ObjectTag>
        struct provider_of
        {
            typedef Detail::SimpleHeapProvider5B4288A9Impl<
                ObjectTagSequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<ObjectTagSequence>::type,
                    ObjectTag
                >::type,
                typename Traits::DistinctEnd<ObjectTagSequence>::type
            > type;
        };

        template<class ObjectTag>
        inline typename provider_of<ObjectTag>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<ObjectTag>::type &>(*pMutableThis);
        }
    };
    
    
    
    
    
    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Sequence, class I, class IEnd>
        class ATL_NO_VTABLE SmartHeapProviderImpl : 
            SimpleHeapProvider5B4288A9<
                mpl::vector<
                    ObjectTag<typename mpl::deref<I>::type, QuickHeapWithoutSubscriptOperator>
                >
            >,
            public SmartHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef SmartHeapProviderImpl<Sequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef shared_ptr<object_type> sp_object_type;
            typedef ObjectTag<object_type, QuickHeapWithoutSubscriptOperator> obj_tag_type;
            typedef typename provider_of<obj_tag_type>::type provider_type;

            static sp_object_type NewStaticObject()
            {
                return sp_object_type(provider_type::StaticHeap().New(), deleter(provider_type::StaticHeap()));
            }

            sp_object_type NewObject()
            {
                provider_type &provider = ProviderOf<obj_tag_type>();
                return sp_object_type(provider.Heap().New(), deleter(provider.Heap()));
            }

        private:
            class deleter
            {
            public:
                deleter(typename provider_type::object_heap_type &heap) : m_pHeap(&heap) {}
                void operator()(object_type *p) { m_pHeap->Delete(p); }
            private:
                typename provider_type::object_heap_type *m_pHeap;
            };
        };

        template<class Sequence>
        class SmartHeapProviderImpl<Sequence, 
                                    typename Traits::DistinctEnd<Sequence>::type, 
                                    typename Traits::DistinctEnd<Sequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class Sequence>
    class ATL_NO_VTABLE SmartHeapProvider : 
        public Detail::SmartHeapProviderImpl<Sequence, 
                                             typename Traits::DistinctBegin<Sequence>::type, 
                                             typename Traits::DistinctEnd<Sequence>::type>
    {
    public:
        typedef SmartHeapProvider<Sequence> this_type;
        typedef Sequence sequence_type;

        template<class T>
        struct provider_of
        {
            typedef Detail::SmartHeapProviderImpl<
                Sequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<Sequence>::type,
                    T
                >::type,
                typename Traits::DistinctEnd<Sequence>::type
            > type;
        };

        template<class T>
        inline typename provider_of<T>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<T>::type &>(*pMutableThis);
        }
    };
    
    
    
    
    
    namespace Detail {

        namespace mpl = boost::mpl;
        using namespace boost;

        template<class Sequence, class I, class IEnd>
        class ATL_NO_VTABLE DisposableHeapProviderImpl : 
            SmartHeapProvider<
                mpl::vector<
                    typename mpl::deref<I>::type
                >
            >,
            public DisposableHeapProviderImpl<Sequence, typename mpl::next<I>::type, IEnd>
        {
        public:
            typedef DisposableHeapProviderImpl<Sequence, I, IEnd> this_type;
            typedef typename mpl::deref<I>::type object_type;
            typedef typename provider_of<object_type>::type provider_type;
            typedef std::vector<typename provider_type::sp_object_type> sp_object_vector_type;

            virtual ~DisposableHeapProviderImpl()
            {
                typedef sp_object_vector_type::reverse_iterator ReverseIterator;
                for (ReverseIterator ri = Objects().rbegin(), ri_end = Objects().rend(); ri != ri_end; ++ri)
                    (*ri)->Dispose();
            }

            static typename provider_type::sp_object_type NewStaticObject()
            {
                return provider_type::NewStaticObject();
            }

            typename provider_type::sp_object_type NewObject()
            {
                return ProviderOf<object_type>().NewObject();
            }

            typename sp_object_vector_type::size_type Register(typename provider_type::sp_object_type const &p)
            {
                Objects().push_back(p);
                return Objects().size() - 1;
            }

            typename provider_type::sp_object_type operator[](typename sp_object_vector_type::size_type n)
            {
                return Objects()[n];
            }
        
        private:
            shared_ptr<sp_object_vector_type> m_pObjects;

            sp_object_vector_type &Objects()
            {
                if (!m_pObjects.get())
                    m_pObjects = make_shared<sp_object_vector_type>();
                return *m_pObjects.get();
            }
        };

        template<class Sequence>
        class DisposableHeapProviderImpl<Sequence, 
                                             typename Traits::DistinctEnd<Sequence>::type, 
                                             typename Traits::DistinctEnd<Sequence>::type> : 
            noncopyable
        {
        };

    }   // namespace Detail


    template<class Sequence>
    class ATL_NO_VTABLE DisposableHeapProvider : 
        public Detail::DisposableHeapProviderImpl<Sequence, 
                                                  typename Traits::DistinctBegin<Sequence>::type, 
                                                  typename Traits::DistinctEnd<Sequence>::type>
    {
    public:
        typedef DisposableHeapProvider<Sequence> this_type;
        typedef Sequence sequence_type;

        template<class T>
        struct provider_of
        {
            typedef Detail::DisposableHeapProviderImpl<
                Sequence,
                typename boost::mpl::find<
                    typename Traits::Distinct<Sequence>::type,
                    T
                >::type,
                typename Traits::DistinctEnd<Sequence>::type
            > type;
        };

        template<class T>
        inline typename provider_of<T>::type &ProviderOf() const
        {
            this_type *pMutableThis = const_cast<this_type *>(this);
            return static_cast<typename provider_of<T>::type &>(*pMutableThis);
        }
    };

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    NullDeleter<T> MakeNullDeleter(T)
    {
        return NullDeleter<T>();
    }

    template<class T>
    struct NullDeleter
    {
        void operator()(T *p) { }
    };

    template<class T>
    struct NullDeleter<T const *>
    {
        void operator()(T const *p) { }
    };

    template<class T>
    struct NullDeleter<T *>
    {
        void operator()(T const *p) { }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;

        struct DefaultHostInfo5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<HostInfo5B4288A9Label, HostInfo5B4288A9>,
                pair<RuntimeHost5B4288A9Label, RuntimeHost5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultHostInfo5B4288A9ApiHolder : 
        Detail::DefaultHostInfo5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        struct DefaultRuntimeHost5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<HostInfo5B4288A9Label, HostInfo5B4288A9>,
                pair<FusionInfo5B4288A9Label, FusionInfo5B4288A9>,
                pair<MetadataInfo5B4288A9Label, MetadataInfo5B4288A9>,
                pair<StrongNameInfo5B4288A9Label, StrongNameInfo5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultRuntimeHost5B4288A9ApiHolder : 
        Detail::DefaultRuntimeHost5B4288A9ApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct HostInfo5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::HostInfo5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class HostInfo5B4288A9ApiHolder
    >    
    class BaseHostInfo5B4288A9 : 
        public SmartPtrChain<
            BaseHostInfo5B4288A9<HostInfo5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<boost::mpl::void_>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename HostInfo5B4288A9ApiAt<HostInfo5B4288A9ApiHolder, Interfaces::HostInfo5B4288A9Label>::type,
                typename HostInfo5B4288A9ApiAt<HostInfo5B4288A9ApiHolder, Interfaces::RuntimeHost5B4288A9Label>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseHostInfo5B4288A9<HostInfo5B4288A9ApiHolder> this_type;

        typedef typename HostInfo5B4288A9ApiAt<HostInfo5B4288A9ApiHolder, Interfaces::RuntimeHost5B4288A9Label>::type runtime_host_type;

        typedef typename provider_of<this_type>::type host_info_provider_type;
        typedef typename provider_of<runtime_host_type>::type runtime_host_provider_type;
        typedef typename chain_from<boost::mpl::void_>::type host_info_chain_type; 

        static boost::shared_ptr<this_type> NewHost()
        {
            return host_info_chain_type::NewRootObject<this_type, host_info_provider_type>();
        }

        boost::shared_ptr<runtime_host_type const> GetRuntime(std::wstring const &version) const
        {
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            boost::shared_ptr<runtime_host_type> pExistingRuntime;
            if (!TryGetRuntime(version, pExistingRuntime))
            {
                boost::shared_ptr<runtime_host_type> pNewRuntime = NewRuntime();

                std::wstring const &corVersion = pNewRuntime->GetCORVersion();
                if (corVersion != version)
                {
                    std::wstring what;
                    what += L"The version '";
                    what += version;
                    what += L"' is not supported. For your information, this process runs at version '";
                    what += corVersion;
                    what += L"'.";
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(what));
                }

                runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
                m_versionToIndex[version] = provider.Register(pNewRuntime);
                return pNewRuntime;
            }
            else
            {
                return pExistingRuntime;
            }
        }

    private:
        
        void SetThis(boost::weak_ptr<this_type> const &pThis) const
        {
            _ASSERTE(m_pThis.use_count() == 0);
            m_pThis = pThis;
        }

        boost::shared_ptr<runtime_host_type> NewRuntime() const
        {
            runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
            host_info_chain_type &chain = ChainFrom<boost::mpl::void_>();
            return chain.NewObject<runtime_host_type>(provider);
        }

        bool TryGetRuntime(std::wstring const &version, boost::shared_ptr<runtime_host_type> &pExistingRuntime) const
        {
            if (m_versionToIndex.find(version) == m_versionToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_versionToIndex[version];
                runtime_host_provider_type &provider = ProviderOf<runtime_host_type>();
                pExistingRuntime = provider[index];
                return true;
            }
        }

        mutable boost::unordered_map<std::wstring, size_t> m_versionToIndex;
    };





    struct RuntimeHostChainMapper : 
        SmartPtrChainMapper
    {
        template<
            class T,
            class Previous,
            class Current
        >
        static bool CanMapFirstAncestor(Current const &current)
        {
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapFirstAncestor(Current const &current) 
        { 
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static bool CanMapAncestor(Current const &current)
        {
            return current.GetInfo<T>();
        }

        template<
            class T,
            class Previous,
            class Current
        >
        static boost::shared_ptr<T> MapAncestor(Current const &current) 
        { 
            return current.GetInfo<T>();
        }
    };

    template<class ApiCartridgesHolder, class ApiLabel>
    struct RuntimeHost5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::RuntimeHost5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class RuntimeHost5B4288A9ApiHolder
    >    
    class BaseRuntimeHost5B4288A9 : 
        public SmartPtrChain<
            BaseRuntimeHost5B4288A9<RuntimeHost5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename RuntimeHost5B4288A9ApiAt<RuntimeHost5B4288A9ApiHolder, Interfaces::HostInfo5B4288A9Label>::type, RuntimeHostChainMapper>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename RuntimeHost5B4288A9ApiAt<RuntimeHost5B4288A9ApiHolder, StrongNaming::Interfaces::StrongNameInfo5B4288A9Label>::type,
                typename RuntimeHost5B4288A9ApiAt<RuntimeHost5B4288A9ApiHolder, Metadata::Interfaces::MetadataInfo5B4288A9Label>::type,
                typename RuntimeHost5B4288A9ApiAt<RuntimeHost5B4288A9ApiHolder, Fusion::Interfaces::FusionInfo5B4288A9Label>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseRuntimeHost5B4288A9<RuntimeHost5B4288A9ApiHolder> this_type;

        typedef typename RuntimeHost5B4288A9ApiAt<RuntimeHost5B4288A9ApiHolder, Interfaces::HostInfo5B4288A9Label>::type host_info_type;

        typedef typename chain_from<host_info_type>::type runtime_host_chain_type; 

        BaseRuntimeHost5B4288A9() : 
            m_corVersionInitialized(false),
            m_corSysDirPathInitialized(false)
        { }

        std::wstring const &GetCORVersion() const
        {
            CheckDisposed();

            if (!m_corVersionInitialized)
            {
                WCHAR buffer[MAX_PATH] = { 0 };
                DWORD bufferSize = MAX_PATH - 1;
                DWORD length = 0;

#pragma warning(push)
#pragma warning(disable: 4996)
                HRESULT hr = ::GetCORVersion(buffer, bufferSize, &length);
#pragma warning(pop)
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                
                m_corVersion = buffer;

                m_corVersionInitialized = true;
            }
            return m_corVersion;
        }

        boost::filesystem::path const &GetCORSystemDirectoryPath() const
        {
            CheckDisposed();

            using namespace boost::filesystem;

            if (!m_corSysDirPathInitialized)
            {
                WCHAR buffer[MAX_PATH] = { 0 };
                DWORD bufferSize = MAX_PATH - 1;
                DWORD length = 0;

#pragma warning(push)
#pragma warning(disable: 4996)
                HRESULT hr = ::GetCORSystemDirectory(buffer, bufferSize, &length);
#pragma warning(pop)
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_corSysDirPath = buffer;
                
                m_corSysDirPathInitialized = true;
            }
            return m_corSysDirPath;
        }

        template<class Info>
        boost::shared_ptr<Info> GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, Info>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            boost::shared_ptr<Info> pExistingInfo;
            if (!TryGetInfo<Info>(pExistingInfo))
            {
                boost::shared_ptr<Info> pNewInfo;
                pNewInfo = NewInfo<Info>();
                
                typedef typename provider_of<Info>::type InfoProvider;
                InfoProvider &provider = ProviderOf<Info>();
                Utilities::TypeInfo key = mpl::identity<Info>();
                m_infoToIndex[key] = provider.Register(pNewInfo);
                return pNewInfo;
            }
            else
            {
                return pExistingInfo;
            }
        }

    private:
        friend typename host_info_type;

        template<class Info>
        boost::shared_ptr<Info> NewInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, Info>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            typedef typename provider_of<Info>::type InfoProvider;
            InfoProvider &provider = ProviderOf<Info>();
            runtime_host_chain_type &chain = ChainFrom<host_info_type>();
            return chain.NewObject<Info>(provider);
        }

        template<class Info>
        bool TryGetInfo(boost::shared_ptr<Info> &pExistingInfo) const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, Info>::type I;
            typedef mpl::end<sequence_type>::type IEnd;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<I, IEnd> >));

            Utilities::TypeInfo key = mpl::identity<Info>();
            if (m_infoToIndex.find(key) == m_infoToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_infoToIndex[key];
                typedef typename provider_of<Info>::type InfoProvider;
                InfoProvider &provider = ProviderOf<Info>();
                pExistingInfo = provider[index];
                return true;
            }
        }

        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSysDirPathInitialized;
        mutable boost::filesystem::path m_corSysDirPath;
        mutable boost::unordered_map<Utilities::TypeInfo, size_t, Utilities::TypeInfoHash, Utilities::TypeInfoEqualTo> m_infoToIndex;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

    //namespace Detail {
    //    
    //    namespace mpl = boost::mpl;

    //    struct DefaultHostInfoApiHolderImpl
    //    {
    //        typedef mpl::map<
    //            mpl::pair<Interfaces::StrongNameInfoLabel, StrongNameInfo> 
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultStrongNameInfo5B4288A9ApiHolder
    {
    };





    //namespace Detail {
    //    
    //    namespace mpl = boost::mpl;

    //    struct DefaultHostInfoApiHolderImpl
    //    {
    //        typedef mpl::map<
    //            mpl::pair<Interfaces::StrongNameInfoLabel, StrongNameInfo> 
    //        > api_cartridges;
    //    };

    //}   // namespace Detail {

    struct DefaultStrongNameKey5B4288A9ApiHolder
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameInfo5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameInfo5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameInfo5B4288A9ApiHolder
    >    
    class BaseStrongNameInfo5B4288A9 : 
        public SimpleDisposable
    {
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct StrongNameKey5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::StrongNameKey5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class StrongNameKey5B4288A9ApiHolder
    >    
    class BaseStrongNameKey5B4288A9 : 
        public SimpleDisposable
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::StrongNaming;
        using namespace Urasandesu::CppAnonym::StrongNaming::Interfaces;

        struct DefaultIAssemblyMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadata5B4288A9Label, IAssemblyMetadata5B4288A9>,
                pair<MetadataDispenser5B4288A9Label, MetadataDispenser5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIAssemblyMetadata5B4288A9ApiHolder : 
        Detail::DefaultIAssemblyMetadata5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIModuleMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<IModuleMetadata5B4288A9Label, IModuleMetadata5B4288A9>,
                pair<IAssemblyMetadata5B4288A9Label, IAssemblyMetadata5B4288A9>,
                pair<IAssemblyMetadata5B4288A9HashLabel, IAssemblyMetadata5B4288A9Hash>,
                pair<IAssemblyMetadata5B4288A9EqualToLabel, IAssemblyMetadata5B4288A9EqualTo>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIModuleMetadata5B4288A9ApiHolder : 
        Detail::DefaultIModuleMetadata5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultITypeMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadata5B4288A9Label, ITypeMetadata5B4288A9>,
                pair<IModuleMetadata5B4288A9Label, IModuleMetadata5B4288A9>,
                pair<IModuleMetadata5B4288A9HashLabel, IModuleMetadata5B4288A9Hash>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultITypeMetadata5B4288A9ApiHolder : 
        Detail::DefaultITypeMetadata5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {

        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultIMethodMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadata5B4288A9Label, IMethodMetadata5B4288A9>,
                pair<ITypeMetadata5B4288A9HashLabel, ITypeMetadata5B4288A9Hash>,
                pair<ITypeMetadata5B4288A9Label, ITypeMetadata5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultIMethodMetadata5B4288A9ApiHolder : 
        Detail::DefaultIMethodMetadata5B4288A9ApiHolderImpl
    {
    };

    
    
    
    
    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataInfo5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<RuntimeHost5B4288A9Label, RuntimeHost5B4288A9>,
                pair<MetadataDispenser5B4288A9Label, MetadataDispenser5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMetadataInfo5B4288A9ApiHolder : 
        Detail::DefaultMetadataInfo5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMetadataDispenser5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<MetadataInfo5B4288A9Label, MetadataInfo5B4288A9>,
                pair<AssemblyMetadata5B4288A9Label, AssemblyMetadata5B4288A9>,
                pair<IAssemblyMetadata5B4288A9HashLabel, IAssemblyMetadata5B4288A9Hash>,
                pair<IAssemblyMetadata5B4288A9EqualToLabel, IAssemblyMetadata5B4288A9EqualTo>,
                pair<ModuleMetadata5B4288A9Label, ModuleMetadata5B4288A9>,
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<TypeMetadata5B4288A9Label, TypeMetadata5B4288A9>,
                pair<MethodMetadata5B4288A9Label, MethodMetadata5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultMetadataDispenser5B4288A9ApiHolder : 
        Detail::DefaultMetadataDispenser5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;
        using namespace Urasandesu::CppAnonym::Fusion;

        struct DefaultAssemblyMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<IAssemblyMetadata5B4288A9Label, IAssemblyMetadata5B4288A9>,
                pair<MetadataDispenser5B4288A9Label, MetadataDispenser5B4288A9>,
                pair<FusionInfo5B4288A9Label, FusionInfo5B4288A9>,
                pair<AssemblyInfo5B4288A9Label, AssemblyInfo5B4288A9>,
                pair<IMetaDataAssemblyImport, IMetaDataAssemblyImport>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<IMetaDataDispenserEx, IMetaDataDispenserEx>,
                pair<ModuleMetadata5B4288A9Label, ModuleMetadata5B4288A9>,
                pair<IModuleMetadata5B4288A9HashLabel, IModuleMetadata5B4288A9Hash>,
                pair<IModuleMetadata5B4288A9EqualToLabel, IModuleMetadata5B4288A9EqualTo>,
                pair<TypeMetadata5B4288A9Label, TypeMetadata5B4288A9>,
                pair<MethodMetadata5B4288A9Label, MethodMetadata5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultAssemblyMetadata5B4288A9ApiHolder : 
        Detail::DefaultAssemblyMetadata5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultModuleMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<IModuleMetadata5B4288A9Label, IModuleMetadata5B4288A9>,
                pair<AssemblyMetadata5B4288A9Label, AssemblyMetadata5B4288A9>,
                pair<IMetaDataImport2, IMetaDataImport2>,
                pair<ITypeMetadata5B4288A9Label, ITypeMetadata5B4288A9>,
                pair<TypeMetadata5B4288A9Label, TypeMetadata5B4288A9>,
                pair<ITypeMetadata5B4288A9HashLabel, ITypeMetadata5B4288A9Hash>,
                pair<ITypeMetadata5B4288A9EqualToLabel, ITypeMetadata5B4288A9EqualTo>,
                pair<MetadataDispenser5B4288A9Label, MetadataDispenser5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultModuleMetadata5B4288A9ApiHolder : 
        Detail::DefaultModuleMetadata5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultTypeMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<ITypeMetadata5B4288A9Label, ITypeMetadata5B4288A9>,
                pair<MetadataDispenser5B4288A9Label, MetadataDispenser5B4288A9>,
                pair<AssemblyMetadata5B4288A9Label, AssemblyMetadata5B4288A9>,
                pair<ModuleMetadata5B4288A9Label, ModuleMetadata5B4288A9>,
                pair<MethodMetadata5B4288A9Label, MethodMetadata5B4288A9>,
                pair<IMethodMetadata5B4288A9HashLabel, IMethodMetadata5B4288A9Hash>,
                pair<IMethodMetadata5B4288A9EqualToLabel, IMethodMetadata5B4288A9EqualTo>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultTypeMetadata5B4288A9ApiHolder : 
        Detail::DefaultTypeMetadata5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Metadata::Interfaces;

        struct DefaultMethodMetadata5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<IMethodMetadata5B4288A9Label, IMethodMetadata5B4288A9>,
                pair<AssemblyMetadata5B4288A9Label, AssemblyMetadata5B4288A9>,
                pair<TypeMetadata5B4288A9Label, TypeMetadata5B4288A9>,
                pair<ITypeMetadata5B4288A9Label, ITypeMetadata5B4288A9>,
                pair<IMetaDataImport2, IMetaDataImport2>
            > api_cartridges;
        };

    }   // namespace Detail {
    
    struct DefaultMethodMetadata5B4288A9ApiHolder : 
        Detail::DefaultMethodMetadata5B4288A9ApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct IAssemblyMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IAssemblyMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseIAssemblyMetadata5B4288A9
    {
    public:
        typedef BaseIAssemblyMetadata5B4288A9<IAssemblyMetadata5B4288A9ApiHolder> this_type;

        typedef typename IAssemblyMetadata5B4288A9ApiAt<IAssemblyMetadata5B4288A9ApiHolder, StrongNaming::Interfaces::StrongNameKey5B4288A9Label>::type strong_name_key_type;
        typedef typename IAssemblyMetadata5B4288A9ApiAt<IAssemblyMetadata5B4288A9ApiHolder, Interfaces::MetadataDispenser5B4288A9Label>::type metadata_dispenser_type;
        typedef typename IAssemblyMetadata5B4288A9ApiAt<IAssemblyMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9Label>::type i_assembly_metadata_type;

        virtual mdAssembly GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<strong_name_key_type const> GetStrongNameKey() const = 0;
        virtual boost::shared_ptr<metadata_dispenser_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseIAssemblyMetadata5B4288A9Hash : 
        Traits::HashComputable<boost::shared_ptr<typename IAssemblyMetadata5B4288A9ApiAt<IAssemblyMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9Label>::type const> >
    {
    public:
        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Utilities;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, HashValue(v->GetResolutionScope().get()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IAssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseIAssemblyMetadata5B4288A9EqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IAssemblyMetadata5B4288A9ApiAt<IAssemblyMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9Label>::type const> >
    {
    public:
        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x && y);

            return x->GetName() == y->GetName() &&
                   x->GetResolutionScope() == y->GetResolutionScope();
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IModuleMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IModuleMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IModuleMetadata5B4288A9ApiHolder
    >    
    class BaseIModuleMetadata5B4288A9
    {
    public:
        typedef BaseIModuleMetadata5B4288A9<IModuleMetadata5B4288A9ApiHolder> this_type;

        typedef typename IModuleMetadata5B4288A9ApiAt<IModuleMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9Label>::type i_assembly_metadata_type;

        virtual mdModule GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<i_assembly_metadata_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IModuleMetadata5B4288A9ApiHolder
    >    
    class BaseIModuleMetadata5B4288A9Hash : 
        Traits::HashComputable<boost::shared_ptr<typename IModuleMetadata5B4288A9ApiAt<IModuleMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9Label>::type const> >
    {
    public:
        typedef typename IModuleMetadata5B4288A9ApiAt<IModuleMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9HashLabel>::type i_assembly_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_assembly_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IModuleMetadata5B4288A9ApiHolder
    >    
    class BaseIModuleMetadata5B4288A9EqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IModuleMetadata5B4288A9ApiAt<IModuleMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9Label>::type const> >
    {
    public:
        typedef typename IModuleMetadata5B4288A9ApiAt<IModuleMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9EqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            _ASSERTE(x && y);

            return x->GetName() == y->GetName() &&
                   i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ITypeMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ITypeMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ITypeMetadata5B4288A9ApiHolder
    >    
    class BaseITypeMetadata5B4288A9
    {
    public:
        typedef BaseITypeMetadata5B4288A9<ITypeMetadata5B4288A9ApiHolder> this_type;

        typedef typename ITypeMetadata5B4288A9ApiAt<ITypeMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9Label>::type i_module_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual boost::shared_ptr<this_type const> GetBaseType() const = 0;
        virtual boost::shared_ptr<i_module_metadata_type const> GetResolutionScope() const = 0;
        virtual std::vector<COR_SIGNATURE> const &GetSignatures() const = 0;
        virtual bool IsGenericParameter() const = 0;
    };




    
    template<
        class ITypeMetadata5B4288A9ApiHolder
    >    
    class BaseITypeMetadata5B4288A9Hash : 
        Traits::HashComputable<boost::shared_ptr<typename ITypeMetadata5B4288A9ApiAt<ITypeMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type const> >
    {
    public:
        typedef typename ITypeMetadata5B4288A9ApiAt<ITypeMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9HashLabel>::type i_module_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, i_module_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class ITypeMetadata5B4288A9ApiHolder
    >    
    class BaseITypeMetadata5B4288A9EqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename ITypeMetadata5B4288A9ApiAt<ITypeMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type const> >
    {
    public:
        //typedef typename ITypeMetadata5B4288A9ApiAt<ITypeMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9EqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x != NULL && y != NULL);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(&x->GetResolutionScope(), &y->GetResolutionScope());
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct IMethodMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::IMethodMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class IMethodMetadata5B4288A9ApiHolder
    >    
    class BaseIMethodMetadata5B4288A9
    {
    public:
        typedef BaseIMethodMetadata5B4288A9<IMethodMetadata5B4288A9ApiHolder> this_type;

        typedef typename IMethodMetadata5B4288A9ApiAt<IMethodMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type i_type_metadata_type;
        typedef typename IMethodMetadata5B4288A9ApiAt<IMethodMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9Label>::type i_method_metadata_type;

        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetName() const = 0;
        virtual CallingConventions const &GetCallingConvention() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetReturnType() const = 0;
        virtual std::vector<boost::shared_ptr<i_type_metadata_type const> > const &GetParameterTypes() const = 0;
        virtual boost::shared_ptr<i_type_metadata_type const> GetResolutionScope() const = 0;
    };




    
    template<
        class IMethodMetadata5B4288A9ApiHolder
    >    
    class BaseIMethodMetadata5B4288A9Hash : 
        Traits::HashComputable<boost::shared_ptr<typename IMethodMetadata5B4288A9ApiAt<IMethodMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9Label>::type const> >
    {
    public:
        typedef typename IMethodMetadata5B4288A9ApiAt<IMethodMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9HashLabel>::type i_type_metadata_hash_type;

        result_type operator()(param_type v) const
        {
            using namespace boost;
            using namespace Urasandesu::CppAnonym::Collections;

            _ASSERTE(v);

            std::size_t seed = 0;
            hash_combine(seed, hash_value(v->GetName()));
            hash_combine(seed, v->GetCallingConvention().Value());
            hash_combine(seed, i_type_metadata_hash_type()(v->GetReturnType()));
            hash_combine(seed, SequenceHashValue(v->GetParameterTypes().cbegin(), 
                                                 v->GetParameterTypes().cend(), 
                                                 i_type_metadata_hash_type()));
            hash_combine(seed, i_type_metadata_hash_type()(v->GetResolutionScope()));
            return seed;
        }
    };

    
    
    
    
    template<
        class IMethodMetadata5B4288A9ApiHolder
    >    
    class BaseIMethodMetadata5B4288A9EqualTo : 
        Traits::EqualityComparable<boost::shared_ptr<typename IMethodMetadata5B4288A9ApiAt<IMethodMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9Label>::type const> >
    {
    public:
        //typedef typename IMethodMetadata5B4288A9ApiAt<IMethodMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9EqualToLabel>::type i_assembly_metadata_equal_to_type;

        result_type operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            //_ASSERTE(x && y);

            //return x->GetName() == y->GetName() &&
            //       i_assembly_metadata_equal_to_type()(x->GetResolutionScope(), y->GetResolutionScope());
        }
    };

    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataInfo5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataInfo5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataInfo5B4288A9ApiHolder
    >    
    class BaseMetadataInfo5B4288A9 : 
        public SmartPtrChain<
            BaseMetadataInfo5B4288A9<MetadataInfo5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MetadataInfo5B4288A9ApiAt<MetadataInfo5B4288A9ApiHolder, Hosting::Interfaces::RuntimeHost5B4288A9Label>::type>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename MetadataInfo5B4288A9ApiAt<MetadataInfo5B4288A9ApiHolder, Interfaces::MetadataDispenser5B4288A9Label>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataInfo5B4288A9<MetadataInfo5B4288A9ApiHolder> this_type;

        typedef typename MetadataInfo5B4288A9ApiAt<MetadataInfo5B4288A9ApiHolder, Hosting::Interfaces::RuntimeHost5B4288A9Label>::type runtime_host_type;
        typedef typename MetadataInfo5B4288A9ApiAt<MetadataInfo5B4288A9ApiHolder, Interfaces::MetadataDispenser5B4288A9Label>::type metadata_dispenser_type;

        typedef typename provider_of<metadata_dispenser_type>::type metadata_dispenser_provider_type;

        typedef typename chain_from<runtime_host_type>::type metadata_info_chain_type; 

        BaseMetadataInfo5B4288A9()
        { }

        boost::shared_ptr<metadata_dispenser_type> CreateDispenser() const
        {
            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            boost::shared_ptr<metadata_dispenser_type> pDisp = NewDispenser();
            provider.Register(pDisp);
            return pDisp;
        }

    private:
        friend typename runtime_host_type;

        boost::shared_ptr<metadata_dispenser_type> NewDispenser() const
        {
            metadata_dispenser_provider_type &provider = ProviderOf<metadata_dispenser_type>();
            metadata_info_chain_type &chain = ChainFrom<runtime_host_type>();
            return chain.NewObject<metadata_dispenser_type>(provider);
        }
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MetadataDispenser5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MetadataDispenser5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MetadataDispenser5B4288A9ApiHolder
    >    
    class BaseMetadataDispenser5B4288A9 : 
        public SmartPtrChain<
            BaseMetadataDispenser5B4288A9<MetadataDispenser5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::MetadataInfo5B4288A9Label>::type>
            >
        >,
        public DisposableHeapProvider<
            boost::mpl::vector<
                typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::AssemblyMetadata5B4288A9Label>::type,
                typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::ModuleMetadata5B4288A9Label>::type,
                typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::TypeMetadata5B4288A9Label>::type,
                typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::MethodMetadata5B4288A9Label>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseMetadataDispenser5B4288A9<MetadataDispenser5B4288A9ApiHolder> this_type;

        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::MetadataInfo5B4288A9Label>::type metadata_info_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::AssemblyMetadata5B4288A9Label>::type assembly_metadata_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9HashLabel>::type i_assembly_metadata_hash_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9EqualToLabel>::type i_assembly_metadata_equal_to_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::ModuleMetadata5B4288A9Label>::type module_metadata_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::TypeMetadata5B4288A9Label>::type type_metadata_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, Interfaces::MethodMetadata5B4288A9Label>::type method_metadata_type;
        typedef typename MetadataDispenser5B4288A9ApiAt<MetadataDispenser5B4288A9ApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;

        typedef typename provider_of<assembly_metadata_type>::type assembly_metadata_provider_type;
        typedef typename provider_of<module_metadata_type>::type module_metadata_provider_type;
        typedef typename provider_of<type_metadata_type>::type type_metadata_provider_type;
        typedef typename provider_of<method_metadata_type>::type method_metadata_provider_type;

        typedef typename chain_from<metadata_info_type>::type metadata_dispenser_chain_type; 

        BaseMetadataDispenser5B4288A9()
        { }

        boost::shared_ptr<assembly_metadata_type const> GetAssembly(std::wstring const &fullName) const
        {
            boost::shared_ptr<assembly_metadata_type> pNewAsm;
            pNewAsm = NewAssembly(fullName);

            boost::shared_ptr<assembly_metadata_type> pExistingAsm;
            if (!TryGetAssembly(*pNewAsm, pExistingAsm))
            {
                assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
                m_asmToIndex[pNewAsm] = provider.Register(pNewAsm);
                return pNewAsm;
            }
            else
            {
                return pExistingAsm;
            }
        }

    private:
        friend typename metadata_info_type;
        friend typename assembly_metadata_type;

        boost::shared_ptr<assembly_metadata_type> NewAssembly(std::wstring const &fullName) const
        {
            assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
            metadata_dispenser_chain_type &chain = ChainFrom<metadata_info_type>();
            boost::shared_ptr<assembly_metadata_type> pAsm = chain.NewObject<assembly_metadata_type>(provider);
            pAsm->SetName(fullName);
            return pAsm;
        }

        bool TryGetAssembly(assembly_metadata_type const &keyAsm, boost::shared_ptr<assembly_metadata_type> &pExistingAsm) const
        {
            boost::shared_ptr<assembly_metadata_type const> pKeyAsm(&keyAsm, Utilities::MakeNullDeleter(&keyAsm));
            if (m_asmToIndex.find(pKeyAsm) == m_asmToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_asmToIndex[pKeyAsm];
                assembly_metadata_provider_type &provider = ProviderOf<assembly_metadata_type>();
                pExistingAsm = provider[index];
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

        mutable boost::unordered_map<boost::shared_ptr<assembly_metadata_type const>, 
                                     size_t, 
                                     i_assembly_metadata_hash_type, 
                                     i_assembly_metadata_equal_to_type> m_asmToIndex;
        mutable ATL::CComPtr<com_meta_data_dispenser_type> m_pComMetaDisp;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyMetadata5B4288A9ApiHolder
    >    
    class BaseAssemblyMetadata5B4288A9 : 
        public SmartPtrChain<
            BaseAssemblyMetadata5B4288A9<AssemblyMetadata5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::MetadataDispenser5B4288A9Label>::type>
            >
        >,
        public AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9Label>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseAssemblyMetadata5B4288A9<AssemblyMetadata5B4288A9ApiHolder> this_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::IAssemblyMetadata5B4288A9Label>::type base_type;

        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, IMetaDataAssemblyImport>::type com_meta_data_assembly_import_type;        
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, IMetaDataDispenserEx>::type com_meta_data_dispenser_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Fusion::Interfaces::FusionInfo5B4288A9Label>::type fusion_info_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Fusion::Interfaces::AssemblyInfo5B4288A9Label>::type assembly_info_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::ModuleMetadata5B4288A9Label>::type module_metadata_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9HashLabel>::type i_module_metadata_hash_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9EqualToLabel>::type i_module_metadata_equal_to_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::TypeMetadata5B4288A9Label>::type type_metadata_type;
        typedef typename AssemblyMetadata5B4288A9ApiAt<AssemblyMetadata5B4288A9ApiHolder, Interfaces::MethodMetadata5B4288A9Label>::type method_metadata_type;        
        
        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Asm, module_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Asm, module_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Asm, module_metadata_provider_type, typename base_type::metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Asm, module_metadata_provider_type, typename base_type::metadata_dispenser_type), 
            boost::mpl::void_
        >::type module_metadata_provider_type;
        
        typedef typename chain_from<typename base_type::metadata_dispenser_type>::type assembly_metadata_chain_type; 

        BaseAssemblyMetadata5B4288A9() : 
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

                boost::shared_ptr<fusion_info_type const> pFuInfo;
                pFuInfo = Map<fusion_info_type>();
                boost::shared_ptr<assembly_info_type> pAsmInfo;
                pAsmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, m_name);
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





    template<class ApiCartridgesHolder, class ApiLabel>
    struct ModuleMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::ModuleMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class ModuleMetadata5B4288A9ApiHolder
    >    
    class BaseModuleMetadata5B4288A9 : 
        public SmartPtrChain<
            BaseModuleMetadata5B4288A9<ModuleMetadata5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::AssemblyMetadata5B4288A9Label>::type>
            >
        >,
        public ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9Label>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseModuleMetadata5B4288A9<ModuleMetadata5B4288A9ApiHolder> this_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::IModuleMetadata5B4288A9Label>::type base_type;

        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::AssemblyMetadata5B4288A9Label>::type assembly_metadata_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, IMetaDataImport2>::type com_meta_data_import_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type i_type_metadata_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::TypeMetadata5B4288A9Label>::type type_metadata_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9HashLabel>::type i_type_metadata_hash_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9EqualToLabel>::type i_type_metadata_equal_to_type;
        typedef typename ModuleMetadata5B4288A9ApiAt<ModuleMetadata5B4288A9ApiHolder, Interfaces::MetadataDispenser5B4288A9Label>::type metadata_dispenser_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Mod, type_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Mod, type_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Mod, type_metadata_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Mod, type_metadata_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type type_metadata_provider_type;

        typedef typename chain_from<assembly_metadata_type>::type module_metadata_chain_type; 

        BaseModuleMetadata5B4288A9() : 
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





    template<class ApiCartridgesHolder, class ApiLabel>
    struct TypeMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::TypeMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class TypeMetadata5B4288A9ApiHolder
    >    
    class BaseTypeMetadata5B4288A9 : 
        public SmartPtrChain<
            BaseTypeMetadata5B4288A9<TypeMetadata5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<BaseTypeMetadata5B4288A9<TypeMetadata5B4288A9ApiHolder> >,
                SmartPtrChainInfo<typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::ModuleMetadata5B4288A9Label>::type>
            >
        >,
        public TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseTypeMetadata5B4288A9<TypeMetadata5B4288A9ApiHolder> this_type;
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type base_type;

        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::MetadataDispenser5B4288A9Label>::type metadata_dispenser_type;
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::AssemblyMetadata5B4288A9Label>::type assembly_metadata_type;
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::ModuleMetadata5B4288A9Label>::type module_metadata_type;
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::MethodMetadata5B4288A9Label>::type method_metadata_type;        
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9HashLabel>::type i_method_metadata_hash_type;
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9EqualToLabel>::type i_method_metadata_equal_to_type;
        typedef typename TypeMetadata5B4288A9ApiAt<TypeMetadata5B4288A9ApiHolder, IMetaDataImport2>::type com_meta_data_import_type;        

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Type, type_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Type, type_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Type, type_metadata_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Type, type_metadata_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type type_metadata_provider_type;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(Type, method_metadata_provider_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(Type, method_metadata_provider_type);
        typedef typename boost::mpl::eval_if<
            CPP_ANONYM_HAS_MEMBER_TYPE(Type, method_metadata_provider_type, metadata_dispenser_type), 
            CPP_ANONYM_GET_MEMBER_TYPE(Type, method_metadata_provider_type, metadata_dispenser_type), 
            boost::mpl::void_
        >::type method_metadata_provider_type;        

        typedef typename chain_from<this_type>::type nested_type_metadata_chain_type; 
        typedef typename chain_from<module_metadata_type>::type type_metadata_chain_type; 

        BaseTypeMetadata5B4288A9() : 
            m_mdt(mdTokenNil),
            m_genericArgsInit(false),
            m_kindInitialized(false),
            m_kind(TypeKinds::TK_END),
            m_filled(false)
        { }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                if (boost::shared_ptr<this_type> p = MapFirstAncestor<this_type>())
                {
                    return p->GetToken();
                }
                else
                {
                    _ASSERTE(!m_name.empty());

                    this_type *pMutableThis = const_cast<this_type *>(this);

                    boost::shared_ptr<assembly_metadata_type> pAsmMeta = MapFirst<assembly_metadata_type>();
                
                    com_meta_data_import_type &comMetaImp = pAsmMeta->GetCOMMetaDataImport();

                    HRESULT hr = comMetaImp.FindTypeDefByName(m_name.c_str(), NULL, &m_mdt);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
            }
            return m_mdt;
        }
        
        std::wstring const &GetName() const
        {
            if (m_name.empty())
                FillPropertiesIfNecessary();
            return m_name;
        }

        boost::shared_ptr<typename base_type::this_type const> GetBaseType() const
        {
            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
        }

        boost::shared_ptr<typename base_type::i_module_metadata_type const> GetResolutionScope() const
        {
            return MapFirst<module_metadata_type>();
        }

        std::vector<COR_SIGNATURE> const &GetSignatures() const
        {
            if (m_sigs.empty())
                PushBackSignatures(m_sigs, *this);

            return m_sigs;
        }

        std::vector<boost::shared_ptr<base_type const> > const &GetGenericArguments() const
        {
            if (!m_genericArgsInit)
            {
                this_type *pMutableThis = const_cast<this_type *>(this);

                boost::shared_ptr<assembly_metadata_type> pAsm = pMutableThis->MapFirst<assembly_metadata_type>();
                boost::shared_ptr<module_metadata_type> pMod = pMutableThis->MapFirst<module_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HCORENUM hEnum = NULL;
                    BOOST_SCOPE_EXIT((&hEnum)(&comMetaImp))
                    {
                        if (hEnum)
                            comMetaImp.CloseEnum(hEnum);
                    }
                    BOOST_SCOPE_EXIT_END
                boost::array<mdGenericParam, 16> m_mdgps;
                ULONG count = 0;
                HRESULT hr = E_FAIL;
                mdToken mdtTarget = GetToken();
                do
                {
                    hr = comMetaImp.EnumGenericParams(&hEnum, mdtTarget, m_mdgps.c_array(), m_mdgps.size(), &count);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                    m_genericArgs.reserve(m_genericArgs.size() + count);
                    for (UINT i = 0; i < count; ++i)
                    {
                        boost::shared_ptr<this_type> pType;
                        pType = pMod->NewType(m_mdgps[i]);
                        m_genericArgs.push_back(pType);
                    }
                } while (0 < count);

                m_genericArgsInit = true;
            }
            return m_genericArgs;
        }

        bool IsGenericParameter() const
        {
            return TypeFromToken(GetToken()) == mdtGenericParam;
        }

        bool IsGenericType() const
        {
            return !GetGenericArguments().empty();
        }
        
        bool IsGenericTypeDefinition() const
        {
            if (!IsGenericType())
            {
                return false;
            }
            else
            {
                nested_type_metadata_chain_type &chain = ChainFrom<this_type>();
                boost::shared_ptr<base_type> pGenericTypeDef = chain.GetPrevious().lock();
                return !pGenericTypeDef;
            }
        }

        boost::shared_ptr<this_type const> MakeGenericType(std::vector<boost::shared_ptr<base_type const> > const &genericArgs) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            type_metadata_provider_type &provider = pDisp->ProviderOf<this_type>();
            nested_type_metadata_chain_type &chain = ChainFrom<this_type>();
            boost::shared_ptr<this_type> pType = chain.NewObject<this_type>(provider);
            pType->SetGenericArguments(genericArgs);
            return pType;
        }

        boost::shared_ptr<method_metadata_type const> GetMethod(std::wstring const &name, 
                                                                CallingConventions const &callingConvention, 
                                                                boost::shared_ptr<base_type const> const &pRetType, 
                                                                std::vector<boost::shared_ptr<base_type const> > const &paramTypes) const
        {
            boost::shared_ptr<method_metadata_type> pMethod;
            pMethod = NewMethod(name, callingConvention, pRetType, paramTypes);

            boost::shared_ptr<method_metadata_type> pExistingMethod;
            if (!TryGetMethod(*pMethod, pExistingMethod))
            {
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                method_metadata_provider_type &provider = pDisp->ProviderOf<method_metadata_type>();
                m_methodToIndex[pMethod] = provider.Register(pMethod);
                return pMethod;
            }
            else
            {
                return pExistingMethod;
            }
        }

    private:
        friend typename module_metadata_type;

        void SetName(std::wstring const &name)
        {
            _ASSERTE(!name.empty());
            _ASSERTE(m_name.empty());
            m_name = name;
        }

        void SetToken(mdToken mdt)
        {
            _ASSERTE(!IsNilToken(mdt));
            _ASSERTE(m_mdt == mdTokenNil);
            m_mdt = mdt;
        }

        void SetGenericArguments(std::vector<boost::shared_ptr<base_type const> > const &genericArgs)
        {
            _ASSERTE(!m_genericArgsInit);
            _ASSERTE(genericArgs.size() != 0);
            m_genericArgs = genericArgs;
            m_genericArgsInit = true;
        }

        boost::shared_ptr<method_metadata_type> NewMethod(std::wstring const &name, 
                                                          CallingConventions const &callingConvention, 
                                                          boost::shared_ptr<base_type const> const &pRetType, 
                                                          std::vector<boost::shared_ptr<base_type const> > const &paramTypes) const
        {
            boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
            method_metadata_provider_type &provider = pDisp->ProviderOf<method_metadata_type>();
            boost::shared_ptr<method_metadata_type> pMethod = NewObjectFirst<method_metadata_type>(provider);
            pMethod->SetName(name);
            pMethod->SetCallingConvention(callingConvention);
            pMethod->SetReturnType(pRetType);
            pMethod->SetParameterTypes(paramTypes);
            return pMethod;
        }

        bool TryGetMethod(method_metadata_type const &keyMethod, boost::shared_ptr<method_metadata_type> &pExistingMethod) const
        {
            boost::shared_ptr<method_metadata_type const> pKeyMethod(&keyMethod, Utilities::MakeNullDeleter(&keyMethod));
            if (m_methodToIndex.find(pKeyMethod) == m_methodToIndex.end())
            {
                return false;
            }
            else
            {
                size_t index = m_methodToIndex[pKeyMethod];
                boost::shared_ptr<metadata_dispenser_type const> pDisp = MapFirst<metadata_dispenser_type>();
                method_metadata_provider_type &provider = pDisp->ProviderOf<method_metadata_type>();
                pExistingMethod = provider[index];
                return true;
            }
        }

        void FillPropertiesIfNecessary() const
        {
            if (m_filled)
                return;

            this_type *pMutableThis = const_cast<this_type *>(this);

            boost::shared_ptr<module_metadata_type> pMod = MapFirst<module_metadata_type>();
            boost::shared_ptr<assembly_metadata_type> pAsm = pMod->MapFirst<assembly_metadata_type>();

            com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

            mdToken mdtTarget = GetToken();
            if (TypeFromToken(mdtTarget) == mdtTypeRef)
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }
            else if (TypeFromToken(mdtTarget) == mdtTypeDef)
            {
                WCHAR name[MAX_SYM_NAME] = { 0 };
                ULONG nameSize = sizeof(name);
                DWORD attr = 0;
                mdToken mdtExt = mdTokenNil;
                HRESULT hr = comMetaImp.GetTypeDefProps(mdtTarget, name, nameSize, 
                                                        &nameSize, &attr, &mdtExt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

                m_name = name;
                if (!IsNilToken(mdtExt) && 
                    (TypeFromToken(mdtExt) == mdtTypeDef ||
                     TypeFromToken(mdtExt) == mdtTypeRef))
                {
                    m_pBaseType = pMod->NewType(mdtExt);
                }
                else if (!IsNilToken(mdtExt))
                {
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                }
            }
            else
            {
                BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
            }


            m_filled = true;
        }

        TypeKinds const &GetKind() const
        {
            using Interfaces::MetadataSpecialValues;

            if (!m_kindInitialized)
            {
                std::wstring const &name = GetName();
                if (name == MetadataSpecialValues::TYPE_NAME_OF_VOID) m_kind = TypeKinds::TK_VOID;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_BOOLEAN) m_kind = TypeKinds::TK_BOOLEAN;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_CHAR) m_kind = TypeKinds::TK_CHAR;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_SBYTE) m_kind = TypeKinds::TK_I1;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_BYTE) m_kind = TypeKinds::TK_U1;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT16) m_kind = TypeKinds::TK_I2;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT16) m_kind = TypeKinds::TK_U2;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT32) m_kind = TypeKinds::TK_I4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT32) m_kind = TypeKinds::TK_U4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INT64) m_kind = TypeKinds::TK_I8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_UINT64) m_kind = TypeKinds::TK_U8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_SINGLE) m_kind = TypeKinds::TK_R4;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_DOUBLE) m_kind = TypeKinds::TK_R8;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_STRING) m_kind = TypeKinds::TK_STRING;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_INTPTR) m_kind = TypeKinds::TK_I;
                else if (name == MetadataSpecialValues::TYPE_NAME_OF_OBJECT) m_kind = TypeKinds::TK_OBJECT;
                else
                {
                    if (name.find(MetadataSpecialValues::GENERIC_TYPE_IDENTIFIER) != std::wstring::npos)
                    {
                        m_kind = TypeKinds::TK_GENERICINST;
                    }
                    else
                    {
                        boost::shared_ptr<base_type const> pBaseType = GetBaseType();
                        if (pBaseType && pBaseType->GetName() == MetadataSpecialValues::TYPE_NAME_OF_VALUETYPE)
                        {
                            m_kind = TypeKinds::TK_VALUETYPE;
                        }
                        else
                        {
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        }
                    }
                }

                m_kindInitialized = true;
            }
            return m_kind;
        }

        static void PushBackSignatures(std::vector<COR_SIGNATURE> &sigs, this_type const &this_)
        {
            TypeKinds const &typeKind = this_.GetKind();
            switch (typeKind.Value())
            {
                case TypeKinds::TK_VOID:
                case TypeKinds::TK_I:
                case TypeKinds::TK_OBJECT:
                case TypeKinds::TK_STRING:
                    sigs.push_back(typeKind.Value());
                    break;

                case TypeKinds::TK_VALUETYPE:
                    sigs.push_back(typeKind.Value());
                    {
                        BYTE pData[4] = { 0 };
                        ULONG length = ::CorSigCompressToken(this_.GetToken(), pData);
                        for (BYTE const *i = pData, *i_end = i + length; i != i_end; ++i)
                            sigs.push_back(*i);
                    }
                    break;

                case TypeKinds::TK_GENERICINST:
                    sigs.push_back(typeKind.Value());
                    {
                    }
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;

                default:
                    BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    break;
            }
        }

        mutable std::wstring m_name;
        mutable boost::shared_ptr<base_type const> m_pBaseType;
        mutable mdToken m_mdt;
        mutable bool m_genericArgsInit;
        mutable bool m_kindInitialized;
        mutable TypeKinds m_kind;
        mutable std::vector<COR_SIGNATURE> m_sigs;
        mutable std::vector<boost::shared_ptr<base_type const> > m_genericArgs;
        mutable boost::unordered_map<boost::shared_ptr<method_metadata_type const>, 
                                     size_t, 
                                     i_method_metadata_hash_type, 
                                     i_method_metadata_equal_to_type> m_methodToIndex;        
        mutable bool m_filled;
    };





    template<class ApiCartridgesHolder, class ApiLabel>
    struct MethodMetadata5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::MethodMetadata5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class MethodMetadata5B4288A9ApiHolder
    >    
    class BaseMethodMetadata5B4288A9 : 
        public SmartPtrChain<
            BaseMethodMetadata5B4288A9<MethodMetadata5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, Interfaces::TypeMetadata5B4288A9Label>::type>
            >
        >,
        public MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9Label>::type,
        public SimpleDisposable
    {
    public:
        typedef BaseMethodMetadata5B4288A9<MethodMetadata5B4288A9ApiHolder> this_type;
        typedef typename MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, Interfaces::IMethodMetadata5B4288A9Label>::type base_type;

        typedef typename MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, Interfaces::AssemblyMetadata5B4288A9Label>::type assembly_metadata_type;
        typedef typename MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, Interfaces::TypeMetadata5B4288A9Label>::type type_metadata_type;
        typedef typename MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, Interfaces::ITypeMetadata5B4288A9Label>::type i_type_metadata_type;
        typedef typename MethodMetadata5B4288A9ApiAt<MethodMetadata5B4288A9ApiHolder, IMetaDataImport2>::type com_meta_data_import_type;        
        
        BaseMethodMetadata5B4288A9() : 
            m_mdt(mdTokenNil),
            m_callingConvention(CallingConventions::CC_NO_VALUE),
            m_retTypeInitialized(false), 
            m_paramTypesInitialized(false)
        { }

        mdToken GetToken() const
        {
            if (m_mdt == mdTokenNil)
            {
                _ASSERTE(!m_name.empty());

                SimpleBlob sig;

                _ASSERTE(m_callingConvention != CallingConventions::CC_NO_VALUE);
                SignatureUtil::PutSignatures(sig, m_callingConvention);

                _ASSERTE(m_paramTypesInitialized);
                sig.Put<COR_SIGNATURE>(m_paramTypes.size());

                _ASSERTE(m_retTypeInitialized);
                SignatureUtil::PutSignatures(sig, *m_pRetType);

                typedef std::vector<boost::shared_ptr<typename base_type::i_type_metadata_type const> >::const_iterator ConstIterator;
                for (ConstIterator ci = m_paramTypes.cbegin(), ci_end = m_paramTypes.cend(); ci != ci_end; ++ci)
                    SignatureUtil::PutSignatures(sig, **ci);

                this_type *pMutableThis = const_cast<this_type *>(this);

                boost::shared_ptr<assembly_metadata_type> pAsm = MapFirst<assembly_metadata_type>();
                boost::shared_ptr<type_metadata_type> pType = MapFirst<type_metadata_type>();
                
                com_meta_data_import_type &comMetaImp = pAsm->GetCOMMetaDataImport();

                HRESULT hr = comMetaImp.FindMethod(pType->GetToken(), m_name.c_str(), 
                                                   sig.Ptr(), sig.Size(), &m_mdt);
                if (FAILED(hr))
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return m_mdt;
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
            if (!m_retTypeInitialized)
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
            return MapFirst<type_metadata_type>();
        }

    private:
        friend typename type_metadata_type;

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

        void SetReturnType(boost::shared_ptr<i_type_metadata_type const> const &pRetType)
        {
            _ASSERTE(!m_retTypeInitialized);
            m_pRetType = pRetType;
            m_retTypeInitialized = true;
        }

        void SetParameterTypes(std::vector<boost::shared_ptr<i_type_metadata_type const> > const &paramTypes)
        {
            _ASSERTE(!m_paramTypesInitialized);
            m_paramTypes = paramTypes;
            m_paramTypesInitialized = true;
        }

        mutable mdToken m_mdt;
        std::wstring m_name;
        CallingConventions m_callingConvention;
        bool m_retTypeInitialized; 
        boost::shared_ptr<i_type_metadata_type const> m_pRetType;
        bool m_paramTypesInitialized; 
        std::vector<boost::shared_ptr<i_type_metadata_type const> > m_paramTypes;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Hosting::Interfaces;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;

        struct DefaultFusionInfo5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<RuntimeHost5B4288A9Label, RuntimeHost5B4288A9>,
                pair<AssemblyInfo5B4288A9Label, AssemblyInfo5B4288A9>,
                pair<IAssemblyCache, IAssemblyCache>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultFusionInfo5B4288A9ApiHolder : 
        Detail::DefaultFusionInfo5B4288A9ApiHolderImpl
    {
    };





    namespace Detail {
        
        using namespace boost::mpl;
        using namespace Urasandesu::CppAnonym::Fusion::Interfaces;

        struct DefaultAssemblyInfo5B4288A9ApiHolderImpl
        {
            typedef map<
                pair<FusionInfo5B4288A9Label, FusionInfo5B4288A9>
            > api_cartridges;
        };

    }   // namespace Detail {

    struct DefaultAssemblyInfo5B4288A9ApiHolder : 
        Detail::DefaultAssemblyInfo5B4288A9ApiHolderImpl
    {
    };

}}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion { namespace ApiHolders {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct FusionInfo5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::FusionInfo5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FusionInfo5B4288A9ApiHolder
    >    
    class BaseFusionInfo5B4288A9 : 
        public SmartPtrChain<
            BaseFusionInfo5B4288A9<FusionInfo5B4288A9ApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename FusionInfo5B4288A9ApiAt<FusionInfo5B4288A9ApiHolder, Hosting::Interfaces::RuntimeHost5B4288A9Label>::type>
            >
        >,
        SmartHeapProvider<
            boost::mpl::vector<
                typename FusionInfo5B4288A9ApiAt<FusionInfo5B4288A9ApiHolder, Interfaces::AssemblyInfo5B4288A9Label>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseFusionInfo5B4288A9<FusionInfo5B4288A9ApiHolder> this_type;
        
        typedef typename FusionInfo5B4288A9ApiAt<FusionInfo5B4288A9ApiHolder, Hosting::Interfaces::RuntimeHost5B4288A9Label>::type runtime_host_type;
        typedef typename FusionInfo5B4288A9ApiAt<FusionInfo5B4288A9ApiHolder, Interfaces::AssemblyInfo5B4288A9Label>::type assembly_info_type;
        typedef typename FusionInfo5B4288A9ApiAt<FusionInfo5B4288A9ApiHolder, IAssemblyCache>::type com_assembly_cache_type;

        typedef typename provider_of<assembly_info_type>::type assembly_info_provider_type;

        BaseFusionInfo5B4288A9()
        { }

        boost::shared_ptr<assembly_info_type> QueryAssemblyInfo(
                  AssemblyQueryTypes const &type, std::wstring const &assemblyName) const
        {
            using namespace boost::filesystem;

            this_type *pMutableThis = const_cast<this_type *>(this);

            WCHAR buffer[MAX_PATH] = { 0 };
            ASSEMBLY_INFO asmInfo;
            ::ZeroMemory(&asmInfo, sizeof(ASSEMBLY_INFO));
            asmInfo.cbAssemblyInfo = sizeof(ASSEMBLY_INFO);
            asmInfo.pszCurrentAssemblyPathBuf = buffer;
            asmInfo.cchBuf = MAX_PATH;
            HRESULT hr = pMutableThis->GetCOMAssemblyCache().QueryAssemblyInfo(type.Value(), assemblyName.c_str(), &asmInfo);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            ULONGLONG assemblySizeInKB = 0;
            ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), 
                       &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

            assembly_info_provider_type &provider = ProviderOf<assembly_info_type>();
            boost::shared_ptr<assembly_info_type> pAsmInfo = provider.NewObject();
            pAsmInfo->SetAssemblySizeInKB(assemblySizeInKB);
            pAsmInfo->SetAssemblyPath(asmInfo.pszCurrentAssemblyPathBuf);
            return pAsmInfo;
        }

    private:
        friend typename runtime_host_type;

        void Init(boost::weak_ptr<runtime_host_type> const &pRuntimeAsScope) const
        {
            _ASSERTE(m_pRuntimeAsScope.use_count() == 0);
            m_pRuntimeAsScope = pRuntimeAsScope;
        }

        void SetThis(boost::weak_ptr<this_type> const &pThis) const
        {
            _ASSERTE(m_pThis.use_count() == 0);
            m_pThis = pThis;
        }

        void SetVersion(std::wstring const &version)
        {
            _ASSERTE(!version.empty());
            _ASSERTE(m_version.empty());
            m_version = version;
        }

        com_assembly_cache_type &GetCOMAssemblyCache()
        {
            using namespace boost::filesystem;
            
            if (m_pComAsmCache.p == NULL)
            {
                boost::shared_ptr<runtime_host_type> pRuntimeHost = MapFirst<runtime_host_type>();

                path const &corSysDirPath = pRuntimeHost->GetCORSystemDirectoryPath();
                path fusionPath = corSysDirPath;
                fusionPath /= L"fusion.dll";

                HMODULE hmodCorEE = ::LoadLibraryW(fusionPath.c_str());
                if (hmodCorEE == NULL)
                    BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
                BOOST_SCOPE_EXIT((hmodCorEE))
                {
                    ::FreeLibrary(hmodCorEE);
                }
                BOOST_SCOPE_EXIT_END

                typedef HRESULT (__stdcall *CreateAsmCachePtr)(IAssemblyCache **ppAsmCache, DWORD dwReserved);

                CreateAsmCachePtr pfnCreateAsmCache = NULL;
                pfnCreateAsmCache = reinterpret_cast<CreateAsmCachePtr>(
                                                ::GetProcAddress(hmodCorEE, "CreateAssemblyCache"));
                if (!pfnCreateAsmCache)
                    BOOST_THROW_EXCEPTION(CppAnonymSystemException(::GetLastError()));
        
                HRESULT hr = pfnCreateAsmCache(&m_pComAsmCache, 0);
                if (FAILED(hr)) 
                    BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
            }
            return *m_pComAsmCache;
        }
        
        mutable boost::weak_ptr<runtime_host_type> m_pRuntimeAsScope;
        mutable boost::weak_ptr<this_type> m_pThis;
        std::wstring m_version;
        mutable ATL::CComPtr<com_assembly_cache_type> m_pComAsmCache;
    };

    
    
    
    
    template<class ApiCartridgesHolder, class ApiLabel>
    struct AssemblyInfo5B4288A9ApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::AssemblyInfo5B4288A9ApiHolderLabel, ApiLabel>
    {
    };

    template<
        class AssemblyInfo5B4288A9ApiHolder
    >    
    class BaseAssemblyInfo5B4288A9
    {
    public:
        typedef BaseAssemblyInfo5B4288A9<AssemblyInfo5B4288A9ApiHolder> this_type;

        typedef typename AssemblyInfo5B4288A9ApiAt<AssemblyInfo5B4288A9ApiHolder, Interfaces::FusionInfo5B4288A9Label>::type fusion_info_type;

        BaseAssemblyInfo5B4288A9() :
            m_assemblySizeInKB(0)
        { }
        
        ULONGLONG GetAssemblySizeInKB() const 
        { 
            return m_assemblySizeInKB; 
        }
        
        boost::filesystem::path const &GetAssemblyPath() const 
        { 
            return m_assemblyPath; 
        }

    private:
        friend typename fusion_info_type;

        void SetAssemblySizeInKB(ULONGLONG assemblySizeInKB)
        { 
            m_assemblySizeInKB = assemblySizeInKB; 
        }
        
        void SetAssemblyPath(boost::filesystem::path const &assemblyPath)
        { 
            m_assemblyPath = assemblyPath; 
        }

        ULONGLONG m_assemblySizeInKB;
        boost::filesystem::path m_assemblyPath;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test2.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Test2, Test_01)
    {
        namespace mpl = boost::mpl;
        using boost::shared_ptr;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Metadata;
        using namespace Urasandesu::CppAnonym::StrongNaming;

        typedef HostInfo5B4288A9 HostInfo;
        typedef RuntimeHost5B4288A9 RuntimeHost;
        typedef MetadataInfo5B4288A9 MetadataInfo;
        typedef MetadataDispenser5B4288A9 MetadataDispenser;
        typedef AssemblyMetadata5B4288A9 AssemblyMetadata;
        typedef ModuleMetadata5B4288A9 ModuleMetadata;
        typedef ITypeMetadata5B4288A9 ITypeMetadata;
        typedef TypeMetadata5B4288A9 TypeMetadata;
        typedef MethodMetadata5B4288A9 MethodMetadata;

        shared_ptr<HostInfo const> pHostInfo = HostInfo::NewHost();

        shared_ptr<RuntimeHost const> pRuntimeHost = pHostInfo->GetRuntime(L"v2.0.50727");
        ASSERT_TRUE(pRuntimeHost);

        shared_ptr<MetadataInfo const> pMetaInfo = pRuntimeHost->Map<MetadataInfo>();
        ASSERT_TRUE(pMetaInfo);

        shared_ptr<MetadataDispenser> pMetaDisp = pMetaInfo->CreateDispenser();
        ASSERT_TRUE(pMetaDisp);

        shared_ptr<AssemblyMetadata const> pSystemCore;
        pSystemCore = pMetaDisp->GetAssembly(L"System.Core, Version=3.5.0.0, Culture=neutral, " 
                                             L"PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        ASSERT_EQ(0x20000001, pSystemCore->GetToken());
        
        shared_ptr<AssemblyMetadata const> pMSCorLib;
        pMSCorLib = pMetaDisp->GetAssembly(L"mscorlib, Version=2.0.0.0, Culture=neutral, " 
                                           L"PublicKeyToken=b77a5c561934e089, processorArchitecture=x86");
        ASSERT_EQ(0x20000001, pMSCorLib->GetToken());   // !! CAUTION: This is CORRECT !!

        shared_ptr<ModuleMetadata const> pSystemCoreModule = pSystemCore->GetModule(L"System.Core.dll");
        ASSERT_EQ(0x00000001, pSystemCoreModule->GetToken());
        
        shared_ptr<ModuleMetadata const> pMSCorLibModule = pMSCorLib->GetModule(L"CommonLanguageRuntimeLibrary");
        ASSERT_EQ(0x00000001, pMSCorLibModule->GetToken());

        shared_ptr<TypeMetadata const> pVoid = pMSCorLibModule->GetType(L"System.Void");
        ASSERT_EQ(0x02000125, pVoid->GetToken());

        shared_ptr<TypeMetadata const> pObject = pMSCorLibModule->GetType(L"System.Object");
        ASSERT_EQ(0x02000002, pObject->GetToken());

        shared_ptr<TypeMetadata const> pIntPtr = pMSCorLibModule->GetType(L"System.IntPtr");
        ASSERT_EQ(0x020000C5, pIntPtr->GetToken());

        shared_ptr<TypeMetadata const> pDateTime = pMSCorLibModule->GetType(L"System.DateTime");
        ASSERT_EQ(0x02000032, pDateTime->GetToken());

        shared_ptr<TypeMetadata const> pFunc1 = pSystemCoreModule->GetType(L"System.Func`1");
        ASSERT_TRUE(pFunc1->IsGenericType());
        ASSERT_TRUE(pFunc1->IsGenericTypeDefinition());
        {
            std::vector<shared_ptr<ITypeMetadata const> > const &genericArgs = pFunc1->GetGenericArguments();
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
        }
        ASSERT_EQ(0x02000058, pFunc1->GetToken());

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
#if 0
#endif
    }


}
