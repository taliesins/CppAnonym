
#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#include <Urasandesu/CppAnonym/Fusion/AssemblyInfo.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    AssemblyInfo::AssemblyInfo(ULONGLONG assemblySizeInKB, boost::filesystem::path const &assemblyPath) :
        m_assemblySizeInKB(assemblySizeInKB), 
        m_assemblyPath(assemblyPath)
    { }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Fusion {
