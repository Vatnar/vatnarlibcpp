#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include "Components2D.h"
#include "IGameObject.h"
#include "SpriteObject.h"

namespace Vatnar {
	class SpriteObject;

	class Game {
	public:
		sf::RenderWindow *window;

		explicit Game(sf::RenderWindow *window);

		bool Init();

		void Update(sf::Time dt);

		void CheckCollisions2D(sf::Time dt);

		// Delete copy constructor and copy assignment
		Game(const Game &) = delete;

		Game &operator=(const Game &) = delete;

		// Allow move semantics
		Game(Game &&) = default;

		Game &operator=(Game &&) = default;


		// Function for initalizating or common logic for game object.
		// Game objects should have seperate functiosn but i dont want to manually
		// Change the game.Update() loop each time.
		// Perhaps store objects in a container and call .Update() for each,
		// and .init for each.

		// Call for each added object to add them to the game loop.
	private:
		std::vector<std::unique_ptr<IGameObject> > objects;
		std::vector<std::shared_ptr<Collider2D> >  colliders;
	public:
		template<typename T>
		T &AddObject() {

			static_assert(
				std::is_base_of_v<IGameObject, T>,
				"T must derive from IGameObject");

			auto obj = std::make_unique<T>();
			T &  ref = *obj;

			objects.push_back(std::move(obj));

			return ref;
		}
		void AddColliderSprite(std::shared_ptr<Collider2D> collider) {

				colliders.push_back(collider);
		}


	};
}
#endif //GAME_H
