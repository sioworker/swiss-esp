#include "../bt.hpp"

#ifdef MOD_BT
	#include <BLEDevice.h>
	#include <BLEServer.h>
	#include <esp_gap_ble_api.h>

	void btInit() {
		BLEDevice::init(""); // brings up controller + bluedroid + gap
		esp_ble_tx_power_set(ESP_BLE_PWR_TYPE_ADV, ESP_PWR_LVL_P9);
		#ifdef MOD_BT_APPLE_SPAMMER
			pAdv = BLEDevice::createServer()->getAdvertising();
			esp_bd_addr_t a = {0xf0,0xed,0xc0,0xff,0xee,0x69}; // needs an addr set once in init
			pAdv->setDeviceAddress(a, BLE_ADDR_TYPE_RANDOM);
		#endif
		ledFlash(200); // init done
	}
#endif
