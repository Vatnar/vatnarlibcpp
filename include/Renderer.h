#ifndef VATNAR_H
#define VATNAR_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include "Game.h"

namespace Vatnar::Renderer {
	bool WindowInit(sf::RenderWindow &window);
	bool EventLoop(sf::RenderWindow &window);
	void Update(const Game &game, sf::Clock &deltaClock);

	void AddDrawable(std::unique_ptr<sf::Drawable> drawable);
}

#endif // VATNAR_H
