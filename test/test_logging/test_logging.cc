#define BOOST_TEST_MODULE Test Logging

#include "../../core/logging.h"

#include <boost/test/included/unit_test.hpp> 

using namespace logging;

BOOST_AUTO_TEST_CASE(test_logging_builds_message) {
	auto msg = buildMsg(Level::INFO, "Test Message");	
	BOOST_CHECK(msg.length() > 0);	
}
