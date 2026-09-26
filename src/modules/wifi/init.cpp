#include "../wifi.hpp"

#ifdef MOD_WIFI
	#include <WiFi.h>
	#include <esp_wifi.h>

	void wifiInit() {
		WiFi.mode(WIFI_MODE_AP);
		esp_wifi_set_promiscuous(true);
		esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
		#ifdef MOD_WIFI_AP_SPAMMER
			Serial.printf("beaconing %s0..%d\n", MOD_WIFI_AP_SPAMMER_NAME, MOD_WIFI_AP_SPAMMER_COUNT - 1);
		#endif
		ledFlash(200); // init done
	}
#endif
