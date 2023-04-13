set(TEST_NAME text_editor_test)
add_executable(${TEST_NAME} tests.cpp)
target_link_libraries(${TEST_NAME} gtest_main)

target_link_libraries(${TEST_NAME} ${LIBRARY_NAME} GTest::gtest_main)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
