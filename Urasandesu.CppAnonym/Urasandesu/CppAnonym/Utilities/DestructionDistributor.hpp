#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    struct DestructionDistributor
    {
        typedef typename boost::call_traits<T>::param_type param_type;
        typedef typename boost::remove_pointer<typename Traits::RemoveConst<T>::type>::type raw_type;

        static inline void Destruct(param_type obj)
        {
            typedef typename boost::is_pointer<T>::type is_pointer;
            typedef typename boost::has_trivial_destructor<raw_type>::type has_trivial_destructor;
            
            DestructImpl<is_pointer, has_trivial_destructor>::Destruct(obj);
        }

        template<class IsPointer, class HasTrivialDestructor>
        struct DestructImpl
        {
            static inline void Destruct(param_type obj)
            {
                // Do nothing. Because T has trivial destructor in this case.
            }
        };

        template<>
        struct DestructImpl<boost::integral_constant<bool, false>, boost::integral_constant<bool, false>> 
        { 
            static inline void Destruct(param_type obj)
            {
                obj.~raw_type();
            }
        };

        template<>
        struct DestructImpl<boost::integral_constant<bool, true>, boost::integral_constant<bool, false>> 
        { 
            static inline void Destruct(param_type obj)
            {
                obj->~raw_type();
            }
        };
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DESTRUCTIONDISTRIBUTOR_HPP