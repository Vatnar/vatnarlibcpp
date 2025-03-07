cmake_minimum_required(VERSION 3.26)
project(VatnarLib)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
find_package(ImGui-SFML REQUIRED)

set(SFML_STATIC_LIBRARIES TRUE)


file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(VatnarLib ${SOURCES})

target_include_directories(VatnarLib PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-graphics sfml-window sfml-system
        ImGui-SFML::ImGui-SFML)
