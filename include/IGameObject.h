#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>

namespace sf { class Time; }

namespace Vatnar {
	class IGameObject {
	protected:
		sf::Vector2f position;

	public:
		virtual ~IGameObject() = default;

		/**
		 *
		 * @return reference to sf::Vector2f position
		 */
		sf::Vector2f &getPosition();

		virtual bool Init() = 0;

		virtual void Update(const sf::Time &dt) {}
	};


}
#endif //GAMEOBJECT_H
