#include "window.hpp"
#include "line.hpp"
#include "drawable.hpp"

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
