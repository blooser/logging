#include "logging.h"

#include "../strings/strings.h"
#include "../time/time.h"
#include <sstream>

#include "filter.h"

namespace logging {

std::string MESSAGE_FORMAT = DEFAULT_MESSAGE_FORMAT; 

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
  return strings::join(LevelCast(level).toString(), SEPARATOR, formatTranslate(MESSAGE_FORMAT), NEW_LINE);  
}

std::string MessageBuilder::formatTranslate(const std::string& format) {
  auto it = format.begin();
  std::stringstream output;
  
  while (it != format.end()) {
    if (*it == '%') {
      switch (*(++it)) {
        case 't':
          output << time::currentTime();
          break;
        case 'm':
          output << message;
          break;
        default:
          std::cerr << "Incorrect format parameter: " << *it << NEW_LINE; 
      }
      ++it;
      continue;
    }

    output << *it++; 
 }

  return output.str();
}


}
