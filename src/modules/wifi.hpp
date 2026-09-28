#pragma once
#include <cstdint>
#include "../modules.h"
#include "../led.hpp"

#ifdef MOD_WIFI
	#if defined(MOD_WIFI_AP_SPAMMER) && defined(MOD_WIFI_PORTAL)
		#error "enable only one wifi mode: AP_SPAMMER or PORTAL (they share the radio)"
	#endif
	#include "wifi/init.hpp"
	#include "wifi/tick.hpp"
	#include "wifi/portal.hpp"
	#ifdef MOD_WIFI_AP_SPAMMER
		void wifiBeacon(const char* ssid, uint8_t idx); // build+tx one beacon, shared
	#endif
#endif
