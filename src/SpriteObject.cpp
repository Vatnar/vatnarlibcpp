//
// Created by peter on 22/02/2025.
//

#include "SpriteObject.h"

#include <iostream>

#include "Renderer.h"

// applies dt
void Vatnar::SpriteObject::Update(sf::Time dt) {
	if (components.physics.has_value()) {
		components.physics->Update();
		position += components.physics->velocity*dt.asSeconds();
	}
	if (updateFunc) updateFunc(*this, dt);
	sprite.setPosition(position);

	Renderer::AddDrawable(std::make_unique<sf::Sprite>(sprite));
}

bool Vatnar::SpriteObject::Init() {
	sprite.setOrigin(sprite.getScale().x/2, sprite.getScale().y/2);
	if (initFunc) initFunc(*this);
	if (components.collision && components.physics.has_value()) {
		components.physics->collider = components.collision;
	}
	return true;
}
