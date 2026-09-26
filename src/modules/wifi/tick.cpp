#include "../wifi.hpp"

#ifdef MOD_WIFI
	#include <Arduino.h>

	void wifiTick() {
		#ifdef MOD_WIFI_AP_SPAMMER
			static unsigned long last = 0;
			if (millis() - last < 100) return; // ~10hz per ap
			last = millis();
			for (int i = 0; i < MOD_WIFI_AP_SPAMMER_COUNT; i++) {
				char ssid[33];
				snprintf(ssid, sizeof(ssid), "%s%d", MOD_WIFI_AP_SPAMMER_NAME, i);
				wifiBeacon(ssid, i);
			}
		#endif
	}
#endif
