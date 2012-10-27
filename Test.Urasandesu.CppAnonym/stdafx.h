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
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/transform_view.hpp>

#include <boost/intrusive_ptr.hpp>
#include <boost/detail/atomic_count.hpp>
#include <boost/unordered_set.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/variant.hpp>

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

template<class Tag, INT Index>
class AtomicCounter : 
    boost::noncopyable
{
public:
    static AtomicCounter &Instance() { static AtomicCounter ac; return ac; }
    INT operator++() { return ++m_count; }
    INT operator--() { return --m_count; }
    INT Value() { return m_count; }
private:
    AtomicCounter() : m_count(0) { }
    ~AtomicCounter() { }
    boost::detail::atomic_count m_count;
};

template<class Tag, INT Index>
struct BasicCounter
{
    typedef AtomicCounter<Tag, Index> counter;
    static counter &Instance() { return counter::Instance(); }
};

template<class Counter>
struct SurvivalCounter : 
    Counter
{
    SurvivalCounter() { ++Instance(); }
    ~SurvivalCounter() { --Instance(); }
};

template<class T1, class Counter>
struct CounterWithValue1 : 
    Counter
{
    CounterWithValue1() : m_value() { }
    CounterWithValue1(T1 value) : m_value(value) { }
    T1 m_value;
};

template<class Counter>
struct ActionCouner : 
    Counter
{
    template<class T>
    void operator()(T obj)
    {
        ++Instance();
    }
};

template<class A1, class Counter>
class CounterWithAction1 : 
    public Counter
{
public:
    CounterWithAction1() : m_action() { }
    CounterWithAction1(A1 action) : m_action(action) { }
    template<class T>
    void operator()(T obj)
    {
        Counter::operator()(obj);
        m_action(obj);
    }
private:
    A1 m_action;
};


//#ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
//#include <Urasandesu/CppAnonym/DefaultSTDMETHODWrapper.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
//#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_ENVIRONMENT_H
//#include <Urasandesu/CppAnonym/Environment.h>
//#endif
//
////#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
////#include <Urasandesu/CppAnonym/HeapProvider.hpp>
////#endif
//
////#ifndef URASANDESU_CPPANONYM_IAPIOPERABLE_H
////#include <Urasandesu/CppAnonym/IApiOperable.h>
////#endif
//
////#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
////#include <Urasandesu/CppAnonym/IHeapContent.h>
////#endif
//
//#ifndef URASANDESU_CPPANONYM_IDISPOSABLE_HPP
//#include <Urasandesu/CppAnonym/IDisposable.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
//#include <Urasandesu/CppAnonym/ObjectTag.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP
//#include <Urasandesu/CppAnonym/PersistentInfo.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/PersistableHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
//#include <Urasandesu/CppAnonym/SafeEnum.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
//#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_H
//#include <Urasandesu/CppAnonym/SimpleHeap.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H
//#include <Urasandesu/CppAnonym/SmartPtrChainMapper.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
//#include <Urasandesu/CppAnonym/SmartPtrChainConstructor.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
//#include <Urasandesu/CppAnonym/SmartPtrChainInfo.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
//#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
//#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_DISPOSINGINFO_H
//#include <Urasandesu/CppAnonym/DisposingInfo.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_H
//#include <Urasandesu/CppAnonym/DisposableHeapProvider.h>
//#endif

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include <Urasandesu/CppAnonym/StackTrace.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

//#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
//#include <Urasandesu/CppAnonym/SimpleDisposable.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SYSTEMERROR_H
//#include <Urasandesu/CppAnonym/SystemError.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_H
//#include <Urasandesu/CppAnonym/SmartPtrChain.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
//#endif

//#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
//#endif

