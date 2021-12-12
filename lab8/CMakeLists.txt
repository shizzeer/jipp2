cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  17)

include_directories(include)
add_executable(notes src/main.cpp src/Note.cpp src/TextNote.cpp include/TextNote.h src/ListNote.cpp include/ListNote.h src/NoteDirector.cpp include/NoteDirector.h)