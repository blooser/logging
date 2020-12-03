#define BOOST_TEST_MODULE Test Level 

#include "../../core/level.h"

#include <boost/test/included/unit_test.hpp> 

using namespace logging;

BOOST_AUTO_TEST_CASE(test_levelcast_cast_to_string) {
    BOOST_CHECK(LevelCast(Level::INFO).toString() == "INFO");		
}