//#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymObjectDisposedException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H
//#include <Urasandesu/CppAnonym/CppAnonymInvalidOperationException.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_COLLECTIONS_GLOBALSAFEDICTIONARY_H
//#include <Urasandesu/CppAnonym/Collections/GlobalSafeDictionary.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
//#include <Urasandesu/CppAnonym/Collections/Iterable.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_COLLECTIONS_RAPIDVECTOR_H
//#include <Urasandesu/CppAnonym/Collections/RapidVector.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_CARTRIDGEAPISYSTEM_H
//#include <Urasandesu/CppAnonym/Traits/CartridgeApiSystem.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_HASCONST_H
//#include <Urasandesu/CppAnonym/Traits/HasConst.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
//#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_REPLACE_H
//#include <Urasandesu/CppAnonym/Traits/Replace.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_DISTINCT_H
//#include <Urasandesu/CppAnonym/Traits/Distinct.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
//#include <Urasandesu/CppAnonym/Traits/EqualityComparable.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_HASHCOMPUTABLE_H
//#include <Urasandesu/CppAnonym/Traits/HashComputable.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_ISLIKEPOINTER_H
//#include <Urasandesu/CppAnonym/Traits/IsLikePointer.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEPOINTERHOLDERIMPL_H
//#include <Urasandesu/CppAnonym/Traits/MakePointerHolderImpl.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPPOINTERHOLDERIMPL_H
//#include <Urasandesu/CppAnonym/Traits/MakeHeapPointerHolderImpl.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEVALUEHOLDERIMPL_H
//#include <Urasandesu/CppAnonym/Traits/MakeValueHolderImpl.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_MAKEHEAPVALUEHOLDERIMPL_H
//#include <Urasandesu/CppAnonym/Traits/MakeHeapValueHolderImpl.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_MAXSIZETYPE_H
//#include <Urasandesu/CppAnonym/Traits/MaxSizeType.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_PREDICATABLE_H
//#include <Urasandesu/CppAnonym/Traits/Predicatable.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERTYPE_H
//#include <Urasandesu/CppAnonym/Traits/HasMemberType.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_GETMEMBERTYPE_H
//#include <Urasandesu/CppAnonym/Traits/GetMemberType.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_TRAITS_HASMEMBERFUNCTION_H
//#include <Urasandesu/CppAnonym/Traits/HasMemberFunction.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_ANYPTR_H
//#include <Urasandesu/CppAnonym/Utilities/AnyPtr.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP
//#include <Urasandesu/CppAnonym/Utilities/AssignationDistributor.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_ISANYT_HPP
//#include <Urasandesu/CppAnonym/Utilities/IsAnyT.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_HPP
//#include <Urasandesu/CppAnonym/Utilities/CComObjectSlim.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP
//#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributor.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
//#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
//#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicy.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
//#include <Urasandesu/CppAnonym/Utilities/DestructionDistributor.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_HPP
//#include <Urasandesu/CppAnonym/Utilities/EqualTo.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_NULLDELETER_HPP
//#include <Urasandesu/CppAnonym/Utilities/NullDeleter.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_HPP
//#include <Urasandesu/CppAnonym/Utilities/Hash.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_HEAPDELETER_HPP
//#include <Urasandesu/CppAnonym/Utilities/HeapDeleter.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP
//#include <Urasandesu/CppAnonym/Utilities/StackAllocator.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_AUTOPTR_HXX
//#include <Urasandesu/CppAnonym/Utilities/AutoPtr.hxx>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_HPP
//#include <Urasandesu/CppAnonym/Utilities/TypeInfo.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTR_HPP
//#include <Urasandesu/CppAnonym/Utilities/SemiAutoPtr.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPPTR_HPP
//#include <Urasandesu/CppAnonym/Utilities/TempPtr.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTR_HPP
//#include <Urasandesu/CppAnonym/Utilities/VariantPtr.hpp>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
//#include <Urasandesu/CppAnonym/Metadata/CallingConventions.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_METADATA_TYPEKINDS_H
//#include <Urasandesu/CppAnonym/Metadata/TypeKinds.h>
//#endif
//
//#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYQUERYTYPES_H
//#include <Urasandesu/CppAnonym/Fusion/AssemblyQueryTypes.h>
//#endif

//#ifndef URASANDESU_CPPANONYM_BASECPPANONYMSTORAGE_HXX
//#include <Urasandesu/CppAnonym/BaseCppAnonymStorage.hxx>
//#endif
