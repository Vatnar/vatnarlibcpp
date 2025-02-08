#pragma once
#include <SFML/Graphics.hpp>

namespace Vatnar {
	/**
	 * @brief Static class Renderer with functions regarding drawing and
	 rendering to window.
	 *
	 */
	class Renderer {
	public:
		Renderer() = delete; // Purely static class
		static bool init();
		static constexpr uint32_t lerpColor(const uint32_t &a, const uint32_t
				&b, float t);
		constexpr static void tint_color(uint32_t &color);

		static bool Run();
	private:
		/**
		 * @brief Draw() is called every frame, things that are to be drawn
		 * on per-frame basis should be called or placed in draw
		 * @returns void
		 */
		static void DrawFrameInfo(std::array<std::chrono::duration<double, std::milli>, 5> &times);

		static void initCircles
		(std::vector<sf::CircleShape> &circles);





		/**
		* @brief Draws all objects in a container.
		* @tparam Container A standard container type (e.g., std::vector, std::list).
		* @param objects The container holding drawable objects.
		*/
		template<class Container>
		static void DrawContainer(const Container& objects);

		static sf::RenderWindow window;
	};
}
