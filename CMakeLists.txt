cmake_minimum_required(VERSION 3.26)
project(DungeonCrawler)

set(CMAKE_CXX_STANDARD 17)

add_executable(DungeonCrawler main.cpp
        dungeonCrawler.cpp
        dungeonCrawler.h
        RNG.cpp
        RNG.h
        namingThings.cpp
        namingThings.h)
