cmake_minimum_required(VERSION 4.1)
project(CS_Final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS_Final
        Attack.cpp
        Attack.h
        Fighting.cpp
        Player.cpp
        Player.h
        Players.cpp
        Players.h
        Game.cpp
        Intro.cpp
        Intro.h)
