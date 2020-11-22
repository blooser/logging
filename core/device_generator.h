#include "device.h"

#include <type_traits>

namespace logging {

template <typename Flow>	
struct DeviceGenerator {
	static Device<Flow>* generate(const std::string& location) {
		return new Device<Flow>(location);
	};

};

template <>
struct DeviceGenerator<std::ostream> {
	static Device<std::ostream>* generate(const std::ostream& os) {
		return new Device<std::ostream>();
	}
};

}
