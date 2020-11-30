set (TEST_FILES
	${PROJECT_SOURCE_DIR}/types/types.h
)

add_executable (test_types test_types.cc ${TEST_FILES})
target_link_libraries (test_types ${Boost})
add_test (NAME TestTypes COMMAND test_types)


