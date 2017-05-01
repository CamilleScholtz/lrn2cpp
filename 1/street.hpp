#ifndef STREET_HPP
#define STREET_HPP

#include "circle.hpp"
#include "fill.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "window.hpp"

class street {
private:
	int     c;
	window &w;

	fill ground;
public:
	street(window &w, int c);
	void house(window &w, int c);
	void print();
};

#endif
