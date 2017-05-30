#ifndef STREET_HPP
#define STREET_HPP

#include "fill.hpp"
#include "house.hpp"
#include "window.hpp"

class street {
private:
	window &w;
	int     houseCount;

	fill ground;
public:
	street(window &w, int houseCount);
	void print();
};

#endif
