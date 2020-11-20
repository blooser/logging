#include <string>

namespace logging {

enum class Level {
	INFO,
	WARN,
	ERROR,
	FATAL,
	DEBUG
};

std::string levelToStr(Level level);

}
