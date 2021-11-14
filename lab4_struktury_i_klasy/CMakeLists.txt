cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  17)

include_directories(include)
add_executable(lab4 src/main.cpp src/struktury.cpp src/Prostopadloscian.cpp include/Prostopadloscian.h src/Kula.cpp include/Kula.h src/FunkcjaKwadratowa.cpp include/FunkcjaKwadratowa.h src/Student.cpp include/Student.h src/Punkt.cpp include/Punkt.h src/Figura.cpp include/Figura.h src/PrzykladDesktruktor.cpp include/PrzykladDesktruktor.h)