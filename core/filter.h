#ifndef FILTER_H
#define FILTER_H

namespace logging {

enum class Filter {
    INFO_ONLY,
    WARN_ONLY,
    ERROR_ONLY,
    FATAL_ONLY,
    DBUG_ONLY,	
    ALL	
};

extern Filter filter;

};

#endif
