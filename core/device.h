#ifndef DEVICE_H
#define DEVICE_H

#include "device_util.h"

#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>

namespace logging {


class DeviceData {
	public:
		DeviceData(const std::string &_location);
		virtual ~DeviceData() {};

		virtual void write(const std::string& msg) = 0;
		std::string getLocation() const;
		
		bool operator==(const DeviceData& other) {
			return (location == other.location);
		};

		bool operator!=(const DeviceData& other) {
			return !(location == other.location);
		}

		inline void operator<<(const std::string& msg) {
			write(msg);	
		};

		friend std::ostream& operator<<(std::ostream& os, const DeviceData& device) {
			return os << "Device [" << device.location << "]";
		}

	private:
		std::string location;
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

}

#endif
