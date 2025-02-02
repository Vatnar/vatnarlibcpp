#include <iostream>

#include "Renderer.h"

int main() {
    if (!Renderer::init())
        std::cout << "Renderer::init failed" << std::endl;
    else
        std::cout << "Renderer::init success" << std::endl;

    if (!Renderer::RenderLoop())
        std::cout << "Renderer::RenderLoop failed" << std::endl;
    else
        std::cout << "Renderer::RenderLoop success" << std::endl;

    return 0;
}
