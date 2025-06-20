cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(MyUtilities)

include_directories(Config)

file(GLOB_RECURSE SOURCES "Config/*.cpp")

add_library(MyUtilities ${SOURCES})

add_executable(MyUtilitiesTest main.cpp)
set(EXECUTABLE_OUTPUT_PATH D:\\Code\\MyUtilities)

target_link_libraries(MyUtilitiesTest MyUtilities)