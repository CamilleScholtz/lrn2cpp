#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "window.hpp"

class house {
private:
	window &w;
	int    startx;

	rectangle base;
	rectangle door;
	rectangle glass;
	line      shine;
	line      roofLeft;
	line      roofRight;
	rectangle chimney;
	circle    smoke1;
	circle    smoke2;
public:
	house(window &w, int startx);
	void print();
};

#endif
