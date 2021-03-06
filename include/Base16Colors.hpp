#ifndef _BASE_16_COLORS_H_
#define _BASE_16_COLORS_H_

#include <array>
#include <vector>

const std::vector<std::array<uint8_t, 3>> base_16_eighties = {
	{{0x2d, 0x2d, 0x2d}}, // Base 00 - Black
	{{0xf2, 0x77, 0x7a}}, // Base 08 - Red
	{{0x99, 0xcc, 0x99}}, // Base 0B - Green
	{{0xff, 0xcc, 0x66}}, // Base 0A - Yellow
	{{0x66, 0x99, 0xcc}}, // Base 0D - Blue
	{{0xcc, 0x99, 0xcc}}, // Base 0E - Magenta
	{{0x66, 0xcc, 0xcc}}, // Base 0C - Cyan
	{{0xd3, 0xd0, 0xc8}}, // Base 05 - White
	{{0x74, 0x73, 0x69}}, // Base 03 - Bright Black
	{{0xf2, 0x77, 0x7a}}, // Base 08 - Bright Red
	{{0x99, 0xcc, 0x99}}, // Base 0B - Bright Green
	{{0xff, 0xcc, 0x66}}, // Base 0A - Bright Yellow
	{{0x66, 0x99, 0xcc}}, // Base 0D - Bright Blue
	{{0xcc, 0x99, 0xcc}}, // Base 0E - Bright Magenta
	{{0x66, 0xcc, 0xcc}}, // Base 0C - Bright Cyan
	{{0xf2, 0xf0, 0xec}}, // Base 07 - Bright White
	{{0xf9, 0x91, 0x57}}, // Base 09
	{{0xd2, 0x7b, 0x53}}, // Base 0F
	{{0x39, 0x39, 0x39}}, // Base 01
	{{0x51, 0x51, 0x51}}, // Base 02
	{{0xa0, 0x9f, 0x93}}, // Base 04
	{{0xe8, 0xe6, 0xdf}}, // Base 06
};
#endif /* ifndef _BASE_16_COLORS_H_ */
