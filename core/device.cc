#include "device.h"

logging::DeviceData::DeviceData(const std::string &_name) 
  : name(_name) {

}

std::string logging::DeviceData::getName() const {
  return name;
}
 
