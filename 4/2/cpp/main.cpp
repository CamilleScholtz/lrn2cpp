#include <cmath>
#include "hwlib.hpp"
/// \file

/// \brief
/// Count using LEDs and buttons.
/// \details
/// Count is a function that uses a counter to turn LEDs on or off.
/// This counter can be altered by using two buttons, one to decrease
/// the counter, and one to increase the counter.
///
/// @param[in] leds - An array of the leds.
/// @param[in] l    - The button that is used to decrease the counter.
/// @param[in] r    - The button that is used to increase the counter.
void blink(hwlib::port_out &leds, hwlib::pin_in &l ,hwlib::pin_in &r) {
	int p = 0;

	// These values only become true once the l or r buttons are pressed.
	bool lp = false;
	bool rp = false;

	if (l.get()) {
		lp = true;
	} else if (lp) {
		if (p < leds.number_of_pins())-1) {
			p++;
		} else {
			p = 0;
		}
		lp = false;
	}

	if (r.get()) {
		rp = true;
	} else if (rp) {
		if (p < 0) {
			p--;
		} else {
			p = leds.number_of_pins() - 1
		}
		rp = false;
	}

	leds.set(pow(2.0, p)-1);
}

int main(void) {
	// Kill the watchdog.
	WDT->WDT_MR = WDT_MR_WDDIS;

	namespace t = hwlib::target;

	// Initialize LEDs.
	auto l1 = t::pin_out(t::pins::d13);
	auto l2 = t::pin_out(t::pins::d12);
	auto l3 = t::pin_out(t::pins::d11);
	auto l4 = t::pin_out(t::pins::d10);
	auto leds = hwlib::port_out_from_pins(l1, l2, l3, l4);

	// Initialize the buttons.
	auto bl = t::pin_in(target::pins::d8);
	auto br = t::pin_in(target::pins::d7);

	blink(leds, bl, br);
}
