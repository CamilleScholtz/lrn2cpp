#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "victim.hpp"
#include "wall.hpp"

int main() {
	window w(vector(128, 64));
	wall top(w, vector(0,  0), vector(124, 4), 2, vector(1, -1));
	wall right(w, vector(120,  0), vector(124, 62), 2, vector(-1, 1));
	wall bottom(w, vector(0, 60), vector(124, 64), 2, vector(1, -1));
	wall left(w, vector(0, 0), vector(4, 60), 2, vector(-1, 1));
	ball b(w, vector(50, 20), 8, vector(10, 6));
	victim v(w, vector(50, 20), vector(60, 30));

	drawable *objects[] = {&v, &b, &top, &left, &right, &bottom};

	for (int i=0; i<64; i++) {
		for(auto &p : objects) {
			p->draw();
		}
		for(auto &p : objects ) {
			 p->update();
		}
		for(auto &p : objects) {
			for(auto &other : objects){
				p->interact(*other);
			}
		}
	}
}
