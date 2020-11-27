#ifndef LEVEL_H
#define LEVEL_H

#include <string>

namespace logging {

enum class Level {
	INFO,
	WARN,
	ERROR,
	FATAL,
	DEBUG
};


struct LevelCast {
	LevelCast(const Level levelToCast) : level(levelToCast) {}

	std::string toString() {	
		switch (level) {
				case Level::INFO:
					return "INFO";
				case Level::WARN:
					return "WARN";
				case Level::ERROR:
					return "ERROR";
				case Level::FATAL:
					return "FATAL";
				case Level::DEBUG:
					return "DEBUG";
				default:
					return "Unknown"; 
			}
	}

	private:
		Level level;
};

}

#endif
