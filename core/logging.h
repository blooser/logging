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
#include <algorithm>

namespace logging {

using Devices = std::vector<std::unique_ptr<DeviceData>>;
Devices& devices();

template <typename Flow>
Devices::iterator findDevice(const Flow& flow) {
	auto device = std::unique_ptr<DeviceData>(DeviceGenerator<Flow>::generate(flow));
	return std::find_if(devices().begin(), devices().end(), [&](auto& other) {
		return (*device == *other);
	});
}

template <typename Flow>
bool exists(const Flow& flow) {
	return (findDevice(flow) != devices().end());
}

template <typename Flow>
bool registerDevice(const Flow& flow) {
	if (exists(flow)) {
		return false;
	}

	auto device = std::unique_ptr<DeviceData>(DeviceGenerator<Flow>::generate(flow));
	devices().push_back(std::move(device));      
	return true;	
}

template <typename Flow>
bool unregisterDevice(const Flow& flow) {
	if (not exists(flow)) {
		return false;
	}

	auto device = findDevice(flow);
	devices().erase(device);
	return true;
}

void unregisterAllDevices();

void log(std::ostream &os, Level level, const char* msg);

std::string buildMsg(Level level, const char* msg);

}

#endif 
