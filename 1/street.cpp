#include "street.hpp"

street::street(window &w, int houseCount):
	w(w),
	houseCount(houseCount),

	ground(w, 0, 59, 128, 65)
{}

void street::print() {
	ground.print();
	for (int i=0; i<houseCount; i++) {
		house house(w, i);
		house.print();
	}
}
