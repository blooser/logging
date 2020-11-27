#include <sstream>
#include <string>

namespace logging {

namespace strings {

template <typename Ptr>
std::string ptrAddressToStr(Ptr* ptr) {
	std::stringstream ss;
	ss << ptr;
	return ss.str();
}

}

}
