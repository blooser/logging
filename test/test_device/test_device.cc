#define BOOST_TEST_MODULE Test Device

#include "../../core/device.h"

#include <boost/test/included/unit_test.hpp> 

#include <vector>
#include <string>
#include <filesystem>

using namespace logging;
namespace fs = std::filesystem;

struct FileFixture {
	std::vector<std::string> files;

	~FileFixture() {
		for (const auto& file : files) {	
			fs::remove(file);
		}
	}

	void generateFiles(const int n=5) {
		for (int i=0; i<n; ++i) {
			files.push_back("file" + std::to_string(i) + ".txt");
		}
	}
};


BOOST_AUTO_TEST_CASE(test_device_data_equality_operator) {
	Device<std::ostream> d1(std::cout);
	Device<std::ostream> d2(std::cout);
	Device<std::ostream> d3(std::clog);
	BOOST_CHECK(d1 == d2);
	BOOST_CHECK(not (d1 != d2));
	BOOST_CHECK(d1 != d3);
}

BOOST_FIXTURE_TEST_CASE(test_device_pointer_equality_operator, FileFixture) {
	generateFiles(2);
	std::ofstream file1(files.at(0));
	std::ofstream file2(files.at(1));
	Device<std::ofstream*> d1(&file1);
	Device<std::ofstream*> d2(&file2);
	Device<std::ofstream*> d11(&file1);
	Device<std::ofstream*> d22(&file2);
	BOOST_CHECK(d1 == d11);
	BOOST_CHECK(d1 != d2);
	BOOST_CHECK(d2 == d22);
}

BOOST_AUTO_TEST_CASE(test_device_transfer_data_to_outupt) {
	Device<std::ostream> d(std::cerr);
	BOOST_CHECK(d.getName() == "cerr");
	std::cerr.clear();
	d << "test message";
	BOOST_CHECK(std::cerr.good());
	BOOST_CHECK(bool(std::cerr));	
}

