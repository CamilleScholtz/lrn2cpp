#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "window.hpp"
#include "line.hpp"

class rectangle {
private:
	line left, right, top, bottom;
public:
	rectangle(window &w, int sx, int sy, int ex, int ey);
	void print();
};

#endif
