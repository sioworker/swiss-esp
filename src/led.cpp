#include "led.hpp"
#include <Arduino.h>

static unsigned long off = 0;

void ledInit() { pinMode(LED, OUTPUT); }

void ledFlash(unsigned ms) {
	digitalWrite(LED, HIGH);
	off = millis() + ms;
}

void ledTick() {
	if (off && millis() >= off) { digitalWrite(LED, LOW);off = 0; }
}
