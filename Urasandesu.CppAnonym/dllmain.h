// dllmain.h : モジュール クラスの宣言

class CUrasandesuCppAnonymModule : public ATL::CAtlDllModuleT< CUrasandesuCppAnonymModule >
{
public :
	DECLARE_LIBID(LIBID_UrasandesuCppAnonymLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_URASANDESUCPPANONYM, "{952E50F0-63E1-404D-8FFD-0EDA53D3C1C6}")
};

extern class CUrasandesuCppAnonymModule _AtlModule;
