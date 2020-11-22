#ifndef LOGGING_H
#define LOGGING_H

#include "level.h"
#include "device.h"
#include "device_generator.h"

#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <memory>

namespace logging {

using Devices = std::vector<std::unique_ptr<DeviceData>>;
Devices& devices();

template <typename Flow>
bool registerDevice(Flow flow) {
 auto device = std::unique_ptr<DeviceData>(DeviceGenerator<Flow>::generate(flow));
 devices().push_back(std::move(device));      
}

template <typename Flow>
bool unregisterDevice(Flow flow) {

}

void log(std::ostream &os, Level level, const char* msg);

std::string buildMsg(Level level, const char *msg);

}

#endif 
