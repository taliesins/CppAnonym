/* 
 * File: SafeEnum.h
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
#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#define URASANDESU_CPPANONYM_SAFEENUM_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_HASH_H
#include <Urasandesu/CppAnonym/Utilities/Hash.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H
#include <Urasandesu/CppAnonym/Utilities/EqualTo.h>
#endif

#ifndef URASANDESU_CPPANONYM_SAFEENUMFWD_H
#include <Urasandesu/CppAnonym/SafeEnumFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<class EnumDef, class EnumType>
    class SafeEnum : public EnumDef
    {
    public:
        typedef SafeEnum<EnumDef, EnumType> this_type;

        SafeEnum() : 
            m_value(EnumType())
        { }
        
        SafeEnum(EnumType value) : 
            m_value(value)
        { }

        explicit SafeEnum(ULONG value) : 
            m_value(static_cast<EnumType>(value))
        { }

        EnumType Value() const
        {
            return m_value;
        }
        
        bool operator ==(this_type const &other) const
        {
            return m_value == other.m_value; 
        }
        
        bool operator !=(this_type const &other) const
        {
            return m_value != other.m_value; 
        }
        
        bool operator <(this_type const &other) const
        {
            return m_value <  other.m_value; 
        }
        
        bool operator <=(this_type const &other) const
        {
            return m_value <= other.m_value; 
        }
        
        bool operator >(this_type const &other) const
        {
            return m_value >  other.m_value; 
        }
        
        bool operator >=(this_type const &other) const
        {
            return m_value >= other.m_value; 
        }

    protected:
        EnumType m_value;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace HashDetail {

        template<class EnumDef, class EnumType>
        struct HashImpl<SafeEnum<EnumDef, EnumType> > : 
            Traits::HashComputable<SafeEnum<EnumDef, EnumType> >
        {
            result_type operator()(param_type v) const
            {
                return boost::hash_value(v.Value());
            }
        };

    }   // namespace HashDetail {

    
    
    template<class EnumDef, class EnumType>
    struct Hash<SafeEnum<EnumDef, EnumType> > : 
        HashDetail::HashImpl<SafeEnum<EnumDef, EnumType> >
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_SAFEENUM_H
