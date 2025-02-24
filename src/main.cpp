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
	auto& fallingBlock = game.AddObject<Vatnar::SpriteObject>();

	fallingBlock.initFunc = [&](Vatnar::SpriteObject& object) {
		object.texture.create(1, 1);
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(50.f, 50.f);
		object.getPosition() = {100.f, 200.f};

		object.components.physics.emplace(true, sf::Vector2f(0, 0), 3.0f);
		auto circleCollider = std::make_shared<Vatnar::CircleCollider>(&object);
		object.components.collision = circleCollider;
		circleCollider->collision.normal = sf::Vector2f(0.f, 0.f);
		circleCollider->radius = 25.f;

		game.AddColliderSprite(circleCollider);

	};
	fallingBlock.updateFunc = [&](Vatnar::SpriteObject& object, sf::Time dt) {};
	auto& groundBlock = game.AddObject<Vatnar::SpriteObject>();
	groundBlock.initFunc = [&](Vatnar::SpriteObject& object) {
		object.texture.create(1, 1);
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(20.f, 50.f);
		object.getPosition().x = 100;
		object.getPosition().y = 400;


		auto circleCollider = std::make_shared<Vatnar::CircleCollider>(&object);
		object.components.collision = circleCollider;
		circleCollider->collision.normal = sf::Vector2f(0.f, 0.f);
		circleCollider->radius = 25.f;

		game.AddColliderSprite(circleCollider);
	};
	groundBlock.updateFunc = [&](Vatnar::SpriteObject& object, sf::Time dt) {

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
