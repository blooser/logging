#define BOOST_TEST_MODULE Test Device

#include "../../core/device_util.h"

#include <boost/test/included/unit_test.hpp> 

using namespace logging;

BOOST_AUTO_TEST_CASE(test_device_util_returns_device_names) {
    BOOST_CHECK(ostreamDeviceName(std::cout) == "cout");
    BOOST_CHECK(ostreamDeviceName(std::cerr) == "cerr");
    BOOST_CHECK(ostreamDeviceName(std::clog) == "clog");
}
