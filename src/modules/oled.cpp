#include "oled.hpp"

#ifdef MOD_OLED
	#include <Arduino.h>
	#include <Wire.h>
	#include <Adafruit_SSD1306.h>

	static Adafruit_SSD1306 disp(MOD_OLED_W, MOD_OLED_H, &Wire, -1);

	bool oledBegin() {
		pinMode(MOD_OLED_VCC, OUTPUT);
		digitalWrite(MOD_OLED_VCC, HIGH);delay(100); // let the panel power up
		Wire.begin(MOD_OLED_SDA, MOD_OLED_SCL);
		for (uint8_t a = 1; a < 127; a++) { Wire.beginTransmission(a);if (Wire.endTransmission() == 0) Serial.printf("i2c @0x%02x\n", a); }
		return disp.begin(SSD1306_SWITCHCAPVCC, MOD_OLED_ADDR);
	}

	void oledShow(const char* title, const char* line) {
		disp.clearDisplay();
		disp.setTextColor(SSD1306_WHITE);
		disp.setTextSize(2);disp.setCursor(0, 0);disp.println(title);
		disp.setTextSize(1);disp.setCursor(0, 28);disp.println(line);
		disp.display();
	}

	#define W SSD1306_WHITE
	#define B SSD1306_BLACK
	void oledCat(int x, bool step) {
		const int fy = 46; // feet baseline
		disp.clearDisplay();
		disp.drawFastHLine(0, fy + 1, 128, W); // ground
		if (step) disp.drawLine(x + 2, fy - 14, x - 4, fy - 22, W); // tail up
		else      disp.drawLine(x + 2, fy - 14, x - 5, fy - 15, W); // tail out
		disp.fillRoundRect(x + 4, fy - 18, 28, 12, 4, W); // body
		disp.fillCircle(x + 34, fy - 14, 7, W); // head
		disp.fillTriangle(x + 30, fy - 20, x + 34, fy - 20, x + 31, fy - 27, W); // ear
		disp.fillTriangle(x + 36, fy - 20, x + 40, fy - 20, x + 39, fy - 27, W); // ear
		disp.fillCircle(x + 37, fy - 15, 1, B); // eye
		int a = step ? 6 : 5, b = step ? 5 : 6; // alt leg lengths = stepping
		disp.fillRect(x + 6,  fy - 6, 3, a, W);
		disp.fillRect(x + 14, fy - 6, 3, b, W);
		disp.fillRect(x + 22, fy - 6, 3, a, W);
		disp.fillRect(x + 28, fy - 6, 3, b, W);
		disp.display();
	}

	void oledCatFront(int cx, bool blink) {
		const int cy = 15; // head center
		disp.clearDisplay();
		disp.drawFastHLine(0, 47, 128, W); // ground
		disp.fillRoundRect(cx - 12, 26, 24, 18, 6, W); // body
		disp.fillRect(cx - 8, 42, 4, 5, W);disp.fillRect(cx + 4, 42, 4, 5, W); // front paws
		disp.fillCircle(cx, cy, 11, W); // head
		disp.fillTriangle(cx - 11, cy - 4, cx - 3, cy - 7, cx - 12, cy - 15, W); // ear
		disp.fillTriangle(cx + 11, cy - 4, cx + 3, cy - 7, cx + 12, cy - 15, W); // ear
		if (blink) { disp.drawFastHLine(cx - 7, cy - 1, 5, B);disp.drawFastHLine(cx + 2, cy - 1, 5, B); }
		else { disp.fillCircle(cx - 4, cy - 1, 2, B);disp.fillCircle(cx + 4, cy - 1, 2, B); } // staring eyes
		disp.fillTriangle(cx - 2, cy + 3, cx + 2, cy + 3, cx, cy + 5, B); // nose
		disp.drawLine(cx, cy + 5, cx - 3, cy + 7, B);disp.drawLine(cx, cy + 5, cx + 3, cy + 7, B); // mouth
		disp.drawLine(cx - 6, cy + 3, cx - 17, cy + 1, W);disp.drawLine(cx - 6, cy + 4, cx - 17, cy + 5, W); // whiskers
		disp.drawLine(cx + 6, cy + 3, cx + 17, cy + 1, W);disp.drawLine(cx + 6, cy + 4, cx + 17, cy + 5, W);
		disp.display();
	}
	#undef W
	#undef B
#endif
