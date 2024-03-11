cmake_minimum_required(VERSION 3.17.5)

project(PEInfo VERSION 1.0.1.1 LANGUAGES CXX)

add_subdirectory(src)

add_executable(peinfo example.cpp)

target_compile_options(peinfo PRIVATE -Wall -Wextra -pedantic -fno-omit-frame-pointer)
target_compile_features(peinfo PRIVATE cxx_std_20)
target_link_options(peinfo PRIVATE -fno-omit-frame-pointer)

target_link_libraries(peinfo PRIVATE libpeinfo)
