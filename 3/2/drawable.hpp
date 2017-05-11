#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "window.hpp"
#include "vector.hpp"

class drawable {
protected:
	window w;
	vector location;
	vector size;
	vector bounce = vector(1, 1);
public:
	drawable(window &w, const vector &location, const vector &size);
	bool overlaps(const drawable &other);
	virtual void draw() = 0;
	virtual void update(){}
	virtual void interact(drawable &other){}
	vector getBounce();
	std::ostream &print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &lhs, const drawable &rhs);

#endif
