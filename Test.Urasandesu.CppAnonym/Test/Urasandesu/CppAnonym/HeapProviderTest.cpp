#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_H
#include <Urasandesu/CppAnonym/HeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
#include <Urasandesu/CppAnonym/Traits/Replace.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

namespace Urasandesu { namespace CppAnonym { 

    // TODO: .h ‚Æ .cpp ‚É•ª—£
    class CppAnonymArgumentException : 
        public CppAnonymException
    {
    public:
        CppAnonymArgumentException() : 
            CppAnonymException()
        {
        }

        CppAnonymArgumentException(std::string const &what) : 
            CppAnonymException(what)
        {
        }

        CppAnonymArgumentException(std::wstring const &what) : 
            CppAnonymException(what)
        {
        }

        CppAnonymArgumentException(std::string const &what, std::string const &paramName) : 
            CppAnonymException(what)
        {
            AppendMessage(m_what, paramName);
        }

        CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName) : 
            CppAnonymException(what)
        {
            AppendMessage(m_what, paramName);
        }

        CppAnonymArgumentException(std::string const &what, CppAnonymException &innerException) : 
            CppAnonymException(what, innerException)
        {
        }

        CppAnonymArgumentException(std::wstring const &what, CppAnonymException &innerException) : 
            CppAnonymException(what, innerException)
        {
        }

        CppAnonymArgumentException(std::string const &what, std::string const &paramName, CppAnonymException &innerException) : 
            CppAnonymException(what, innerException)
        {
            AppendMessage(m_what, paramName);
        }

        CppAnonymArgumentException(std::wstring const &what, std::wstring const &paramName, CppAnonymException &innerException) : 
            CppAnonymException(what, innerException)
        {
            AppendMessage(m_what, paramName);
        }

    private:
        static void AppendMessage(std::string &what, std::wstring const &paramName)
        {
            AppendMessage(what, std::string(ATL::CW2A(paramName.c_str())));
        }

        static void AppendMessage(std::string &what, std::string const &paramName)
        {
            what += "\r\n";
            what += "Parameter Name: ";
            what += paramName;
        }
    };


    // TODO: .h ‚Æ .cpp ‚É•ª—£
    struct CppAnonymNotSupportedException : CppAnonymException
    {
        CppAnonymNotSupportedException() : 
            CppAnonymException()
        { }

        CppAnonymNotSupportedException(std::string const &what) : 
            CppAnonymException(what)
        { }

        CppAnonymNotSupportedException(std::wstring const &what) : 
            CppAnonymException(what)
        { }

        CppAnonymNotSupportedException(std::string const &what, CppAnonymException &innerException) : 
            CppAnonymException(what, innerException)
        { }

