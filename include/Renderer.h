#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"

namespace Vatnar::Renderer {
	bool WindowInit(sf::RenderWindow &window);
	bool EventLoop(sf::RenderWindow &window);
	void Update(const Game &game, sf::Clock &deltaClock);

	void AddDrawable(std::unique_ptr<sf::Drawable> drawable);
}

#endif // RENDERER_H
