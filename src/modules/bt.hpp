#pragma once
#include <cstdint>
#include <cstddef>
#include "../modules.h"
#include "../led.hpp"

#ifdef MOD_BT
	#include "bt/init.hpp"
	#include "bt/tick.hpp"
	#ifdef MOD_BT_APPLE_SPAMMER
		class BLEAdvertising;
		extern BLEAdvertising* pAdv; // set in init, used in tick
		enum ApplType { AT_AUD, AT_SET };
		struct ApplDev { const char* name; uint8_t id; ApplType type; };
		extern const ApplDev applDevs[];
		extern const int applN;
		void applPacket(const ApplDev& d, uint8_t* buf, size_t& len); // build one adv, shared
	#endif
#endif
