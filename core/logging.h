#include "level.h"

#include <iostream>
#include <string>
#include <ostream>

namespace logging {

void log(std::ostream &os, Level level, const char* msg);

std::string buildMsg(Level level, const char *msg);

}
