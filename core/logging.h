#include "level.h"
#include "device.h"

#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <memory>

namespace logging {

using Devices = std::vector<std::unique_ptr<DeviceData>>;
Devices& devices();

template <typename Flow>
bool registerDevice(Flow flow);

void log(std::ostream &os, Level level, const char* msg);

std::string buildMsg(Level level, const char *msg);

}
