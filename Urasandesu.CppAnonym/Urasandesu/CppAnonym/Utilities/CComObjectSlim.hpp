/* 
 * File: CComObjectSlim.hpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


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
