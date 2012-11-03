#pragma once
#ifndef BASICCOUNTER_H
#define BASICCOUNTER_H

#ifndef ATOMICCOUNTER_H
#include <AtomicCounter.h>
#endif

template<class Tag, INT Index>
struct BasicCounter
{
    typedef AtomicCounter<Tag, Index> counter;
    static counter &Instance() { return counter::Instance(); }
};

#endif  // #ifndef BASICCOUNTER_H