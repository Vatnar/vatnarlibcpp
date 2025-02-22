#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "IGameObject.h"

namespace Vatnar {
	class Game {
	public:
		sf::RenderWindow *window;

		explicit Game(sf::RenderWindow *window);

		bool Init() const;

		void Update(sf::Time dt) const;

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
		template<typename T>
		T &AddObject() {
			static_assert(
				std::is_base_of_v<IGameObject, T>,
				"T must derive from IGameObject");
			objects.push_back(std::make_unique<T>());
			return static_cast<T &>(*objects.back());
		}

	private:
		std::vector<std::unique_ptr<IGameObject> > objects;
	};
}
#endif //GAME_H
