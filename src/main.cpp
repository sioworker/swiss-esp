#include <Arduino.h>
#include "modules.h"
#include "util.hpp"
#include "modules/wifi.hpp"
#include "modules/bt.hpp"
#include "modules/oled.hpp"

void setup() {
	Serial.begin(115200);
	led.init();
	Button.init();
	#ifdef MOD_WIFI
		wifiInit();
	#endif
	#ifdef MOD_BT
		btInit();
	#endif
	#ifdef MOD_OLED
		oledInit();
	#endif
}

void loop() {
	Button.tick();
	led.tick();
	#ifdef MOD_WIFI
		wifiTick();
	#endif
	#ifdef MOD_BT
		btTick();
	#endif
	#ifdef MOD_OLED
		oledTick();
	#endif
}
