set (TEST_FILES
	${PROJECT_SOURCE_DIR}/core/level.h
)

add_executable (test_level test_level.cc ${TEST_FILES})
target_link_libraries (test_level ${Boost})
add_test (NAME TestLevel COMMAND test_level)

