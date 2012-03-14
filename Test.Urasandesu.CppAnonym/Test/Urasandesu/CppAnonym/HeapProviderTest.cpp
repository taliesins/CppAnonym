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

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTFUSIONINFOAPIPROTO3CBCB74B_H
#include <Urasandesu/CppAnonym/Fusion/DefaultFusionInfoApiProto3CBCB74B.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoProto3CBCB74B.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTHOSTINFOAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultHostInfoApiProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_DEFAULTRUNTIMEHOSTAPIPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/DefaultRuntimeHostApiProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEHOSTINFOPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseHostInfoProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASERUNTIMEHOSTPROTO07F03042_H
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostProto07F03042.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_BASEMETADATAINFOPROTOB8DF5A21_H
#include <Urasandesu/CppAnonym/Metadata/BaseMetadataInfoProtoB8DF5A21.h>
#endif

#ifndef URASANDESU_CPPANONYM_STRONGNAMING_BASESTRONGNAMEINFOPROTO4236D495_H
#include <Urasandesu/CppAnonym/StrongNaming/BaseStrongNameInfoProto4236D495.h>
#endif

namespace Urasandesu { namespace CppAnonym { 

}}   // namespace Urasandesu { namespace CppAnonym { 

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace StrongNaming {

namespace Urasandesu { namespace CppAnonym { namespace Hosting {


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
