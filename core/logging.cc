#include "logging.h"
#include "device_generator.h"

#define SEPARATOR "  -  "

void logging::log(std::ostream &os, Level level, const char* msg) {
  os << buildMsg(level, msg);
}

std::string logging::buildMsg(Level level, const char *msg) {
  return logging::levelToStr(level) + SEPARATOR + msg;  
}

logging::Devices& logging::devices() {
  static Devices d;
  return d; 
}

