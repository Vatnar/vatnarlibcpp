#include "Renderer.h"

#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#define WINDOW_WIDTH 1920u
#define WINDOW_HEIGHT 1080u
#define WINDOW_SIZE {WINDOW_WIDTH, WINDOW_HEIGHT}

namespace Vatnar {
	sf::RenderWindow Renderer::window;

	template<typename Container>
	void Renderer::DrawContainer(const Container &objects) {
		for (const auto &obj: objects) { window.draw(obj); }
	}

	bool Renderer::init() {
		window.create(sf::VideoMode(WINDOW_SIZE), "EXAMPLE WINDOW");
		window.setFramerateLimit(30);

		return true;
	}



	constexpr void Renderer::tint_color(uint32_t &color) {
		uint8_t a = (color >> 24) & 0xFF;
		uint8_t r = (color >> 16) & 0xFF;
		uint8_t g = (color >> 8) & 0xFF;
		uint8_t b = color & 0xFF;

		r = uint8_t(r * 0.8f);
		g = uint8_t(g * 0.8f);
		b = uint8_t(b * 0.8f);

		color = (a << 24) | (r << 16) | (g << 8) | b;
	}

	constexpr uint32_t Renderer::lerpColor(const uint32_t &a, const
										   uint32_t &b,
										   float t) {
		uint8_t ar = (a >> 16) & 0xFF, ag = (a >> 8) & 0xFF, ab = a & 0xFF;
		uint8_t br = (b >> 16) & 0xFF, bg = (b >> 8) & 0xFF, bb = b & 0xFF;

		uint8_t R = static_cast<uint8_t>(ar + t * (br - ar));
		uint8_t G = static_cast<uint8_t>(ag + t * (bg - ag));
		uint8_t B = static_cast<uint8_t>(ab + t * (bb - ab));

		return (255 << 24) | (R << 16) | (G << 8) | B; // Keep alpha at 255
	}

	bool Renderer::Run() {
		// Initialize array for use with DrawFrameInfo()
		std::array<std::chrono::duration<double, std::milli>, 5> times{};

		sf::Texture texture(WINDOW_SIZE);

		std::vector<uint32_t> pixels(WINDOW_WIDTH * WINDOW_HEIGHT);
		// Nice colours
		// 0xFF8B8BFF Pinkish
		// 0xFF6B6BFF pinkish orange
		// 0xFFFF6B6B purple blue

		constexpr int num_colors = 16;
		constexpr int num_steps = 2 * num_colors;

		uint32_t first_color = 0xFFFF6B6B;
		uint32_t last_color = 0xFFFF6B00;

		std::array<uint32_t, num_steps> colors;

		// Precompute interpolated colors (without tint)
		for (int i = 0; i < num_colors; ++i) {
			float t = i / float(num_colors - 1);
			colors[2 * i] = lerpColor(first_color, last_color, t); // Normal color
			colors[2 * i + 1] = colors[2 * i]; // Copy for tinting
		}

		// Apply tint to every second color
		for (int i = 1; i < num_steps; i += 2) {
			tint_color(colors[i]);
		}

		auto start = std::chrono::high_resolution_clock::now();

		for (size_t i = 0; i < pixels.size(); ++i) {
			int index = (i * num_steps) / pixels.size(); // Map `i` to color index
			pixels[i] = colors[index];
		}


		const auto end = std::chrono::high_resolution_clock::now();

		texture.update(reinterpret_cast<uint8_t*>(pixels.data()));


		std::cout << "Time: "
				<< std::chrono::duration_cast<std::chrono::milliseconds>(
					end - start).count()
				<< " ms\n" << std::endl;
		sf::Sprite sprite(texture);

		while (window.isOpen()) {
			while (const std::optional event = window.pollEvent()) {
				if (event->is<sf::Event::Closed>()) {
					window.close();
					return true;
				}
			}


			window.clear();
			window.draw(sprite);
			DrawFrameInfo(times);
			window.display();
		}

		return false;
	}

	void Renderer::DrawFrameInfo(
		std::array<std::chrono::duration<double, std::milli>, 5> &times) {
		auto now = std::chrono::duration<double, std::milli>(
			std::chrono::high_resolution_clock::now().time_since_epoch());

		double duration_ms = 0.0;
		for (size_t i = 1; i < times.size(); i++) {
			duration_ms += (times[i - 1] - times[i]).count();
		}
		duration_ms /= (times.size() - 1);

		std::rotate(times.rbegin(), times.rbegin() + 1, times.rend());
		times[0] = now;


		std::string duration  = std::format("{:.2f}", duration_ms);
		std::string framerate = std::format(
			"{:.2f}", (duration_ms > 0 ? 1000.0 / duration_ms : 0));

		sf::RectangleShape box({200, 100});
		box.setPosition({0, 0});
		box.setFillColor(sf::Color(0, 0, 0, 200));


		sf::Font font("Arial.ttf");

		sf::Text frametime(font, "Frame: " + duration + "ms", 30);
		frametime.setFillColor(sf::Color::White);
		frametime.setPosition({0, 0});

		sf::Text fps(font, "FPS: " + framerate, 30);
		fps.setFillColor(sf::Color::White);
		fps.setPosition({0, 50});


		window.draw(box);
		window.draw(frametime);
		window.draw(fps);
	}

	void Renderer::initCircles(std::vector<sf::CircleShape> &circles) {
#define RADIUS 5.0f
		sf::Vector2f center = {RADIUS, RADIUS};
		int          rows   = 100, cols = 100; // Define grid dimensions
		// Max diagonal distance in the grid
		float maxDistance = std::sqrt(
			(rows - 1) * (rows - 1) + (cols - 1) * (cols - 1));

		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				sf::CircleShape circle(RADIUS);
				circle.setOrigin({circle.getRadius(), circle.getRadius()});
				circle.setPosition(center);

				float distance = std::sqrt(row * row + col * col);
				float factor = distance / maxDistance; // Scale from 0.0 to 1.0
				// sf::Color blended = static_cast<sf::Color>(lerpColor2(
					// 0xFF0000FF, 0x0000FFFF,
					// factor));

				// circle.setFillColor(blended);
				circles.emplace_back(circle);

				center.x += RADIUS * 2;
			}
			center.y += 2 * RADIUS;
			center.x = RADIUS;
		}
	}
}
