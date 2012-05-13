#include "stdafx.h"

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
