#include "Renderer.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

namespace Vatnar::Renderer {
	std::vector<std::unique_ptr<sf::Drawable>> perFrameObjects;

	bool WindowInit(sf::RenderWindow &window) {
		window.setFramerateLimit(60);
		ImGui::SFML::Init(window);
		return true;
	}

	void AddDrawable(std::unique_ptr<sf::Drawable> drawable) {
		perFrameObjects.emplace_back(std::move(drawable));
	}

	bool EventLoop(sf::RenderWindow &window) {
		sf::Event event{};
		bool eventHappened = false;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(window, event);
			if (!eventHappened)
				eventHappened = true;
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		return eventHappened;
	}

	void Update(const Game &game, sf::Clock &deltaClock) {
		while (game.window->isOpen()) {
			EventLoop(*game.window);
			sf::Time dt = deltaClock.restart();
			ImGui::SFML::Update(*game.window, dt);

			ImGui::ShowDemoWindow();
			ImGui::SFML::Render(*game.window); // Render ImGui first

			game.Update(dt); // Update game objects (calls AddDrawable)
			game.CheckCollisions2D(dt);

			// Draw SFML objects
			game.window->clear();
			for (auto &obj : perFrameObjects) {
				game.window->draw(*obj);
			}
			game.window->display();
			perFrameObjects.clear(); // Only clear after drawing
		}
	}

}
