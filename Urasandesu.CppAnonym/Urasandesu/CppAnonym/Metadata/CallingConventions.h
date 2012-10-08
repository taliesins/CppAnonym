#pragma once
#ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H
#define URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H

#ifndef URASANDESU_CPPANONYM_SAFEENUM_HPP
#include <Urasandesu/CppAnonym/SafeEnum.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Metadata {

    namespace Detail {

        class ATL_NO_VTABLE CallingConventionsDef
        {
        public:
            enum type
            {
                CC_STANDARD, 
                CC_VAR_ARGS, 
                CC_ANY, 
                CC_HAS_THIS, 
                CC_EXPLICIT_THIS, 
                CC_UNREACHED
            };

            std::vector<COR_SIGNATURE> const &GetSignatures() const
            {
                if (m_sigs.empty())
                {
                    typedef SafeEnum<CallingConventionsDef> CallingConventions;
                
                    CallingConventions const *this_ = static_cast<CallingConventions const *>(this);
                    switch (this_->Value())
                    {
                        case CC_STANDARD: 
                            m_sigs.push_back(IMAGE_CEE_CS_CALLCONV_DEFAULT);
                            break;
                        case CC_VAR_ARGS: 
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        case CC_ANY: 
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        case CC_HAS_THIS: 
                            m_sigs.push_back(IMAGE_CEE_CS_CALLCONV_HASTHIS);
                            break;
                        case CC_EXPLICIT_THIS: 
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                        default:
                            BOOST_THROW_EXCEPTION(CppAnonymNotImplementedException());
                    }
                }
                return m_sigs;
            }
        
        protected:
            CallingConventionsDef() { }
        
        private:
            mutable std::vector<COR_SIGNATURE> m_sigs;
        };

    }   // Detail

    typedef SafeEnum<Detail::CallingConventionsDef> CallingConventions;

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Metadata {

#endif  // #ifndef URASANDESU_CPPANONYM_METADATA_CALLINGCONVENTIONS_H