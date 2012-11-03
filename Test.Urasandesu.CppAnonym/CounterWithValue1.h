#pragma once
#ifndef COUNTERWITHVALUE1_H
#define COUNTERWITHVALUE1_H

template<class T1, class Counter>
struct CounterWithValue1 : 
    Counter
{
    CounterWithValue1() : m_value() { }
    CounterWithValue1(T1 value) : m_value(value) { }
    T1 m_value;
};

#endif  // #ifndef COUNTERWITHVALUE1_H