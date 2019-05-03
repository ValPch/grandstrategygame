cmake_minimum_required(VERSION 2.8.12)

project(tester)

add_compile_options(-std=c++17 -Wall)

set(SOURCES_LIST tester/tester.cpp tester/tests.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/library)

add_subdirectory(library)

add_executable(tester.exe ${SOURCES_LIST})

target_link_libraries(tester.exe library)

