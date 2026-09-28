#pragma once
#include "../modules.h"
#include "../led.hpp"

#ifdef MOD_OLED
	#include "oled/init.hpp"
	#include "oled/tick.hpp"
	bool oledBegin();                                    // power+i2c+panel init, shared
	void oledShow(const char* title, const char* line);  // 2 lines, shared
	void oledCat(int x, bool step);                      // full walking-cat frame at x, shared
	void oledCatFront(int cx, bool blink);               // front stare pose, shared
#endif
