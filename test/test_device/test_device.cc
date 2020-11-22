#define BOOST_TEST_MODULE Test Device

#include "../../core/device.h"

#include <boost/test/included/unit_test.hpp> 

using namespace logging;

BOOST_AUTO_TEST_CASE(test_device_data_equality_operator) {
	Device<std::ostream> d1(std::cout);
	Device<std::ostream> d2(std::cout);
	Device<std::ostream> d3(std::clog);
	BOOST_CHECK(d1 == d2);
	BOOST_CHECK(not (d1 != d2));
	BOOST_CHECK(d1 != d3);
}

BOOST_AUTO_TEST_CASE(test_device_transfer_data_to_cout) {
	Device<std::ostream> d(std::cerr);
	BOOST_CHECK(d.getLocation() == "cerr");
	std::cerr.clear();
	d << "test message";
	BOOST_CHECK(bool(std::cerr));	
}

