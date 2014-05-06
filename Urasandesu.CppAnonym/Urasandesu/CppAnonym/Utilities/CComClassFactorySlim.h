/* 
 * File: CComClassFactorySlim.h
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
#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMCLASSFACTORYSLIM_H
#define URASANDESU_CPPANONYM_UTILITIES_CCOMCLASSFACTORYSLIM_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMCLASSFACTORYSLIMFWD_H
#include <Urasandesu/CppAnonym/Utilities/CComClassFactorySlimFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace CComClassFactorySlimDetail {

        using ATL::CComObjectRootEx;
        using ATL::CComGlobalsThreadModel;
        using ATL::CComPtr;
        using boost::shared_ptr;

        
        
        class CComClassFactorySlim : 
            public IClassFactory,
            public CComObjectRootEx<CComGlobalsThreadModel>
        {
        public: 
            CComClassFactorySlim() { }
            virtual ~CComClassFactorySlim() { }

            BEGIN_COM_MAP(CComClassFactorySlim)
                COM_INTERFACE_ENTRY(IClassFactory)
            END_COM_MAP()

            HRESULT Initialize(REFCLSID rclsid);

            STDMETHOD(CreateInstance)(IUnknown *pUnkOuter, REFIID riid, void **ppvObject)
            {
                return m_pComClassFactory->CreateInstance(pUnkOuter, riid, ppvObject);
            }
        
            STDMETHOD(LockServer)(BOOL fLock)
            {
                return m_pComClassFactory->LockServer(fLock);
            }

        private:
            shared_ptr<HINSTANCE__> m_hmodComDll;
            CComPtr<IClassFactory> m_pComClassFactory;
        };
        
        
        
        template<REFCLSID RCLSID>
        class CComClassFactorySlimT : 
            public CComClassFactorySlim
        {
        public:
            CComClassFactorySlimT() { }
            virtual ~CComClassFactorySlimT() { }

            HRESULT FinalConstruct()
            {
                return CComClassFactorySlim::Initialize(RCLSID);
            }
        };

    }   // namespace CComClassFactorySlimDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMCLASSFACTORYSLIM_H
