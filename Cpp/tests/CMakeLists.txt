cmake_minimum_required(VERSION 3.14)
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# Now simply link against gtest or gtest_main as needed. Eg
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(ut_hello_world ut_hello_world.cpp)
target_link_libraries(ut_hello_world gtest_main)

add_executable(ut_functions ut_functions.cpp)
target_link_libraries(ut_functions gtest_main)
gtest_discover_tests(ut_hello_world ut_functions)

