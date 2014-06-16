/* 
 * File: CppAnonym.h
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


#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYM_H
#define URASANDESU_CPPANONYM_CPPANONYM_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H
#include <Urasandesu/CppAnonym/CppAnonymDependsOn.h>
#endif

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_H
#include <Urasandesu/CppAnonym/Collections.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_H
#include <Urasandesu/CppAnonym/Traits.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_H
#include <Urasandesu/CppAnonym/Utilities.h>
#endif

#ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
#include <Urasandesu/CppAnonym/DefaultSTDMETHODWrapper.h>
#endif

#ifndef URASANDESU_CPPANONYM_DEPENDENTOBJECTSPROVIDER_H
#include <Urasandesu/CppAnonym/DependentObjectsProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_ENVIRONMENT_H
#include <Urasandesu/CppAnonym/Environment.h>
#endif

#ifndef URASANDESU_CPPANONYM_HEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/HeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_IAPIOPERABLE_H
#include <Urasandesu/CppAnonym/IApiOperable.h>
#endif

#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#include <Urasandesu/CppAnonym/IHeapContent.h>
#endif

#ifndef URASANDESU_CPPANONYM_IDISPOSABLE_HPP
#include <Urasandesu/CppAnonym/IDisposable.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_LOG_H
#include "Urasandesu/CppAnonym/Log.h"
#endif

#ifndef URASANDESU_CPPANONYM_OBJECTTAG_H
#include <Urasandesu/CppAnonym/ObjectTag.h>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTENTINFO_HPP
#include <Urasandesu/CppAnonym/PersistentInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_PERSISTABLEHEAPPROVIDER_H
#include <Urasandesu/CppAnonym/PersistableHeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEFLAGSENUM_H
#include <Urasandesu/CppAnonym/SafeFlagsEnum.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_H
#include <Urasandesu/CppAnonym/SimpleBlob.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAP_HPP
#include <Urasandesu/CppAnonym/SimpleHeap.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SimpleHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINMAPPER_H
#include <Urasandesu/CppAnonym/SmartPtrChainMapper.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAINCONSTRUCTOR_H
#include <Urasandesu/CppAnonym/SmartPtrChainConstructor.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAININFO_HPP
#include <Urasandesu/CppAnonym/SmartPtrChainInfo.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTHEAPPROVIDER_HPP
#include <Urasandesu/CppAnonym/SmartHeapProvider.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_STATICDEPENDENTOBJECTSSTORAGE_H
#include <Urasandesu/CppAnonym/StaticDependentObjectsStorage.h>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSINGINFO_H
#include <Urasandesu/CppAnonym/DisposingInfo.h>
#endif

#ifndef URASANDESU_CPPANONYM_DISPOSABLEHEAPPROVIDER_H
#include <Urasandesu/CppAnonym/DisposableHeapProvider.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#include <Urasandesu/CppAnonym/StackTrace.h>
#endif

#ifndef URASANDESU_CPPANONYM_SIMPLEDISPOSABLE_H
#include <Urasandesu/CppAnonym/SimpleDisposable.h>
#endif

#ifndef URASANDESU_CPPANONYM_SYSTEMERROR_H
#include <Urasandesu/CppAnonym/SystemError.h>
#endif

#ifndef URASANDESU_CPPANONYM_SMARTPTRCHAIN_HPP
#include <Urasandesu/CppAnonym/SmartPtrChain.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMCOMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymCOMException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTIMPLEMENTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotImplementedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMARGUMENTEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymArgumentException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMNOTSUPPORTEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymNotSupportedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMOBJECTDISPOSEDEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymObjectDisposedException.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMINVALIDOPERATIONEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymInvalidOperationException.h>
#endif

#ifndef URASANDESU_CPPANONYM_VERSION_H
#include <Urasandesu/CppAnonym/Version.h>
#endif

#endif  // #ifndef URASANDESU_CPPANONYM_CPPANONYM_H
