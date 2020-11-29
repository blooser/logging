#include "logging.h"

#include "../strings/strings.h"
#include "../time/time.h"

#include "filter.h"

namespace logging {

void log(Level level, const char* msg) {
  if (static_cast<int>(level) != static_cast<int>(filter) and filter != Filter::ALL) {
    return;
  } 

  std::string log_msg = MessageBuilder(msg).build(level); 
  for (auto& device : devices()) { 
    (*device) << log_msg;
  }
}

Devices& devices() {
  static Devices d;
  return d; 
}

const std::string MessageBuilder::SEPARATOR = " - ";
const std::string MessageBuilder::NEW_LINE = "\n";

std::string MessageBuilder::build(Level level) {
  return strings::join(LevelCast(level).toString(), SEPARATOR, time::currentTime(), SEPARATOR, message, NEW_LINE);  
}



}
