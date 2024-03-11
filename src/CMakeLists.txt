cmake_minimum_required(VERSION 3.17.5)

project(libpeinfo VERSION 1.1.1.1 LANGUAGES CXX)

add_library(libpeinfo INTERFACE parser.h section_header.h standard_fields.h win_specific_fields.h pattern.h pe_header.h constants.h characteristics.h
        util.h)

set_property(TARGET libpeinfo PROPERTY CXX_STANDARD 20)

target_include_directories(libpeinfo INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
