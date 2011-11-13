// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 一部の CString コンストラクタは明示的です。

#include <atlbase.h>
#include <atlstr.h>

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#import "libid:E21F0F69-633F-45E2-BF2E-0EB2D6F2CE6B" version("1.0") no_namespace // CppAnonym 1.0 タイプ ライブラリ

#ifndef URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H
#include <Urasandesu/CppAnonym/CppAnonymDependsOn.h>
#endif

#include <gtest/gtest.h>
