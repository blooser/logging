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
#include <initializer_list>

namespace logging {

using Devices = std::vector<std::unique_ptr<DeviceData>>;
Devices& devices();

static const std::string DEFAULT_MESSAGE_FORMAT = "%t - %m";
extern std::string MESSAGE_FORMAT;

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

template <typename... Flows>
void registerDevices(const Flows&... flows) {
	(registerDevice(flows), ...);
}

template <typename Flow>
bool unregisterDevice(const Flow& flow) {
	auto device = findDevice(flow);

	if (device == devices().end()) {
		return false;
	}

	devices().erase(device);
	return true;
}

template <typename ...Flows>
void unregisterDevices(const Flows&... flows) {
	if (not sizeof...(Flows)) {
		devices().clear();
		return;
	}

	(unregisterDevice(flows), ...);
}

void log(Level level, const char* msg);
void printDevices();

struct MessageBuilder {
	MessageBuilder(const char* msg) : message(msg) {}

	std::string build(Level level); 
	std::string formatTranslate(const std::string& format);

	private:
		const char* message;
		static const std::string SEPARATOR;
		static const std::string NEW_LINE;
};

#define INFO(msg) logging::log(logging::Level::INFO, msg)
#define WARN(msg) logging::log(logging::Level::WARN, msg)
#define ERROR(msg) logging::log(logging::Level::ERROR, msg)
#define FATAL(msg) logging::log(logging::Level::FATAL, msg)
#define DEBUG(msg) logging::log(logging::Level::DEBUG, msg)

}

#endif 
