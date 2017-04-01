#ifndef _XCB_ROOT_IMAGE_H_
#define _XCB_ROOT_IMAGE_H_

#include <xcb/xcb.h>
#include <xcb/xcb_image.h>

#include <array>
#include <vector>

typedef std::array<uint8_t, 3> RGBPixel;

std::vector<RGBPixel> XCBGetRootImage();

#endif /* ifndef _XCB_ROOT_IMAGE_H_ */
