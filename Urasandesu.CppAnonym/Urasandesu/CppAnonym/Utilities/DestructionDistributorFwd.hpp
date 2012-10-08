#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTORFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTORFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace DestructionDistributorDetail {

        template<class T, class IsPointer, class HasTrivialDestructor>
        struct DestructImpl;

        template<class T>
        struct DestructionDistributorImpl;

    }   // namespace DestructionDistributorDetail {

    template<class T>
    struct DestructionDistributor;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTORFWD_HPP