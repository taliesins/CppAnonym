#pragma once
#ifndef URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H
#define URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H

namespace Urasandesu { namespace CppAnonym { namespace Collections {

    template<class InputIterator1, class InputIterator2>
    bool SequenceEqual(InputIterator1 i1, InputIterator1 i_end1,
                       InputIterator2 i2, InputIterator2 i_end2)
    {
        while ((i1 != i_end1) && (i2 != i_end2))
        {
            if (!(*i1 == *i2))
                return false;
            ++i1; ++i2;
        }
        return (i1 == i_end1) && (i2 == i_end2);
    } 

    
    template<class InputIterator, class Hash>
    inline std::size_t SequenceHashValue(InputIterator i, InputIterator i_end, Hash hash)
    {
        std::size_t seed = 0;
        for ( ; i != i_end; ++i)
            boost::hash_combine(seed, hash(*i));
        return seed;
    } 

    template<class InputIterator>
    inline std::size_t SequenceHashValue(InputIterator i, InputIterator i_end)
    {
        return SequenceHashValue(i, i_end, Utilities::CreateHash(i));
    } 

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Collections {

#endif  // URASANDESU_CPPANONYM_COLLECTIONS_ITERABLE_H