#include <Arduino.h>

#define LED 2
#define BTN 0

bool prev = HIGH;
unsigned long last = 0;

void setup() {
	Serial.begin(115200);
	pinMode(LED, OUTPUT);
	pinMode(BTN, INPUT_PULLUP);
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
}
