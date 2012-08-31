#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONDISABLEDPOLICY_HPP
#define URASANDESU_CPPANONYM_UTILITIES_DELETIONDISABLEDPOLICY_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONDISABLEDPOLICYFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionDisabledPolicyFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class D>
    class DeletionDisabledPolicy
    {
    public:
        typedef DeletionDisabledPolicy<D> this_type;

        typedef D deleter;

        explicit DeletionDisabledPolicy(deleter d) : 
            m_d(d) 
        { 
            m_disabled[0] = false; 
        }
        
        template<class T>
        void operator()(T *p) 
        { 
            if (!m_disabled[0]) 
                m_d(p); 
        }
        
        void DisablesDeletion() 
        { 
            m_disabled[0] = true; 
        }
    
    private:
        deleter m_d;
        bool m_disabled[1];
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONDISABLEDPOLICY_HPP