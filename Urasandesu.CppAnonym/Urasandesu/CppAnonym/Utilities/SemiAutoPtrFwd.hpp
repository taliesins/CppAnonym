#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    namespace SemiAutoPtrDetail {

        struct SemiAutoPtrHolder;

        CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(SemiAutoPtrImpl, factory_type);
        CPP_ANONYM_DECLARE_GET_MEMBER_TYPE(SemiAutoPtrImpl, factory_type);

        template<class T, class D>
        struct SemiAutoPtrHolderImpl;

        template<class T, class D>
        struct SemiAutoPtrHolderImplFactory;

        template<class T>
        class SemiAutoPtrImpl;

    }   // namespace SemiAutoPtrDetail {

    template<class T>
    class SemiAutoPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_SEMIAUTOPTRFWD_HPP