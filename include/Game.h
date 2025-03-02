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
		/**
		 * @brief Adds game object to Update loop
		 * @tparam ObjectType Derived class of IGameObject
		 * @return shared_ptr stored in a vector in game instance
		 */
		template<typename ObjectType>
		std::shared_ptr<ObjectType> AddObject() {
			static_assert(std::is_base_of_v<IGameObject, ObjectType>, "ObjectType must derive from IGameObject");

			auto obj = std::make_shared<ObjectType>();
			objects.push_back(obj);
			return obj;
		}

		/**
		 * @brief Adds collider to Update loop
		 * @tparam ColliderType Derived class of Collider2D
		 * @param parent Reference to the parent of the collider
		 * @return shared_ptr to collider
		 */
		template<typename ColliderType>
		std::shared_ptr<ColliderType> AddCollider(IGameObject &parent) {
			static_assert(std::is_base_of_v<Collider2D, ColliderType>, "ColliderType must derive from Collider2D");

			auto coll = std::make_shared<ColliderType>(&parent);
			colliders.push_back(coll);
			return coll;
		}

		/**
		 * @brief Game constructor from window
		 * @param window address of window
		 */
		explicit Game(sf::RenderWindow *window);

		bool Init();

		/**
		 * @brief Calls update for each game object
		 * @param dt time since last frame
		 */
		void Update(sf::Time dt) const;

		/**
		 * @brief Checks collisions for each collider in the game
		 * @param dt time since last frame
		 */
		void CheckCollisions2D(sf::Time dt);

		// Delete copy constructor and copy assignment
		Game(const Game &) = delete;
		Game &operator=(const Game &) = delete;

		// Allow move semantics
		Game(Game &&) = default;
		Game &operator=(Game &&) = default;

	public:
		sf::RenderWindow *window;

	private:
		// objects "belong" to the game, but init and update functions can be changed in main
		std::vector<std::shared_ptr<IGameObject> > objects;
		// colliders "belong" to the objects
		std::vector<std::shared_ptr<Collider2D> >  colliders;
	};
	///< Class for managing game data and function.
}
#endif //GAME_H
