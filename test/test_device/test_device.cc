#define BOOST_TEST_MODULE Test Device

#include "../../core/device.h"

#include <boost/test/included/unit_test.hpp> 

using namespace logging;

BOOST_AUTO_TEST_CASE(test_device_data_equality_operator) {
	Device<std::ostream> d1;
	Device<std::ostream> d2;
	Device<std::string> d3("test.txt");
	BOOST_CHECK(d1 == d2);
	BOOST_CHECK(!(d1 != d2));
	BOOST_CHECK(d1 != d3);
}

BOOST_AUTO_TEST_CASE(test_device_transfer_data_to_cout) {
	Device<std::ostream> d;
	BOOST_CHECK(d.getLocation() == "cout");
	std::cout.clear();
	d << "test message";
	BOOST_CHECK(bool(std::cout));	
}



