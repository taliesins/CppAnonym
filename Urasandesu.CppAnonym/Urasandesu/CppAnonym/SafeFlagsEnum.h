/* 
 * File: SafeFlagsEnum.h
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
#ifndef URASANDESU_CPPANONYM_SAFEFLAGSENUM_H
#define URASANDESU_CPPANONYM_SAFEFLAGSENUM_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEFLAGSENUMFWD_H
#include <Urasandesu/CppAnonym/SafeFlagsEnumFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<class EnumDef, class EnumType>
    struct SafeFlagsEnum : 
        SafeEnum<EnumDef, EnumType>
    {
        typedef SafeEnum<EnumDef, EnumType> base_type;
        typedef SafeFlagsEnum<EnumDef, EnumType> this_type;

        SafeFlagsEnum() : 
            base_type()
        { }
        
        SafeFlagsEnum(EnumType value) : 
            base_type(value)
        { }
        
        explicit SafeFlagsEnum(ULONG value) : 
            base_type(static_cast<EnumType>(value))
        { }

        friend EnumType operator |(this_type const &lhs, EnumType rhs)
        {
            return static_cast<EnumType>(lhs.Value() | +rhs);
        }

        friend EnumType operator |(EnumType lhs, this_type const &rhs)
        {
            return static_cast<EnumType>(+lhs | rhs.Value());
        }

        friend EnumType operator &(this_type const &lhs, EnumType rhs)
        {
            return static_cast<EnumType>(lhs.Value() & +rhs);
        }

        friend EnumType operator &(EnumType lhs, this_type const &rhs)
        {
            return static_cast<EnumType>(+lhs & rhs.Value());
        }

        this_type &operator |=(this_type const &rhs)
        {
            m_value = static_cast<EnumType>(+m_value | rhs.Value());
            return *this;
        }

        this_type &operator &=(this_type const &rhs)
        {
            m_value = static_cast<EnumType>(+m_value & rhs.Value());
            return *this;
        }

    };

#define CPP_ANONYM_DECLARE_SAFE_FLAGS_ENUM_OPERATORS(type_) \
    friend type_ operator |(type_ lhs, type_ rhs) \
    { \
        return static_cast<type_>(+lhs | +rhs); \
    } \
    \
    friend type_ operator &(type_ lhs, type_ rhs) \
    { \
        return static_cast<type_>(+lhs & +rhs); \
    } \
    \
    friend type_ operator ~(type_ v) \
    { \
        return static_cast<type_>(~(+v)); \
    }

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SAFEFLAGSENUM_H
