#include "victim.hpp"

victim::victim(window &w, const vector &start, const vector& end):
   drawable(w, start, end - start),
   start(start),
   end(end),
   left(w, vector(start.x, start.y), vector(start.x,end.y)),
   right(w, vector(end.x, start.y), vector(end.x, end.y)),
   top(w, vector(start.x, start.y), vector(end.x, start.y)),
   bottom(w, vector(start.x, end.y), vector(end.x, end.y ))
{}

void victim::draw() {
	for (int x = start.x; x < end.x; x++) {
		for (int y = start.y; y < end.y; y++) {
			w.draw(vector(x, y));
		}
	}
}

void victim::interact(drawable &other) {
	if (this != &other) {
		if (overlaps(other)) {
			if (start.x < end.x) {
				start.x++;
			}
			if (start.y < end.y) {
				start.y++;
			}
			if (end.x > start.y) {
				end.x--;
			}
			if (end.y > start.y) {
				end.y--;
			}
		}
	}
}
