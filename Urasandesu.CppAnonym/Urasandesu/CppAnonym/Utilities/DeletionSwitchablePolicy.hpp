#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP
#define URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICYFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/DeletionSwitchablePolicyFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class D>
    class DeletionSwitchablePolicy
    {
    public:
        typedef DeletionSwitchablePolicy<D> this_type;

        typedef D deleter;

        explicit DeletionSwitchablePolicy(deleter d) : 
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
        
        void EnableDeletion() 
        { 
            m_disabled[0] = false; 
        }
        
        void DisableDeletion() 
        { 
            m_disabled[0] = true; 
        }
    
    private:
        deleter m_d;
        bool m_disabled[1];
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_DELETIONSWITCHABLEPOLICY_HPP