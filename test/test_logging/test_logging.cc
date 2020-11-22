#define BOOST_TEST_MODULE Test Logging
#include <boost/test/included/unit_test.hpp> 

#include <string>
#include <filesystem>

#include "../../core/logging.h"
#include "../../core/device_generator.h"

using namespace logging;
namespace fs = std::filesystem;

struct FileFixture {
	const std::string FILE_NAME = "log_test.txt";

	~FileFixture() {
		unregisterAllDevices();	
		if (fs::exists(FILE_NAME)) {
			BOOST_TEST_MESSAGE("Removing: " + FILE_NAME);	
			fs::remove(FILE_NAME);
		}
	}
};


BOOST_AUTO_TEST_CASE(test_logging_builds_message) {
	auto msg = buildMsg(Level::INFO, "Test Message");	
	BOOST_CHECK(msg.length() > 0);	
}

BOOST_FIXTURE_TEST_CASE(test_logging_registers_device, FileFixture) {
	BOOST_CHECK(devices().size() == 0);
	BOOST_CHECK(registerDevice(FILE_NAME));	
	BOOST_CHECK(devices().size() > 0);
	BOOST_CHECK(not (registerDevice(FILE_NAME))); // NOTE: Duplicate
}

BOOST_FIXTURE_TEST_CASE(test_logging_unregisters_device, FileFixture) {
	BOOST_CHECK(registerDevice(std::cout));
	BOOST_CHECK(exists(std::cout));
	BOOST_CHECK(unregisterDevice(std::cout));
	BOOST_CHECK(not exists(std::cout));	
}

BOOST_FIXTURE_TEST_CASE(test_logging_returns_device_if_found, FileFixture) {
	registerDevice(FILE_NAME);
	auto device = findDevice(FILE_NAME);
	BOOST_CHECK(typeid(device) == typeid(Devices::iterator));
	BOOST_CHECK(device != devices().end());
}

BOOST_FIXTURE_TEST_CASE(test_logging_finds_exists_device, FileFixture) {
	registerDevice(FILE_NAME);
	BOOST_CHECK(devices().size() > 0);
	BOOST_CHECK(exists(FILE_NAME));
	BOOST_CHECK(not exists(std::cout));
}
