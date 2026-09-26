#pragma once

// --- MODULES ---
#define MOD_WIFI
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
        // TODO
        // i have no idea how to do this...
    #endif
    // --- Fake BT Keyboard ---
    #define MOD_BT_KEYTOOTH
    #ifdef MOD_BT_KEYTOOTH
        // TODO (rewrite hx4c/keytooth)
    #endif
#endif