#include "logging.h"

#include "../strings/strings.h"

void logging::log(Level level, const char* msg) {
  std::string log_msg = MessageBuilder(msg).build(level); 
  for (auto& device : devices()) { 
    (*device) << log_msg;
  }
}

logging::Devices& logging::devices() {
  static Devices d;
  return d; 
}

const std::string logging::MessageBuilder::SEPARATOR = " - ";
const std::string logging::MessageBuilder::NEW_LINE = "\n";

std::string logging::MessageBuilder::build(Level level) {
  return logging::strings::join(logging::LevelCast(level).toString(), SEPARATOR, message, NEW_LINE);  
}
