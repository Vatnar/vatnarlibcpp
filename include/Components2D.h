//
// Created by peter on 22/02/2025.
//

#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include "IGameObject.h"

namespace Vatnar {
	struct Collision2D {
		// From origin to contact point
		sf::Vector2f normal = {0, 0}; // normal being 0, 0 means no collisions
	};

	struct Collider2D {
		IGameObject *parent = nullptr;
		Collision2D  collision;

		virtual ~Collider2D() = default;

		virtual void Update(
			std::vector<std::shared_ptr<Collider2D> >
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
			std::vector<std::shared_ptr<Collider2D> >
			otherColliders, sf::Time dt) override {
			// Check if any collisions happen.
			for (auto otherCollider: otherColliders) {
				//Get closest distance to otherCollider
			}
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

	struct CircleCollider final : Collider2D {
		float radius = 100;
		CircleCollider() = default;
		explicit CircleCollider(IGameObject* parentObject) {
			parent = parentObject;
		}
		void Update(std::vector<std::shared_ptr<Collider2D> >
			otherColliders, sf::Time dt) override {
			// Current implementation returns on first collision, so one collision per fram
			for (auto otherCollider: otherColliders) {
				if (auto other = dynamic_cast<CircleCollider *>(otherCollider.get())) {
					// otherCollider is a CircleCollider
					auto pos = parent->getPosition();
					auto otherPos = other->parent->getPosition();
					sf::Vector2f diff = otherPos - pos;
					if (std::hypot(diff.x, diff.y) <= radius +other->radius) {
						collision.normal = diff;
						std::cout << "Distanec" <<std::hypot(diff.x, diff.y)<< std::endl;
						return;
					}
				}
			}
			collision.normal = {0, 0};
		}

		void Init() override {
			// Add to callable list.
		}
	};


	struct Physics2D {
		bool                        affectedByGravity = true;
		sf::Vector2f                velocity;
		float                       mass              = 1.0f;
		std::shared_ptr<Collider2D> collider;

		// Does not apply dt
		void Update() {
			if (affectedByGravity) {
				velocity.y += 9.81f; // Gravity simulation
			}
			if (collider && collider->collision.normal != sf::Vector2f(0.f, 0.f)) {
				auto &normal = collider->collision.normal;
					// Collision happened
					velocity.x -= mass * mass * normal.x;
					velocity.y -= mass * mass * normal.y;
					normal = sf::Vector2f(0, 0); // Reset collision
				}
		}
	};
}
#endif //PHYSICSCOMPONENT_H
