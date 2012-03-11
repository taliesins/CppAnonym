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

#include <mscoree.h>

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
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

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<
        class InfoFusionApiType = boost::use_default
    >    
    class BaseFusionInfoProto3CBCB74B : 
        public IHeapContent<std::wstring>
    {
    };

    typedef BaseFusionInfoProto3CBCB74B<> FusionInfoProto3CBCB74B;
    
}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    template<
        class InfoMetadataApiType = boost::use_default,
        class AssemblyMetadataApiType = boost::use_default
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

    struct DefaultInfoHostingApi;

    namespace Detail {

        template<
            class InfoHostingApiType = boost::use_default
        >    
        struct InfoHostingApiTraitProto07F03042
        {
            typedef typename Traits::Replace<InfoHostingApiType, boost::use_default, 
                                 DefaultInfoHostingApi>::type info_hosting_api_type_type;
        };

    }   // namespace Detail

    template<
        class InfoHostingApiType,
        class InfoStrongNamingApiType,
        class InfoMetadataApiType,
        class AssemblyMetadataApiType, 
        class InfoFusionApiType
    >    
    class BaseHostInfoProto07F03042;



    template<
        class InfoHostingApiType = boost::use_default,
        class InfoStrongNamingApiType = boost::use_default,
        class InfoMetadataApiType = boost::use_default,
        class AssemblyMetadataApiType = boost::use_default, 
        class InfoFusionApiType = boost::use_default
    >
    class BaseRuntimeHostProto07F03042 : 
        public IHeapContent<std::wstring>, 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                StrongNaming::BaseStrongNameInfoProto4236D495<InfoStrongNamingApiType>, 
                Metadata::BaseMetadataInfoProtoB8DF5A21<InfoMetadataApiType, AssemblyMetadataApiType>, 
                Fusion::BaseFusionInfoProto3CBCB74B<InfoFusionApiType>
            >
        >
    {
    public:
        BaseRuntimeHostProto07F03042() : 
            m_corVersionInitialized(false), 
            m_corSystemDirectoryPathInitialized(false)
        { }
        
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
        mutable bool m_corVersionInitialized;
        mutable std::wstring m_corVersion;
        mutable bool m_corSystemDirectoryPathInitialized;
        mutable boost::filesystem::path m_corSystemDirectoryPath;
    };

    typedef BaseRuntimeHostProto07F03042<> RuntimeHostProto07F03042;

    //template<
    //    class InfoHostingApiType = boost::use_default
    //>
    //class BaseRuntimeHost : 
    //    public IMetadataApiOperable<
    //        BaseAssemblyMetadata<AssemblyMetadataApiType>, 
    //        typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type
    //    >
    //{

    //template<
    //    class InfoMetadataApiType = boost::use_default,
    //    class AssemblyMetadataApiType = boost::use_default
    //>    
    //class BaseMetadataInfo
    //{
    //public:
    //    typedef typename UNT::Replace<InfoMetadataApiType, boost::use_default, DefaultInfoMetadataApi>::type info_meta_data_api_type;
    //    typedef typename UNT::Replace<AssemblyMetadataApiType, boost::use_default, DefaultAssemblyMetadataApi>::type assembly_meta_data_api_type;

    template<
        class InfoHostingApiType = boost::use_default,      // TODO: EEE‚Á‚Ä‚¢‚¤‚©A‚±‚±‚àŠK‘w\‘¢‚É‚Å‚«‚é‚ñ‚¶‚á‚ËH
        class InfoStrongNamingApiType = boost::use_default,
        class InfoMetadataApiType = boost::use_default,     // TODO: ‚±‚±ŠK‘w\‘¢‚É‚·‚é
        class AssemblyMetadataApiType = boost::use_default, 
        class InfoFusionApiType = boost::use_default
    >    
    class BaseHostInfoProto07F03042 : 
        public HeapProvider<
            std::wstring, 
            boost::mpl::vector<
                BaseRuntimeHostProto07F03042<
                    InfoHostingApiType, 
                    InfoStrongNamingApiType, 
                    InfoMetadataApiType, 
                    AssemblyMetadataApiType, 
                    InfoFusionApiType
                > 
            > 
        >
    {
    public:
        typedef BaseRuntimeHostProto07F03042<InfoHostingApiType, 
                                             InfoStrongNamingApiType, 
                                             InfoMetadataApiType, 
                                             AssemblyMetadataApiType, 
                                             InfoFusionApiType> runtime_host_type;
        typedef typename type_decided_by<runtime_host_type>::type runtime_host_heap_type;

        runtime_host_type *GetRuntime(const std::wstring &version)
        {
            if (version.empty())
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(L"The parameter must be non-empty.", L"version"));

            runtime_host_heap_type &heap = Of<runtime_host_type>();
            runtime_host_type *pRuntimeHost = heap.NewPseudo();

            std::wstring const &corVersion = pRuntimeHost->GetCORVersion();
            if (corVersion != version)
            {
                BOOST_SCOPE_EXIT((&heap))
                {
                    heap.DeleteLast();
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

            heap.SetToLast(version);
            return pRuntimeHost;
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

        HostInfoProto07F03042 info;
        typedef HostInfoProto07F03042::runtime_host_type RuntimeHost;
        RuntimeHost const *pRuntimeHost = info.GetRuntime(L"v2.0.50727");

        fs::path const &corSystemDirectoryPath = pRuntimeHost->GetCORSystemDirectoryPath();
        ASSERT_STREQ(L"C:\\Windows\\Microsoft.NET\\Framework\\v2.0.50727\\", corSystemDirectoryPath.c_str());
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
