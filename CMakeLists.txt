cmake_minimum_required(VERSION 3.25)
project(complete)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(complete main.cpp speechManager.cpp speechManager.h player.cpp player.h)
