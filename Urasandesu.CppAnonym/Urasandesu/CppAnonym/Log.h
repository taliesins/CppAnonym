/* 
 * File: Log.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_CPPANONYM_LOG_H
#define URASANDESU_CPPANONYM_LOG_H

#ifndef URASANDESU_CPPANONYM_LOGFWD_H
#include <Urasandesu/CppAnonym/LogFwd.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Logging {

    namespace LogDetail {

        namespace logging = boost::log;
        namespace sinks = boost::log::sinks;
        namespace attrs = boost::log::attributes;
        namespace src = boost::log::sources;
        namespace expr = boost::log::expressions;
        namespace keywords = boost::log::keywords;
        using boost::posix_time::ptime;
        using std::basic_ostream;
        using std::string;

        enum LogSeverityLevel
        {
            LSL_DEBUG, 
            LSL_VERBOSE, 
            LSL_INFO, 
            LSL_WARNING, 
            LSL_ERROR, 
            LSL_UNREACHED = 10
        };

        template<class CharT, class TraitsT>
        inline basic_ostream<CharT, TraitsT> &operator <<(basic_ostream<CharT, TraitsT> &strm, LogSeverityLevel lvl)
        {
            using std::size_t;

            static char const *const str[] =
            {
                "DEBUG", 
                "VERBOSE", 
                "INFO", 
                "WARNING", 
                "ERROR"
            };

            if (static_cast<size_t>(lvl) < (sizeof(str) / sizeof(*str)))
                strm << str[lvl];
            else
                strm << static_cast<int>(lvl);
            return strm;
        }

        BOOST_LOG_ATTRIBUTE_KEYWORD(process_id, "ProcessID", attrs::current_process_id::value_type)
        BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
        BOOST_LOG_ATTRIBUTE_KEYWORD(thread_id, "ThreadID", attrs::current_thread_id::value_type)
        BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", LogSeverityLevel)
        BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", ptime)
        BOOST_LOG_ATTRIBUTE_KEYWORD(file_line, "FileLine", string)
        BOOST_LOG_ATTRIBUTE_KEYWORD(file_path, "FilePath", string)

        char const LOGGING_TARGET[] = "URASANDESU_CPPANONYM_LOGGING_TARGET";
        char const LOGGING_BASE_NAME[] = "URASANDESU_CPPANONYM_LOGGING_BASE_NAME";
        char const LOGGING_SEVERITY[] = "URASANDESU_CPPANONYM_LOGGING_SEVERITY";

        class Bootstrap
        {
        public:
            static void InitializeLogger();

        private:
            Bootstrap();

            string GetLogTarget() const;
            string GetLogBaseName() const;
            int GetLogSeverity() const;
            void InitializeLoggerCore();
        };

        BOOST_LOG_GLOBAL_LOGGER(LogW, src::wseverity_logger_mt<LogSeverityLevel>);
        BOOST_LOG_GLOBAL_LOGGER(LogA, src::severity_logger_mt<LogSeverityLevel>);

        inline int GetIndentLevel()
        {
            using boost::log::current_scope;
            auto size = current_scope().value().size();
            return size == 0 ? 0 : (size - 1) * 4;
        }

    }   // namespace LogDetail {

#define CPPANONYM_D_LOG_ENABLED() Urasandesu::CppAnonym::Logging::LogDetail::LogW::get().open_record(boost::log::keywords::severity = Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG)
#define CPPANONYM_D_LOG(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << s
#define CPPANONYM_D_LOG1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg)
#define CPPANONYM_D_LOG2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2)
#define CPPANONYM_D_LOG3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_D_LOG4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_D_LOG5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)
#define CPPANONYM_D_LOGW(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << s
#define CPPANONYM_D_LOGW1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg)
#define CPPANONYM_D_LOGW2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2)
#define CPPANONYM_D_LOGW3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_D_LOGW4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_D_LOGW5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_DEBUG) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)

#define CPPANONYM_V_LOG_ENABLED() Urasandesu::CppAnonym::Logging::LogDetail::LogW::get().open_record(boost::log::keywords::severity = Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE)
#define CPPANONYM_V_LOG(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << s
#define CPPANONYM_V_LOG1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg)
#define CPPANONYM_V_LOG2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2)
#define CPPANONYM_V_LOG3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_V_LOG4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_V_LOG5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)
#define CPPANONYM_V_LOGW(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << s
#define CPPANONYM_V_LOGW1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg)
#define CPPANONYM_V_LOGW2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2)
#define CPPANONYM_V_LOGW3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_V_LOGW4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_V_LOGW5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_VERBOSE) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)

#define CPPANONYM_I_LOG_ENABLED() Urasandesu::CppAnonym::Logging::LogDetail::LogW::get().open_record(boost::log::keywords::severity = Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO)
#define CPPANONYM_I_LOG(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << s
#define CPPANONYM_I_LOG1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg)
#define CPPANONYM_I_LOG2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2)
#define CPPANONYM_I_LOG3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_I_LOG4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_I_LOG5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)
#define CPPANONYM_I_LOGW(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << s
#define CPPANONYM_I_LOGW1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg)
#define CPPANONYM_I_LOGW2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2)
#define CPPANONYM_I_LOGW3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_I_LOGW4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_I_LOGW5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_INFO) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)

#define CPPANONYM_W_LOG_ENABLED() Urasandesu::CppAnonym::Logging::LogDetail::LogW::get().open_record(boost::log::keywords::severity = Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING)
#define CPPANONYM_W_LOG(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << s
#define CPPANONYM_W_LOG1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg)
#define CPPANONYM_W_LOG2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2)
#define CPPANONYM_W_LOG3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_W_LOG4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_W_LOG5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)
#define CPPANONYM_W_LOGW(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << s
#define CPPANONYM_W_LOGW1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg)
#define CPPANONYM_W_LOGW2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2)
#define CPPANONYM_W_LOGW3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_W_LOGW4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_W_LOGW5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_WARNING) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)

#define CPPANONYM_E_LOG_ENABLED() Urasandesu::CppAnonym::Logging::LogDetail::LogW::get().open_record(boost::log::keywords::severity = Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR)
#define CPPANONYM_E_LOG(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << s
#define CPPANONYM_E_LOG1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg)
#define CPPANONYM_E_LOG2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2)
#define CPPANONYM_E_LOG3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_E_LOG4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_E_LOG5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogA::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::string(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), ' ') << boost::str(boost::format(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)
#define CPPANONYM_E_LOGW(s) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << s
#define CPPANONYM_E_LOGW1(fmt, arg) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg)
#define CPPANONYM_E_LOGW2(fmt, arg1, arg2) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2)
#define CPPANONYM_E_LOGW3(fmt, arg1, arg2, arg3) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3)
#define CPPANONYM_E_LOGW4(fmt, arg1, arg2, arg3, arg4) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4)
#define CPPANONYM_E_LOGW5(fmt, arg1, arg2, arg3, arg4, arg5) BOOST_LOG_SEV((Urasandesu::CppAnonym::Logging::LogDetail::LogW::get()), Urasandesu::CppAnonym::Logging::LogDetail::LSL_ERROR) << boost::log::add_value("FileLine", boost::lexical_cast<std::string>(__LINE__)) << boost::log::add_value("FilePath", __FILE__) << std::wstring(Urasandesu::CppAnonym::Logging::LogDetail::GetIndentLevel(), L' ') << boost::str(boost::wformat(fmt) % arg1 % arg2 % arg3 % arg4 % arg5)

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Logging {

#endif  // URASANDESU_CPPANONYM_LOG_H
