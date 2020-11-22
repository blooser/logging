set (TEST_FILES
	${PROJECT_SOURCE_DIR}/core/device_util.h
	${PROJECT_SOURCE_DIR}/core/device_util.cc
)

add_executable(test_device_util test_device_util.cc ${TEST_FILES})
target_link_libraries(test_device_util ${Boost})
add_test(NAME TestDeviceUtil COMMAND test_device_util)
