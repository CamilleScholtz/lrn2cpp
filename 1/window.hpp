#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>

#ifndef WINDOW_HPP
#define WINDOW_HPP

class window {
private:
	int w;
	int h;
public:
	window(int w, int h);
	void draw(int x, int y);
};

#endif
