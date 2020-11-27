#include "device.h"

logging::DeviceData::DeviceData(const std::string &_name) 
  : name(_name), corrupted(false) {

}

std::string logging::DeviceData::getName() const {
  return name;
}

bool logging::DeviceData::isCorrupted() const {
  return corrupted;
}
 
