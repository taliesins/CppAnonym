#pragma once
#ifndef URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H
#define URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H

#ifndef URASANDESU_CPPANONYM_STACKTRACEFWD_H
#include <Urasandesu/CppAnonym/StackTraceFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    typedef boost::error_info<struct tag_stack_trace, StackTrace *> ThrowStackTrace;

    class CppAnonymException : 
        public virtual boost::exception, 
        public virtual std::exception
    {
    public:
        CppAnonymException();
        CppAnonymException(std::string const &what);
        CppAnonymException(std::wstring const &what);
        CppAnonymException(std::string const &what, CppAnonymException &innerException);
        CppAnonymException(std::wstring const &what, CppAnonymException &innerException);
        virtual const char *__CLR_OR_THIS_CALL what() const;
        
    protected:
        std::string m_what;
        boost::shared_ptr<StackTrace> m_pStackTrace;
    
    private:
        void CaptureStackTrace(CppAnonymException *this_);

    };

    template class boost::shared_ptr<StackTrace>;

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_CPPANONYMEXCEPTION_H