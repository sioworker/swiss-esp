#pragma once

// --- MODULES ---
// #define MOD_WIFI
#define MOD_BT

// --- MODULE/FUNCTIONS ---
#ifdef MOD_WIFI
    // --- WiFi AP Mass-Creator ---
    #define MOD_WIFI_AP_SPAMMER
    #ifdef MOD_WIFI_AP_SPAMMER
        #define MOD_WIFI_AP_SPAMMER_COUNT 100
        #define MOD_WIFI_AP_SPAMMER_NAME "lubie-koty-"//+ index
    #endif
#endif

#ifdef MOD_BT
    // --- Apple Proximity Spammer ---
    #define MOD_BT_APPLE_SPAMMER
    #ifdef MOD_BT_APPLE_SPAMMER
        #define MOD_BT_APPLE_INT 100 // ms to hold each device+mac before rotating
        /* 
            AUD=audio 31B popup - AUD(name,modelId)
            SET=setup 23B popup - SET(name,modelId)
        */
        #define MOD_BT_APPLE_DEVS(AUD, SET) \
            AUD("Airpods", 0x02) \
            AUD("Power Beats", 0x03) \
            AUD("Beats X", 0x05) \
            AUD("Beats Solo 3", 0x06) \
            AUD("Beats Studio 3", 0x09) \
            AUD("Airpods Max", 0x0a) \
            AUD("Power Beats Pro", 0x0b) \
            AUD("Beats Solo Pro", 0x0c) \
            AUD("Airpods Pro", 0x0e) \
            AUD("Airpods Gen 2", 0x0f) \
            AUD("Beats Flex", 0x10) \
            AUD("Beats Studio Buds", 0x11) \
            AUD("Beats Fit Pro", 0x12) \
            AUD("Airpods Gen 3", 0x13) \
            AUD("Airpods Pro Gen 2", 0x14) \
            AUD("Beats Studio Buds Plus", 0x16) \
            AUD("Beats Studio Pro", 0x17) \
            AUD("Airpods Pro Gen 2 USB-C", 0x24) \
            AUD("Beats Solo 4", 0x25) \
            AUD("Beats Solo Buds", 0x26) \
            AUD("Software update", 0x2e) \
            AUD("Powerbeats fit", 0x2f) \
            SET("AppleTV Setup", 0x01) \
            SET("Transfer Number", 0x02) \
            SET("AppleTV Pair", 0x06) \
            SET("Setup New Phone", 0x09) \
            SET("Homepod Setup", 0x0b) \
            SET("AppleTV Homekit Setup", 0x0d) \
            SET("AppleTV Keyboard Setup", 0x13) \
            SET("TV Color Balance", 0x1e) \
            SET("AppleTV New User", 0x20) \
            SET("Vision Pro", 0x24) \
            SET("AppleTV Connecting to Network", 0x27) \
            SET("AppleTV AppleID Setup", 0x2b) \
            SET("AppleTV Wireless Audio Sync", 0xc0)
    #endif
    // --- Fake BT Keyboard ---
    #define MOD_BT_KEYTOOTH
    #ifdef MOD_BT_KEYTOOTH
        // TODO (rewrite hx4c/keytooth)
    #endif
#endif