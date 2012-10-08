#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTERFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTERFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace Detail {

        struct TemporaryHolder;

        template<class T, class Tag, class D>
        struct TemporaryHolderImpl;

        template<class T, class Tag, class D>
        struct TemporaryHolderImplFactory;

    }   // namespace Detail {

    template<class T, class Tag>
    class TemporaryPointer;

    template<class T, class Tag>
    class PersistableTemporaryPointer;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPOINTERFWD_HPP