#include "ColorWindow.hpp"

#define BLOCK_X 30.f
#define BLOCK_Y 40.f
#define GAP_X 10.f

#include <cmath>

void ColorWindow::onResize()
{
	sf::View view(sf::FloatRect(0.f, 0.f,
				this->sf::Window::getSize().x, this->getSize().y));
	this->setView(view);
}

ColorWindow::ColorWindow(const std::vector<RGBPixel>& colors, uint32_t num_rows)
	:sf::RenderWindow(sf::VideoMode(1, 1), "BG Color Extract", sf::Style::Close),
	 _num_rows(num_rows)
{
	this->setVerticalSyncEnabled(true);
	this->setFramerateLimit(60);
	UpdateColors(colors);
}

void ColorWindow::UpdateColors(const std::vector<RGBPixel>& colors)
{
	/* std::sort(colors.begin(), colors.end(), [] (const RGBPixel& a, const RGBPixel& b) { */
	/* 		return ((a[0] + a[1] + a[2]) < b[0] + b[1] + b[2]); */
	/* }); */
	uint32_t num_cols = std::ceil(colors.size() / static_cast<double>(_num_rows));
	sf::Vector2u size(GAP_X +  num_cols * (BLOCK_X + GAP_X),
	                  GAP_X + _num_rows * (BLOCK_Y + GAP_X));
	this->setSize(size);

	_colors.clear();
	_colors.reserve(colors.size());

	uint32_t col = 0, row = 0;
	for (auto c : colors) {
		sf::RectangleShape shape(sf::Vector2f(BLOCK_X, BLOCK_Y));
		shape.setFillColor(sf::Color(c[0], c[1], c[2], 255));
		shape.setOutlineColor(sf::Color(c[0], c[1], c[2], 255));
		shape.setPosition(GAP_X + col * (BLOCK_X + GAP_X), GAP_X + row * (BLOCK_Y + GAP_X));
		_colors.push_back(shape);
		if (++col > (num_cols - 1)) {
			col = 0;
			row++;
		}
	}
}

void ColorWindow::Draw()
{
	this->clear(sf::Color::Black);

	std::vector<sf::RectangleShape> shapes;
	shapes.reserve(_colors.size());
	for (auto c : _colors) {
		this->draw(c);
	}

	this->display();
}
