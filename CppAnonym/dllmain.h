// dllmain.h : モジュール クラスの宣言

class CCppAnonymModule : public ATL::CAtlDllModuleT< CCppAnonymModule >
{
public :
	DECLARE_LIBID(LIBID_CppAnonymLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CPPANONYM, "{744CBF35-B24F-4EAC-B473-45CA44F4981E}")
};

extern class CCppAnonymModule _AtlModule;
