/* 
 * File: Log.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_CPPANONYM_LOG_H
#include <Urasandesu/CppAnonym/Log.h>
#endif

#ifndef URASANDESU_CPPANONYM_ENVIRONMENT_H
#include <Urasandesu/CppAnonym/Environment.h>
#endif

namespace Urasandesu { namespace CppAnonym { namespace Logging {

    namespace LogDetail {

        void Bootstrap::InitializeLogger()
        {
            static Bootstrap bootstrap;
        }

        
        
        Bootstrap::Bootstrap()
        {
            InitializeLoggerCore(); 
        }

        
        
        string Bootstrap::GetLogTarget() const
        {
            auto logTarget = Environment::GetEnvironmentVariable(LOGGING_TARGET);
            return logTarget.empty() ? "log" : logTarget;
        }

        
        
        string Bootstrap::GetLogBaseName() const
        {
            auto logBaseName = Environment::GetEnvironmentVariable(LOGGING_BASE_NAME);
            return logBaseName.empty() ? "app" : logBaseName;
        }

        
        
        int Bootstrap::GetLogSeverity() const
        {
            using boost::lexical_cast;
            using boost::bad_lexical_cast;

            try
            {
                auto logSeverity = Environment::GetEnvironmentVariable(LOGGING_SEVERITY);
                return lexical_cast<int>(logSeverity);
            }
            catch(bad_lexical_cast const &)
            {
                return LSL_INFO;
            }
        }

        
        
        void Bootstrap::InitializeLoggerCore()
        {
            using boost::shared_ptr;

            auto logTarget = GetLogTarget();
            auto logFileName = logTarget + "/" + GetLogBaseName() + "_%Y%m%d.log";
            auto logSeverity = GetLogSeverity();
            shared_ptr<sinks::synchronous_sink<sinks::text_file_backend>> sink = logging::add_file_log
            (
                keywords::auto_flush = true,
                keywords::open_mode = std::ios::app,
                keywords::target = logTarget,
                keywords::file_name = logFileName,
                keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
                keywords::format = 
                    expr::stream << 
                        expr::format_date_time(timestamp, "%Y/%m/%d %H:%M:%S.%f") << 
                        "," << 
                        severity.or_default(LSL_VERBOSE) <<
                        "," << 
                        process_id << 
                        "," << 
                        line_id << 
                        "," << 
                        thread_id << 
                        "," <<
                        "\"" << expr::csv_decor[expr::stream << expr::message] << "\"" << 
                        expr::if_(severity <= LSL_VERBOSE || LSL_WARNING <= severity) [
                            expr::stream << 
                                "," << 
                                "\"" << expr::csv_decor[expr::stream << file_path] << "\"" << 
                                "," << 
                                file_line
                        ] << 
                        expr::if_(severity <= LSL_DEBUG || LSL_ERROR <= severity) [
                            expr::stream << 
                                "," <<
                                expr::format_named_scope("Scope", keywords::format = "\"%n=>%f,%l\"", keywords::delimiter = ",")
                        ]
            );

            std::locale loc = boost::locale::generator()("en_US.UTF-8");
            sink->imbue(loc);

            sink->set_filter(logSeverity <= severity);

            logging::core::get()->add_sink(sink);

            logging::add_common_attributes();
            logging::core::get()->add_global_attribute("Scope", attrs::named_scope());
            logging::core::get()->add_global_attribute("RecordID", attrs::counter<unsigned int>());
            logging::core::get()->add_global_attribute("ThreadID", attrs::current_thread_id());
        }

        
        
        BOOST_LOG_GLOBAL_LOGGER_INIT(LogW, src::wseverity_logger_mt<LogSeverityLevel>)
        {
            Bootstrap::InitializeLogger();
            src::wseverity_logger_mt<LogSeverityLevel> lg;
            return lg;
        }

        
        
        BOOST_LOG_GLOBAL_LOGGER_INIT(LogA, src::severity_logger_mt<LogSeverityLevel>)
        {
            Bootstrap::InitializeLogger();
            src::severity_logger_mt<LogSeverityLevel> lg;
            return lg;
        }

    }   // namespace LogDetail {

}}}   // namespace Urasandesu { namespace CppAnonym { namespace Logging {
