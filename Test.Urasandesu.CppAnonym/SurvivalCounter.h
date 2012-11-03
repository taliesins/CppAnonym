#pragma once
#ifndef SURVIVALCOUNTER_H
#define SURVIVALCOUNTER_H

template<class Counter>
struct SurvivalCounter : 
    Counter
{
    SurvivalCounter() { ++Instance(); }
    ~SurvivalCounter() { --Instance(); }
};

#endif  // #ifndef SURVIVALCOUNTER_H