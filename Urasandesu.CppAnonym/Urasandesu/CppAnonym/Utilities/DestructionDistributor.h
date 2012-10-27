#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H
#define URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTORFWD_H
#include <Urasandesu/CppAnonym/Utilities/DestructionDistributorFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace DestructionDistributorDetail {

        using boost::has_trivial_destructor;
        using boost::integral_constant;
        using boost::is_pointer;

        typedef integral_constant<bool, false> False;

        template<class T, class IsPointer, class HasTrivialDestructor>
        struct DestructImpl
        {
            static void Destruct(void *p)
            {
                // nop
            }
        };

        template<class T>
        struct DestructImpl<T, False, False>
        {
            static void Destruct(void *p)
            {
                T *temp = reinterpret_cast<T *>(p);
                temp->~T();
            }
        };

        template<class T>
        struct DestructionDistributorImpl
        {
            typedef typename is_pointer<T>::type is_pointer_type;
            typedef typename has_trivial_destructor<T>::type has_trivial_destructor_type;
            typedef DestructImpl<T, is_pointer_type, has_trivial_destructor_type> impl_type;
            
            static void Destruct(void *p)
            {
                impl_type::Destruct(p);
            }
        };

    }   // namespace DestructionDistributorDetail {

    template<class T>
    struct DestructionDistributor : 
        DestructionDistributorDetail::DestructionDistributorImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_H