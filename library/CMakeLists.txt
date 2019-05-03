cmake_minimum_required(VERSION 2.8.12)

project(library)

add_compile_options(-std=c++17 -Wall)

set(SOURCES_LIST sources/basic.cpp sources/unit_types.cpp sources/french_units.cpp sources/country.cpp sources/init_france.cpp sources/game.cpp)
set(HEADERS_LIST headers/basic.h headers/unit_types.h headers/french_units.h headers/country.h headers/init_france.h headers/game.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(library ${SOURCES_LIST} ${HEADERS_LIST})
