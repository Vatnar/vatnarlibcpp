//
// Created by peter on 22/02/2025.
//

#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

namespace Vatnar {
	struct Collision2D {
		// From origin to contact point
		sf::Vector2f normal = {0,0}; // normal being 0, 0 means no collisions
	};
	struct Collider2D {
		Collision2D collision;
		virtual ~Collider2D() = default;

		virtual void Update(
			std::vector<std::unique_ptr<Collider2D> >
			colliders, sf::Time dt) = 0;

		virtual void Init() = 0;
	};

	struct BoxCollider final : Collider2D {
		// Points are relative to origin
		sf::Vector2f point1 = {100, 100};
		sf::Vector2f point2 = {100, -100};
		sf::Vector2f point3 = {-100, -100};
		sf::Vector2f point4 = {-100, 100};

		void Update(
			std::vector<std::unique_ptr<Collider2D> >
			colliders, sf::Time dt) override {
			// Check if any collisions happen.
			// set velocity to account for collision

			// If collides
			//collision.Normal =
			// else
			collision.normal = {0, 0};
		}

		void Init() override {
			// Add to callable list.
		}
	};


	struct Physics2D {
		sf::Vector2f                velocity;
		float                       mass              = 1.0f;
		bool                        affectedByGravity = true;
		std::unique_ptr<Collider2D> collider;

		// Does not apply dt
		void Update() {
			if (affectedByGravity) {
				velocity.y += 15 * 9.81f; // Gravity simulation
			}
			if (collider) {
				auto &normal = collider->collision.normal;
				if (normal != sf::Vector2f(0,0)) {
					// Collision happened
					velocity.x -= mass*mass*normal.x;
					velocity.y -= mass*mass*normal.y;
					normal = sf::Vector2f(0,0); // Reset collision
				}
			}
			if (collider && (collider->collision.normal != sf::Vector2f(0, 0))){
			}
		}
	};
}
#endif //PHYSICSCOMPONENT_H
