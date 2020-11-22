#ifndef DEVICE_GENERATOR_H
#define DEVICE_GENERATOR_H

#include "device.h"

#include <type_traits>
#include <ostream>

namespace logging {

template <typename Flow>	
struct DeviceGenerator {
	static Device<Flow>* generate(Flow flow) {
		return new Device<Flow>(flow);
	};

};

template <>
struct DeviceGenerator<std::ostream> {
	static Device<std::ostream>* generate(const std::ostream& os) {
		return new Device<std::ostream>();
	}
};

}

#endif
