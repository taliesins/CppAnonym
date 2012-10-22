#pragma once
#ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP
#define URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP

namespace Urasandesu { namespace CppAnonym { namespace Utilities {

    template<class T>
    class StackAllocator
    {
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T const *const_pointer;
        typedef T &reference;
        typedef T const &const_reference;
        typedef T value_type;

        template<class U>
        struct rebind
        {
	        typedef StackAllocator<U> other;
        };

        StackAllocator() throw() { }
        template<class U> StackAllocator(StackAllocator<U> const &) throw() { }
        ~StackAllocator() throw() { }

        pointer allocate(size_type num, void const *hint = NULL)
        {
            return reinterpret_cast<pointer>(_malloca(num * sizeof(T)));
        }

        void construct(pointer p, T const &value)
        {
	        new(p)T(value);
        }

        void deallocate(pointer p, size_type num)
        {
            _freea(p);
        }

        void destroy(pointer p)
        {
	        p->~T();
        }

        pointer address(reference value) const { return &value; }
        const_pointer address(const_reference value) const { return &value; }

        size_type max_size() const throw()
        {
	        return std::numeric_limits<size_t>::max() / sizeof(T);
        }
    };

    template<class T1, class T2>
    bool operator==(StackAllocator<T1> const &, StackAllocator<T2> const &) throw() { return true; }

    template<class T1, class T2>
    bool operator!=(StackAllocator<T1> const &, StackAllocator<T2> const &) throw() { return false; }

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Utilities {

#endif  // #ifndef URASANDESU_CPPANONYM_UTILITIES_STACKALLOCATOR_HPP