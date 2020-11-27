#ifndef STRINGS_H
#define STRINGS_H

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

template <typename ...Strings>
std::string join(const std::string& str,  Strings ...strings) {
	return (str + ... + std::string(strings));		
}

}

}

#endif
