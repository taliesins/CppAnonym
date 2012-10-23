#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_H
#include <Urasandesu/CppAnonym/Utilities/AssignationDistributor.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace AssignationDistributorDetail {

        template<class T, class IsPointer, class HasTrivialAssign>
        inline void AssignImpl<T, IsPointer, HasTrivialAssign>::Assign(void *pDst, void *pSrc)
        {
            if (pDst != pSrc)
                ::memcpy_s(pDst, sizeof(T), pSrc, sizeof(T));
        }

        template<class T>
        inline void AssignImpl<T, False, False>::Assign(void *pDst, void *pSrc)
        {
            if (pDst != pSrc)
                *reinterpret_cast<T *>(pDst) = *reinterpret_cast<T *>(pSrc);
        }

        template<class T>
        inline void AssignationDistributorImpl<T>::Assign(void *pDst, void *pSrc)
        {
            impl_type::Assign(pDst, pSrc);
        }

    }   // namespace AssignationDistributorDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_ASSIGNATIONDISTRIBUTOR_HPP