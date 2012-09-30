#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTORFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AssignationDistributorDetail {

        using namespace boost;

        template<class T, class IsPointer, class HasTrivialAssign>
        struct AssignImpl
        {
            static void Assign(void *pDst, void *pSrc)
            {
                if (pDst != pSrc)
                    ::memcpy_s(pDst, sizeof(T), pSrc, sizeof(T));
            }
        };

        template<class T>
        struct AssignImpl<T, integral_constant<bool, false>, integral_constant<bool, false> >
        {
            static void Assign(void *pDst, void *pSrc)
            {
                if (pDst != pSrc)
                    *reinterpret_cast<T *>(pDst) = *reinterpret_cast<T *>(pSrc);
            }
        };

        template<class T>
        struct AssignationDistributorImpl
        {
            typedef typename is_pointer<T>::type is_pointer_type;
            typedef typename has_trivial_assign<T>::type has_trivial_assign_type;
            typedef AssignImpl<T, is_pointer_type, has_trivial_assign_type> impl_type;
            
            static void Assign(void *pDst, void *pSrc)
            {
                impl_type::Assign(pDst, pSrc);
            }
        };

    }   // namespace AssignationDistributorDetail {

    template<class T>
    struct AssignationDistributor : 
        AssignationDistributorDetail::AssignationDistributorImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP