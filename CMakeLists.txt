cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

project(ece2400-sec10 CXX)
enable_testing()

include_directories(include)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(eval)
