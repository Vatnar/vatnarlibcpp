cmake_minimum_required(VERSION 3.29)
project(vatnarlibcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(vatnarlibcpp main.cpp
        Point2D.cpp
        Point2D.h
        Circle2D.cpp
        Circle2D.h)
