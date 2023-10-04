cmake_minimum_required(VERSION 3.0)
project(TEST)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB MY_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
add_executable(test test.cpp ${MY_HEAD})
