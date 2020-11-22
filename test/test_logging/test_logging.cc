#define BOOST_TEST_MODULE Test Logging
#include <boost/test/included/unit_test.hpp> 

#include "../../core/logging.h"
#include "../../core/device_generator.h"

using namespace logging;

BOOST_AUTO_TEST_CASE(test_logging_builds_message) {
	auto msg = buildMsg(Level::INFO, "Test Message");	
	BOOST_CHECK(msg.length() > 0);	
}

BOOST_AUTO_TEST_CASE(test_logging_registers_device) {
	BOOST_CHECK(devices().size() == 0);
	registerDevice("log_test.txt");	
	BOOST_CHECK(devices().size() > 0);
}
