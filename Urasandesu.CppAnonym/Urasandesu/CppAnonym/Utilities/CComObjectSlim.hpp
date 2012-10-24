#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#define URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_H
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class Base>
    HRESULT CComObjectSlim<Base>::CreateInstance(this_type **ppObj)
    {
        if (ppObj == NULL) 
            return E_POINTER;
        *ppObj = NULL;

        HRESULT hr = E_FAIL;
        std::auto_ptr<this_type> pObj(new this_type());

        pObj->SetVoid(NULL);                    // Declared in CComObjectRootBase.
        pObj->InternalFinalConstructAddRef();   // Declared in user class DECLARE_PROTECT_FINAL_CONSTRUCT.

        hr = pObj->_AtlInitialConstruct();      // Declared in CComObjectRootEx.
        if (FAILED(hr)) 
            return hr;

        hr = pObj->FinalConstruct();            // Declared in user class.
        if (FAILED(hr)) 
            return hr;

        hr = pObj->_AtlFinalConstruct();        // Declared in CComObjectRootBase.
        pObj->InternalFinalConstructRelease();  // Declared in user class DECLARE_PROTECT_FINAL_CONSTRUCT.

        *ppObj = pObj.release();
        return S_OK;
    }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP