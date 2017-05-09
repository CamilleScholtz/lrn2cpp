#include <stdlib.h>
#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "vector.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP

class window {
private:
	vector size;
public:
	window(const vector &size);
	void clear();
	void draw(const vector &pixel);
};

void wait_ms(int n);

#endif