        CppAnonymNotSupportedException(std::wstring const &what, CppAnonymException &innerException) : 
            CppAnonymException(what, innerException)
        { }
    };

}}   // namespace Urasandesu { namespace CppAnonym { 

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class InfoHostingApiType
    >
    class BaseRuntimeHostProto07F03042;

    struct DefaultInfoHostingApi;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    struct DefaultInfoFusionApi
    {
        typedef Hosting::DefaultInfoHostingApi info_hosting_api_type;
    };

    namespace Detail {

        template<
            class InfoFusionApiType = boost::use_default
        >    
        struct InfoFusionApiTraitProto3CBCB74B
        {
            typedef typename Traits::Replace<InfoFusionApiType, boost::use_default, 
                                 DefaultInfoFusionApi>::type info_fusion_api_type;
            typedef typename boost::mpl::eval_if<
                                boost::is_same<InfoFusionApiType, boost::use_default>, 
                                boost::mpl::identity<boost::use_default>, 
                                boost::mpl::identity<typename info_fusion_api_type::info_hosting_api_type> >::type info_hosting_api_type;
        };

    }   // namespace Detail

    class AssemblyInfo
    {
    //ULONG cbAssemblyInfo;
    //DWORD dwAssemblyFlags;
    //ULARGE_INTEGER uliAssemblySizeInKB;
    //LPWSTR pszCurrentAssemblyPathBuf;
    //ULONG cchBuf;
    public:
        AssemblyInfo(ULONGLONG assemblySizeInKB, boost::filesystem::path const &assemblyPath) :
            m_assemblySizeInKB(assemblySizeInKB), 
            m_assemblyPath(assemblyPath)
        { }

        inline ULONGLONG GetAssemblySizeInKB() const { return m_assemblySizeInKB; }
        inline boost::filesystem::path const &GetAssemblyPath() const { return m_assemblyPath; }

    private:
        ULONGLONG m_assemblySizeInKB;
        boost::filesystem::path m_assemblyPath;
    };

    namespace AssemblyQueryTypes {

        enum Types
        {
            Default = 0,
            Validate = QUERYASMINFO_FLAG_VALIDATE, 
            GetSize = QUERYASMINFO_FLAG_GETSIZE
        };

    } // QueryAssemblyTypes



    template<
        class InfoFusionApiType = boost::use_default
    >    
    class BaseFusionInfoProto3CBCB74B : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef Detail::InfoFusionApiTraitProto3CBCB74B<InfoFusionApiType> trait_type;
        typedef Hosting::BaseRuntimeHostProto07F03042<typename trait_type::info_hosting_api_type> runtime_host_type;

        BaseFusionInfoProto3CBCB74B() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type const &runtimeHost)
        {
            using namespace boost::filesystem;
            _ASSERTE(m_pRuntimeHost == NULL);
            
            m_pRuntimeHost = &runtimeHost;
            path const &corSystemDirectoryPath = m_pRuntimeHost->GetCORSystemDirectoryPath();
            path fusionPath = corSystemDirectoryPath;
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
        
            HRESULT hr = pfnCreateAsmCache(&m_pAsmCache, 0);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

        AssemblyInfo QueryAssemblyInfo(AssemblyQueryTypes::Types type, std::wstring const &assemblyName) const
        {
            using namespace boost::filesystem;

            WCHAR buffer[MAX_PATH] = { 0 };
            ASSEMBLY_INFO asmInfo;
            ::ZeroMemory(&asmInfo, sizeof(ASSEMBLY_INFO));
            asmInfo.cbAssemblyInfo = sizeof(ASSEMBLY_INFO);
            asmInfo.pszCurrentAssemblyPathBuf = buffer;
            asmInfo.cchBuf = MAX_PATH;
            HRESULT hr = m_pAsmCache->QueryAssemblyInfo(type, assemblyName.c_str(), &asmInfo);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            ULONGLONG assemblySizeInKB = 0;
            ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

            return AssemblyInfo(assemblySizeInKB, asmInfo.pszCurrentAssemblyPathBuf);
        }

    private:
        runtime_host_type const *m_pRuntimeHost;
        ATL::CComPtr<IAssemblyCache> m_pAsmCache;
    };

    typedef BaseFusionInfoProto3CBCB74B<> FusionInfoProto3CBCB74B;
    
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class InfoMetadataApiType = boost::use_default
    >    
    class BaseMetadataInfoProtoB8DF5A21 :
        public IHeapContent<std::wstring>
    {
    };

    typedef BaseMetadataInfoProtoB8DF5A21<> MetadataInfoProtoB8DF5A21;


}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

    template<
        class InfoStrongNamingApiType = boost::use_default
    >    
    class BaseStrongNameInfoProto4236D495 : 
        public IHeapContent<std::wstring>
    {
    };

    typedef BaseStrongNameInfoProto4236D495<> StrongNameInfoProto4236D495;
    

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct DefaultInfoHostingApi
    {
        typedef INT info_strong_naming_api_type;
        typedef INT info_metadata_api_type;
        typedef Fusion::DefaultInfoFusionApi info_fusion_api_type;
    };

    namespace Detail {

        template<
            class InfoHostingApiType = boost::use_default
        >    
        struct InfoHostingApiTraitProto07F03042
        {
            typedef typename Traits::Replace<InfoHostingApiType, boost::use_default, 
                                 DefaultInfoHostingApi>::type info_hosting_api_type_type;
            typedef typename info_hosting_api_type_type::info_strong_naming_api_type info_strong_naming_api_type;
            typedef typename info_hosting_api_type_type::info_metadata_api_type info_metadata_api_type;
            typedef typename boost::mpl::eval_if<
                                boost::is_same<InfoHostingApiType, boost::use_default>, 
                                boost::mpl::identity<boost::use_default>, 
                                boost::mpl::identity<typename info_hosting_api_type_type::info_fusion_api_type> >::type info_fusion_api_type;
        };

    }   // namespace Detail

    template<
        class InfoHostingApiType
    >    
    class BaseHostInfoProto07F03042;



    template<
        class InfoHostingApiType = boost::use_default
    >
    class BaseRuntimeHostProto07F03042 : 
        public IHeapContent<std::wstring>, 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                StrongNaming::BaseStrongNameInfoProto4236D495<typename Detail::InfoHostingApiTraitProto07F03042<InfoHostingApiType>::info_strong_naming_api_type>, 
                Metadata::BaseMetadataInfoProtoB8DF5A21<typename Detail::InfoHostingApiTraitProto07F03042<InfoHostingApiType>::info_metadata_api_type>, 
                Fusion::BaseFusionInfoProto3CBCB74B<typename Detail::InfoHostingApiTraitProto07F03042<InfoHostingApiType>::info_fusion_api_type>
            >
        >
    {
    public:
        typedef BaseRuntimeHostProto07F03042<InfoHostingApiType> this_type;
        typedef Detail::InfoHostingApiTraitProto07F03042<InfoHostingApiType> trait_type;
        typedef StrongNaming::BaseStrongNameInfoProto4236D495<typename trait_type::info_strong_naming_api_type> strong_name_info_type;
        typedef typename type_decided_by<strong_name_info_type>::type strong_name_info_heap_type;
        typedef Fusion::BaseFusionInfoProto3CBCB74B<typename trait_type::info_fusion_api_type> fusion_info_type;
        typedef typename type_decided_by<fusion_info_type>::type fusion_info_heap_type;

        BaseRuntimeHostProto07F03042() : 
            m_corVersionInitialized(false), 
            m_corSystemDirectoryPathInitialized(false)
        {
            namespace mpl = boost::mpl;
            mpl::for_each<sequence_type>(m_infosInitializer(m_infos));
        }

        template<class InfoType>
        InfoType const *GetInfo() const
        {
            namespace mpl = boost::mpl;
            using namespace boost;
            
            typedef mpl::find<sequence_type, InfoType>::type i;
            typedef mpl::end<sequence_type>::type i_end;
            BOOST_MPL_ASSERT((mpl::not_<boost::is_same<i, i_end> >));

            typedef typename type_decided_by<InfoType>::type info_heap_type;
            LPCSTR infoTypeName = typeid(InfoType).name();
            InfoType *pInfo = static_cast<InfoType *>(m_infos[infoTypeName]);
            if (pInfo == NULL)
            {
                info_heap_type &infoHeap = const_cast<this_type *>(this)->Of<InfoType>();
                pInfo = infoHeap.New(GetCORVersion());
                pInfo->Init(*this);
                m_infos[infoTypeName] = pInfo;
            }

            return pInfo;
        }
        
        std::wstring const &GetCORVersion() const
        {
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
            using namespace boost::filesystem;

            if (!m_corSystemDirectoryPathInitialized)
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

                m_corSystemDirectoryPath = buffer;
                
                m_corSystemDirectoryPathInitialized = true;
            }
            return m_corSystemDirectoryPath;
        }
    
    private:
        mutable boost::unordered_map<std::string, void *> m_infos;
        
        class m_infosInitializer
        {
        public:
            m_infosInitializer(boost::unordered_map<std::string, void *> &infos) : 
                m_pInfos(&infos)
            { }

            template<typename T> 
            void operator()(T _)
            {
                (*m_pInfos)[typeid(T).name()] = NULL;
            }

        private:
            boost::unordered_map<std::string, void *> *m_pInfos;
        };

        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSystemDirectoryPathInitialized;
        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

    typedef BaseRuntimeHostProto07F03042<> RuntimeHostProto07F03042;

    template<
        class InfoHostingApiType = boost::use_default
    >    
    class BaseHostInfoProto07F03042 : 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                BaseRuntimeHostProto07F03042<InfoHostingApiType> 
            > 
        >
    {
    public:
        typedef BaseHostInfoProto07F03042<InfoHostingApiType> this_type;
        typedef BaseRuntimeHostProto07F03042<InfoHostingApiType> runtime_host_type;
        typedef typename type_decided_by<runtime_host_type>::type runtime_host_heap_type;

        runtime_host_type const *GetRuntime(std::wstring const &version) const
        {
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            runtime_host_heap_type const &heap = Of<runtime_host_type>();
            if (heap.Exists(version))
            {
                return heap.Get(version);
            }
            else
            {
                runtime_host_heap_type *pHeap = const_cast<runtime_host_heap_type *>(&heap);
                runtime_host_type const *pRuntimeHost = pHeap->NewPseudo();

                std::wstring const &corVersion = pRuntimeHost->GetCORVersion();
                if (corVersion != version)
                {
                    BOOST_SCOPE_EXIT((pHeap))
                    {
                        pHeap->DeleteLast();
                    }
                    BOOST_SCOPE_EXIT_END

                    std::wstring what;
                    what += L"The version '";
                    what += version;
                    what += L"' is not supported. For your information, this process runs at version '";
                    what += corVersion;
                    what += L"'.";
                    BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException(what));
                }

                pHeap->SetToLast(version);
                return pRuntimeHost;
            }
        }
    };

    typedef BaseHostInfoProto07F03042<> HostInfoProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {


// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_HeapProviderTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Hosting_BaseHostInfoTest, Test_01)
    {
        namespace fs = boost::filesystem;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Hosting;
        using namespace Urasandesu::CppAnonym::Fusion;

        HostInfoProto07F03042 info;
        typedef HostInfoProto07F03042::runtime_host_type RuntimeHost;
        RuntimeHost const *pRuntimeHost = info.GetRuntime(L"v2.0.50727");
        RuntimeHost const *pRuntimeHost2 = info.GetRuntime(L"v2.0.50727");
        ASSERT_EQ(pRuntimeHost, pRuntimeHost2); 

        fs::path const &corSystemDirectoryPath = pRuntimeHost->GetCORSystemDirectoryPath();
        ASSERT_STREQ(L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\", corSystemDirectoryPath.c_str());

        typedef RuntimeHost::fusion_info_type FusionInfo;
        FusionInfo const *pFuInfo = pRuntimeHost->GetInfo<FusionInfo>();
        ASSERT_FALSE(pFuInfo == NULL);

        FusionInfo const *pFuInfo2 = pRuntimeHost->GetInfo<FusionInfo>();
        ASSERT_EQ(pFuInfo, pFuInfo2);

        std::wstring assemblyName(L"System.Core, Version=3.5.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089, processorArchitecture=MSIL");
        AssemblyInfo asmInfo = pFuInfo->QueryAssemblyInfo(AssemblyQueryTypes::GetSize, assemblyName);
        fs::path expected(L"C:\\Windows\\assembly\\GAC_MSIL\\System.Core\\3.5.0.0__b77a5c561934e089\\System.Core.dll");
        ASSERT_TRUE(fs::equivalent(expected, asmInfo.GetAssemblyPath()));
        ASSERT_EQ(652, asmInfo.GetAssemblySizeInKB());

        std::cout << "";
        //ULONGLONG src = 2147483648;
        //ULARGE_INTEGER l;
        //::ZeroMemory(&l, sizeof(ULARGE_INTEGER));
        //::memcpy_s(&l, sizeof(ULARGE_INTEGER), &src, sizeof(ULONGLONG));

        //std::cout << l << std::endl;
        //std::cout << ll << std::endl;
    }

    struct A : 
        Urasandesu::CppAnonym::IHeapContent<INT>
    {
        INT m_value;
    };

    struct B : 
        Urasandesu::CppAnonym::IHeapContent<INT>
    {
        ULONG m_value;
    };

    TEST(Urasandesu_CppAnonym_HeapProviderTest, DefaultPathTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef HeapProvider<INT, mpl::vector<A, B> > MyHeapProvider;

        MyHeapProvider heap;
        MyHeapProvider::type_decided_by<A>::type &aHeap = heap.Of<A>();
        A *pA = aHeap.New(0);
        pA->m_value = 10;
        ASSERT_EQ(aHeap.Get(0), pA);
        ASSERT_EQ(10, aHeap.Get(0)->m_value);
        ASSERT_EQ(1, aHeap.Size());
        ASSERT_TRUE(aHeap.Exists(0)); 
        ASSERT_FALSE(aHeap.Exists(1)); 

        MyHeapProvider::type_decided_by<B>::type &bHeap = heap.Of<B>();
        B *pB = bHeap.New(1);
        pB->m_value = 20;
        ASSERT_EQ(bHeap.Get(1), pB);
        ASSERT_EQ(20, bHeap.Get(1)->m_value);
        ASSERT_EQ(1, bHeap.Size());
        ASSERT_TRUE(bHeap.Exists(1)); 
        ASSERT_FALSE(bHeap.Exists(0)); 

        MyHeapProvider const &cHeap = heap;
        MyHeapProvider::type_decided_by<A>::type const &caHeap = cHeap.Of<A>();
        A const *pcA = caHeap.Get(0);
        ASSERT_EQ(caHeap.Get(0), pcA);
        ASSERT_EQ(10, caHeap.Get(0)->m_value);
        ASSERT_EQ(1, caHeap.Size());
        ASSERT_TRUE(caHeap.Exists(0)); 
        ASSERT_FALSE(caHeap.Exists(1)); 
    }


    TEST(Urasandesu_CppAnonym_HeapProviderTest, TypeConceptTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef HeapProvider<INT, mpl::vector<INT, DOUBLE> > MyHeapProvider;

        // This declaration doesn't work because contents of boost::mpl::vector don't 
        // implement necessary interface Urasandesu::CppAnonym::IHeapContent.
        //MyHeapProvider heap;  // error C2664
    }

    TEST(Urasandesu_CppAnonym_CppAnonymArgumentExceptionTest, Test_01)
    {
        using namespace std;
        using namespace boost;
        using namespace Urasandesu::CppAnonym;
        
        try
        {
            BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"hoge", L"paramName"));
        }
        catch (CppAnonymException &e)
        {
            string msg = diagnostic_information(e);
            cout << msg << endl;
            string expectContaining = "paramName";
            ASSERT_TRUE(msg.find(expectContaining) != string::npos);
        }
    }

    TEST(Urasandesu_CppAnonym_HeapProviderTest, DeleteTest_01)
    {
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;

        typedef HeapProvider<INT, mpl::vector<A, B> > MyHeapProvider;

        MyHeapProvider heap;
        MyHeapProvider::type_decided_by<A>::type &aHeap = heap.Of<A>();
        A *pA = aHeap.New(0);
        ASSERT_EQ(1, aHeap.Size());
        ASSERT_TRUE(aHeap.Exists(0)); 

        aHeap.DeleteLast();
        ASSERT_EQ(0, aHeap.Size());
        ASSERT_FALSE(aHeap.Exists(0)); 

        
        MyHeapProvider::type_decided_by<B>::type &bHeap = heap.Of<B>();
        B *pB = bHeap.New(0);
        ASSERT_EQ(1, bHeap.Size());
        ASSERT_TRUE(bHeap.Exists(0)); 

        bHeap.DeleteLast();
        ASSERT_EQ(0, bHeap.Size());
        ASSERT_FALSE(bHeap.Exists(0)); 
    }
}
