#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include "IGameObject.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <optional>

#include "Components2D.h"

namespace Vatnar {

	class SpriteObject final : public IGameObject {
		// Final for now
	public:
		sf::Sprite                                    sprite;
		sf::Texture                                   texture;
		std::function<void(SpriteObject &, sf::Time)> updateFunc;
		std::function<void(SpriteObject &)>           initFunc;
		struct Components {
			std::optional<Physics2D> physics;
			std::shared_ptr<Collider2D> collision;
		};
		Components components;
		void Update(sf::Time dt) override;
		bool Init() override;

	};
}


#endif //SPRITEOBJECT_H
