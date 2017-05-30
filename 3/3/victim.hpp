#include "window.hpp"
#include "line.hpp"
#include "drawable.hpp"
// @file

/// \brief
/// victim
/// \details
/// A rectangle, every time the ball touches this rectangle it will shrink.
class victim : public drawable {
protected:
	vector start;
	vector end;
private:
	line left;
	line right;
	line top;
	line bottom;
public:
	victim(window &w, const vector &start, const vector &end);
	void draw() override;
	void interact(drawable &other) override;
};
