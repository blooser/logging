cmake_minimum_required(VERSION 3.12)

project (logging VERSION 0.0.1 DESCRIPTION "Logging library")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (CORE_FILES
	core/level.h
	core/level.cc
	core/logging.h
	core/logging.cc
	core/device.h
	core/device.cc
	core/device_generator.h
	core/device_util.h
	core/device_util.cc
)

enable_testing()
add_subdirectory (test)

add_library (logging SHARED ${CORE_FILES})
