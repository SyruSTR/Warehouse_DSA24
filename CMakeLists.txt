cmake_minimum_required(VERSION 3.29)
project(warehouse)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_COMPILER_CLANG_SCAN_DEPS "/usr/bin/clang-scan-deps")

add_executable(warehouse main.cpp
        Hashmap.cpp
        Hashmap.h)
