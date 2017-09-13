/* 
 * File: CComObjectSlimTest.cpp
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

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Utilities_CComObjectSlimTest.*
namespace {

    TEST(Urasandesu_CppAnonym_Utilities_CComObjectSlimTest, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Utilities;
        
        typedef std::vector<VARIANT> VariantVector;
        typedef ATL::_Copy<VARIANT> VariantCopy;
        typedef ATL::CComEnumOnSTL<IEnumVARIANT, &__uuidof(IEnumVARIANT), VARIANT, VariantCopy, VariantVector> VariantEnumerator;
        typedef CComObjectSlim<VariantEnumerator> VariantEnumeratorObject;

        VariantEnumeratorObject *pVarEnum_ = NULL;
        ASSERT_HRESULT_SUCCEEDED(VariantEnumeratorObject::CreateInstance(&pVarEnum_)); 
        ATL::CComPtr<IEnumVARIANT> pVarEnum = pVarEnum_; 
    }
}
