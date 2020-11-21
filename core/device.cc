#include "device.h"

logging::DeviceData::DeviceData(const std::string &_location) 
  : location(_location) {

}

std::string logging::DeviceData::getLocation() const {
  return location;
}
 
