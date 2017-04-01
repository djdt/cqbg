#include "XCBRootImage.hpp"

#include <iostream>

xcb_pixmap_t* GetRootPixmap(xcb_connection_t* conn, xcb_screen_t* screen)
{
	xcb_intern_atom_cookie_t atom_cookie = xcb_intern_atom(
			conn, 0, 13, "_XROOTPMAP_ID");
	xcb_intern_atom_reply_t* atom_reply = xcb_intern_atom_reply(
			conn, atom_cookie, nullptr);
	xcb_atom_t atom = atom_reply->atom;
	delete atom_reply;

	xcb_get_property_cookie_t cookie = xcb_get_property(
			conn, 0, screen->root, atom, XCB_ATOM_PIXMAP, 0, 1);
	xcb_get_property_reply_t* reply = xcb_get_property_reply(
			conn, cookie, nullptr);
	xcb_pixmap_t* pixmap = static_cast<xcb_pixmap_t*>(
			xcb_get_property_value(reply));
	delete reply;

	return pixmap;
}

std::vector<RGBPixel> CreateFromXImage(xcb_image_t* image)
{
	std::vector<RGBPixel> img_data;

	img_data.reserve(image->width * image->height);

	for (uint32_t y = 0; y < image->height; ++y) {
		for (uint32_t x = 0; x < image->width; ++x) {
			uint32_t pixel = xcb_image_get_pixel(image, x, y);
			img_data.push_back({{static_cast<uint8_t>(pixel >> 16),
					                 static_cast<uint8_t>((pixel & 0x00ff00) >> 8),
			                     static_cast<uint8_t>(pixel & 0x0000ff)}});
		}
	}

	return img_data;
}

std::vector<RGBPixel> XCBGetRootImage()
{
	/* Get the current background image */
	int default_screen_num;
	xcb_connection_t* conn = xcb_connect(nullptr, &default_screen_num);
	if (conn == nullptr) {
		std::cerr << "Failed to open display." << std::endl;
		return {};
	}

	xcb_screen_t* screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
	if (screen == nullptr) {
		std::cerr << "Failed to get xcb screen." << std::endl;
		return {};
	}

	xcb_pixmap_t* pixmap = GetRootPixmap(conn, screen);
	if (pixmap == nullptr) {
		std::cerr << "Failed to get pixmap." << std::endl;
		return {};
	}

	xcb_image_t* image = xcb_image_get(conn, *pixmap, 0, 0,
			screen->width_in_pixels, screen->height_in_pixels, ~0, XCB_IMAGE_FORMAT_Z_PIXMAP);

	if (image == nullptr) {
		std::cerr << "Could not create xcb image." << std::endl;
		return {};
	}

	/* Get the image bytes from background */
	auto img_data = CreateFromXImage(image);
	xcb_image_destroy(image);

	xcb_set_close_down_mode(conn, XCB_CLOSE_DOWN_RETAIN_PERMANENT);
	xcb_disconnect(conn);

	return img_data;
}
