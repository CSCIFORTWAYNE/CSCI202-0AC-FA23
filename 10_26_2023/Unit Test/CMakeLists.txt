cmake_minimum_required(VERSION 2.8.12)

project(Test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(student SHARED donut.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--wrap=main")

add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} student pthread)