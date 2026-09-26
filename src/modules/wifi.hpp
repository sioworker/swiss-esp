#pragma once
#include <cstdint>
#include "../modules.h"
#include "../led.hpp"

#ifdef MOD_WIFI
	#include "wifi/init.hpp"
	#include "wifi/tick.hpp"
	#ifdef MOD_WIFI_AP_SPAMMER
		void wifiBeacon(const char* ssid, uint8_t idx); // build+tx one beacon, shared
	#endif
#endif
