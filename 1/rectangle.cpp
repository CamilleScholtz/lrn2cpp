#include "rectangle.hpp"

rectangle::rectangle(window &w, int sx, int sy, int ex, int ey):
	left(w, sx, sy, sx, ey),
	right(w, ex, sy, ex, ey),
	top(w, sx, sy, ex, sy),
	bottom(w, sx, ey, ex+1, ey)
{}

void rectangle::print(){
	left.print();
	right.print();
	top.print();
	bottom.print();
}
