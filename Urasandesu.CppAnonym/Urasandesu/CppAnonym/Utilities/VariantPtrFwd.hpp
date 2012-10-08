#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP
#define URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#define CPPANONYM_VARIANT_PTR_LIMIT_TYPES \
    BOOST_MPL_LIMIT_VECTOR_SIZE

#define CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS_IMPL(z, N, T) \
    class BOOST_PP_CAT(T, N) = boost::mpl::void_

#define CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS \
    BOOST_PP_ENUM(CPPANONYM_VARIANT_PTR_LIMIT_TYPES, CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS_IMPL, T)

#define CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(param)  \
    BOOST_PP_ENUM_SHIFTED_PARAMS(CPPANONYM_VARIANT_PTR_LIMIT_TYPES, param)

    namespace VariantPtrDetail {

        template<class T0, CPPANONYM_VARIANT_PTR_ENUM_SHIFTED_PARAMS(class T)>
        class VariantPtrImpl;

    }   // namespace VariantPtrDetail {

    template<CPPANONYM_VARIANT_PTR_AUX_DECLARE_PARAMS>
    struct VariantPtr;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_VARIANTPTRFWD_HPP