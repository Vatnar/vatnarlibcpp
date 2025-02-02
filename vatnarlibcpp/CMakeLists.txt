cmake_minimum_required(VERSION 3.26)
project(VatnarLib)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)


# Add executable
add_executable(VatnarLib src/main.cpp src/Vector2.cpp src/Point2.cpp
        src/Renderer.cpp
        src/Renderer.h)

# Include header files and link libraries
target_include_directories(VatnarLib PRIVATE include)

target_link_libraries(VatnarLib PRIVATE SFML::Graphics)
