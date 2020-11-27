#include "logging.h"

#include "../strings/strings.h"

#define SEPARATOR "  -  "

void logging::log(Level level, const char* msg) {
  std::string log_msg = buildMsg(level, msg);
  for (auto& device : devices()) { 
    (*device) << log_msg;
  }
}

std::string logging::buildMsg(Level level, const char *msg) {
  return logging::strings::join(logging::LevelCast(level).toString(), SEPARATOR, msg, "\n");  
}

logging::Devices& logging::devices() {
  static Devices d;
  return d; 
}

