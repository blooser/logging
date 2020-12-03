set (TEST_FILES
    ${PROJECT_SOURCE_DIR}/core/device.h
    ${PROJECT_SOURCE_DIR}/core/device.cc
    ${PROJECT_SOURCE_DIR}/core/device_generator.h
    ${PROJECT_SOURCE_DIR}/core/device_util.h
    ${PROJECT_SOURCE_DIR}/core/device_util.cc
)

add_executable (test_device_generator test_device_generator.cc ${TEST_FILES})
target_link_libraries (test_device_generator ${Boost})
add_test (NAME TestDeviceGenerator COMMAND test_device_generator)
