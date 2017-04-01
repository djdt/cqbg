#ifndef _COLOR_WINDOW_H_
#define _COLOR_WINDOW_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "AnsiColors.hpp"
#include "Base16Colors.hpp"

#define MATCH_COLORS ansi_colors_16

typedef std::array<uint8_t, 3> RGBPixel;

class ColorWindow : public sf::RenderWindow
{
	private:
		bool _show_match_colors;
		uint32_t _num_rows;
		std::vector<sf::RectangleShape> _colors;

		void onResize();

	public:
		ColorWindow(const std::vector<RGBPixel>& colors, uint32_t num_rows = 2);

		void UpdateColors(const std::vector<RGBPixel>& colors);
		void Draw();
};
#endif /* ifndef _COLOR_WINDOW_H_ */
