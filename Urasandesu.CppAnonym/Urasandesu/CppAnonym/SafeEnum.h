#pragma once
#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#define URASANDESU_CPPANONYM_SAFEENUM_H

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

    private:
        EnumType m_value;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SAFEENUM_H