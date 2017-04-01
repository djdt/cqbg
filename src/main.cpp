#include <iostream>
#include <limits>
#include <string>

#include "AnsiColors.hpp"
#include "ColorWindow.hpp"
#include "RGBQuantize.hpp"
#include "XCBRootImage.hpp"

std::vector<RGBPixel> ExtractColors(uint32_t num_colors)
{
	auto img_data = XCBGetRootImage();
	auto colors = rgbq::ExtractColors_Octree(img_data, num_colors, 4);
	colors = rgbq::MatchColors(colors, ansi_colors_16);
	colors.insert(colors.end(), ansi_colors_16.begin(), ansi_colors_16.end());
	return colors;
}

int32_t main(int32_t argc, const char* argv[])
{
	bool colors_output = false;
	bool colors_window = true;

	for (int32_t i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		if (arg == "-h" || arg == "--help") {

			return 0;
		} else if (arg == "-o" || arg == "--output") {
			colors_output = true;
			colors_window = false;
		}
	}

	auto colors = ExtractColors(64);

	if (colors_window) {
		ColorWindow window(colors, 2);
		while(window.isOpen())
		{
			sf::Event e;
			while(window.pollEvent(e))
			{
				if(e.type == sf::Event::Closed)
					window.close();
				else if (e.type == sf::Event::KeyPressed) {
					switch (e.key.code) {
						case sf::Keyboard::Q:
							window.close();
							break;
						case sf::Keyboard::R:
							colors = ExtractColors(64);
							window.UpdateColors(colors);
							break;
						default:
							break;
					}
				} else if (e.type == sf::Event::MouseMoved) {
					/* window.HandleMouse(e); */
				}
			}
			window.Draw();
		}
	}

	return 0;
}
