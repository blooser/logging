#ifndef DEVICE_GENERATOR_H
#define DEVICE_GENERATOR_H

#include "device.h"

#include <type_traits>
#include <ostream>
#include <fstream>

namespace logging {

template <typename Flow>	
struct DeviceGenerator {
    static Device<Flow>* generate(const Flow& flow) {
        return new Device<Flow>(flow);
    };
};

template <typename Flow>
struct DeviceGenerator<Flow*> {
    static Device<Flow*>* generate(Flow* flow) {
        return new Device<Flow*>(flow);
    }
};

template <>
struct DeviceGenerator<std::ostream> {
    static Device<std::ostream>* generate(const std::ostream& os) {
        return new Device<std::ostream>(const_cast<std::ostream&>(os));
    }
};

}

#endif
