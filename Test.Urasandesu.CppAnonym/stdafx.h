// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 一部の CString コンストラクターは明示的です。

#include <atlbase.h>
#include <atlstr.h>

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#ifndef URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H
#include <Urasandesu/CppAnonym/CppAnonymDependsOn.h>
#endif

#include <boost/mpl/vector.hpp>
#include <boost/timer.hpp>
#include <gtest/gtest.h>

#include <mscoree.h>
#include <boost/mpl/for_each.hpp>
#include <fusion.h>
