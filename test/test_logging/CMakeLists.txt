set (TEST_FILES
    ${PROJECT_SOURCE_DIR}/core/logging.h
    ${PROJECT_SOURCE_DIR}/core/logging.cc
    ${PROJECT_SOURCE_DIR}/core/device.h
    ${PROJECT_SOURCE_DIR}/core/device.cc
    ${PROJECT_SOURCE_DIR}/core/device_generator.h
    ${PROJECT_SOURCE_DIR}/core/device_util.h
    ${PROJECT_SOURCE_DIR}/core/device_util.cc
    ${PROJECT_SOURCE_DIR}/core/level.h
    ${PROJECT_SOURCE_DIR}/core/filter.h
    ${PROJECT_SOURCE_DIR}/core/filter.cc
    ${PROJECT_SOURCE_DIR}/time/time.h
    ${PROJECT_SOURCE_DIR}/time/time.cc
    ${PROJECT_SOURCE_DIR}/types/types.h
)

add_executable(test_logging test_logging.cc ${TEST_FILES})
target_link_libraries(test_logging ${Boost})
add_test(NAME TestLogging COMMAND test_logging)
