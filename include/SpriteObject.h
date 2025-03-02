#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include "IGameObject.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <optional>

#include "Components2D.h"


namespace Vatnar {

	class SpriteObject final : public IGameObject {
	public:
		sf::Sprite                                    sprite;		///< Sprite instance of object
		sf::Texture                                   texture;		///< Texture instance of object
		std::function<void(SpriteObject &, sf::Time)> updateFunc;	///< std::function to call on each frame

		std::function<void(SpriteObject &)>           initFunc;		///< std::function to call on initialization

		struct Components {
			std::optional<Physics2D> physics;						///< optional physics component
			std::shared_ptr<Collider2D> collision;					///< optional collision
		};
		Components components; ///< struct containing all mandatory and optional components of class instance

		/**
		 * @brief Runs every frame for every object
		 * @details in reality dt is the avarage time of the couple last frames
		 * @param dt deltaTime, time since last frame
		 */
		void Update(const sf::Time &dt) override;

		/**
		 * @brief Runs once for initialization for every object
		 * @return false if initialization fails, else true
		 */
		bool Init() override;

	};
}


#endif //SPRITEOBJECT_H
