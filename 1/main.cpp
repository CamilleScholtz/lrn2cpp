#include "street.hpp"
#include "window.hpp"

int main() {
	window w(128, 64);

	// The second argument defines the amount of houses there should
	// be.
	street qt(w, 3);
	qt.print();

	return 0;
}
