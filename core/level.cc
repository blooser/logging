#include "level.h"

std::string logging::levelToStr(Level level) {
  using logging::Level;

  switch (level) {
    case Level::INFO:
      return "INFO";
    case Level::WARN:
      return "WARN";
    case Level::ERROR:
      return "ERROR";
    case Level::FATAL:
      return "FATAL";
    case Level::DEBUG:
      return "DEBUG";
    default:
      return "Unknown";
  }
}
