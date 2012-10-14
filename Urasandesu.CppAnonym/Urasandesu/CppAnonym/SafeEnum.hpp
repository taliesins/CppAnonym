#pragma once
#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#define URASANDESU_CPPANONYM_SAFEENUM_HPP

#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#include <Urasandesu/CppAnonym/SafeEnum.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    template<class EnumDef, class EnumType>
    SafeEnum<EnumDef, EnumType>::SafeEnum() : 
        m_value(EnumType())
    { }

    template<class EnumDef, class EnumType>
    SafeEnum<EnumDef, EnumType>::SafeEnum(EnumType value) : 
        m_value(value)
    { }

    template<class EnumDef, class EnumType>
    inline EnumType SafeEnum<EnumDef, EnumType>::Value() const
    {
        return m_value;
    }

    template<class EnumDef, class EnumType>
    inline bool SafeEnum<EnumDef, EnumType>::operator==(typename SafeEnum<EnumDef, EnumType>::this_type const &other) const 
    { 
        return m_value == other.m_value; 
    }
    
    template<class EnumDef, class EnumType>
    inline bool SafeEnum<EnumDef, EnumType>::operator!=(typename SafeEnum<EnumDef, EnumType>::this_type const &other) const 
    { 
        return m_value != other.m_value; 
    }
    
    template<class EnumDef, class EnumType>
    inline bool SafeEnum<EnumDef, EnumType>::operator<(typename SafeEnum<EnumDef, EnumType>::this_type const &other) const 
    { 
        return m_value <  other.m_value; 
    }
    
    template<class EnumDef, class EnumType>
    inline bool SafeEnum<EnumDef, EnumType>::operator<=(typename SafeEnum<EnumDef, EnumType>::this_type const &other) const 
    { 
        return m_value <= other.m_value; 
    }
    
    template<class EnumDef, class EnumType>
    inline bool SafeEnum<EnumDef, EnumType>::operator>(typename SafeEnum<EnumDef, EnumType>::this_type const &other) const 
    { 
        return m_value >  other.m_value; 
    }
    
    template<class EnumDef, class EnumType>
    inline bool SafeEnum<EnumDef, EnumType>::operator>=(typename SafeEnum<EnumDef, EnumType>::this_type const &other) const 
    { 
        return m_value >= other.m_value; 
    }

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP