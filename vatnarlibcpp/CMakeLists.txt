cmake_minimum_required(VERSION 3.30)
project(VatnarLib)

set(CMAKE_CXX_STANDARD 14)

add_executable(VatnarLib src/main.cpp src/Vector2.cpp src/Circle2D.cpp
)
target_include_directories(VatnarLib PRIVATE include)
