/* 
 * File: CComClassFactorySlim.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMCLASSFACTORYSLIM_H
#include <Urasandesu/CppAnonym/Utilities/CComClassFactorySlim.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace CComClassFactorySlimDetail {

        HRESULT CComClassFactorySlim::Initialize(REFCLSID rclsid)
        {
            using boost::array;
            using std::vector;
            using std::wstring;

            auto strClsid = array<OLECHAR, 128>();
            ::StringFromGUID2(rclsid, strClsid.c_array(), static_cast<int>(strClsid.size()));

            auto key = boost::str(boost::wformat(L"CLSID\\%|1$s|\\InprocServer32") % strClsid.data());

            auto hKeyClassesRoot = HKEY();
            BOOST_SCOPE_EXIT((&hKeyClassesRoot))
            {
                if (hKeyClassesRoot)
                    ::RegCloseKey(hKeyClassesRoot);
            }
            BOOST_SCOPE_EXIT_END
            {
                auto result = ::RegOpenKeyExW(HKEY_CLASSES_ROOT, key.c_str(), 0, KEY_READ, &hKeyClassesRoot);
                if (result != ERROR_SUCCESS)
                    return HRESULT_FROM_WIN32(result);
            }

            auto comDllName = wstring();
            {
                auto length = 0ul;
                auto type = 0ul;
                auto result = ERROR_SUCCESS;
                result = ::RegQueryValueExW(hKeyClassesRoot, nullptr, nullptr, &type, nullptr, &length);
                if (result != ERROR_SUCCESS)
                    return HRESULT_FROM_WIN32(result);
                
                if (type != REG_SZ && type != REG_EXPAND_SZ)
                    return ERROR_FILE_NOT_FOUND;
                
                auto _comDllName = vector<WCHAR>();
                _comDllName.resize(length / sizeof(WCHAR));
                result = ::RegQueryValueExW(hKeyClassesRoot, nullptr, nullptr, &type, reinterpret_cast<BYTE *>(&_comDllName[0]), &length);
                if (result != ERROR_SUCCESS)
                    return HRESULT_FROM_WIN32(result);
                
                comDllName = &_comDllName[0];
            }

            {
                m_hmodComDll = shared_ptr<HINSTANCE__>(::LoadLibraryExW(comDllName.c_str(), nullptr, LOAD_WITH_ALTERED_SEARCH_PATH), &::FreeLibrary);
                if (!m_hmodComDll)
                    return HRESULT_FROM_WIN32(::GetLastError());

                typedef HRESULT (__stdcall *DllGetClassObjectPtr)(REFCLSID rclsid, REFIID riid, void **ppv);
                auto *pfnDllGetClassObject = reinterpret_cast<DllGetClassObjectPtr>(::GetProcAddress(m_hmodComDll.get(), "DllGetClassObject"));
                if (!pfnDllGetClassObject)
                    return HRESULT_FROM_WIN32(::GetLastError());
                    
                auto hr = pfnDllGetClassObject(rclsid, IID_IClassFactory, reinterpret_cast<void **>(&m_pComClassFactory));
                if (FAILED(hr)) 
                    return hr;
            }

            return S_OK;
        }

    }   // namespace CComClassFactorySlimDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {
