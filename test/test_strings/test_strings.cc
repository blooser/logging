#define BOOST_TEST_MODULE Test Strings

#include <boost/test/included/unit_test.hpp> 

#include "../../strings/strings.h"

using namespace logging::strings;

BOOST_AUTO_TEST_CASE(test_strings_converts_pointer_address_to_string) {
	int *ptr = (int*)0x44ff80;
	auto address = ptrAddressToStr(ptr);
	BOOST_CHECK(typeid(address) == typeid(std::string));
	BOOST_CHECK(address.length());
	BOOST_CHECK(address == "0x44ff80");
}
