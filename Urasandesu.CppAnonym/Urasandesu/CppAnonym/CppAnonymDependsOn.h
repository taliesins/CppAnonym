/* 
 * File: CppAnonymDependsOn.h
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
#ifndef URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H
#define URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H

#ifndef _ATL_APARTMENT_THREADED
#define _ATL_APARTMENT_THREADED
#endif

#ifndef _ATL_NO_AUTOMATIC_NAMESPACE
#define _ATL_NO_AUTOMATIC_NAMESPACE
#endif

#ifndef _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#endif

#ifndef ATL_NO_ASSERT_ON_DESTROY_NONEXISTENT_WINDOW
#define ATL_NO_ASSERT_ON_DESTROY_NONEXISTENT_WINDOW
#endif

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_MAP_SIZE 30
#define BOOST_MPL_LIMIT_VECTOR_SIZE 30

#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <boost/call_traits.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/exception/all.hpp>
#include <boost/exception/errinfo_nested_exception.hpp>
#include <boost/exception_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/flyweight.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/locale/generator.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/support/exception.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/make_shared.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/program_options.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/scope_exit.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/system/windows_error.hpp>
#include <boost/type_traits.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <comdef.h>
#include <Dbghelp.h>
#include <tlhelp32.h>


#ifdef OUTPUT_DEBUG
#define D_COUT(s) std::cout << s << std::endl
#define D_COUT1(fmt, arg) std::cout << boost::format(fmt) % arg << std::endl
#define D_COUT2(fmt, arg1, arg2) std::cout << boost::format(fmt) % arg1 % arg2 << std::endl
#define D_COUT3(fmt, arg1, arg2, arg3) std::cout << boost::format(fmt) % arg1 % arg2 % arg3 << std::endl
#define D_COUT4(fmt, arg1, arg2, arg3, arg4) std::cout << boost::format(fmt) % arg1 % arg2 % arg3 % arg4 << std::endl
#define D_COUT5(fmt, arg1, arg2, arg3, arg4, arg5) std::cout << boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5 << std::endl
#define D_WCOUT(s) std::wcout << s << std::endl
#define D_WCOUT1(fmt, arg) std::wcout << boost::wformat(fmt) % arg << std::endl
#define D_WCOUT2(fmt, arg1, arg2) std::wcout << boost::wformat(fmt) % arg1 % arg2 << std::endl
#define D_WCOUT3(fmt, arg1, arg2, arg3) std::wcout << boost::wformat(fmt) % arg1 % arg2 % arg3 << std::endl
#define D_WCOUT4(fmt, arg1, arg2, arg3, arg4) std::wcout << boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 << std::endl
#define D_WCOUT5(fmt, arg1, arg2, arg3, arg4, arg5) std::wcout << boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5 << std::endl
#define D_COUTI(i, s) std::cout << std::string(i, ' ') << s << std::endl
#define D_COUTI1(i, fmt, arg) std::cout << std::string(i, ' ') << boost::format(fmt) % arg << std::endl
#define D_COUTI2(i, fmt, arg1, arg2) std::cout << std::string(i, ' ') << boost::format(fmt) % arg1 % arg2 << std::endl
#define D_COUTI3(i, fmt, arg1, arg2, arg3) std::cout << std::string(i, ' ') << boost::format(fmt) % arg1 % arg2 % arg3 << std::endl
#define D_COUTI4(i, fmt, arg1, arg2, arg3, arg4) std::cout << std::string(i, ' ') << boost::format(fmt) % arg1 % arg2 % arg3 % arg4 << std::endl
#define D_COUTI5(i, fmt, arg1, arg2, arg3, arg4, arg5) std::cout << std::string(i, ' ') << boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5 << std::endl
#define D_WCOUTI(i, s) std::wcout << std::wstring(i, L' ') << s << std::endl
#define D_WCOUTI1(i, fmt, arg) std::wcout << std::wstring(i, L' ') << boost::wformat(fmt) % arg << std::endl
#define D_WCOUTI2(i, fmt, arg1, arg2) std::wcout << std::wstring(i, L' ') << boost::wformat(fmt) % arg1 % arg2 << std::endl
#define D_WCOUTI3(i, fmt, arg1, arg2, arg3) std::wcout << std::wstring(i, L' ') << boost::wformat(fmt) % arg1 % arg2 % arg3 << std::endl
#define D_WCOUTI4(i, fmt, arg1, arg2, arg3, arg4) std::wcout << std::wstring(i, L' ') << boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 << std::endl
#define D_WCOUTI5(i, fmt, arg1, arg2, arg3, arg4, arg5) std::wcout << std::wstring(i, L' ') << boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5 << std::endl
#else
#define D_COUT(s)
#define D_COUT1(fmt, arg)
#define D_COUT2(fmt, arg1, arg2)
#define D_COUT3(fmt, arg1, arg2, arg3)
#define D_COUT4(fmt, arg1, arg2, arg3, arg4)
#define D_COUT5(fmt, arg1, arg2, arg3, arg4, arg5)
#define D_WCOUT(s)
#define D_WCOUT1(fmt, arg)
#define D_WCOUT2(fmt, arg1, arg2)
#define D_WCOUT3(fmt, arg1, arg2, arg3)
#define D_WCOUT4(fmt, arg1, arg2, arg3, arg4)
#define D_WCOUT5(fmt, arg1, arg2, arg3, arg4, arg5)
#define D_COUTI(i, s) 
#define D_COUTI1(i, fmt, arg) 
#define D_COUTI2(i, fmt, arg1, arg2) 
#define D_COUTI3(i, fmt, arg1, arg2, arg3) 
#define D_COUTI4(i, fmt, arg1, arg2, arg3, arg4) 
#define D_COUTI5(i, fmt, arg1, arg2, arg3, arg4, arg5) 
#define D_WCOUTI(i, s) 
#define D_WCOUTI1(i, fmt, arg) 
#define D_WCOUTI2(i, fmt, arg1, arg2) 
#define D_WCOUTI3(i, fmt, arg1, arg2, arg3) 
#define D_WCOUTI4(i, fmt, arg1, arg2, arg3, arg4) 
#define D_WCOUTI5(i, fmt, arg1, arg2, arg3, arg4, arg5) 
#endif


namespace Urasandesu { namespace CppAnonym {

}}   // namespace Urasandesu { namespace CppAnonym {

#ifndef URASANDESU_CPPANONYM_COLLECTIONS_COLLECTIONSDEPENDSON_H
#include <Urasandesu/CppAnonym/Collections/CollectionsDependsOn.h>
#endif

#ifndef URASANDESU_CPPANONYM_TRAITS_TRAITSDEPENDSON_H
#include <Urasandesu/CppAnonym/Traits/TraitsDependsOn.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_UTILITIESDEPENDSON_H
#include <Urasandesu/CppAnonym/Utilities/UtilitiesDependsOn.h>
#endif

#endif  // #ifndef URASANDESU_CPPANONYM_CPPANONYMDEPENDSON_H
