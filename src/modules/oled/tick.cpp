#include "../oled.hpp"

#ifdef MOD_OLED
	#include <Arduino.h>

	void oledTick() {
		static unsigned long last = 0, stareAt = 0;
		static int x = -44;
		static bool step = false, staring = false;
		unsigned long now = millis();
		if (staring) {
			if (now - last < 300) return; // blink pace
			last = now;
			step = !step; // reuse as blink flag
			oledCatFront(64, step);
			if (now - stareAt > 2500) { staring = false;x = 49; } // done, walk on
			return;
		}
		if (now - last < 80) return; // ~12fps
		last = now;
		x += 3;
		step = !step;
		oledCat(x, step);
		if (x == 46) { staring = true;stareAt = now; } // mid screen: turn + stare
		if (x > 128) x = -44; // loop back on
	}
#endif
