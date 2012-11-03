#pragma once
#ifndef COUNTERWITHACTION1_H
#define COUNTERWITHACTION1_H

template<class A1, class Counter>
class CounterWithAction1 : 
    public Counter
{
public:
    CounterWithAction1() : m_action() { }
    CounterWithAction1(A1 action) : m_action(action) { }
    template<class T>
    void operator()(T obj)
    {
        Counter::operator()(obj);
        m_action(obj);
    }
private:
    A1 m_action;
};

#endif  // #ifndef COUNTERWITHACTION1_H