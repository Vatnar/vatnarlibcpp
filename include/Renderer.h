#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"

namespace Vatnar::Renderer {
	/**
	 * @brief Initializes window, framerate
	 * @param window reference to RenderWindow
	 * @return false if fails, else true
	 */
	bool WindowInit(sf::RenderWindow &window);

	/**
	 * Handles all upcoming events including input
	 * @param window reference to renderWindow
	 * @return false if fails, else true
	 */
	bool EventLoop(sf::RenderWindow &window);

	/**
	 * Updates state of game
	 * @param game reference to game instance
	 * @param deltaClock reference to deltaClock
	 */
	void Update(Game &game, sf::Clock &deltaClock);

	/**
	 * Adds a object to a draw loop
	 * @param drawable a drawable object, like sprite and so on
	 */
	void AddDrawable(std::unique_ptr<sf::Drawable> drawable);
}

#endif // RENDERER_H
