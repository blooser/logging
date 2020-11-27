#ifndef DEVICE_H
#define DEVICE_H

#include "device_util.h"
#include "../strings/strings.h"

#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>

namespace logging {


class DeviceData {
	public:
		DeviceData(const std::string &_name);
		virtual ~DeviceData() {};

		virtual void write(const std::string& msg) = 0;
		std::string getName() const;
		
		bool operator==(const DeviceData& other) {
			return (name == other.name);
		};

		bool operator!=(const DeviceData& other) {
			return !(*this == other);
		}

		inline void operator<<(const std::string& msg) {
			write(msg);	
		};

		friend std::ostream& operator<<(std::ostream& os, const DeviceData& device) {
			return os << "Device [" << device.name << "]";
		}

	private:
		std::string name;
};


template <typename Flow>
class Device : public DeviceData {
	public:
		Device(const Flow& flow) : stream(flow, std::ios::app), DeviceData(flow) {

		}
		
		~Device() {
			stream.close();		
		}

	void write(const std::string& msg) override {
		stream << msg;
	}

	private:
		std::ofstream stream;
};

template <>
class Device<std::ostream> : public DeviceData {
	public:
		Device(std::ostream &os) : stream(os), DeviceData(ostreamDeviceName(os)) {
			
		}
		
	void write(const std::string& msg) override {
		stream << msg;
	}	

	private:
		std::ostream &stream;
};

template <>
class Device<std::ofstream*> : public DeviceData {
	public:
		// NOTE: DeviceData's Constructor is before the Device's constructor 
		Device(std::ofstream* os) : stream(os), DeviceData("ofstream at " + strings::ptrAddressToStr(os)) {

		}

		~Device() {
			
		}

		void write(const std::string& msg) override {
			if (not stream or not stream->is_open()) {
				return;
			}

			(*stream) << msg;
		}

	private:
		std::ofstream* stream;
};

}

#endif
