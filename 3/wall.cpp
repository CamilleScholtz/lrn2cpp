#include "wall.hpp"

wall::wall(window& w, const vector &start, const vector &end, const int &interval):
	rectangle(w, start, end),
	fill(true),
	interval(interval),
	box(w, start, end)
{}

void wall::draw() {
	if(fill == true) {
		for (int y=start.y; y < end.y; y++) {
			for (int x=start.x; x < end.x; x++) {
				w.draw(vector(x, y));
			}
		}
	}

	box.draw();
}

void wall::update() {
	count++;
	if ((count % interval) == 0){
		if (fill == true){
			fill = false;
		} else if (fill == false) {
			fill = true;
		}
	}
}
