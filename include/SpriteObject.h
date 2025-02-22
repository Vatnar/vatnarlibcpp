#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include "IGameObject.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <optional>

#include "PhysicsComponent.h"

namespace Vatnar {
	class SpriteObject final : public IGameObject {
		// Final for now
	public:
		sf::Sprite                                    sprite;
		sf::Texture                                   texture;
		std::function<void(SpriteObject &, sf::Time)> updateFunc;
		std::function<void(SpriteObject &)>           initFunc;
		struct SpriteComponents {
			std::optional<PhysicsComponent> physics;
		} spriteComponents;
		void Update(sf::Time dt) override;
		bool Init() override;
	private:

	};
}


#endif //SPRITEOBJECT_H
