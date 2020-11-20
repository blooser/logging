#include "logging.h"

#define SEPARATOR "  -  "

void logging::log(std::ostream &os, Level level, const char* msg) {
  os << buildMsg(level, msg);
}

std::string logging::buildMsg(Level level, const char *msg) {
  return logging::levelToStr(level) + SEPARATOR + msg;  
}
