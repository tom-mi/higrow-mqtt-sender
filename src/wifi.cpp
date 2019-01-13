#include <WiFi.h>
#include <WiFiClient.h>
#include "wifi.h"

const int WIFI_CONNECT_TIMEOUT_SECONDS = 30;

boolean connect_wifi() {
  Serial.print(F("Connecting to wifi "));
  Serial.println(WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  for (int i=0; i<WIFI_CONNECT_TIMEOUT_SECONDS && WiFi.status() != WL_CONNECTED; i++) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print(F("Connected to "));
    Serial.println(WIFI_SSID);
    Serial.print(F("IP address: "));
    Serial.println(WiFi.localIP());
    return true;
  } else {
    Serial.println(F("Failed to connect to WiFi"));
    return false;
  }
}
