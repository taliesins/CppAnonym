#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTORFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTORFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AssignationDistributorDetail {

        template<class T, class IsPointer, class HasTrivialAssign>
        struct AssignImpl;

        template<class T>
        struct AssignationDistributorImpl;

    }   // namespace AssignationDistributorDetail {

    template<class T>
    struct AssignationDistributor;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTORFWD_HPP