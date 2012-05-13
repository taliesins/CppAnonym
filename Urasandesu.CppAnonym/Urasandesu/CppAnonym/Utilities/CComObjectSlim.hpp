#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#define URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class Base>
    class CComObjectSlim : 
        public ATL::CComObjectNoLock<Base>
    {
    public:
        static HRESULT CreateInstance(CComObjectSlim<Base>** ppObj)
        {
            if (ppObj == NULL) 
                return E_POINTER;
            *ppObj = NULL;

            HRESULT hr = E_FAIL;
            std::auto_ptr<CComObjectSlim<Base>> pObj(new CComObjectSlim<Base>());

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
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP