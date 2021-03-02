cmake_minimum_required(VERSION 3.17)
project(Starcraft)

set(CMAKE_CXX_STANDARD 14)

add_executable(Starcraft main.cpp Unit.h Unit.cpp Zergling.h Zergling.cpp Marine.h Marine.cpp Stalker.h Stalker.cpp)