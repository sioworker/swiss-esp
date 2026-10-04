#include "util.hpp"
#include <Arduino.h>

Led led;
static unsigned long off = 0;

void Led::init() { pinMode(LED, OUTPUT); }

void Led::flash(unsigned ms) {
	digitalWrite(LED, HIGH);
	off = millis() + ms;
}

void Led::tick() {
	if (off && millis() >= off) { digitalWrite(LED, LOW);off = 0; }
}

Btn Button;
static bool held = false, dbl = false, nextF = false, prevF = false, confF = false;
static unsigned long downAt = 0, edgeAt = 0, firstDown = 0;

void Btn::init() { pinMode(BTN, INPUT_PULLUP); }

bool Btn::pressed() { return digitalRead(BTN) == LOW; } // active low

void Btn::tick() {
	bool cur = pressed();unsigned long now = millis();
	if (cur == held || now - edgeAt < 20) return; // no edge / debounce
	edgeAt = now;held = cur;
	if (cur) { // press
		if (firstDown && now - firstDown <= BTN_DOUBLE) { prevF = true;dbl = true;firstDown = 0; } // 2nd quick tap
		else { firstDown = now;dbl = false; }
		downAt = now;
	} else { // release
		if (dbl) { dbl = false;return; } // 2nd click of double, done
		unsigned long h = now - downAt;
		Serial.printf("held %lums\n", h);
		if (h >= BTN_CONFIRM) { confF = true;firstDown = 0; }
		else if (h >= BTN_NEXT) { nextF = true;firstDown = 0; }
		// else short tap: keep firstDown as double candidate
	}
}

bool Btn::next() { bool f = nextF;nextF = false;return f; }
bool Btn::previous() { bool f = prevF;prevF = false;return f; }
bool Btn::confirm() { bool f = confF;confF = false;return f; }

void Btn::waitPress() { while (!pressed()) { led.tick();delay(1); } }
void Btn::waitRelease() { while (pressed()) { led.tick();delay(1); } }
