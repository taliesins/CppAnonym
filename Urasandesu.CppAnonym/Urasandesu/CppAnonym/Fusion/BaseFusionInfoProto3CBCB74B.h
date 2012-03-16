#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H
#define URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Hosting {

    template<
        class HostInfoApiType
    >
    class BaseRuntimeHostProto07F03042;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Hosting {

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    namespace AssemblyQueryTypes {

        enum Types;

    } // QueryAssemblyTypes

    class AssemblyInfo;

    struct DefaultFusionInfoApiProto3CBCB74B;


    template<
        class FusionInfoApiType = DefaultFusionInfoApiProto3CBCB74B
    >    
    class BaseFusionInfoProto3CBCB74B : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef Hosting::BaseRuntimeHostProto07F03042<
                    typename FusionInfoApiType::runtime_host_api_type> runtime_host_type;

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

        boost::shared_ptr<AssemblyInfo> QueryAssemblyInfo(
                  AssemblyQueryTypes::Types type, std::wstring const &assemblyName) const
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
            ::memcpy_s(&assemblySizeInKB, sizeof(ULONGLONG), 
                       &asmInfo.uliAssemblySizeInKB, sizeof(ULARGE_INTEGER));

            return boost::make_shared<AssemblyInfo>(assemblySizeInKB, 
                                                    asmInfo.pszCurrentAssemblyPathBuf);
        }

    private:
        runtime_host_type const *m_pRuntimeHost;
        ATL::CComPtr<IAssemblyCache> m_pAsmCache;
    };

    typedef BaseFusionInfoProto3CBCB74B<> FusionInfoProto3CBCB74B;
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOPROTO3CBCB74B_H