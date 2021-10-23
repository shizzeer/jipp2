# plik cmake tworzacy biblioteke

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  17)

include_directories(../include)

# Skompilowanie pliku zrodlowego do formatu statycznej biblioteki.
# Oznacza to, ze biblioteka ta bedzie wkompilowana do kodu aplikacji.
# W zwiazku z tym dostepne beda jej funkcje, ale rozmiar kodu aplikacji sie zwiekszy.
add_library(matrixLib STATIC src/matrixLib.cpp)
