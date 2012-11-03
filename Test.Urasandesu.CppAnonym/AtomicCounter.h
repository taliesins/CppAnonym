#pragma once
#ifndef ATOMICCOUNTER_H
#define ATOMICCOUNTER_H

#include <boost/detail/atomic_count.hpp>

template<class Tag, INT Index>
class AtomicCounter : 
    boost::noncopyable
{
public:
    static AtomicCounter &Instance() { static AtomicCounter ac; return ac; }
    INT operator++() { return ++m_count; }
    INT operator--() { return --m_count; }
    INT Value() { return m_count; }
private:
    AtomicCounter() : m_count(0) { }
    ~AtomicCounter() { }
    boost::detail::atomic_count m_count;
};

#endif  // #ifndef ATOMICCOUNTER_H