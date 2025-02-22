#include "Game.h"
#include <memory>
#include <vector>
Vatnar::Game::Game(sf::RenderWindow *window) {
	this->window = window;
}

bool Vatnar::Game::Init() const {
	for (const auto &obj : this->objects) {
		obj->Init();
	}
	return true;
}

void Vatnar::Game::Update(sf::Time dt) const { // called once per frame
	for (const auto &obj : this->objects) {
		obj->Update(dt);
	}
}

void Vatnar::Game::CheckCollisions2D(sf::Time dt) const {
	for (const auto &collider : colliders) {
		// Create a new vector excluding the current collider
		std::vector<std::unique_ptr<Collider2D>> otherColliders;
		std::ranges::copy_if(
			colliders
			, std::back_inserter(otherColliders),
			  [&](const std::unique_ptr<Collider2D> &c) { return c.get() != collider.get(); });

		// Update collider with the filtered list
		collider->Update(otherColliders, dt);
	}

}
