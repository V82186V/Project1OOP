cmake_minimum_required(VERSION 3.21)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp Rooms.h Rooms.cpp Date.h Date.cpp Init.cpp Hotel.cpp Hotel.h RoomDB.h RoomDB.cpp Init.h)
