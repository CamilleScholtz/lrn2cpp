#include "fill.hpp"

void fill::print() {
	for (int x = sx; x < ex; x++) {
		for (int y = sy; y < ey; y++) {
			w.draw(x, y);
		}
	}
}
