cmake_minimum_required(VERSION 3.14)

# set the project name
project(tdd_gtest VERSION 0.1.0)

include_directories(include)
# add the executable
add_executable(hello_world src/hello_world.cpp)

add_subdirectory(googletest)
add_subdirectory(tests)
