#ifndef _ANSI_COLORS_H_
#define _ANSI_COLORS_H_

#include <array>
#include <vector>

const std::vector<std::array<uint8_t, 3>> ansi_colors_16 = {
	{{0x00, 0x00, 0x00}}, // black
	{{0x80, 0x00, 0x00}}, // red
	{{0x00, 0x80, 0x00}}, // green
	{{0x80, 0x80, 0x00}}, // yellow
	{{0x00, 0x00, 0x80}}, // blue
	{{0x80, 0x00, 0x80}}, // magenta
	{{0x00, 0x80, 0x80}}, // cyan
	{{0xc0, 0xc0, 0xc0}}, // white
	{{0x80, 0x80, 0x80}}, // bright black
	{{0xff, 0x00, 0x00}}, // bright red
	{{0x00, 0xff, 0x00}}, // bright green
	{{0xff, 0xff, 0x00}}, // bright yellow
	{{0x00, 0x00, 0xff}}, // bright blue
	{{0xff, 0x00, 0xff}}, // bright magenta
	{{0x00, 0xff, 0xff}}, // bright cyan
	{{0xff, 0xff, 0xff}}  // bright white
};

const std::vector<std::array<uint8_t, 3>> ansi_colors_22 = {
	{{0x00, 0x00, 0x00}}, // black
	{{0x80, 0x00, 0x00}}, // red
	{{0x00, 0x80, 0x00}}, // green
	{{0x80, 0x80, 0x00}}, // yellow
	{{0x00, 0x00, 0x80}}, // blue
	{{0x80, 0x00, 0x80}}, // magenta
	{{0x00, 0x80, 0x80}}, // cyan
	{{0xc0, 0xc0, 0xc0}}, // white
	{{0x80, 0x80, 0x80}}, // bright black
	{{0xff, 0x00, 0x00}}, // bright red
	{{0x00, 0xff, 0x00}}, // bright green
	{{0xff, 0xff, 0x00}}, // bright yellow
	{{0x00, 0x00, 0xff}}, // bright blue
	{{0xff, 0x00, 0xff}}, // bright magenta
	{{0x00, 0xff, 0xff}}, // bright cyan
	{{0xff, 0xff, 0xff}}, // bright white
	{{0xff, 0x80, 0x40}}, // orange
	{{0x80, 0x40, 0x20}}, // brown
	{{0x30, 0x30, 0x30}}, // dark grey
	{{0x50, 0x50, 0x50}}, // light grey
	{{0xa0, 0xa0, 0xa0}}, // lighter grey
	{{0xe0, 0xe0, 0xe0}}, // lightest grey
};

#endif /* ifndef _ANSI_COLORS_H_ */
