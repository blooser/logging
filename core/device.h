#ifndef DEVICE_H
#define DEVICE_H

#include "../strings/strings.h"
#include "../types/types.h"

#include "device_util.h"

#include <boost/type_index.hpp>
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
    static_assert(types::is_string_like<Flow>(), "Type is not a string like");				
    
    public:
        Device(const Flow& flow) : stream(flow, std::ios::app), DeviceData(flow) {}
        
        ~Device() {
            stream.close();		
        }

    void write(const std::string& msg) override {
        stream << msg;
    }

    private:
        std::ofstream stream;
};

template <typename Flow> 
class Device<Flow*> : public DeviceData {
    static_assert(types::is_streamable<Flow, const std::string&>::value, "Type is not streamable");

    public:
        Device(Flow* flow) : stream{flow}, DeviceData(strings::ptrAddressToStr(flow)) {}	

    void write(const std::string& msg) override {	
            (*stream) << msg;
        }


    private:
        Flow* stream;
};


template <>
class Device<std::ostream> : public DeviceData {
    public:
        Device(std::ostream &os) : stream{os}, DeviceData(ostreamDeviceName(os)) {

    }
        
    void write(const std::string& msg) override {
        stream << msg;
    }	

    private:
        std::ostream& stream;
};

}

#endif
