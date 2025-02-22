//
// Created by peter on 22/02/2025.
//

#include "SpriteObject.h"

#include "Renderer.h"

void Vatnar::SpriteObject::Update(sf::Time dt) {
	if (spriteComponents.physics) spriteComponents.physics->Update(dt);

	if (updateFunc) updateFunc(*this, dt);
	Renderer::AddDrawable(std::make_unique<sf::Sprite>(sprite));
}

bool Vatnar::SpriteObject::Init() {
	if (initFunc) initFunc(*this);
	return true;
}
