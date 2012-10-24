#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_H
#define URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_H

#ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIMFWD_H
#include <Urasandesu/CppAnonym/Utilities/CComObjectSlimFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class Base>
    class CComObjectSlim : 
        public ATL::CComObjectNoLock<Base>
    {
    public:
        typedef CComObjectSlim<Base> this_type;

        static HRESULT CreateInstance(this_type **ppObj);
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_CCOMOBJECTSLIM_H