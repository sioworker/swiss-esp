#pragma once
#define LED 2 // onboard led
#define BTN 0 // boot button
#define BTN_NEXT 130    // min hold ms => next (shorter taps feed double)
#define BTN_CONFIRM 250 // min hold ms => confirm
#define BTN_DOUBLE 249  // 2 presses within this ms => previous

struct Led {
	void init();
	void flash(unsigned ms); // non-blocking, tick turns it off
	void tick();
};
extern Led led;

struct Btn {
	void init();
	void tick();        // call once per loop (main), detects gestures
	bool pressed();     // live: held down right now
	bool next();        // consume: tap held BTN_NEXT..BTN_CONFIRM
	bool previous();    // consume: 2 quick taps within BTN_DOUBLE
	bool confirm();     // consume: held >= BTN_CONFIRM
	void waitPress();   // block til pressed (leds keep ticking)
	void waitRelease(); // block til released
};
extern Btn Button;
