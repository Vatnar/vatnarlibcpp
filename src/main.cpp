#include <iostream>

#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Renderer.h"

#include "game.h"
#include "SpriteObject.h"

using namespace Vatnar;
int main() {
	sf::RenderWindow window(sf::VideoMode({800, 600}), "game");
	Game game(&window);

	if (!Renderer::WindowInit(*game.window)) {
		std::cout << "Failed to initialize window";
		exit(EXIT_FAILURE);
	}


	sf::Clock deltaClock;
	auto fallingBlock = game.AddObject<SpriteObject>();
	assert(fallingBlock && "fallingBlock is nullptr!");

	fallingBlock->initFunc = [&](SpriteObject& object) {
		object.texture.create(1, 1);
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(50.f, 50.f);
		object.getPosition() = {100.f, 200.f};

		object.components.physics.emplace(true, sf::Vector2f(0, 0), 3.0f);

		auto &collider = object.components.collision;
		collider = game.AddCollider<CircleCollider>(*fallingBlock);
		collider->collision.normal = sf::Vector2f(0.f, 0.f);

		CircleCollider::SetRadius(collider, 25.0f);

	};
	fallingBlock->updateFunc = [&](SpriteObject& object, sf::Time dt) {};


	auto groundBlock = game.AddObject<SpriteObject>();

	groundBlock->initFunc = [&](SpriteObject& object) {
		object.texture.create(1, 1);
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(20.f, 50.f);
		object.getPosition().x = 100;
		object.getPosition().y = 400;

		auto &collision = object.components.collision;
		collision = game.AddCollider<CircleCollider>(*groundBlock);
		collision->collision.normal = sf::Vector2f(0.f, 0.f);
		CircleCollider::SetRadius(collision, 25.f);
	};
	auto groundBlock2 = game.AddObject<SpriteObject>();
	groundBlock2->initFunc = [&](SpriteObject& object) {
		object.texture.create(1, 1);
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(20.f, 50.f);
		auto &position = object.getPosition();
		position.x = 150;
		position.y = 400;

		auto &collision = object.components.collision;
		collision = game.AddCollider<CircleCollider>(*groundBlock2);
		collision->collision.normal = sf::Vector2f(0.f, 0.f);
		CircleCollider::SetRadius(collision, 25.f);
	};
	if (!game.Init()) {
		std::cout << "Failed to initialize Vatnar";
		game.window->close();
		ImGui::SFML::Shutdown();
		exit(EXIT_FAILURE);
	}
	Renderer::Update(game, deltaClock);
	ImGui::SFML::Shutdown();
}
