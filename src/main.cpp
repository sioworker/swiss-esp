#include <Arduino.h>
#include "modules.h"
#include "modules/wifi.hpp"

#define LED 2
#define BTN 0

bool prev = HIGH;
unsigned long last = 0;

void setup() {
	Serial.begin(115200);
	pinMode(LED, OUTPUT);
	pinMode(BTN, INPUT_PULLUP);
#ifdef MOD_WIFI
	wifiInit();
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
#ifdef MOD_WIFI
	wifiTick();
#endif
}
