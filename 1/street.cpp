#include "street.hpp"

street::street(window &w, int c):
	w(w),
	c(c),
	ground(w,     0,         59, 128,       65)
{}

void street::house(window &w, int c) {
	rectangle base(w,       8+(c*40),  30, 40+(c*40), 55);
	rectangle door(w,       13+(c*40), 42, 21+(c*40), 55);
	rectangle window(w,     28+(c*40), 42, 34+(c*40), 48);
	line      windowLine(w, 28+(c*40), 42, 34+(c*40), 48);
	line      roofLeft(w,   8+(c*40),  30, 24+(c*40), 14);
	line      roofRight(w,  40+(c*40), 30, 24+(c*40), 14);
	rectangle chimney(w,    32+(c*40), 14, 36+(c*40), 25);
	circle    smoke1(w,     32+(c*40), 11, 4);
	circle    smoke2(w,     35+(c*40), 7,  3);

	base.print();
	door.print();
	window.print();
	windowLine.print();
	roofLeft.print();
	roofRight.print();
	chimney.print();
	smoke1.print();
	smoke2.print();
	ground.print();
}

void street::print() {
	ground.print();
	for (int i=0; i<c; i++) {
		house(w, i);
	}
}
