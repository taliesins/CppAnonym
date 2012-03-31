#pragma once
#ifndef URASANDESU_CPPANONYM_SAFEENUM_H
#define URASANDESU_CPPANONYM_SAFEENUM_H

namespace Urasandesu { namespace CppAnonym {

    template<class EnumDef, class EnumType = EnumDef::type>
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

        inline EnumType Value() const
        {
            return m_value;
        }

        inline bool operator ==(this_type const &other) const { return m_value == other.m_value; }
        inline bool operator !=(this_type const &other) const { return m_value != other.m_value; }
        inline bool operator <(this_type const &other) const { return m_value <  other.m_value; }
        inline bool operator <=(this_type const &other) const { return m_value <= other.m_value; }
        inline bool operator >(this_type const &other) const { return m_value >  other.m_value; }
        inline bool operator >=(this_type const &other) const { return m_value >= other.m_value; }

    private:
        EnumType m_value;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SAFEENUM_H