#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>

namespace logging {


class DeviceData {
	public:
		DeviceData(const std::string &_location);

		virtual std::ostream& getStream() = 0;
		std::string getLocation() const;
		
		bool operator==(const DeviceData& other) {
			return (location == other.location);
		};

		bool operator!=(const DeviceData& other) {
			return !(location == other.location);
		}

		inline void operator<<(const std::string &msg) {
			getStream() << msg;
		};

		friend std::ostream& operator<<(std::ostream& os, const DeviceData &device) {
			return os << "Device [" << device.location << "]";
		}

	private:
		std::string location;
};


template <typename Flow>
class Device : public DeviceData {
	public:
		Device(Flow flow) : stream(flow), DeviceData(flow) {
			
		}
		
		~Device() {
			stream.close();		
		}

		std::ostream& getStream() {
			return stream;
		}

	private:
		std::ofstream stream;
};

template <>
class Device<std::ostream> : public DeviceData {
	public:
		Device() : DeviceData("cout") {
			
		}
		
		std::ostream& getStream(){
			return std::cout;
		}
};

}

#endif
