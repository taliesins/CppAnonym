#pragma once
#ifndef URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H
#define URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H

namespace Urasandesu { namespace CppAnonym { namespace Fusion {

    class AssemblyInfo
    {
    public:
        AssemblyInfo(ULONGLONG assemblySizeInKB, boost::filesystem::path const &assemblyPath);
        inline ULONGLONG GetAssemblySizeInKB() const { return m_assemblySizeInKB; }
        inline boost::filesystem::path const &GetAssemblyPath() const { return m_assemblyPath; }

    private:
        ULONGLONG m_assemblySizeInKB;
        boost::filesystem::path m_assemblyPath;
    };
        
}}}  // namespace Urasandesu { namespace CppAnonym { namespace Fusion {

#endif  // URASANDESU_CPPANONYM_FUSION_ASSEMBLYINFO_H