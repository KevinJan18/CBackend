cmake_minimum_required(VERSION 3.3.2)   # CMake version check
project(cbackend)                       # Create project "cbackend"
set(CMAKE_CXX_STANDARD 11)              # Enable c++11 standard

include_directories (${lib})
set(CMAKE_SOURCE_DIR, src)
set(SOURCE_FILES src/main.cpp src/main.h lib/Server/Server.h lib/Server/Server.cpp)            # Add main.cpp file of project root directory as source file

add_executable(cbackend ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
add_executable(server ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
if(WIN32)
    target_link_libraries(cbackend wsock32 ws2_32)
endif()
