//
// Created by peter on 22/02/2025.
//

#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include <SFML/System/Vector2.hpp>

namespace Vatnar{
	struct PhysicsComponent {
		sf::Vector2f velocity;
		float mass = 1.0f;
		bool affectedByGravity = true;

		void Update(sf::Time dt) {
			if (affectedByGravity) {
				velocity.y += 9.8f * dt.asSeconds(); // Gravity simulation
			}
		}
	};


}
#endif //PHYSICSCOMPONENT_H
