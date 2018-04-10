cmake_minimum_required(VERSION 3.3.2)   # CMake version check
project(cbackend)                       # Create project "cbackend"
set(CMAKE_CXX_STANDARD 11)              # Enable c++11 standard

set(SOURCE_FILES main.cpp Server.cpp Server.h main.cpp main.h)            # Add main.cpp file of project root directory as source file
add_executable(cbackend ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
add_executable(cbackend_server ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable