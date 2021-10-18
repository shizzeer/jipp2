cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

# project(firstLib)

include_directories(include) # Mowimy kompilatorowi ze pliki naglowkowe znajduja sie w folderze include
add_library(firstLibLib STATIC src/lib.cpp) # Kompilacja biblioteki