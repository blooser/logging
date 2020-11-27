set (TEST_FILES
	${PROJECT_SOURCE_DIR}/strings/strings.h
)

add_executable (test_strings test_strings.cc ${TEST_FILES})
add_test(NAME TestStrings COMMAND test_strings)
