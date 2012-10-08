#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#define URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYQUERYTYPES_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyQueryTypes.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEMFWD_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystemFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_BASERUNTIMEHOSTFWD_HPP
#include <Urasandesu/CppAnonym/Hosting/BaseRuntimeHostFwd.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_APIHOLDERS_DEFAULTFUSIONINFOAPIHOLDERFWD_H
#include <Urasandesu/CppAnonym/Fusion/ApiHolders/DefaultFusionInfoApiHolderFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFOFWD_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfoFwd.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFOFWD_HPP
#include <Urasandesu/CppAnonym/Fusion/BaseFusionInfoFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    template<class ApiCartridgesHolder, class ApiLabel>
    struct FusionInfoApiAt : 
        Traits::ApiAt<ApiCartridgesHolder, Interfaces::FusionInfoApiHolderLabel, ApiLabel>
    {
    };

    template<
        class FusionInfoApiHolder
    >    
    class BaseFusionInfo : 
        public IHeapContent<std::wstring>
    {
    public:
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;

        BaseFusionInfo() : 
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
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP