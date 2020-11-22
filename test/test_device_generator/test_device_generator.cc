#define BOOST_TEST_MODULE Test Device

#include "../../core/device_generator.h"

#include <boost/test/included/unit_test.hpp> 

using namespace logging;

BOOST_AUTO_TEST_CASE(test_device_generator_generates_device) {
	auto d1 = DeviceGenerator<std::string>::generate("test.txt");
	BOOST_CHECK(typeid(*d1) == typeid(Device<std::string>));
	delete d1;

	auto d2 = DeviceGenerator<std::ostream>::generate(std::cerr);
	BOOST_CHECK(typeid(*d2) == typeid(Device<std::ostream>));
	delete d2;
}

