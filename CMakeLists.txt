cmake_minimum_required(VERSION 3.12)

project (logging VERSION 0.0.1 DESCRIPTION "Logging library")

set (CORE_FILES
	core/level.h
	core/level.cc
	core/logging.h
	core/logging.cc
)

add_library (logging SHARED ${CORE_FILES})
