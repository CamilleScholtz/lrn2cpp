#ifndef LINE_HPP
#define LINE_HPP

#include <stdlib.h>

#include "window.hpp"

class line {
private:
	int sx;
	int sy;
	int ex;
	int ey;
	window &w;
public:
	line(window &w, int sx, int sy, int ex, int ey):
		sx(sx),
		sy(sy),
		ex(ex),
		ey(ey),
		w(w)
	{}
	void print();
};

#endif
