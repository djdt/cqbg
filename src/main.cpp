#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include "ArgsParseParser.hpp"

#include "RGBMatchColors.hpp"
#include "RGBQuantize/Octree.hpp"

#include "Base16Colors.hpp"
#include "ColorWindow.hpp"
#include "Parsei3status.hpp"
#include "XCBRootImage.hpp"

std::vector<RGBPixel> extractColors(uint32_t num_colors)
{
	auto img_data = XCBGetRootImage();
	auto colors = rgb::quantizeOctree(img_data, num_colors, 4);
	colors = rgb::matchColors(colors, base_16_eighties);
	return colors;
}

std::vector<std::string> getColorHexes(
		const std::vector<RGBPixel>& colors)
{
	std::vector<std::string> hexes;
	for (auto color : colors) {
		std::stringstream hex;
		hex << "#";
		for (auto v : color) {
			hex << std::setfill('0') << std::setw(2) << std::hex;
			hex << static_cast<int>(v);

		}
		hexes.push_back(hex.str());
	}
	return hexes;
}

int32_t main(int32_t argc, const char* argv[])
{
	argsparse::Parser parser("cqBG");
	parser.addOption("help", 'h', "print help message and exit");
	parser.addOption("output", 'o', "output colors to xresources file", std::string("/home/tom/.Xresources"), 0);
	parser.addOption("compare", 'c', "print/display compare colors");
	parser.addOption("number", 'n', "number of extracted colors", 64);

	if (!parser.parse(argc, argv) || parser["help"].count) {
		std::cout << parser << std::endl;
		return 0;
	}

	auto colors = extractColors(parser["number"].as<int32_t>());
	if (parser["compare"].count) {
		colors.insert(colors.end(), base_16_eighties.begin(), base_16_eighties.end());
	}

	if (parser["output"].count) {
		std::ofstream ofs(parser["output"].as<std::string>(), std::ios::out);

		auto hexes = getColorHexes(colors);
		for (size_t i = 0; i < hexes.size(); ++i) {
			ofs << "*"  << base_16_eighties_names[i];
			ofs << ": " << hexes[i];
			ofs << "\n";
		}

		ofs.close();

		parsei3StatusConfig("/home/tom/.i3/i3status.conf.template",
				"/home/tom/.i3/i3status.conf", hexes);

		std::system("xrdb ~/.Xresources");
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
									base_16_eighties.begin(), base_16_eighties.end());
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
