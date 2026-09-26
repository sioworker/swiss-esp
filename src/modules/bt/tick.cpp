#include "../bt.hpp"

#ifdef MOD_BT
	#include <Arduino.h>
	#include <BLEDevice.h>
	#include <esp_gap_ble_api.h>
	#include <string>

	void btTick() {
		#ifdef MOD_BT_APPLE_SPAMMER
			static unsigned long last = 0;
			static bool advOn = false;
			unsigned long now = millis();
			if (advOn && now - last < MOD_BT_APPLE_INT) return; // keep current device up
			if (advOn) { pAdv->stop();advOn = false; }
			esp_bd_addr_t mac;
			for (int i = 0; i < 6; i++) mac[i] = random(256);
			mac[0] |= 0xf0; // top bits high => valid random addr, new device each time
			const ApplDev& d = applDevs[random(applN)];
			uint8_t pkt[31];size_t n;applPacket(d, pkt, n);
			BLEAdvertisementData ad;
			ad.addData(std::string((char*)pkt, n));
			int t = random(3); // vary pdu type, apple uses all 3
			pAdv->setAdvertisementType(t == 0 ? ADV_TYPE_IND : t == 1 ? ADV_TYPE_SCAN_IND : ADV_TYPE_NONCONN_IND);
			pAdv->setDeviceAddress(mac, BLE_ADDR_TYPE_RANDOM);
			pAdv->setAdvertisementData(ad);
			pAdv->start();
			advOn = true;last = now;
		#endif
	}
#endif
