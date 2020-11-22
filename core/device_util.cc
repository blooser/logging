#include "device_util.h"

#include <iostream>

std::string logging::ostreamDeviceName(const std::ostream& os) {
	if (&os == &std::cout) {
		return "cout";
	} else if (&os == &std::cerr) {
		return "cerr";
	} else if (&os == &std::clog) {
		return "clog";
	} else {
		return "unknown";
	}
}
