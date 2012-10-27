#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H
#define URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTORFWD_H
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AssignationDistributorDetail {

        using boost::has_trivial_assign;
        using boost::integral_constant;
        using boost::is_pointer;

        typedef integral_constant<bool, false> False;

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
        struct AssignImpl<T, False, False>
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

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H