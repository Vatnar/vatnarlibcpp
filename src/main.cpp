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
		object.sprite.setPosition(200, 200);

		object.spriteComponents.physics.emplace(true, sf::Vector2f(300, -400), 3.0f);

		std::unique_ptr<Vatnar::CircleCollider> circleCollider = std::make_unique<Vatnar::CircleCollider>(&object);
		object.spriteComponents.collision = std::move(circleCollider);

		// Access and modify the collider safely
		if (auto *circleColliderPtr = dynamic_cast<Vatnar::CircleCollider*>(object.spriteComponents.collision.get())) {
			circleColliderPtr->collision.normal = sf::Vector2f(0.f, 0.f);
			circleColliderPtr->radius = 50.f;
		}

		// Assign collider to physics component
		object.spriteComponents.physics->collider = std::move(object.spriteComponents.collision);

		// Add to the game
		game.AddColliderSprite(object, std::move(object.spriteComponents.physics->collider));


	};
	fallingBlock.updateFunc = [&](Vatnar::SpriteObject& object, sf::Time dt) {
	};
	auto& groundBlock = game.AddObject<Vatnar::SpriteObject>();
	groundBlock.initFunc = [&](Vatnar::SpriteObject& object) {
		object.texture.create(1, 1);
		sf::Uint8 whitePixel[] = {255, 255, 255, 255};
		object.texture.update(whitePixel);
		object.sprite.setTexture(object.texture);
		object.sprite.setScale(50.f, 50.f);
		object.sprite.setPosition(100, 200);
		object.getPosition().x = 100;
		object.getPosition().y = 200;


		std::unique_ptr<Vatnar::CircleCollider> circleCollider = std::make_unique<Vatnar::CircleCollider>(&object);
		object.spriteComponents.collision = std::move(circleCollider);

		auto &collider = object.spriteComponents.collision;
		collider->collision.normal = sf::Vector2f(0.f, 0.f);

		// Cast to access `radius`
		if (auto *circleColliderPtr = dynamic_cast<Vatnar::CircleCollider*>(collider.get())) {
			circleColliderPtr->radius = 50.f;
		}

		game.AddColliderSprite(object, std::move(collider));
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
