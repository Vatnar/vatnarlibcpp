#include "Game.h"
#include <memory>
#include <vector>
namespace Vatnar {
	Game::Game(sf::RenderWindow *window) { this->window = window; }

	bool Game::Init() {
		for (const auto &obj: this->objects) {
			obj->Init();
			// Add colliders to list
			if (const auto obj2 = dynamic_cast<SpriteObject*>(obj.get())) {
				if (obj2->components.collision) {
					colliders.push_back(obj2->components.collision);
				}
			}
		}
		return true;
	}

	void Game::Update(const sf::Time dt) const {
		// called once per frame
		for (const auto &obj: this->objects) { obj->Update(dt); }
	}

	void Game::CheckCollisions2D(const sf::Time dt){

		for (const auto &collider: colliders) {
			// Create a new vector excluding the current collider

			std::vector<std::shared_ptr<Collider2D> > otherColliders;
			std::copy_if(
				colliders.begin(), colliders.end(),
				std::back_inserter(otherColliders),
				[&](const std::shared_ptr<Collider2D> &c) {
					return c.get() != collider.get();
				}
			);
			// Update collider with the filtered list
			collider->Update(otherColliders, dt);
		}
	}
}
