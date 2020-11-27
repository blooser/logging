#define BOOST_TEST_MODULE Test Logging
#include <boost/test/included/unit_test.hpp> 

#include <string>
#include <filesystem>
#include <algorithm>
#include <iterator>

#include "../../core/logging.h"
#include "../../core/device_generator.h"

using namespace logging;
namespace fs = std::filesystem;

struct FileFixture {
	const std::string FILE_NAME = "log_test.txt";

	~FileFixture() {
		unregisterDevices();	
		if (fs::exists(FILE_NAME)) {
			BOOST_TEST_MESSAGE("Removing: " + FILE_NAME);	
			fs::remove(FILE_NAME);
		}
	}

	std::string load(const std::string& path) {
    std::ifstream file(path);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	}
};

BOOST_AUTO_TEST_CASE(test_logging_builds_message) {
	auto msg = buildMsg(Level::INFO, "Test Message");	
	BOOST_CHECK(msg.find("INFO") != std::string::npos);
	BOOST_CHECK(msg.find("Test Message") != std::string::npos);	
}

BOOST_FIXTURE_TEST_CASE(test_logging_registers_device, FileFixture) {
	BOOST_CHECK(devices().size() == 0);
	BOOST_CHECK(registerDevice(FILE_NAME));	
	BOOST_CHECK(devices().size() > 0);
	BOOST_CHECK(not (registerDevice(FILE_NAME))); // NOTE: Duplicate
}

BOOST_AUTO_TEST_CASE(test_logging_registers_multiple_devices_and_unregister_them) {
	BOOST_CHECK(devices().size() == 0);
	registerDevices(std::cout, std::cerr, "test.txt");
	BOOST_CHECK(devices().size() == 3);
	unregisterDevices(std::cerr, "test.txt");
	BOOST_CHECK(devices().size() == 1);
	unregisterDevices(std::cout);
	BOOST_CHECK(devices().size() == 0);
}

BOOST_AUTO_TEST_CASE(test_logging_unregisters_all_devices_if_no_arguments_in_unregister_method) {
	BOOST_CHECK(devices().size() == 0);
	registerDevices(std::cout, "hello.txt", "test.txt", std::cerr);
	BOOST_CHECK(devices().size() == 4);
	unregisterDevices();
	BOOST_CHECK(devices().size() == 0);
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

BOOST_FIXTURE_TEST_CASE(test_logging_registers_and_unregisters_ofstream, FileFixture) {
	std::ofstream file(FILE_NAME);
	BOOST_CHECK(file.is_open());
	registerDevice(&file);
	BOOST_CHECK(devices().size());
	log(Level::WARN, "This is warn");
	unregisterDevices(&file);
	BOOST_CHECK(not devices().size());
}

BOOST_AUTO_TEST_CASE(test_logging_pointer_equality_operator) {
	unregisterDevices();
	BOOST_CHECK(not devices().size());	

	std::ofstream os1;
	std::ofstream os2;

	registerDevices(&os1, &os2);
	BOOST_CHECK(devices().size() == 2);
	unregisterDevice(&os2);
	BOOST_CHECK(devices().size() == 1);
	unregisterDevice(&os1);
	BOOST_CHECK(devices().size() == 0);
}

BOOST_FIXTURE_TEST_CASE(test_logging_finds_exists_device, FileFixture) {
	registerDevice(FILE_NAME);
	BOOST_CHECK(devices().size() > 0);
	BOOST_CHECK(exists(FILE_NAME));
	BOOST_CHECK(not exists(std::cout));
	BOOST_CHECK(not exists("i_do_not_exist.txt"));
}
