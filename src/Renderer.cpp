#include "Renderer.h"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::RenderWindow Renderer::window;

bool Renderer::init() {
    window.create(sf::VideoMode({800u, 600u}), "EXAMPLE WINDOW");
    window.setFramerateLimit(144);
    return true;
}

bool Renderer::RenderLoop() {
    sf::Texture texture;
    if (!texture.loadFromFile("img/test.jpg")) {
        std::cout << "Error loading texture!" << std::endl;
        return false;
    }

    sf::Sprite sprite(texture);

    sf::Vector2u textureSize = texture.getSize();
    std::cout << "Texture Size: " << textureSize.x << "x" << textureSize.y << std::endl;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return true;
            }
        }

        sf::Vector2u windowSize = window.getSize();

        float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
        float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

        float scale = std::min(scaleX, scaleY);

        sprite.setScale({scale, scale});

        sf::FloatRect spriteBounds = sprite.getGlobalBounds();
        sprite.setOrigin({spriteBounds.size.x / 2.0f, spriteBounds.size.y / 2.0f})
        ; // Set origin to center
        sprite.setPosition({windowSize.x / 2.0f, windowSize.y / 2.0f
    }); // Set position to center of window


        window.clear();
        window.draw(sprite);
        window.display();
    }

    return false;
}
