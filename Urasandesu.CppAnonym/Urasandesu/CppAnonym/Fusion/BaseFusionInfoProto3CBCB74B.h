#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H
#define URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    struct IRuntimeHostApi;

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Traits {

    template<class ApiType, class IApiType>
    struct ParentApiOrDefault;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Traits {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    namespace Detail {

        struct AssemblyQueryTypesDef
        {
            enum type
            {
                AQT_DEFAULT = 0,
                AQT_VALIDATE = QUERYASMINFO_FLAG_VALIDATE, 
                AQT_GET_SIZE = QUERYASMINFO_FLAG_GETSIZE,
                AQT_UNREACHED
            };
        };

    }   // Detail

    typedef SafeEnum<Detail::AssemblyQueryTypesDef> AssemblyQueryTypes;

    class AssemblyInfo;

    struct DefaultFusionInfoApiProto3CBCB74B;


    template<
        class FusionInfoApiType = DefaultFusionInfoApiProto3CBCB74B
    >    
    class BaseFusionInfoProto3CBCB74B : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef typename Traits::ParentApiOrDefault<FusionInfoApiType, Hosting::IRuntimeHostApi>::type runtime_host_api_type;
        typedef Hosting::BaseRuntimeHostProto07F03042<runtime_host_api_type> runtime_host_type;

        BaseFusionInfoProto3CBCB74B() : 
            m_pRuntimeHost(NULL)
        { }

        void Init(runtime_host_type &runtimeHost) const
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
        
            HRESULT hr = pfnCreateAsmCache(&m_pAsmCacheApi, 0);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        }

        boost::shared_ptr<AssemblyInfo> QueryAssemblyInfo(
                  AssemblyQueryTypes const &type, std::wstring const &assemblyName) const
        {
            using namespace boost::filesystem;

            WCHAR buffer[MAX_PATH] = { 0 };
            ASSEMBLY_INFO asmInfo;
            ::ZeroMemory(&asmInfo, sizeof(ASSEMBLY_INFO));
            asmInfo.cbAssemblyInfo = sizeof(ASSEMBLY_INFO);
            asmInfo.pszCurrentAssemblyPathBuf = buffer;
            asmInfo.cchBuf = MAX_PATH;
            HRESULT hr = m_pAsmCacheApi->QueryAssemblyInfo(type.Value(), assemblyName.c_str(), &asmInfo);
            if (FAILED(hr)) 
                BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

            ULONGLONG assemblySizeInKB = 0;
            ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), 
                       &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

            return boost::make_shared<AssemblyInfo>(assemblySizeInKB, 
                                                    asmInfo.pszCurrentAssemblyPathBuf);
        }

    private:
        mutable runtime_host_type *m_pRuntimeHost;
        mutable ATL::CComPtr<IAssemblyCache> m_pAsmCacheApi;
    };

    typedef BaseFusionInfoProto3CBCB74B<> FusionInfoProto3CBCB74B;
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H