/* 
 * File: DefaultSTDMETHODWrapper.h
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
#ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
#define URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H

#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

#define CPPANONYM_DECLARE_METHOD_ARG(r, data, i, elem) \
    BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(2, 0, elem) BOOST_PP_TUPLE_ELEM(2, 1, elem)

#define CPPANONYM_DECLARE_METHOD_LOAD_ARG(r, data, i, elem) \
    BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(2, 1, elem)

#define CPPANONYM_DECLARE_DEFAULT_STDMETHOD_WRAPPER(method, args_tuple_seq) \
    public: \
        STDMETHOD(method)(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_ARG, _, args_tuple_seq)) \
        { \
            using namespace std; \
            using namespace boost; \
            using namespace Urasandesu::CppAnonym; \
             \
            try \
            { \
                return method##Core(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_LOAD_ARG, _, args_tuple_seq)); \
            } \
            catch (CppAnonymException &e) \
            { \
                cout << diagnostic_information(e) << endl; \
            } \
            catch (...) \
            { \
                cout << diagnostic_information(boost::current_exception()) << endl; \
            } \
             \
            return S_OK; \
        } \
         \
    protected: \
        STDMETHOD(method##Core)(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_ARG, _, args_tuple_seq)) \
        { \
            return S_OK; \
        }


#define CPPANONYM_DECLARE_DEFAULT_STDMETHOD_VOID_WRAPPER(method, args_tuple_seq) \
    public: \
        STDMETHOD_(void, method)(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_ARG, _, args_tuple_seq)) \
        { \
            using namespace std; \
            using namespace boost; \
            using namespace Urasandesu::CppAnonym; \
             \
            try \
            { \
                method##Core(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_LOAD_ARG, _, args_tuple_seq)); \
            } \
            catch (CppAnonymException &e) \
            { \
                cout << diagnostic_information(e) << endl; \
            } \
            catch (...) \
            { \
                cout << diagnostic_information(boost::current_exception()) << endl; \
            } \
        } \
         \
    protected: \
        STDMETHOD_(void, method##Core)(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_ARG, _, args_tuple_seq)) \
        { \
        }


#define CPPANONYM_DECLARE_DEFAULT_STDMETHOD__WRAPPER(ret, method, args_tuple_seq) \
    public: \
        STDMETHOD_(ret, method)(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_ARG, _, args_tuple_seq)) \
        { \
            using namespace std; \
            using namespace boost; \
            using namespace Urasandesu::CppAnonym; \
             \
            try \
            { \
                return method##Core(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_LOAD_ARG, _, args_tuple_seq)); \
            } \
            catch (CppAnonymException &e) \
            { \
                cout << diagnostic_information(e) << endl; \
            } \
            catch (...) \
            { \
                cout << diagnostic_information(boost::current_exception()) << endl; \
            } \
             \
            return ret(); \
        } \
         \
    protected: \
        STDMETHOD_(ret, method##Core)(BOOST_PP_SEQ_FOR_EACH_I(CPPANONYM_DECLARE_METHOD_ARG, _, args_tuple_seq)) \
        { \
            return ret(); \
        }

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_DEFAULTSTDMETHODWRAPPER_H
