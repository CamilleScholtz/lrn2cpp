#include "hwlib.hpp"
/// \file

/// \brief
/// Show a pattern.
/// \details
/// A function that makes LEDs blink in a patterns.
///
/// @param[in] leds - An array of the LEDs.
/// @param[in] ms   - The time to sleep.
void blink(hwlib::port_out &leds, int ms=500) {
	int p = 3;
	while (true) {
		for(unsigned int i=0; i<leds.number_of_pins()/2; i++) {
			leds.set(p);
			p *= 2;
			hwlib::wait_ms(ms);
		}
		for(unsigned int i=0; i<leds.number_of_pins()/2; i++) {
			leds.set(p);
			p /= 2;
			hwlib::wait_ms(ms);
		}
	}
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

	blink(leds);
}
