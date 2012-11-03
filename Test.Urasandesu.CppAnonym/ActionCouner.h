#pragma once
#ifndef ACTIONCOUNER_H
#define ACTIONCOUNER_H

template<class Counter>
struct ActionCouner : 
    Counter
{
    template<class T>
    void operator()(T obj)
    {
        ++Instance();
    }
};

#endif  // #ifndef ACTIONCOUNER_H