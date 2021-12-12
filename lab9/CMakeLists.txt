cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  17)

include_directories(include)
add_executable(lab9 src/main.cpp src/MP3Player.cpp include/MP3Player.h)
add_subdirectory(StopExample)