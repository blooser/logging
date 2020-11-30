#define BOOST_TEST_MODULE Test Types 
#include <boost/test/included/unit_test.hpp> 

#include "../../types/types.h"

#include <iostream>

using namespace logging;

BOOST_AUTO_TEST_CASE(test_is_streamable) {
	BOOST_CHECK(bool(types::is_streamable<std::ostream, std::string>::value));
	BOOST_CHECK(not bool(types::is_streamable<int, std::string>::value));	
}

BOOST_AUTO_TEST_CASE(test_is_string_like) {
	BOOST_CHECK(types::is_string_like<char*>());
	BOOST_CHECK(types::is_string_like<std::string>());
	BOOST_CHECK(not types::is_string_like<int>());
	BOOST_CHECK(not types::is_string_like<bool>());
}

