#include "device_util.h"

#include <iostream>

namespace logging {

std::string ostreamDeviceName(const std::ostream& os) {
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

}
