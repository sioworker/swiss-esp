#pragma once
#define LED 2 // onboard led

void ledInit();
void ledFlash(unsigned ms); // non-blocking, ledTick turns it off
void ledTick();
