/* 
 * File: Environment.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_ENVIRONMENT_H
#include <Urasandesu/CppAnonym/Environment.h>
#endif

#ifndef URASANDESU_CPPANONYM_CPPANONYMSYSTEMEXCEPTION_H
#include <Urasandesu/CppAnonym/CppAnonymSystemException.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    namespace EnvironmentDetail {

        template<class TChar>
        errno_t DupEnv_S(TChar **buffer, size_t *numberOfElements, TChar const *varname);
        
        template<>
        errno_t DupEnv_S<CHAR>(CHAR **buffer, size_t *numberOfElements, CHAR const *varname)
        {
            return ::_dupenv_s(buffer, numberOfElements, varname);
        }
        
        template<>
        errno_t DupEnv_S<WCHAR>(WCHAR **buffer, size_t *numberOfElements, WCHAR const *varname)
        {
            return ::_wdupenv_s(buffer, numberOfElements, varname);
        }


        
        template<class TChar>
        errno_t PutEnv_S(TChar const *name, TChar const *value);

        template<>
        errno_t PutEnv_S<CHAR>(CHAR const *name, CHAR const *value)
        {
            return ::_putenv_s(name, value);
        }

        template<>
        errno_t PutEnv_S<WCHAR>(WCHAR const *name, WCHAR const *value)
        {
            return ::_wputenv_s(name, value);
        }
        
        
        
        template<class TChar>
        basic_string<TChar, char_traits<TChar>, allocator<TChar> > EnvironmentImpl::GetEnvironmentVariable(TChar const *variable)
        {
            auto pVarValue = static_cast<TChar *>(nullptr);
            auto varValueSize = size_t();
            auto err = DupEnv_S(&pVarValue, &varValueSize, variable);
            if (err)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(err));

            if (varValueSize == 0)
                return basic_string<TChar, char_traits<TChar>, allocator<TChar> >();
        
            auto result = basic_string<TChar, char_traits<TChar>, allocator<TChar> >(pVarValue);
            ::free(pVarValue);
            return result;
        }
        
        
        
        template<class TChar> 
        basic_string<TChar, char_traits<TChar>, allocator<TChar> > EnvironmentImpl::GetEnvironmentVariable(basic_string<TChar, char_traits<TChar>, allocator<TChar> > const &variable)
        {
            return GetEnvironmentVariable(variable.c_str());
        }
        
        
        
        template<class TChar> 
        void EnvironmentImpl::SetEnvironmentVariable(TChar const *name, TChar const *value)
        {
            auto err = PutEnv_S(name, value);
            if (err)
                BOOST_THROW_EXCEPTION(CppAnonymSystemException(err));
        }



        template<class TChar> 
        void EnvironmentImpl::SetEnvironmentVariable(basic_string<TChar, char_traits<TChar>, allocator<TChar> > const &name, TChar const *value)
        {
            SetEnvironmentVariable(name.c_str(), value);
        }



        template<class TChar> 
        void EnvironmentImpl::SetEnvironmentVariable(TChar const *name, basic_string<TChar, char_traits<TChar>, allocator<TChar> > const &value)
        {
            SetEnvironmentVariable(name, value.c_str());
        }



        template<class TChar> 
        void EnvironmentImpl::SetEnvironmentVariable(basic_string<TChar, char_traits<TChar>, allocator<TChar> > const &name, basic_string<TChar, char_traits<TChar>, allocator<TChar> > const &value)
        {
            SetEnvironmentVariable(name.c_str(), value.c_str());
        }

    
        
        template basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > EnvironmentImpl::GetEnvironmentVariable<CHAR>(CHAR const *);
        template basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > EnvironmentImpl::GetEnvironmentVariable<WCHAR>(WCHAR const *);
        template basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > EnvironmentImpl::GetEnvironmentVariableW<CHAR>(basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > const &);
        template basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > EnvironmentImpl::GetEnvironmentVariableW<WCHAR>(basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > const &);
        template void EnvironmentImpl::SetEnvironmentVariable<CHAR>(CHAR const *, CHAR const *);
        template void EnvironmentImpl::SetEnvironmentVariable<WCHAR>(WCHAR const *, WCHAR const *);
        template void EnvironmentImpl::SetEnvironmentVariable<CHAR>(CHAR const *, basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > const &);
        template void EnvironmentImpl::SetEnvironmentVariable<WCHAR>(WCHAR const *, basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > const &);
        template void EnvironmentImpl::SetEnvironmentVariable<CHAR>(basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > const &, CHAR const *);
        template void EnvironmentImpl::SetEnvironmentVariable<WCHAR>(basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > const &, WCHAR const *);
        template void EnvironmentImpl::SetEnvironmentVariable<CHAR>(basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > const &, basic_string<CHAR, char_traits<CHAR>, allocator<CHAR> > const &);
        template void EnvironmentImpl::SetEnvironmentVariable<WCHAR>(basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > const &, basic_string<WCHAR, char_traits<WCHAR>, allocator<WCHAR> > const &);

    }   // namespace EnvironmentDetail {
        
}}  // namespace Urasandesu { namespace CppAnonym {
