#include "../oled.hpp"

#ifdef MOD_OLED
	#include <Arduino.h>

	void oledInit() {
		if (!oledBegin()) { Serial.println("oled not found"); return; }
		oledShow("swiss-esp", "booting...");
		led.flash(200); // init done
	}
#endif
