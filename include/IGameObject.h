#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
namespace Vatnar {
	class IGameObject {
	protected:
		sf::Vector2f position; // Store object's position

	public:
		virtual ~IGameObject() = default;

		virtual sf::Vector2f &getPosition() {
			return position;
		}


		virtual bool Init() = 0;

		virtual void Update(sf::Time dt) {}
	};
}
#endif //GAMEOBJECT_H
