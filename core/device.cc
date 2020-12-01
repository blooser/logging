#include "device.h"

namespace logging {

DeviceData::DeviceData(const std::string &_name) 
  : name(_name) {

}

std::string DeviceData::getName() const {
  return name;
}
 
}
