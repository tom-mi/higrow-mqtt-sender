#include <Arduino.h>
#include "device_id.h"

String get_device_id() {
  uint64_t mac_integer = ESP.getEfuseMac();
  uint8_t *mac = (uint8_t*) &mac_integer;
  char mac_chars[13];
  for (int i=0; i<6; i++) {
    sprintf(mac_chars + i * 2, "%" PRIx8, mac[i]);
  }
  return mac_chars;
}
