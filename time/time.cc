#include "time.h"

#include <ctime>

namespace logging {

namespace time {

std::string currentTime() {
	std::time_t time = std::time(nullptr);
	char bufor[100];	
	std::strftime(bufor, sizeof(bufor), "%F %T", std::gmtime(&time));
	return bufor;
}

}

}
