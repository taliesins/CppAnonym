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

        SafeEnum();
        SafeEnum(EnumType value);
        EnumType Value() const;
        bool operator ==(this_type const &other) const;
        bool operator !=(this_type const &other) const;
        bool operator <(this_type const &other) const;
        bool operator <=(this_type const &other) const;
        bool operator >(this_type const &other) const;
        bool operator >=(this_type const &other) const;

    private:
        EnumType m_value;
    };

}}   // namespace Urasandesu { namespace CppAnonym {

#endif  // #ifndef URASANDESU_CPPANONYM_SAFEENUM_H