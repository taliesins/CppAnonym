
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_METADATA_DEFAULTINFOMETADATAAPI_H
#include <Urasandesu/CppAnonym/Metadata/DefaultInfoMetadataApi.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    HRESULT DefaultInfoMetadataApi::CoCreateInstance(REFCLSID rclsid, 
                                         LPUNKNOWN pUnkOuter,
                                         DWORD dwClsContext, 
                                         REFIID riid, 
                                         LPVOID FAR* ppv)
    {
        return ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
    }

    IID const DefaultInfoMetadataApi::CLSID_Dispenser = CLSID_CorMetadataDispenser;
    IID const DefaultInfoMetadataApi::IID_IDispenser = IID_IMetadataDispenserEx;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {
