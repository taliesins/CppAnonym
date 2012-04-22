// Test.Urasandesu.CppAnonym.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_METADATA_OPCODEKIND_H
#include <Urasandesu/CppAnonym/Metadata/OpCodeKind.h>
#endif

//#ifndef URASANDESU_CPPANONYM_METADATA_STACKBEHAVIOUR_H
//#include <Urasandesu/CppAnonym/Metadata/StackBehaviour.h>
//#endif

// Test.Urasandesu.CppAnonym.exe --gtest_filter=Urasandesu_CppAnonym_Test.*
namespace {

    TEST(Urasandesu_CppAnonym_Test, Test_01)
    {
        using namespace Urasandesu::CppAnonym::Metadata;
        OperandParam const &param = OperandParams::InlineBrTarget;
        //SUCCEED();
    }
}
