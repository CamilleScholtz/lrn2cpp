#ifndef FILL_HPP
#define FILL_HPP

#include "window.hpp"
#include "line.hpp"

class fill {
private:
	int sx;
	int sy;
	int ex;
	int ey;
	window &w;
public:
	fill(window &w, int sx, int sy, int ex, int ey):
		sx(sx),
		sy(sy),
		ex(ex),
		ey(ey),
		w(w)
	{}
	void print();
};

#endif
