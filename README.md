# VatnarLib
## Quick Links
- [Planned Features](#planned-features)
- [Implementation Checklist](#implementation-checklist)
- [How to Build and Run](#how-to-build-and-run)

VatnarLib is a graphics library written in C++. It is designed primarily for learning purposes but includes foundational features to support basic graphic rendering and animations.


## Planned Features
- **Window creation with OpenGL**: Set up a basic window with OpenGL.
- **2D Drawing**: Draw 2D shapes and objects.
- **Colors**: Integrate color manipulation for shapes and backgrounds.
- **Camera movement**: Enable a moving camera for 3D navigation.
- **3D Drawing**: Support 3D shape rendering.
- **Interactive Drawing**: Allow user input for interactive graphics.

### Future Ideas
- **Multithreading**: Enable parallel processing for efficiency.
- **Vulkan Support**: Consider adding Vulkan support for advanced graphics.
- **Multiple Windows**: Allow rendering across multiple windows.
- **Interactive Terminal**: Add a terminal interface for commands and adjustments.

## Implementation Checklist
- [x] **Circle Logic**: Simplified animation with references for circles.
- [x] **Circle API**: Intuitive API for circle creation and manipulation.
- [ ] **Rectangle Refactor**: Improve the rectangle handling process.
- [ ] **Parametric Curves**: Implement parametric curves for smoother shapes.
- [ ] **OpenGL Window Drawing**: Enable OpenGL window rendering.
- [ ] **Pixel Drawing with OpenGL**: Render pixels via OpenGL.
- [ ] **OpenGL Shapes**: Draw points and circles using OpenGL.
- [ ] **Vector Object Drawing**: Enable drawing of vector-based objects.
- [ ] **3D Rendering**: Begin work on 3D implementations.

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
