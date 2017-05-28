#include "hwlib.hpp"
/// \file

/// \brief
/// Count using LEDs.
/// \details
/// Count is a function that uses a counter to turn LEDs on or off.
// This counter can be altered by using two buttons, one to decrease
/// the counter, and one to increase the counter.
///
/// @param[in] leds - An array of the leds.
/// @param[in] l    - The button that is used to decrease the counter.
/// @param[in] r    - The button that is used to increase the counter.
void blink(hwlib::port_out &leds, hwlib::pin_in &l ,hwlib::pin_in &r) {
	unsigned c = 0;

	// These values only become true once the l or r buttons are pressed.
	bool lp = false;
	bool rp = false;

	while (true) {
		if (l.get() == 0 && lp == false) {
			if (c > 0 && c <= leds.number_of_pins()) {
				c--;
			}
		  	lp = true;
		}
		if (l.get() == 1) {
			 lp = false;
		}

		if (r.get() == 0 && rp == false) {
			if (c < leds.number_of_pins()) {
				c++;
			 }
			 rp = true;
		}
		if (r.get() == 1) {
			 rp = false;
		}

		for (unsigned int i=0; i<c; i++) {
			 leds.set(1 << i);
		}

		// When c is 0 all LEDs should be of.
		if (c == 0) {
			leds.set(0x00);
		}
	}
}

int main(void) {
	// Kill the watchdog.
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace t = hwlib::target;

	// Initialize the leds.
	auto r = t::pin_out(t::pins::d13);
	auto y = t::pin_out(t::pins::d12);
	auto g = t::pin_out(t::pins::d11);

	auto leds = hwlib::port_out_from_pins(r, y, g);

	// Initialize the buttons.
	auto bl = t::pin_in(target::pins::d10);
	auto br = t::pin_in(target::pins::d9);

	blink(leds, bl, br);
}
