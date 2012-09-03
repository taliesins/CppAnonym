#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP
#define URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_INTERFACES_FUSIONINFOAPIHOLDERLABEL_HPP
#include <Urasandesu/CppAnonym/Fusion/Interfaces/FusionInfoApiHolderLabel.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_HOSTING_INTERFACES_RUNTIMEHOSTLABEL_HPP
#include <Urasandesu/CppAnonym/Hosting/Interfaces/RuntimeHostLabel.hpp>
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
        public SmartPtrChain<
            BaseFusionInfo<FusionInfoApiHolder>,
            boost::mpl::vector<
                SmartPtrChainInfo<typename FusionInfoApiAt<FusionInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type>
            >
        >,
        SmartHeapProvider<
            boost::mpl::vector<
                typename FusionInfoApiAt<FusionInfoApiHolder, Interfaces::AssemblyInfoLabel>::type
            >
        >,
        public SimpleDisposable
    {
    public:
        typedef BaseFusionInfo<FusionInfoApiHolder> this_type;
        
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, Hosting::Interfaces::RuntimeHostLabel>::type runtime_host_type;
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, Interfaces::AssemblyInfoLabel>::type assembly_info_type;
        typedef typename FusionInfoApiAt<FusionInfoApiHolder, IAssemblyCache>::type com_assembly_cache_type;

        typedef typename provider_of<assembly_info_type>::type assembly_info_provider_type;

        BaseFusionInfo()
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

        //void Init(boost::weak_ptr<runtime_host_type> const &pRuntimeAsScope) const
        //{
        //    _ASSERTE(m_pRuntimeAsScope.use_count() == 0);
        //    m_pRuntimeAsScope = pRuntimeAsScope;
        //}

        //void SetThis(boost::weak_ptr<this_type> const &pThis) const
        //{
        //    _ASSERTE(m_pThis.use_count() == 0);
        //    m_pThis = pThis;
        //}

        //void SetVersion(std::wstring const &version)
        //{
        //    _ASSERTE(!version.empty());
        //    _ASSERTE(m_version.empty());
        //    m_version = version;
        //}

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
        
        //mutable boost::weak_ptr<runtime_host_type> m_pRuntimeAsScope;
        //mutable boost::weak_ptr<this_type> m_pThis;
        //std::wstring m_version;
        mutable ATL::CComPtr<com_assembly_cache_type> m_pComAsmCache;
    };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_BASEFUSIONINFO_HPP