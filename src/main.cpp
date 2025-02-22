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
		if (!object.texture.create(1, 1)) {
			std::cerr << "Failed to create texture!" << std::endl;
			return;
		}
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(50.f, 50.f);
		object.sprite.setPosition(200, 200);
		// initial velocity apear not working
		object.spriteComponents.physics.emplace(sf::Vector2f(300, 300), 3.0f, true);
		object.spriteComponents.collision = std::make_unique<Vatnar::CircleCollider>();



	};

	bouncyball.updateFunc = [&](Vatnar::SpriteObject& object, sf::Time dt) {



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
