#include "logging.h"
#include "device_generator.h"

#define SEPARATOR "  -  "

void logging::log(Level level, const char* msg) {
  std::string log_msg = buildMsg(level, msg);
  for (auto& device : devices()) { 
    (*device) << log_msg;
  }
}

std::string logging::buildMsg(Level level, const char *msg) {
  return logging::levelToStr(level) + SEPARATOR + msg + "\n";  
}

logging::Devices& logging::devices() {
  static Devices d;
  return d; 
}

void logging::unregisterAllDevices() {
  devices().clear();
}
