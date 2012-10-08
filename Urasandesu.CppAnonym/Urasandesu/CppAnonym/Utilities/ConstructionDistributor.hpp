#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP

#ifndef URASANDESU_CPPANONYM_TRAITS_REMOVECONST_H
#include <Urasandesu/CppAnonym/Traits/RemoveConst.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTORFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/ConstructionDistributorFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace ConstructionDistributorDetail {

        using namespace boost;
        using namespace Urasandesu::CppAnonym::Traits;

        template<class T, class IsPointer, class HasTrivialConstructor>
        struct ConstructImpl
        {
            static void Construct(void *p)
            {
                ::ZeroMemory(p, sizeof(T));
            }
            
            template<class A1>
            static void Construct(void *p, A1 arg1)
            {
                BOOST_MPL_ASSERT((is_same<T, typename RemoveConst<typename remove_reference<A1>::type>::type>));
                ::memcpy_s(p, sizeof(T), &arg1, sizeof(T));
            }
        };

        template<class T>
        struct ConstructImpl<T, integral_constant<bool, false>, integral_constant<bool, false> >
        {
            static void Construct(void *p)
            {
                new(p)T();
            }

            template<class A1>
            static void Construct(void *p, A1 arg1)
            {
                new(p)T(arg1);
            }
        };

        template<class T>
        struct ConstructionDistributorImpl
        {
            typedef typename is_pointer<T>::type is_pointer_type;
            typedef typename has_trivial_constructor<T>::type has_trivial_constructor_type;
            typedef ConstructImpl<T, is_pointer_type, has_trivial_constructor_type> impl_type;
            
            static void Construct(void *p)
            {
                impl_type::Construct(p);
            }
            
            template<class A1>
            static void Construct(void *p, A1 arg1)
            {
                impl_type::Construct<A1>(p, arg1);
            }
        };

    }   // namespace ConstructionDistributorDetail {

    template<class T>
    struct ConstructionDistributor : 
        ConstructionDistributorDetail::ConstructionDistributorImpl<T>
    {
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CONSTRUCTIONDISTRIBUTOR_HPP