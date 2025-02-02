#pragma once
#include <SFML/Graphics.hpp>

class Renderer {
public:
    static bool init();
    static bool RenderLoop();
    static sf::RenderWindow window;
};
