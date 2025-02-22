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
	window->clear();
	for (const auto &obj : this->objects) {
		obj->Update(dt);
	}
	window->display();
}
