#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_SIGNATUREUTIL_HPP
#define URASANDESU_CPPANONYM_METADATA_SIGNATUREUTIL_HPP

#ifndef URASANDESU_CPPANONYM_SIMPLEBLOB_HPP
#include <Urasandesu/CppAnonym/SimpleBlob.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    struct SignatureUtil
    {
        template<class SignatureHolder>
        static void PutSignatures(SimpleBlob &sb, SignatureHolder const &sigHolder)
        {
            typedef std::vector<COR_SIGNATURE>::const_iterator Iterator;
            std::vector<COR_SIGNATURE> const &sigs = sigHolder.GetSignatures();
            for (Iterator i = sigs.cbegin(), i_end = sigs.cend(); i != i_end; ++i)
                sb.Put<COR_SIGNATURE>(*i);
        }
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_SIGNATUREUTIL_HPP