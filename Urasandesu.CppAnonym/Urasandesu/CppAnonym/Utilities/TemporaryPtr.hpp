#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTR_HPP

#ifndef URASANDESU_CPPANONYM_UTILITIES_DEFAULTDELETER_HPP
#include <Urasandesu/CppAnonym/Utilities/DefaultDeleter.hpp>
#endif

#ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTRFWD_HPP
#include <Urasandesu/CppAnonym/Utilities/TemporaryPtrFwd.hpp>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T, class Tag, class D>
    class TemporaryPtr : 
        boost::noncopyable
    {
    public:
        typedef TemporaryPtr<T, Tag, D> this_type;
        typedef DeletionDisabledPolicy<D> deletion_disabled_deleter;

        typedef T element_type;
        typedef T value_type;
        typedef T *pointer;

        explicit TemporaryPtr(T *p) : 
            m_p(p),
            m_ddd(deletion_disabled_deleter(D()))
        { }

        TemporaryPtr(T *p, D d) : 
            m_p(p),
            m_ddd(deletion_disabled_deleter(d))
        { }

        ~TemporaryPtr()
        {
            m_ddd(m_p);
        }

        pointer operator->()
        {
            return m_p;
        }

        pointer Get()
        {
            return m_p;
        }

        pointer Move()
        {
            m_ddd.DisablesDeletion();
            return m_p;
        }

    private:
        T *m_p;
        deletion_disabled_deleter m_ddd;
    };

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_TEMPORARYPTR_HPP