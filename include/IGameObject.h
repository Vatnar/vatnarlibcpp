#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>

namespace Vatnar {
	class IGameObject {
	public:
		virtual bool Init() = 0;
		virtual void Update(sf::Time dt) = 0;
		virtual ~IGameObject() = default;

	};
}
#endif //GAMEOBJECT_H
