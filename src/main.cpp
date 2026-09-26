#include <Arduino.h>

#define LED 2

void setup() {
	Serial.begin(115200);
	pinMode(LED, OUTPUT);
}

void loop() {
	digitalWrite(LED, !digitalRead(LED));
	Serial.println(millis());
	delay(100);
}
