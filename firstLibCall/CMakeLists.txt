cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

# project(firstLibCall)

# Plikow naglowkowych szukaj w folderze include dolaczanej biblioteki
include_directories(../firstLib/include)
# Stworz plik wykonywalny o nazwie firstLibCall
add_executable(firstLibCall main.cpp)
# Podlacz pod stworzony plik wykonywalny utworzona biblioteke
target_link_libraries(firstLibCall firstLibLib)