#define BOOST_TEST_MODULE Test Device

#include "../../core/device_generator.h"

#include <boost/test/included/unit_test.hpp> 

#include <filesystem>

using namespace logging;
namespace fs = std::filesystem;

struct FileFixture {
    std::string FILE_NAME = "test.txt";

    ~FileFixture() {
        if (fs::exists(FILE_NAME)) {
            fs::remove(FILE_NAME);
        }	
    }
};

BOOST_FIXTURE_TEST_CASE(test_device_generator_generates_device, FileFixture) {
    auto d1 = DeviceGenerator<std::string>::generate(FILE_NAME);
    BOOST_CHECK(typeid(*d1) == typeid(Device<std::string>));
    delete d1;

    auto d2 = DeviceGenerator<std::ostream>::generate(std::cerr);
    BOOST_CHECK(typeid(*d2) == typeid(Device<std::ostream>));
    delete d2;
}

