#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H
#define URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H

#ifndef URASANDESU_CPPANONYM_TRAITS_EQUALITYCOMPARABLE_H
#include <Urasandesu/CppAnonym/Traits/EqualityComparable.h>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTOFWD_H
#include <Urasandesu/CppAnonym/Utilities/EqualToFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace EqualToDetail {

        using boost::algorithm::iequals;
        using boost::filesystem::path;

        template<class T>
        struct EqualToImpl;

        template<>
        struct EqualToImpl<path> : 
            Traits::EqualityComparable<path>
        {
            result_type operator()(param_type x, param_type y) const
            {
                return iequals(x.native(), y.native());
            }
        };

    }   // namespace EqualToDetail {

    template<>
    struct EqualTo<boost::filesystem::path> : 
        EqualToDetail::EqualToImpl<boost::filesystem::path>
    {
    };

    
    
    
    
    template<class T>
    struct EqualTo<T const *> : 
        Traits::EqualityComparable<T const *>
    {
        inline result_type operator()(param_type x, param_type y) const
        {
            return x == y;
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_EQUALTO_H