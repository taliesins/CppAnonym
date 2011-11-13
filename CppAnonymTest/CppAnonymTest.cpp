// CppAnonymTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

namespace {

    // CppAnonymTest.exe --gtest_filter=CppAnonymTestSuite.CppAnonymTest
    TEST(CppAnonymTestSuite, CppAnonymTest)
    {
        SUCCEED();
    }
}
