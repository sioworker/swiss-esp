#include "../wifi.hpp"

#ifdef MOD_WIFI
	#ifdef MOD_WIFI_AP_SPAMMER
		#include <WiFi.h>
		#include <esp_wifi.h>
	#endif

	void wifiInit() {
		#ifdef MOD_WIFI_AP_SPAMMER
			WiFi.mode(WIFI_MODE_AP);
			esp_wifi_set_promiscuous(true);
			esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
			Serial.printf("beaconing %s0..%d\n", MOD_WIFI_AP_SPAMMER_NAME, MOD_WIFI_AP_SPAMMER_COUNT - 1);
		#endif
		#ifdef MOD_WIFI_PORTAL
			portalInit();
		#endif
		led.flash(200); // init done
	}
#endif
