# VatnarLib
## Quick Links
- [Planned Features](#planned-features)
- [Implementation Checklist](#implementation-checklist)
- [How to Build and Run](#how-to-build-and-run)

VatnarLib is a graphics library written in C++.
It is designed primarily for learning purposes 
but includes foundational features to support 
basic graphic rendering and animations.


## Planned Features
- **Window creation with SMFL**: Set up a basic window with SMFL.
- **2D Drawing**: Draw 2D shapes and objects.
- **Colors**: Integrate color manipulation for shapes and backgrounds.
- **Camera movement**: Enable a moving camera for 3D navigation.
- **3D Drawing**: Support 3D shape rendering.
- **Interactive Drawing**: Allow user input for interactive graphics.

### Future Ideas
- **Interactive Terminal**: Add a terminal interface for commands and adjustments.
- **Raytracing**: Integrate with Pandora raytracing library

## Implementation Checklist
- [x] **Vector and Point classes (2D) Logic**
- [X] **Automatically fetch dependencies with CMake**
- [ ] **Shapes API**: API for Shape creation and manipulation.
- [ ] **SMFL Window Drawing**
- [ ] **Pixel Drawing with SMFL**
- [ ] **SMFL Shapes**: API for drawing shapes with SMFL.
- [ ] **Parametric Curves**
- [ ] **Vector Object Drawing**
- [ ] **3D Rendering**

## How to Build and Run

1. **Prerequisites**:
    - **CMake**: Install CMake from [here](https://cmake.org/download/).
    - **C++ Compiler**: Ensure you have a C++20-compatible compiler (e.g., `g++`, `clang++`, or MSVC on Windows).
    - **SFML**: The project fetches SFML automatically during the build process.

2. **Clone the Repository**:
   Clone the repository to your local machine:
    ```bash
    git clone https://github.com/Vatnar/vatnarlibcpp.git
    cd vatnarlibcpp
    ```

3. **Build**:
   Using CMake:
    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

4. **Run**:
   It’s recommended to run from the command line for logs:
    ```bash
    ./bin/VatnarLib
    ```

---
