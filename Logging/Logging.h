#pragma once

#include "boost/log/trivial.hpp"
#include "boost/log/utility/setup.hpp"

namespace logging = boost::log;

enum severity_level
{
    trace,
    debug,
    info,
    processing_perf,
    processing_info,
    warning,
    error,
    fatal
};

void init_logging();