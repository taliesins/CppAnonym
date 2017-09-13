/* 
 * File: CComClassFactorySlimTest.cpp
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
#include <gtest/gtest.h>

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMCLASSFACTORYSLIM_H
#include <Urasandesu/CppAnonym/Utilities/CComClassFactorySlim.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
#endif

#include <cor.h>
#include <corprof.h>

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_CComClassFactorySlimTest.*
namespace {

    CPPANONYM_TEST(Urasandesu_CppAnonym_Utilities_CComClassFactorySlimTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        using ATL::CComPtr;
        using std::wstring;

        {
            typedef CComClassFactorySlimT<CLSID_CorMetaDataDispenser> MetaDataDispenserClassFactory;
            typedef CComObjectSlim<MetaDataDispenserClassFactory> MetaDataDispenserClassFactoryObject;

            auto *pComMetaDispFactory = static_cast<MetaDataDispenserClassFactoryObject *>(nullptr);
            ASSERT_HRESULT_SUCCEEDED(MetaDataDispenserClassFactoryObject::CreateInstance(&pComMetaDispFactory)); 
            auto m_pComMetaDispFactory = CComPtr<IClassFactory>(pComMetaDispFactory);

            auto pComMetaDisp = CComPtr<IMetaDataDispenserEx>();
            ASSERT_HRESULT_SUCCEEDED(m_pComMetaDispFactory->CreateInstance(nullptr, IID_IMetaDataDispenserEx, reinterpret_cast<void **>(&pComMetaDisp)));
            // S_OK
        }

        {
            auto strExtProf = wstring(L"{532C1F05-F8F3-4FBA-8724-699A31756ABD}");   // see https://github.com/urasandesu/Prig/blob/master/Urasandesu.Prig/UrasandesuPrig.idl
            auto extProf = IID();
            ::IIDFromString(strExtProf.c_str(), &extProf);

            typedef CComObjectSlim<CComClassFactorySlim> ExternalProfilerClassFactoryObject;

            auto *pComExtProfFactory = static_cast<ExternalProfilerClassFactoryObject *>(nullptr);
            ASSERT_HRESULT_SUCCEEDED(ExternalProfilerClassFactoryObject::CreateInstance(&pComExtProfFactory));
            ASSERT_HRESULT_SUCCEEDED(pComExtProfFactory->Initialize(extProf));
            auto m_pComExtProfFactory = CComPtr<IClassFactory>(pComExtProfFactory);

            auto m_pComProfExtCallback = CComPtr<ICorProfilerCallback>();
            ASSERT_HRESULT_SUCCEEDED(m_pComExtProfFactory->CreateInstance(nullptr, IID_ICorProfilerCallback, reinterpret_cast<void **>(&m_pComProfExtCallback)));
            // S_OK
        }

        {
            auto pComMetaDisp = CComPtr<IMetaDataDispenserEx>();
            ASSERT_HRESULT_FAILED(::CoCreateInstance(CLSID_CorMetaDataDispenser, NULL, CLSCTX_INPROC_SERVER, IID_IMetaDataDispenserEx, reinterpret_cast<void **>(&pComMetaDisp)));
            // CO_E_NOTINITIALIZED: CoInitialize has not been called. 
        }
    }
}
