// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#ifndef URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H
#include <Urasandesu/CppAnonym/CppAnonymDependsOn.h>
#endif

#include <boost/timer.hpp>
#include <gtest/gtest.h>

#include <boost/foreach.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/range/algorithm_ext.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/transform_view.hpp>

#include <boost/intrusive_ptr.hpp>
#include <boost/detail/atomic_count.hpp>
#include <boost/unordered_set.hpp>
#include <boost/weak_ptr.hpp>

#define CPPANONYM_TEST(test_case_name, test_name) \
    class GTEST_TEST_CLASS_NAME_(test_case_name, test_name); \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)); \
    TEST(test_case_name, test_name) \
    { \
        using namespace Urasandesu::CppAnonym; \
        try \
        { \
            CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name)()); \
        } \
        catch (CppAnonymException &e) \
        { \
            std::cout << boost::diagnostic_information(e) << std::endl; \
            throw; \
        } \
        catch (...) \
        { \
            std::cout << boost::diagnostic_information(boost::current_exception()) << std::endl; \
            throw; \
        } \
    } \
    void CppAnonymTest(GTEST_TEST_CLASS_NAME_(test_case_name, test_name))

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_HPP
#include <Urasandesu/CppAnonym/ObjectTag.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#include <Urasandesu/CppAnonym/Collections/Iterable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP
#include <Urasandesu/CppAnonym/Utilities/StackAllocator.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_HPP
#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
#include <Urasandesu/CppAnonym/Traits/Distinct.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/HasMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_HPP
#include <Urasandesu/CppAnonym/Traits/GetMemberType.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_HPP
#include <Urasandesu/CppAnonym/Utilities/TypeInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYQUERYTYPES_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyQueryTypes.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainMapper.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainConstructor.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/DisposableHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymObjectDisposedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymInvalidOperationException.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_NULLDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/NullDeleter.hpp>
#endif


