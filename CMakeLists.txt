cmake_minimum_required(VERSION 3.15.0)

project(tsk-scheduler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17 -Wall")

find_package(Boost COMPONENTS system date_time REQUIRED)
find_package(Threads REQUIRED)

enable_testing()

add_subdirectory(test)
add_subdirectory(src)

install (PROGRAMS ${CMAKE_SOURCE_DIR}/bin/start.sh
    DESTINATION ${PROJECT_BINARY_DIR}/bin)