set (TEST_FILES
	${PROJECT_SOURCE_DIR}/core/device.h
	${PROJECT_SOURCE_DIR}/core/device.cc
)

add_executable (test_device test_device.cc ${TEST_FILES})
target_link_libraries (test_device ${Boost})
add_test (NAME TestDevice COMMAND test_device)
