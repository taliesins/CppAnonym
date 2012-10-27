#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATORFWD_H
#define URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATORFWD_H

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    class StackAllocator;

    template<class T1, class T2>
    bool operator ==(StackAllocator<T1> const &, StackAllocator<T2> const &) throw();

    template<class T1, class T2>
    bool operator !=(StackAllocator<T1> const &, StackAllocator<T2> const &) throw();

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATORFWD_H