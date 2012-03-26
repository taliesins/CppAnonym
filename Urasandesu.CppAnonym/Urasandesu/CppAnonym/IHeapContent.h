#pragma once
#ifndef URASANDESU_CPPANONYM_IHEAPCONTENT_H
#define URASANDESU_CPPANONYM_IHEAPCONTENT_H

namespace Urasandesu { namespace CppAnonym {

    template<class Key>
    class ATL_NO_VTABLE IHeapContent
    {
    public:        
        inline Key GetKey() const
        {
            return m_key;
        }
        
        inline void SetKey(Key key)
        {
            m_key = key;
        }
        
        inline bool IsPseudo() const
        {
            return m_key == Key();
        }

    protected:
        IHeapContent() : 
            m_key(Key())
        { }
        
    private:        
        Key m_key;
    }; 
    
}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_IHEAPCONTENT_H