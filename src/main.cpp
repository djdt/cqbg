#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include "ArgsParseParser.hpp"

#include "RGBMatchColors.hpp"
#include "RGBQuantize/Octree.hpp"

#include "AnsiColors.hpp"
#include "Base16Colors.hpp"
#include "ColorWindow.hpp"
#include "XCBRootImage.hpp"

#define COMPARE_COLORS ansi_colors_22

std::vector<RGBPixel> extractColors(uint32_t num_colors)
{
	auto img_data = XCBGetRootImage();
	auto colors = rgb::quantizeOctree(img_data, num_colors, 4);
	colors = rgb::matchColors(colors, COMPARE_COLORS);
	return colors;
}

std::string colorHex(const RGBPixel& color)
{
	std::stringstream hex("");
	hex << "#";
	for (auto v : color) {
		hex << std::setfill('0') << std::setw(2) << std::hex;
		hex << static_cast<int>(v);
	}
	return hex.str();
}

int32_t main(int32_t argc, const char* argv[])
{
	argsparse::Parser parser("cqBG");
	parser.addText("Window Keys:\n\t(r) : reload the colors.");
	parser.addOption("help", 'h', "print help message and exit");
	parser.addOption("compare", 'c', "print/display compare colors");
	parser.addOption("default", 'd', "use default colors");
	/* parser.addOption("number", 'n', "number of extracted colors", 96); */
	parser.addOption("output", 'o', "output colors to cout");

	if (!parser.parse(argc, argv) || parser["help"].count) {
		std::cout << parser << std::endl;
		return 0;
	}

	std::vector<RGBPixel> colors;
	if (parser["default"]) {
		colors = base_16_eighties;
	} else {
		/* colors = extractColors(parser["number"].as<int32_t>()); */
		colors = extractColors(96);
	}
	if (parser["compare"].count) {
		colors.insert(colors.end(), COMPARE_COLORS.begin(), COMPARE_COLORS.end());
	}

	if (parser["output"].count) {
		for (const auto& color : colors) {
			std::cout << colorHex(color) << std::endl;
		}
		return 0;
	}

	ColorWindow window(colors, parser["compare"].count ? 2 : 1);
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
			else if (e.type == sf::Event::KeyPressed) {
				switch (e.key.code) {
					case sf::Keyboard::Q:
						window.close();
						break;
					case sf::Keyboard::R:
						colors = extractColors(64);
						if (parser["compare"].count)
							colors.insert(colors.end(),
									COMPARE_COLORS.begin(), COMPARE_COLORS.end());
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

return 0;
}
