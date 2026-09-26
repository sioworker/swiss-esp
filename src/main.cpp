#include <Arduino.h>
#include "modules.h"
#include "led.hpp"
#include "modules/wifi.hpp"
#include "modules/bt.hpp"

#define BTN 0

bool prev = HIGH;
unsigned long last = 0;

void setup() {
	Serial.begin(115200);
	ledInit();
	pinMode(BTN, INPUT_PULLUP);
	#ifdef MOD_WIFI
		wifiInit();
	#endif
	#ifdef MOD_BT
		btInit();
	#endif
}

void loop() {
	bool cur = digitalRead(BTN);
	if (cur != prev && millis() - last > 50) {
		last = millis();
		if (cur == LOW) {
			digitalWrite(LED, !digitalRead(LED));
			Serial.println("boot pressed");
		}
		prev = cur;
	}
	ledTick();
	#ifdef MOD_WIFI
		wifiTick();
	#endif
	#ifdef MOD_BT
		btTick();
	#endif
}
