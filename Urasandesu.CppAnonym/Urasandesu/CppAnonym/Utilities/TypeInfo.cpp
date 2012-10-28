
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_UTILITIES_TYPEINFO_H
#include <Urasandesu/CppAnonym/Utilities/TypeInfo.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace TypeInfoDetail {

        bool TypeInfoImpl::operator ==(TypeInfoImpl const &other) const
        {
            if (IsEmpty() && other.IsEmpty())
                return true;
            else if (IsEmpty() || other.IsEmpty())
                return false;
            else
                return m_pHolder->GetType() == other.m_pHolder->GetType();
        }

    }   // namespace TypeInfoDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {
