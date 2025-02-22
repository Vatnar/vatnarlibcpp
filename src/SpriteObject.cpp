//
// Created by peter on 22/02/2025.
//

#include "SpriteObject.h"

#include <iostream>

#include "Renderer.h"

// applies dt
void Vatnar::SpriteObject::Update(sf::Time dt) {
	if (spriteComponents.physics) {
		spriteComponents.physics->Update();
		sprite.move(spriteComponents.physics->velocity.x*dt.asSeconds(), spriteComponents.physics->velocity.y*dt.asSeconds());
	}
	if (updateFunc) updateFunc(*this, dt);

	Renderer::AddDrawable(std::make_unique<sf::Sprite>(sprite));
}

bool Vatnar::SpriteObject::Init() {
	if (spriteComponents.collision) {
		spriteComponents.physics->collider = std::move(
			spriteComponents.collision);
		// Transfer ownership
	}
	if (initFunc) initFunc(*this);
	return true;
}
