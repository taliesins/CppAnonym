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

#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <boost/call_traits.hpp>
#include <boost/exception/all.hpp>
#include <boost/exception/errinfo_nested_exception.hpp>
#include <boost/exception_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
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
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/scope_exit.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/system/windows_error.hpp>
#include <boost/type_traits.hpp>
#include <boost/unordered_map.hpp>
#include <comdef.h>
#include <tlhelp32.h>
#include <Dbghelp.h>

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