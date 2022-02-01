cmake_minimum_required(VERSION 3.16)
project(PassMan)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(lib/openssl/include/openssl)
link_directories(lib/openssl)

add_executable(passman src/main.cpp src/DbManager.cpp src/DbCrypto.cpp src/Database.cpp src/PasswordGenerator.cpp)

target_link_libraries(passman libcrypto.a)
target_link_libraries(passman libssl.a)
