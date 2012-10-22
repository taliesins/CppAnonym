#pragma once
#ifndef URASANDESU_CPPANONYM_STACKTRACE_H
#define URASANDESU_CPPANONYM_STACKTRACE_H

#ifndef URASANDESU_CPPANONYM_STACKFRAME_H
#include <Urasandesu/CppAnonym/StackFrame.h>
#endif

#ifndef URASANDESU_CPPANONYM_STACKTRACEFWD_H
#include <Urasandesu/CppAnonym/StackTraceFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym {

    class StackTrace
    {
    public:
        StackTrace();
        ~StackTrace();
        void Capture(INT skipCount = 1,
                     HANDLE hProcess = ::GetCurrentProcess(), 
                     HANDLE hThread = ::GetCurrentThread(), 
                     LPCWSTR userSearchPath = L".\\", 
                     LPCONTEXT pContext = NULL);

        boost::ptr_vector<StackFrame> *GetStackFrames();
        
    private:
        HANDLE m_hProcess;
        boost::ptr_vector<StackFrame> m_frames;
    };

}}  // namespace Urasandesu { namespace CppAnonym {

#endif  // URASANDESU_CPPANONYM_STACKTRACE_H