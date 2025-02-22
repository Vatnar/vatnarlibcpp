#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Renderer.h"

#include "game.h"
#include "SpriteObject.h"

int main() {
	sf::RenderWindow window(sf::VideoMode({800, 600}), "game");
	Vatnar::Game game(&window);

	if (!Vatnar::Renderer::WindowInit(*game.window)) {
		std::cout << "Failed to initialize window";
		exit(EXIT_FAILURE);
	}


	sf::Clock deltaClock;
	auto& bouncyball = game.AddObject<Vatnar::SpriteObject>();

	bouncyball.initFunc = [&](Vatnar::SpriteObject& object) {
		object.sprite.setColor(sf::Color::White);
		object.spriteComponents.physics.emplace(sf::Vector2f(3, 3), 3.0f, true);
		object.sprite.setPosition(0, 0);
	};
	bouncyball.updateFunc = [&](Vatnar::SpriteObject& object, sf::Time dt) {
		auto &sprite = object.sprite;
		sprite.setPosition(sprite.getPosition().x,
			sprite.getPosition().y+object.spriteComponents.physics->velocity.y);
	};
	if (!game.Init()) {
		std::cout << "Failed to initialize Vatnar";
		game.window->close();
		ImGui::SFML::Shutdown();
		exit(EXIT_FAILURE);
	}
	Vatnar::Renderer::Update(game, deltaClock);
	ImGui::SFML::Shutdown();
}
