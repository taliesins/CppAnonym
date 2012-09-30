#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTORFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTORFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace ConstructionDistributorDetail {

        template<class T, class IsPointer, class HasTrivialConstructor>
        struct ConstructImpl;

        template<class T>
        struct ConstructionDistributorImpl;

    }   // namespace ConstructionDistributorDetail {

    template<class T>
    struct ConstructionDistributor;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTORFWD_HPP