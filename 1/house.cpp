#include "house.hpp"

house::house(window &w, int startx):
	w(w),
	startx(startx),

	base(w, 8+(startx*40), 30, 40+(startx*40), 55),
	door(w, 13+(startx*40), 42, 21+(startx*40), 55),
	glass(w, 28+(startx*40), 42, 34+(startx*40), 48),
	shine(w, 28+(startx*40), 42, 34+(startx*40), 48),
	roofLeft(w, 8+(startx*40), 30, 24+(startx*40), 14),
	roofRight(w, 40+(startx*40), 30, 24+(startx*40), 14),
	chimney(w, 32+(startx*40), 14, 36+(startx*40), 25),
	smoke1(w, 32+(startx*40), 11, 4),
	smoke2(w, 35+(startx*40), 7, 3)
{}

void house::print() {
	base.print();
	door.print();
	glass.print();
	shine.print();
	roofLeft.print();
	roofRight.print();
	chimney.print();
	smoke1.print();
	smoke2.print();
}