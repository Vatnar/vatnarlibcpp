#include "Renderer.h"

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
			ImGui::SFML::Render(*game.window);

			perFrameObjects.clear();
			game.Update(dt);
			for (auto &obj : perFrameObjects) {
				game.window->draw(*obj);
			}
			perFrameObjects.clear();
		}
	}
}
